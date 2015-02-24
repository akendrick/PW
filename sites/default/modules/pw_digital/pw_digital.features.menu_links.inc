<?php
/**
 * @file
 * pw_digital.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pw_digital_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-pennywise-digital-edition:edition
  $menu_links['menu-pennywise-digital-edition:edition'] = array(
    'menu_name' => 'menu-pennywise-digital-edition',
    'link_path' => 'edition',
    'router_path' => 'edition',
    'link_title' => 'Browse Past Editions',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '50',
  );
  // Exported menu link: menu-pennywise-digital-edition:edition/castlegar-slocan
  $menu_links['menu-pennywise-digital-edition:edition/castlegar-slocan'] = array(
    'menu_name' => 'menu-pennywise-digital-edition',
    'link_path' => 'edition/castlegar-slocan',
    'router_path' => 'edition/castlegar-slocan',
    'link_title' => 'Castlegar & Slocan Valley',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-pennywise-digital-edition:edition/kootenay-lake
  $menu_links['menu-pennywise-digital-edition:edition/kootenay-lake'] = array(
    'menu_name' => 'menu-pennywise-digital-edition',
    'link_path' => 'edition/kootenay-lake',
    'router_path' => 'edition/kootenay-lake',
    'link_title' => 'Kootenay Lake',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-pennywise-digital-edition:edition/nelson-salmo
  $menu_links['menu-pennywise-digital-edition:edition/nelson-salmo'] = array(
    'menu_name' => 'menu-pennywise-digital-edition',
    'link_path' => 'edition/nelson-salmo',
    'router_path' => 'edition/nelson-salmo',
    'link_title' => 'Nelson & Salmo',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-pennywise-digital-edition:edition/trail-area
  $menu_links['menu-pennywise-digital-edition:edition/trail-area'] = array(
    'menu_name' => 'menu-pennywise-digital-edition',
    'link_path' => 'edition/trail-area',
    'router_path' => 'edition/trail-area',
    'link_title' => 'Trail, Beaver Valley & Rossland',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-special-features:edition/hometown
  $menu_links['menu-special-features:edition/hometown'] = array(
    'menu_name' => 'menu-special-features',
    'link_path' => 'edition/hometown',
    'router_path' => 'edition/hometown',
    'link_title' => 'Hometown',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
<<<<<<< HEAD
    'weight' => '50',
=======
    'weight' => '-47',
>>>>>>> SiteReformation
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Browse Past Editions');
  t('Castlegar & Slocan Valley');
  t('Hometown');
  t('Kootenay Lake');
  t('Nelson & Salmo');
  t('Trail, Beaver Valley & Rossland');


  return $menu_links;
}
