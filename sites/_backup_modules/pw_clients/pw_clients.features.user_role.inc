<?php
/**
 * @file
 * pw_clients.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_clients_user_default_roles() {
  $roles = array();

  // Exported role: user editor.
  $roles['user editor'] = array(
    'name' => 'user editor',
    'weight' => '10',
  );

  return $roles;
}
