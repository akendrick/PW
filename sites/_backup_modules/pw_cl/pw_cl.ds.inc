<?php
/**
 * @file
 * pw_cl.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_cl_ds_field_settings_info() {
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

  $ds_fieldsetting = new stdClass();
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

  $ds_fieldsetting = new stdClass();
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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|classified|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'classified';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|classified|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_cl_ds_layout_settings_info() {
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

  $ds_layout = new stdClass();
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

  $ds_layout = new stdClass();
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

  $ds_layout = new stdClass();
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|classified|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'classified';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_image',
        1 => 'field_ad_type',
      ),
      'left' => array(
        0 => 'group_details',
        1 => 'field_tags',
        2 => 'post_date',
        3 => 'field_phone',
        4 => 'field_link',
        5 => 'field_email',
      ),
      'right' => array(
        0 => 'field_ad_copy',
      ),
    ),
    'fields' => array(
      'field_image' => 'header',
      'field_ad_type' => 'header',
      'group_details' => 'left',
      'field_tags' => 'left',
      'post_date' => 'left',
      'field_ad_copy' => 'right',
      'field_phone' => 'left',
      'field_link' => 'left',
      'field_email' => 'left',
    ),
    'classes' => array(),
  );
  $export['node|classified|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|classified|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'classified';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'group_default',
        1 => 'field_ad_type',
        2 => 'field_ad_copy',
      ),
      'middle' => array(
        0 => 'group_form_basics',
        1 => 'field_tags',
      ),
      'right' => array(
        0 => 'group_otional',
        1 => 'field_area_code',
        2 => 'field_link',
        3 => 'field_phone',
        4 => 'field_email',
      ),
      'footer' => array(
        0 => 'field_image',
      ),
      'hidden' => array(
        0 => 'group_cl_ad_master',
        1 => 'title',
        2 => 'group_publishing_group',
        3 => 'path',
        4 => '_add_existing_field',
        5 => 'group_contact',
      ),
    ),
    'fields' => array(
      'group_default' => 'left',
      'group_form_basics' => 'middle',
      'group_otional' => 'right',
      'field_image' => 'footer',
      'group_cl_ad_master' => 'hidden',
      'title' => 'hidden',
      'group_publishing_group' => 'hidden',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
      'field_ad_type' => 'left',
      'field_tags' => 'middle',
      'field_ad_copy' => 'left',
      'group_contact' => 'hidden',
      'field_area_code' => 'right',
      'field_link' => 'right',
      'field_phone' => 'right',
      'field_email' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|classified|form'] = $ds_layout;

  return $export;
}
