<?php
/**
 * @file
 * pw_cl.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_cl_user_default_roles() {
  $roles = array();

  // Exported role: classified editor.
  $roles['classified editor'] = array(
    'name' => 'classified editor',
    'weight' => '6',
  );

  // Exported role: submit ad.
  $roles['submit ad'] = array(
    'name' => 'submit ad',
    'weight' => '1',
  );

  return $roles;
}
