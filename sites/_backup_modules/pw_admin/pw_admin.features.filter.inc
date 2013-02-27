<?php
/**
 * @file
 * pw_admin.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pw_admin_filter_default_formats() {
  $formats = array();

  // Exported format: Edition Editor.
  $formats['edition_editor'] = array(
    'format' => 'edition_editor',
    'name' => 'Edition Editor',
    'cache' => '1',
    'status' => '1',
    'weight' => '-10',
    'filters' => array(
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'scribd_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'scribd_filter_display_method' => 'embed_html5',
          'scribd_filter_display_mode' => 'list',
        ),
      ),
    ),
  );

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '-7',
    'filters' => array(
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_markdown' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <p> <br> <strike> <h2> <h3> <h4> <h5> <h6>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '-6',
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => '-37',
        'status' => '1',
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Markdown Filter.
  $formats['markdown_filtering'] = array(
    'format' => 'markdown_filtering',
    'name' => 'Markdown Filter',
    'cache' => '1',
    'status' => '1',
    'weight' => '-8',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'lightbox2_filter' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_markdown' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '-9',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
