<?php

/**
 * @file
 * API functions for mobile_tools
 */

/**
 * Define the list of device groups available to mobile_tools
 *
 * Set a list of id/human readable pairs of arbitrary device groupings.
 * Do not wrap the name in the t() function. The value will be translated
 * later on before display to ensure proper translation.
 * 
 * You can name your device groups however you like.
 * Ensure the keys contain only lowercase, alphanumeric values along
 * with dashes and/or underscores.
 *
 * Used to define a device "space" and used as the default values
 * in the hook_purl_provider() implementation in mobile_tools.module
 *
 * Only one implementation of this hook is triggered at any given time. The
 * options for which module to use are configurable in the administrative
 * pages for mobile_tools.
 *
 * @return array
 *  Returns an array of device groups
 */
function hook_mobile_tools_device_groups() {
  return array(
    'iphone' => 'iPhone',
    'ipod' => 'iPod',
    'ipad' => 'iPad',
    'android' => 'Android',
    'opera_mini' => 'Opera Mini',
    'blackberry' => 'BlackBerry',
  );
}

/**
 * Detect the type of device in use.
 *
 * @todo write documentation
 */
function hook_mobile_tools_detect_device() {
  
}

/**
 * Detect if the given feature is available for the given device.
 *
 * @param string $capability
 *  Name of the capability to test
 * @param string $device
 *  Name of the device to test
 * @return boolean
 *  Returns TRUE if the device is capable, FALSE otherwise.
 *
 * @todo verify the notes on this hook
 * @todo see how this works
 */
function hook_mobile_tools_device_capability($capability, $device = NULL) {
  
}