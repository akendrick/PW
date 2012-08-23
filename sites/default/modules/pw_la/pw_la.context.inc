<?php
/**
 * @file
 * pw_la.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_la_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'classified_ad_layout';
  $context->description = 'layout for PW site';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '<front>' => '<front>',
        'section/*' => 'section/*',
        'node/*' => 'node/*',
        'editorial' => 'editorial',
        'editorial/*' => 'editorial/*',
        'sales/*' => 'sales/*',
        'browse/*' => 'browse/*',
        'online/*' => 'online/*',
        'edition' => 'edition',
        'edition/*' => 'edition/*',
        'user' => 'user',
        'user/*' => 'user/*',
        'contact/*' => 'contact/*',
        'search' => 'search',
        'search?*' => 'search?*',
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
        'views-taxonomy_listing-tax_sub_list' => array(
          'module' => 'views',
          'delta' => 'taxonomy_listing-tax_sub_list',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-display_ad_blocks-print_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-print_block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-20eeba41cb621b5fc7f09165eda65f99' => array(
          'module' => 'views',
          'delta' => '20eeba41cb621b5fc7f09165eda65f99',
          'region' => 'sidebar_first',
          'weight' => '-32',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-31',
        ),
        'views-27d2d6d0e3ed6c5fa504fe7a9076159a' => array(
          'module' => 'views',
          'delta' => '27d2d6d0e3ed6c5fa504fe7a9076159a',
          'region' => 'sidebar_first',
          'weight' => '-30',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'sidebar_first',
          'weight' => '-29',
        ),
        'menu-menu-advertising-links' => array(
          'module' => 'menu',
          'delta' => 'menu-advertising-links',
          'region' => 'sidebar_first',
          'weight' => '-28',
        ),
        'views-editorial_views-editorial_block' => array(
          'module' => 'views',
          'delta' => 'editorial_views-editorial_block',
          'region' => 'sidebar_first',
          'weight' => '-27',
        ),
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => '5',
          'region' => 'sidebar_first',
          'weight' => '-26',
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
      'delta_template' => 'traditional',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('layout');
  t('layout for PW site');
  $export['classified_ad_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact_block';
  $context->description = 'Contact block';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people/*' => 'people/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pennywise-pw_contact_user' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact_user',
          'region' => 'content',
          'weight' => '-10',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'menu',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'traditional',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact block');
  t('layout');
  $export['contact_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'editorial_layout';
  $context->description = 'Layout for the editorial page';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'editorial' => 'editorial',
        'editorial/*' => 'editorial/*',
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
          'weight' => '-26',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-25',
        ),
        'menu-menu-advertising-links' => array(
          'module' => 'menu',
          'delta' => 'menu-advertising-links',
          'region' => 'sidebar_first',
          'weight' => '-24',
        ),
        'views-c315909adc26bde14b5aef5a95966ac1' => array(
          'module' => 'views',
          'delta' => 'c315909adc26bde14b5aef5a95966ac1',
          'region' => 'sidebar_first',
          'weight' => '-23',
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
  t('Layout for the editorial page');
  t('layout');
  $export['editorial_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general_layout';
  $context->description = 'General layout for blocks';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'section/*' => 'section/*',
        'sales/*' => 'sales/*',
        'ad/*' => 'ad/*',
        'area/*' => 'area/*',
        'attachments/*' => 'attachments/*',
        'search/*' => 'search/*',
        'user/*' => 'user/*',
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
          'weight' => '-9',
        ),
        'views-display_ad_blocks-print_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-print_block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'sidebar_first',
          'weight' => '-27',
        ),
        'views-02990d644d7eb62daab6d080d86a23b7' => array(
          'module' => 'views',
          'delta' => '02990d644d7eb62daab6d080d86a23b7',
          'region' => 'sidebar_first',
          'weight' => '-26',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-25',
        ),
        'views-editorial_views-editorial_block' => array(
          'module' => 'views',
          'delta' => 'editorial_views-editorial_block',
          'region' => 'sidebar_first',
          'weight' => '-24',
        ),
        'menu-menu-advertising-links' => array(
          'module' => 'menu',
          'delta' => 'menu-advertising-links',
          'region' => 'sidebar_first',
          'weight' => '-23',
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
  t('General layout for blocks');
  t('layout');
  $export['general_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'header_all';
  $context->description = 'All pages - site wide header';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
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
        'views-display_ad_blocks-block_1' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-block_1',
          'region' => 'splash_one',
          'weight' => '-30',
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
          'weight' => '-28',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'preface_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages - site wide header');
  t('layout');
  $export['header_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'simple_page';
  $context->description = 'No side bars just header and footer.';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'ad/*' => 'ad/*',
        'submit-ad' => 'submit-ad',
        'user/*' => 'user/*',
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pennywise-pw_breadcrumb' => array(
          'module' => 'pennywise',
          'delta' => 'pw_breadcrumb',
          'region' => 'content',
          'weight' => '-10',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'menu',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_left',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('No side bars just header and footer.');
  t('layout');
  $export['simple_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'trad_classified_layout';
  $context->description = 'Traditional layout for classified ad blocks content surrounded by side bars.';
  $context->tag = 'traditional';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'traditional',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Traditional layout for classified ad blocks content surrounded by side bars.');
  t('traditional');
  $export['trad_classified_layout'] = $context;

  return $export;
}
