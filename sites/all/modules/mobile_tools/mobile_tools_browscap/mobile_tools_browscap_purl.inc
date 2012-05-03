<?php

class mobile_tools_browscap_purl implements purl_processor {

/*
browser
platform
frames
iframes
tables
cookies
javascript
vbscript
javaapplets
activexcontrols
ismobiledevice
issyndicationreader
crawler
cssversion
parent
*/


  public function method() {
    return 'browscap';
  }

  /**
   * Allow extension of the admin setup form.
   */
  public function admin_form(&$form, $id) {

  }

  /**
   * Provide a description of processor for the end user
   *
   * @return string description.
   */
  public function description() {
    return t("Purl processor based on browscap.");
  }

  /**
   * Detect the the processor value for the current page request
   *
   * @return value that can be pased to the parse step.
   */
  public function detect($q) {
    return browscap_get_browser();
  }

  /**
   * Detects processor in the passed 'value'.
   *
   * @param $valid_values
   * @param $value
   * @return an array of purl_path_element objects
   */
  public function parse($valid_values, $value) {

  }

  /**
   * Can't adjust browscap
   */
  public function adjust(&$value, $element, &$q) { }

  /**
   * Can't rewrite browscap
   */
  public function rewrite(&$path, &$options, $element) { }


}
