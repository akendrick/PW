<?php
/**
 * @file
 * pw_classifieds.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_classifieds_user_default_roles() {
  $roles = array();

  // Exported role: classified editor
  $roles['classified editor'] = array(
    'name' => 'classified editor',
    'weight' => '5',
  );

  return $roles;
}
