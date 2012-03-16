<?php
/**
 * @file
 * pw_users_contact.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_users_contact_user_default_roles() {
  $roles = array();

  // Exported role: sales
  $roles['sales'] = array(
    'name' => 'sales',
    'weight' => '8',
  );

  return $roles;
}
