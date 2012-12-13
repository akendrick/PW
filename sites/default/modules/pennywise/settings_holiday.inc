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
  $holiday_settings = array(
    'setting_flag' => 0, // 0 is no holiday, 1 is early deadline, 2 is Longweekend/special, 3 is Extended holiday.
    'setting_hr' => 'No Holiday Message (Regular Hours)',
    'event' => 'Pennywise will be closed for Christmas.',
    'hours' => 'Monday Dec. 19, 2012 - Tuesday Jan 3rd, 2013',
    'submission_flag' => 0,
    'submission_hr' => 'hourly',
    'message' => '',
    'receipt_message' => '',
  );
  $holiday = variable_get('pennywise_holiday_settings', $holiday_settings);

//  $holiday_message = t('<h2>@holiday</h2><p>The Pennywise office will be closed @hours.<br> Online submissions will be updated @online.',
//      array('@holiday' => $holiday_event, '@hours' => $holiday_hours, '@online' => $online));

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
    '#default_value' => $holiday['setting_flag'],
    '#required'      => TRUE,
  );

  $form['regular_hours'] = array(
    '#title'       => t('Regular Hours of Operation'),
    '#description' => t('This is the defacto days of operation. Shown only when holiday hours are not visible.'),
    '#type'        => 'textfield',
    '#default_value' => 'Open Monday to Thursday 9am - 5pm, Friday 9am - 4pm',
    '#required'      => TRUE,
  );

  $form['hm'] = array(
    '#type' => 'fieldset',
    '#title' => 'Set Holiday Message',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['hm']['holiday'] = array(
    '#title'         => t('Holiday'),
    '#description'   => t('The reason for the change in schedule. <br><em>Eg. Christmas, Ramadan, or Rememberance Day.</em>'),
    '#type'          => 'textfield',
    '#default_value' => $holiday['event'],
    '#required'      => TRUE,
  );

  $form['hm']['holiday_hours'] = array(
    '#title'       => t('Holiday Date/Time'),
    '#description' => t('This greeting will only be visible if <em>Holidays</em> is set to anything other than <strong>Regular Hours</strong>.<em>Eg. Monday Dec. 19, 2012 - Tuesday Jan 3rd, 2013</em>'),
    '#type'        => 'textfield',
    '#default_value' => $holiday['hours'],
    '#required'      => TRUE,
  );

  $form['hm']['online_submissions'] = array(
    '#title'       => t('Online Submissions'),
    '#type'        => 'radios',
    '#description' => t('Set online submission updating.'),
    '#options'     => array(
      t('hourly'),
      t('daily'),
      t('every few days'),
      t('on the return of regular business hours'),
    ),
    '#default_value' => $holiday['submission_flag'],
    '#required'      => TRUE,
  );

  // Holiday Message
  $form['hm']['holiday_message'] = array(
    '#type' => 'fieldset',
    '#title' => 'Holiday Message',
    '#collapsible' => FALSE,
  );
  // OUtput
  $form['hm']['holiday_message']['output'] = array(
    '#type'         => 'item',
    '#description'  => $holiday['message'],
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

  $holiday = array(
    'setting_flag' => $form_state['values']['holiday_settings'], // 0 is no holiday, 1 is early deadline, 2 is Longweekend/special, 3 is Extended holiday.
    'setting_hr' => $form_state['complete form']['holiday_settings'][$holiday_settings]['#title'],
    'event' => $form_state['values']['holiday'],
    'hours' => $form_state['values']['holiday_hours'],
    'reg_hours' => $form_state['values']['regular_hours'],
    'submission_flag' => $form_state['values']['online_submissions'],
    'submission_hr' => $form_state['complete form']['online_submissions'][$online]['#title'],
  );


  // Create specific message for ad submission receipts.
  switch($holiday['submission_flag']) {
    case 0: //Hourly
      $holiday['receipt_message'] = '';
      break;
    case 1: // Daily
      $holiday['receipt_message'] = 'Online ad submissions are checked daily. Liveload ads are given priority and will be processed within 24 hours the next business day after submission.';
      break;
    case 2: // Every Few Days
      $holiday['receipt_message'] = 'During long holidays the office is closed but online submissions are checked periodically, and all ad submissions will be processed in due course. Liveload ads will be given priority and processed every 3-4 days.';
      break;
    case 3: // On the return of regular business hours
      $holiday['receipt_message'] = 'During long holidays the office is closed but online submissions are checked periodically. All ad submissions will be processed in due course. Liveload ads will be processed online at the return of regular business hours.';
      break;
  }
  $holiday['message'] =
    t('<h2>@holiday</h2><p class="holiday-hours">The Pennywise office will be closed @hours.</p><p class="holiday-details">@online',
    array('@holiday' => $holiday['event'], '@hours' => $holiday['hours'], '@online' => $holiday['receipt_message']));

//  dpm('FORM STATE');
//  dpm($form_state);
//  dpm('Holiday Settings');
//  dpm($holiday);

  variable_set('pennywise_holiday_settings', $holiday);

  drupal_set_message( t('Your settings have been updated.') );
}