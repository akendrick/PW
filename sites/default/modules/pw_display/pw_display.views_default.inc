<?php
/**
 * @file
 * pw_display.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_display_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'display_ad_administration';
  $view->description = 'Views Bulk Admin for Display Ads';
  $view->tag = 'default, admin, pwadmin, pw';
  $view->base_table = 'node';
  $view->human_name = 'Display Ad Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Display Ads Overview';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'status' => 'status',
    'publish_on' => 'status',
    'field_display_ad' => 'field_display_ad',
    'field_section_all_select' => 'field_display_ad',
    'field_tags' => 'field_display_ad',
    'field_display_ad_type' => 'field_display_ad_type',
    'field_publish_date' => 'field_publish_date',
    'field_ad_client' => 'field_ad_client',
    'view_node' => 'field_ad_client',
    'unpublish_on' => 'unpublish_on',
    'views_bulk_operations' => 'views_bulk_operations',
    'edit_node' => 'views_bulk_operations',
    'nid' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'publish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_ad' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'field_section_all_select' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_ad_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publish_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ad_client' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'unpublish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'NEW';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '<span class=\'marker\'>NEW</span>';
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Scheduler: Publish on */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['label'] = 'Publishing';
  $handler->display->display_options['fields']['publish_on']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['publish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['publish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'short';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = 'Ad';
  $handler->display->display_options['fields']['field_display_ad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_display_ad']['field_api_classes'] = 0;
  /* Field: Content: Section Selector */
  $handler->display->display_options['fields']['field_section_all_select']['id'] = 'field_section_all_select';
  $handler->display->display_options['fields']['field_section_all_select']['table'] = 'field_data_field_section_all_select';
  $handler->display->display_options['fields']['field_section_all_select']['field'] = 'field_section_all_select';
  $handler->display->display_options['fields']['field_section_all_select']['label'] = '';
  $handler->display->display_options['fields']['field_section_all_select']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['text'] = 'All Areas';
  $handler->display->display_options['fields']['field_section_all_select']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_section_all_select']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_section_all_select']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_section_all_select']['field_api_classes'] = 0;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_tags']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_tags']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_tags']['field_api_classes'] = 0;
  /* Field: Content: Display Ad Type */
  $handler->display->display_options['fields']['field_display_ad_type']['id'] = 'field_display_ad_type';
  $handler->display->display_options['fields']['field_display_ad_type']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['fields']['field_display_ad_type']['field'] = 'field_display_ad_type';
  $handler->display->display_options['fields']['field_display_ad_type']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_ad_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_ad_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_display_ad_type']['field_api_classes'] = 0;
  /* Field: Content: Publishing Date */
  $handler->display->display_options['fields']['field_publish_date']['id'] = 'field_publish_date';
  $handler->display->display_options['fields']['field_publish_date']['table'] = 'field_data_field_publish_date';
  $handler->display->display_options['fields']['field_publish_date']['field'] = 'field_publish_date';
  $handler->display->display_options['fields']['field_publish_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_publish_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_publish_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_publish_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_publish_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_publish_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_publish_date']['field_api_classes'] = 0;
  /* Field: Content: Client */
  $handler->display->display_options['fields']['field_ad_client']['id'] = 'field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['table'] = 'field_data_field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['field'] = 'field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_client']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_client']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_client']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_client']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_client']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Customer Link';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'CLIENT LINK';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'em';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'field-display-link field-display-client-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  /* Field: Scheduler: Unpublish on */
  $handler->display->display_options['fields']['unpublish_on']['id'] = 'unpublish_on';
  $handler->display->display_options['fields']['unpublish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['unpublish_on']['field'] = 'unpublish_on';
  $handler->display->display_options['fields']['unpublish_on']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['external'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['date_format'] = 'short';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'EDIT';
  /* Field: Link: Clone */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Link: Clone';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'CLONE';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]/clone';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'clone-link';
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Sort criterion: Content: Published */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Sort criterion: Scheduler: Unpublish on */
  $handler->display->display_options['sorts']['unpublish_on']['id'] = 'unpublish_on';
  $handler->display->display_options['sorts']['unpublish_on']['table'] = 'scheduler';
  $handler->display->display_options['sorts']['unpublish_on']['field'] = 'unpublish_on';
  /* Contextual filter: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['arguments']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'target' => 'target',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = '0';
  $handler->display->display_options['filters']['field_display_ad_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['operator_id'] = 'field_display_ad_type_value_op';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['label'] = 'Display Ad Type (field_display_ad_type)';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['operator'] = 'field_display_ad_type_value_op';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['identifier'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['multiple'] = FALSE;

  /* Display: Display Page */
  $handler = $view->new_display('page', 'Display Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'all' => 'all',
    'banner' => 'banner',
    'poster' => 'poster',
    'print' => 'print',
    'splash' => 'splash',
    'target' => 'target',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = '0';
  $handler->display->display_options['filters']['field_display_ad_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['operator_id'] = 'field_display_ad_type_value_op';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['label'] = 'Display Ad Type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['operator'] = 'field_display_ad_type_value_op';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['identifier'] = 'display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'admin/pennywise/display_ads';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Display Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pw-admin';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Display Ads';
  $handler->display->display_options['tab_options']['description'] = 'Show All Display Ads';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-pw-admin';
  $export['display_ad_administration'] = $view;

  $view = new view;
  $view->name = 'display_ad_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Display Ad Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'display_ad_banner',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['field_api_classes'] = 0;
  /* Sort criterion: Content: Section (field_tags) */
  $handler->display->display_options['sorts']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['sorts']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['sorts']['field_tags_tid']['field'] = 'field_tags_tid';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '-2';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'print' => 'print',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = '0';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = '0';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'classification';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';

  /* Display: Poster Block */
  $handler = $view->new_display('block', 'Poster Block', 'poster_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'display_ad_poster',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'poster' => 'poster',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;

  /* Display: Banner Block */
  $handler = $view->new_display('block', 'Banner Block', 'banner_block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = FALSE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'display_ad_blocks:banner_all_block';
  $handler->display->display_options['empty']['view']['inherit_arguments'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '-2';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'banner' => 'banner',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Banner Block w/TID';

  /* Display: Splash Block */
  $handler = $view->new_display('block', 'Splash Block', 'splash_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'display_ad_splash',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'splash' => 'splash',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;

  /* Display: Print Block */
  $handler = $view->new_display('block', 'Print Block', 'print_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class'] = 'display-ad-print-grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_display_ad']['element_class'] = 'display-ad-thumbnail';
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'display_ad_print_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['field_api_classes'] = 0;
  /* Field: Client */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['ui_name'] = 'Client';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '[term_node_tid]
';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['type'] = 'ul';
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'area' => 0,
    'classification' => 0,
    'client' => 0,
    'tags' => 0,
  );
  /* Field: Content: Ad Copy */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['label'] = '';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_ad_copy']['settings'] = array(
    'trim_length' => '60',
  );
  $handler->display->display_options['fields']['field_ad_copy']['field_api_classes'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'print' => 'print',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;

  /* Display: Poster Filler */
  $handler = $view->new_display('block', 'Poster Filler', 'poster_filler');
  $handler->display->display_options['display_description'] = 'Random Pennywise poster ads - as filler';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'poster' => 'poster',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;
  /* Filter criterion: Content: Client (field_ad_client) */
  $handler->display->display_options['filters']['field_ad_client_tid']['id'] = 'field_ad_client_tid';
  $handler->display->display_options['filters']['field_ad_client_tid']['table'] = 'field_data_field_ad_client';
  $handler->display->display_options['filters']['field_ad_client_tid']['field'] = 'field_ad_client_tid';
  $handler->display->display_options['filters']['field_ad_client_tid']['value'] = array(
    83 => '83',
  );
  $handler->display->display_options['filters']['field_ad_client_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ad_client_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_ad_client_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ad_client_tid']['vocabulary'] = 'client';
  $handler->display->display_options['filters']['field_ad_client_tid']['hierarchy'] = 1;

  /* Display: Banner ALL Block */
  $handler = $view->new_display('block', 'Banner ALL Block', 'banner_all_block');
  $handler->display->display_options['display_description'] = 'for all areas - no taxonomy restriction';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['filters']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['filters']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['value'] = array(
    'banner' => 'banner',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Banner Block w/TID';
  $export['display_ad_blocks'] = $view;

  return $export;
}
