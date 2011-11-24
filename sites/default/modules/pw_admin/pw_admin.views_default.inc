<?php
/**
 * @file
 * pw_admin.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_admin_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'classified_ad_administration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Classified Ad Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pennywise Ad Administration';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any classified content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_node' => 'edit_node',
    'field_image' => 'field_image',
    'term_node_tid' => 'term_node_tid',
    'field_area' => 'term_node_tid',
    'field_promote' => 'field_area',
    'field_rate' => 'field_promote',
    'field_ad_type_1' => 'field_ad_type_1',
    'field_ad_copy' => 'field_ad_copy',
    'name' => 'name',
    'mail' => 'name',
    'rid' => 'name',
    'field_phone' => 'name',
    'field_duration' => 'field_duration',
    'field_price' => 'field_price',
    'field_date_start' => 'field_date_start',
    'delete_node' => 'delete_node',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '<br/>',
    ),
    'field_area' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_promote' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_rate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_ad_type_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_ad_copy' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_date_start' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['text'] = 'EDIT';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Section';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'classification' => 0,
    'tags' => 0,
  );
  /* Field: Content: Classified Ad Type */
  $handler->display->display_options['fields']['field_ad_type']['id'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['field'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['label'] = 'Liveload';
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
  $handler->display->display_options['fields']['field_ad_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['field_api_classes'] = 0;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
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
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Ad Copy */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
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
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['field_api_classes'] = 0;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['text'] = 'DELETE';
  /* Field: Content: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk Action';
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
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '30';
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
      'override_label' => 1,
      'label' => 'Delete Multiple',
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
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish Multiple',
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
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish Multiple',
    ),
    'node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish Multiple By Keyword',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Sort criterion: Content: Classification (field_tags) */
  $handler->display->display_options['sorts']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['sorts']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['sorts']['field_tags_tid']['field'] = 'field_tags_tid';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'classified' => 'classified',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['filters']['field_ad_type_value']['id'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['filters']['field_ad_type_value']['field'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'section';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'classification';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Ad Copy (field_ad_copy) */
  $handler->display->display_options['filters']['field_ad_copy_value']['id'] = 'field_ad_copy_value';
  $handler->display->display_options['filters']['field_ad_copy_value']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['filters']['field_ad_copy_value']['field'] = 'field_ad_copy_value';
  $handler->display->display_options['filters']['field_ad_copy_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_ad_copy_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['operator_id'] = 'field_ad_copy_value_op';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['label'] = 'Ad body contains';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['operator'] = 'field_ad_copy_value_op';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['identifier'] = 'field_ad_copy_value';
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_ad_copy_value']['expose']['multiple'] = FALSE;

  /* Display: Classified Dashboard */
  $handler = $view->new_display('page', 'Classified Dashboard', 'Ads');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['path'] = 'admin/pennywise/ads/classifieds';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Classified Ad Administration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Liveload Page */
  $handler = $view->new_display('page', 'Liveload Page', 'classifieds_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Liveload Ads';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'classified' => 'classified',
  );
  /* Filter criterion: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['filters']['field_ad_type_value']['id'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['filters']['field_ad_type_value']['field'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/pennywise/ads/classifieds/liveload';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Liveload Ad Administration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Classified Ads */
  $handler = $view->new_display('page', 'Classified Ads', 'liveload_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Classified Ad Administration';
  $handler->display->display_options['path'] = 'admin/pennywise/ads/classifieds/all';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Classified Ads';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Liveload Attachment */
  $handler = $view->new_display('attachment', 'Liveload Attachment', 'liveload_attach');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'classified' => 'classified',
  );
  /* Filter criterion: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['filters']['field_ad_type_value']['id'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['filters']['field_ad_type_value']['field'] = 'field_ad_type_value';
  $handler->display->display_options['filters']['field_ad_type_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'Ads' => 0,
    'classifieds_page' => 0,
    'liveload_page' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = 0;

  /* Display: Incoming */
  $handler = $view->new_display('page', 'Incoming', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Incoming Ads';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_node' => 'edit_node',
    'field_image' => 'field_image',
    'term_node_tid' => 'term_node_tid',
    'field_area' => 'field_area',
    'field_promote' => 'field_rate',
    'field_rate' => 'field_rate',
    'field_ad_copy' => 'field_ad_copy',
    'name' => 'name',
    'mail' => 'name',
    'rid' => 'name',
    'field_phone' => 'name',
    'field_duration' => 'field_duration',
    'field_price' => 'field_price',
    'field_date_start' => 'field_duration',
    'delete_node' => 'delete_node',
    'views_bulk_operations' => 'views_bulk_operations',
    'field_ccid' => 'field_ccid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '<br/>',
    ),
    'field_area' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_promote' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_rate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
    ),
    'field_ad_copy' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_date_start' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_ccid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['text'] = 'EDIT';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
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
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Section';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'area' => 0,
    'classification' => 0,
    'tags' => 0,
  );
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_area']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_area']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_area']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_area']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_area']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_area']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_area']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_area']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_area']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_area']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_area']['field_api_classes'] = 0;
  /* Field: Content: Liveload Your Ad */
  $handler->display->display_options['fields']['field_promote']['id'] = 'field_promote';
  $handler->display->display_options['fields']['field_promote']['table'] = 'field_data_field_promote';
  $handler->display->display_options['fields']['field_promote']['field'] = 'field_promote';
  $handler->display->display_options['fields']['field_promote']['label'] = 'Promote Your Ad';
  $handler->display->display_options['fields']['field_promote']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promote']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promote']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promote']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promote']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_promote']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promote']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promote']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promote']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_promote']['field_api_classes'] = 0;
  /* Field: Content: Rate */
  $handler->display->display_options['fields']['field_rate']['id'] = 'field_rate';
  $handler->display->display_options['fields']['field_rate']['table'] = 'field_data_field_rate';
  $handler->display->display_options['fields']['field_rate']['field'] = 'field_rate';
  $handler->display->display_options['fields']['field_rate']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_rate']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_rate']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_rate']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_rate']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_rate']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_rate']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_rate']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_rate']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_rate']['field_api_classes'] = 0;
  /* Field: Content: Ad Copy */
  $handler->display->display_options['fields']['field_ad_copy']['id'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['table'] = 'field_data_field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['field'] = 'field_ad_copy';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['field_ad_copy']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_copy']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_copy']['field_api_classes'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  /* Field: Field: Phone Number */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_phone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_phone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_phone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_phone']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_phone']['click_sort_column'] = 'number';
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = 0;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_duration']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_duration']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_duration']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_duration']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_duration']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_duration']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_duration']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_duration']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_duration']['field_api_classes'] = 0;
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_price']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_price']['field_api_classes'] = 0;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_date_start']['id'] = 'field_date_start';
  $handler->display->display_options['fields']['field_date_start']['table'] = 'field_data_field_date_start';
  $handler->display->display_options['fields']['field_date_start']['field'] = 'field_date_start';
  $handler->display->display_options['fields']['field_date_start']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_start']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_start']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_start']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_start']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date_start']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date_start']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date_start']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date_start']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date_start']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_date_start']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_start']['field_api_classes'] = 0;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['text'] = 'DELETE';
  /* Field: Content: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Bulk Action';
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
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '30';
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
      'override_label' => 1,
      'label' => 'Delete Multiple',
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
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish Multiple',
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
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish Multiple',
    ),
    'node_unpublish_by_keyword_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish Multiple By Keyword',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: CCID */
  $handler->display->display_options['fields']['field_ccid']['id'] = 'field_ccid';
  $handler->display->display_options['fields']['field_ccid']['table'] = 'field_data_field_ccid';
  $handler->display->display_options['fields']['field_ccid']['field'] = 'field_ccid';
  $handler->display->display_options['fields']['field_ccid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ccid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ccid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ccid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ccid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ccid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ccid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ccid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ccid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_ccid']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_ccid']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ad_s' => 'ad_s',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['path'] = 'admin/pennywise/ads/classifieds/incoming';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Incoming Ads';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['classified_ad_administration'] = $view;

  $view = new view;
  $view->name = 'pennywise_admin_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Pennywise Admin Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pennywise Admin';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Classification */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
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
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tags']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_tags']['field_api_classes'] = 0;
  /* Field: Content: Classified Ad Type */
  $handler->display->display_options['fields']['field_ad_type']['id'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['field'] = 'field_ad_type';
  $handler->display->display_options['fields']['field_ad_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_type']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
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
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['base_path'] = 'admin/pennywise/ads';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Classified Ad Type (field_ad_type) */
  $handler->display->display_options['arguments']['field_ad_type_value']['id'] = 'field_ad_type_value';
  $handler->display->display_options['arguments']['field_ad_type_value']['table'] = 'field_data_field_ad_type';
  $handler->display->display_options['arguments']['field_ad_type_value']['field'] = 'field_ad_type_value';
  $handler->display->display_options['arguments']['field_ad_type_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_ad_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ad_type_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_ad_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ad_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ad_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_ad_type_value']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ad_type_value']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/pennywise';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Pennywise';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['pennywise_admin_dashboard'] = $view;

  return $export;
}
