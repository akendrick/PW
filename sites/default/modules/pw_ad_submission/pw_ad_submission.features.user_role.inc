<?php
/**
 * @file
 * pw_ad_submission.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pw_ad_submission_user_default_roles() {
  $roles = array();

  // Exported role: submit ad
  $roles['submit ad'] = array(
    'name' => 'submit ad',
    'weight' => '1',
  );

  return $roles;
}
