<?php
/**
 * @file
 * pw_pages_attachments.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_pages_attachments_user_default_roles() {
  $roles = array();

  // Exported role: page editor
  $roles['page editor'] = array(
    'name' => 'page editor',
    'weight' => '9',
  );

  return $roles;
}
