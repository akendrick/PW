<?php
/**
 * @file
 * pw_layout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_layout_ctools_plugin_api() {
  return array("version" => "3");
}

/**
 * Implements hook_views_api().
 */
function pw_layout_views_api() {
  return array("version" => "3.0");
}
