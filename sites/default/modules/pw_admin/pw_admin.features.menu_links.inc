<?php
/**
 * @file
 * pw_admin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pw_admin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management:admin/pennywise
  $menu_links['management:admin/pennywise'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise',
    'router_path' => 'admin/pennywise',
    'link_title' => 'Pennywise',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: management:admin/pennywise/settings
  $menu_links['management:admin/pennywise/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise/settings',
    'router_path' => 'admin/pennywise/settings',
    'link_title' => 'Pennywise Settings',
    'options' => array(),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise',
  );
  // Exported menu link: menu-pw-admin:<front>
  $menu_links['menu-pw-admin:<front>'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Pennywise',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/article
  $menu_links['menu-pw-admin:admin/pennywise/article'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/article',
    'router_path' => 'admin/pennywise',
    'link_title' => 'Editorial',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/classified
  $menu_links['menu-pw-admin:admin/pennywise/classified'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/classified',
    'router_path' => 'admin/pennywise/classified',
    'link_title' => 'Classifieds',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/classified/ad_s
  $menu_links['menu-pw-admin:admin/pennywise/classified/ad_s'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/classified/ad_s',
    'router_path' => 'admin/pennywise/classified/ad_s',
    'link_title' => 'Incoming',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'admin/pennywise/classified',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/classified/liveload
  $menu_links['menu-pw-admin:admin/pennywise/classified/liveload'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/classified/liveload',
    'router_path' => 'admin/pennywise/classified/liveload',
    'link_title' => 'Liveload',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'admin/pennywise/classified',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/display_ads
  $menu_links['menu-pw-admin:admin/pennywise/display_ads'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/display_ads',
    'router_path' => 'admin/pennywise/display_ads',
    'link_title' => 'Display',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/display_ads/all
  $menu_links['menu-pw-admin:admin/pennywise/display_ads/all'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/display_ads/all',
    'router_path' => 'admin/pennywise/display_ads/all',
    'link_title' => 'All Display',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/display_ads',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/display_ads/banner
  $menu_links['menu-pw-admin:admin/pennywise/display_ads/banner'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/display_ads/banner',
    'router_path' => 'admin/pennywise/display_ads/banner',
    'link_title' => 'Banner',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/display_ads',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/display_ads/poster
  $menu_links['menu-pw-admin:admin/pennywise/display_ads/poster'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/display_ads/poster',
    'router_path' => 'admin/pennywise/display_ads/poster',
    'link_title' => 'Poster',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/display_ads',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/display_ads/print
  $menu_links['menu-pw-admin:admin/pennywise/display_ads/print'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/display_ads/print',
    'router_path' => 'admin/pennywise/display_ads/print',
    'link_title' => 'Print Ads',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/display_ads',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/display_ads/splash
  $menu_links['menu-pw-admin:admin/pennywise/display_ads/splash'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/display_ads/splash',
    'router_path' => 'admin/pennywise/display_ads/splash',
    'link_title' => 'Splash',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/display_ads',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/edition/digital
  $menu_links['menu-pw-admin:admin/pennywise/edition/digital'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/edition/digital',
    'router_path' => 'admin/pennywise/edition',
    'link_title' => 'Edition',
    'options' => array(
      'attributes' => array(
        'title' => 'Pennywise Digital Edition administration',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/pages
  $menu_links['menu-pw-admin:admin/pennywise/pages'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/pages',
    'router_path' => 'admin/pennywise/pages',
    'link_title' => 'Pages',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/pages/attachments
  $menu_links['menu-pw-admin:admin/pennywise/pages/attachments'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/pages/attachments',
    'router_path' => 'admin/pennywise/pages/attachments',
    'link_title' => 'Attachments',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/pages',
  );
  // Exported menu link: menu-pw-admin:admin/pennywise/settings/
  $menu_links['menu-pw-admin:admin/pennywise/settings/'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'admin/pennywise/settings/',
    'router_path' => 'admin/pennywise/settings',
    'link_title' => 'Settings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-pw-admin:node/add
  $menu_links['menu-pw-admin:node/add'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-49',
  );
  // Exported menu link: menu-pw-admin:node/add/adworks-file
  $menu_links['menu-pw-admin:node/add/adworks-file'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/adworks-file',
    'router_path' => 'node/add/adworks-file',
    'link_title' => 'Upload Adworks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-pw-admin:node/add/article
  $menu_links['menu-pw-admin:node/add/article'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/article',
    'router_path' => 'node/add/article',
    'link_title' => 'Create Editorial',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-pw-admin:node/add/attachment
  $menu_links['menu-pw-admin:node/add/attachment'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/attachment',
    'router_path' => 'node/add/attachment',
    'link_title' => 'Create Attachment',
    'options' => array(
      'attributes' => array(
        'title' => 'Creates PDF downloads for clients and sales, amongst other things.',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: menu-pw-admin:node/add/classified
  $menu_links['menu-pw-admin:node/add/classified'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/classified',
    'router_path' => 'node/add/classified',
    'link_title' => 'Create Classified Ad',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-pw-admin:node/add/display-ads
  $menu_links['menu-pw-admin:node/add/display-ads'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/display-ads',
    'router_path' => 'node/add/display-ads',
    'link_title' => 'Create Display Ad',
    'options' => array(
      'attributes' => array(
        'title' => 'One stop creation button for all display ads.',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: menu-pw-admin:node/add/page
  $menu_links['menu-pw-admin:node/add/page'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Create Page',
    'options' => array(
      'attributes' => array(
        'title' => 'Create static pages',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: menu-pw-admin:node/add/pw-digital
  $menu_links['menu-pw-admin:node/add/pw-digital'] = array(
    'menu_name' => 'menu-pw-admin',
    'link_path' => 'node/add/pw-digital',
    'router_path' => 'node/add/pw-digital',
    'link_title' => 'Add Digital Edition',
    'options' => array(
      'attributes' => array(
        'title' => 'Attach digital edition page',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Content');
  t('Add Digital Edition');
  t('All Display');
  t('Attachments');
  t('Banner');
  t('Classifieds');
  t('Create Attachment');
  t('Create Classified Ad');
  t('Create Display Ad');
  t('Create Editorial');
  t('Create Page');
  t('Display');
  t('Edition');
  t('Editorial');
  t('Incoming');
  t('Liveload');
  t('Pages');
  t('Pennywise');
  t('Pennywise Settings');
  t('Poster');
  t('Print Ads');
  t('Settings');
  t('Splash');
  t('Upload Adworks');


  return $menu_links;
}
