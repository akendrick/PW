<?php

/**
 * @file
 * Converts `ad_submission` nodes to `classified`.
 */
define ('DEBUG', TRUE);

function promote_to_classified_ad($nid) {
  $submitted = node_load($nid);

  $data = array(
    'nid'         => $nid,
    'classified'  => $submitted->field_rate['und'][0]['value'],
    'tid'         => $submitted->field_tags['und'][0]['tid'],
    'term'        => taxonomy_term_title($data['tid']),
    'copy'        => $submitted->field_ad_copy['und'][0]['value'],
    'safe_copy'   => $submitted->field_ad_copy['und'][0]['safe_value'],
   // 'phone'       => 
    'ad type'     => $submitted->field_promote['und'][0]['value'],
    'uid'         => $submitted->uid,
    'title'       => substr($submitted->field_ad_copy['und'][0]['value'], 0, 55),
    'duration'    => $submitted->field_duration['und'][0]['value'],
//    'link'        => $submitted->
//    'publish'     => array(
//      'start'      => '',
//      'end'        => '',
//    ),
//    'phone'       => '',
//    'email'       => '',
//    'area code'   => '',
//    'link'        => $submitted->field_
    'image'    => array(
      'fid' => $submitted->field_image['und'][0]['fid'],
      'uri' => $submitted->field_image['und'][0]['uri'],
      'filename' => $submitted->field_image['und'][0]['filename'],
      'filemime' => $submitted->field_image['und'][0]['filemime'],
      'status' => 1,
      'uid' => $submitted->uid,
    ),
//    
//    'published'   => '',
//    'author'      => '',
//    'created'     => '',
);  

// Implied items
// - Phone
// - area code
// - 
  
dpm('NODE DATA');
dpm($submitted->uid);


## Create New Classified Ad **

  $ad = new StdClass();
  $ad->type = 'classified';
  node_object_prepare($ad);

  // Attache AD SUBMISSION UID to new NODE
  $ad->uid = $submitted->uid;
 
  $ad->language = 'und';
  dpm($ad);

  if ($data['image']['fid']) {
    //dpm('Image Detected!');
    // $image = (object) $data['image'];
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
    dpm('Link detected - ' . $link);
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
    dpm('PHONE # detected - ' . $phone);
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
  node_submit($ad);
  node_save($ad);
  
  // UPDATE `adp` database with new NID
  ## Edit Newly created Classified Ad **
  dpm('Submitted');
  dpm($submitted);
  dpm('Data');
  dpm($data);
  dpm('NEW AD');
  dpm($ad);
  dpm($ad->nid);
  
  // Testing Redirect
  //$options = array(
  //  'query' => 'destination=pwadmin/classified/incoming'
  //);
  //$destination = drupal_get_destination();
  //?destination=pwadmin/classified/incoming
  $path = 'node/'. $ad->nid . '/edit';
  dpm('NEW PATH: ' . $path);
  drupal_goto($path);
  
   #module_load_include('inc', 'node', 'node.pages');
   #$edit_ad = node_form($form, $form_state, $ad->nid);
   
   return $edit_ad;
//   $ad = node_add('classified');



}
 
// function promote_to_classified_ad($nid) {
//   $submitted = node_load($nid);
//   
//   $submitted_data = array(
//     'classified'  => $submitted->field_rate['und'][0]['value'],
//     'class'       => $submitted->field_tags['und'][0]['tid'],
//     'copy'        => $submitted->field_ad_copy['und'][0]['value'],
//     'ad type'     => $submitted->field_promote['und'][0]['value'],
// //    'publish'     => array(
// //      'start'      => '',
// //      'end'        => '',
//       'duration'   => $submitted->field_duration['und'][0]['value'],
// //    ),
// //    'phone'       => '',
// //    'email'       => '',
// //    'area code'   => '',
// //    'link'        => array(
// //      1 => '',
// //    ),
//     'image'    => array(
//       'fid' => $submitted->field_image['und'][0]['fid'],
//       'uri' => $submitted->field_image['und'][0]['uri'],
//       'filename' => $submitted->field_image['und'][0]['filename'],
//       'filemime' => $submitted->field_image['und'][0]['filemime'],
//     ),
// //    
// //    'published'   => '',
// //    'author'      => '',
// //    'created'     => '',
// );  
//   
//   
//   module_load_include('inc', 'node', 'node.pages');
//   $ad = node_add('classified');
//   
//   #set new form defaults...
// //  $ad['field_ad_copy']['und'][0]['value']['#value'] = $submitted_data['copy'];
// //  $ad['field_tags']['und']['#value'] = $submitted_data['class'];
//   #$ad['field_ad_type']['und']['#default_value'] = TRUE;
//   #$ad['field_ad_type']['und']['#value'] = 1;
//   #$ad['scheduler_settings']['publish_on']['#value']['date'] = ;
//   #$ad['scheduler_settings']['publish_on']['#value']['time'] = ;
//   #$ad['scheduler_settings']['unpublish_on']['#value']['date'] = date("Y-m-d", strtotime('Tuesday'));
//   #$ad['scheduler_settings']['unpublish_on']['#value']['time'] = date("Y-m-d", strtotime('5am'));
//   
//   if(DEBUG) {
//     dpm('Promote Ad');
//     dpm($submitted);
// 
//     dpm('Scheduler Settings');
//     dpm($ad['scheduler_settings']);
//   
//     dpm('UPdated Ad');
//     dpm($ad);  
//   }
// //  
//   return $ad;
// }