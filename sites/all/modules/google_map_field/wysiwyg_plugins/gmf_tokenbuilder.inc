<?php

/**
 * @file
 * Specialised hook to register plugin presence with the WYSIWYG module.
 */

/**
 *  WYSIWYG module integration for map token builder
 */
function google_map_field_gmf_tokenbuilder_plugin() {
  $plugins['gmf_tokenbuilder'] = array(
    'title' => t('Google Map Field Token Builder'),
    'icon file' => 'gmftb.toolbar_icon.png',
    'icon title' => t('Google Map Field Token Builder'),
    'settings' => array(),
  );
  return $plugins;
}
