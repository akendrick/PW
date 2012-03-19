<?php
/**
 * @file
 * pw_pages_attachments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_pages_attachments_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_views_api().
 */
function pw_pages_attachments_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pw_pages_attachments_node_info() {
  $items = array(
    'attachment' => array(
      'name' => t('Attachment'),
      'base' => 'node_content',
      'description' => t('For large attachments - such as PDFs or large image files where the user is encouraged to download as well as view them online.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Use <em>pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
