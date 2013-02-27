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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'nid' => 0,
    'field_link' => 0,
    'field_display_ad' => 0,
    'edit_node' => 0,
    'delete_node' => 0,
  );
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Sort criterion: Content: Client (field_ad_client) */
  $handler->display->display_options['sorts']['field_ad_client_tid']['id'] = 'field_ad_client_tid';
  $handler->display->display_options['sorts']['field_ad_client_tid']['table'] = 'field_data_field_ad_client';
  $handler->display->display_options['sorts']['field_ad_client_tid']['field'] = 'field_ad_client_tid';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '-2';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href=\'http://localhost:8888/pw7/advertising-information/sales\' class=\'poster-block-advertising-link\'>See your ad here<br>Advertise with Pennywise!</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'display_ad_blocks:banner_default_filler';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '-2';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = 'both';
  $handler->display->display_options['style_options']['skin'] = 'print';
  $handler->display->display_options['style_options']['visible'] = '4';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['auto'] = '8';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Display Ad File Link */
  $handler->display->display_options['fields']['field_display_ad_1']['id'] = 'field_display_ad_1';
  $handler->display->display_options['fields']['field_display_ad_1']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad_1']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad_1']['ui_name'] = 'Content: Display Ad File Link';
  $handler->display->display_options['fields']['field_display_ad_1']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_display_ad_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['text'] = '[field_display_ad]<br>
[field_ad_client]<br>
[field_ad_copy]<br>
';
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['type'] = 'lightbox2__lightbox__display_ad_print_thumbnail__original';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'display_ad_print_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Client */
  $handler->display->display_options['fields']['field_ad_client']['id'] = 'field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['table'] = 'field_data_field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['field'] = 'field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['label'] = '';
  $handler->display->display_options['fields']['field_ad_client']['alter']['text'] = '<a href="[field_display_ad_1]" 
rel="lightbox[_field_display_ad]<p><a href= title class="lightbox-processed" http: pennywiseads.com sites default files images display>"
>[field_ad_client]</a>';
  $handler->display->display_options['fields']['field_ad_client']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ad_client']['alter']['path'] = '[field_display_ad_1] ';
  $handler->display->display_options['fields']['field_ad_client']['alter']['rel'] = 'lightshow';
  $handler->display->display_options['fields']['field_ad_client']['element_type'] = 'h6';
  $handler->display->display_options['fields']['field_ad_client']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_client']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ad_client']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Ad Copy */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['label'] = '';
  $handler->display->display_options['fields']['field_ad_copy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['path'] = '[field_display_ad_1]';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['rel'] = 'lightshow';
  $handler->display->display_options['fields']['field_ad_copy']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_ad_copy']['settings'] = array(
    'trim_length' => '30',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<a href="[field_display_ad_1]" 
rel="lightbox[field_display_ad_1]%5B<p><a href=\'[field_display_ad_1]\'Download Original</a></p>%5D" title class="lightbox-processed views-ajax-processed-processed">
[field_ad_client]<br>[field_ad_copy]
</a>';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_class'] = '.button-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'MORE';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Client (field_ad_client) */
  $handler->display->display_options['sorts']['field_ad_client_tid']['id'] = 'field_ad_client_tid';
  $handler->display->display_options['sorts']['field_ad_client_tid']['table'] = 'field_data_field_ad_client';
  $handler->display->display_options['sorts']['field_ad_client_tid']['field'] = 'field_ad_client_tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="poster-block block-title poster-block-title">Advertising Here!</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'file_view_mode' => 'media_original',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['filters']['field_ad_client_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ad_client_tid']['vocabulary'] = 'client';
  $handler->display->display_options['filters']['field_ad_client_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Poster Filler Block';

  /* Display: Banner filler */
  $handler = $view->new_display('block', 'Banner filler', 'banner_default_filler');
  $handler->display->display_options['display_description'] = 'for all areas - no taxonomy restriction';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'file_view_mode' => 'media_original',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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

  /* Display: Target Block */
  $handler = $view->new_display('block', 'Target Block', 'target_block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'target' => 'target',
  );
  $handler->display->display_options['filters']['field_display_ad_type_value']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Target Block ';

  /* Display: Front Poster Block (2) */
  $handler = $view->new_display('block', 'Front Poster Block (2)', 'front_mulitiple_poster_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Poster Block';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href=\'http://localhost:8888/pw7/advertising-information/sales\' class=\'poster-block-advertising-link\'>See your ad here<br>Advertise with Pennywise!</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['block_description'] = 'Front Page Poster (2) Block';

  /* Display: FRONT Page Banner  */
  $handler = $view->new_display('block', 'FRONT Page Banner ', 'front_banner_block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'display_ad_blocks:banner_default_filler';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'classification' => 'classification',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '-2';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['block_description'] = 'FRONT Banner Block';

  /* Display: Front Poster Block (1) */
  $handler = $view->new_display('block', 'Front Poster Block (1)', 'front_1poster_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Poster Block';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href=\'http://localhost:8888/pw7/advertising-information/sales\' class=\'poster-block-advertising-link\'>See your ad here<br>Advertise with Pennywise!</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['empty'] = 'http://pennywiseads.com/node/[nid]';
  $handler->display->display_options['fields']['field_link']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['path'] = '[field_link]';
  $handler->display->display_options['fields']['field_display_ad']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['block_description'] = 'Front Page Poster (2) Block';

  /* Display: FRONT Print Block */
  $handler = $view->new_display('block', 'FRONT Print Block', 'front_print_block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = 'both';
  $handler->display->display_options['style_options']['skin'] = 'tango';
  $handler->display->display_options['style_options']['visible'] = '5';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['auto'] = '10';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['style_options']['ajax'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Display Ad File Link */
  $handler->display->display_options['fields']['field_display_ad_1']['id'] = 'field_display_ad_1';
  $handler->display->display_options['fields']['field_display_ad_1']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad_1']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad_1']['ui_name'] = 'Content: Display Ad File Link';
  $handler->display->display_options['fields']['field_display_ad_1']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_ad_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_display_ad_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Display Ad */
  $handler->display->display_options['fields']['field_display_ad']['id'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['table'] = 'field_data_field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['field'] = 'field_display_ad';
  $handler->display->display_options['fields']['field_display_ad']['label'] = '';
  $handler->display->display_options['fields']['field_display_ad']['alter']['text'] = '[field_display_ad]<br>
[field_ad_client]<br>
[field_ad_copy]<br>
';
  $handler->display->display_options['fields']['field_display_ad']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_display_ad']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_display_ad']['type'] = 'lightbox2__lightbox__display_ad_print_thumbnail__original';
  $handler->display->display_options['fields']['field_display_ad']['settings'] = array(
    'image_style' => 'display_ad_print_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_display_ad']['group_column'] = 'fid';
  /* Field: Content: Client */
  $handler->display->display_options['fields']['field_ad_client']['id'] = 'field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['table'] = 'field_data_field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['field'] = 'field_ad_client';
  $handler->display->display_options['fields']['field_ad_client']['label'] = '';
  $handler->display->display_options['fields']['field_ad_client']['alter']['text'] = '<a href="[field_display_ad_1]" 
rel="lightbox[_field_display_ad]<p><a href= title class="lightbox-processed" http: pennywiseads.com sites default files images display>"
>[field_ad_client]</a>';
  $handler->display->display_options['fields']['field_ad_client']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ad_client']['alter']['path'] = '[field_display_ad_1] ';
  $handler->display->display_options['fields']['field_ad_client']['alter']['rel'] = 'lightshow';
  $handler->display->display_options['fields']['field_ad_client']['element_type'] = 'h6';
  $handler->display->display_options['fields']['field_ad_client']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_client']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ad_client']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Ad Copy */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['label'] = '';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['path'] = '[field_display_ad_1]';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['rel'] = 'lightshow';
  $handler->display->display_options['fields']['field_ad_copy']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ad_copy']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_ad_copy']['settings'] = array(
    'trim_length' => '30',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<a href="[field_display_ad_1]" 
rel="lightbox[field_display_ad_1]%5B<p><a href=\'[field_display_ad_1]\'Download Original</a></p>%5D" title class="lightbox-processed views-ajax-processed-processed">
[field_ad_client]<br>[field_ad_copy]
</a>';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_class'] = '.button-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $export['display_ad_blocks'] = $view;

  return $export;
}
