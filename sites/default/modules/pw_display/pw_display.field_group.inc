<?php
/**
 * @file
 * pw_display.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_display_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|display_ads|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '3',
    'children' => array(
      0 => 'field_display_ad_type',
      1 => 'field_ad_copy',
      2 => 'field_ad_client',
      3 => 'field_publish_date',
      4 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-6',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basics|node|display_ads|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_options|node|display_ads|form';
  $field_group->group_name = 'group_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Options',
    'weight' => '5',
    'children' => array(
      0 => 'field_email',
      1 => 'field_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_options|node|display_ads|form'] = $field_group;

  return $export;
}
