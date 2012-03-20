<?php
/**
 * @file
 * pw_ad_submission.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_ad_submission_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function pw_ad_submission_node_info() {
  $items = array(
    'ad_s' => array(
      'name' => t('Ad Submission'),
      'base' => 'node_content',
      'description' => t('Online classified ad submission.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
