<?php
/**
 * @file
 * pw_adworks.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_adworks_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|adworks_file|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'adworks_file';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|adworks_file|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|adworks_file|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'adworks_file';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|adworks_file|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_adworks_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|adworks_file|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'adworks_file';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'author' => 'ds_content',
      'post_date' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|adworks_file|default'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|adworks_file|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'adworks_file';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'author',
        1 => 'post_date',
      ),
      'right' => array(
        0 => 'field_publish',
      ),
    ),
    'fields' => array(
      'author' => 'left',
      'post_date' => 'left',
      'field_publish' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|adworks_file|full'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|adworks_file|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'adworks_file';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'classes' => array(),
  );
  $export['node|adworks_file|teaser'] = $ds_layout;

  return $export;
}
