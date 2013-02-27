<?php
/**
 * @file
 * pw_pages.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_pages_field_default_fields() {
  $fields = array();

  // Exported field: 'node-article-body'.
  $fields['node-article-body'] = array(
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
      'bundle' => 'article',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'block_list_header' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '80',
          ),
          'type' => 'text_trimmed',
          'weight' => '2',
        ),
        'block_list_item' => array(
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
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'editorial_slideshow' => array(
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
            'trim_length' => '85',
          ),
          'type' => 'text_trimmed',
          'weight' => '2',
        ),
        'simple_teaser' => array(
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
        'teaser' => array(
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
            'trim_length' => '360',
          ),
          'type' => 'text_trimmed',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-article-field_area_taxonomy'.
  $fields['node-article-field_area_taxonomy'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '5',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_area_taxonomy',
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
            'vocabulary' => 'area',
            'parent' => '0',
          ),
        ),
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
        ),
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'article',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'block_list_header' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'block_list_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '12',
        ),
        'editorial_slideshow' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_area_taxonomy',
      'label' => 'Area',
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
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-article-field_email'.
  $fields['node-article-field_email'] = array(
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
      'bundle' => 'article',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'block_list_header' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'block_list_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => '8',
        ),
        'editorial_slideshow' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
      ),
      'ds_extras_field_template' => '',
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
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-article-field_entity_reference'.
  $fields['node-article-field_entity_reference'] = array(
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
      'bundle' => 'article',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'block_list_header' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'block_list_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => '9',
        ),
        'editorial_slideshow' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_entity_reference',
      'label' => 'Reference Other',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-article-field_image'.
  $fields['node-article-field_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '5',
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
      'bundle' => 'article',
      'deleted' => '0',
      'description' => 'This image will be at the top of the page and used through out the site as the articles primary image.',
      'display' => array(
        'block_list_header' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'editorial_block_list_header',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'block_list_item' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightbox__classified_page_style__original',
          'weight' => '0',
        ),
        'editorial_slideshow' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'editorial_block_list_header',
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
        'simple_teaser' => array(
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
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'editorial_teaser',
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
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Header Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => 'field/image',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '800 KB',
        'max_resolution' => '1200x1200',
        'min_resolution' => '150x150',
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
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'file_attach',
            ),
            'source_reference' => array(
              'autocomplete' => '1',
            ),
          ),
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
          'preview_image_style' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-article-field_images_editorial_extra'.
  $fields['node-article-field_images_editorial_extra'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_images_editorial_extra',
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
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'article',
      'deleted' => '0',
      'description' => 'These images can be of lower resolution than the primary header image. These images will only be displayed on the full editorial page, not in any teasers.',
      'display' => array(
        'block_list_header' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'block_list_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'lightbox2',
          'settings' => array(),
          'type' => 'lightbox2__lightshow__editorial_small__original',
          'weight' => '3',
        ),
        'editorial_slideshow' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_images_editorial_extra',
      'label' => 'Extra Images',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '800 KB',
        'max_resolution' => '1000x1000',
        'min_resolution' => '150x150',
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
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'file_attach',
            ),
            'source_reference' => array(
              'autocomplete' => '1',
            ),
          ),
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
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-article-field_link'.
  $fields['node-article-field_link'] = array(
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
      'bundle' => 'article',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'block_list_header' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'block_list_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '7',
        ),
        'editorial_slideshow' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
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
          'url_cutoff' => '80',
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
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-article-field_submitter'.
  $fields['node-article-field_submitter'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_submitter',
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
      'bundle' => 'article',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'block_list_header' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
        ),
        'block_list_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '11',
        ),
        'editorial_slideshow' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'inline',
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
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_submitter',
      'label' => 'Submitted by',
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
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-attachment-body'.
  $fields['node-attachment-body'] = array(
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
      'bundle' => 'attachment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'simple_teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => '350',
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Description',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'display_summary' => 0,
        'text_processing' => '1',
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
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-attachment-field_entity_reference'.
  $fields['node-attachment-field_entity_reference'] = array(
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
      'bundle' => 'attachment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'If the attachment is several pages or files you can reference the other items here.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
        ),
        'simple_teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_entity_reference',
      'label' => 'References',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-attachment-field_file'.
  $fields['node-attachment-field_file'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_file',
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
          'class_id' => '2',
          'current_class_id' => '2',
        ),
        'uri_scheme' => 'storage-field-file',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'attachment',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 11,
        ),
        'simple_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_file',
      'label' => 'File',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'description_field' => 0,
        'file_directory' => 'storage/attachments',
        'file_extensions' => 'txt pdf doc tif psd jpg png ind exl',
        'max_filesize' => '10 MB',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 'attach',
              'clipboard' => 0,
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'move',
              'path' => 'storage/attachments',
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
            'image_classified_list_nocrop' => 0,
            'image_classified_page_style' => 0,
            'image_display_ad_print_thumbnail' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 0,
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_miniature_square' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-attachment-field_high_res_ad'.
  $fields['node-attachment-field_high_res_ad'] = array(
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
      'bundle' => 'attachment',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file_entity',
          'settings' => array(
            'file_view_mode' => 'default',
          ),
          'type' => 'file_rendered',
          'weight' => '4',
        ),
        'simple_teaser' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_url_plain',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_high_res_ad',
      'label' => 'Attachment',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'description_field' => 0,
        'file_directory' => 'attachments',
        'file_extensions' => 'txt pdf jpg tiff gif png',
        'max_filesize' => '5MB',
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
              'path' => 'attachments',
            ),
            'source_reference' => array(
              'autocomplete' => '1',
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

  // Exported field: 'node-attachment-field_image'.
  $fields['node-attachment-field_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '5',
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
      'bundle' => 'attachment',
      'deleted' => '0',
      'description' => 'Optional thumbnail of file. If uploading a PDF (or any kind of image) please include a thumbnail/screen capture so that the viewer can see what they are getting with this.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'file',
            'image_style' => 'large',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'simple_teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'thumbnail',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'file',
            'image_style' => 'medium',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Thumbnail',
      'required' => 1,
      'settings' => array(
        'alt_field' => 0,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => 'images/attachment',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '500 KB',
        'max_resolution' => '',
        'min_resolution' => '',
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
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'file_attach',
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
            'auto' => 0,
            'icon_link' => 0,
            'image' => 'image',
            'image_classified-list-style' => 0,
            'image_classified_list_nocrop' => 0,
            'image_classified_page_style' => 0,
            'image_display_ad_print_thumbnail' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 0,
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_large' => 'image_large',
            'image_medium' => 'image_medium',
            'image_miniature_square' => 0,
            'image_square_thumbnail' => 'image_square_thumbnail',
            'image_thumbnail' => 'image_thumbnail',
            'link' => 0,
          ),
          'insert_width' => '',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-attachment-field_link'.
  $fields['node-attachment-field_link'] = array(
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
      'bundle' => 'attachment',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'By default when you add an attachment you will see a thumbnail/link to the file and the user can click on it to view it at a higher resolution. <strong>By adding a link here you override that and the user is instead sent to this web address.</strong>',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '5',
        ),
        'simple_teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_link',
      'label' => 'Highlighted Link',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => 'highlighted-link',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'custom_add_another' => '',
        'display' => array(
          'url_cutoff' => '80',
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-page-body'.
  $fields['node-page-body'] = array(
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
      'bundle' => 'page',
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
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'display_summary' => 1,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-page-field_entity_reference'.
  $fields['node-page-field_entity_reference'] = array(
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
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Attach pages, display ads, editorials or downloadable files to this page.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => TRUE,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_entity_reference',
      'label' => 'References',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-page-field_image'.
  $fields['node-page-field_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '5',
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
      'bundle' => 'page',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'editorial_header',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'medium',
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
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_image',
      'label' => 'Header Image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => 'images/page',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 'attach',
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'images',
            ),
            'source_reference' => array(
              'autocomplete' => '1',
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
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-page-field_images_editorial_extra'.
  $fields['node-page-field_images_editorial_extra'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_images_editorial_extra',
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
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'page',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_images_editorial_extra',
      'label' => 'Inserted Images',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => 'images/page',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
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
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'images',
            ),
            'source_reference' => array(
              'autocomplete' => '1',
            ),
          ),
          'insert' => 1,
          'insert_absolute' => FALSE,
          'insert_class' => 'inserted-image-style',
          'insert_default' => 'image_medium',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 'image',
            'image_classified_ad_image_small' => 0,
            'image_display_ad_banner' => 0,
            'image_display_ad_poster' => 0,
            'image_display_ad_print_full' => 0,
            'image_display_ad_print_thumbnail' => 0,
            'image_display_ad_splash' => 0,
            'image_display_ad_target' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 'image_editorial_small',
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_large' => 'image_large',
            'image_medium' => 'image_medium',
            'image_square_thumbnail' => 'image_square_thumbnail',
            'image_thumbnail' => 'image_thumbnail',
            'link' => 'link',
          ),
          'insert_width' => '550',
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-page-field_link'.
  $fields['node-page-field_link'] = array(
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
      'bundle' => 'page',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'This link field is for expressly highlighting a specific link. It will be displayed in large type.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_link',
      'label' => 'Highlighted Link',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => 'link-highlight',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'default',
          'title' => '',
        ),
        'custom_add_another' => '',
        'display' => array(
          'url_cutoff' => '80',
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
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-body'.
  $fields['node-pw_digital-body'] = array(
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
      'bundle' => 'pw_digital',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<strong>You can also copy and paste the whole text from Scribd.</strong>
<ol><li>Navigate to the edition you want to embed.</li>
<li>Select Embed</li>
<li>Choose option <strong>WordPress</strong></li>
<li>copy and paste the whole line into the body of the text.</li>
<li>Should look like: <em>[scribd id=pub-18673738874898982461 key=yy mode=list] </em></li>
</ol>',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'kootenay_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'nelson_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'trail_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'display_summary' => 0,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_castlegar_edition'.
  $fields['node-pw_digital-field_castlegar_edition'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_castlegar_edition',
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
        'max_length' => '80',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'castlegar_edition_view' => array(
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
          'type' => 'text_default',
          'weight' => '0',
        ),
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
          'weight' => '8',
        ),
        'full' => array(
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
          'weight' => '8',
        ),
        'kootenay_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'nelson_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'teaser' => array(
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
          'weight' => '8',
        ),
        'trail_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_castlegar_edition',
      'label' => 'Castlegar Edition',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_display_ad'.
  $fields['node-pw_digital-field_display_ad'] = array(
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
      'bundle' => 'pw_digital',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'kootenay_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'nelson_edition_view' => array(
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
        'trail_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_display_ad',
      'label' => 'Cover',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'custom_add_another' => '',
        'default_image' => 0,
        'file_directory' => 'images/cover',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '100 KB',
        'max_resolution' => '900x900',
        'min_resolution' => '100x100',
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
              'reference' => 'reference',
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'file_attach',
            ),
            'source_reference' => array(
              'autocomplete' => '1',
            ),
          ),
          'insert' => 0,
          'insert_absolute' => FALSE,
          'insert_class' => '',
          'insert_default' => 'auto',
          'insert_styles' => array(
            'auto' => 'auto',
            'image' => 0,
            'image_classified-list-style' => 0,
            'image_classified_page_style' => 0,
            'image_display_ad_print_thumbnail' => 0,
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
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_edition_date'.
  $fields['node-pw_digital-field_edition_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_edition_date',
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
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datetime',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'default' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'kootenay_edition_view' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'nelson_edition_view' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'trail_edition_view' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_edition_date',
      'label' => 'Edition Date',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'default_value' => 'strtotime',
        'default_value2' => 'same',
        'default_value_code' => '+1 Tuesday',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'display_all_day' => 0,
          'increment' => '15',
          'input_format' => 'Y-m-d H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_entity_reference'.
  $fields['node-pw_digital-field_entity_reference'] = array(
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
      'bundle' => 'pw_digital',
      'deleted' => '0',
      'description' => 'Create and link special feature pages. Eg. Hometown Business pages, Christmas Carols, and Back to School sections.',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '1',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '10',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '10',
        ),
        'kootenay_edition_view' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '1',
        ),
        'nelson_edition_view' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'link' => 1,
          ),
          'type' => 'entityreference_label',
          'weight' => '10',
        ),
        'trail_edition_view' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 1,
            'view_mode' => 'teaser',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_entity_reference',
      'label' => 'Special Feature',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => 'Attach another special feature.',
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_kootenay_lake_edition'.
  $fields['node-pw_digital-field_kootenay_lake_edition'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_kootenay_lake_edition',
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
        'max_length' => '80',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
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
          'weight' => '9',
        ),
        'full' => array(
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
          'weight' => '9',
        ),
        'kootenay_edition_view' => array(
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
          'type' => 'text_default',
          'weight' => '0',
        ),
        'nelson_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'teaser' => array(
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
          'weight' => '9',
        ),
        'trail_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_kootenay_lake_edition',
      'label' => 'Kootenay Lake Edition',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_nelson_edition'.
  $fields['node-pw_digital-field_nelson_edition'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_nelson_edition',
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
        'max_length' => '80',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
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
          'weight' => '7',
        ),
        'full' => array(
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
          'weight' => '7',
        ),
        'kootenay_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'nelson_edition_view' => array(
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
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
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
          'weight' => '7',
        ),
        'trail_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_nelson_edition',
      'label' => 'Nelson Edition',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'text_processing' => '1',
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

  // Exported field: 'node-pw_digital-field_pdf'.
  $fields['node-pw_digital-field_pdf'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_pdf',
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
        'display_field' => 0,
        'storage_class' => array(
          'class_id' => '2',
          'current_class_id' => '1',
        ),
        'uri_scheme' => 'storage-field-pdf',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'deleted' => '0',
      'description' => 'Direct link to pdf for download purposes. <strong>Label the file with the AREA.</strong><br><em>eg. Pennywise_Castlegar_Nov13-2021.pdf</em>',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '1',
        ),
        'kootenay_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'nelson_edition_view' => array(
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
        'trail_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_pdf',
      'label' => 'PDF',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'description_field' => 1,
        'file_directory' => 'pdf',
        'file_extensions' => 'pdf',
        'max_filesize' => '10MB',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'file',
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
              'attach_mode' => 'copy',
              'path' => 'file_attach',
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
            'image_classified_list_nocrop' => 0,
            'image_classified_page_style' => 0,
            'image_display_ad_print_thumbnail' => 0,
            'image_editorial_block_list_header' => 0,
            'image_editorial_header' => 0,
            'image_editorial_small' => 0,
            'image_editorial_teaser' => 0,
            'image_editorial_thumbnail' => 0,
            'image_large' => 0,
            'image_medium' => 0,
            'image_miniature_square' => 0,
            'image_square_thumbnail' => 0,
            'image_thumbnail' => 0,
            'link' => 0,
          ),
          'insert_width' => '',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_scribd'.
  $fields['node-pw_digital-field_scribd'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_scribd',
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
        'max_length' => '80',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'default_value' => array(
        0 => array(
          'value' => '[scribd id=pub-18673738874898982461 key=yy mode=list]',
          'format' => 'edition_editor',
        ),
      ),
      'deleted' => '0',
      'description' => 'You can also copy and paste the whole text from Scribd.
<ol>
<li>Navigate to the edition you want to embed.
<li>Select Embed
<li>Choose option WordPress
<li>copy and paste the whole line into the body of the text.
<li>Should look like: <em>[scribd id=pub-18673738874898982461 key=yy mode=list]</em>
',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
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
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
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
          'type' => 'text_default',
          'weight' => '0',
        ),
        'kootenay_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'nelson_edition_view' => array(
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
        'trail_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_scribd',
      'label' => 'Scribd',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => 'Add another edition',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '80',
        ),
        'type' => 'text_textfield',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_special_feature_link'.
  $fields['node-pw_digital-field_special_feature_link'] = array(
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
      'bundle' => 'pw_digital',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Link special feature here by typing the name of the file.<br>
If you have not uploaded the special feature <a href=\'/node/add/attachment\' target=\'_NEW\'>click here.</a><br>
NOTE: Thumbnail image required.',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 11,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'kootenay_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'nelson_edition_view' => array(
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
        'trail_edition_view' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_special_feature_link',
      'label' => 'Special Feature Link',
      'required' => 0,
      'settings' => array(
        'custom_add_another' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-pw_digital-field_trail'.
  $fields['node-pw_digital-field_trail'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_trail',
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
        'max_length' => '80',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'pw_digital',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'castlegar_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
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
          'weight' => '6',
        ),
        'full' => array(
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
          'weight' => '6',
        ),
        'kootenay_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'nelson_edition_view' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'teaser' => array(
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
          'weight' => '6',
        ),
        'trail_edition_view' => array(
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
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_trail',
      'label' => 'Trail Edition',
      'required' => 1,
      'settings' => array(
        'custom_add_another' => '',
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<strong>You can also copy and paste the whole text from Scribd.</strong>
<ol><li>Navigate to the edition you want to embed.</li>
<li>Select Embed</li>
<li>Choose option <strong>WordPress</strong></li>
<li>copy and paste the whole line into the body of the text.</li>
<li>Should look like: <em>[scribd id=pub-18673738874898982461 key=yy mode=list] </em></li>
</ol>');
  t('Area');
  t('Attach pages, display ads, editorials or downloadable files to this page.');
  t('Attachment');
  t('Body');
  t('By default when you add an attachment you will see a thumbnail/link to the file and the user can click on it to view it at a higher resolution. <strong>By adding a link here you override that and the user is instead sent to this web address.</strong>');
  t('Castlegar Edition');
  t('Cover');
  t('Create and link special feature pages. Eg. Hometown Business pages, Christmas Carols, and Back to School sections.');
  t('Description');
  t('Direct link to pdf for download purposes. <strong>Label the file with the AREA.</strong><br><em>eg. Pennywise_Castlegar_Nov13-2021.pdf</em>');
  t('Edition Date');
  t('Email');
  t('Extra Images');
  t('File');
  t('Header Image');
  t('Highlighted Link');
  t('If the attachment is several pages or files you can reference the other items here.');
  t('Inserted Images');
  t('Kootenay Lake Edition');
  t('Link');
  t('Link special feature here by typing the name of the file.<br>
If you have not uploaded the special feature <a href=\'/node/add/attachment\' target=\'_NEW\'>click here.</a><br>
NOTE: Thumbnail image required.');
  t('Nelson Edition');
  t('Optional thumbnail of file. If uploading a PDF (or any kind of image) please include a thumbnail/screen capture so that the viewer can see what they are getting with this.');
  t('PDF');
  t('Reference Other');
  t('References');
  t('Scribd');
  t('Special Feature');
  t('Special Feature Link');
  t('Submitted by');
  t('These images can be of lower resolution than the primary header image. These images will only be displayed on the full editorial page, not in any teasers.');
  t('This image will be at the top of the page and used through out the site as the articles primary image.');
  t('This link field is for expressly highlighting a specific link. It will be displayed in large type.');
  t('Thumbnail');
  t('Trail Edition');
  t('You can also copy and paste the whole text from Scribd.
<ol>
<li>Navigate to the edition you want to embed.
<li>Select Embed
<li>Choose option WordPress
<li>copy and paste the whole line into the body of the text.
<li>Should look like: <em>[scribd id=pub-18673738874898982461 key=yy mode=list]</em>
');

  return $fields;
}
