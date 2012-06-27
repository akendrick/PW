<?php

/**
 *  @file
 *  This module parses Adworks data into new Classified nodes.
 *
 */

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
function _adworks_pre_flight_ads($adworks) {
  $message = array(); // Empty message array.

  // Parse ADWORKS->node->body for ads

    // Collect Ads
    preg_match_all('/(?<=\<begad>)(.+)(?=<endad>)/', $adworks, $copy);
    $ad_count = count($copy[0]);
    $ad_count_message = 'Classified Ad Count: ' . $ad_count . '<br>';

    // Collect Images
    preg_match_all('/(?<=PICAD)[0-9]{4,20}(?:[-_]*[0-9]{1,3})/', $adworks, $images);
    $image_count = count($images[0]);
    $image_count_message = 'Image Count: ' . $image_count . '<br>';

    // Cycle through all the ads for images
    foreach ($images[0] as $key => $image) {
      // Search Directory // Upgradable function
      $image_name = $image . '.jpg';
      $options = array ('key' => 'filename');
      $found = file_scan_directory('public://', '$' . $image_name . '$', $options);
      $image_file = array_shift($found);

      // Determine if file is currently in use.
      $image_folder = explode('/', $image_file->uri);
      $image_folder = $image_folder[2];
      
      if($image_folder == 'classified_ad_images') {
        // Do nothing as ad already exists.
        $image_in_use[] = $image_name;
      }

      // If corresponding image is NOT FOUND record image name
      if (!$image_file) {
        $missing_image_files[] = $image_name;
      }
    }

    // Count and sort missing images
    $message_body = $ad_count_message . $image_count_message . '<br>';

    if ($image_in_use) {
      sort($image_in_use);
      foreach($image_in_use as $image) {
        $in_use .= $image . '<br>';
      }
      $message_body .= '<br><strong>IN USE BY ANOTHER AD OR ALREADY UPLOADED:</strong><br>' . $in_use . '<br> If you are uploading a newer version, please edit that ad directly.<br>';;
    }
    if ($missing_image_files) {
      // Sort Image files
      sort($missing_image_files);
      foreach($missing_image_files as $missing) {
        $missing_images .= $missing . '<br>';
      }
      $message_body .= '<br><strong>MISSING IMAGES: <strong><br>' . $missing_images . '<br>####### NO ADS UPLOADED #########';
      $status = FALSE;

      $preflight['status'] = $status;
      $preflight['message'] = $message_body;
    }
    else {
      // Image files are present.
      $message_body .= '<BR><BR><strong>Images All Present & Counted For!</strong>.';
      $status = TRUE;

      $preflight['status'] = $status;
      $preflight['message'] = $message_body;
    }

  return $preflight;

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
  global $base_path;

  // Prepare Batch Output Reporting
  //$context['results'][] = $results;
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array(
      'progress' => 0,
      'email_count' => 0,
      'node_count' => 0,
      'image_count' => 0,
      'image_found' => 0,
      'image_already_uploaded' => 0,
      'image_missing' => 0,
      'phone_count' => 0,
      'link_count' => 0,
      'area_count' => 0,
      'error_count' => 0,
      'error_messages' => array(),
      'max' => $ad_total,
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


  // Image
  preg_match('/(?<=PICAD)[0-9]{4,20}(?:[-_]*[0-9]{1,3})/', $ad, $image);
  $image = $image[0];
  
  $image = FALSE;
  if ($image  && $check_images) {
    $context['sandbox']['images_count']++;
 
    // Check for image in FILES
    // Search Directory // Upgradable function
    $image_name = $image . '.jpg';
    $options = array ('key' => 'filename');
    $found = file_scan_directory('public://', '$' . $image . '$', $options);
    
    dpm('FILE FOUND');
    dpm($found);
    // If Image present prepare it for saving.
    if($image_file && $check_images) {

      // Take image object file and save to permanent directory
      $image_file = array_shift($found);
      $destination = 'public://classified_ad_images/' . $image_file->filename;
      $replace = FILE_EXISTS_REPLACE;
 
      $file = file_save_data($image_file->uri, $destination, $replace);
  
      // Set Status
      $file->status = FILE_STATUS_PERMANENT;
  
      // Prepare Classified Node Object
      // - Convert to ARRAY!
      $new_ad->field_image[$new_ad->language][0] = (array) $file;
      
      //$images_found[] = $image_name;
      $context['sandbox']['image_found']++;
    }
    else {
      // log missing images.
      //$images_missing[] = $image_name;
      $context['sandbox']['image_missing']++;
    }
    
  }
    


  // Ad Copy
  preg_match('/(?<=\<begad>)(.+)(?=<endad>)/', $ad, $copy);
  $copy = $copy[0];

  if ($image) {
    // Remove PICAD reference from copy.
    $copy_pic = explode('PICAD', $copy);
    $copy = $copy_pic[0];
    $image_count += 1;
  }
  $new_ad->field_ad_copy = array(
    $new_ad->language => array(
      0 => array(
        'value' => $copy,
#        'summary' => text_summary($copy),  
#        'format' => filter_default_format(),
        'format' => 'filtered_html',
#        'value' => $copy, // was 'safe_value'
      ),
    ),
  );

  // Ad Title
  $new_ad->title = substr($copy, 0, 45);
  // Use Title to label uploaded image (if any)
  if ($image) {
    $new_ad->field_image[$new_ad->language] = array(
      0 => array(
        'description' => $new_ad->title,
        )
    );
  }
  // Link
  preg_match('/([www]{3}([\.|\/][a-zA-Z0-9_?\-=]+#!?)+)/', $copy, $link);
  $link = check_url($link[0]);
  if ($link) {
    $new_ad->field_link = array(
      $new_ad->language => array(
        0 => array(
          'url' => $link,
        ),
      ),
    );
    // count links
    //$link_count += 1;
    $context['sandbox']['link_count']++;

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
    $context['sandbox']['phone_count']++;
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
    $context['sandbox']['area_count']++;
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
  preg_match('/([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})/', $copy, $email);
  $email = $email[0];

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
    $context['sandbox']['email_count']++;
  }

  // Classification
  preg_match('/(?<=class:)[0-9]{4}/', $ad, $section);
  $section = $section[0];
  $term_id = db_query('SELECT tid FROM {taxonomy_term_data} WHERE tid = (SELECT entity_id FROM {field_data_field_classified_id} WHERE field_classified_id_value = :cid)', array(':cid' => $section))->fetchField();

  if(!$term_id) {
    //dpm('Taxonomy term missing (' . $term_id . '): ' . $section );
    //$errors[] = 'Taxonomy term missing (' . $term_id . '): ' . $section ;
    $context['sandbox']['error_count']++;
    $context['sandbox']['error_messages'][] = 'Taxonomy term missing: ' . $section;
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

// AD COUNTER
// Returns ad count even if ads aren't save to database.
if(!$create_ads) {
  $results['ad_count'] = $ad_count;
  $context['progress']++;
}



 // Return if any images missing.
 //$create_ads = TRUE;

  if (count($images_missing) > 0 || $image_check == TRUE) {
    return $results;
  }
  elseif (!$images_missing || count($images_missing) == 0 || !$errors) {
    if ($create_ads) {
      // AD SAVE
      $ad_count += 1;
      node_submit($new_ad);
      node_save($new_ad);
      $context['progress']++;
    }
    else {
      // log results
      $watchdog_message = "Ad Created: " . $term->name . ' ' . $term_id .
      watchdog($watchdog_message, 'error message');
    }
  }
    $context['progress']++;
  
  
  //if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
  //  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  //}
//  return $results;

}

/**
* Implementation of custom finished batch script
*
* Returns information from batch_set();
*/

function adworks_batch_finished($success, $results, $operations) {
  //drupal_goto('admin/pennywise/classified/upcomming');
  dpm('Results');
  dpm($results);
  
  if ($success) {
    $message = count($results) . ' processed.';
    $message .= theme('item_list', $results);
    //$message = format_plural(count($results), 'One classified ad processed.', '@count classified ads processed.');
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occured while processing %error_op with arguments: @arguments', 
      array('%error_op' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    //$message = t('Finished with error(s)');
  }
  drupal_set_message($message);
  
  dpm('RESULTS');
  dpm($results);
}

//  // ERROR OUTPUT
//  if ($results['image']['error'] || $results['errors']) {
//    // Image errors
//    $error_message = 'No Ads Created! \n ******************* MISSING IMAGES: ';
//    foreach ($results['image']['error'] as $missing) {
//      $error_message .= $missing . "\n";
//    }
//    // Other Errors
//    $error_message .= "/n ***************** ERRORS DETECTED: /n";
//    foreach ($results['errors'] as $error) {
//      $error_message .= $error . "\n";
//    }
//    form_set_error('field_body', $error_message);
//  }
//  elseif ($results['ad_count'] == 0 || $results['ad_count'] == NULL) {
//    form_set_error('field_body', 'Unable to save ads to database. Please consult administrator.');
//  }
//  // elseif ($results['schedule'] != TRUE) {
//  //  form_set_error('field_body', 'Problems have been detected with ad scheduling. Please consult system administrator.');
//  // }
//  else {
//    drupal_set_message('Ads Created: ' . $results['ad_count'], 'status');
//  }

