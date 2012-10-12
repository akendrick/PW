<?php
/**
 * @file
 * pw_cl.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_cl_ctools_plugin_api() {
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
function pw_cl_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pw_cl_image_default_styles() {
  $styles = array();

  // Exported image style: classified-list-style.
  $styles['classified-list-style'] = array(
    'name' => 'classified-list-style',
    'effects' => array(
      21 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '265',
          'height' => '145',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: classified_list_nocrop.
  $styles['classified_list_nocrop'] = array(
    'name' => 'classified_list_nocrop',
    'effects' => array(
      27 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '265',
          'height' => '145',
          'upscale' => 0,
        ),
        'weight' => '-10',
      ),
      26 => NULL,
      28 => NULL,
    ),
  );

  // Exported image style: classified_page_style.
  $styles['classified_page_style'] = array(
    'name' => 'classified_page_style',
    'effects' => array(
      24 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '580',
          'height' => '490',
          'upscale' => 1,
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
function pw_cl_node_info() {
  $items = array(
    'ad_s' => array(
      'name' => t('Ad Submission'),
      'base' => 'node_content',
      'description' => t('Online classified ad submission.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'adworks_file' => array(
      'name' => t('Adworks File'),
      'base' => 'node_content',
      'description' => t('Upload and schedule new ads from Adworks.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Make sure ALL IMAGES are loaded before <strong>Saving</strong> the file. Use the <strong>Preview</strong> button with the <strong>Do NOT create images</strong> option until ALL images are loaded..'),
    ),
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
