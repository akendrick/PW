<?php
/**
 * @file
 * pw_clients.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pw_clients_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
      1 => 'user editor',
    ),
    'module' => 'user',
  );

  return $permissions;
}
