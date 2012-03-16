<?php
/**
 * @file
 * pw_defaults.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_defaults_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '7',
  );

  return $roles;
}
