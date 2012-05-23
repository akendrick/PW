<?php

/**
 * @file
 * Converts `ad_submission` nodes to `classified`.
 */

/**
 * Custom function promot_to_classified_ad
 *
 * @var nid
 * - Node id to load node for conversion.
 * - Create new `classified_ad` based on data from `ad_s` submission.
 *
 * NOTE: 
 *  This function deletes the database entry from `adp`. 
 *  Erasing payment related data.
 *
 * @return
 *  Redirects user to the edit page for the new node.
 */
function promote_to_classified_ad($nid) {
  $submitted = node_load($nid);

  $data = array(
    'nid'         => $nid,
    'classified'  => $submitted->field_rate['und'][0]['value'],
    'tid'         => $submitted->field_tags['und'][0]['tid'],
    'term'        => taxonomy_term_title($data['tid']),
    'copy'        => $submitted->field_ad_copy['und'][0]['value'],
    'safe_copy'   => $submitted->field_ad_copy['und'][0]['safe_value'],
    'ad type'     => $submitted->field_promote['und'][0]['value'],
    'uid'         => $submitted->uid,
    'title'       => substr($submitted->field_ad_copy['und'][0]['value'], 0, 55),
    'duration'    => $submitted->field_duration['und'][0]['value'],
    'image'    => array(
      'fid' => $submitted->field_image['und'][0]['fid'],
      'uri' => $submitted->field_image['und'][0]['uri'],
      'filename' => $submitted->field_image['und'][0]['filename'],
      'filemime' => $submitted->field_image['und'][0]['filemime'],
      'status' => 1,
      'uid' => $submitted->uid,
    ),
  );  

// Implied items
// - Phone
// - area code
// - 
  

// Create New Classified Ad

  $ad = new StdClass();
  $ad->type = 'classified';
  node_object_prepare($ad);

  // Attache AD SUBMISSION UID to new NODE
  $ad->uid = $submitted->uid;
 
  $ad->language = 'und';

  if ($data['image']['fid']) {
    drupal_set_message( t('Image detected - @image', array('@image' => $data['image']['filename'])));
    $ad->field_image = array(
      $ad->language => array(
        0 => $data['image'],
      ),
    );
  }
  
  $ad->title = $data['title'];
  $ad->field_ad_copy = array(
    $ad->language => array(
      0 => array(
        'value' => $data['copy'],
        'safe_value' => $data['safe_copy'],
      )
    )
  );
  
  // SCAN AD FOR DATA 
  // LINK
  preg_match('/([www]{3}([\.|\/][a-zA-Z0-9_?\-=]+)+)/', $data['safe_copy'], $link);
  $link = check_url($link[0]);
  if($link){
    drupal_set_message( t('Embedded link detected - @link', array('@link' => $link)));
    $ad->field_link = array(
      $ad->laguage => array(
        0 => array(
          'url' => $link,
        ),
      ),
    );
  }
  // PHONE
  preg_match('/((\d)?(\s|-)?(\()?(\d){3}(\))?(\s|-){1}(\d){3}(\s|-){1}(\d){4})/', $data['safe_copy'], $phone);
  $phone = $phone[0];
  if ($phone) {
    drupal_set_message( t('Embedded phone number detected - @phone', array('@phone' => $phone)));
    $ad->field_phone = array(
      $ad->language => array(
        0 => array(
          'number' => $phone,
          'country_codes' => 'ca',
          'extension' => '',
        ),
      ),
    );
  }
  
  // LIVELOAD // by default
  $ad->field_ad_type = array(
    $ad->language => array(
      0 => array(
        'value' => 1, // 1 for liveload
      ),
    ),
  );

  $ad->field_tags = array(
    $ad->language => array(
      0 => array(
        'tid' => $data['tid'],
        'taxonomy_term' => $data['term'],
      ),
    ),
  );
  
  
    // Proces ad
 //   node_submit($ad);
 //   node_save($ad);
    
    // UPDATE `adp` database with new NID
    ## Edit Newly created Classified Ad **
    
    if (DEBUG) {  
      dpm('Submitted');
      dpm($submitted);
      dpm('Data');
      dpm($data);
      dpm('NEW AD');
      dpm($ad);
      dpm($ad->nid);
    // Testing Redirect
      $options = array(
        'query' => 'destination=pwadmin/classified/incoming'
      );
      $destination = drupal_get_destination();
      //?destination=pwadmin/classified/incoming
    }    
 //   $path = 'node/'. $ad->nid . '/edit';
 //   dpm('NEW PATH: ' . $path);
 //   drupal_goto($path);
    
     #module_load_include('inc', 'node', 'node.pages');
     #$edit_ad = node_form($form, $form_state, $ad->nid);
     
 //    return $edit_ad;
    //$ad = node_add('classified');



}
 
