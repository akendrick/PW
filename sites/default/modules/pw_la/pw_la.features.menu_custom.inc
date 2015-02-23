<?php
/**
 * @file
 * pw_la.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pw_la_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-pw-mobile-menu.
  $menus['menu-pw-mobile-menu'] = array(
    'menu_name' => 'menu-pw-mobile-menu',
    'title' => 'PW Mobile Menu',
    'description' => 'Quick links to all major PW pages',
  );
  // Exported menu: menu-special-features.
  $menus['menu-special-features'] = array(
    'menu_name' => 'menu-special-features',
    'title' => 'Special Features',
    'description' => 'Special inserts and features that appear in the Pennywise paper.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('PW Mobile Menu');
  t('Quick links to all major PW pages');
  t('Special Features');
  t('Special inserts and features that appear in the Pennywise paper.');


  return $menus;
}
