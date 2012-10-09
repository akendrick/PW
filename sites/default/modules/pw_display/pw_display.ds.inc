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
  $ds_layout->layout = 'ds_form_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'field_display_ad',
      ),
      'left' => array(
        0 => 'field_section_all_select',
        1 => 'field_tags',
      ),
      'middle' => array(
        0 => 'field_display_ad_type',
        1 => 'group_basics',
        2 => 'field_publish_date',
        3 => 'field_ad_client',
        4 => 'title',
        5 => 'field_ad_copy',
      ),
      'right' => array(
        0 => 'path',
        1 => 'field_link',
        2 => 'group_options',
        3 => 'field_email',
      ),
      'footer' => array(
        0 => 'field_entity_reference',
      ),
      'hidden' => array(
        0 => 'field_high_res_ad',
        1 => 'group_description_box',
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'header',
      'field_section_all_select' => 'left',
      'field_tags' => 'left',
      'field_display_ad_type' => 'middle',
      'group_basics' => 'middle',
      'path' => 'right',
      'field_publish_date' => 'middle',
      'field_link' => 'right',
      'field_ad_client' => 'middle',
      'group_options' => 'right',
      'field_email' => 'right',
      'title' => 'middle',
      'field_entity_reference' => 'footer',
      'field_high_res_ad' => 'hidden',
      'field_ad_copy' => 'middle',
      'group_description_box' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
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
