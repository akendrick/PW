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

      // If corresponding image is NOT FOUND record image name
      if (!$image_file) {
        $missing_image_files[] = $image_name;
      }
    }

    // Count and sort missing images
    $message_body = $ad_count_message . $image_count_message . '<br>';

    if ($missing_image_files) {
      // Sort Image files
      sort($missing_image_files);
      foreach($missing_image_files as $missing) {
        $missing_images .= $missing . '<br>';
      }
      $message_body .= '<br>MISSING IMAGES: <br>' . $missing_images . '<br>####### NO ADS UPLOADED #########';
      $status = FALSE;

      $preflight['status'] = $status;
      $preflight['message'] = $message_body;
    }
    else {
      // Image files are present.
      $message_body .= '<strong>Images All Present & Counted For!</strong>.';
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
*
*  @TODO
*  Image handler should:
*   - Perform PREFLIGHT for images!! -- DONE in form validation.
*   - Check the entire directory for file
*   - LEAVE - if already a 'live' file (ie. in `files/classifieds_ad_images`
*   - MOVE - if file is in 'files/classified_ad_image_upload`
*/
function _adworks_parse_indivual_ad($ad, $publish_dates = NULL, $create_ads = NULL, $check_images = NULL) {

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
  if ($image  && $check_images) {
    // Check for image on FILES
    // Search Directory // Upgradable function
    $image_name = $image . '.jpg';
    $options = array ('key' => 'filename');
    $found = file_scan_directory('public://', '$' . $image . '$', $options);
    $image_file = array_shift($found);

    // Create managed File Object and add Image fields.
    if($image_file->uri && $check_images == TRUE) {
      $file = (object) array(
        'uid' => 1,
        'uri' => $image_file->uri,
        'filename' => $image_file->filename,
        'title' => 'Pennywise Classified Ad : ' . $image_file->name,
        'filemime' => 'image/jpeg',
      );
      // Move image to Classified Image folder
      $file = file_copy($file, 'public://classified_ad_images', FILE_EXISTS_REPLACE);

      $new_ad->field_image = array(
        $new_ad->language => array(
          0 => (array)$file,
        ),
      );

      $images_found[] = $image_name;
    }
    else {
      $images_missing[] = $image_name;
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
    $link_count += 1;
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
    $phone_count += 1;
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
    $area_code_count += 1;
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
    $email_count += 1;
  }


  // Classification
  preg_match('/(?<=class:)[0-9]{4}/', $ad, $section);
  $section = $section[0];
  $term_id = db_query('SELECT tid FROM {taxonomy_term_data} WHERE tid = (SELECT entity_id FROM {field_data_field_classified_id} WHERE field_classified_id_value = :cid)', array(':cid' => $section))->fetchField();
  if(!$term_id) {
    $errors[] = 'Taxonomy term missing: ' . $section;
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



  // Collate ad creation data.
  $results = array(
    'email' => $email_count,
    'link' => $link_count,
    'area code' => $area_code_count,
    'image' => array(
      'found' => $images_found,
      'error' => $images_missing,
      'total' => $image_count,
    ),
    'phone' => $phone_count,
    'ad_count' => $ad_count,
    'errors' => $errors,
  );

//  if ($create_ads == FALSE) {
//    //drupal_set_message('OVERRIDE - Do not create ads.', 'alert');
//    return $results;
//  }

// AD COUNTER
// Returns ad count even if ads aren't save to database.
if(!$create_ads) {
  $ad_count += 1;
  $results['ad_count'] = $ad_count;
}


 // Return if any images missing.
 //$create_ads = TRUE;

  if (count($images_missing) > 0 || $image_check == TRUE) {
    return $results;
  }
  elseif (!$images_missing || count($images_missing) == 0 || !$errors) {
    if ($create_ads) {
      // AD SAVE
      node_submit($new_ad);
      node_save($new_ad);
      $ad_count += 1;
      $results['ad_count'] = $ad_count;
    }
    else {
      // log results
      $watchdog_message = "Ad Created: " . $term->name . ' ' . $term_id .
      watchdog($watchdog_message, 'error message');
    }
  }

  // Scheduler
  // Handled on SAVE
  // THis is OBSELETE NOW.

  // Date & time set in adworks.module -- _parse_adworks_data($node)
  // if ($new_ad->nid) {
  //   if ($publish_dates['start'] && $publish_dates['end'] && $create_ads) {
  //     db_insert('scheduler')
  //       ->fields(array(
  //         'nid' => $new_ad->nid,
  //         'publish_on' => $publish_dates['start'],
  //         'unpublish_on' => $publish_dates['end'],
  //       ))
  //       ->execute();
  //   }
  //   $results['schedule'] = TRUE;
  // }
  // else {
  //   $results['schedule'] = 'Unable to schedule ad.';
  // }


  return $results;

}
