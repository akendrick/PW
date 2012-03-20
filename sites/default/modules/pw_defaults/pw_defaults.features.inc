<?php
/**
 * @file
 * pw_defaults.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_defaults_ctools_plugin_api() {
  return array("version" => "3");
}

/**
 * Implements hook_views_api().
 */
function pw_defaults_views_api() {
  return array("version" => "3.0");
}
