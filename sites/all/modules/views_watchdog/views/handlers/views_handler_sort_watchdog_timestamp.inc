<?php

/**
 * @file
 * Views field handler for the views_watchdog module.
 */

/**
 * Provides watchdog event ID as secondary sort for the timestamp field.
 *
 * @ingroup views_sort_handlers
 */
class views_handler_sort_watchdog_timestamp extends views_handler_sort_date {


  function option_definition() {

    $options = parent::option_definition();

    $options['watchdog_timestamp_secondary_sort'] = array('default' => TRUE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['watchdog_timestamp_secondary_sort'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add watchdog event ID as secondary sort field.'),
      '#description' => t('Useful if several watchdog entries have the same timestamp.'),
      '#default_value' => !empty($this->options['watchdog_timestamp_secondary_sort']),
    );
  }


  function query() {

    parent::query();

    if (!empty($this->options['watchdog_timestamp_secondary_sort'])) {
      $this->query->add_orderby(NULL, $this->table_alias . '.wid', $this->options['order']);
    }
  }
}
