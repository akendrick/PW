<?php
/**
 * @file
 * pw_cl.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_cl_field_default_fields() {
  $fields = array();

  // Exported field: 'node-ad_s-field_ad_copy'.
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'masonry' => 0,
            'masonry_animated' => 1,
            'masonry_animated_duration' => '500',
            'masonry_center' => 0,
            'masonry_gutter' => '0',
            'masonry_resizable' => 1,
            'masonry_rtl' => 0,
            'masonry_width' => '200',
          ),
          'type' => 'text_plain',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_copy',
      'label' => 'Ad Copy',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
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
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_ad_details'.
  $fields['node-ad_s-field_ad_details'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ad_details',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
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
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_details',
      'label' => 'Ad Details',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_area'.
  $fields['node-ad_s-field_area'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
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
      'locked' => '0',
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
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<strong class=\'ad-area-discount\'>Save $2 when you book all four areas.</strong>
<strong class=\'ad-area-areas\'>NOTE: Publication Areas</strong>
<ul><li><strong>Nelson & Salmo</strong><br>Serving Nelson, RR#2 (Tagham & Blewett), & Ymir
<li><strong>Kootenay Lake</strong><br>Serving Kaslo, Balfour, Ainsworth, Meadow Creek and Nelson\'s RR#1 & 3 (north of the bridge)
<li><strong>Trail, Beaver Valley & Rossland</strong><br>Serving Trail, Fruitvale, Montrose and Genelle
<li><strong>Castlegar & Slocan Valley</strong><br>Serving Castlegar, South Slocan, Slocan Park, Slocan, Crescent Valley and Winlaw
<li><strong>Internet - included FREE</strong><br>Your ad is also placed on our website the same day as the printed day.</p>
</ul> 
',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_area',
      'label' => 'Area Edtions',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_buttons',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_duration'.
  $fields['node-ad_s-field_duration'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_duration',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
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
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => '2',
        ),
      ),
      'deleted' => '0',
      'description' => '<strong>Book 2 weeks receive your 3rd week FREE!</strong>',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '6',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_duration',
      'label' => 'Weeks to run',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_email'.
  $fields['node-ad_s-field_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_email',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'email',
      'settings' => array(
        'user_role_field' => array(
          1 => 0,
          2 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
          8 => 0,
          9 => '9',
          10 => 0,
          11 => 0,
          12 => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => 17,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_email',
      'label' => 'Email',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '40',
        ),
        'type' => 'email_textfield',
        'weight' => '326',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_image'.
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
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'storage_class' => array(
          'class_id' => '1',
          'current_class_id' => '1',
        ),
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
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '<strong>Add an image!</strong> <small>Everyone likes to see what they are buying.</small>
<ul><li>Personal/Non-Profit $1.49/week</li><li>Business $2.99/week</li></ul>',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__medium__original',
          'weight' => '1',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Power Picture',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'custom_add_another' => '',
        'custom_remove' => '',
        'default_image' => 0,
        'epsacrop' => array(
          'styles' => array(
            'classified-list-style' => 0,
            'classified_list_js_crop' => 0,
            'display_ad_print_cropped_vert_thumbnail' => 0,
            'display_ad_smart_crop_med_square' => 0,
            'editoral_square_thumbnail' => 0,
            'editorial_block_list_header' => 0,
            'editorial_header' => 0,
            'editorial_small' => 0,
            'editorial_teaser' => 0,
            'editorial_tiny' => 0,
            'miniature_square' => 0,
          ),
        ),
        'file_directory' => 'online_ad_submission_images',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '4MB',
        'max_resolution' => '1200x1200',
        'min_resolution' => '60x60',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 0,
              'clipboard' => 0,
              'reference' => 0,
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'move',
              'path' => 'file_attach',
            ),
            'source_imce' => array(
              'imce_mode' => 0,
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'insert' => 0,
          'insert_absolute' => 0,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'icon_link' => 0,
            'image' => 0,
            'image_classified-list-style' => 0,
            'image_classified_list_js_crop' => 0,
            'image_classified_list_nocrop' => 0,
            'image_classified_page_style' => 0,
            'image_display_ad_full_page' => 0,
            'image_display_ad_print_cropped_vert_thumbnail' => 0,
            'image_display_ad_print_thumbnail' => 0,
            'image_display_ad_smart_crop_med_square' => 0,
            'image_editoral_square_thumbnail' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 0,
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_editorial_tiny' => 0,
            'image_epsacrop_thumb' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_miniature_square' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'label_help_description' => '',
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '318',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_liveload'.
  $fields['node-ad_s-field_liveload'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_liveload',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '<strong>$5 one time fee.</strong>
Your ad will go online within 1/2 hour of our receiving it. Monday - Friday 9am - 3pm PST.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 21,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_liveload',
      'label' => 'Liveload your ad',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_onoff',
        'weight' => '317',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_notes'.
  $fields['node-ad_s-field_notes'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_notes',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Need some help with your ad? Want your ad to run every other week? Let us know, we are here to help.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_notes',
      'label' => 'Special Requests',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'label_help_description' => '',
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '6',
        ),
        'type' => 'text_textarea',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_phone'.
  $fields['node-ad_s-field_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'cck_phone',
      'settings' => array(
        'size' => '15',
        'user_role_field' => array(
          1 => 0,
          2 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
          8 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'phone_number',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'global_phone_number',
          'weight' => 20,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_phone',
      'label' => 'Phone Number',
      'required' => 1,
      'settings' => array(
        'all_country_codes' => 0,
        'country_code_position' => 'before',
        'country_codes' => array(
          'country_selection' => array(
            'ad' => 0,
            'ae' => 0,
            'af' => 0,
            'ag' => 0,
            'ai' => 0,
            'al' => 0,
            'am' => 0,
            'an' => 0,
            'ao' => 0,
            'ar' => 0,
            'as' => 0,
            'at' => 0,
            'au' => 0,
            'aw' => 0,
            'az' => 0,
            'ba' => 0,
            'bb' => 0,
            'bd' => 0,
            'be' => 0,
            'bf' => 0,
            'bg' => 0,
            'bh' => 0,
            'bi' => 0,
            'bj' => 0,
            'bm' => 0,
            'bn' => 0,
            'bo' => 0,
            'br' => 0,
            'bs' => 0,
            'bt' => 0,
            'bw' => 0,
            'by' => 0,
            'bz' => 0,
            'ca' => 'ca',
            'cc' => 0,
            'cd' => 0,
            'cf' => 0,
            'cg' => 0,
            'ch' => 0,
            'ci' => 0,
            'ck' => 0,
            'cl' => 0,
            'cm' => 0,
            'cn' => 0,
            'co' => 0,
            'cr' => 0,
            'cu' => 0,
            'cv' => 0,
            'cx' => 0,
            'cy' => 0,
            'cz' => 0,
            'de' => 0,
            'dj' => 0,
            'dk' => 0,
            'dm' => 0,
            'do' => 0,
            'dz' => 0,
            'ec' => 0,
            'ee' => 0,
            'eg' => 0,
            'er' => 0,
            'es' => 0,
            'et' => 0,
            'fi' => 0,
            'fj' => 0,
            'fk' => 0,
            'fm' => 0,
            'fo' => 0,
            'fr' => 0,
            'ga' => 0,
            'gb' => 0,
            'gd' => 0,
            'ge' => 0,
            'gf' => 0,
            'gh' => 0,
            'gi' => 0,
            'gl' => 0,
            'gm' => 0,
            'gn' => 0,
            'gp' => 0,
            'gq' => 0,
            'gr' => 0,
            'gt' => 0,
            'gu' => 0,
            'gw' => 0,
            'gy' => 0,
            'hk' => 0,
            'hn' => 0,
            'hr' => 0,
            'ht' => 0,
            'hu' => 0,
            'id' => 0,
            'ie' => 0,
            'il' => 0,
            'in' => 0,
            'io' => 0,
            'iq' => 0,
            'ir' => 0,
            'is' => 0,
            'it' => 0,
            'jm' => 0,
            'jo' => 0,
            'jp' => 0,
            'ke' => 0,
            'kg' => 0,
            'kh' => 0,
            'ki' => 0,
            'km' => 0,
            'kn' => 0,
            'kp' => 0,
            'kr' => 0,
            'kw' => 0,
            'ky' => 0,
            'kz' => 0,
            'la' => 0,
            'lb' => 0,
            'lc' => 0,
            'li' => 0,
            'lk' => 0,
            'lr' => 0,
            'ls' => 0,
            'lt' => 0,
            'lu' => 0,
            'lv' => 0,
            'ly' => 0,
            'ma' => 0,
            'mc' => 0,
            'md' => 0,
            'me' => 0,
            'mg' => 0,
            'mh' => 0,
            'mk' => 0,
            'ml' => 0,
            'mm' => 0,
            'mn' => 0,
            'mo' => 0,
            'mp' => 0,
            'mq' => 0,
            'mr' => 0,
            'ms' => 0,
            'mt' => 0,
            'mu' => 0,
            'mv' => 0,
            'mw' => 0,
            'mx' => 0,
            'my' => 0,
            'mz' => 0,
            'na' => 0,
            'nc' => 0,
            'ne' => 0,
            'nf' => 0,
            'ng' => 0,
            'ni' => 0,
            'nl' => 0,
            'no' => 0,
            'np' => 0,
            'nr' => 0,
            'nu' => 0,
            'nz' => 0,
            'om' => 0,
            'pa' => 0,
            'pe' => 0,
            'pf' => 0,
            'pg' => 0,
            'ph' => 0,
            'pk' => 0,
            'pl' => 0,
            'pm' => 0,
            'pr' => 0,
            'ps' => 0,
            'pt' => 0,
            'pw' => 0,
            'py' => 0,
            'qa' => 0,
            'ro' => 0,
            'rs' => 0,
            'ru' => 0,
            'rw' => 0,
            'sa' => 0,
            'sb' => 0,
            'sc' => 0,
            'sd' => 0,
            'se' => 0,
            'sg' => 0,
            'sh' => 0,
            'si' => 0,
            'sk' => 0,
            'sl' => 0,
            'sm' => 0,
            'sn' => 0,
            'so' => 0,
            'sr' => 0,
            'ss' => 0,
            'st' => 0,
            'sv' => 0,
            'sy' => 0,
            'sz' => 0,
            'tc' => 0,
            'td' => 0,
            'tg' => 0,
            'th' => 0,
            'tj' => 0,
            'tk' => 0,
            'tm' => 0,
            'tn' => 0,
            'to' => 0,
            'tp' => 0,
            'tr' => 0,
            'tt' => 0,
            'tv' => 0,
            'tw' => 0,
            'tz' => 0,
            'ua' => 0,
            'ug' => 0,
            'us' => 0,
            'uy' => 0,
            'uz' => 0,
            'va' => 0,
            'vc' => 0,
            've' => 0,
            'vg' => 0,
            'vi' => 0,
            'vn' => 0,
            'vu' => 0,
            'wf' => 0,
            'ws' => 0,
            'ye' => 0,
            'yt' => 0,
            'za' => 0,
            'zm' => 0,
            'zw' => 0,
          ),
          'hide_single_cc' => 1,
        ),
        'custom_add_another' => '',
        'custom_remove' => '',
        'default_country' => 'ca',
        'enable_country_level_validation' => 0,
        'enable_default_country' => 1,
        'enable_extension' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'cck_phone',
        'settings' => array(
          'size' => 15,
        ),
        'type' => 'phone_number',
        'weight' => '325',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_rate'.
  $fields['node-ad_s-field_rate'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_rate',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Personal' => 'Personal & Non-Profit',
          'Business' => 'Business',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'ad_s',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => 'Personal',
        ),
      ),
      'deleted' => '0',
      'description' => '<b>Business Rated Categories include:</b><br>ALL RENTALS, Bulletin Board, Firewood, Contractor/Tradespeople, Services, Health Personal Care, Gardening/Landscaping, Business Opportunities, Employment Opportunities, Legal Notices, Commercial Real Estate, Commercial Rentals, Vacation Rentals, Shared Accommodations, House Sitting.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_rate',
      'label' => 'Rate',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_buttons',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-ad_s-field_tags'.
  $fields['node-ad_s-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
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
      'custom_add_another' => '',
      'custom_remove' => '',
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
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Classification',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-adworks_file-body'.
  $fields['node-adworks_file-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'adworks_file',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<big><strong>Test your file first!</strong></big>
<ol>
<li>To minimize any problems paste Adworks copy into <em>TextWrangler</em>:
  <ul>
  <li><strong>Straighten Quotes</strong></li>
  <li><strong>Find/Replace All <big>`</big> with <big>\'</big></strong> (back ticks with single quotes).</li>
</ul></li>
<li>Run Preflight on classifieds by selecting:
<ul>
<li> Check All Images</li>
<li> Do NOT Create Ads</li>
<li> Select --> <strong>PREVIEW</strong>
</ul>
<li>Move missing images to <strong>files/classified_ad_image_upload</strong></li>
<li>Run preflight again</li>
<li>If all images are present - change to <strong>Create Ads</strong> and select <strong>SAVE</strong></li>
</ol>

',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'masonry' => 0,
            'masonry_animated' => 1,
            'masonry_animated_duration' => '500',
            'masonry_center' => 0,
            'masonry_gutter' => '0',
            'masonry_resizable' => 1,
            'masonry_rtl' => 0,
            'masonry_width' => '200',
            'trim_length' => '600',
          ),
          'type' => 'text_trimmed',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'display_summary' => 0,
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '10',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-adworks_file-field_ad_creation_override'.
  $fields['node-adworks_file-field_ad_creation_override'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ad_creation_override',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Do Not Create Ads',
          1 => 'Create Ads',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'adworks_file',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => 'Use the override to \'go through the motions\' of checking the ads but do not save the ads.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_creation_override',
      'label' => 'Ad Creation Override',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-adworks_file-field_image_override'.
  $fields['node-adworks_file-field_image_override'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_image_override',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Administrative Override (Do Not Check Images)',
          1 => 'Check All Images',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'adworks_file',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => '1',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image_override',
      'label' => 'Image Override',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-adworks_file-field_image_uploader'.
  $fields['node-adworks_file-field_image_uploader'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_image_uploader',
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
      'locked' => '0',
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'adworks_file',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 10,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image_uploader',
      'label' => 'Image Uploader',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'description_field' => 0,
        'file_directory' => 'classified_ad_image_upload',
        'file_extensions' => 'jpg gif',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'multiupload_filefield_widget',
        'settings' => array(
          'insert' => 0,
          'insert_absolute' => FALSE,
          'insert_class' => '',
          'insert_default' => array(
            0 => 'auto',
          ),
          'insert_styles' => array(
            0 => 'auto',
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_mfw',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-adworks_file-field_publish'.
  $fields['node-adworks_file-field_publish'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_publish',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => 'optional',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'adworks_file',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '2',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_publish',
      'label' => 'Publish Date',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'default_value' => 'strtotime',
        'default_value2' => 'strtotime',
        'default_value_code' => '+1 Tuesday 05:30',
        'default_value_code2' => '+2 Tuesday 05:00',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '30',
          'input_format' => 'Y-m-d H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-0:+1',
        ),
        'type' => 'date_popup',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-classified-field_ad_copy'.
  $fields['node-classified-field_ad_copy'] = array(
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
<<<<<<< HEAD
          'weight' => '5',
=======
          'weight' => '4',
>>>>>>> SiteReformation
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'masonry' => 0,
            'masonry_animated' => 1,
            'masonry_animated_duration' => '500',
            'masonry_center' => 0,
            'masonry_gutter' => '0',
            'masonry_resizable' => 1,
            'masonry_rtl' => 0,
            'masonry_width' => '200',
            'trim_length' => '80',
          ),
          'type' => 'text_trimmed',
          'weight' => '2',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '80',
          ),
          'type' => 'text_trimmed',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_copy',
      'label' => 'Ad Copy',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '15',
        ),
        'type' => 'text_textarea',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-classified-field_ad_type'.
  $fields['node-classified-field_ad_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ad_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Regular',
          1 => 'Liveload',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '5',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_type',
      'label' => 'Classified Ad Type',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-classified-field_addressfield'.
  $fields['node-classified-field_addressfield'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_addressfield',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'addressfield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'element_key' => 'node|classified|field_addressfield|und|0',
          'thoroughfare' => '',
          'premise' => '',
          'locality' => '',
          'administrative_area' => 'BC',
          'postal_code' => '',
          'country' => 'CA',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'rss' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_addressfield',
      'label' => 'Address',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(
            'CA' => 'CA',
          ),
          'format_handlers' => array(
            'address' => 'address',
            'address-hide-country' => 'address-hide-country',
            'organisation' => 0,
            'name-full' => 0,
            'name-oneline' => 0,
          ),
        ),
        'type' => 'addressfield_standard',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-classified-field_area_code'.
  $fields['node-classified-field_area_code'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_area_code',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '8',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_area_code',
      'label' => 'Area Code',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '10',
        ),
        'type' => 'text_textfield',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-classified-field_email'.
  $fields['node-classified-field_email'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_email',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'email',
      'settings' => array(
        'user_role_field' => array(
          1 => 0,
          2 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
          8 => 0,
          9 => '9',
          10 => 0,
          11 => 0,
          12 => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
<<<<<<< HEAD
          'weight' => '3',
=======
          'weight' => '2',
>>>>>>> SiteReformation
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_email',
      'label' => 'Email',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-classified-field_geofield'.
  $fields['node-classified-field_geofield'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_geofield',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'bbox' => array(
          0 => 'top',
          1 => 'bottom',
          2 => 'left',
          3 => 'right',
        ),
        'bottom' => array(
          0 => 'bottom',
        ),
        'centroid' => array(
          0 => 'lat',
          1 => 'lon',
        ),
        'geohash' => array(
          0 => 'geohash',
        ),
        'lat' => array(
          0 => 'lat',
        ),
        'left' => array(
          0 => 'left',
        ),
        'lon' => array(
          0 => 'lon',
        ),
        'right' => array(
          0 => 'right',
        ),
        'top' => array(
          0 => 'top',
        ),
      ),
      'locked' => '0',
      'module' => 'geofield',
      'settings' => array(
        'backend' => 'default',
        'srid' => '4326',
      ),
      'translatable' => '0',
      'type' => 'geofield',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'geofield_map',
          'settings' => array(
            'geofield_map_baselayers_hybrid' => 1,
            'geofield_map_baselayers_map' => 1,
            'geofield_map_baselayers_physical' => 0,
            'geofield_map_baselayers_satellite' => 1,
            'geofield_map_controltype' => 'small',
            'geofield_map_draggable' => 0,
            'geofield_map_height' => '300px',
            'geofield_map_maptype' => 'map',
            'geofield_map_mtc' => 'standard',
            'geofield_map_overview' => 0,
            'geofield_map_overview_opened' => 0,
            'geofield_map_pancontrol' => 1,
            'geofield_map_scale' => 0,
            'geofield_map_scrollwheel' => 0,
            'geofield_map_streetview_show' => 0,
            'geofield_map_width' => '100%',
            'geofield_map_zoom' => '12',
          ),
          'type' => 'geofield_map_map',
<<<<<<< HEAD
          'weight' => '0',
=======
          'weight' => '1',
>>>>>>> SiteReformation
        ),
        'rss' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_geofield',
      'label' => 'Geofield',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'geocoder',
        'settings' => array(
          'delta_handling' => 'default',
          'geocoder_field' => 'field_addressfield',
          'geocoder_handler' => 'google',
          'handler_settings' => array(
            'google' => array(
              'all_results' => 0,
              'geometry_type' => 'point',
              'reject_results' => array(
                'APPROXIMATE' => 'APPROXIMATE',
                'GEOMETRIC_CENTER' => 0,
                'RANGE_INTERPOLATED' => 0,
                'ROOFTOP' => 0,
              ),
            ),
          ),
        ),
        'type' => 'geocoder',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-classified-field_image'.
  $fields['node-classified-field_image'] = array(
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
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'storage_class' => array(
          'class_id' => '1',
          'current_class_id' => '1',
        ),
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
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__classified_page_style__original',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
            'masonry' => 0,
            'masonry_animated' => 1,
            'masonry_animated_duration' => '500',
            'masonry_center' => 0,
            'masonry_gutter' => '0',
            'masonry_resizable' => 1,
            'masonry_rtl' => 0,
            'masonry_width' => '200',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'square_thumbnail',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__classified-list-style__original',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'custom_add_another' => '',
        'custom_remove' => '',
        'default_image' => 0,
        'file_directory' => 'classified_ad_images',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '512 KB',
        'max_resolution' => '1200x1200',
        'min_resolution' => '40x40',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'imagefield_crop',
        'settings' => array(
          'collapsible' => '3',
          'croparea' => '500x500',
          'enforce_minimum' => 0,
          'enforce_ratio' => 1,
          'preview_image_style' => 'classified_list_nocrop',
          'progress_indicator' => 'throbber',
          'resolution' => '240x130',
        ),
        'type' => 'imagefield_crop_widget',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-classified-field_link'.
  $fields['node-classified-field_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_link',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
<<<<<<< HEAD
          'weight' => '4',
=======
          'weight' => '3',
>>>>>>> SiteReformation
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_link',
      'label' => 'Link',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => 'nofollow',
          'target' => 'default',
          'title' => '',
        ),
        'custom_add_another' => '',
        'custom_remove' => '',
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'none',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-classified-field_phone'.
  $fields['node-classified-field_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'cck_phone',
      'settings' => array(
        'size' => '15',
        'user_role_field' => array(
          1 => 0,
          2 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
          8 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
        ),
      ),
      'translatable' => '0',
      'type' => 'phone_number',
    ),
    'field_instance' => array(
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'global_phone_number',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'search_result' => array(
          'label' => 'inline',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'global_phone_number',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'cck_phone',
          'settings' => array(),
          'type' => 'local_phone_number',
          'weight' => '2',
        ),
      ),
      'ds_extras_field_template' => 'theme_ds_field_minimal',
      'entity_type' => 'node',
      'field_name' => 'field_phone',
      'label' => 'Phone',
      'required' => 0,
      'settings' => array(
        'all_country_codes' => 1,
        'country_code_position' => 'after',
        'country_codes' => array(
          'country_selection' => array(
            'ad' => 0,
            'ae' => 0,
            'af' => 0,
            'ag' => 0,
            'ai' => 0,
            'al' => 0,
            'am' => 0,
            'an' => 0,
            'ao' => 0,
            'ar' => 0,
            'as' => 0,
            'at' => 0,
            'au' => 0,
            'aw' => 0,
            'az' => 0,
            'ba' => 0,
            'bb' => 0,
            'bd' => 0,
            'be' => 0,
            'bf' => 0,
            'bg' => 0,
            'bh' => 0,
            'bi' => 0,
            'bj' => 0,
            'bm' => 0,
            'bn' => 0,
            'bo' => 0,
            'br' => 0,
            'bs' => 0,
            'bt' => 0,
            'bw' => 0,
            'by' => 0,
            'bz' => 0,
            'ca' => 'ca',
            'cc' => 0,
            'cd' => 0,
            'cf' => 0,
            'cg' => 0,
            'ch' => 0,
            'ci' => 0,
            'ck' => 0,
            'cl' => 0,
            'cm' => 0,
            'cn' => 0,
            'co' => 0,
            'cr' => 0,
            'cu' => 0,
            'cv' => 0,
            'cx' => 0,
            'cy' => 0,
            'cz' => 0,
            'de' => 0,
            'dj' => 0,
            'dk' => 0,
            'dm' => 0,
            'do' => 0,
            'dz' => 0,
            'ec' => 0,
            'ee' => 0,
            'eg' => 0,
            'er' => 0,
            'es' => 0,
            'et' => 0,
            'fi' => 0,
            'fj' => 0,
            'fk' => 0,
            'fm' => 0,
            'fo' => 0,
            'fr' => 0,
            'ga' => 0,
            'gb' => 0,
            'gd' => 0,
            'ge' => 0,
            'gf' => 0,
            'gh' => 0,
            'gi' => 0,
            'gl' => 0,
            'gm' => 0,
            'gn' => 0,
            'gp' => 0,
            'gq' => 0,
            'gr' => 0,
            'gt' => 0,
            'gu' => 0,
            'gw' => 0,
            'gy' => 0,
            'hk' => 0,
            'hn' => 0,
            'hr' => 0,
            'ht' => 0,
            'hu' => 0,
            'id' => 0,
            'ie' => 0,
            'il' => 0,
            'in' => 0,
            'io' => 0,
            'iq' => 0,
            'ir' => 0,
            'is' => 0,
            'it' => 0,
            'jm' => 0,
            'jo' => 0,
            'jp' => 0,
            'ke' => 0,
            'kg' => 0,
            'kh' => 0,
            'ki' => 0,
            'km' => 0,
            'kn' => 0,
            'kp' => 0,
            'kr' => 0,
            'kw' => 0,
            'ky' => 0,
            'kz' => 0,
            'la' => 0,
            'lb' => 0,
            'lc' => 0,
            'li' => 0,
            'lk' => 0,
            'lr' => 0,
            'ls' => 0,
            'lt' => 0,
            'lu' => 0,
            'lv' => 0,
            'ly' => 0,
            'ma' => 0,
            'mc' => 0,
            'md' => 0,
            'me' => 0,
            'mg' => 0,
            'mh' => 0,
            'mk' => 0,
            'ml' => 0,
            'mm' => 0,
            'mn' => 0,
            'mo' => 0,
            'mp' => 0,
            'mq' => 0,
            'mr' => 0,
            'ms' => 0,
            'mt' => 0,
            'mu' => 0,
            'mv' => 0,
            'mw' => 0,
            'mx' => 0,
            'my' => 0,
            'mz' => 0,
            'na' => 0,
            'nc' => 0,
            'ne' => 0,
            'nf' => 0,
            'ng' => 0,
            'ni' => 0,
            'nl' => 0,
            'no' => 0,
            'np' => 0,
            'nr' => 0,
            'nu' => 0,
            'nz' => 0,
            'om' => 0,
            'pa' => 0,
            'pe' => 0,
            'pf' => 0,
            'pg' => 0,
            'ph' => 0,
            'pk' => 0,
            'pl' => 0,
            'pm' => 0,
            'pr' => 0,
            'ps' => 0,
            'pt' => 0,
            'pw' => 0,
            'py' => 0,
            'qa' => 0,
            'ro' => 0,
            'rs' => 0,
            'ru' => 0,
            'rw' => 0,
            'sa' => 0,
            'sb' => 0,
            'sc' => 0,
            'sd' => 0,
            'se' => 0,
            'sg' => 0,
            'sh' => 0,
            'si' => 0,
            'sk' => 0,
            'sl' => 0,
            'sm' => 0,
            'sn' => 0,
            'so' => 0,
            'sr' => 0,
            'ss' => 0,
            'st' => 0,
            'sv' => 0,
            'sy' => 0,
            'sz' => 0,
            'tc' => 0,
            'td' => 0,
            'tg' => 0,
            'th' => 0,
            'tj' => 0,
            'tk' => 0,
            'tm' => 0,
            'tn' => 0,
            'to' => 0,
            'tp' => 0,
            'tr' => 0,
            'tt' => 0,
            'tv' => 0,
            'tw' => 0,
            'tz' => 0,
            'ua' => 0,
            'ug' => 0,
            'us' => 0,
            'uy' => 0,
            'uz' => 0,
            'va' => 0,
            'vc' => 0,
            've' => 0,
            'vg' => 0,
            'vi' => 0,
            'vn' => 0,
            'vu' => 0,
            'wf' => 0,
            'ws' => 0,
            'ye' => 0,
            'yt' => 0,
            'za' => 0,
            'zm' => 0,
            'zw' => 0,
          ),
          'hide_single_cc' => 1,
        ),
        'custom_add_another' => '',
        'custom_remove' => '',
        'default_country' => 'ca',
        'enable_country_level_validation' => 0,
        'enable_default_country' => TRUE,
        'enable_extension' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'cck_phone',
        'settings' => array(
          'size' => 15,
        ),
        'type' => 'phone_number',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-classified-field_tags'.
  $fields['node-classified-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
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
      'bundle' => 'classified',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
<<<<<<< HEAD
          'weight' => '1',
=======
          'weight' => '0',
>>>>>>> SiteReformation
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '1',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Return to',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-free-field_body_text'.
  $fields['node-free-field_body_text'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_body_text',
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
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'free',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Please use 15 - 25 words (about 120 characters) to describe your one personal item per Free for Free ad.
<ul><li>Bunkbeds FREE to good home
<li>FREE pink floral couch
<li>FREE 2 wheel bike will fit 8 year old 
</ul>
Please don\'t post services in FREE for FREE such as free estimates, no free rides to polling station, or buy 3 get 1 free. ',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_body_text',
      'label' => 'Ad Copy',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-free-field_contact_seller'.
  $fields['node-free-field_contact_seller'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contact_seller',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'email' => 'Allow contact & questions.',
          'none' => 'None. All relevant information is in ad.',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'free',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => 'email',
        ),
      ),
      'deleted' => '0',
      'description' => 'Allowing questions and comments will help Pennywise readers contact you about your free ad. They will be allowed to post questions and comments on your ad, and you will be able to respond to them. Comments and questions will also be sent to your email so you can be alerted the moment someone posts a question.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'full' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_contact_seller',
      'label' => 'Allow Questions & Comments',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_buttons',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-free-field_image'.
  $fields['node-free-field_image'] = array(
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
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'storage_class' => array(
          'class_id' => '1',
          'current_class_id' => '1',
        ),
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
      'bundle' => 'free',
      'custom_add_another' => '',
      'custom_remove' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'classified-list-style',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'classified-list-style',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'custom_add_another' => '',
        'custom_remove' => '',
        'default_image' => 0,
        'file_directory' => 'free',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '2MB',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'imagefield_crop',
        'settings' => array(
          'collapsible' => '2',
          'croparea' => '500x500',
          'enforce_minimum' => 1,
          'enforce_ratio' => 1,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
          'resolution' => '200x150',
        ),
        'type' => 'imagefield_crop_widget',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-free-field_price_free'.
  $fields['node-free-field_price_free'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_price_free',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Free' => 'Free',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'free',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'value' => 'Free',
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
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '0',
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_price_free',
      'label' => 'Price',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_buttons',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-free-field_tags'.
  $fields['node-free-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'field_permissions' => array(
        'type' => '0',
      ),
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
      'locked' => '0',
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
      'bundle' => 'free',
      'custom_add_another' => '',
      'custom_remove' => '',
      'default_value' => array(
        0 => array(
          'tid' => '131',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 11,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'notifications' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Section',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'custom_remove' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<b>Business Rated Categories include:</b><br>ALL RENTALS, Bulletin Board, Firewood, Contractor/Tradespeople, Services, Health Personal Care, Gardening/Landscaping, Business Opportunities, Employment Opportunities, Legal Notices, Commercial Real Estate, Commercial Rentals, Vacation Rentals, Shared Accommodations, House Sitting.');
  t('<big><strong>Test your file first!</strong></big>
<ol>
<li>To minimize any problems paste Adworks copy into <em>TextWrangler</em>:
  <ul>
  <li><strong>Straighten Quotes</strong></li>
  <li><strong>Find/Replace All <big>`</big> with <big>\'</big></strong> (back ticks with single quotes).</li>
</ul></li>
<li>Run Preflight on classifieds by selecting:
<ul>
<li> Check All Images</li>
<li> Do NOT Create Ads</li>
<li> Select --> <strong>PREVIEW</strong>
</ul>
<li>Move missing images to <strong>files/classified_ad_image_upload</strong></li>
<li>Run preflight again</li>
<li>If all images are present - change to <strong>Create Ads</strong> and select <strong>SAVE</strong></li>
</ol>

');
  t('<strong class=\'ad-area-discount\'>Save $2 when you book all four areas.</strong>
<strong class=\'ad-area-areas\'>NOTE: Publication Areas</strong>
<ul><li><strong>Nelson & Salmo</strong><br>Serving Nelson, RR#2 (Tagham & Blewett), & Ymir
<li><strong>Kootenay Lake</strong><br>Serving Kaslo, Balfour, Ainsworth, Meadow Creek and Nelson\'s RR#1 & 3 (north of the bridge)
<li><strong>Trail, Beaver Valley & Rossland</strong><br>Serving Trail, Fruitvale, Montrose and Genelle
<li><strong>Castlegar & Slocan Valley</strong><br>Serving Castlegar, South Slocan, Slocan Park, Slocan, Crescent Valley and Winlaw
<li><strong>Internet - included FREE</strong><br>Your ad is also placed on our website the same day as the printed day.</p>
</ul> 
');
  t('<strong>$5 one time fee.</strong>
Your ad will go online within 1/2 hour of our receiving it. Monday - Friday 9am - 3pm PST.');
  t('<strong>Add an image!</strong> <small>Everyone likes to see what they are buying.</small>
<ul><li>Personal/Non-Profit $1.49/week</li><li>Business $2.99/week</li></ul>');
  t('<strong>Book 2 weeks receive your 3rd week FREE!</strong>');
  t('Ad Copy');
  t('Ad Creation Override');
  t('Ad Details');
  t('Address');
  t('Allow Questions & Comments');
  t('Allowing questions and comments will help Pennywise readers contact you about your free ad. They will be allowed to post questions and comments on your ad, and you will be able to respond to them. Comments and questions will also be sent to your email so you can be alerted the moment someone posts a question.');
  t('Area Code');
  t('Area Edtions');
  t('Body');
  t('Classification');
  t('Classified Ad Type');
  t('Email');
  t('Geofield');
  t('Image');
  t('Image Override');
  t('Image Uploader');
  t('Link');
  t('Liveload your ad');
  t('Need some help with your ad? Want your ad to run every other week? Let us know, we are here to help.');
  t('Phone');
  t('Phone Number');
  t('Please use 15 - 25 words (about 120 characters) to describe your one personal item per Free for Free ad.
<ul><li>Bunkbeds FREE to good home
<li>FREE pink floral couch
<li>FREE 2 wheel bike will fit 8 year old 
</ul>
Please don\'t post services in FREE for FREE such as free estimates, no free rides to polling station, or buy 3 get 1 free. ');
  t('Power Picture');
  t('Price');
  t('Publish Date');
  t('Rate');
  t('Return to');
  t('Section');
  t('Special Requests');
  t('Use the override to \'go through the motions\' of checking the ads but do not save the ads.');
  t('Weeks to run');

  return $fields;
}
