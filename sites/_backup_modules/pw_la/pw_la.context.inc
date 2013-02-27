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
  $context->name = '403';
  $context->description = 'If page restricted';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin' => 'admin',
        'admin/*' => 'admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
        'authenticated user' => 'authenticated user',
        'display ad client' => 'display ad client',
        'submit ad' => 'submit ad',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-20eeba41cb621b5fc7f09165eda65f99' => array(
          'module' => 'views',
          'delta' => '20eeba41cb621b5fc7f09165eda65f99',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'menu-menu-pennywise-digital-edition' => array(
          'module' => 'menu',
          'delta' => 'menu-pennywise-digital-edition',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-02990d644d7eb62daab6d080d86a23b7' => array(
          'module' => 'views',
          'delta' => '02990d644d7eb62daab6d080d86a23b7',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'menu-menu-advertising-links' => array(
          'module' => 'menu',
          'delta' => 'menu-advertising-links',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => '5',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('If page restricted');
  t('admin');
  $export['403'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'admin_dashboard';
  $context->description = 'Dashboard layout';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-admin_dashboard-display_dash' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-display_dash',
          'region' => 'dashboard_main',
          'weight' => '-32',
        ),
        'views-admin_dashboard-block_1' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-block_1',
          'region' => 'dashboard_main',
          'weight' => '-31',
        ),
        'views-admin_dashboard-block_2' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-block_2',
          'region' => 'dashboard_main',
          'weight' => '-30',
        ),
        'comment-recent' => array(
          'module' => 'comment',
          'delta' => 'recent',
          'region' => 'dashboard_main',
          'weight' => '-29',
        ),
        'pennywise-pw_logo' => array(
          'module' => 'pennywise',
          'delta' => 'pw_logo',
          'region' => 'dashboard_sidebar',
          'weight' => '-32',
        ),
        'user-online' => array(
          'module' => 'user',
          'delta' => 'online',
          'region' => 'dashboard_sidebar',
          'weight' => '-31',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'dashboard_sidebar',
          'weight' => '-30',
        ),
        'views-admin_dashboard-classified_dash' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-classified_dash',
          'region' => 'dashboard_sidebar',
          'weight' => '-29',
        ),
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => '5',
          'region' => 'dashboard_sidebar',
          'weight' => '-28',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard layout');
  t('admin');
  $export['admin_dashboard'] = $context;

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
        '~classifieds' => '~classifieds',
        '~ad/submit' => '~ad/submit',
        '~thank-you' => '~thank-you',
        '~ad/*/thank-you' => '~ad/*/thank-you',
        '~user/login' => '~user/login',
        '~display/*' => '~display/*',
        'ad/*' => 'ad/*',
        '<front>' => '<front>',
        'classifieds' => 'classifieds',
        'section/*' => 'section/*',
        'node/*' => 'node/*',
        'sales/*' => 'sales/*',
        'browse/*' => 'browse/*',
        'online/*' => 'online/*',
        'edition' => 'edition',
        'edition/*' => 'edition/*',
        'editorial' => 'editorial',
        'editorial/*' => 'editorial/*',
        'user' => 'user',
        'user/*' => 'user/*',
        'contact/*' => 'contact/*',
        'search' => 'search',
        'search?*' => 'search?*',
        'search/*' => 'search/*',
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
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'jump_menu-jump_menu-m_menu-browse-classifi' => array(
          'module' => 'jump_menu',
          'delta' => 'jump_menu-m_menu-browse-classifi',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-27d2d6d0e3ed6c5fa504fe7a9076159a' => array(
          'module' => 'views',
          'delta' => '27d2d6d0e3ed6c5fa504fe7a9076159a',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'pennywise-pw_tmtv' => array(
          'module' => 'pennywise',
          'delta' => 'pw_tmtv',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'views-editorial_views-editorial_block' => array(
          'module' => 'views',
          'delta' => 'editorial_views-editorial_block',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'pennywise-pw_edition' => array(
          'module' => 'pennywise',
          'delta' => 'pw_edition',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'menu-menu-advertising-links' => array(
          'module' => 'menu',
          'delta' => 'menu-advertising-links',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'views-display_ad_blocks-target_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-target_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-poster_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-poster_block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-display_ad_blocks-banner_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-banner_block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'views-907bb0d6d9250ade64f9adcb26ad0a08' => array(
          'module' => 'views',
          'delta' => '907bb0d6d9250ade64f9adcb26ad0a08',
          'region' => 'header_second',
          'weight' => '-9',
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
  $context->name = 'footer_all';
  $context->description = 'Footer 4 fold boxes links';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~ad/submit' => '~ad/submit',
        '~ad/thank-you' => '~ad/thank-you',
        '~user/login' => '~user/login',
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
        'pennywise-pw_edition' => array(
          'module' => 'pennywise',
          'delta' => 'pw_edition',
          'region' => 'postscript_first',
          'weight' => '-8',
        ),
        'views-editorial_slideshow-block_1' => array(
          'module' => 'views',
          'delta' => 'editorial_slideshow-block_1',
          'region' => 'postscript_second',
          'weight' => '-10',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'postscript_third',
          'weight' => '-10',
        ),
        'menu-menu-advertising-links' => array(
          'module' => 'menu',
          'delta' => 'menu-advertising-links',
          'region' => 'postscript_fourth',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Footer 4 fold boxes links');
  t('layout');
  $export['footer_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage_classified_layout';
  $context->description = 'Front page for PW site';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'classifieds' => 'classifieds',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'content',
          'weight' => '-36',
        ),
        'views-taxonomy_listing-tax_sub_list' => array(
          'module' => 'views',
          'delta' => 'taxonomy_listing-tax_sub_list',
          'region' => 'content',
          'weight' => '-36',
        ),
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => '5',
          'region' => 'content',
          'weight' => '-36',
        ),
        'views-display_ad_blocks-print_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-print_block',
          'region' => 'content',
          'weight' => '-35',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-34',
        ),
        'views-display_ad_blocks-splash_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-splash_block',
          'region' => 'splash_two',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-target_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-target_block',
          'region' => 'sidebar_first',
          'weight' => '-45',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-44',
        ),
        'pennywise-pw_tmtv' => array(
          'module' => 'pennywise',
          'delta' => 'pw_tmtv',
          'region' => 'sidebar_first',
          'weight' => '-43',
        ),
        'views-ef0d1e47fd179cf664b200173efd842c' => array(
          'module' => 'views',
          'delta' => 'ef0d1e47fd179cf664b200173efd842c',
          'region' => 'sidebar_first',
          'weight' => '-42',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-41',
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
      'delta_template' => 'clone_of_ad_submission_layout',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page for PW site');
  t('layout');
  $export['frontpage_classified_layout'] = $context;

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
        'menu_block-6' => array(
          'module' => 'menu_block',
          'delta' => '6',
          'region' => 'super_menu',
          'weight' => '-10',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'preface_third',
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
  t('All pages - site wide header');
  t('layout');
  $export['header_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'Search layout';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search?' => 'search?',
        'search*' => 'search*',
        'search?*' => 'search?*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search layout');
  t('layout');
  $export['search'] = $context;

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
        'ad/submit' => 'ad/submit',
        'ad/submit/*' => 'ad/submit/*',
        'thank-you/*' => 'thank-you/*',
        'display/*' => 'display/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
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
  t('No side bars just header and footer.');
  t('layout');
  $export['simple_page'] = $context;

  return $export;
}
