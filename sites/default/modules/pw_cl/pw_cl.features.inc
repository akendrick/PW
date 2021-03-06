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
      31 => array(
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
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
    'label' => 'classified-list-style',
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
    'label' => 'classified_list_nocrop',
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
    'label' => 'classified_page_style',
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
      'help' => t('<strong>NOTE: Business Rated Categories include: ALL RENTALS</strong>, Bulletin Board, Firewood, Contractor/Tradespeople, Services, Health Personal Care, Gardening/Landscaping, Business Opportunities, Employment Opportunities, Legal Notices, Commercial Real Estate, Commercial Rentals, Vacation Rentals, Shared Accommodations, House Sitting.
<span class="classified-rates\'>
<strong>Classified Ad Rates per area</strong><br>
<ul><li><strong>Personal:</strong> 15 words or less - $3.50 <em>per week</em> + tax. (20¢ per additional word.)</li>
<li><strong>Business:</strong> 15 words or less - $5.00 <em>per week</em> + tax. (40¢ per additional word.)</li></ul>
</span>
<span class="classified-directions\'>
<strong>Classified Ad Rates per area</strong><br>
<ul><li><strong>Personal:</strong> 15 words or less - $3.50 <em>per week</em> + tax. (20¢ per additional word.)</li>
<li><strong>Business:</strong> 15 words or less - $5.00 <em>per week</em> + tax. (40¢ per additional word.)</li></ul>
</span>'),
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
    'free' => array(
      'name' => t('Free Ad'),
      'base' => 'node_content',
      'description' => t('Free ad'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Please use 15 - 25 words to describe your one personal item per Free for Free ad.
<ul>
<li>Puppies FREE to good home
<li>FREE pink floral couch
<li>FREE 2 wheel bike will fit 8 year old 
</ul>
Please don\'t post services in FREE for FREE such as free estimates, no free rides to polling station, or buy 3 get 1 free. '),
    ),
  );
  return $items;
}
