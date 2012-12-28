<?php

/**
 * @file
 *  Settings Page/Form and form validation.
 *
 *   // USING Absolute_messages as PDM (persistant dismissable messages not working as expected.
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
  /* set defaults */
  $holiday_settings = array(
    'holiday_settings' => 0,
    'regular_hours'    => t('Open Monday to Thursday 9am - 5pm, Friday 9am - 4pm.'),
    'holiday_message_type' => 2,
    'holiday'          => t('Pennywise is closed for Christmas'),
    'holiday_hours'    => t('Monday Dec. 19, 2012 - Tuesday Jan 3rd, 2013'),
    'holiday_details'  => t(''),
    'holiday_message'  => t('<h2>@holiday</h2><p>The Pennywise office will be closed @hours.<br> @details.',
      array('@holiday' => $holiday_settings['holiday'], '@hours' => $holiday_settings['holiday_hours'], '@details' => $holiday_settings['holiday_details'])),
  );
  $holiday = variable_get('pennywise_holiday_settings', $holiday_settings);

  $form['holiday_settings'] = array(
    '#title'       => t('Set Holiday Greeting'),
    '#type'        => 'radios',
    '#description' => t('Set holiday messages to display on the site.<br>This greeting will only be visible if <em>Holidays</em> is set to anything other than <strong>Regular Hours</strong>.'),
    '#options'     => array(
      0 => 'Regular Hours',
      1 => 'Turn on Holiday message.',
    ),
    '#default_value' => $holiday['holiday_settings'],
    '#required'      => TRUE,
  );

  $form['regular_hours'] = array(
    '#title'       => t('Regular Hours of Operation'),
    '#description' => t('This is the defacto days of operation. Shown only when holiday hours are not visible.'),
    '#type'        => 'textfield',
    '#default_value' => $holiday['regular_hours'],
    '#required'      => TRUE,
  );


  $form['hm'] = array(
    '#type' => 'fieldset',
    '#title' => t('Set Holiday Message'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

/*
  $form['hm']['holiday_message_type'] = array(
    '#title'       => t('Holiday Message Type'),
    '#type'        => 'radios',
    '#description' => t('Specify how the holiday message is shown.<dl><dt>Dismissible</dt><dd>User can dismiss the message or wait for it to automatically disappear after certain amount of time.</dd><dt>Permanent</dt><dd>(Non-dismissible) Message is always present and cannot be removed.</dd></dl>This greeting will only be visible if <em>Holidays</em> is set to anything other than <strong>Regular Hours</strong>.'),
    '#options'     => array(
      0 => t('Show message once then nevermore. (Dismissible)'),
      1 => t('Show message on every page. (Dismissable)'),
      2 => t('Show message on every pages including emails & reciepts. (Dismissable)'),
      3 => t('Show message on every pages including emails & reciepts. (Permanent)'),
    ),
    '#default_value' => $holiday['holiday_message_type'],
    '#required'      => TRUE,
  );
*/

  $form['hm']['holiday'] = array(
    '#title'         => t('Holiday'),
    '#description'   => t('The reason for the change in schedule. <br><em>Eg. Christmas, Ramadan, or Rememberance Day.</em>'),
    '#type'          => 'textfield',
    '#default_value' => $holiday['holiday'],
    '#required'      => TRUE,
  );

  $form['hm']['holiday_hours'] = array(
    '#title'       => t('Holiday Date & Time'),
    '#description' => t('<em>Eg. Monday Dec. 19, 2012 - Tuesday Jan 3rd, 2013</em>'),
    '#type'        => 'textfield',
    '#default_value' => $holiday['holiday_hours'],
    '#required'      => TRUE,
  );

  $form['hm']['holiday_details'] = array(
   '#title'        => t('Special Holiday Message'),
   '#description'  => t('More details about the holiday ad submission process etc.'),
   '#type'         => 'textarea',
   '#required'     => FALSE,
   '#default_value'=> $holiday['holiday_details'],
   '#cols'         => 10,
   '#rows'         => 5,
   '#resizable'    => FALSE,
 );

 // Holiday Message
  $form['hm']['holiday_message'] = array(
    '#type' => 'fieldset',
    '#title' => 'Holiday Message',
    '#collapsible' => FALSE,
  );
  // OUtput
  $form['hm']['holiday_message']['message'] = array(
    '#type'         => 'item',
    '#description'  => $holiday['holiday_message'],
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
    'holiday_settings'  => $form_state['values']['holiday_settings'],
    'regular_hours'     => $form_state['values']['regular_hours'],
    'holiday_message_type' => $form_state['values']['holiday_message_type'],
    'holiday'          => $form_state['values']['holiday'],
    'holiday_hours'    => $form_state['values']['holiday_hours'],
    'holiday_details'  => $form_state['values']['holiday_details'],
  );


  $holiday['holiday_message'] =
    t('<h2>@holiday</h2><p class="holiday-hours">The Pennywise office will be closed @hours.</p><p class="holiday-details">@details',
    array('@holiday' => $holiday['holiday'], '@hours' => $holiday['holiday_hours'], '@details' => $holiday['holiday_details']));
  $holiday['holiday_message_plain'] =
    t('@holiday.\n\r The Pennywise office will be closed @hours. \r\n @details',
    array('@holiday' => $holiday['holiday'], '@hours' => $holiday['holiday_hours'], '@details' => $holiday['holiday_details']));

//  dpm('FORM STATE');
//  dpm($form_state);
//  dpm('Holiday Settings');
//  dpm($holiday);

  variable_set('pennywise_holiday_settings', $holiday);

  drupal_set_message( t('Your settings have been updated.') );
}