<?php
/**
 * @file
 * pw_la.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_la_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_free|form';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_free';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'comment_body' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => FALSE,
  );
  $export['comment|comment_node_free|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_task|form';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_task';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'author',
        1 => 'comment_body',
      ),
      'hidden' => array(
        2 => 'subject',
        3 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'author' => 'ds_content',
      'comment_body' => 'ds_content',
      'subject' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['comment|comment_node_task|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'field_submitter',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'field_submitter' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|article|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
<<<<<<< HEAD
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
=======
>>>>>>> SiteReformation
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
<<<<<<< HEAD
        0 => 'full_name_display',
        1 => 'field_area_taxonomy',
        2 => 'field_phone',
        3 => 'contact',
        4 => 'field_fax',
        5 => 'field_address',
=======
        1 => 'full_name_display',
        2 => 'field_area_taxonomy',
        3 => 'field_phone',
        4 => 'contact',
        5 => 'field_fax',
        6 => 'field_address',
>>>>>>> SiteReformation
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'full_name_display' => 'right',
      'field_area_taxonomy' => 'right',
      'field_phone' => 'right',
      'contact' => 'right',
      'field_fax' => 'right',
      'field_address' => 'right',
    ),
    'classes' => array(),
<<<<<<< HEAD
=======
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
>>>>>>> SiteReformation
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}
