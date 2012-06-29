<?php
/**
 * @file
 * pw_display.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_display_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pw_display_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pw_display_image_default_styles() {
  $styles = array();

  // Exported image style: display_ad_print_thumbnail.
  $styles['display_ad_print_thumbnail'] = array(
    'name' => 'display_ad_print_thumbnail',
    'effects' => array(
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '60',
          'height' => '85',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function pw_display_node_info() {
  $items = array(
    'display_ads' => array(
      'name' => t('Display ads'),
      'base' => 'node_content',
      'description' => t('General display ad content type - for banner, splash, poster, print, video, target, etc. '),
      'has_title' => '1',
      'title_label' => t('Ad Name'),
      'help' => t('Note: <strong>Obituaries, Birth Announcements, Wedding Announcements</strong> are considered clients.'),
    ),
  );
  return $items;
}
