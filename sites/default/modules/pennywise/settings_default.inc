<?php

/**
 * @file
 *  Settings Page/Form and form validation.
 *
 */
function pw_general_settings_page() {
#  $output = t('Pennywise Website General Settings.');
  $output = drupal_get_form('pennywise_general_settingsform');

  return $output;

}



/**
* Implementation of FAPI for classifieds
*/

function pennywise_general_settingsform() {
  $pw_general = array(
    'toll_free' => '1-800-663-4619',
    'local'     => '250-353-2602',
    'fax'       => '250-353-7444',
    'mailing_address' => 'Box 430, Kaslo, BC Canada, V0G 1M0',
    'email'     => 'info@pennywiseads.com',
    'contest'   => 'Enter PW Contests Click Here.',
    'facebook'  => 'http://www.facebook.com/profile.php?id=728375773',
    'twitter'   => 'https://twitter.com/PennywiseAds',
  );
  $pw_general = variable_get('pennywise_general_contact_settings', $pw_general);


  $form['pennywise_contact_information']['toll_free'] = array(
    '#type' => 'textfield',
    '#title' => t('Toll free phone number.'),
    '#size' => 15,
    '#default_value' => $pw_general['toll_free'],
/*  '#default_value' => variable_get('pw_phone_toll_free', '1-800-663-4619'), */
  );
  $form['pennywise_contact_information']['local'] = array(
    '#type' => 'textfield',
    '#title' => t('Local phone number.'),
    '#size' => 15,
    '#default_value' => $pw_general['local'], //variable_get('pw_phone_local', '250-353-2602'),
  );
  $form['pennywise_contact_information']['fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax number.'),
    '#size' => 15,
/*         '#description' => t('This is the main contact information for Pennywise.'), */
   '#default_value' => $pw_general['fax'], // '#default_value' => variable_get('pw_phone_fax', '250-353-7444'),
  );
  $form['pennywise_contact_information']['mailing_address'] = array(
    '#type' => 'textfield',
    '#title' => t(' Mailing address.'),
    '#size' => 80,
    '#default_value' => $pw_general['mailing_address'], //'#default_value' => variable_get('pw_mailing_address', 'Box 430, Kaslo, BC Canada, V0G 1M0'),
  );
  $form['pennywise_contact_information']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Email address.'),
    '#size' => 45,
    '#default_value' => $pw_general['email'], //'#default_value' => variable_get('pw_email', 'info@pennywiseads.com'),
  );

  $form['pennywise_contact_information']['contest'] = array(
    '#type' => 'textfield',
    '#title' => t('Contest link.'),
    '#size' => 50,
    '#description' => t('Enter the title of the contest link.'),
    '#default_value' => $pw_general['contest'], //'#default_value' => variable_get('pw_facebook_link', 'http://www.facebook.com/profile.php?id=728375773'),
  );

  $form['pennywise_contact_information']['facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook link.'),
    '#size' => 50,
    '#description' => t('Include full link address. This means <strong>http://</strong>. '),
    '#default_value' => $pw_general['facebook'], //'#default_value' => variable_get('pw_facebook_link', 'http://www.facebook.com/profile.php?id=728375773'),
  );

  $form['pennywise_contact_information']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter link.'),
    '#size' => 50,
    '#description' => t('Include full link address. This means <strong>http://</strong>. '),
    '#default_value' => $pw_general['twitter'], //'#default_value' => variable_get('pw_twitter_link', 'http://www.twitter.com'),
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
function pennywise_general_settingsform_submit($form, &$form_state) {
//  dpm($form_state);

  variable_set('pennywise_general_contact_settings', $form_state['values']);

 // $email = $form_state['values']['default_email'];
 // $disable_submission = $form_state['values']['online_submissions'];
 //
 // variable_set('pennywise_classified_settings_email', $email);
 // variable_set('pennywise_classified_settings_submissions', $disable_submission);

  drupal_set_message( t('Your settings have been updated.') );



}

