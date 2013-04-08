<?php
/**
 * @file
 * pw_editorial.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pw_editorial_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-advertising-links.
  $menus['menu-advertising-links'] = array(
    'menu_name' => 'menu-advertising-links',
    'title' => 'Advertising Information',
    'description' => 'Advertising information, sales, circulation, web stats, sales reps etc.',
  );
  // Exported menu: menu-browse-classifieds.
  $menus['menu-browse-classifieds'] = array(
    'menu_name' => 'menu-browse-classifieds',
    'title' => 'Browse Classifieds',
    'description' => 'Classified Taxonomy Menu',
  );
  // Exported menu: menu-pennywise-digital-edition.
  $menus['menu-pennywise-digital-edition'] = array(
    'menu_name' => 'menu-pennywise-digital-edition',
    'title' => 'Browse Pennywise',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Advertising Information');
  t('Advertising information, sales, circulation, web stats, sales reps etc.');
  t('Browse Classifieds');
  t('Browse Pennywise');
  t('Classified Taxonomy Menu');


  return $menus;
}
