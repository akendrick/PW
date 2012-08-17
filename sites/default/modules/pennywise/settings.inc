<?php

/**
 * @file
 *  Settings Page/Form and form validation.
 *
 */
function pw_greetings_page() {
  $output = t('<h2>Pennywise Settings.</h2>');
  $output .= t('<p><strong> Classified Settings: </strong> From here you can change the default greetings, place holiday messages and change the default email address.');
  $output .= t('<p><strong> Display Settings: </strong> From here you can change ... nothing at this time.');
  #$output = drupal_get_form('classified_settingsform');
  
  return $output;
  
}
function pw_general_settings_page() {
  $output = t('Pennywise Website General Settings.');
  #$output = drupal_get_form('classified_settingsform');
  $output = drupal_get_form('pennywise_general_settingsform');
 
  return $output;
  
}


function pw_classified_settings_page() {
  $output = t('Settings for classifieds.');
  $output = drupal_get_form('pennywise_classified_settingsform');
  
  return $output;
  
}

function pw_display_settings_page() {
  $output = t('No settings for display at this time.');
  #$output = drupal_get_form('classified_settingsform');
  
  return $output;
  
}


/**
* Implementation of FAPI for classifieds
*/

function pennywise_classified_settingsform() {
  $form['default_email'] = array(
    '#title' => t('Default Email'),
    '#type'  => 'textfield',
    '#description' => t('A default email address to which a copy of all submitted classified ads will be sent to in addition to being saved on the server.'),
    '#default_value' => variable_get('pw_email', 'info@pennywiseads.com'),
    '#required' => TRUE,
  );
  
  $form['online_submissions'] = array(
    '#title'       => t('Online Submissions'),
    '#type'        => 'radios',
    '#description' => t('Allows users to submit classified ads online.'),
    '#options'     => array(
      t('Disable Submission'),
      t('Submit Ads'),
    ),
    '#default_value' => variable_get('pennywise_classified_settings_submissions', 1),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Submit'),
  );
  
  return $form;
}


/**
* Implementation of custom form validation -- CLASSIFIED.
*/
function pennywise_classified_settingsform_validate($form, &$form_state) {
  if ( !valid_email_address($form_state['values']['default_email']) ) {
    form_set_error('default_email', t('Invalid email address.'));
  }
}

/**
* Implementation of form submission -- CLASSIFIED.
*/
function pennywise_classified_settingsform_submit($form, &$form_state) {

  $email = $form_state['values']['default_email'];
  $disable_submission = $form_state['values']['online_submissions'];

  variable_set('pennywise_classified_settings_email', $email);
  variable_set('pennywise_classified_settings_submissions', $disable_submission);
  
  drupal_set_message( t('Your settings have been updated.') );

}

