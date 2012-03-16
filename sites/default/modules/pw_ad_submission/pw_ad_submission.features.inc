<?php
/**
 * @file
 * pw_ad_submission.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_ad_submission_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
