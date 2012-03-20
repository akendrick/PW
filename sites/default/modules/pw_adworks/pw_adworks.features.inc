<?php
/**
 * @file
 * pw_adworks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_adworks_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_node_info().
 */
function pw_adworks_node_info() {
  $items = array(
    'adworks_file' => array(
      'name' => t('Adworks File'),
      'base' => 'node_content',
      'description' => t('Upload new ad from Adworks through here.
<h4>To minimize any problems copy Adworks copy into a plain text file preferably <em>TextWrangler</em> and use <strong>Straighten Quotes</strong>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
