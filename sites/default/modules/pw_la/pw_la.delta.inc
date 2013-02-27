<?php
/**
 * @file
 * pw_la.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function pw_la_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'content_only';
  $delta->name = 'Content Only';
  $delta->description = 'Large central content no sidebars';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = 'front';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'alpha_region_sidebar_first_force' => 0,
      'alpha_region_sidebar_first_zone' => NULL,
      'alpha_region_sidebar_first_equal_height_element' => FALSE,
      'alpha_region_content_columns' => '24',
    ),
    'color_pwt_files' => NULL,
    'color_pwt_logo' => NULL,
    'color_pwt_palette' => NULL,
    'color_pwt_stylesheets' => NULL,
    'color_pwt_screenshot' => NULL,
  );
  $export['content_only'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'default_center';
  $delta->name = 'Default Centered ';
  $delta->description = 'PW default - content centered between nav bars';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'toggle_logo' => 0,
      'toggle_name' => 0,
      'toggle_slogan' => 0,
    ),
    'color_pwt_files' => NULL,
    'color_pwt_logo' => NULL,
    'color_pwt_palette' => NULL,
    'color_pwt_stylesheets' => NULL,
    'color_pwt_screenshot' => NULL,
  );
  $export['default_center'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'front';
  $delta->name = 'Front';
  $delta->description = 'Content and primary navigation';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = 'default_center';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'alpha_region_sidebar_second_zone' => NULL,
      'alpha_region_sidebar_second_equal_height_element' => FALSE,
      'alpha_region_content_columns' => '20',
      'alpha_region_sidebar_first_weight' => '10',
      'alpha_region_sidebar_first_position' => '20',
    ),
    'color_pwt_files' => NULL,
    'color_pwt_logo' => NULL,
    'color_pwt_palette' => NULL,
    'color_pwt_stylesheets' => NULL,
    'color_pwt_screenshot' => NULL,
  );
  $export['front'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'mobile';
  $delta->name = 'mobile';
  $delta->description = 'Mobile Friendly';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = 'default_center';
  $delta->settings = array();
  $export['mobile'] = $delta;

  return $export;
}
