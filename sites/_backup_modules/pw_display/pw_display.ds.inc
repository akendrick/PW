<?php
/**
 * @file
 * pw_display.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_display_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|display_ads|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'display_ads';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_display_ad',
      ),
      'left' => array(
        1 => 'title',
        2 => 'field_ad_copy',
      ),
      'right' => array(
        3 => 'field_ad_client',
        4 => 'field_link',
        5 => 'field_email',
      ),
      'footer' => array(
        6 => 'field_special_feature_link',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'header',
      'title' => 'left',
      'field_ad_copy' => 'left',
      'field_ad_client' => 'right',
      'field_link' => 'right',
      'field_email' => 'right',
      'field_special_feature_link' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|display_ads|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|display_ads|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'display_ads';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_display_ad',
        1 => 'group_basics',
        2 => 'field_display_ad',
        3 => 'group_description_box',
        4 => 'group_options',
        5 => 'field_publish_date',
        6 => 'field_section_all_select',
        7 => 'group_advanced',
        8 => 'field_link',
        10 => 'field_email',
        11 => 'field_tags',
        12 => 'field_special_feature_link',
        13 => 'field_display_ad_type',
        14 => 'field_ad_client',
        15 => 'title',
        16 => 'field_ad_copy',
      ),
      'hidden' => array(
        9 => 'path',
        17 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_display_ad' => 'ds_content',
      'group_basics' => 'ds_content',
      'field_display_ad' => 'ds_content',
      'group_description_box' => 'ds_content',
      'group_options' => 'ds_content',
      'field_publish_date' => 'ds_content',
      'field_section_all_select' => 'ds_content',
      'group_advanced' => 'ds_content',
      'field_link' => 'ds_content',
      'path' => 'hidden',
      'field_email' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_special_feature_link' => 'ds_content',
      'field_display_ad_type' => 'ds_content',
      'field_ad_client' => 'ds_content',
      'title' => 'ds_content',
      'field_ad_copy' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|display_ads|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|display_ads|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'display_ads';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_display_ad',
        1 => 'title',
        2 => 'field_ad_client',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'ds_content',
      'title' => 'ds_content',
      'field_ad_client' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|display_ads|teaser'] = $ds_layout;

  return $export;
}
