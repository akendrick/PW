<?php
/**
 * @file
 * pw_digital.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_digital_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'edition_viewer';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Edition Viewer';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pennywise Digital Edition';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['text'] = 'Castlegar Edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['path'] = 'edition/latest/castlegar';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['link_class'] = 'latest-edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_castlegar_edition']['type'] = 'text_plain';
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['text'] = 'Nelson & Area Edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['path'] = 'edition/latest/nelson';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['type'] = 'text_plain';
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['text'] = 'Nelson Edition';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['path'] = 'edition/latest/nelson-area';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nelson_edition']['type'] = 'text_plain';
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['text'] = 'Trail & Area Edition';
  $handler->display->display_options['fields']['field_trail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['path'] = 'edition/latest/trail-area';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  /* Field: Content: Attach File */
  $handler->display->display_options['fields']['field_special_feature_link']['id'] = 'field_special_feature_link';
  $handler->display->display_options['fields']['field_special_feature_link']['table'] = 'field_data_field_special_feature_link';
  $handler->display->display_options['fields']['field_special_feature_link']['field'] = 'field_special_feature_link';
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pw_digital' => 'pw_digital',
  );

  /* Display: Archive */
  $handler = $view->new_display('page', 'Archive', 'page_edition_archive');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_castlegar_edition' => 'field_castlegar_edition',
    'field_kootenay_lake_edition' => 'field_kootenay_lake_edition',
    'field_nelson_edition' => 'field_nelson_edition',
    'field_trail' => 'field_trail',
    'field_special_feature_link_1' => 'field_special_feature_link_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_castlegar_edition' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_kootenay_lake_edition' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nelson_edition' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_special_feature_link_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['text'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['path'] = 'edition/castlegar-slocan/[nid]';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['link_class'] = 'latest-edition button';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_castlegar_edition']['type'] = 'text_plain';
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['text'] = 'Kootenay Lake';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['path'] = 'edition/kootenay-lake/[nid]';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['type'] = 'text_plain';
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['text'] = 'Nelson Edition';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['path'] = 'edition/nelson-salmo/[nid]';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_nelson_edition']['element_class'] = 'button';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nelson_edition']['type'] = 'text_plain';
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['text'] = 'Trail, Beaver Valley & Rossland';
  $handler->display->display_options['fields']['field_trail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['path'] = 'edition/trail-area/[nid]';
  $handler->display->display_options['fields']['field_trail']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  /* Field: Content: References */
  $handler->display->display_options['fields']['field_entity_reference']['id'] = 'field_entity_reference';
  $handler->display->display_options['fields']['field_entity_reference']['table'] = 'field_data_field_entity_reference';
  $handler->display->display_options['fields']['field_entity_reference']['field'] = 'field_entity_reference';
  $handler->display->display_options['fields']['field_entity_reference']['label'] = '';
  $handler->display->display_options['fields']['field_entity_reference']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_entity_reference']['alter']['path'] = 'node/[field_entity_reference-target_id]';
  $handler->display->display_options['fields']['field_entity_reference']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_entity_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_entity_reference']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_entity_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_entity_reference']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_entity_reference']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_entity_reference']['multi_type'] = 'ol';
  $handler->display->display_options['path'] = 'edition';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Browse Past Editions';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: C Page */
  $handler = $view->new_display('page', 'C Page', 'edition_page_c');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Castlegar & Slocan Valley Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'castlegar_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'edition/castlegar-slocan';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: T Page */
  $handler = $view->new_display('page', 'T Page', 'edition_page_t');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trail, Beaver Valley & Rossland Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'trail_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'edition/trail-area';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Trail, Beaver Valley & Rossland';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: N Page */
  $handler = $view->new_display('page', 'N Page', 'edition_page_n');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nelson & Salmo Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'nelson_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'edition/nelson-salmo';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Nelson & Salmo';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: K Page */
  $handler = $view->new_display('page', 'K Page', 'edition_page_kl');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'kootenay_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'edition/kootenay-lake';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Kootenay Lake';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Hometown */
  $handler = $view->new_display('page', 'Hometown', 'page_hometown');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hometown';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'attachment' => 'attachment',
  );
  /* Filter criterion: Content: Feature Type (field_feature_type) */
  $handler->display->display_options['filters']['field_feature_type_value']['id'] = 'field_feature_type_value';
  $handler->display->display_options['filters']['field_feature_type_value']['table'] = 'field_data_field_feature_type';
  $handler->display->display_options['filters']['field_feature_type_value']['field'] = 'field_feature_type_value';
  $handler->display->display_options['filters']['field_feature_type_value']['value'] = array(
    'hometown' => 'hometown',
  );
  $handler->display->display_options['path'] = 'edition/hometown';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Hometown';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['name'] = 'menu-special-features';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: C1 */
  $handler = $view->new_display('page', 'C1', 'c1_idiv_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Castlegar & Slocan Valley Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'castlegar_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['path'] = 'edition/castlegar-slocan/%';
  $handler->display->display_options['menu']['title'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: T1 */
  $handler = $view->new_display('page', 'T1', 't1_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trail and Salmo Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'trail_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['path'] = 'edition/trail-area/%';
  $handler->display->display_options['menu']['title'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: N1 */
  $handler = $view->new_display('page', 'N1', 'n1_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nelson & Salmo Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'nelson_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['path'] = 'edition/nelson-salmo/%';
  $handler->display->display_options['menu']['title'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: K1 */
  $handler = $view->new_display('page', 'K1', 'k1_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kootenay Lake - Pennywise Digital Edition';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'nelson_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['path'] = 'edition/kootenay-lake/%';
  $handler->display->display_options['menu']['title'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Carolling */
  $handler = $view->new_display('page', 'Carolling', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Carolling';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'special_feature';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'attachment' => 'attachment',
  );
  /* Filter criterion: Content: Feature Type (field_feature_type) */
  $handler->display->display_options['filters']['field_feature_type_value']['id'] = 'field_feature_type_value';
  $handler->display->display_options['filters']['field_feature_type_value']['table'] = 'field_data_field_feature_type';
  $handler->display->display_options['filters']['field_feature_type_value']['field'] = 'field_feature_type_value';
  $handler->display->display_options['filters']['field_feature_type_value']['value'] = array(
    'carolling' => 'carolling',
  );
  $handler->display->display_options['path'] = 'edition/carolling';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Carolling';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['name'] = 'menu-special-features';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['edition_viewer'] = $view;

  return $export;
}
