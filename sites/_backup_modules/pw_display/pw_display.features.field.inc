<?php
/**
 * @file
 * pw_display.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_display_field_default_fields() {
  $fields = array();

  // Exported field: 'node-display_ads-field_ad_client'.
  $fields['node-display_ads-field_ad_client'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ad_client',
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
            'vocabulary' => 'client',
            'parent' => '0',
          ),
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The following are considered clients
<ul>
<li>Pennywise
<li>Obituaries
<li>Birth Announcements
<li>Wedding Announcements
</ul>',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_plain',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '2',
        ),
        'token' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_client',
      'label' => 'Client',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_ad_copy'.
  $fields['node-display_ads-field_ad_copy'] = array(
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
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ad_copy',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
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
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_display_ad'.
  $fields['node-display_ads-field_display_ad'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_display_ad',
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
        'default_image' => '993',
        'storage_class' => array(
          'class_id' => '1',
          'current_class_id' => '1',
        ),
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'deleted' => '0',
      'description' => 'Upload (or select) display ad.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__thumbnail__large',
          'weight' => '0',
        ),
        'token' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__large__original',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_display_ad',
      'label' => 'Display Ad',
      'required' => 1,
      'settings' => array(
        'alt_field' => 1,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => 'images/display',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '5MB',
        'max_resolution' => '2000x2000',
        'min_resolution' => '25x25',
        'title_field' => 1,
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
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'display-ads',
            ),
            'source_imce' => array(
              'imce_mode' => 0,
            ),
            'source_reference' => array(
              'autocomplete' => '1',
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
            'image_display_ad_print_thumbnail' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 0,
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_editorial_tiny' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_miniature_square' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'medium',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_display_ad_type'.
  $fields['node-display_ads-field_display_ad_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_display_ad_type',
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
          'banner' => 'Banner Ad',
          'poster' => 'Poster Ad',
          'print' => 'Print Ad',
          'splash' => 'Splash Ad',
          'target' => 'Target Ad',
          'video' => 'Video Ad',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Select the ad type. This will affect the ads placement and thumbnail size. <br>
<strong>ALL ADS ARE FORCED RESIZED TO THE AD TYPE.</strong>.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'token' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_display_ad_type',
      'label' => 'Display Ad Type',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
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

  // Exported field: 'node-display_ads-field_email'.
  $fields['node-display_ads-field_email'] = array(
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
        ),
      ),
      'translatable' => '0',
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Optional email contact for business.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_email',
      'label' => 'Email',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'email_textfield',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_entity_reference'.
  $fields['node-display_ads-field_entity_reference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_entity_reference',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'property' => 'title',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'attachment' => 'attachment',
          ),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'node',
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
        ),
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Link this display ad to a PDF attachment, another display ad or even a classified ad. Link to a specific PW web page, or even an online web submission form. You can also create the attachment right here.
<strong>Display ads can only be linked. Do not create another display ad here!</strong>',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'token' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_entity_reference',
      'label' => 'File Attach',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => 'Attach another',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'inline_entity_form',
        'settings' => array(
          'fields' => array(),
          'type_settings' => array(
            'allow_existing' => 1,
            'delete_references' => 0,
            'match_operator' => 'CONTAINS',
          ),
        ),
        'type' => 'inline_entity_form',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_high_res_ad'.
  $fields['node-display_ads-field_high_res_ad'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_high_res_ad',
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
        'display_default' => 1,
        'display_field' => 1,
        'storage_class' => array(
          'class_id' => '1',
          'current_class_id' => '1',
        ),
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'deleted' => '0',
      'description' => 'Upload related document.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '6',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_high_res_ad',
      'label' => 'Related File',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'description_field' => 1,
        'file_directory' => 'images/attachment',
        'file_extensions' => 'pdf gif tif jpg',
        'max_filesize' => '4MB',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 0,
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'display-ad/attachment',
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'insert' => 0,
          'insert_absolute' => FALSE,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_classified_ad_image_small' => 0,
            'image_display_ad_banner' => 0,
            'image_display_ad_poster' => 0,
            'image_display_ad_print_full' => 0,
            'image_display_ad_print_thumbnail' => 0,
            'image_display_ad_splash' => 0,
            'image_display_ad_target' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 0,
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_link'.
  $fields['node-display_ads-field_link'] = array(
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
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Title tag allows you to shorten very long and complex web links with a concise title.<br>
Eg. You can replace:<br>
<em>http://www.example.com/book_1/chapt-3/page_30</em><br>
with <strong>Page 30</strong>.<br>
<p><strong>NOTE: YOU must include HTTP://</strong><br>if the URL is not located at http://PennywiseAds.com
',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_link',
      'label' => 'Link',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'custom_add_another' => '',
        'display' => array(
          'url_cutoff' => '0',
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
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
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_publish_date'.
  $fields['node-display_ads-field_publish_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_publish_date',
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
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'token' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_publish_date',
      'label' => 'Publishing Date',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_section_all_select'.
  $fields['node-display_ads-field_section_all_select'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_section_all_select',
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
          0 => 'Select Area',
          1 => 'All Areas',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'token' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_section_all_select',
      'label' => 'Section Selector',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_special_feature_link'.
  $fields['node-display_ads-field_special_feature_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '5',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_special_feature_link',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 1,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'attachment' => 'attachment',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'display_ads',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Link file here by typing the title of the uploaded file name. To upload a file click <a href=\'/node/add/attachment\' target=\'_NEW\'>here.</a>',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'token' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_special_feature_link',
      'label' => 'Attach File',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'inline_entity_form',
        'settings' => array(
          'fields' => array(),
          'type_settings' => array(
            'allow_existing' => 1,
            'delete_references' => 1,
            'match_operator' => 'CONTAINS',
          ),
        ),
        'type' => 'inline_entity_form',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-display_ads-field_tags'.
  $fields['node-display_ads-field_tags'] = array(
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
      'bundle' => 'display_ads',
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
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'token' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Section',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Attach File');
  t('Client');
  t('Description');
  t('Display Ad');
  t('Display Ad Type');
  t('Email');
  t('File Attach');
  t('Link');
  t('Link file here by typing the title of the uploaded file name. To upload a file click <a href=\'/node/add/attachment\' target=\'_NEW\'>here.</a>');
  t('Link this display ad to a PDF attachment, another display ad or even a classified ad. Link to a specific PW web page, or even an online web submission form. You can also create the attachment right here.
<strong>Display ads can only be linked. Do not create another display ad here!</strong>');
  t('Optional email contact for business.');
  t('Publishing Date');
  t('Related File');
  t('Section');
  t('Section Selector');
  t('Select the ad type. This will affect the ads placement and thumbnail size. <br>
<strong>ALL ADS ARE FORCED RESIZED TO THE AD TYPE.</strong>.');
  t('The following are considered clients
<ul>
<li>Pennywise
<li>Obituaries
<li>Birth Announcements
<li>Wedding Announcements
</ul>');
  t('Title tag allows you to shorten very long and complex web links with a concise title.<br>
Eg. You can replace:<br>
<em>http://www.example.com/book_1/chapt-3/page_30</em><br>
with <strong>Page 30</strong>.<br>
<p><strong>NOTE: YOU must include HTTP://</strong><br>if the URL is not located at http://PennywiseAds.com
');
  t('Upload (or select) display ad.');
  t('Upload related document.');

  return $fields;
}
