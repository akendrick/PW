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
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
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

  // Exported image style: display_ad_full_page.
  $styles['display_ad_full_page'] = array(
    'name' => 'display_ad_full_page',
    'effects' => array(
      33 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '940',
          'height' => '1020',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: display_ad_print_cropped_vert_thumbnail.
  $styles['display_ad_print_cropped_vert_thumbnail'] = array(
    'name' => 'display_ad_print_cropped_vert_thumbnail',
    'effects' => array(
      5 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '95',
          'height' => '140',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

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

  // Exported image style: display_ad_smart_crop_med_square.
  $styles['display_ad_smart_crop_med_square'] = array(
    'name' => 'display_ad_smart_crop_med_square',
    'effects' => array(
      6 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '165',
          'height' => '220',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
      7 => array(
        'label' => 'Rounded Corners',
        'help' => 'This is true cropping, not overlays, so the result <em>can</em> be transparent.',
        'effect callback' => 'canvasactions_roundedcorners_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_roundedcorners_form',
        'summary theme' => 'canvasactions_roundedcorners_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_roundedcorners',
        'data' => array(
          'radius' => '16',
          'independent_corners_set' => array(
            'independent_corners' => 1,
            'radii' => array(
              'tl' => '20',
              'tr' => '20',
              'bl' => '0',
              'br' => '0',
            ),
          ),
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: miniature_square.
  $styles['miniature_square'] = array(
    'name' => 'miniature_square',
    'effects' => array(
      29 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '30',
          'height' => '30',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
      30 => array(
        'label' => 'Rounded Corners',
        'help' => 'This is true cropping, not overlays, so the result <em>can</em> be transparent.',
        'effect callback' => 'canvasactions_roundedcorners_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_roundedcorners_form',
        'summary theme' => 'canvasactions_roundedcorners_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_roundedcorners',
        'data' => array(
          'radius' => '5',
          'independent_corners_set' => array(
            'independent_corners' => 0,
            'radii' => array(
              'tl' => 0,
              'tr' => 0,
              'bl' => 0,
              'br' => 0,
            ),
          ),
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
