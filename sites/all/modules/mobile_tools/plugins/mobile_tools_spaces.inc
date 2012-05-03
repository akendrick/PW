<?php

/**
 * @file
 * Spaces plugin implementation for Mobile Tools device groups
 *
 * @author Mathew Winstone <mwinstone@coldfrontlabs.ca>
 */
 
/**
 * Mobile Tools integration for Spaces.
 */
class space_mobile_tools extends space_type_purl {
  var $device = NULL;
  
  /**
   * Constructor
   */
  function __construct($type, $id = NULL) {
    parent::__construct($type, $id);
  }
  
  /**
   * Implementation of space->title().
   */
  function title() {
    return 'Mobile Tools Space';
  }

  /**
   * Override of activate().
   */
  function activate() {
    if (parent::activate()) {
      // Set the device group context for the Context module
      //if (module_exists('context')) {
      //   $plugin = context_get_plugin('condition', 'mobile');
      //   if (!empty($plugin)) {
      //     dpm($this);
           //$device_group = mobile_tools_get_active_device_group();
           //$plugin->execute($device_group);
      //   }
      //}
      //dpm($this);
      // Set the header
      
      // Add configured options

      // Replace old hook_init functionality
      /*function mobile_tools_init(){
        global $mobile_tools_device, $conf;
        // Skip everything in case Drush is used
        if (drupal_is_cli()) {
          return;
        }
        // Some small extras
        if (mobile_tools_site_type() == 'mobile') {
          $conf['default_nodes_main'] = variable_get('default_nodes_main_mobile', variable_get('default_nodes_main', 10));
        }   
      }*/

      // @todo replace hook_boot functionality
      /*
      if (mobile_tools_site_type() == 'mobile') {
        $conf['site_frontpage'] = variable_get('site_frontpage_mobile', variable_get('site_frontpage', 'node'));
      }
      */
      
      
      
      return TRUE;
    }
    return FALSE;
  }
  
  /**
   * Override of load().
   */
  function load() {
    return TRUE;
  }
  
  /**
   * Implementation of space->router().
   */
  function router($op, $object = NULL, $is_active = TRUE) {
    switch($op) {
      case 'init':
        return;
    }
  }
}
