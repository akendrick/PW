<?php
/**
 * @file
 * pw_admin.features.inc
 */

/**
 * Implements hook_ccl_features_preset().
 */
function pw_admin_ccl_features_preset() {
  return array(
    'Add Editorial' => array(
      'type' => 'block',
      'title' => 'Add Editorial',
      'link' => 'node/add/article',
      'options' => 'a:15:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:4:"ad_s";s:7:"node_id";s:0:"";s:12:"block_global";i:0;s:12:"block_select";a:2:{s:33:"views|editorial_slideshow-block_1";s:33:"views|editorial_slideshow-block_1";s:38:"views|deba537d237e294b8f1a706f5b8291e0";s:38:"views|deba537d237e294b8f1a706f5b8291e0";}s:13:"la_visibility";s:1:"1";s:8:"la_pages";s:0:"";s:8:"la_types";a:9:{s:4:"ad_s";i:0;s:12:"adworks_file";i:0;s:10:"attachment";i:0;s:10:"classified";i:0;s:10:"pw_digital";i:0;s:11:"display_ads";i:0;s:7:"article";i:0;s:4:"page";i:0;s:7:"webform";i:0;}s:8:"la_roles";a:12:{i:1;i:0;i:4;i:0;i:2;i:0;i:8;i:0;i:9;i:0;i:11;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:10;i:0;i:12;i:0;i:3;i:0;}s:12:"view_options";s:1:"2";s:12:"view_display";s:25:"sales_people_page|default";s:9:"view_view";s:17:"sales_people_page";}',
    ),
    'Manage Banner Ads' => array(
      'type' => 'block',
      'title' => 'Manage Banner Ads',
      'link' => 'admin/pennywise/display_ads/banner',
      'options' => 'a:15:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:4:"ad_s";s:7:"node_id";s:0:"";s:12:"block_global";i:0;s:12:"block_select";a:1:{s:36:"views|display_ad_blocks-banner_block";s:36:"views|display_ad_blocks-banner_block";}s:13:"la_visibility";s:1:"1";s:8:"la_pages";s:0:"";s:8:"la_types";a:9:{s:4:"ad_s";i:0;s:12:"adworks_file";i:0;s:10:"attachment";i:0;s:10:"classified";i:0;s:10:"pw_digital";i:0;s:11:"display_ads";i:0;s:7:"article";i:0;s:4:"page";i:0;s:7:"webform";i:0;}s:8:"la_roles";a:12:{i:1;i:0;i:4;i:0;i:2;i:0;i:8;i:0;i:9;i:0;i:11;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:10;i:0;i:12;i:0;i:3;i:0;}s:12:"view_options";s:1:"2";s:12:"view_display";s:25:"sales_people_page|default";s:9:"view_view";s:17:"sales_people_page";}',
    ),
    'Manage Editorials' => array(
      'type' => 'block',
      'title' => 'Manage Editorials',
      'link' => 'admin/pennywise/editorial/all',
      'options' => 'a:15:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:4:"ad_s";s:7:"node_id";s:0:"";s:12:"block_global";i:0;s:12:"block_select";a:2:{s:33:"views|editorial_slideshow-block_1";s:33:"views|editorial_slideshow-block_1";s:38:"views|deba537d237e294b8f1a706f5b8291e0";s:38:"views|deba537d237e294b8f1a706f5b8291e0";}s:13:"la_visibility";s:1:"1";s:8:"la_pages";s:0:"";s:8:"la_types";a:9:{s:4:"ad_s";i:0;s:12:"adworks_file";i:0;s:10:"attachment";i:0;s:10:"classified";i:0;s:10:"pw_digital";i:0;s:11:"display_ads";i:0;s:7:"article";i:0;s:4:"page";i:0;s:7:"webform";i:0;}s:8:"la_roles";a:12:{i:1;i:0;i:4;i:0;i:2;i:0;i:8;i:0;i:9;i:0;i:11;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:10;i:0;i:12;i:0;i:3;i:0;}s:12:"view_options";s:1:"2";s:12:"view_display";s:25:"sales_people_page|default";s:9:"view_view";s:17:"sales_people_page";}',
    ),
    'Manage Poster Ads' => array(
      'type' => 'block',
      'title' => 'Manage Poster Ads',
      'link' => 'admin/pennywise/display_ads/poster',
      'options' => 'a:15:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:4:"ad_s";s:7:"node_id";s:0:"";s:12:"block_global";i:0;s:12:"block_select";a:2:{s:36:"views|display_ad_blocks-poster_block";s:36:"views|display_ad_blocks-poster_block";s:37:"views|display_ad_blocks-poster_filler";s:37:"views|display_ad_blocks-poster_filler";}s:13:"la_visibility";s:1:"1";s:8:"la_pages";s:0:"";s:8:"la_types";a:9:{s:4:"ad_s";i:0;s:12:"adworks_file";i:0;s:10:"attachment";i:0;s:10:"classified";i:0;s:10:"pw_digital";i:0;s:11:"display_ads";i:0;s:7:"article";i:0;s:4:"page";i:0;s:7:"webform";i:0;}s:8:"la_roles";a:12:{i:1;i:0;i:4;i:0;i:2;i:0;i:8;i:0;i:9;i:0;i:11;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:10;i:0;i:12;i:0;i:3;i:0;}s:12:"view_options";s:1:"2";s:12:"view_display";s:25:"sales_people_page|default";s:9:"view_view";s:17:"sales_people_page";}',
    ),
    'Manage Print Ads' => array(
      'type' => 'block',
      'title' => 'Manage Print Ads',
      'link' => 'admin/pennywise/display_ads/print',
      'options' => 'a:15:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:4:"ad_s";s:7:"node_id";s:0:"";s:12:"block_global";i:0;s:12:"block_select";a:1:{s:35:"views|display_ad_blocks-print_block";s:35:"views|display_ad_blocks-print_block";}s:13:"la_visibility";s:1:"1";s:8:"la_pages";s:0:"";s:8:"la_types";a:9:{s:4:"ad_s";i:0;s:12:"adworks_file";i:0;s:10:"attachment";i:0;s:10:"classified";i:0;s:10:"pw_digital";i:0;s:11:"display_ads";i:0;s:7:"article";i:0;s:4:"page";i:0;s:7:"webform";i:0;}s:8:"la_roles";a:12:{i:1;i:0;i:4;i:0;i:2;i:0;i:8;i:0;i:9;i:0;i:11;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:10;i:0;i:12;i:0;i:3;i:0;}s:12:"view_options";s:1:"2";s:12:"view_display";s:25:"sales_people_page|default";s:9:"view_view";s:17:"sales_people_page";}',
    ),
    'New Display Ad' => array(
      'type' => 'block',
      'title' => 'New Display Ad',
      'link' => 'node/add/display-ads',
      'options' => 'a:15:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:4:"ad_s";s:7:"node_id";s:21:" [nid: [nid: [nid:]]]";s:12:"block_global";i:0;s:12:"block_select";a:7:{s:36:"views|display_ad_blocks-poster_block";s:36:"views|display_ad_blocks-poster_block";s:36:"views|display_ad_blocks-banner_block";s:36:"views|display_ad_blocks-banner_block";s:36:"views|display_ad_blocks-splash_block";s:36:"views|display_ad_blocks-splash_block";s:35:"views|display_ad_blocks-print_block";s:35:"views|display_ad_blocks-print_block";s:37:"views|display_ad_blocks-poster_filler";s:37:"views|display_ad_blocks-poster_filler";s:31:"views|display_ad_blocks-block_1";s:31:"views|display_ad_blocks-block_1";s:38:"views|a3a62bf9d61c86d66224d2dc5ca86e64";s:38:"views|a3a62bf9d61c86d66224d2dc5ca86e64";}s:13:"la_visibility";s:1:"1";s:8:"la_pages";s:0:"";s:8:"la_types";a:9:{s:4:"ad_s";i:0;s:12:"adworks_file";i:0;s:10:"attachment";i:0;s:10:"classified";i:0;s:10:"pw_digital";i:0;s:11:"display_ads";i:0;s:7:"article";i:0;s:4:"page";i:0;s:7:"webform";i:0;}s:8:"la_roles";a:12:{i:1;i:0;i:4;i:0;i:2;i:0;i:8;i:0;i:9;i:0;i:11;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:10;i:0;i:12;i:0;i:3;i:0;}s:12:"view_options";s:1:"2";s:12:"view_display";s:25:"sales_people_page|default";s:9:"view_view";s:17:"sales_people_page";}',
    ),
  );
}

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_admin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pw_admin_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pw_admin_node_info() {
  $items = array(
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
