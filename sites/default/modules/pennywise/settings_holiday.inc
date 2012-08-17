<?php

/**
 * @file
 *  Settings Page/Form and form validation.
 *
 */

function pw_holiday_settings_page() {
  $output = t('Pennywise Holiday Message Settings.');
  #$output = drupal_get_form('classified_settingsform');
  $output = drupal_get_form('pennywise_holiday_settingsform');
 
  return $output;
  
}


/**
* Implementation of FAPI for General
*/

function pennywise_holiday_settingsform() {
  /* defaults */
  $holiday_settings = variable_get('pennywise_holiday_settings', array('#title' => 'No Holiday Message (Regular Hours)', '#value' => 0));
  $holiday_event = variable_get('pennywise_holiday_event', t('Pennywise will be closed for Christmas.'));
  $holiday_hours = variable_get('pennywise_holiday_hours', t('Monday Dec. 19, 2012 - Tuesday Jan 3rd, 2013'));
  $online = variable_get('pennywise_holiday_online', array('#title' => 'hourly', '#value' => 0));

  $holiday_message = t('<h2>@holiday</h2><p>The Pennywise office will be closed @hours.<br> Online submissions will be updated @online.', 
      array('@holiday' => $holiday_event, '@hours' => $holiday_hours, '@online' => $online));

  $form['holiday_settings'] = array(
    '#title'       => t('Holiday Greeting'),
    '#type'        => 'radios',
    '#description' => t('Set holiday messages to display on the site.<br>This greeting will only be visible if <em>Holidays</em> is set to anything other than <strong>Regular Hours</strong>.'),
    '#options'     => array(
      t('No Holiday Message (Regular Hours)'),
      t('Early Deadline'),
      t('Long Weekend/Special Holiday'),
      t('Extended Holidays'),
    ),
    '#default_value' => $holiday_settings['#value'],
    '#required'      => TRUE,
  );
  
  $form['holiday'] = array(
    '#title'         => t('Holiday'),
    '#description'   => t('The reason for the change in schedule. <br><em>Eg. Christmas, Ramadan, or Rememberance Day.</em>'),
    '#type'          => 'textfield',
    '#default_value' => $holiday_event,
    '#required'      => TRUE,
  );

  $form['holiday_hours'] = array(
    '#title'       => t('Holiday Date/Time'),
    '#description' => t('This greeting will only be visible if <em>Holidays</em> is set to anything other than <strong>Regular Hours</strong>.'),
    '#type'        => 'textfield',
    '#default_value' => $holiday_hours,
    '#required'      => TRUE,
  );

  $form['online_submissions'] = array(
    '#title'       => t('Online Submissions'),
    '#type'        => 'radios',
    '#description' => t('Set online submission updating.'),
    '#options'     => array(
      t('hourly'),
      t('daily'),
      t('every few days'),
      t('on the return of regular business hours'),
    ),
    '#default_value' => $online['#value'],
    '#required'      => TRUE,
  );

  // Holiday Message
  $form['holiday_message'] = array(
    '#type' => 'fieldset',
    '#title' => 'Holiday Message',
    '#collapsible' => FALSE,
  );
  // OUtput
  $form['holiday_message']['output'] = array(
    '#type'         => 'item',
    '#description'  => $holiday_message,
    '#attributes'   => array('message-demo'),
  );
  
  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}


/**
* Implementation of form submission -- HOLIDAY.
*/
function pennywise_holiday_settingsform_submit($form, &$form_state) {

  $holiday_event    = $form_state['values']['holiday'];
  $holiday_hours    = $form_state['values']['holiday_hours'];
  
  $holiday_settings = $form_state['values']['holiday_settings'];
  $holiday_settings = array(
    '#value' => $form_state['values']['holiday_settings'],
    '#title' => $form_state['complete form']['holiday_settings'][$holiday_settings]['#title'],
  );
  $online = $form_state['values']['online_submissions'];
  $online = array(
    '#value' => $form_state['values']['online_submissions'],
    '#title' => $form_state['complete form']['online_submissions'][$online]['#title'],
  );

  variable_set('pennywise_holiday_settings', $holiday_settings);
  variable_set('pennywise_holiday_event', $holiday_event);
  variable_set('pennywise_holiday_hours', $holiday_hours);
  variable_set('pennywise_holiday_online', $online);  
 
  drupal_set_message( t('Your settings have been updated.') );
}