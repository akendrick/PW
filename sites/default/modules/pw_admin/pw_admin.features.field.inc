<?php
/**
 * @file
 * pw_admin.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_admin_field_default_fields() {
  $fields = array();

  // Exported field: 'node-ad_s-field_ad_copy'
  $fields['node-ad_s-field_ad_copy'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ad_copy',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_copy',
      'label' => 'Ad Copy',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_ad_details'
  $fields['node-ad_s-field_ad_details'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ad_details',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_details',
      'label' => 'Ad Details',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_agree'
  $fields['node-ad_s-field_agree'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_agree',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Confirm' => 'Confirm',
          'Not Yet' => 'Not Ready Yet.',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => array(
        0 => array(
          'value' => 'Not Yet',
        ),
      ),
      'deleted' => '0',
      'description' => 'Confirm your ad submission.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_agree',
      'label' => 'Confirmation',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_area'
  $fields['node-ad_s-field_area'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '4',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_area',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Trail' => 'Trail, Beaver Valley & Rossland',
          'Nelson' => 'Nelson & Salmo',
          'Castlegar' => 'Castlegar & Slocan Valley',
          'Kootenay Lake' => 'Kootenay Lake',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<strong class=\'ad-note\'>NOTE: Publication Areas</strong>
<ul><li><strong>Nelson & Salmo</strong><br>Serving Nelson, RR#2 (Tagham & Blewett), & Ymir
<li><strong>Kootenay Lake</strong><br>Serving Kaslo, Balfour, Ainsworth, Meadow Creek and Nelson\'s RR#1 & 3 (north of the bridge)
<li><strong>Trail, Beaver Valley & Rossland</strong><br>Serving Trail, Fruitvale, Montrose and Genelle
<li><strong>Castlegar & Slocan Valley</strong><br>Serving Castlegar, South Slocan, Slocan Park, Slocan, Crescent Valley and Winlaw
<li><strong>Internet - included FREE</strong><br>Your ad is also placed on our website the same day as the printed day.</p>
</ul>
<em class=\'ad-note\'>Save $2 when you book all four areas.</em>',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '5',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_area',
      'label' => 'Area',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_duration'
  $fields['node-ad_s-field_duration'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_duration',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          1 => '1',
          2 => '2',
          6 => '6',
          9 => '9',
          12 => '12',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => array(
        0 => array(
          'value' => '2',
        ),
      ),
      'deleted' => '0',
      'description' => 'Number of weeks you wish to run your ad.<br/>
<strong>Book 2 weeks receive your 3rd week FREE!</strong>',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_duration',
      'label' => 'Duration',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_image'
  $fields['node-ad_s-field_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_image',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
        'user_role_field' => array(
          1 => 0,
          2 => 0,
          3 => '3',
          4 => 0,
          5 => '5',
          6 => '6',
          7 => '7',
          8 => 0,
          9 => '9',
          10 => '10',
        ),
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'deleted' => '0',
      'description' => 'Adding an image will improve your chances of getting seen. Everyone likes to see an item before buying, why not show them right now.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__medium__original',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'file_directory' => 'online_ad_submission_images',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '500k',
        'max_resolution' => '900x900',
        'min_resolution' => '60x60',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(),
            'source_attach' => array(
              'absolute' => 0,
              'attach_mode' => 'move',
              'path' => 'file_attach',
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'insert' => 0,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_notes'
  $fields['node-ad_s-field_notes'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_notes',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_notes',
      'label' => 'Notes',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '3',
        ),
        'type' => 'text_textarea',
        'weight' => '20',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_price'
  $fields['node-ad_s-field_price'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_price',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
        'precision' => '10',
        'scale' => '2',
      ),
      'translatable' => '0',
      'type' => 'number_decimal',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_price',
      'label' => 'Price',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_promote'
  $fields['node-ad_s-field_promote'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_promote',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Regular',
          1 => 'Liveload',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => '<em>In a rush? Can\'t wait until Tuesday?</em><br/>
<strong>For an additional $5 (not incl. taxes)</strong> we can guarantee your ad will go online within 1/2 hour of our receiving it.
Available from Monday through Thursday, 9 am - 4:30 pm PST (Friday 9am until 3pm).',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_promote',
      'label' => 'Liveload Your Ad',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_rate'
  $fields['node-ad_s-field_rate'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_rate',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Personal' => 'Personal',
          'Business' => 'Business',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => array(
        0 => array(
          'value' => 'Personal',
        ),
      ),
      'deleted' => '0',
      'description' => '<strong>NOTE: Business Rated Categories include: ALL RENTALS</strong>, Bulletin Board, Firewood, Contractor/Tradespeople, Services, Health Personal Care, Gardening/Landscaping, Business Opportunities, Employment Opportunities, Legal Notices, Commercial Real Estate, Commercial Rentals, Vacation Rentals, Shared Accommodations, House Sitting',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_rate',
      'label' => 'Rate',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_tags'
  $fields['node-ad_s-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'classification',
            'parent' => 0,
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Section',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-classification-field_business_rated'
  $fields['taxonomy_term-classification-field_business_rated'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_business_rated',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => 'Business Rated Only',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'classification',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_business_rated',
      'label' => 'Business Rated',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
        ),
        'type' => 'options_onoff',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-classification-field_classified_id'
  $fields['taxonomy_term-classification-field_classified_id'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_classified_id',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'max_length' => '6',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'classification',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_classified_id',
      'label' => 'Classification ID',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '8',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<em>In a rush? Can\'t wait until Tuesday?</em><br/>
<strong>For an additional $5 (not incl. taxes)</strong> we can guarantee your ad will go online within 1/2 hour of our receiving it.
Available from Monday through Thursday, 9 am - 4:30 pm PST (Friday 9am until 3pm).');
  t('<strong class=\'ad-note\'>NOTE: Publication Areas</strong>
<ul><li><strong>Nelson & Salmo</strong><br>Serving Nelson, RR#2 (Tagham & Blewett), & Ymir
<li><strong>Kootenay Lake</strong><br>Serving Kaslo, Balfour, Ainsworth, Meadow Creek and Nelson\'s RR#1 & 3 (north of the bridge)
<li><strong>Trail, Beaver Valley & Rossland</strong><br>Serving Trail, Fruitvale, Montrose and Genelle
<li><strong>Castlegar & Slocan Valley</strong><br>Serving Castlegar, South Slocan, Slocan Park, Slocan, Crescent Valley and Winlaw
<li><strong>Internet - included FREE</strong><br>Your ad is also placed on our website the same day as the printed day.</p>
</ul>
<em class=\'ad-note\'>Save $2 when you book all four areas.</em>');
  t('<strong>NOTE: Business Rated Categories include: ALL RENTALS</strong>, Bulletin Board, Firewood, Contractor/Tradespeople, Services, Health Personal Care, Gardening/Landscaping, Business Opportunities, Employment Opportunities, Legal Notices, Commercial Real Estate, Commercial Rentals, Vacation Rentals, Shared Accommodations, House Sitting');
  t('Ad Copy');
  t('Ad Details');
  t('Adding an image will improve your chances of getting seen. Everyone likes to see an item before buying, why not show them right now.');
  t('Area');
  t('Business Rated');
  t('Classification ID');
  t('Confirm your ad submission.');
  t('Confirmation');
  t('Duration');
  t('Image');
  t('Liveload Your Ad');
  t('Notes');
  t('Number of weeks you wish to run your ad.<br/>
<strong>Book 2 weeks receive your 3rd week FREE!</strong>');
  t('Price');
  t('Rate');
  t('Section');

  return $fields;
}