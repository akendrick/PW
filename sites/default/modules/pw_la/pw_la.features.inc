<?php
/**
 * @file
 * pw_la.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_la_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function pw_la_views_api() {
  return array("version" => "3.0");
}
