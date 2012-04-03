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

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '7',
  );

  // Exported role: classified editor
  $roles['classified editor'] = array(
    'name' => 'classified editor',
    'weight' => '5',
  );

  // Exported role: display ad client
  $roles['display ad client'] = array(
    'name' => 'display ad client',
    'weight' => '3',
  );

  // Exported role: display ad editor
  $roles['display ad editor'] = array(
    'name' => 'display ad editor',
    'weight' => '4',
  );

  // Exported role: editorial editor
  $roles['editorial editor'] = array(
    'name' => 'editorial editor',
    'weight' => '6',
  );

  // Exported role: page editor
  $roles['page editor'] = array(
    'name' => 'page editor',
    'weight' => '9',
  );

  // Exported role: sales
  $roles['sales'] = array(
    'name' => 'sales',
    'weight' => '8',
  );

  // Exported role: submit ad
  $roles['submit ad'] = array(
    'name' => 'submit ad',
    'weight' => '1',
  );

  return $roles;
}
