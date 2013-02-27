<?php
/**
 * @file
 * pw_cl.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pw_cl_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_adworks_file';
  $strongarm->value = array();
  $export['menu_options_adworks_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ad_s';
  $strongarm->value = array();
  $export['menu_options_ad_s'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_classified';
  $strongarm->value = array();
  $export['menu_options_classified'] = $strongarm;

  return $export;
}
