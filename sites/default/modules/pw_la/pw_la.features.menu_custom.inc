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

  // Exported menu: menu-special-features.
  $menus['menu-special-features'] = array(
    'menu_name' => 'menu-special-features',
    'title' => 'Special Features',
    'description' => 'Special inserts and features that appear in the Pennywise paper.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Special Features');
  t('Special inserts and features that appear in the Pennywise paper.');


  return $menus;
}
