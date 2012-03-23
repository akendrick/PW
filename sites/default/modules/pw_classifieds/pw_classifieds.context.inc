<?php
/**
 * @file
 * pw_classifieds.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_classifieds_context_default_contexts() {
  $export = array();

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

  return $export;
}
