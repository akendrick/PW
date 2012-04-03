<?php
/**
 * @file
 * pw_pages_attachments.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pw_pages_attachments_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-pages
  $menus['menu-pages'] = array(
    'menu_name' => 'menu-pages',
    'title' => 'Menu Pages',
    'description' => 'No data',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu Pages');
  t('No data');


  return $menus;
}
