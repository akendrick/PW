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
  $field_group->identifier = 'group_advanced|node|display_ads|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_display_ad';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '4',
    'children' => array(
      0 => 'field_special_feature_link',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_advanced|node|display_ads|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|display_ads|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_display_ad';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '1',
    'children' => array(
      0 => 'field_display_ad',
      1 => 'field_tags',
      2 => 'field_section_all_select',
      3 => 'field_publish_date',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-6',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basics|node|display_ads|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description_box|node|display_ads|form';
  $field_group->group_name = 'group_description_box';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_display_ad';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '2',
    'children' => array(
      0 => 'field_display_ad_type',
      1 => 'field_ad_copy',
      2 => 'field_ad_client',
      3 => 'title',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'blind',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_description_box|node|display_ads|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display_ad|node|display_ads|form';
  $field_group->group_name = 'group_display_ad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Display Ad',
    'weight' => '0',
    'children' => array(
      0 => 'group_advanced',
      1 => 'group_basics',
      2 => 'group_description_box',
      3 => 'group_options',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => '',
      ),
    ),
  );
  $export['group_display_ad|node|display_ads|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_options|node|display_ads|form';
  $field_group->group_name = 'group_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'display_ads';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_display_ad';
  $field_group->data = array(
    'label' => 'Options',
    'weight' => '3',
    'children' => array(
      0 => 'field_email',
      1 => 'field_link',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_options|node|display_ads|form'] = $field_group;

  return $export;
}
