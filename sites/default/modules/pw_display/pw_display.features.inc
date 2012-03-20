<?php
/**
 * @file
 * pw_display.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_display_ctools_plugin_api() {
  return array("version" => "1");
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

  // Exported image style: display_ad_banner
  $styles['display_ad_banner'] = array(
    'name' => 'display_ad_banner',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '520',
          'height' => '130',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: display_ad_poster
  $styles['display_ad_poster'] = array(
    'name' => 'display_ad_poster',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '150',
          'height' => '400',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: display_ad_print_full
  $styles['display_ad_print_full'] = array(
    'name' => 'display_ad_print_full',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '920',
          'height' => '800',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: display_ad_print_thumbnail
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

  // Exported image style: display_ad_splash
  $styles['display_ad_splash'] = array(
    'name' => 'display_ad_splash',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '200',
          'height' => '80',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: display_ad_target
  $styles['display_ad_target'] = array(
    'name' => 'display_ad_target',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '150',
          'height' => '150',
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
      'title_label' => t('Ad Title'),
      'help' => t('Note: <strong>Obituaries, Birth Announcements, Wedding Announcements</strong> are considered clients.'),
    ),
  );
  return $items;
}
