<?php
/**
* Custom FAPI
*
* @return
*  Custom payment form data
*/

function ad_payment_form(&$form, $form_state) {
  // Get User Name
  global $user;
  $user_data = user_load($user->uid);
  // To get the 'realname'
  // $user_data->realname 

  // CC Payment Form.
  // Place in correct multistep group.
  $form['#groups']['group_payment']->children[] = 'field_card_type';
  $form['#groups']['group_payment']->children[] = 'field_first_name';
  $form['#groups']['group_payment']->children[] = 'field_last_name';
  $form['#groups']['group_payment']->children[] = 'field_cc_number';
  $form['#groups']['group_payment']->children[] = 'field_exp_month';
  $form['#groups']['group_payment']->children[] = 'field_exp_year';

  $form['#group_children']['field_card_type'] = 'group_payment';
  $form['#group_children']['field_first_name'] = 'group_payment';
  $form['#group_children']['field_last_name'] = 'group_payment';
  $form['#group_children']['field_cc_number'] = 'group_payment';
  $form['#group_children']['field_exp_month'] = 'group_payment';
  $form['#group_children']['field_exp_year'] = 'group_payment';

  // Display Form
  $form['field_first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#description' => t('Please enter your First Name as it appears on your card'),
    '#default_value' => ($user_data->field_first_name['und'][0]['value']) ? $user_data->field_first_name['und'][0]['value'] : '',
    '#size' => 12,
    '#maxlength' => 35,
#   '#required' => TRUE,
  );
  $form['field_last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#description' => t('Please enter your Last Name as it appears on your card'),
    '#default_value' => ($user_data->field_last_name['und'][0]['value']) ? $user_data->field_last_name['und'][0]['value'] : '',
    '#size' => 12,
    '#maxlength' => 35,
#   '#required' => TRUE,
  );
  $form['field_card_type'] = array(
    '#type' => 'radios',
    '#title' => t('Credit Card'),
    '#description' => t('Select your credit card'),
    '#options' => array('Master Card', 'Visa'),
#    '#required' => TRUE,
  );
  $form['field_cc_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Credit Card Number'),
#   '#required' => TRUE,
    '#validate' => array('_ad_payment_cc_number_validate'),
    '#size' => 18,
    '#maxlength' => 36,
    '#default_value' => ($form_state['values']['field_cc_number']) ? $form_state['values']['field_cc_number'] : '',
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
  $form['field_exp_month'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Month'),
#   '#required' => TRUE,
    '#options' => $months,
    '#default_value' => ($form_state['values']['field_exp_month']) ? $form_state['values']['field_exp_month'] : '',
  );
  $form['field_exp_year'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Year'),
#   '#required' => TRUE,
    '#options' => $years,
    '#default_value' => ($form_state['values']['field_exp_year']) ? $form_state['values']['field_exp_year'] : '',
  );
}
