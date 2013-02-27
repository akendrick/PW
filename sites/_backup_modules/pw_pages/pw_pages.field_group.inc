<?php
/**
 * @file
 * pw_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_pages_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attachment|node|attachment|form';
  $field_group->group_name = 'group_attachment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'attachment';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attachment',
    'weight' => '0',
    'children' => array(
      0 => 'group_basics',
      1 => 'group_optional',
      2 => 'group_description',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Attachment',
      'instance_settings' => array(
        'classes' => '',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_attachment|node|attachment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|attachment|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'attachment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attachment';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '1',
    'children' => array(
      0 => 'field_high_res_ad',
      1 => 'field_image',
      2 => 'title',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basics|node|attachment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bonus|node|article|form';
  $field_group->group_name = 'group_bonus';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_link',
      1 => 'field_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bonus|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|attachment|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'attachment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attachment';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '2',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_description|node|attachment|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|article|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '3',
    'children' => array(
      0 => 'field_entity_reference',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ed_basic|node|article|form';
  $field_group->group_name = 'group_ed_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic',
    'weight' => '1',
    'children' => array(
      0 => 'field_submitter',
      1 => 'field_area_taxonomy',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ed_basic|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_edition|node|pw_digital|form';
  $field_group->group_name = 'group_edition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pw_digital';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Edition',
    'weight' => '0',
    'children' => array(
      0 => 'field_trail',
      1 => 'field_nelson_edition',
      2 => 'field_castlegar_edition',
      3 => 'field_kootenay_lake_edition',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_edition|node|pw_digital|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_details|node|article|default';
  $field_group->group_name = 'group_editorial_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_submitter',
      1 => 'field_area_taxonomy',
      2 => 'post_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_editorial_details|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_more|node|article|default';
  $field_group->group_name = 'group_editorial_more';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'field_link',
      1 => 'field_email',
      2 => 'field_entity_reference',
      3 => 'links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_editorial_more|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|pw_editions|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pw_digital';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_edition_date',
      1 => 'field_display_ad',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|node|pw_editions|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_optional_features|node|pw_digital|form';
  $field_group->group_name = 'group_optional_features';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pw_digital';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Optional Features',
    'weight' => '2',
    'children' => array(
      0 => 'field_entity_reference',
      1 => 'field_scribd',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Optional Features',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Add a special feature such as Carolling, or Home Town Business Section here. They can be attachment features or extra links to additional Scribd documents.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_optional_features|node|pw_digital|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_optional|node|attachment|form';
  $field_group->group_name = 'group_optional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'attachment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attachment';
  $field_group->data = array(
    'label' => 'Optional',
    'weight' => '3',
    'children' => array(
      0 => 'field_link',
      1 => 'field_entity_reference',
      2 => 'path',
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
  $export['group_optional|node|attachment|form'] = $field_group;

  return $export;
}
