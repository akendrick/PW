<?php
/**
 * @file
 * pw_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ad_submission_page';
  $context->description = 'Ad submission theming';
  $context->tag = 'submit, page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ad_s' => 'ad_s',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'ad_submission_layout',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ad submission theming');
  t('submit, page');
  $export['ad_submission_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'classified_ad_layout';
  $context->description = 'General layout for classified ad blocks';
  $context->tag = 'classifieds';
  $context->conditions = array(
    'mobile' => array(
      'values' => array(
        'desktop' => 'desktop',
        'ipad' => 'ipad',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'section/*' => 'section/*',
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-taxonomy_listing-tax_sub_list' => array(
          'module' => 'views',
          'delta' => 'taxonomy_listing-tax_sub_list',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-print_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-print_block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-display_ad_blocks-splash_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-splash_block',
          'region' => 'splash_two',
          'weight' => '-10',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'views-02990d644d7eb62daab6d080d86a23b7' => array(
          'module' => 'views',
          'delta' => '02990d644d7eb62daab6d080d86a23b7',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'menu-menu-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-pages',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-editorial_views-block_1' => array(
          'module' => 'views',
          'delta' => 'editorial_views-block_1',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'views-display_ad_blocks-poster_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-poster_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-banner_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-banner_block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'views-deba537d237e294b8f1a706f5b8291e0' => array(
          'module' => 'views',
          'delta' => 'deba537d237e294b8f1a706f5b8291e0',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_left',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('General layout for classified ad blocks');
  t('classifieds');
  $export['classified_ad_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'classified_mobile_theme';
  $context->description = 'Classified mobile block arrangement';
  $context->tag = 'mobile';
  $context->conditions = array(
    'mobile' => array(
      'values' => array(
        'android' => 'android',
        'blackberry' => 'blackberry',
        'iphone' => 'iphone',
        'ipod' => 'ipod',
        'mobile' => 'mobile',
        'opera_mini' => 'opera_mini',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'content',
          'weight' => '-8',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'content',
          'weight' => '-6',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-5',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'menu-menu-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-pages',
          'region' => 'menu',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Classified mobile block arrangement');
  t('mobile');
  $export['classified_mobile_theme'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mobile_theme';
  $context->description = 'General mobile block arrangement';
  $context->tag = 'mobile';
  $context->conditions = array(
    'mobile' => array(
      'values' => array(
        'android' => 'android',
        'blackberry' => 'blackberry',
        'iphone' => 'iphone',
        'ipod' => 'ipod',
        'mobile' => 'mobile',
        'opera_mini' => 'opera_mini',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'threeup_one',
          'weight' => '-10',
        ),
        'views-taxonomy_listing-tax_sub_list' => array(
          'module' => 'views',
          'delta' => 'taxonomy_listing-tax_sub_list',
          'region' => 'content',
          'weight' => '-9',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'content',
          'weight' => '-7',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-02990d644d7eb62daab6d080d86a23b7' => array(
          'module' => 'views',
          'delta' => '02990d644d7eb62daab6d080d86a23b7',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'menu-menu-pages' => array(
          'module' => 'menu',
          'delta' => 'menu-pages',
          'region' => 'menu',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('General mobile block arrangement');
  t('mobile');
  $export['mobile_theme'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'trad_classified_layout';
  $context->description = 'Traditional layout for classified ad blocks content surrounded by side bars.';
  $context->tag = 'classifieds';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Traditional layout for classified ad blocks content surrounded by side bars.');
  t('classifieds');
  $export['trad_classified_layout'] = $context;

  return $export;
}
