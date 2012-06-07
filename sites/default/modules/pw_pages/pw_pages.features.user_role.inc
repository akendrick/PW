<?php
/**
 * @file
 * pw_pages.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_pages_user_default_roles() {
  $roles = array();

  // Exported role: editorial editor.
  $roles['editorial editor'] = array(
    'name' => 'editorial editor',
    'weight' => '6',
  );

  // Exported role: page editor.
  $roles['page editor'] = array(
    'name' => 'page editor',
    'weight' => '9',
  );

  return $roles;
}
