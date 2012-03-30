<?php
/**
 * @file
 * pw_editorial.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_editorial_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|block_list_header';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'block_list_header';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h6',
        'class' => 'field-editorial-title',
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'More',
        'wrapper' => '',
        'class' => 'field-link-readmore',
      ),
    ),
  );
  $export['node|article|block_list_header'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|block_list_item';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'block_list_item';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h6',
        'class' => 'field-block-list-header',
      ),
    ),
    'node_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'More',
        'wrapper' => '',
        'class' => 'field-block-link-readmore',
      ),
    ),
  );
  $export['node|article|block_list_item'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|article|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|simple_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'simple_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['node|article|simple_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_editorial_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|block_list_header';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'block_list_header';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|article|block_list_header'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|block_list_item';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'block_list_item';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|article|block_list_item'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'group_editorial_details',
        2 => 'group_editorial_more',
        3 => 'field_images_editorial_extra',
        4 => 'body',
        5 => 'comments',
        6 => 'field_link',
        7 => 'field_email',
        8 => 'field_submitter',
        9 => 'field_entity_reference',
        10 => 'links',
        11 => 'post_date',
        12 => 'field_area_taxonomy',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'group_editorial_details' => 'ds_content',
      'group_editorial_more' => 'ds_content',
      'field_images_editorial_extra' => 'ds_content',
      'body' => 'ds_content',
      'comments' => 'ds_content',
      'field_link' => 'ds_content',
      'field_email' => 'ds_content',
      'field_submitter' => 'ds_content',
      'field_entity_reference' => 'ds_content',
      'links' => 'ds_content',
      'post_date' => 'ds_content',
      'field_area_taxonomy' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
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
        0 => 'group_ed_basic',
        1 => 'title',
        2 => 'field_submitter',
        3 => 'field_area_taxonomy',
        4 => 'field_image',
      ),
      'middle' => array(
        0 => 'group_bonus',
        1 => 'field_link',
        2 => 'field_email',
      ),
      'right' => array(
        0 => 'group_details',
        1 => 'field_images_editorial_extra',
        2 => 'field_entity_reference',
      ),
      'hidden' => array(
        0 => 'path',
        1 => 'group_ed_group_master',
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'body' => 'header',
      'group_ed_basic' => 'left',
      'group_bonus' => 'middle',
      'group_details' => 'right',
      'path' => 'hidden',
      'group_ed_group_master' => 'hidden',
      'title' => 'left',
      'field_link' => 'middle',
      'field_submitter' => 'left',
      'field_email' => 'middle',
      'field_images_editorial_extra' => 'right',
      'field_area_taxonomy' => 'left',
      'field_image' => 'left',
      'field_entity_reference' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|article|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|simple_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'simple_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'limit' => array(
      'field_image' => '1',
    ),
    'classes' => array(),
  );
  $export['node|article|simple_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'title',
        1 => 'field_submitter',
        2 => 'field_area_taxonomy',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'field_submitter' => 'right',
      'field_area_taxonomy' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|article|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function pw_editorial_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'block_list_header';
  $ds_view_mode->label = 'Block List Header';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['block_list_header'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'block_list_item';
  $ds_view_mode->label = 'Block List Item';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['block_list_item'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'simple_teaser';
  $ds_view_mode->label = 'Simple Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['simple_teaser'] = $ds_view_mode;

  return $export;
}
