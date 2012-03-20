<?php
/**
 * @file
 * pw_classifieds.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_classifieds_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cl_ad_master|node|classified|form';
  $field_group->group_name = 'group_cl_ad_master';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classified Master Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_contact',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Classified Master Group',
      'instance_settings' => array(
        'classes' => 'grid-6',
      ),
    ),
  );
  $export['group_cl_ad_master|node|classified|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|classified|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cl_ad_master';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '14',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|node|classified|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_default|node|classified|form';
  $field_group->group_name = 'group_default';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default',
    'weight' => '0',
    'children' => array(
      0 => 'field_ad_type',
      1 => 'field_ad_copy',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Default',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-6',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_default|node|classified|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_form_basics|node|classified|form';
  $field_group->group_name = 'group_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
      1 => 'field_tags',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-8',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_form_basics|node|classified|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_otional|node|classified|form';
  $field_group->group_name = 'group_otional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Optional',
    'weight' => '2',
    'children' => array(
      0 => 'field_link',
      1 => 'field_phone',
      2 => 'field_area_code',
      3 => 'field_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Optional',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-8',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_otional|node|classified|form'] = $field_group;

  return $export;
}
