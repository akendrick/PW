<?php
/**
 * @file
 * pw_layout.features.inc
 */

/**
 * Implements hook_views_api().
 */
function pw_layout_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function pw_layout_image_default_styles() {
  $styles = array();

  // Exported image style: classified_ad_image_small
  $styles['classified_ad_image_small'] = array(
    'name' => 'classified_ad_image_small',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '260',
          'height' => '150',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
