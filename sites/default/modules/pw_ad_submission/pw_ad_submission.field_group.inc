<?php
/**
 * @file
 * pw_ad_submission.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_ad_submission_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_grouping|node|ad_s|form';
  $field_group->group_name = 'group_ad_grouping';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad';
  $field_group->data = array(
    'label' => 'Ad Group',
    'weight' => '27',
    'children' => array(
      0 => 'field_notes',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Ad Group',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ad_grouping|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_review|node|ad_s|form';
  $field_group->group_name = 'group_ad_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vgroup_parent';
  $field_group->data = array(
    'label' => 'Ad Review',
    'weight' => '4',
    'children' => array(
      0 => 'field_ad_details',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ad_review|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad|node|ad_s|form';
  $field_group->group_name = 'group_ad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vgroup_parent';
  $field_group->data = array(
    'label' => 'Create Classified Ad',
    'weight' => '1',
    'children' => array(
      0 => 'field_ad_copy',
      1 => 'group_area_rate',
      2 => 'group_section_duration',
      3 => 'group_ad_grouping',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Create Classified Ad',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $export['group_ad|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_area_rate|node|ad_s|form';
  $field_group->group_name = 'group_area_rate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad';
  $field_group->data = array(
    'label' => 'Area & Rate',
    'weight' => '25',
    'children' => array(
      0 => 'field_area',
      1 => 'field_rate',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Area & Rate',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_area_rate|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_payment|node|ad_s|form';
  $field_group->group_name = 'group_payment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vgroup_parent';
  $field_group->data = array(
    'label' => 'Submit Payment',
    'weight' => '3',
    'children' => array(
      0 => 'field_price',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Submit Payment',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $export['group_payment|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_duration|node|ad_s|form';
  $field_group->group_name = 'group_section_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad';
  $field_group->data = array(
    'label' => 'Section & Duration',
    'weight' => '26',
    'children' => array(
      0 => 'field_tags',
      1 => 'field_duration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Section & Duration',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_section_duration|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_upgrade|node|ad_s|form';
  $field_group->group_name = 'group_upgrade';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vgroup_parent';
  $field_group->data = array(
    'label' => 'Upgrade Your Ad',
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
      1 => 'field_promote',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Upgrade Your Ad',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $export['group_upgrade|node|ad_s|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vgroup_parent|node|ad_s|form';
  $field_group->group_name = 'group_vgroup_parent';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Submit Ad Vgroup',
    'weight' => '0',
    'children' => array(
      0 => 'group_ad',
      1 => 'group_upgrade',
      2 => 'group_payment',
      3 => 'group_ad_review',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Submit Ad Vgroup',
      'instance_settings' => array(
        'classes' => '',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '0',
        'move_additional' => '1',
      ),
    ),
  );
  $export['group_vgroup_parent|node|ad_s|form'] = $field_group;

  return $export;
}
