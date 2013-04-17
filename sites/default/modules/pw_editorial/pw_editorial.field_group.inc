<?php
/**
 * @file
 * pw_editorial.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_editorial_field_group_info() {
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
    'weight' => '1',
    'children' => array(
      0 => 'group_description',
      1 => 'group_optional',
      2 => 'group_special_feature',
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
    'label' => 'Links',
    'weight' => '1',
    'children' => array(
      0 => 'field_link',
      1 => 'field_email',
      2 => 'field_entity_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
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
    'label' => 'File Attachemnt',
    'weight' => '9',
    'children' => array(
      0 => 'body',
      1 => 'field_high_res_ad',
      2 => 'field_image',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'File Attachemnt',
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
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
      1 => 'group_extra_image_group',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
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
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_submitter',
      2 => 'field_area_taxonomy',
      3 => 'title',
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
  $export['group_ed_basic|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ed_group_master|node|article|form';
  $field_group->group_name = 'group_ed_group_master';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Groups',
    'weight' => '1',
    'children' => array(
      0 => 'group_bonus',
      1 => 'group_details',
      2 => 'group_ed_basic',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_ed_group_master|node|article|form'] = $field_group;

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
  $field_group->identifier = 'group_extra_image_group|node|article|form';
  $field_group->group_name = 'group_extra_image_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Upload Extra Images',
    'weight' => '17',
    'children' => array(
      0 => 'field_images_editorial_extra',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Upload Extra Images',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_extra_image_group|node|article|form'] = $field_group;

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
    'label' => 'Optional Features & Inserts',
    'weight' => '2',
    'children' => array(
      0 => 'field_entity_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Optional Features & Inserts',
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
    'weight' => '10',
    'children' => array(
      0 => 'field_link',
      1 => 'field_entity_reference',
      2 => 'field_file',
      3 => 'path',
      4 => 'redirect',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_special_feature|node|attachment|form';
  $field_group->group_name = 'group_special_feature';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'attachment';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attachment';
  $field_group->data = array(
    'label' => 'Special Feature',
    'weight' => '8',
    'children' => array(
      0 => 'field_scribd',
      1 => 'field_feature_type',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Special Feature',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_special_feature|node|attachment|form'] = $field_group;

  return $export;
}
