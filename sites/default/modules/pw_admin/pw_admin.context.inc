<?php
/**
 * @file
 * pw_admin.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_admin_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'admin-stuff';
  $context->description = 'Admin special features';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/*' => 'admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin special features');
  t('admin');
  $export['admin-stuff'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'admin-stuff-admin-theme';
  $context->description = 'Admin special features';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin/*' => '~admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin special features');
  t('admin');
  $export['admin-stuff-admin-theme'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'admin-theme-by-role';
  $context->description = 'Provide admin theme when creating nodes.';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/' => 'node/add/',
        'node/add/*' => 'node/add/*',
        'admin/' => 'admin/',
        'admin/*' => 'admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'classified editor' => 'classified editor',
        'digital edition editor' => 'digital edition editor',
        'display ad editor' => 'display ad editor',
        'editorial editor' => 'editorial editor',
        'page editor' => 'page editor',
        'sales' => 'sales',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'admin_theme_',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provide admin theme when creating nodes.');
  t('admin');
  $export['admin-theme-by-role'] = $context;

  return $export;
}
