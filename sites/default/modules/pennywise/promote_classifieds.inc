<?php

/**
 * @file
 * Converts `ad_submission` nodes to `classified`.
 */

/**
 * Custom function promote_to_classified_ad
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
  //watchdog('Promote', $nid . ' NID');
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
    'title'       => trim(substr($submitted->field_ad_copy['und'][0]['value'], 0, 52)) . '...',
    'duration'    => $submitted->field_duration['und'][0]['value'],
    );
    if ($submitted->field_image['und'][0]['fid']) {
      $data['image'] = array(
        'fid' => $submitted->field_image['und'][0]['fid'],
        'uri' => $submitted->field_image['und'][0]['uri'],
        'filename' => $submitted->field_image['und'][0]['filename'],
        'filemime' => $submitted->field_image['und'][0]['filemime'],
        'status' => 1,
        'uid' => $submitted->uid,
      );
    }

  //watchdog('Promote', 'Load data from node.');

// Create New Classified Ad
  $ad = new StdClass();
  $ad->type = 'classified';

  //watchdog('Promote', 'Prepare node');
  node_object_prepare($ad);

  // Attache AD SUBMISSION UID to new NODE
  $ad->uid = $submitted->uid;

  $ad->language = 'und';

  if (array_key_exists('image', $data)) {
    $ad->field_image = array(
      $ad->language => array(
        0 => $data['image'],
      ),
    );
  }

  // SCAN AD FOR DATA
  // LINK
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

  if ($email) {
    watchdog('Promote', 'Found Email.');
  }
  if (!$email) {
    watchdog('Promote', 'Found Link.');
    $ad->field_link = array(
      $ad->laguage => array(
        0 => array(
          'url' => $link,
        ),
      ),
    );
  }

  // PHONE
  watchdog('Promote', 'Prepping Phone.');
  preg_match('/((\d)?(\s|-)?(\()?(\d){3}(\))?(\s|-){1}(\d){3}(\s|-){1}(\d){4})/', $data['copy'], $phone);
  $phone = $phone[0];
  if ($phone) {
    // drupal_set_message( t('Embedded phone number detected - @phone', array('@phone' => $phone)));
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


  //watchdog('Promote', 'Setting Defaults.');
  $ad->title = $data['title'];
  $ad->field_ad_copy = array(
    $ad->language => array(
      0 => array(
        'value' => $data['copy'],
        'safe_value' => $data['safe_copy'],
      )
    )
  );

  // LIVELOAD // by default
  $ad->field_ad_type = array(
    $ad->language => array(
      0 => array(
        'value' => 1, // 1 for liveload
      ),
    ),
  );

  //watchdog('Promote', 'Setting Taxonomy Term.');
  $ad->field_tags = array(
    $ad->language => array(
      0 => array(
        'tid' => $data['tid'],
        'taxonomy_term' => $data['term'],
      ),
    ),
  );


  // Proces ad
  //watchdog('Promote', 'Node Submit.');
  node_submit($ad);

  //watchdog('Promote', 'Node Save --> not yet.');
  node_save($ad);
  node_delete($nid);
  watchdog('PW - Promote Ad', 'Created new classified ad ('. $ad->nid . ') from deleted Ad Submission (' . $nid . ') by user: ' . $submitted->uid . '.' );

  // Redirect to new node Edit page
  $path = 'node/'. $ad->nid . '/edit';
  drupal_goto($path);
  module_load_include('inc', 'node', 'node.pages');
  $edit_ad = node_form($form, $form_state, $ad->nid);

/*   if (node_save($ad)) { */

/* } */


  return $edit_ad;

}
