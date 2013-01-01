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
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'header' => array(
        0 => 'field_display_ad',
      ),
      'left' => array(
        0 => 'title',
        1 => 'field_ad_copy',
      ),
      'right' => array(
        0 => 'field_ad_client',
        1 => 'field_link',
        2 => 'field_email',
        3 => 'field_high_res_ad',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'header',
      'title' => 'left',
      'field_ad_copy' => 'left',
      'field_ad_client' => 'right',
      'field_link' => 'right',
      'field_email' => 'right',
      'field_high_res_ad' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|display_ads|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|display_ads|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'display_ads';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_3col_stacked_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_display_ad',
        1 => 'field_section_all_select',
        2 => 'field_tags',
        3 => 'field_display_ad_type',
        4 => 'group_basics',
        5 => 'path',
        6 => 'field_publish_date',
        7 => 'field_link',
        8 => 'group_options',
        9 => 'field_email',
        10 => 'field_ad_client',
        11 => 'field_entity_reference',
        12 => 'title',
        13 => 'group_description_box',
        14 => 'field_ad_copy',
        15 => 'field_high_res_ad',
        16 => 'field_special_feature_link',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'header',
      'field_section_all_select' => 'header',
      'field_tags' => 'header',
      'field_display_ad_type' => 'header',
      'group_basics' => 'header',
      'path' => 'header',
      'field_publish_date' => 'header',
      'field_link' => 'header',
      'group_options' => 'header',
      'field_email' => 'header',
      'field_ad_client' => 'header',
      'field_entity_reference' => 'header',
      'title' => 'header',
      'group_description_box' => 'header',
      'field_ad_copy' => 'header',
      'field_high_res_ad' => 'header',
      'field_special_feature_link' => 'header',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => FALSE,
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
