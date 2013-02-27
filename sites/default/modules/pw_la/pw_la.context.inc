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
  $context->name = 'classifieds_et_al';
  $context->description = 'General look and feel for classifieds and most pages';
  $context->tag = 'Pages';
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
        'pennywise-submit_editorial' => array(
          'module' => 'pennywise',
          'delta' => 'submit_editorial',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'pennywise-pw_tmtv' => array(
          'module' => 'pennywise',
          'delta' => 'pw_tmtv',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'pennywise-pw_edition' => array(
          'module' => 'pennywise',
          'delta' => 'pw_edition',
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
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('General look and feel for classifieds and most pages');
  t('Pages');
  $export['classifieds_et_al'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer_all';
  $context->description = 'General links appearing at the bottom of every page';
  $context->tag = 'Default';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~ad/submit' => '~ad/submit',
        '~ad/*/thank-you' => '~ad/*/thank-you',
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
  $context->condition_mode = 0;

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
  $context->name = 'mobile_layout';
  $context->description = '';
  $context->tag = 'default';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('default');
  $export['mobile_layout'] = $context;

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

  return $export;
}
