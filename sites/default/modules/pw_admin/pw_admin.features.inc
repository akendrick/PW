<?php
/**
 * @file
 * pw_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_admin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function pw_admin_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pw_admin_node_info() {
  $items = array(
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
