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
    'label' => 'Review & Submit',
    'weight' => '4',
    'children' => array(
      0 => 'field_ad_details',
      1 => 'field_agree',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Review & Submit',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<h2>Review</h2>
<ol><li>Review your ad to make sure all the information is correct<li>If there are any issues select the appropriate tab on top to correct it.<li> When finished click on SUBMIT to submit your ad. </ol>',
      ),
      'formatter' => 'closed',
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
    'label' => '1. CREATE AD',
    'weight' => '1',
    'children' => array(
      0 => 'field_ad_copy',
      1 => 'group_area_rate',
      2 => 'group_section_duration',
      3 => 'group_ad_grouping',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '1. CREATE AD',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<h2>Step One:</h2>
<ol><li><strong>Create your classified ad here.</strong><br>Fill out all the fields on this page. <li>When finished this page select the OPTIONS tab to continue. </ol>',
      ),
      'formatter' => 'open',
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
    'label' => '3. PAYMENT',
    'weight' => '3',
    'children' => array(
      0 => 'field_price',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '3. PAYMENT',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<h2>Step Three:</h2>
<ol><li>Fill out your credit card information here.<br /><strong>Pennywise makes every effort to keep your information safe!</strong><br><li>When finished this page select the REVIEW tab to finish. </ol>',
      ),
      'formatter' => 'closed',
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
    'label' => '2. OPTIONS',
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
      1 => 'field_promote',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => '2. OPTIONS',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<h2>Step Two:</h2>
<ol><li>Add some pizzaz with an image or get your ad online now with a liveload. <li>When finished this page select the PAYMENT tab to continue. </ol>',
      ),
      'formatter' => 'closed',
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
    'label' => 'Submit Ad Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_ad',
      1 => 'group_upgrade',
      2 => 'group_payment',
      3 => 'group_ad_review',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Submit Ad Group',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_vgroup_parent|node|ad_s|form'] = $field_group;

  return $export;
}
