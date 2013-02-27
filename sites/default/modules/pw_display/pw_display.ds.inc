<?php
/**
 * @file
 * pw_display.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_display_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|display_ads|block_list_item';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'display_ads';
  $ds_fieldsetting->view_mode = 'block_list_item';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|display_ads|block_list_item'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|display_ads|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'display_ads';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|display_ads|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|display_ads|print_display_ad';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'display_ads';
  $ds_fieldsetting->view_mode = 'print_display_ad';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'em',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'more',
        'wrapper' => '',
        'class' => 'more-button button',
      ),
    ),
  );
  $export['node|display_ads|print_display_ad'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|display_ads|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'display_ads';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => '',
      ),
    ),
  );
  $export['node|display_ads|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_display_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|display_ads|block_list_item';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'display_ads';
  $ds_layout->view_mode = 'block_list_item';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_display_ad',
      ),
      'right' => array(
        0 => 'field_ad_client',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'left',
      'field_ad_client' => 'right',
      'title' => 'right',
    ),
  );
  $export['node|display_ads|block_list_item'] = $ds_layout;

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
        1 => 'field_link',
        2 => 'field_email',
      ),
      'right' => array(
        3 => 'title',
        4 => 'field_ad_client',
        5 => 'field_ad_copy',
      ),
      'footer' => array(
        6 => 'field_special_feature_link',
        7 => 'field_high_res_ad',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'header',
      'field_link' => 'left',
      'field_email' => 'left',
      'title' => 'right',
      'field_ad_client' => 'right',
      'field_ad_copy' => 'right',
      'field_special_feature_link' => 'footer',
      'field_high_res_ad' => 'footer',
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
        2 => 'group_description_box',
        3 => 'field_display_ad',
        4 => 'field_publish_date',
        5 => 'group_options',
        7 => 'field_section_all_select',
        8 => 'group_advanced',
        9 => 'field_link',
        10 => 'field_tags',
        11 => 'field_email',
        12 => 'field_display_ad_type',
        13 => 'field_special_feature_link',
        14 => 'field_ad_client',
        15 => 'title',
        16 => 'field_ad_copy',
      ),
      'hidden' => array(
        6 => 'path',
        17 => 'redirect',
        18 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_display_ad' => 'ds_content',
      'group_basics' => 'ds_content',
      'group_description_box' => 'ds_content',
      'field_display_ad' => 'ds_content',
      'field_publish_date' => 'ds_content',
      'group_options' => 'ds_content',
      'path' => 'hidden',
      'field_section_all_select' => 'ds_content',
      'group_advanced' => 'ds_content',
      'field_link' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_email' => 'ds_content',
      'field_display_ad_type' => 'ds_content',
      'field_special_feature_link' => 'ds_content',
      'field_ad_client' => 'ds_content',
      'title' => 'ds_content',
      'field_ad_copy' => 'ds_content',
      'redirect' => 'hidden',
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
  $ds_layout->id = 'node|display_ads|print_display_ad';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'display_ads';
  $ds_layout->view_mode = 'print_display_ad';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_display_ad',
      ),
      'header' => array(
        1 => 'field_ad_client',
      ),
      'right' => array(
        2 => 'title',
        3 => 'field_ad_copy',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_display_ad' => 'left',
      'field_ad_client' => 'header',
      'title' => 'right',
      'field_ad_copy' => 'right',
      'node_link' => 'right',
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
  $export['node|display_ads|print_display_ad'] = $ds_layout;

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

/**
 * Implements hook_ds_view_modes_info().
 */
function pw_display_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'print_display_ad';
  $ds_view_mode->label = 'Print Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['print_display_ad'] = $ds_view_mode;

  return $export;
}
