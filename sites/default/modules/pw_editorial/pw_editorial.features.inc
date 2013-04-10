<?php
/**
 * @file
 * pw_editorial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_editorial_ctools_plugin_api() {
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
function pw_editorial_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pw_editorial_image_default_styles() {
  $styles = array();

  // Exported image style: classified_list_js_crop.
  $styles['classified_list_js_crop'] = array(
    'name' => 'classified_list_js_crop',
    'effects' => array(
<<<<<<< HEAD
      17 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '240',
          'height' => '130',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '24/13',
            'bgcolor' => 'white',
            'bgopacity' => '0.6',
          ),
=======
      32 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '240',
          'height' => '130',
          'upscale' => 0,
>>>>>>> feature/Editorial-Image-Handling
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: editoral_square_thumbnail.
  $styles['editoral_square_thumbnail'] = array(
    'name' => 'editoral_square_thumbnail',
    'effects' => array(
<<<<<<< HEAD
      10 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '130',
          'height' => '130',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '1/1',
            'bgcolor' => 'white',
            'bgopacity' => '0.6',
          ),
=======
      26 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '130',
          'height' => '130',
          'upscale' => 0,
>>>>>>> feature/Editorial-Image-Handling
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: editorial_block_list_header.
  $styles['editorial_block_list_header'] = array(
    'name' => 'editorial_block_list_header',
    'effects' => array(
<<<<<<< HEAD
      21 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '134',
          'height' => '180',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '67/90',
            'bgcolor' => 'white',
            'bgopacity' => '.8',
          ),
=======
      25 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '134',
          'height' => '180',
          'upscale' => 0,
>>>>>>> feature/Editorial-Image-Handling
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: editorial_header.
  $styles['editorial_header'] = array(
    'name' => 'editorial_header',
    'effects' => array(
<<<<<<< HEAD
      11 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '580',
          'height' => '400',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '29/20',
            'bgcolor' => 'white',
            'bgopacity' => '0.6',
          ),
        ),
        'weight' => '2',
=======
      24 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '580',
          'height' => '400',
          'upscale' => 0,
        ),
        'weight' => '1',
>>>>>>> feature/Editorial-Image-Handling
      ),
    ),
  );

  // Exported image style: editorial_small.
  $styles['editorial_small'] = array(
    'name' => 'editorial_small',
    'effects' => array(
<<<<<<< HEAD
      18 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '134',
          'height' => '104',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '67/52',
            'bgcolor' => 'white',
            'bgopacity' => '0.6',
          ),
=======
      27 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '134',
          'height' => '104',
          'upscale' => 0,
>>>>>>> feature/Editorial-Image-Handling
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: editorial_teaser.
  $styles['editorial_teaser'] = array(
    'name' => 'editorial_teaser',
    'effects' => array(
<<<<<<< HEAD
      13 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '260',
          'height' => '230',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '26/23',
            'bgcolor' => 'white',
            'bgopacity' => '0.6',
          ),
        ),
        'weight' => '2',
=======
      28 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '260',
          'height' => '230',
          'upscale' => 0,
        ),
        'weight' => '1',
>>>>>>> feature/Editorial-Image-Handling
      ),
    ),
  );

  // Exported image style: editorial_thumbnail.
  $styles['editorial_thumbnail'] = array(
    'name' => 'editorial_thumbnail',
    'effects' => array(
<<<<<<< HEAD
      19 => array(
=======
      23 => array(
>>>>>>> feature/Editorial-Image-Handling
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
<<<<<<< HEAD
          'width' => '135',
          'height' => '65',
=======
          'width' => '140',
          'height' => '75',
>>>>>>> feature/Editorial-Image-Handling
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: editorial_tiny.
  $styles['editorial_tiny'] = array(
    'name' => 'editorial_tiny',
    'effects' => array(
<<<<<<< HEAD
      16 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => '45',
          'height' => '30',
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '3/2',
            'bgcolor' => 'white',
            'bgopacity' => '0.6',
          ),
=======
      29 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '45',
          'height' => '30',
          'upscale' => 0,
>>>>>>> feature/Editorial-Image-Handling
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
function pw_editorial_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Editorial'),
      'base' => 'node_content',
      'description' => t('Editorial articles with links, images, and video (coming soon).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'attachment' => array(
      'name' => t('Attachment'),
      'base' => 'node_content',
      'description' => t('For large attachments - such as PDFs or large image files where the user is encouraged to download as well as view them online.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Use <em>pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pw_digital' => array(
      'name' => t('Digital Edition'),
      'base' => 'node_content',
      'description' => t('Digital editions of the Pennywise paper. Using PDF with Scribd or other variation to display it.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
