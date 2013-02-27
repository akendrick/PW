<?php

/**
 * @file
 *  Settings Page/Form and form validation.
 *
 */
function pw_general_settings_page() {
  $output .= t('Pennywise Website General Settings.');
  $output = drupal_get_form('pennywise_general_settingsform');

  return $output;

}



/**
* Implementation of FAPI for classifieds
*/

function pennywise_general_settingsform() {
  $form['pennywise_contact_information']['pw_phone_toll_free'] = array(
    '#type' => 'textfield',
    '#title' => t('Toll free phone number.'),
    '#size' => 15,
    '#default_value' => variable_get('pw_phone_toll_free', '1-800-663-4619'),
  );
  $form['pennywise_contact_information']['pw_phone_local'] = array(
    '#type' => 'textfield',
    '#title' => t('Local phone number.'),
    '#size' => 15,
    '#default_value' => variable_get('pw_phone_local', '250-353-2602'),
  );
  $form['pennywise_contact_information']['pw_phone_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax number.'),
    '#size' => 15,
/*         '#description' => t('This is the main contact information for Pennywise.'), */
    '#default_value' => variable_get('pw_phone_fax', '250-353-7444'),
  );
  $form['pennywise_contact_information']['pw_mailing_address'] = array(
    '#type' => 'textfield',
    '#title' => t(' Mailing address.'),
    '#size' => 80,
    '#default_value' => variable_get('pw_mailing_address', 'Box 430, Kaslo, BC Canada, V0G 1M0'),
  );
  $form['pennywise_contact_information']['pw_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Email address.'),
    '#size' => 45,
    '#default_value' => variable_get('pw_email', 'info@pennywiseads.com'),
  );
  $form['pennywise_contact_information']['pw_facebook_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook link.'),
    '#size' => 50,
    '#description' => t('Include full link address. This means <strong>http://</strong>. '),
    '#default_value' => variable_get('pw_facebook_link', 'http://www.facebook.com/profile.php?id=728375773'),
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

