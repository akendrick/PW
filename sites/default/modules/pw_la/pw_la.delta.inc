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
  $delta->machine_name = 'ad_submission_layout';
  $delta->name = 'Content Left Large - 1 Sidebar';
  $delta->description = '';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'toggle_name' => 1,
      'toggle_slogan' => 0,
      'toggle_comment_user_verification' => 1,
      'toggle_favicon' => 1,
      'toggle_main_menu' => 1,
      'toggle_secondary_menu' => 1,
      'alpha_debug_block_toggle' => 0,
      'alpha_debug_grid_toggle' => 0,
      'alpha_debug_grid_roles' => array(
        1 => 0,
        4 => 0,
        2 => 0,
        8 => 0,
        9 => 0,
        11 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
        12 => 0,
        3 => 0,
      ),
      'alpha_toggle_breadcrumb' => 0,
      'alpha_region_sidebar_second_zone' => NULL,
      'alpha_region_sidebar_second_weight' => '0',
      'alpha_region_sidebar_second_position' => '-2',
      'alpha_region_sidebar_second_equal_height_element' => FALSE,
      'alpha_zone_super_menu_wrapper' => 1,
      'alpha_zone_super_menu_force' => 0,
      'alpha_zone_super_menu_order' => 0,
      'alpha_zone_super_menu_section' => 'header',
      'alpha_zone_super_menu_weight' => '-10',
      'alpha_zone_super_menu_columns' => '12',
      'alpha_zone_super_menu_css' => '',
      'alpha_zone_super_menu_wrapper_css' => '',
      'alpha_zone_super_menu_equal_height_container' => 0,
      'alpha_region_super_menu_force' => 1,
      'alpha_region_super_menu_zone' => 'super_menu',
      'alpha_region_super_menu_prefix' => '0',
      'alpha_region_super_menu_columns' => '12',
      'alpha_region_super_menu_suffix' => '0',
      'alpha_region_super_menu_weight' => '1',
      'alpha_region_super_menu_position' => '0',
      'alpha_region_super_menu_css' => '',
      'alpha_region_super_menu_equal_height_element' => 0,
      'alpha_region_super_menu_equal_height_container' => 0,
      'alpha_zone_branding_columns' => '12',
      'alpha_region_branding_force' => 1,
      'alpha_zone_menu_weight' => '3',
      'alpha_region_content_columns' => '20',
      'alpha_region_content_position' => '-8',
      'alpha_region_sidebar_first_weight' => '-8',
      'alpha_region_sidebar_first_position' => '-6',
      'alpha_zone_preface_weight' => '0',
    ),
  );
  $export['ad_submission_layout'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'admin_theme_';
  $delta->name = 'Admin Theme ';
  $delta->description = '';
  $delta->theme = 'bartik';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_bartik_settings' => array(
      'toggle_logo' => 1,
      'toggle_name' => 1,
      'toggle_slogan' => 1,
      'toggle_node_user_picture' => 1,
      'toggle_comment_user_picture' => 1,
      'toggle_comment_user_verification' => 1,
      'toggle_favicon' => 1,
      'toggle_main_menu' => 1,
      'toggle_secondary_menu' => 1,
      'default_logo' => 1,
      'logo_path' => '',
      'logo_upload' => '',
      'default_favicon' => 1,
      'favicon_path' => '',
      'favicon_upload' => '',
    ),
  );
  $export['admin_theme_'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'clone_of_ad_submission_layout';
  $delta->name = 'Front PW';
  $delta->description = 'Front Page layout';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = 'content_left';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'toggle_comment_user_verification' => 1,
      'toggle_favicon' => 1,
      'alpha_debug_block_toggle' => 0,
      'alpha_debug_grid_toggle' => 0,
      'alpha_debug_grid_roles' => array(
        1 => 0,
        4 => 0,
        2 => 0,
        8 => 0,
        9 => 0,
        11 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
        12 => 0,
        3 => 0,
      ),
      'alpha_toggle_action_links' => 0,
      'alpha_toggle_tabs' => 0,
      'alpha_hidden_site_slogan' => 0,
      'alpha_region_sidebar_second_zone' => NULL,
      'alpha_region_sidebar_second_weight' => '0',
      'alpha_region_sidebar_second_position' => '-2',
      'alpha_region_sidebar_second_equal_height_element' => FALSE,
      'alpha_zone_menu_weight' => '3',
      'alpha_region_content_columns' => '20',
      'alpha_region_content_position' => '-8',
      'alpha_region_sidebar_first_weight' => '-8',
      'alpha_region_sidebar_first_position' => '-6',
      'alpha_zone_preface_weight' => '0',
    ),
  );
  $export['clone_of_ad_submission_layout'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'clone_of_content_left';
  $delta->name = 'Mobile PW';
  $delta->description = 'mobile simple layout';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = 'content_left';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'alpha_layouts_alpha_default_normal_media' => 'all and (min-width: 600px) and (min-device-width: 600px), all and (max-device-width: 1024px) and (min-width: 1024px) and (orientation:landscape)',
      'alpha_debug_block_toggle' => 1,
      'alpha_debug_block_active' => 1,
      'alpha_debug_grid_toggle' => 1,
      'alpha_debug_grid_active' => 1,
      'alpha_debug_grid_roles' => array(
        1 => '1',
        3 => '3',
        4 => 0,
        2 => 0,
        8 => 0,
        9 => 0,
        11 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        10 => 0,
        12 => 0,
      ),
      'alpha_hidden_site_slogan' => 0,
      'alpha_zone_user_columns' => '12',
      'alpha_region_user_first_columns' => '8',
      'alpha_region_user_second_columns' => '4',
      'alpha_zone_threeup_order' => 0,
      'alpha_zone_threeup_weight' => '1',
      'alpha_zone_threeup_primary' => NULL,
      'alpha_zone_menu_section' => 'content',
      'alpha_zone_menu_weight' => '-10',
      'alpha_region_menu_weight' => '1',
      'alpha_region_sidebar_first_weight' => '-10',
      'alpha_region_sidebar_first_position' => '-1',
      'alpha_region_content_weight' => '0',
    ),
  );
  $export['clone_of_content_left'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'content_left';
  $delta->name = 'Modern PW';
  $delta->description = 'Content is on the left, with the side bars on the right. Making space for a large block above it.';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'toggle_logo' => 1,
      'toggle_slogan' => 0,
      'alpha_layouts_alpha_default_normal_media' => 'all and (min-width: 500px) and (min-device-width: 500px), all and (max-device-width: 1024px) and (min-width: 1024px) and (orientation:landscape)',
      'alpha_zone_branding_wrapper' => 0,
      'alpha_zone_branding_weight' => '-6',
      'alpha_zone_branding_columns' => '12',
      'alpha_region_branding_force' => 1,
      'alpha_region_branding_columns' => '6',
      'alpha_region_splash_one_force' => 1,
      'alpha_region_splash_two_force' => 1,
      'alpha_zone_user_weight' => '0',
      'alpha_zone_user_columns' => '24',
      'alpha_region_user_first_columns' => '16',
      'alpha_region_user_second_columns' => '8',
      'alpha_zone_menu_weight' => '6',
      'alpha_region_menu_weight' => '-10',
      'alpha_zone_header_section' => 'content',
      'alpha_zone_header_weight' => '-6',
      'alpha_zone_header_columns' => '24',
      'alpha_region_header_first_columns' => '15',
      'alpha_region_header_second_columns' => '9',
      'alpha_zone_content_weight' => '0',
      'alpha_region_content_columns' => '15',
      'alpha_region_content_position' => '0',
      'alpha_region_sidebar_first_weight' => '8',
      'alpha_region_sidebar_first_position' => '2',
      'alpha_region_sidebar_second_columns' => '5',
      'alpha_region_sidebar_second_weight' => '10',
      'alpha_region_sidebar_second_position' => '0',
      'alpha_zone_preface_section' => 'footer',
      'alpha_zone_preface_weight' => '-8',
      'alpha_zone_preface_columns' => '24',
      'alpha_region_preface_first_columns' => '8',
      'alpha_region_preface_second_columns' => '8',
      'alpha_region_preface_third_columns' => '8',
      'alpha_zone_postscript_section' => 'footer',
      'alpha_zone_postscript_weight' => '0',
      'alpha_zone_postscript_columns' => '24',
      'alpha_zone_postscript_primary' => 'postscript_first',
      'alpha_region_postscript_first_columns' => '6',
      'alpha_region_postscript_second_columns' => '6',
      'alpha_region_postscript_third_columns' => '6',
      'alpha_region_postscript_fourth_columns' => '6',
      'alpha_zone_footer_columns' => '24',
    ),
  );
  $export['content_left'] = $delta;

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'traditional';
  $delta->name = 'Traditional';
  $delta->description = 'Centered content between 2 sidebars';
  $delta->theme = 'pwt';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_pwt_settings' => array(
      'toggle_logo' => 1,
      'toggle_comment_user_verification' => 1,
      'toggle_favicon' => 1,
      'alpha_layouts_alpha_default_normal_media' => 'all and (min-width: 600px) and (min-device-width: 600px), all and (max-device-width: 1024px) and (min-width: 800px) and (orientation:landscape)',
      'alpha_zone_branding_columns' => '12',
      'alpha_region_branding_force' => 1,
      'alpha_zone_menu_weight' => '3',
      'alpha_zone_header_columns' => '24',
      'alpha_region_header_first_columns' => '7',
      'alpha_region_header_second_columns' => '9',
      'alpha_zone_preface_weight' => '-10',
      'alpha_zone_preface_columns' => '24',
      'alpha_region_preface_first_columns' => '8',
      'alpha_region_preface_second_columns' => '8',
      'alpha_region_preface_third_columns' => '8',
      'alpha_zone_content_weight' => '-6',
      'alpha_zone_content_primary' => 'sidebar_first',
      'alpha_region_content_columns' => '15',
      'alpha_region_sidebar_second_columns' => '5',
      'alpha_zone_postscript_columns' => '24',
      'alpha_zone_postscript_primary' => 'postscript_first',
      'alpha_region_postscript_first_columns' => '6',
      'alpha_region_postscript_second_columns' => '6',
      'alpha_region_postscript_third_columns' => '6',
      'alpha_region_postscript_fourth_columns' => '6',
      'alpha_region_footer_first_columns' => '6',
      'alpha_region_footer_second_columns' => '6',
    ),
  );
  $export['traditional'] = $delta;

  return $export;
}
