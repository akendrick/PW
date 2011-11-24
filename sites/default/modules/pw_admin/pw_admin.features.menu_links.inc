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
    'weight' => '0',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/pennywise/ads
  $menu_links['management:admin/pennywise/ads'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise/ads',
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
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'admin/pennywise',
  );
  // Exported menu link: management:admin/pennywise/ads/classifieds
  $menu_links['management:admin/pennywise/ads/classifieds'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise/ads/classifieds',
    'router_path' => 'admin/pennywise/ads/classifieds',
    'link_title' => 'Classified Ad Administration',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'admin/pennywise',
  );
  // Exported menu link: management:admin/pennywise/ads/classifieds/all
  $menu_links['management:admin/pennywise/ads/classifieds/all'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise/ads/classifieds/all',
    'router_path' => 'admin/pennywise/ads/classifieds/all',
    'link_title' => 'Classified Ads',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/ads/classifieds',
  );
  // Exported menu link: management:admin/pennywise/ads/classifieds/incoming
  $menu_links['management:admin/pennywise/ads/classifieds/incoming'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise/ads/classifieds/incoming',
    'router_path' => 'admin/pennywise/ads/classifieds/incoming',
    'link_title' => 'Incoming Ads',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-20',
    'parent_path' => 'admin/pennywise/ads/classifieds',
  );
  // Exported menu link: management:admin/pennywise/ads/classifieds/liveload
  $menu_links['management:admin/pennywise/ads/classifieds/liveload'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/pennywise/ads/classifieds/liveload',
    'router_path' => 'admin/pennywise/ads/classifieds/liveload',
    'link_title' => 'Liveload Ad Administration',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/pennywise/ads/classifieds',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Classified Ad Administration');
  t('Classified Ads');
  t('Editorial');
  t('Incoming Ads');
  t('Liveload Ad Administration');
  t('Pennywise');


  return $menu_links;
}
