<?php
/**
 * @file
 * pw_classifieds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_classifieds_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_views_api().
 */
function pw_classifieds_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pw_classifieds_image_default_styles() {
  $styles = array();

  // Exported image style: classified_ad_image_small
  $styles['classified_ad_image_small'] = array(
    'name' => 'classified_ad_image_small',
    'effects' => array(
      11 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '220',
          'height' => '150',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function pw_classifieds_node_info() {
  $items = array(
    'classified' => array(
      'name' => t('Classified Ads'),
      'base' => 'node_content',
      'description' => t('Classified ad node type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
