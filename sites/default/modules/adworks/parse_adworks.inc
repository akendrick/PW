<?php

/**
 *  @file
 *  This module parses Adworks data into new Classified nodes.
 *
 */

/**
 * Custom REGEX for URL
 *
 * @param $ad_copy
 *  - text string that will be searched.
 * @param $search_copy
 *  'link' - ignore email addresses
 *  'email' - ignore links
 */
function ad_url($ad_copy, $search_type = 'link') {
  $regex = "/((https?|ftp)\:\/\/)?"; // SCHEME
  $regex .= "([a-z0-9+!*(),;?&=\$_.-]+(\:[a-z0-9+!*(),;?&=\$_.-]+)?@)?"; // User and Pass
  $regex .= "([a-z0-9-.]*)\.([a-z]{2,3})"; // Host or IP
  $regex .= "(\:[0-9]{2,5})?"; // Port
  $regex .= "(\/([a-z0-9+\$_-]\.?)+)*\/?"; // Path
  $regex .= "(\?[a-z+&\$_.-][a-z0-9;:@&%=+\/\$_.-]*)?"; // GET Query
  $regex .= "(#[a-z_.-][a-z0-9+\$_.-]*)?/"; // Anchor

  preg_match($regex, $ad_copy, $found);

  // SET EMAIL FLAG
  $email = strstr($found[0], '@');

  switch ($search_type) {
    case 'email':
      if ($email) {
        return($found[0]);
      }
      break;
    case 'link':
      if (!$email) {
        return($found[0]);
      }
      break;
  }
}

/**
 *  Test Adworks Copy.
 *
 *   Test the presence of referneced image files.
 *   Count Ads and check corresponding taxonomy terms.
 *
 *   @return
 *     Drupal_set_message - Overview of result
 *     TRUE if all images are present.
 *     FALSE if even 1 image is missing.
 */
function _adworks_pre_flight_ads($ad, &$context) {
  // Batch Message
  if (empty($context['results'])) {
  $context['results'] = array(
    'batch_type' => 'tested',
    'progress' => 0,
    'email_count' => 0,
    'ad_count' => 0,
    'image_count' => 0,
    'image_found' => 0,
    'image_already_uploaded' => 0,
    'image_replaced' => array(),
    'image_missing' => 0,
    'image_missing_files' => array(),
    'phone_count' => 0,
    'link_count' => 0,
    'area_count' => 0,
    'error_count' => 0,
    'error_messages' => array(),
    'blank_ad' => array(),
    );
  }

  // Ad Copy
  preg_match('/(?<=\<begad>)(.+)(?=<endad>)/', $ad, $copy);
  $copy = $copy[0];
  if (trim($copy) == NULL || $copy == '') {
    $context['results']['blank_ad'][] = 'No ad copy. Possibly a blank line.';
    // watchdog('Preflight', 'Blank line detected.');
  }
  else {

    $context['results']['ad_count']++;

    // Image
    preg_match('/(?<=PICAD)[0-9]{4,20}(?:[-_]*[0-9]{1,3})/', $copy, $image);
    $image = $image[0];

    if ($image) {
      // watchdog('Preflight', 'Image required.');
      $context['results']['image_count']++;

      // Check for image in FILES
      // Search Directory // Upgradable function
      $image_name = $image . '.jpg';
      $options = array ('key' => 'filename');
      $found = file_scan_directory('public://', '$' . $image . '$', $options);
      $image_file = array_shift($found);
      //dpm($image_file);

      if($image_file) {
        // watchdog('Preflight', 'Image found.');
        $context['results']['image_found']++;

        // Determine file location.
        // watchdog('Preflight', 'About to test folder location.');
        $image_filepath = explode('/', $image_file->uri);
        if ($image_filepath[2] == 'classified_ad_images') {
          $context['results']['image_already_uploaded']++;
          $context['results']['image_replaced'][] = $image_file->filename;
        }
      }
      else {
        // log missing images.
        //$images_missing[] = $image_name;
        $context['results']['image_missing']++;
        // watchdog('Preflight', 'No Image found.');
        $context['results']['image_missing_files'][] = $image_name;
     }
    }

    // Link
    $link = ad_url($copy, 'link');
    if ($link) {
      $context['results']['link_count']++;
    }

    // Email
    $email = ad_url($copy, 'email');
    if ($email) {
      $context['results']['email_count']++;
    }

    // Phone
    preg_match('/((\d)?(\s|-)?(\()?(\d){3}(\))?(\s|-){1}(\d){3}(\s|-){1}(\d){4})/', $copy, $phone);
    if ($phone[0]) {
      $context['results']['phone_count']++;
    }

    // area code
    preg_match('/(?<=zip:)[a-zA-Z0-9 ]{7,9}/', $ad, $area_code);
    if ($area_code[0]) {
      $context['results']['area_count']++;
    }

    // Classification
    preg_match('/(?<=class:)[0-9]{4}/', $copy, $section);
    $term_id = db_query('SELECT tid FROM {taxonomy_term_data} WHERE tid = (SELECT entity_id FROM {field_data_field_classified_id} WHERE field_classified_id_value = :cid)', array(':cid' => $section[0]))->fetchField();
    if(!$term_id) {
      if ($new_ad->title === NULL || $new_ad->title == '') {
        // Skip further reporting as already flagged as empty.
      }
      else {
        $context['results']['error_count']++;
        $context['results']['error_messages'][] = 'Taxonomy term missing ' . $section[0] . ' : ' . $new_ad->title;
        $save_ad = FALSE;
      }
    }
  }
}


/**
*  Implementation of custom ad parser.
*
*  Create node from ad.
*
*  @param $ad
*   Parsed Adworks data. Raw text data that requires GREP work.
*  @param $publish_date
*    Associative array containing publishing start & end date for new nodes.
*    - start: in UNIX epoch time.
*    - end: in UNIX epoch time.
*  @param bool $create_ads
*    BOOLEAN - TRUE will save nodes,
*       FALSE omits the save and returns ad data.
*    For testing and image verification purposes only.
*  @param bool $check_images
*    BOOLEAN - TRUE will save images.
*       FALSE omits image check (acts as if images don't exist).
*    For testing and image verification purposes only.
*  @param $context
*    Returns output for batch process and error handling.
*
* Note:
*   Scheduler data is now handled on node_save();
*/
function _adworks_parse_individual_ad($ad, $publish_dates = NULL, $create_ads = NULL, $check_images = NULL, &$context) {
//  global $base_path;
  $save_ad = TRUE;
  $image = array();

  // Prepare Batch Output Reporting
  //$context['results'][] = $results;
  if (empty($context['results'])) {
    $context['results'] = array(
      'batch_type' => 'uploaded',
      'progress' => 0,
      'email_count' => 0,
      'ad_count' => 0,
      'image_count' => 0,
      'image_found' => 0,
      'image_already_uploaded' => 0,
      'image_replaced' => array(),
      'image_missing' => 0,
      'image_missing_files' => array(),
      'phone_count' => 0,
      'link_count' => 0,
      'area_count' => 0,
      'error_count' => 0,
      'error_messages' => array(),
      'blank_ad' => array(),
    );
  }


  $image_count = 0;

  $new_ad = new StdClass();
  $new_ad->type = 'classified';
  node_object_prepare($new_ad);

  $new_ad->language = 'und';
  $new_ad->status = 0;
  $new_ad->promote = 0;
  $new_ad->sticky = 0;
  $new_ad->sticky = 0;
  $new_ad->revision = 0;

  // Ad Copy
  preg_match('/(?<=\<begad>)(.+)(?=<endad>)/', $ad, $copy);
  $copy = $copy[0];

  if (trim($copy) == NULL || $copy == '') {
    $context['results']['blank_ad'][] = 'No ad copy. Possibly a blank line.';
    $save_ad = FALSE;
  }
  else {

    // Image
    preg_match('/(?<=PICAD)[0-9]{4,20}(?:[-_]*[0-9]{1,3})/', $ad, $image);
    $image = $image[0];

    // Check for images in body copy first.
    // Remove PICAD reference from copy.
    $copy_pic = explode('PICAD', $copy);
    $copy = $copy_pic[0];

    if ($image  && $check_images) {

      $context['results']['image_count']++;

      // Check for image in FILES
      // Search Directory // Upgradable function
      $image_name = $image . '.jpg';
      $options = array ('key' => 'filename');
      $found = file_scan_directory('public://', '$' . $image . '$', $options);
      $image_filepath = array_shift($found);

      // If Image present prepare it for saving.
      if($image_filepath && $check_images) {
        // Prepare Classified Node Object
        // - Convert to ARRAY!
        $file = (object) array(
          'uid' => 1,
          'uri' => $image_filepath->uri,
          'filemime' => file_get_mimetype($image_filepath->uri),
          'status' => 1,
          'filename' => substr($copy, 0, 45) . '...',
        );

        // Determine file location.
        // watchdog('Adworks', 'Created image FILE object).');
        $image_folder = explode('/', $image_filepath->uri);
        if ($image_folder[2] == 'classified_ad_images') {
          // watchdog('Adworks', 'File already exisist.');
          $context['results']['image_already_uploaded']++;
          $context['results']['image_replaced'][] = $image_filepath->filename . ': ' . $file->filename;
        }


        $destination = 'public://classified_ad_images/' . $image_filepath->filename;
        $replace = FILE_EXISTS_RENAME;
        $file = file_copy($file, $destination, $replace);
        //$file = file_save_data($image_filepath->uri, $destination, $replace);
        // watchdog('Adworks', 'File Save data successfull.');
//        $file = file_copy($file, 'public://classified_ad_images/', FILE_EXISTS_REPLACE);
        $new_ad->field_image[$new_ad->language][0] = (array)$file;
        // watchdog('Adworks', 'File oject added to node.');

        //$images_found[] = $image_name;
        $context['results']['image_found']++;
      }
      else {
        // log missing images.
        //$images_missing[] = $image_name;
        // watchdog('Adworks', 'Image not found (or not checking for images).');
        $context['results']['image_missing']++;
        $context['results']['image_missing_files'][] = $image_name;
     }

    }

    // Establish
    $new_ad->field_ad_copy = array(
    $new_ad->language => array(
        0 => array(
          'value' => $copy,
          'format' => 'filtered_html',
          'summary' => text_summary($copy, 'plain_text', 55),
  #        'format' => filter_default_format(),
  #        'value' => $copy, // was 'safe_value'
        ),
      ),
    );

    // Ad Title
    $new_ad->title = text_summary($copy, 'plain_text', 55);


    // Use Title to label uploaded image (if any)
    // if ($image) {
    //   $new_ad->field_image[$new_ad->language] = array(
    //     0 => array(
    //       'description' => $new_ad->title,
    //       )
    //   );
    // }


    // Link
    $link = ad_url($copy, 'link');
    if ($link) {
      $new_ad->field_link = array(
        $new_ad->language => array(
          0 => array(
            'url' => $link,
          ),
        ),
      );
      // count links
      $context['results']['link_count']++;
    }

    // Phone
    preg_match('/((\d)?(\s|-)?(\()?(\d){3}(\))?(\s|-){1}(\d){3}(\s|-){1}(\d){4})/', $copy, $phone);
    $phone = $phone[0];

    if ($phone) {
      $new_ad->field_phone = array(
        $new_ad->language => array(
          0 => array(
            'number' => $phone,
            'country_codes' => 'ca',
            'extension' => '',
          ),
        ),
      );
      // Count Phone Numbers
      //$phone_count += 1;
      $context['results']['phone_count']++;
    }

    // area code
    preg_match('/(?<=zip:)[a-zA-Z0-9 ]{7,9}/', $ad, $area_code);
    $area_code = $area_code[0];

    if ($area_code) {
      $new_ad->field_area_code = array(
        $new_ad->language => array(
          0 => array(
            'value' => $area_code,
            'save_value' => check_plain($area_code),
          ),
        ),
      );
      // Count Area Codes
      //$area_code_count += 1;
      $context['results']['area_count']++;
    }

    // LIVELOAD
    $new_ad->field_ad_type = array(
      $new_ad->language => array(
        0 => array(
          'value' => 0, // 1 for liveload
        ),
      ),
    );

    // Email
    $email = ad_url($copy, 'email');
    if ($email) {
      $new_ad->field_email = array(
        $new_ad->language => array(
          0 => array(
            'email' => $email,
          ),
        ),
      );
      // Count Email
      //$email_count += 1;
      $context['results']['email_count']++;
    }

    // Classification
    preg_match('/(?<=class:)[0-9]{4}/', $ad, $section);
    $section = $section[0];
    $term_id = db_query('SELECT tid FROM {taxonomy_term_data} WHERE tid = (SELECT entity_id FROM {field_data_field_classified_id} WHERE field_classified_id_value = :cid)', array(':cid' => $section))->fetchField();

    if(!$term_id) {
      //dpm('Taxonomy term missing (' . $term_id . '): ' . $section );
      //$errors[] = 'Taxonomy term missing (' . $term_id . '): ' . $section ;
      if ($new_ad->title === NULL || $new_ad->title == '') {
        // Skip further reporting as already flagged as empty.
      }
      else {
        $context['results']['error_count']++;
        $context['results']['error_messages'][] = 'Taxonomy term missing ' . $section . ' : ' . $new_ad->title;
        $save_ad = FALSE;
      }
    }
    else {
      $term_name = taxonomy_term_load($term_id);

      $new_ad->field_tags = array(
        $new_ad->language => array(
          0 => array(
            'tid' => $term_id,
            'taxonomy_term' => $term_name,
          ),
        ),
      );
    }

    // dpm( debug_backtrace() );

    // Scheduler
    // Date & time set in adworks.module -- _parse_adworks_data($node)
    if ($publish_dates) {
      $new_ad->scheduler = array(
        'published' => date(variable_get('date_format_long', 'l, F j, Y - H:i'), $publish_dates['start']),
        'unpublished' => date(variable_get('date_format_long', 'l, F j, Y - H:i'), $publish_dates['end']),
        'published_on' => $publish_dates['start'],
        'unpublished_on' => $publish_dates['end'],
      );
      $new_ad->publish_on = $publish_dates['start'];
      $new_ad->unpublish_on = $publish_dates['end'];
    }

    if (count($images_missing) > 0 || $image_check == TRUE) {
      return $results;
    }
    elseif (!$images_missing || count($images_missing) == 0 || !$errors) {
      if ($create_ads && $save_ad) {
        // AD SAVE
        node_submit($new_ad);
        node_save($new_ad);
      }
      else {
        // IF NOT SAVING ADS --> log results
        //$watchdog_message = "Ad Created: " . $term->name . ' ' . $term_id;
        //watchdog($watchdog_message, 'error message');
      }
    // Record total batch results.
    $context['results']['ad_count']++;
    }
    // Progress not tied to ad creation (will count blank lines).
    $context['progress']++;
  }
}
/**
* Implementation of custom finished batch script
*
* Returns information from batch_set();
* Used by both BATCH_PREFLIGHT and BATCH_PROCESS.
*
*/

function adworks_batch_finished($success, $results, $operations) {

  if ($success) {
    // Set default status
    $status = 'status';

    // Default Success Message
    $processed = array();
    $processed[] = t('@ads ads @batch_type', array('@ads' => $results['ad_count'], '@batch_type' => $results['batch_type']));
    $processed[] = t('@email emails', array('@email' => $results['email_count']));
    $processed[] = t('@area postal codes', array('@area' => $results['area_count']));
    $processed[] = t('@phone phone numbers', array('@phone' => $results['phone_count']));

    // If websites
    if ($results['link_count']) {
      $processed[] = t('@link website links', array('@link' => $results['link_count']));
    }


    // If blanks lines detected
    if (count($results['blank_ad'])) {
      $processed[] = format_plural(count($results['blank_ad']), '@count blank line', '@count blank lines');
#      $processed[] = t('@blanks empty lines', array('@blanks' => count($results['blank_ad'])));
    }

    // If images detected
    if ($results['image_count']) {
      $image_message_header = t('@images images required - @found found', array('@images' => $results['image_count'], '@found' => $results['image_found']));

      // already uploaded
      if ($results['image_already_uploaded']) {
        $image_message_header .= t(' - @previous from previous weeks', array('@previous' => $results['image_already_uploaded']));
        asort($results['image_replaced']);
        $image_message .= ($results['image_replaced']) ? theme('item_list', array('items' => $results['image_replaced'], 'title' => 'Images Already Uploaded (will not be replaced)')) : '' ;
      }
     }
    else {
      $image_message_header = '0 images';
    }

    // missing image output
    if ($results['image_missing']) {
      $image_message_header .= t(' - <strong> @missing MISSING </strong>', array('@missing' => $results['image_missing']));
      $missing_message = t('############### @missing MISSING IMAGES: ##################', array('@missing' => $results['image_missing']));
      asort($results['image_missing_files']);
      $error_message = theme('item_list', array('items' => $results['image_missing_files'], 'title' => $missing_message));

      $status = 'warning';
    }

    $processed[] = $image_message_header;
    $processed[] = $image_message;

    // Set Message OUTPUT
    $title = strtoupper( t('Classified ads @batch_type', array( '@batch_type' => $results['batch_type'])) );
    rsort($processed);
    $message = theme('item_list', array('items' => $processed, 'title' => $title));

    // Errors Detected -- WARNING
    if ($results['error_count']) {
      $processed[] = t('@error errors', array('@error' => $results['error_count']));
      $error_message .= format_plural(count($results['error_messages']), '<strong>One error detected.</strong><br>', '<strong>@count errors detected.</strong><br>');
      $error_message .= theme('item_list', array('items' => $results['error_messages'], 'title' => 'ERRORS DETECTED'));

      $status = 'warning';
    }
  }
  else {
    // MAJOR ERRORS -- unable to process.
    $error_operation = reset($operations);
    $error_message .= t('<strong>##############    ALERT ADMINSITRATION IMMEDIATELY    #####################</strong> <br><br>
      An error occured while processing   <strong> %error_op </strong>   on ad: <br><br>@arguments',
      array('%error_op' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    $status = 'error';
  }

  if ($results['batch_type'] == 'tested') {
    //form_set_error('field_ad_creation_override');
    drupal_set_message('<strong>CREATE ADS is currently disabled.</strong> <br> Check <em>Ad Creation Override</em> to save ads.', 'warning');
  }
  if ($error_message) {
    drupal_set_message($error_message, $status);
  }
  if ($message) {
    drupal_set_message($message, 'status');
  }

}
