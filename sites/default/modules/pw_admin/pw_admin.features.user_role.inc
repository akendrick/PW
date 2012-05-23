<?php
/**
 * @file
 * pw_admin.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_admin_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '7',
  );

  // Exported role: sales.
  $roles['sales'] = array(
    'name' => 'sales',
    'weight' => '8',
  );

  return $roles;
}
