<?php
/**
 * @file
 * pw_pages_attachments.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_pages_attachments_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|attachment|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'attachment';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|attachment|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|attachment|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'attachment';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'attachment-teaser-header',
      ),
    ),
  );
  $export['node|attachment|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|page|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => 'page-title-teaser',
      ),
    ),
  );
  $export['node|page|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_pages_attachments_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|attachment|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'attachment';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'post_date',
        3 => 'body',
        4 => 'field_high_res_ad',
        5 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'post_date' => 'ds_content',
      'body' => 'ds_content',
      'field_high_res_ad' => 'ds_content',
      'field_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|attachment|default'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|attachment|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'attachment';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_high_res_ad',
        2 => 'field_image',
      ),
      'middle' => array(
        0 => 'body',
      ),
      'right' => array(
        0 => 'field_link',
        1 => 'path',
        2 => 'field_entity_reference',
      ),
      'hidden' => array(
        0 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_high_res_ad' => 'left',
      'field_image' => 'left',
      'body' => 'middle',
      'field_link' => 'right',
      'path' => 'right',
      'field_entity_reference' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|attachment|form'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|attachment|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'attachment';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'body',
        3 => 'field_high_res_ad',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'field_high_res_ad' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|attachment|teaser'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_image',
        1 => 'title',
      ),
      'left' => array(
        0 => 'post_date',
      ),
      'footer' => array(
        0 => 'body',
        1 => 'field_entity_reference',
        2 => 'comments',
      ),
      'right' => array(
        0 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'header',
      'title' => 'header',
      'post_date' => 'left',
      'body' => 'footer',
      'field_entity_reference' => 'footer',
      'field_link' => 'right',
      'comments' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|page|default'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form_3col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'body',
      ),
      'left' => array(
        0 => 'title',
        1 => 'field_images_editorial_extra',
      ),
      'middle' => array(
        0 => 'field_image',
        1 => 'field_link',
      ),
      'right' => array(
        0 => 'field_entity_reference',
        1 => 'path',
      ),
      'hidden' => array(
        0 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'body' => 'header',
      'title' => 'left',
      'field_images_editorial_extra' => 'left',
      'field_image' => 'middle',
      'field_entity_reference' => 'right',
      'field_link' => 'middle',
      'path' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|page|form'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|page|teaser'] = $ds_layout;

  return $export;
}
