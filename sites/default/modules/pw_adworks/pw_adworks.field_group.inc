<?php
/**
 * @file
 * pw_adworks.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_adworks_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|node|adworks_file|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'adworks_file';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administration',
    'weight' => '1',
    'children' => array(
      0 => 'field_date_start',
      1 => 'field_image_override',
      2 => 'field_ad_creation_override',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Administration',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_admin|node|adworks_file|form'] = $field_group;

  return $export;
}
