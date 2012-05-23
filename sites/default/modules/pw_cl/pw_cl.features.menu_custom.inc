<?php
/**
 * @file
 * pw_cl.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pw_cl_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-pw-super-menu
  $menus['menu-pw-super-menu'] = array(
    'menu_name' => 'menu-pw-super-menu',
    'title' => 'PW Super Menu',
    'description' => 'Super drop down menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('PW Super Menu');
  t('Super drop down menu');


  return $menus;
}
