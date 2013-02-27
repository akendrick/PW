<?php
/**
 * @file
 * pw_admin.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pw_admin_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-pw-admin.
  $menus['menu-pw-admin'] = array(
    'menu_name' => 'menu-pw-admin',
    'title' => 'PW Admin',
    'description' => 'Pennywise website administration menu links.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Management');
  t('PW Admin');
  t('Pennywise website administration menu links.');
  t('The <em>Management</em> menu contains links for administrative tasks.');


  return $menus;
}
