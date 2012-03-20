<?php
/**
 * @file
 * pw_ad_submission.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function pw_ad_submission_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ad_submission_page';
  $context->description = 'Ad submission theming';
  $context->tag = 'submit, page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ad_s' => 'ad_s',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'ad_payment-ad_payment_create_ad' => array(
          'module' => 'ad_payment',
          'delta' => 'ad_payment_create_ad',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'ad_submission_layout',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ad submission theming');
  t('submit, page');
  $export['ad_submission_page'] = $context;

  return $export;
}
