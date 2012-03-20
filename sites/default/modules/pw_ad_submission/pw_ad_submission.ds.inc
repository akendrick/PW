<?php
/**
 * @file
 * pw_ad_submission.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_ad_submission_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|ad_s|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'ad_s';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|ad_s|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_ad_submission_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|ad_s|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ad_s';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_ad_copy',
      ),
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'post_date',
        1 => 'author',
        2 => 'field_tags',
        3 => 'field_area',
        4 => 'field_duration',
        5 => 'links',
      ),
    ),
    'fields' => array(
      'field_ad_copy' => 'header',
      'field_image' => 'left',
      'post_date' => 'right',
      'author' => 'right',
      'field_tags' => 'right',
      'field_area' => 'right',
      'field_duration' => 'right',
      'links' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|ad_s|default'] = $ds_layout;

  return $export;
}
