<?php
/**
 * @file
 * pw_ad_submission.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pw_ad_submission_user_default_permissions() {
  $permissions = array();

  // Exported permission: publish any adworks_file content
  $permissions['publish any adworks_file content'] = array(
    'name' => 'publish any adworks_file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish any classified content
  $permissions['publish any classified content'] = array(
    'name' => 'publish any classified content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish editable adworks_file content
  $permissions['publish editable adworks_file content'] = array(
    'name' => 'publish editable adworks_file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish editable classified content
  $permissions['publish editable classified content'] = array(
    'name' => 'publish editable classified content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish own adworks_file content
  $permissions['publish own adworks_file content'] = array(
    'name' => 'publish own adworks_file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish own classified content
  $permissions['publish own classified content'] = array(
    'name' => 'publish own classified content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish any adworks_file content
  $permissions['unpublish any adworks_file content'] = array(
    'name' => 'unpublish any adworks_file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish any classified content
  $permissions['unpublish any classified content'] = array(
    'name' => 'unpublish any classified content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish editable adworks_file content
  $permissions['unpublish editable adworks_file content'] = array(
    'name' => 'unpublish editable adworks_file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish editable classified content
  $permissions['unpublish editable classified content'] = array(
    'name' => 'unpublish editable classified content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish own adworks_file content
  $permissions['unpublish own adworks_file content'] = array(
    'name' => 'unpublish own adworks_file content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish own classified content
  $permissions['unpublish own classified content'] = array(
    'name' => 'unpublish own classified content',
    'roles' => array(
      0 => 'administrator',
      1 => 'classified editor',
    ),
    'module' => 'publishcontent',
  );

  return $permissions;
}
