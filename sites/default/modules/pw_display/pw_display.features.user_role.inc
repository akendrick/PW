<?php
/**
 * @file
 * pw_display.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_display_user_default_roles() {
  $roles = array();

  // Exported role: display ad client.
  $roles['display ad client'] = array(
    'name' => 'display ad client',
    'weight' => '3',
  );

  // Exported role: display ad editor.
  $roles['display ad editor'] = array(
    'name' => 'display ad editor',
    'weight' => '7',
  );

  return $roles;
}
