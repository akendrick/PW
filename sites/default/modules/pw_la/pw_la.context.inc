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
  $context->name = 'admin_boxes';
  $context->description = 'Add admin boxes in layout';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'classified editor' => 'classified editor',
        'digital edition editor' => 'digital edition editor',
        'display ad editor' => 'display ad editor',
        'editorial editor' => 'editorial editor',
        'page editor' => 'page editor',
        'sales' => 'sales',
        'user editor' => 'user editor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add admin boxes in layout');
  t('admin');
  $export['admin_boxes'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_code_page';
  $context->description = 'Display calling area block as page.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'area-codes' => 'area-codes',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pennywise-pw_phone_areas' => array(
          'module' => 'pennywise',
          'delta' => 'pw_phone_areas',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display calling area block as page.');
  t('Pages');
  $export['area_code_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'classifieds_et_al';
  $context->description = 'General look and feel for classifieds and most pages';
  $context->tag = 'Pages';
  $context->conditions = array(
    'cmd' => array(
      'values' => array(
        2 => 2,
        3 => 3,
      ),
    ),
    'context' => array(
      'values' => array(
        '~mobile_layout' => '~mobile_layout',
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~classifieds' => '~classifieds',
        '~ad/submit' => '~ad/submit',
        '~thank-you' => '~thank-you',
        '~ad/*/thank-you' => '~ad/*/thank-you',
        '~user/login' => '~user/login',
        '~display/*' => '~display/*',
        '~editorial/submit' => '~editorial/submit',
        'ad/*' => 'ad/*',
        '<front>' => '<front>',
        'classifieds' => 'classifieds',
        'section/*' => 'section/*',
        'node/*' => 'node/*',
        'search' => 'search',
        'search/*' => 'search/*',
        'find' => 'find',
        'find/*' => 'find/*',
        'sales/*' => 'sales/*',
        'browse/*' => 'browse/*',
        'online/*' => 'online/*',
        'edition' => 'edition',
        'edition/*' => 'edition/*',
        'editorial' => 'editorial',
        'editorial/*' => 'editorial/*',
        'editorials' => 'editorials',
        'editorials/*' => 'editorials/*',
        'user' => 'user',
        'user/*' => 'user/*',
        'contact/*' => 'contact/*',
        'area-code' => 'area-code',
        'features/hometown' => 'features/hometown',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pennywise-pw_phone_areas' => array(
          'module' => 'pennywise',
          'delta' => 'pw_phone_areas',
          'region' => 'content',
          'weight' => '-53',
        ),
        'views-taxonomy_listing-tax_sub_list' => array(
          'module' => 'views',
          'delta' => 'taxonomy_listing-tax_sub_list',
          'region' => 'content',
          'weight' => '-52',
        ),
        'views-display_ad_blocks-print_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-print_block',
          'region' => 'content',
          'weight' => '-51',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-50',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-27d2d6d0e3ed6c5fa504fe7a9076159a' => array(
          'module' => 'views',
          'delta' => '27d2d6d0e3ed6c5fa504fe7a9076159a',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'pennywise-submit_editorial' => array(
          'module' => 'pennywise',
          'delta' => 'submit_editorial',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'pennywise-pw_tmtv' => array(
          'module' => 'pennywise',
          'delta' => 'pw_tmtv',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'pennywise-pw_edition' => array(
          'module' => 'pennywise',
          'delta' => 'pw_edition',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'menu-menu-special-features' => array(
          'module' => 'menu',
          'delta' => 'menu-special-features',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'views-display_ad_blocks-poster_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-poster_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-target_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-target_block',
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
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'default_center',
    ),
    'disable_context' => array(
      'disabled' => array(
        'mobile_layout' => 'mobile_layout',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('General look and feel for classifieds and most pages');
  t('Pages');
  $export['classifieds_et_al'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = 'Admin Dashboard layout';
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
          'weight' => '-10',
        ),
        'views-admin_dashboard-block_2' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-block_2',
          'region' => 'dashboard_main',
          'weight' => '-8',
        ),
        'views-admin_dashboard-block_1' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-block_1',
          'region' => 'dashboard_main',
          'weight' => '-7',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'dashboard_sidebar',
          'weight' => '-53',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'dashboard_sidebar',
          'weight' => '-53',
        ),
        'jump_menu-jump_menu-m_menu-browse-classifi' => array(
          'module' => 'jump_menu',
          'delta' => 'jump_menu-m_menu-browse-classifi',
          'region' => 'dashboard_sidebar',
          'weight' => '-52',
        ),
        'user-online' => array(
          'module' => 'user',
          'delta' => 'online',
          'region' => 'dashboard_sidebar',
          'weight' => '-51',
        ),
        'views-admin_dashboard-classified_dash' => array(
          'module' => 'views',
          'delta' => 'admin_dashboard-classified_dash',
          'region' => 'dashboard_sidebar',
          'weight' => '-10',
        ),
        'views-85679b54a104be59cbd7704598393d19' => array(
          'module' => 'views',
          'delta' => '85679b54a104be59cbd7704598393d19',
          'region' => 'dashboard_sidebar',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Dashboard layout');
  t('admin');
  $export['dashboard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer_all';
  $context->description = 'General links appearing at the bottom of every page';
  $context->tag = 'Default';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~mobile_layout' => '~mobile_layout',
      ),
    ),
    'path' => array(
      'values' => array(
        '~ad/submit' => '~ad/submit',
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
          'weight' => '-10',
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
  t('Default');
  t('General links appearing at the bottom of every page');
  $export['footer_all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = 'General page layout for front';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
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
          'weight' => '-51',
        ),
        'views-5a90aa23e99571afb94466d320d84fd2' => array(
          'module' => 'views',
          'delta' => '5a90aa23e99571afb94466d320d84fd2',
          'region' => 'content',
          'weight' => '-50',
        ),
        'pennywise-pw_holiday_message' => array(
          'module' => 'pennywise',
          'delta' => 'pw_holiday_message',
          'region' => 'content',
          'weight' => '-49',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-48',
        ),
        'pennywise-pw_tmtv' => array(
          'module' => 'pennywise',
          'delta' => 'pw_tmtv',
          'region' => 'sidebar_first',
          'weight' => '-52',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-51',
        ),
        'views-f9a11ccbc914f473ca208cf404c156ea' => array(
          'module' => 'views',
          'delta' => 'f9a11ccbc914f473ca208cf404c156ea',
          'region' => 'sidebar_first',
          'weight' => '-50',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-49',
        ),
        'views-9bc6b1b550b17fcf0dc4b7540cd1b596' => array(
          'module' => 'views',
          'delta' => '9bc6b1b550b17fcf0dc4b7540cd1b596',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'views-907bb0d6d9250ade64f9adcb26ad0a08' => array(
          'module' => 'views',
          'delta' => '907bb0d6d9250ade64f9adcb26ad0a08',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'front',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('General page layout for front');
  t('Pages');
  $export['front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mobile_front';
  $context->description = '';
  $context->tag = 'Mobile';
  $context->conditions = array(
    'cmd' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'pennywise-pw_logo' => array(
          'module' => 'pennywise',
          'delta' => 'pw_logo',
          'region' => 'content',
          'weight' => '-10',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'content',
          'weight' => '-9',
        ),
        'pennywise-pw_holiday_message' => array(
          'module' => 'pennywise',
          'delta' => 'pw_holiday_message',
          'region' => 'content',
          'weight' => '-8',
        ),
        'pennywise-pw_phone_areas' => array(
          'module' => 'pennywise',
          'delta' => 'pw_phone_areas',
          'region' => 'content',
          'weight' => '-7',
        ),
        'pennywise-pw_edition' => array(
          'module' => 'pennywise',
          'delta' => 'pw_edition',
          'region' => 'content',
          'weight' => '-6',
        ),
        'pennywise-submit_editorial' => array(
          'module' => 'pennywise',
          'delta' => 'submit_editorial',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-deba537d237e294b8f1a706f5b8291e0' => array(
          'module' => 'views',
          'delta' => 'deba537d237e294b8f1a706f5b8291e0',
          'region' => 'content',
          'weight' => '-4',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'mobile',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mobile');
  $export['mobile_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mobile_layout';
  $context->description = '';
  $context->tag = 'Mobile';
  $context->conditions = array(
    'cmd' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
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
        'pennywise-pw_mobile_links' => array(
          'module' => 'pennywise',
          'delta' => 'pw_mobile_links',
          'region' => 'threeup_three',
          'weight' => '-10',
        ),
        'views-276555a85e20cd9e83768e783dbee851' => array(
          'module' => 'views',
          'delta' => '276555a85e20cd9e83768e783dbee851',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'delta_blocks-logo' => array(
          'module' => 'delta_blocks',
          'delta' => 'logo',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'pennywise-pw_contact' => array(
          'module' => 'pennywise',
          'delta' => 'pw_contact',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
      ),
    ),
    'css' => array(
      'Bartik' => array(
        'themes/bartik/css/colors.css' => 0,
        'themes/bartik/css/ie-rtl.css' => 0,
        'themes/bartik/css/ie.css' => 0,
        'themes/bartik/css/ie6.css' => 0,
        'themes/bartik/css/layout-rtl.css' => 0,
        'themes/bartik/css/layout.css' => 0,
        'themes/bartik/css/maintenance-page.css' => 0,
        'themes/bartik/css/print.css' => 0,
        'themes/bartik/css/style-rtl.css' => 0,
        'themes/bartik/css/style.css' => 0,
        'themes/bartik/color/preview.css' => 0,
      ),
      'Pennywise Theme' => array(
        'sites/all/themes/pwt/css/global.css' => 0,
        'sites/all/themes/pwt/css/pw-mobile.css' => 'sites/all/themes/pwt/css/pw-mobile.css',
        'sites/all/themes/pwt/css/pw.css' => 0,
        'sites/all/themes/pwt/css/pwt-alpha-default-narrow.css' => 0,
        'sites/all/themes/pwt/css/pwt-alpha-default-normal.css' => 0,
        'sites/all/themes/pwt/css/pwt-alpha-default-wide.css' => 0,
        'sites/all/themes/pwt/css/pwt-alpha-default.css' => 0,
      ),
      'Seven' => array(
        'themes/seven/ie.css' => 0,
        'themes/seven/ie6.css' => 0,
        'themes/seven/ie7.css' => 0,
        'themes/seven/jquery.ui.theme.css' => 0,
        'themes/seven/reset.css' => 0,
        'themes/seven/style-rtl.css' => 0,
        'themes/seven/style.css' => 0,
        'themes/seven/vertical-tabs-rtl.css' => 0,
        'themes/seven/vertical-tabs.css' => 0,
      ),
    ),
    'delta' => array(
      'delta_template' => 'mobile',
    ),
    'disable_context' => array(
      'disabled' => array(
        'admin-stuff' => 'admin-stuff',
        'admin-stuff-admin-theme' => 'admin-stuff-admin-theme',
        'admin-theme-by-role' => 'admin-theme-by-role',
        'admin_boxes' => 'admin_boxes',
        'area_code_page' => 'area_code_page',
        'classifieds_et_al' => 'classifieds_et_al',
        'dashboard' => 'dashboard',
        'footer_all' => 'footer_all',
        'front_page' => 'front_page',
        'mobile_front' => 'mobile_front',
        'simple_page' => 'simple_page',
        'top_stuff' => 'top_stuff',
        'user' => 'user',
      ),
    ),
    'js' => array(
      'Bartik' => array(
        'themes/bartik/color/preview.js' => 0,
      ),
      'Pennywise Theme' => array(
        'sites/all/themes/pwt/js/jquery.imagesloaded.js' => 0,
        'sites/all/themes/pwt/js/jquery.imagesloaded.min.js' => 0,
        'sites/all/themes/pwt/js/jquery.masonry.min.js' => 0,
        'sites/all/themes/pwt/js/pwt.masonry.js' => 0,
        'sites/all/themes/pwt/js/pwt.mobile.js' => 'sites/all/themes/pwt/js/pwt.mobile.js',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mobile');
  $export['mobile_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search';
  $context->description = 'Default search page';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
        'find' => 'find',
        'find/*' => 'find/*',
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
          'weight' => '-56',
        ),
        'views--exp-search_ads-search_page' => array(
          'module' => 'views',
          'delta' => '-exp-search_ads-search_page',
          'region' => 'content',
          'weight' => '-55',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default search page');
  t('Pages');
  $export['search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_block';
  $context->description = 'Place Search block on classified pages.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'cmd' => array(
      'values' => array(
        2 => 2,
        3 => 3,
      ),
    ),
    'context' => array(
      'values' => array(
        '~mobile_layout' => '~mobile_layout',
      ),
    ),
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
        '~classifieds' => '~classifieds',
        '~ad/submit' => '~ad/submit',
        '~thank-you' => '~thank-you',
        '~ad/*/thank-you' => '~ad/*/thank-you',
        '~user/login' => '~user/login',
        '~display/*' => '~display/*',
        '~editorial/submit' => '~editorial/submit',
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
        'area-code' => 'area-code',
        'features/hometown' => 'features/hometown',
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
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  t('Place Search block on classified pages.');
  $export['search_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'simple_page';
  $context->description = 'Content, header and footer only. No sidebars or header.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/login' => 'user/login',
        'display/*' => 'display/*',
        'editorial/submit' => 'editorial/submit',
        'ad/submit' => 'ad/submit',
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
      ),
    ),
    'delta' => array(
      'delta_template' => 'content_only',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content, header and footer only. No sidebars or header.');
  t('Pages');
  $export['simple_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'top_stuff';
  $context->description = 'Logo, menu bar, address, and splash boxes';
  $context->tag = 'Default';
  $context->conditions = array(
    'cmd' => array(
      'values' => array(
        2 => 2,
        3 => 3,
      ),
    ),
    'context' => array(
      'values' => array(
        '~mobile_layout' => '~mobile_layout',
      ),
    ),
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
        'delta_blocks-logo' => array(
          'module' => 'delta_blocks',
          'delta' => 'logo',
          'region' => 'threeup_one',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-block_1' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-block_1',
          'region' => 'threeup_two',
          'weight' => '-10',
        ),
        'views-display_ad_blocks-splash_block' => array(
          'module' => 'views',
          'delta' => 'display_ad_blocks-splash_block',
          'region' => 'threeup_three',
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default');
  t('Logo, menu bar, address, and splash boxes');
  $export['top_stuff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user';
  $context->description = 'Simple content only user pages.';
  $context->tag = 'Pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
        'people/*' => 'people/*',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'content_only',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Pages');
  t('Simple content only user pages.');
  $export['user'] = $context;

  return $export;
}
