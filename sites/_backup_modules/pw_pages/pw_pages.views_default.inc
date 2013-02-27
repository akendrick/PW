<?php
/**
 * @file
 * pw_pages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_pages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'digital_edition_pages';
  $view->description = 'Digital Edition Pag';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Digital Edition Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pennywise Area Edition';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'nelson_edition_view';
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'edition/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = '[field_edition_date] [field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_castlegar_edition']['element_default_classes'] = FALSE;
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  /* Field: Global: Custom Text: Link to Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom Text: Link to Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Entire Pennywise Digital Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'digital/archive';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'center button';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Edition Date (field_edition_date) */
  $handler->display->display_options['sorts']['field_edition_date_value']['id'] = 'field_edition_date_value';
  $handler->display->display_options['sorts']['field_edition_date_value']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['sorts']['field_edition_date_value']['field'] = 'field_edition_date_value';
  $handler->display->display_options['sorts']['field_edition_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_edition_date_value']['expose']['label'] = 'Edition Date (field_edition_date)';
  /* Contextual filter: Content: Edition Date (field_edition_date) */
  $handler->display->display_options['arguments']['field_edition_date_value']['id'] = 'field_edition_date_value';
  $handler->display->display_options['arguments']['field_edition_date_value']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['arguments']['field_edition_date_value']['field'] = 'field_edition_date_value';
  $handler->display->display_options['arguments']['field_edition_date_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_edition_date_value']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['field_edition_date_value']['summary']['number_of_records'] = '1';
  $handler->display->display_options['arguments']['field_edition_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_edition_date_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_edition_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_edition_date_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_edition_date_value']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['field_edition_date_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_edition_date_value']['use_fromto'] = 'no';
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
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: archive */
  $handler = $view->new_display('page', 'archive', 'edition_archive');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pennywise Digital Archive';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« Current';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '« Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next »';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_node' => 'field_edition_date_1',
    'field_edition_date_1' => 'field_edition_date_1',
    'contextual_links' => 'field_edition_date_1',
    'field_edition_date' => 'field_edition_date_1',
    'field_castlegar_edition' => 'field_castlegar_edition',
    'field_kootenay_lake_edition' => 'field_kootenay_lake_edition',
    'field_nelson_edition' => 'field_nelson_edition',
    'field_trail' => 'field_trail',
    'field_entity_reference' => 'field_edition_date_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_edition_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'contextual_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_edition_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
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
    'field_entity_reference' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'EDIT';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_edition_date_1' => 0,
    'field_edition_date' => 0,
    'field_castlegar_edition' => 0,
    'field_kootenay_lake_edition' => 0,
    'field_nelson_edition' => 0,
    'field_trail' => 0,
    'field_entity_reference' => 0,
  );
  /* Field: Content: Edition Date - Human Readable */
  $handler->display->display_options['fields']['field_edition_date_1']['id'] = 'field_edition_date_1';
  $handler->display->display_options['fields']['field_edition_date_1']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date_1']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date_1']['ui_name'] = 'Content: Edition Date - Human Readable';
  $handler->display->display_options['fields']['field_edition_date_1']['label'] = 'Edition';
  $handler->display->display_options['fields']['field_edition_date_1']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['text'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['path'] = 'edition/castlegar-slocan-valley/[field_edition_date] ';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['text'] = 'Kootenay Lake';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['path'] = 'edition/kootenay-lake/[field_edition_date]';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['text'] = 'Nelson & Salmo';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['path'] = 'edition/nelson-salmo/[field_edition_date]';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['text'] = 'Trail & Area';
  $handler->display->display_options['fields']['field_trail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['path'] = 'edition/trail-salmo-beaver-valley/[field_edition_date]';
  $handler->display->display_options['fields']['field_trail']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  /* Field: Content: References */
  $handler->display->display_options['fields']['field_entity_reference']['id'] = 'field_entity_reference';
  $handler->display->display_options['fields']['field_entity_reference']['table'] = 'field_data_field_entity_reference';
  $handler->display->display_options['fields']['field_entity_reference']['field'] = 'field_entity_reference';
  $handler->display->display_options['fields']['field_entity_reference']['label'] = '';
  $handler->display->display_options['fields']['field_entity_reference']['alter']['text'] = 'Special Insert';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'edition';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Digital Archive';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: T */
  $handler = $view->new_display('page_with_page_title', 'T', 'trail_edition');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trail & Area Pennywise';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'trail_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'edition/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = '[field_edition_date] [field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trail']['element_default_classes'] = FALSE;
  /* Field: Global: Custom Text: Link to Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom Text: Link to Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Entire Pennywise Digital Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'digital/archive';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'center button';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'edition/trail-beaver-valley-rossland';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Trail & Area';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: N */
  $handler = $view->new_display('page_with_page_title', 'N', 'nelson_edition');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nelson & Salmo Pennywise';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'edition/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = '[field_edition_date] [field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  /* Field: Global: Custom Text: Link to Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom Text: Link to Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Entire Pennywise Digital Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'digital/archive';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'center button';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'edition/nelson-salmo';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Nelson';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: C */
  $handler = $view->new_display('page_with_page_title', 'C', 'castlegar_editiion');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Castlegar & Slocan Valley Pennywise';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'castlegar_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'edition/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = '[field_edition_date] [field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_castlegar_edition']['element_default_classes'] = FALSE;
  /* Field: Global: Custom Text: Link to Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom Text: Link to Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Entire Pennywise Digital Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'digital/archive';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'center button';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'edition/castlegar-slocan-valley';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Castlegar, Slocan Valley';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: K */
  $handler = $view->new_display('page_with_page_title', 'K', 'kootenay_lake_edition');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kootenay Lake Pennywise';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'kootenay_edition_view';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'edition/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = '[field_edition_date] [field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  /* Field: Global: Custom Text: Link to Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom Text: Link to Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Entire Pennywise Digital Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'digital/archive';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'center button';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'pw_digital' => 'pw_digital',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'edition/kootenay-lake';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Kootenay Lake';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pennywise-digital-edition';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Recent Editions */
  $handler = $view->new_display('attachment', 'Recent Editions', 'recent_editions_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Previous Pennywise Editions';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_edition_date_1' => 'field_edition_date_1',
    'field_edition_date' => 'field_edition_date_1',
    'field_castlegar_edition' => 'field_castlegar_edition',
    'field_kootenay_lake_edition' => 'field_kootenay_lake_edition',
    'field_nelson_edition' => 'field_nelson_edition',
    'field_trail' => 'field_trail',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_edition_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_edition_date' => array(
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
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header';
  $handler->display->display_options['header']['area']['content'] = '<h4 class=\'digital-archive-header\'>Pennywise Digital Archive</h4>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date_1']['id'] = 'field_edition_date_1';
  $handler->display->display_options['fields']['field_edition_date_1']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date_1']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date_1']['label'] = 'Edition';
  $handler->display->display_options['fields']['field_edition_date_1']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['text'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['path'] = 'edition/castlegar-slocan-valley/[field_edition_date] ';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['link_class'] = 'button button-small';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['text'] = 'Kootenay Lake';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['path'] = 'edition/kootenay-lake/[field_edition_date] ';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['link_class'] = 'button button-small';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['text'] = 'Nelson & Salmo';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['path'] = 'edition/nelson-salmo/[field_edition_date]';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['link_class'] = 'button button-small';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['text'] = 'Trail & Rossland';
  $handler->display->display_options['fields']['field_trail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['path'] = 'edition/trail-beaver-valley-rossland/[field_edition_date]';
  $handler->display->display_options['fields']['field_trail']['alter']['link_class'] = 'button button-small';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Edition Date (field_edition_date) */
  $handler->display->display_options['sorts']['field_edition_date_value']['id'] = 'field_edition_date_value';
  $handler->display->display_options['sorts']['field_edition_date_value']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['sorts']['field_edition_date_value']['field'] = 'field_edition_date_value';
  $handler->display->display_options['sorts']['field_edition_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_edition_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'trail_edition' => 'trail_edition',
    'nelson_edition' => 'nelson_edition',
    'castlegar_editiion' => 'castlegar_editiion',
    'kootenay_lake_edition' => 'kootenay_lake_edition',
    'page_1' => 'page_1',
    'default' => 0,
    'edition_archive' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $handler->display->display_options['render_pager'] = TRUE;

  /* Display: Node Page */
  $handler = $view->new_display('page', 'Node Page', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'replace node with generic view';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_edition_date' => 'field_edition_date',
    'nid' => 'nid',
    'field_castlegar_edition' => 'field_castlegar_edition',
    'field_kootenay_lake_edition' => 'field_kootenay_lake_edition',
    'field_nelson_edition' => 'field_nelson_edition',
    'field_trail' => 'field_trail',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = '<br>';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edition Date */
  $handler->display->display_options['fields']['field_edition_date']['id'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['table'] = 'field_data_field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['field'] = 'field_edition_date';
  $handler->display->display_options['fields']['field_edition_date']['label'] = '';
  $handler->display->display_options['fields']['field_edition_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edition_date']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_edition_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'edition/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = '[field_edition_date] [field_area] Pennywise ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Castlegar Edition */
  $handler->display->display_options['fields']['field_castlegar_edition']['id'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['table'] = 'field_data_field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['field'] = 'field_castlegar_edition';
  $handler->display->display_options['fields']['field_castlegar_edition']['label'] = '';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['text'] = 'Castlegar & Slocan Valley';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['path'] = 'edition/castlegar-slocan-valley/[field_edition_date] ';
  $handler->display->display_options['fields']['field_castlegar_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_castlegar_edition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_castlegar_edition']['element_default_classes'] = FALSE;
  /* Field: Content: Kootenay Lake Edition */
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['id'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['table'] = 'field_data_field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['field'] = 'field_kootenay_lake_edition';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['label'] = '';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['text'] = 'Kootenay Lake';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['path'] = 'edition/kootenay-lake/[field_edition_date]';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_kootenay_lake_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Nelson Edition */
  $handler->display->display_options['fields']['field_nelson_edition']['id'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['table'] = 'field_data_field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['field'] = 'field_nelson_edition';
  $handler->display->display_options['fields']['field_nelson_edition']['label'] = '';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['text'] = 'Nelson & Salmo';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['path'] = 'edition/nelson-salmo/[field_edition_date]';
  $handler->display->display_options['fields']['field_nelson_edition']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_nelson_edition']['element_label_colon'] = FALSE;
  /* Field: Content: Trail Edition */
  $handler->display->display_options['fields']['field_trail']['id'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['table'] = 'field_data_field_trail';
  $handler->display->display_options['fields']['field_trail']['field'] = 'field_trail';
  $handler->display->display_options['fields']['field_trail']['label'] = '';
  $handler->display->display_options['fields']['field_trail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['text'] = 'Trail, Salmo & Beaver Valley';
  $handler->display->display_options['fields']['field_trail']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_trail']['alter']['path'] = 'edition/trail-salmo-beaver-valley/[field_edition_date]';
  $handler->display->display_options['fields']['field_trail']['alter']['link_class'] = 'button';
  $handler->display->display_options['fields']['field_trail']['element_label_colon'] = FALSE;
  /* Field: Global: Custom Text: Link to Archive */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Custom Text: Link to Archive';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View Entire Pennywise Digital Archive';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'digital/archive';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'center button';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'edition/%';
  $export['digital_edition_pages'] = $view;

  $view = new view();
  $view->name = 'editorial_promote_list';
  $view->description = '';
  $view->tag = 'default, pw, admin, pwadmin, editorial, article';
  $view->base_table = 'node';
  $view->human_name = 'Editorial Promote List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial Promote List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
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
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Updated date */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '<=';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-1 hour';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['group'] = 1;

  /* Display: Older Promoted Editorials */
  $handler = $view->new_display('page', 'Older Promoted Editorials', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/pwadmin/editorial/sticky-list';

  /* Display: Recent */
  $handler = $view->new_display('page', 'Recent', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['path'] = 'admin/pennywise/editorial/recent-list';
  $export['editorial_promote_list'] = $view;

  $view = new view();
  $view->name = 'editorial_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Editorial Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'editorial-slideshow-header-slidey-widey-block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'editorial-spotlight-article';
  $handler->display->display_options['style_options']['class'] = 'editorial-spotlight-block';
  $handler->display->display_options['style_options']['wrapper_class'] = 'editorial-spotlight';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php GLOBAL $base_path; GLOBAL $base_root; $link =  $base_root . $base_path . "editorial"; ?><a href=\'<?php echo $link;?>\' class=\' editorial-slideshow-link editorial-slideshow-header-link\'>Community Editorials</a>';
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<?php GLOBAL $base_path; GLOBAL $base_root; $link =  $base_root . $base_path . "editorial"; ?><a href=\'<?php echo $link;?>\' class=\' editorial-slideshow-link editorial-slideshow-footer-link\'>Read All >> </a>';
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'views-spotlight-editorial-image';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'editorial_tiny',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = ' views-spotlight-editorial-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] ...more.';
  $handler->display->display_options['fields']['body']['alter']['path'] = '[view_node]';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_class'] = 'views-spotlight-editorial-body views-spotlight-editorial-body-trimmed';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '180',
  );
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
    'article' => 'article',
  );

  /* Display: Editorial Slideshow (3) Block */
  $handler = $view->new_display('block', 'Editorial Slideshow (3) Block', 'editorial_slideshow_block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Editorial Slideshow (5) Block */
  $handler = $view->new_display('block', 'Editorial Slideshow (5) Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Vertical Slide */
  $handler = $view->new_display('block', 'Vertical Slide', 'vertical_editorial_slider');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['skin'] = 'editorial';
  $handler->display->display_options['style_options']['visible'] = '1';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['auto'] = '6';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 1;
  $handler->display->display_options['style_options']['navigation'] = 'after';
  $handler->display->display_options['style_options']['ajax'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'views-spotlight-editorial-image';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'editorial_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = ' views-spotlight-editorial-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]...';
  $handler->display->display_options['fields']['body']['alter']['path'] = '[view_node]';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'p';
  $handler->display->display_options['fields']['body']['element_class'] = 'views-spotlight-editorial-body views-spotlight-editorial-body-trimmed';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '180',
  );
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
    'article' => 'article',
  );
  /* Filter criterion: Field: Header Image (field_image:fid) */
  $handler->display->display_options['filters']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['filters']['field_image_fid']['operator'] = 'not empty';
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Editorial Slideshow Vertical';
  $export['editorial_slideshow'] = $view;

  $view = new view();
  $view->name = 'editorial_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Editorial Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial Administration Page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Search by';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'editorial-listing-block';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'editorial_teaser',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'EDIT';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_image' => 0,
    'title' => 0,
    'field_link' => 0,
    'status' => 0,
    'unpublish_on' => 0,
    'new_comments' => 0,
  );
  /* Field: Content: Publish link */
  $handler->display->display_options['fields']['publishcontent']['id'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['table'] = 'node';
  $handler->display->display_options['fields']['publishcontent']['field'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['label'] = '';
  $handler->display->display_options['fields']['publishcontent']['element_type'] = 'div';
  $handler->display->display_options['fields']['publishcontent']['element_class'] = 'field-publish-link inline-x-delete-link';
  $handler->display->display_options['fields']['publishcontent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['publishcontent']['unpublish'] = 'X';
  $handler->display->display_options['fields']['publishcontent']['publish'] = 'O';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '210';
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '120',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['empty_zero'] = TRUE;
  /* Sort criterion: Content: Published */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  /* Sort criterion: Content: Body (body:format) */
  $handler->display->display_options['sorts']['body_format']['id'] = 'body_format';
  $handler->display->display_options['sorts']['body_format']['table'] = 'field_data_body';
  $handler->display->display_options['sorts']['body_format']['field'] = 'body_format';
  $handler->display->display_options['sorts']['body_format']['expose']['label'] = 'Body (body:format)';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['group'] = 1;

  /* Display: Main Editorial Page */
  $handler = $view->new_display('page', 'Main Editorial Page', 'editorial_main_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Community Editorials';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'editorial_teaser',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Publish link */
  $handler->display->display_options['fields']['publishcontent']['id'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['table'] = 'node';
  $handler->display->display_options['fields']['publishcontent']['field'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['label'] = '';
  $handler->display->display_options['fields']['publishcontent']['alter']['text'] = '<div class=\'inline-x-delete-link\'>[publishcontent]</div>';
  $handler->display->display_options['fields']['publishcontent']['element_type'] = 'div';
  $handler->display->display_options['fields']['publishcontent']['element_class'] = 'inline-x-delete-link';
  $handler->display->display_options['fields']['publishcontent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['publishcontent']['unpublish'] = 'X';
  $handler->display->display_options['fields']['publishcontent']['publish'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[publishcontent] [title]';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[view_node_1] ';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class=\'editorial-main-page-body\'>[body]... [view_node]</div>';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '180';
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'more';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[view_node]';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '180',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[view_node]';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'More';
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
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'field_image' => 0,
    'publishcontent' => 0,
    'title' => 0,
    'publish_on' => 0,
    'body' => 0,
    'view_node' => 0,
  );
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = TRUE;
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['empty_zero'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Ad Payment: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'adp';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'adworks_file' => 'adworks_file',
  );
  $handler->display->display_options['path'] = 'editorial';

  /* Display: Main Editorial Highlight */
  $handler = $view->new_display('attachment', 'Main Editorial Highlight', 'editorial_highlight');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'publishcontent' => 'publishcontent',
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node_1']['text'] = 'Edit';
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
    'edit_node_1' => 'edit_node_1',
    'field_image' => 0,
    'publishcontent' => 0,
    'title' => 0,
    'body' => 0,
    'view_node' => 0,
    'edit_node' => 0,
    'comment_count' => 0,
  );
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'editorial_header',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Publish link */
  $handler->display->display_options['fields']['publishcontent']['id'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['table'] = 'node';
  $handler->display->display_options['fields']['publishcontent']['field'] = 'publishcontent';
  $handler->display->display_options['fields']['publishcontent']['label'] = '';
  $handler->display->display_options['fields']['publishcontent']['element_type'] = 'div';
  $handler->display->display_options['fields']['publishcontent']['element_class'] = 'inline-x-delete-link';
  $handler->display->display_options['fields']['publishcontent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['publishcontent']['unpublish'] = 'X';
  $handler->display->display_options['fields']['publishcontent']['publish'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'editorial-page-header-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Submitted by */
  $handler->display->display_options['fields']['field_submitter']['id'] = 'field_submitter';
  $handler->display->display_options['fields']['field_submitter']['table'] = 'field_data_field_submitter';
  $handler->display->display_options['fields']['field_submitter']['field'] = 'field_submitter';
  $handler->display->display_options['fields']['field_submitter']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_submitter']['element_class'] = 'field-header-submitted-by';
  $handler->display->display_options['fields']['field_submitter']['type'] = 'text_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><br><strong><b>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '360',
  );
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'More';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'editorial_main_page' => 'editorial_main_page',
    'default' => 0,
    'editorial_block' => 0,
    'recent_editorial_block' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Editorial listing';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Header Image (field_image:fid) */
  $handler->display->display_options['sorts']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['sorts']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
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
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'editorial_main_page' => 'editorial_main_page',
    'default' => 0,
    'recent_editorial_block' => 0,
    'editorial_block' => 0,
  );
  $handler->display->display_options['inherit_pager'] = TRUE;
  $handler->display->display_options['render_pager'] = TRUE;

  /* Display: Editorial List Block */
  $handler = $view->new_display('block', 'Editorial List Block', 'recent_editorial_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Community Editorials';
  $handler->display->display_options['display_description'] = 'List of recent editorial articles.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'editorial-listing-block';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'block_list_header';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_image|field_image_fid';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'block_list_header';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
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
    'title' => 0,
    'field_link' => 0,
  );
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'editorial_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'field-name-node-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'More';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Header Image (field_image:fid) */
  $handler->display->display_options['sorts']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['sorts']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'minute';
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
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'More Editorials Block';

  /* Display: Editorial Block */
  $handler = $view->new_display('block', 'Editorial Block', 'editorial_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Using Display Suite and SPLITTER';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node_split';
  $handler->display->display_options['row_options']['view_mode'] = 'block_list_item';
  $handler->display->display_options['row_options']['first_settings'] = array(
    'first_x_value' => '1',
    'view_mode' => 'block_list_header',
    'links' => 1,
    'comments' => 0,
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class=\'block-title editorial-highlight-box editorial-highlight-box-link\'><a href=\'http://pennywiseads.com/editorial\'>Community Editorials<a></h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Header Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'file',
  );
  $handler->display->display_options['fields']['field_image']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['group_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_link']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'EDIT';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Header Image (field_image:fid) */
  $handler->display->display_options['sorts']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['sorts']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['sorts']['field_image_fid']['order'] = 'DESC';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Top Editorials Block';
  $export['editorial_views'] = $view;

  return $export;
}
