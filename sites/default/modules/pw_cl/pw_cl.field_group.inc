<?php
/**
 * @file
 * pw_cl.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_cl_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_copy_block|node|ad_s|form';
  $field_group->group_name = 'group_ad_copy_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic_info_box';
  $field_group->data = array(
    'label' => 'Ad Copy',
    'weight' => '-18',
    'children' => array(
      0 => 'field_ad_copy',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Ad Copy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-24 alpha omega',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ad_copy_block|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_grouping|node|ad_s|form';
  $field_group->group_name = 'group_ad_grouping';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ad Group',
    'weight' => '-200',
    'children' => array(
      0 => 'group_ad',
      1 => 'group_payment',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Ad Group',
      'instance_settings' => array(
        'classes' => 'grid-24 alpha omega',
        'page_header' => '0',
        'page_counter' => '0',
        'move_button' => '1',
        'move_additional' => '1',
      ),
    ),
  );
  $export['group_ad_grouping|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_review|node|ad_s|form';
  $field_group->group_name = 'group_ad_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad_grouping';
  $field_group->data = array(
    'label' => 'SUBMIT',
    'weight' => '5',
    'children' => array(
      0 => 'field_agree',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'SUBMIT',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $export['group_ad_review|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
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
    'weight' => '3',
    'children' => array(
      0 => 'field_image_override',
      1 => 'field_ad_creation_override',
      2 => 'title',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad|node|ad_s|form';
  $field_group->group_name = 'group_ad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad_grouping';
  $field_group->data = array(
    'label' => 'CREATE AD',
    'weight' => '-80',
    'children' => array(
      0 => 'group_upgrade',
      1 => 'group_basic_info_box',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'CREATE AD',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $export['group_ad|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_area_rate|node|ad_s|form';
  $field_group->group_name = 'group_area_rate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic_info_box';
  $field_group->data = array(
    'label' => 'Area & Rate',
    'weight' => '-17',
    'children' => array(
      0 => 'field_area',
      1 => 'field_duration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Area & Rate',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-8 alpha',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_info_box|node|ad_s|form';
  $field_group->group_name = 'group_basic_info_box';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad';
  $field_group->data = array(
    'label' => '',
    'weight' => '-20',
    'children' => array(
      0 => 'group_free_for_free',
      1 => 'group_ad_copy_block',
      2 => 'group_area_rate',
      3 => 'group_section_duration',
      4 => 'group_section_group',
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
  $export['group_basic_info_box|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|ad_s|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ad';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'group_free_for_free',
      1 => 'group_ad_copy_block',
      2 => 'group_area_rate',
      3 => 'group_section_duration',
      4 => 'group_section_group',
      5 => 'group_upgrade',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basic|node|ad_s|form'] = $field_group;

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
    'weight' => '5',
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
  $field_group->identifier = 'group_classified_ad|node|ad_s|form';
  $field_group->group_name = 'group_classified_ad';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_ad_copy',
      1 => 'field_tags',
      2 => 'field_area',
      3 => 'field_rate',
      4 => 'field_duration',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<div class=\'classified-ad-general\'>
	<div class=\'classified-description-rates\'><strong>Classified Ad Rates</strong>
		<dl class=\'personal\'>
			<dt>Personal & Non-Profit</dt><dd> 15 word or less - $3.50 per week + tax (20¢ per additional word)</dd></dl>
		<dl class=\'business\'>
			<dt>Business</dt><dd> 15 word or less - $5.00 per week + tax (40¢ per additional word)</dd>
		</dl>
		<div class=\'spacer\'></div>
	</div>
	<div class=\'classified-description-directions\'><strong>Directions</strong>
		<ol>
			<li>Start by designating ad as Business or Personal</li>
			<li>Type your ad in the <b>Ad Copy</b> box.<small>Coping and pasting text of your ad from another document may affect the word count and price of your ad.</small></li>
			<li>Chose which <b>Area Edition(s)</b> you want your print ad to appear.</li>
			<li>Chose how many weeks your ad is to run.</li>
			<li>Select the right option to highlight your ad.</li>
			<li>Review your ad and submit when happy.</li>
		<ol>
	</div>
</div>
',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_classified_ad|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|ad_s|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_payment';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '324',
    'children' => array(
      0 => 'field_email',
      1 => 'field_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'For verification purposes only.<br><small> We will not send you any unsolicited emails or pass your phone number to any 3rd party.</small>',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|node|ad_s|form'] = $field_group;

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
  $field_group->identifier = 'group_details|node|classified|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_phone',
      1 => 'field_area_code',
      2 => 'field_image',
      3 => 'field_tags',
      4 => 'post_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'classified-detail-box',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details|node|classified|default'] = $field_group;

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
      0 => 'field_tags',
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
  $field_group->identifier = 'group_free_for_free|node|ad_s|form';
  $field_group->group_name = 'group_free_for_free';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic_info_box';
  $field_group->data = array(
    'label' => 'Special Notices',
    'weight' => '-14',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Special Notices',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'grid-15 special-notices-box omega',
        'description' => '&nbsp;',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_free_for_free|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more|node|ad_s|form';
  $field_group->group_name = 'group_more';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '4',
    'children' => array(
      0 => 'field_notes',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'more-grouping',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opt_image_block|node|ad_s|form';
  $field_group->group_name = 'group_opt_image_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_upgrade';
  $field_group->data = array(
    'label' => 'optional_image_block',
    'weight' => '100',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'optional_image_block',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-9 alpha',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_opt_image_block|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opt_liveload_block|node|ad_s|form';
  $field_group->group_name = 'group_opt_liveload_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_upgrade';
  $field_group->data = array(
    'label' => 'optional liveload block',
    'weight' => '120',
    'children' => array(
      0 => 'field_promote',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'optional liveload block',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-8',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_opt_liveload_block|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opt_notes_block|node|ad_s|form';
  $field_group->group_name = 'group_opt_notes_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_upgrade';
  $field_group->data = array(
    'label' => 'Optional notes block',
    'weight' => '140',
    'children' => array(
      0 => 'field_notes',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Optional notes block',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-5 omega',
        'description' => 'Need some help with your ad? Want your ad to run every other week? Let us know, we can help.',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_opt_notes_block|node|ad_s|form'] = $field_group;

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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_payment|node|ad_s|form';
  $field_group->group_name = 'group_payment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Payment Information',
    'weight' => '3',
    'children' => array(
      0 => 'group_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Payment Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_payment|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publishing_group|node|classified|form';
  $field_group->group_name = 'group_publishing_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publishing Group',
    'weight' => '7',
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
  $export['group_publishing_group|node|classified|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_review|node|ad_s|form';
  $field_group->group_name = 'group_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Review',
    'weight' => '2',
    'children' => array(
      0 => 'field_ad_details',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Review',
      'instance_settings' => array(
        'required_fields' => 0,
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
  $export['group_review|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_duration|node|ad_s|form';
  $field_group->group_name = 'group_section_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic_info_box';
  $field_group->data = array(
    'label' => 'Section & Duration',
    'weight' => '-16',
    'children' => array(
      0 => 'field_rate',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Section & Duration',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-8',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_group|node|ad_s|form';
  $field_group->group_name = 'group_section_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic_info_box';
  $field_group->data = array(
    'label' => 'Classified Section',
    'weight' => '-15',
    'children' => array(
      0 => 'field_tags',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Classified Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'grid-7 omega',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_section_group|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_upgrade|node|ad_s|form';
  $field_group->group_name = 'group_upgrade';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'OPTIONS',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
      1 => 'field_liveload',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'OPTIONS',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_upgrade|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_details|node|ad_s|form';
  $field_group->group_name = 'group_user_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ad_s';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_payment';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '310',
    'children' => array(
      0 => 'field_email',
      1 => 'field_phone',
      2 => 'field_address',
      3 => 'group_review',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Information',
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
  $export['group_user_details|node|ad_s|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'path|node|classified|form';
  $field_group->group_name = 'path';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'classified';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'URL path settings',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'instance_settings' => array(
        'classes' => 'path-form',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['path|node|classified|form'] = $field_group;

  return $export;
}
