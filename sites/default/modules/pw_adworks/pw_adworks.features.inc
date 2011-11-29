<?php
/**
 * @file
 * pw_adworks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_adworks_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pw_adworks_node_info() {
  $items = array(
    'adworks_file' => array(
      'name' => t('Adworks File'),
      'base' => 'node_content',
      'description' => t('Upload new ad from Adworks through here.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
