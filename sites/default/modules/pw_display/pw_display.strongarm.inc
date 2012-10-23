<?php
/**
 * @file
 * pw_display.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pw_display_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_display_ads';
  $strongarm->value = array();
  $export['menu_options_display_ads'] = $strongarm;

  return $export;
}
