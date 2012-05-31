<?php
/**
 * @file
 * pw_cl.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_cl_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'search_ads';
  $view->description = 'Override default search with view.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search Ads';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Ads';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_tags',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_ad_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'search-result-row';
  $handler->display->display_options['style_options']['class'] = 'search-result-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'search-result-wrapper';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_ad_type' => 'field_ad_type',
    'field_tags' => 'field_tags',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'lightbox2__lightbox__medium__large';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['delta_limit'] = 'all';
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Classified Ad Type */
  $handler->display->display_options['fields']['field_ad_type']['id'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['field'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['label'] = '';
  $handler->display->display_options['fields']['field_ad_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['field_api_classes'] = 0;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tags']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_tags']['element_class'] = 'search-classified-section-header';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_tags']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_tags']['field_api_classes'] = 0;
  /* Field: Content: Ad Copy */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['label'] = '';
  $handler->display->display_options['fields']['field_ad_copy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['element_type'] = '0';
  $handler->display->display_options['fields']['field_ad_copy']['element_class'] = 'ad';
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['settings'] = array(
    'trim_length' => '110',
  );
  $handler->display->display_options['fields']['field_ad_copy']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'classified-more-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'more';
  /* Field: Global: Body &amp; Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Body & Link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_ad_copy] <span class=\'classified-more-link\'>[view_node]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'classified-ad-copy';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Field: Phone Number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_phone']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_phone']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['group_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_phone']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_phone']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_phone']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = 0;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_email']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_email']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_email']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_email']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_email']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_email']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
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
  $handler->display->display_options['fields']['field_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_image' => 0,
    'field_ad_type' => 0,
    'field_tags' => 0,
    'field_ad_copy' => 0,
    'view_node' => 0,
    'nothing' => 0,
    'field_phone' => 0,
    'field_email' => 0,
    'field_link' => 0,
    'type' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
  /* Sort criterion: Field: Header Image (field_image:fid) */
  $handler->display->display_options['sorts']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['sorts']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'classified' => 'classified',
    'display_ads' => 'display_ads',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Ad Copy (field_ad_copy) */
  $handler->display->display_options['filters']['field_ad_copy_value']['id'] = 'field_ad_copy_value';
  $handler->display->display_options['filters']['field_ad_copy_value']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['filters']['field_ad_copy_value']['field'] = 'field_ad_copy_value';
  $handler->display->display_options['filters']['field_ad_copy_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_ad_copy_value']['group'] = '0';
  $handler->display->display_options['filters']['field_ad_copy_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['operator_id'] = 'field_ad_copy_value_op';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['label'] = 'Search classified ads:';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['operator'] = 'field_ad_copy_value_op';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['identifier'] = 'search_ads';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['required'] = 1;
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'search_page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search';
  $export['search_ads'] = $view;

  $view = new view;
  $view->name = 'section_pages';
  $view->description = 'Using default Drupal taxonomy/term [override] pages for Classified Ad layout.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Section Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_tags',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'row-type-[field_ad_type]';
  $handler->display->display_options['style_options']['class'] = 'classified-ad-section';
  $handler->display->display_options['style_options']['wrapper_class'] = 'classified-ad-header';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'classified-list-style',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image_1']['delta_limit'] = 'all';
  $handler->display->display_options['fields']['field_image_1']['field_api_classes'] = 0;
  /* Field: Content: Publish link */
  $handler->display->display_options['fields']['publishcontent']['id'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['table'] = 'node';
  $handler->display->display_options['fields']['publishcontent']['field'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['label'] = '';
  $handler->display->display_options['fields']['publishcontent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publishcontent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publishcontent']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publishcontent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publishcontent']['element_type'] = 'div';
  $handler->display->display_options['fields']['publishcontent']['element_class'] = 'field-publish-link inline-x-delete-link';
  $handler->display->display_options['fields']['publishcontent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['publishcontent']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['publishcontent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publishcontent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publishcontent']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['publishcontent']['unpublish'] = 'X';
  $handler->display->display_options['fields']['publishcontent']['publish'] = 'O';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'classified-more-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'more';
  /* Field: Content: Ad Copy [Rewrite] */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['ui_name'] = 'Content: Ad Copy [Rewrite]';
  $handler->display->display_options['fields']['field_ad_copy']['label'] = '';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['text'] = '[field_ad_copy] <span class=\'classified-more-link\'>[view_node]</span>';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_ad_copy']['element_class'] = 'classified-ad-copy';
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['field_ad_copy']['field_api_classes'] = 0;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tags']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tags']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_tags']['element_class'] = 'classified-ad-section';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_tags']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_tags']['field_api_classes'] = 0;
  /* Field: Content: Ad Type: Liveload CSS Class */
  $handler->display->display_options['fields']['field_ad_type']['id'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['field'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['ui_name'] = 'Content: Ad Type: Liveload CSS Class';
  $handler->display->display_options['fields']['field_ad_type']['label'] = '';
  $handler->display->display_options['fields']['field_ad_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['text'] = 'liveload';
  $handler->display->display_options['fields']['field_ad_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['field_api_classes'] = 0;
  /* Field: Content: Ad Type: Liveload Footer */
  $handler->display->display_options['fields']['field_ad_type_1']['id'] = 'field_ad_type_1';
  $handler->display->display_options['fields']['field_ad_type_1']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['fields']['field_ad_type_1']['field'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type_1']['ui_name'] = 'Content: Ad Type: Liveload Footer';
  $handler->display->display_options['fields']['field_ad_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['text'] = '<div class="[field_ad_type]-footer">LIVELOAD AD</div>';
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_type_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['empty'] = '<span class=\'footer\'></span>';
  $handler->display->display_options['fields']['field_ad_type_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_type_1']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_ad_type_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_type_1']['field_api_classes'] = 0;
  /* Field: Global: Rewrite Classified Ad Output */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Rewrite Classified Ad Output';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class=\'classified-ad ad-type-[field_ad_type] section-%1\'>
[field_image]
<div class=\'classified-ad-copy\'><!-- [edit_node]--> [field_ad_copy]</div>
[field_ad_type_1]
</div>
';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 1;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class=\'edit-link edit-link-small\'>edit</span>';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link edit-link-small';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_image' => 0,
    'field_ad_copy' => 0,
    'field_tags' => 0,
    'field_ad_type' => 0,
    'field_ad_type_1' => 0,
    'publishcontent' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
  /* Sort criterion: Content: Section (field_tags) */
  $handler->display->display_options['sorts']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['sorts']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['sorts']['field_tags_tid']['field'] = 'field_tags_tid';
  /* Sort criterion: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['sorts']['field_ad_type_value_1']['id'] = 'field_ad_type_value_1';
  $handler->display->display_options['sorts']['field_ad_type_value_1']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['sorts']['field_ad_type_value_1']['field'] = 'field_ad_type_value';
  $handler->display->display_options['sorts']['field_ad_type_value_1']['order'] = 'DESC';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['sorts']['field_ad_type_value']['id'] = 'field_ad_type_value';
  $handler->display->display_options['sorts']['field_ad_type_value']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['sorts']['field_ad_type_value']['field'] = 'field_ad_type_value';
  $handler->display->display_options['sorts']['field_ad_type_value']['order'] = 'DESC';
  /* Sort criterion: Field: Header Image (field_image:fid) */
  $handler->display->display_options['sorts']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['sorts']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = '1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '3';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'classified' => 'classified',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Section Page */
  $handler = $view->new_display('page', 'Section Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'classified' => 'classified',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['filters']['field_ad_type_value']['id'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['filters']['field_ad_type_value']['field'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = 1;
  $export['section_pages'] = $view;

  return $export;
}
