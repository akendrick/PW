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
function _adworks_pre_flight_ads($node) {
  $message = array(); // Empty message array.
  
  // Parse ADWORKS->node->body for ads
  if ($node->body) {
    $ads = $node->body['und'][0]['value'];

    // Collect Ads
    preg_match_all('/(?<=\<begad>)(.+)(?=<endad>)/', $ads, $copy);
    $ad_count = count($copy[0]);
    $ad_count_message = 'Classified Ad Count: ' . $ad_count . '<br>';

    // Collect Images
    preg_match_all('/(?<=PICAD)[0-9]{4,20}(?:[-_]*[0-9]{1,3})/', $ads, $images);
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
      if (!$image_file->uri) {
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
      $message_body .= '####### NO ADS UPLOADED ######### <br>MISSING IMAGES: <br>' . $missing_images;    
      $status = FALSE;
    }
    else {
      // Image files are present.
      $message_body .= '<strong>Images All Present & Counted For!</strong>';    
      $status = TRUE;
    }
  }

  drupal_set_message($message_body, 'warning' );    
  return $status;
}

/**
*  Implementation of custom ad parser.
*  
*  Create node from ad.
*
*  @TODO
*  Image handler should:
*   - Perform PREFLIGHT for images!!
*   - Check the entire directory for file
*   - LEAVE - if already a 'live' file (ie. in `files/classifieds_ad_images`
*   - MOVE - if file is in 'files/classified_ad_image_upload`
*/
function _adworks_parse_indivual_ad($ad, $create_ads = TRUE) {
  
  $new_ad = new StdClass();
  $new_ad->type = 'classified';
  node_object_prepare($new_ad);
    
  $new_ad->language = 'und';
  

  // Image
  preg_match('/(?<=PICAD)[0-9]{4,20}(?:[-_]*[0-9]{1,3})/', $ad, $image);
  $image = $image[0];
  if ($image) {
    // Check for image on FILES
    // Search Directory // Upgradable function
    $image_name = $image . '.jpg';
    $options = array ('key' => 'filename');
    $found = file_scan_directory('public://', '$' . $image . '$', $options);
    $image_file = array_shift($found);

    // Create managed File Object and add Image fields.
    if($image_file->uri) {      
      $file = (object) array(
        'uid' => 1,
        'uri' => $image_file->uri,
        'filename' => $image_file->filename,
        'title' => 'Pennywise Classified Ad : ' . $image_file->name,
        'filemime' => 'image/jpeg',
        'status' => 1,
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
        'safe_value' => check_plain($copy),
      ),
    ),
  );
  
  // Ad Title
  $new_ad->title = substr($copy, 0, 45);

  // Link
  preg_match('/([www]{3}([\.|\/][a-zA-Z0-9_?\-=]+)+)/', $copy, $link);
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
  $term = taxonomy_term_load($term_id);
  
  $new_ad->field_tags = array(
    $new_ad->language => array(
      0 => array(
        'tid' => $term_id,
        'taxonomy_term' => $term,
      ),
    ),
  );
  
  //if ($new_ad->field_tags[$node->language][0]['tid'] == FALSE) {
  //  dsm($new_ad->field_tags);
  //}
  
  
  if (count($images_missing) > 0 ) {
    return $results;
  }
  elseif (!$images_missing || count($images_missing) == 0) {
    if ($create_ads == TRUE) {
      node_submit($new_ad);
      node_save($new_ad);
      $ad_count += 1;
    }
    else {
          
      // log results
      $watchdog_message = "Ad Created: " . $term->name . ' ' . $term_id . 
      watchdog($watchdog_message, 'error message');
      
    }
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
    'ad_count' => $ad_count
  );

  return $results;
  
}
