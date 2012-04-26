<?php

/**
 * @file
 *
 * - Menu Zebra stripping.
 *
 *
 *
 *
 */
 
 

/**
 * Preprocesses menus being rendered in blocks to add zebra-striping classes to
 * each menu item.
 *
 * Desired output has odd/even classes like:
 *
 * <ul class="menu">
 *   <li class="first leaf has-children menu-mlid-346 even"><a href="/racing">Racing</a></li>
 *   <li class="leaf menu-mlid-347 odd"><a href="/recreational">Recreational</a></li>
 *   <li class="leaf menu-mlid-348 even"><a href="/get-sailing">Get into Sailing</a></li>
 *   <li class="last leaf menu-mlid-349 odd"><a href="/clubs">Clubs</a></li>
 * </ul>
 */
function pwt_preprocess_menu_advertising_links_block_wrapper(&$variables, $hook) {
  dpm($variables);
  
  $zebra = 0;
  foreach (element_children($variables['content']) as $mlid){
    $variables['content'][$mlid]['#attributes']['class'][] = ($zebra % 2) ? 'odd' : 'even';
    $zebra++;
  }
}


// function pwt_menu_alter(&$items) {
//   dpm ($items);
// 
// }