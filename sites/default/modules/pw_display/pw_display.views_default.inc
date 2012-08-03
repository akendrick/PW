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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Cover */
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
  $handler->display->display_options['fields']['field_display_ad']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['more_link'] = 0;
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
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'field_link' => 0,
    'field_display_ad' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
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

  /* Display: Poster Block */
  $handler = $view->new_display('block', 'Poster Block', 'poster_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Poster Block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href=\'http://localhost:8888/pw7/advertising-information/sales\' class=\'poster-block-advertising-link\'>See your ad here<br>Advertise with Pennywise!</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Cover */
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
  $handler->display->display_options['fields']['field_display_ad']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['more_link'] = 0;
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
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'field_link' => 0,
    'field_display_ad' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
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
  $handler->display->display_options['block_description'] = 'Poster (with filler) Block';

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
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'display_ad_blocks:banner_default_filler';
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
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = '1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'ignore';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Cover */
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
  $handler->display->display_options['fields']['field_display_ad']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['more_link'] = 0;
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
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'field_link' => 0,
    'field_display_ad' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
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
  $handler->display->display_options['block_description'] = 'Splash Block';

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
  /* Field: Content: Cover */
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
  $handler->display->display_options['block_description'] = 'Print Block';

  /* Display: Poster Filler */
  $handler = $view->new_display('block', 'Poster Filler', 'poster_filler');
  $handler->display->display_options['display_description'] = 'Random Pennywise poster ads - as filler';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="poster-block block-title poster-block-title">Advertising Here!</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Cover */
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
  $handler->display->display_options['fields']['field_display_ad']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['more_link'] = 0;
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
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'field_link' => 0,
    'field_display_ad' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
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
  $handler->display->display_options['block_description'] = 'Poster Filler Block';

  /* Display: Banner Default */
  $handler = $view->new_display('block', 'Banner Default', 'banner_default_filler');
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
  $handler->display->display_options['block_description'] = 'Banner Filler Block';

  /* Display: Splash Block 2 */
  $handler = $view->new_display('block', 'Splash Block 2', 'block_1');
  $handler->display->display_options['display_description'] = 'Overflow splash block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_link']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_link']['field_api_classes'] = 0;
  /* Field: Content: Cover */
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
  $handler->display->display_options['fields']['field_display_ad']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_display_ad']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_ad']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_ad']['alter']['more_link'] = 0;
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
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'field_link' => 0,
    'field_display_ad' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
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
  $handler->display->display_options['block_description'] = 'Splash Overflow Block';
  $export['display_ad_blocks'] = $view;

  return $export;
}
