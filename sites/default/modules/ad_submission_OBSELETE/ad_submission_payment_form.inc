<?php
/**
* Custom FAPI
*
* @return
*  Custom payment form data
*/

function ad_submission_payment_form(&$form, &$form_state) {
// Hide Ad Data

// Modify '#weight' of existing form.
  $form['#groups']['group_ad']->weight = -15;
  $form['#groups']['group_upgrade']->weight = -10;

//
// Custom CC# Form data
//
  $form['#validate'][] = 'ad_submission_ad_payment_validation';

  $form['group_payment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Payment Information'),
    '#description' => t('Enter your payment information'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['group_payment']['field_card_type'] = array(
    '#type' => 'radios',
    '#title' => t('Credit Card'),
    '#description' => t('Select your credit card'),
    '#options' => array('Master Card', 'Visa'),
    '#default_value' => check_plain($form_state['values']['field_card_type']),
#    '#required' => TRUE,
  );
  $form['group_payment']['field_first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#description' => t('Please enter your First Name as it appears on your card'),
#   '#required' => TRUE,
    '#default_value' => check_plain($form_state['values']['field_first_name']),
    '#size' => 12,
    '#maxlength' => 35,
  );
  $form['group_payment']['field_last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#description' => t('Please enter your Last Name as it appears on your card'),
#   '#required' => TRUE,
    '#default_value' => check_plain($form_state['values']['field_last_name']),
    '#size' => 12,
    '#maxlength' => 35,
  );
  $form['group_payment']['field_cc_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Credit Card Number'),
#   '#required' => TRUE,
#   '#validate' => array('classalter_cc_number_validate'),
    '#default_value' => check_plain($form_state['values']['field_cc_number']),
    '#size' => 18,
    '#maxlength' => 36,
    '#attributes' => array('autocomplete' =>'off'),
  );
  $months = array(
    '00' => 'Select Month',
    '01' => '01 - January',
    '02' => '02 - February',
    '03' => '03 - March',
    '04' => '04 - April',
    '05' => '05 - May',
    '06' => '06 - June',
    '07' => '07 - July',
    '08' => '08 - August',
    '09' => '09 - September',
    '10' => '10 - October',
    '11' => '11 - November',
    '12' => '12 - December',
  );
  $years = array(
    '0000' => 'Select Year',
    '2011' => 2011,
    '2012' => 2012,
    '2013' => 2013,
    '2014' => 2014,
    '2015' => 2015,
    '2016' => 2016,
    '2017' => 2017,
    '2018' => 2018,
  );
  $form['group_payment']['field_exp_month'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Month'),
#   '#required' => TRUE,
    '#options' => $months,
    '#default_value' => check_plain($form_state['values']['field_exp_month']),
  );
  $form['group_payment']['field_exp_year'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Year'),
#   '#required' => TRUE,
    '#options' => $years,
    '#default_value' => check_plain($form_state['values']['field_exp_year']),
  );

}