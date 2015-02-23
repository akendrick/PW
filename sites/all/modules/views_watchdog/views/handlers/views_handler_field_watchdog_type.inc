<?php

/**
 * @file
 * Views field handler for the views_watchdog module.
 */


/**
 * Provides type display options for the watchdog entry.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_watchdog_type extends views_handler_field {


  function option_definition() {

    $options = parent::option_definition();

    $options['watchdog_type_translate'] = array('default' => TRUE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['watchdog_type_translate'] = array(
      '#type' => 'checkbox',
      '#title' => t('Apply translation'),
      '#default_value' => !empty($this->options['watchdog_type_translate']),
    );
  }


  function render($values) {

    $value = $values->{$this->field_alias};

    if (!empty($this->options['watchdog_type_translate'])) {
      $output = t($value);
    }
    else {
      $output = $this->sanitize_value($value);
    }

    return $output;
  }
}
