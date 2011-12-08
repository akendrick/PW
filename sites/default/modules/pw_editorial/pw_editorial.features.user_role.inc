<?php
/**
 * @file
 * pw_editorial.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_editorial_user_default_roles() {
  $roles = array();

  // Exported role: editorial editor
  $roles['editorial editor'] = array(
    'name' => 'editorial editor',
    'weight' => '6',
  );

  return $roles;
}
