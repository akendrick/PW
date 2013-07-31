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

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|classified|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'classified';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|classified|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|free|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'free';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'author',
    ),
  );
  $export['node|free|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|free|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'free';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
    'submitted_by' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'ds_time_ago',
    ),
  );
  $export['node|free|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'contact' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'full_name_display' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

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
  $ds_layout->id = 'node|ad_s|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'ad_s';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_classified_ad',
        1 => 'group_upgrade',
        2 => 'group_review',
        3 => 'field_rate',
        4 => 'field_ad_copy',
        5 => 'group_payment',
        7 => 'field_area',
        9 => 'field_duration',
        10 => 'field_tags',
        13 => 'field_ad_details',
        15 => 'field_liveload',
        16 => 'field_image',
        17 => 'group_contact',
        18 => 'field_phone',
        19 => 'field_email',
      ),
      'right' => array(
        6 => 'group_more',
        14 => 'field_notes',
      ),
      'footer' => array(
        8 => 'title',
        11 => 'path',
        12 => 'redirect',
      ),
      'hidden' => array(
        20 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_classified_ad' => 'left',
      'group_upgrade' => 'left',
      'group_review' => 'left',
      'field_rate' => 'left',
      'field_ad_copy' => 'left',
      'group_payment' => 'left',
      'group_more' => 'right',
      'field_area' => 'left',
      'title' => 'footer',
      'field_duration' => 'left',
      'field_tags' => 'left',
      'path' => 'footer',
      'redirect' => 'footer',
      'field_ad_details' => 'left',
      'field_notes' => 'right',
      'field_liveload' => 'left',
      'field_image' => 'left',
      'group_contact' => 'left',
      'field_phone' => 'left',
      'field_email' => 'left',
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
    'layout_attributes_merge' => 1,
  );
  $export['node|ad_s|form'] = $ds_layout;

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
      'field_phone' => 'left',
      'field_link' => 'left',
      'field_email' => 'left',
      'field_ad_copy' => 'right',
    ),
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|classified|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'classified';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'field_ad_copy',
        2 => 'field_phone',
        3 => 'links',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'field_ad_copy' => 'right',
      'field_phone' => 'right',
      'links' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|classified|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|free|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'free';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'field_price_free',
        2 => 'field_body_text',
        3 => 'author',
      ),
      'footer' => array(
        4 => 'comments',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'field_price_free' => 'right',
      'field_body_text' => 'right',
      'author' => 'right',
      'comments' => 'footer',
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
  $export['node|free|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|free|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'free';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_body_text',
      ),
      'left' => array(
        1 => 'field_price_free',
        2 => 'title',
      ),
      'right' => array(
        3 => 'field_contact_seller',
        4 => 'field_tags',
      ),
      'hidden' => array(
        5 => 'node_notify_subscribe',
        6 => 'field_image',
        7 => 'redirect',
        8 => 'path',
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_body_text' => 'header',
      'field_price_free' => 'left',
      'title' => 'left',
      'field_contact_seller' => 'right',
      'field_tags' => 'right',
      'node_notify_subscribe' => 'hidden',
      'field_image' => 'hidden',
      'redirect' => 'hidden',
      'path' => 'hidden',
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
  $export['node|free|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|free|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'free';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_price_free',
        1 => 'field_image',
      ),
      'right' => array(
        2 => 'post_date',
        3 => 'field_body_text',
        4 => 'submitted_by',
        5 => 'author',
      ),
      'footer' => array(
        6 => 'comments',
      ),
    ),
    'fields' => array(
      'field_price_free' => 'left',
      'field_image' => 'left',
      'post_date' => 'right',
      'field_body_text' => 'right',
      'submitted_by' => 'right',
      'author' => 'right',
      'comments' => 'footer',
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
  $export['node|free|full'] = $ds_layout;

  return $export;
}
