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
        'class' => 'field-editorial-title grid-6',
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
    'post_date' => array(
      'weight' => '13',
      'label' => 'inline',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|article|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|editorial_slideshow';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'editorial_slideshow';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h6',
        'class' => 'editorial-slideshow-title',
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => 'field-link-readmore',
      ),
    ),
  );
  $export['node|article|editorial_slideshow'] = $ds_fieldsetting;

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
  $ds_fieldsetting->id = 'node|attachment|attachment';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'attachment';
  $ds_fieldsetting->view_mode = 'attachment';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|attachment|attachment'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|attachment|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'attachment';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|attachment|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|attachment|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'attachment';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|page|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
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
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'group_editorial_details',
        2 => 'group_editorial_more',
        3 => 'field_images_editorial_extra',
        4 => 'body',
        5 => 'field_link',
        6 => 'field_email',
        7 => 'field_entity_reference',
        8 => 'links',
        9 => 'field_submitter',
        10 => 'field_area_taxonomy',
        11 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'group_editorial_details' => 'ds_content',
      'group_editorial_more' => 'ds_content',
      'field_images_editorial_extra' => 'ds_content',
      'body' => 'ds_content',
      'field_link' => 'ds_content',
      'field_email' => 'ds_content',
      'field_entity_reference' => 'ds_content',
      'links' => 'ds_content',
      'field_submitter' => 'ds_content',
      'field_area_taxonomy' => 'ds_content',
      'post_date' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|editorial_slideshow';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'editorial_slideshow';
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
        1 => 'body',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|article|editorial_slideshow'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_ed_basic',
        1 => 'group_bonus',
        2 => 'title',
        3 => 'field_submitter',
        4 => 'group_details',
        5 => 'field_area_taxonomy',
        6 => 'path',
        7 => 'body',
        8 => 'redirect',
        9 => 'field_link',
        10 => 'field_email',
        11 => 'field_entity_reference',
        12 => 'field_image',
        13 => 'group_extra_image_group',
        14 => 'field_images_editorial_extra',
      ),
      'hidden' => array(
        15 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_ed_basic' => 'ds_content',
      'group_bonus' => 'ds_content',
      'title' => 'ds_content',
      'field_submitter' => 'ds_content',
      'group_details' => 'ds_content',
      'field_area_taxonomy' => 'ds_content',
      'path' => 'ds_content',
      'body' => 'ds_content',
      'redirect' => 'ds_content',
      'field_link' => 'ds_content',
      'field_email' => 'ds_content',
      'field_entity_reference' => 'ds_content',
      'field_image' => 'ds_content',
      'group_extra_image_group' => 'ds_content',
      'field_images_editorial_extra' => 'ds_content',
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
  $ds_layout->id = 'node|attachment|attachment';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'attachment';
  $ds_layout->view_mode = 'attachment';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        1 => 'field_image',
      ),
      'right' => array(
        2 => 'body',
        3 => 'field_high_res_ad',
        4 => 'field_link',
      ),
      'footer' => array(
        5 => 'field_entity_reference',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_image' => 'left',
      'body' => 'right',
      'field_high_res_ad' => 'right',
      'field_link' => 'right',
      'field_entity_reference' => 'footer',
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
    'layout_attributes_merge' => 1,
  );
  $export['node|attachment|attachment'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|attachment|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'attachment';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
        1 => 'field_high_res_ad',
        2 => 'field_file',
      ),
      'right' => array(
        3 => 'links',
        4 => 'title',
        5 => 'body',
        6 => 'field_link',
      ),
      'footer' => array(
        7 => 'field_scribd',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'field_high_res_ad' => 'left',
      'field_file' => 'left',
      'links' => 'right',
      'title' => 'right',
      'body' => 'right',
      'field_link' => 'right',
      'field_scribd' => 'footer',
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
  $export['node|attachment|default'] = $ds_layout;

  $ds_layout = new stdClass();
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
        1 => 'field_file',
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
        0 => 'field_high_res_ad',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_file' => 'left',
      'field_image' => 'left',
      'body' => 'middle',
      'field_link' => 'right',
      'path' => 'right',
      'field_entity_reference' => 'right',
      'field_high_res_ad' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|attachment|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|attachment|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'attachment';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'body',
        3 => 'field_high_res_ad',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_high_res_ad' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|attachment|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_link',
        2 => 'body',
        3 => 'field_entity_reference',
        4 => 'comments',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_link' => 'ds_content',
      'body' => 'ds_content',
      'field_entity_reference' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|page|default'] = $ds_layout;

  $ds_layout = new stdClass();
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
      ),
      'middle' => array(
        0 => 'field_link',
      ),
      'right' => array(
        0 => 'field_entity_reference',
        1 => 'path',
      ),
      'footer' => array(
        0 => 'field_image',
        1 => 'field_images_editorial_extra',
      ),
      'hidden' => array(
        0 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'body' => 'header',
      'title' => 'left',
      'field_link' => 'middle',
      'field_entity_reference' => 'right',
      'path' => 'right',
      'field_image' => 'footer',
      'field_images_editorial_extra' => 'footer',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|page|form'] = $ds_layout;

  $ds_layout = new stdClass();
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|pw_digital|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'pw_digital';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_edition',
        3 => 'field_trail',
        5 => 'field_nelson_edition',
        7 => 'field_castlegar_edition',
        8 => 'field_kootenay_lake_edition',
      ),
      'right' => array(
        1 => 'group_info',
        15 => 'field_edition_date',
        16 => 'field_display_ad',
      ),
      'footer' => array(
        2 => 'group_optional_features',
        10 => 'field_entity_reference',
      ),
      'hidden' => array(
        4 => 'field_scribd',
        6 => 'field_pdf',
        9 => 'path',
        11 => 'title',
        12 => 'body',
        13 => 'field_special_feature_link',
        14 => 'redirect',
        17 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_edition' => 'left',
      'group_info' => 'right',
      'group_optional_features' => 'footer',
      'field_trail' => 'left',
      'field_scribd' => 'hidden',
      'field_nelson_edition' => 'left',
      'field_pdf' => 'hidden',
      'field_castlegar_edition' => 'left',
      'field_kootenay_lake_edition' => 'left',
      'path' => 'hidden',
      'field_entity_reference' => 'footer',
      'title' => 'hidden',
      'body' => 'hidden',
      'field_special_feature_link' => 'hidden',
      'redirect' => 'hidden',
      'field_edition_date' => 'right',
      'field_display_ad' => 'right',
      '_add_existing_field' => 'hidden',
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
  $export['node|pw_digital|form'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function pw_editorial_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'attachment';
  $ds_view_mode->label = 'Attachment';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['attachment'] = $ds_view_mode;

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
  $ds_view_mode->view_mode = 'castlegar_edition_view';
  $ds_view_mode->label = 'Castlegar Edition View';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['castlegar_edition_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'editorial_slideshow';
  $ds_view_mode->label = 'Editorial Slideshow';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['editorial_slideshow'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'kootenay_edition_view';
  $ds_view_mode->label = 'Kootenay Edition View';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['kootenay_edition_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'nelson_edition_view';
  $ds_view_mode->label = 'Nelson Edition View';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['nelson_edition_view'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'simple_teaser';
  $ds_view_mode->label = 'Simple Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['simple_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'special_feature';
  $ds_view_mode->label = 'Special Feature';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['special_feature'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'trail_edition_view';
  $ds_view_mode->label = 'Trail Edition View';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['trail_edition_view'] = $ds_view_mode;

  return $export;
}
