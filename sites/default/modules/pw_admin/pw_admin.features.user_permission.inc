<?php
/**
 * @file
 * pw_admin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pw_admin_user_default_permissions() {
  $permissions = array();

  // Exported permission: access rules debug.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rules',
  );

  return $permissions;
}
