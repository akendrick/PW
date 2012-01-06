<?php
/**
 * @file
 * pw_display.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pw_display_user_default_permissions() {
  $permissions = array();

  // Exported permission: create display_ads content
  $permissions['create display_ads content'] = array(
    'name' => 'create display_ads content',
    'roles' => array(
      0 => 'display ad editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any display_ads content
  $permissions['delete any display_ads content'] = array(
    'name' => 'delete any display_ads content',
    'roles' => array(
      0 => 'display ad editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own display_ads content
  $permissions['delete own display_ads content'] = array(
    'name' => 'delete own display_ads content',
    'roles' => array(
      0 => 'display ad editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any display_ads content
  $permissions['edit any display_ads content'] = array(
    'name' => 'edit any display_ads content',
    'roles' => array(
      0 => 'display ad editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own display_ads content
  $permissions['edit own display_ads content'] = array(
    'name' => 'edit own display_ads content',
    'roles' => array(
      0 => 'display ad editor',
    ),
    'module' => 'node',
  );

  // Exported permission: publish any display_ads content
  $permissions['publish any display_ads content'] = array(
    'name' => 'publish any display_ads content',
    'roles' => array(
      0 => 'administrator',
      1 => 'display ad editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish editable display_ads content
  $permissions['publish editable display_ads content'] = array(
    'name' => 'publish editable display_ads content',
    'roles' => array(
      0 => 'administrator',
      1 => 'display ad editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish own display_ads content
  $permissions['publish own display_ads content'] = array(
    'name' => 'publish own display_ads content',
    'roles' => array(
      0 => 'administrator',
      1 => 'display ad editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish any display_ads content
  $permissions['unpublish any display_ads content'] = array(
    'name' => 'unpublish any display_ads content',
    'roles' => array(
      0 => 'administrator',
      1 => 'display ad editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish editable display_ads content
  $permissions['unpublish editable display_ads content'] = array(
    'name' => 'unpublish editable display_ads content',
    'roles' => array(
      0 => 'administrator',
      1 => 'display ad editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish own display_ads content
  $permissions['unpublish own display_ads content'] = array(
    'name' => 'unpublish own display_ads content',
    'roles' => array(
      0 => 'administrator',
      1 => 'display ad editor',
    ),
    'module' => 'publishcontent',
  );

  return $permissions;
}