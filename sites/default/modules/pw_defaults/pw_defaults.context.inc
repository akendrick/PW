<?php
/**
 * @file
 * pw_defaults.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_defaults_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general_layout';
  $context->description = 'General placement for blocks on the page';
  $context->tag = 'ads';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~pwadmin' => '~pwadmin',
        '~pwadmin/*' => '~pwadmin/*',
        '~section/*' => '~section/*',
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
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-19',
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
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-9',
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
  t('General placement for blocks on the page');
  t('ads');
  $export['general_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pwadmin_layout';
  $context->description = 'Disable certain regions and blocks on admin pages.';
  $context->tag = 'pwadmin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin' => 'admin',
        'admin/*' => 'admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
          'region' => 'header_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'admin_theme_',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Disable certain regions and blocks on admin pages.');
  t('pwadmin');
  $export['pwadmin_layout'] = $context;

  return $export;
}
