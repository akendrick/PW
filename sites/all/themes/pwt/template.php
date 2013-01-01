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

  $zebra = 0;
  foreach (element_children($variables['content']) as $mlid){
    $variables['content'][$mlid]['#attributes']['class'][] = ($zebra % 2) ? 'odd' : 'even';
    $zebra++;
  }
}

/**
* Implementation of template_preprocess_taxonomy_term
*/
function pwt_taxonomy_term_view_alter(&$build) {
//  dpm($build);
}

/**
* Implementation of HOOK_preprocess_block
*/

function pwt_preprocess_block(&$variables) {
 // dpm($variables);
  if ($variables['elements']['#delta'] == 6) {
    //dpm('Header');
    //dpm($variables);
   // $variables['elements']['#content']['10056']
  }
}



/**
* Implementation of HOOK_views_exposed_form
*/
// function pwt_preprocess_views_exposed_form($vars) {
//   if ($vars['form']['#id'] == 'views-exposed-form-search-ads-search-page') {
//     dpm('Views Exposed');
//     dpm($vars);
//   }
// }