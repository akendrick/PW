<?php
/**
 * @file
 * pw_users_contact.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_users_contact_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|user|user|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Contact Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_address',
      1 => 'timezone',
      2 => 'wysiwyg',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contact|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sales|user|user|form';
  $field_group->group_name = 'group_sales';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sales',
    'weight' => '4',
    'children' => array(
      0 => 'field_phone',
      1 => 'field_fax',
      2 => 'field_area_taxonomy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sales',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_sales|user|user|form'] = $field_group;

  return $export;
}
