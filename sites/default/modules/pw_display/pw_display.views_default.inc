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
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Display Ad Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Display Ads Overview';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'status' => 'status',
    'field_display_ad' => 'field_display_ad',
    'field_section_all_select' => 'field_display_ad',
    'field_tags' => 'field_display_ad',
    'field_display_ad_type' => 'field_display_ad_type',
    'title' => 'title',
    'field_ad_client' => 'field_ad_client',
    'view_node' => 'field_ad_client',
    'publish_on' => 'publish_on',
    'publish_countdown' => 'publish_on',
    'unpublish_on' => 'unpublish_on',
    'unpublish_countdown' => 'unpublish_on',
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
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
    'publish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'publish_countdown' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'unpublish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'unpublish_countdown' => array(
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  /* Field: Scheduler: Publish on */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['publish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['publish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'long';
  /* Field: Scheduler: Publish countdown */
  $handler->display->display_options['fields']['publish_countdown']['id'] = 'publish_countdown';
  $handler->display->display_options['fields']['publish_countdown']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_countdown']['field'] = 'publish_countdown';
  $handler->display->display_options['fields']['publish_countdown']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['unpublish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['date_format'] = 'long';
  /* Field: Scheduler: Unpublish countdown */
  $handler->display->display_options['fields']['unpublish_countdown']['id'] = 'unpublish_countdown';
  $handler->display->display_options['fields']['unpublish_countdown']['table'] = 'scheduler';
  $handler->display->display_options['fields']['unpublish_countdown']['field'] = 'unpublish_countdown';
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['external'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['hide_alter_empty'] = 1;
  /* Field: Content: Bulk operations */
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
    'node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_publish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpublish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpublish_by_keyword_action' => array(
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

  /* Display: Display Page */
  $handler = $view->new_display('page', 'Display Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Display Ad Type (field_display_ad_type) */
  $handler->display->display_options['arguments']['field_display_ad_type_value']['id'] = 'field_display_ad_type_value';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['table'] = 'field_data_field_display_ad_type';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['field'] = 'field_display_ad_type_value';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_display_ad_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['summary_options']['base_path'] = 'pwadmin/display_ads';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_display_ad_type_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_display_ad_type_value']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_display_ad_type_value']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['path'] = 'pwadmin/display_ads';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Display Ad Administration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pw-admin';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Display Ads';
  $handler->display->display_options['tab_options']['description'] = 'Show All Display Ads';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: DisplayTab */
  $handler = $view->new_display('page', 'DisplayTab', 'displaytab');
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
  $handler->display->display_options['path'] = 'pwadmin/display_ads/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Dashboard';
  $handler->display->display_options['menu']['weight'] = '-40';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Display Ad Parent';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: All Display Tab */
  $handler = $view->new_display('page', 'All Display Tab', 'alldisplay');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_section_all_select']['alter']['alter_text'] = 1;
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
  $handler->display->display_options['fields']['field_section_all_select']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_section_all_select']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_section_all_select']['hide_alter_empty'] = 1;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  /* Field: Scheduler: Publish on */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['publish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['publish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'long';
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
  $handler->display->display_options['fields']['unpublish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['date_format'] = 'long';
  /* Field: Scheduler: Unpublish countdown */
  $handler->display->display_options['fields']['unpublish_countdown']['id'] = 'unpublish_countdown';
  $handler->display->display_options['fields']['unpublish_countdown']['table'] = 'scheduler';
  $handler->display->display_options['fields']['unpublish_countdown']['field'] = 'unpublish_countdown';
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['external'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['filters']['field_display_ad_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['operator_id'] = 'field_display_ad_type_value_op';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['label'] = 'Display Ad Type ';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['operator'] = 'field_display_ad_type_value_op';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['identifier'] = 'field_display_ad_type_value';
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_display_ad_type_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'pwadmin/display_ads/display';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All Display Ads';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Target */
  $handler = $view->new_display('page', 'Target', 'target');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'pwadmin/display_ads/target';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Target Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Video */
  $handler = $view->new_display('page', 'Video', 'video');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Video Ads Administration';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'pwadmin/display_ads/video';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Video Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Splash */
  $handler = $view->new_display('page', 'Splash', 'splash');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Splash Ads Administration';
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
    'splash' => 'splash',
  );
  $handler->display->display_options['path'] = 'pwadmin/display_ads/splash';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Splash Ads';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Print */
  $handler = $view->new_display('page', 'Print', 'print');
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
    'print' => 'print',
  );
  $handler->display->display_options['path'] = 'pwadmin/display_ads/print';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Print Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Poster */
  $handler = $view->new_display('page', 'Poster', 'poster');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Poster Ads Administration';
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
    'poster' => 'poster',
  );
  $handler->display->display_options['path'] = 'pwadmin/display_ads/poster';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Poster Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Banner */
  $handler = $view->new_display('page', 'Banner', 'banner');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Banner Ad Administration';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_section_all_select']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_section_all_select']['alter']['alter_text'] = 1;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  /* Field: Scheduler: Publish on */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['publish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['publish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'long';
  /* Field: Scheduler: Publish countdown */
  $handler->display->display_options['fields']['publish_countdown']['id'] = 'publish_countdown';
  $handler->display->display_options['fields']['publish_countdown']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_countdown']['field'] = 'publish_countdown';
  $handler->display->display_options['fields']['publish_countdown']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['publish_countdown']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_countdown']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['unpublish_on']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_on']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['unpublish_on']['date_format'] = 'long';
  /* Field: Scheduler: Unpublish countdown */
  $handler->display->display_options['fields']['unpublish_countdown']['id'] = 'unpublish_countdown';
  $handler->display->display_options['fields']['unpublish_countdown']['table'] = 'scheduler';
  $handler->display->display_options['fields']['unpublish_countdown']['field'] = 'unpublish_countdown';
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['external'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['alter']['html'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['unpublish_countdown']['hide_empty'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['empty_zero'] = 0;
  $handler->display->display_options['fields']['unpublish_countdown']['hide_alter_empty'] = 1;
  /* Field: Content: Bulk operations */
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
    'node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_publish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpublish_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'node_unpublish_by_keyword_action' => array(
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
    'banner' => 'banner',
  );
  $handler->display->display_options['path'] = 'pwadmin/display_ads/banner';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Banner Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['display_ad_administration'] = $view;

  return $export;
}
