<?php
/**
* Custom FAPI
*
* @return
*  Custom payment form data
*/

function ad_payment_form(&$form, $form_state) {
  // FREE FOR FREE
  $free4free = '
      <h1 class="free-for-free-link-box box-1 grid-5 alpha">
<a href="mailto:info@pennywiseads.com?subject=Submit FREE for FREE ad&body=Free For Free Ad. %0A%0A%0A%0A%0A
############        FREE for FREE Guidelines       ############ %0A
Please use 15 - 25 words to describe your one personal item per Free for Free ad.%0A
Such as: Puppies FREE to good home; or FREE pink floral couch; or FREE 2 wheel bike ideal fit for 8 year old. %0A
Please don\'t post services, free estimates, buy 3 get 1 free, or free rides to polling station." class="free-ad-link ">
     Submit <span class="free">FREE</span> for <span class="free">FREE</span> Classified <span class="click">Click Here</span>
</a>
      </h1>
      <div class="grid-10 preface-1 omega alpha">
        <h4>Save our Landfills <br> Share your Treasure!</h4>
        <p class="free-for-free-yes-list ">
         Please use 15 - 25 words to describe your one personal item per Free for Free ad.
          <ul>
            <li>Bunkbeds FREE to good home</li>
            <li>FREE pink floral couch</li>
            <li>FREE 2 wheel bike will fit 8 year old</li>
          </ul>
        </p>
        <p class=" free-for-free-no-list ">
          Please don\'t post services in FREE for FREE such as free estimates, no free rides to polling station, or buy 3 get 1 free.
        </p>
      </div> ';

  $form['#groups']['group_free_for_free'] = 'form';
  $form['#group_children']['free_box_link'] = 'group_free_for_free';

  $form['free_box_link'] = array(
    '#type' => 'fieldset',
    '#weight' => 80,
  );
  $form['free_box_link']['free'] = array(
    '#weight' => 80,
    '#prefix' => '<div class="grid-15 alpha omega">',
    '#markup' => $free4free,
    '#suffix' => '</div>',
  );

  // Get User Name
  global $user;
  $user_data = user_load($user->uid);

  // Determine User Role
//  if (user_access('edit any ad_s content') && !DEBUG){
//    $access = FALSE;
//    $required = FALSE;
//    dpm(' Access removed your need to enter CC data.');
//  }
//  else {
  $access = TRUE;
  $required = TRUE;
//  }

  // Get Form State data - if any
  if ($form_state && isset($form_state['values'])) {
    $cc_number = $form_state['values']['field_cc_number'];
    $cc_month  = $form_state['values']['field_exp_month'];
    $cc_year   = $form_state['values']['field_exp_year'];
  }
  else {
    $cc_number = '';
    $cc_month  = '';
    $cc_year   = '';
  }

  // CC Payment Form.
  // Place in correct multistep group.
  $form['#groups']['group_payment']->children[] = 'form';
//  $form['#groups']['group_payment']->children[] = 'field_card_type';
//  $form['#groups']['group_payment']->children[] = 'field_first_name';
//  $form['#groups']['group_payment']->children[] = 'field_last_name';
//  $form['#groups']['group_payment']->children[] = 'field_cc_number';
//  $form['#groups']['group_payment']->children[] = 'field_exp_month';
//  $form['#groups']['group_payment']->children[] = 'field_exp_year';

  $form['#group_children']['card'] = 'group_payment';

//  $form['#group_children']['field_card_type']  = 'group_payment';
//  $form['#group_children']['field_first_name'] = 'group_payment';
//  $form['#group_children']['field_last_name']  = 'group_payment';
//  $form['#group_children']['field_cc_number']  = 'group_payment';
//  $form['#group_children']['field_exp_month']  = 'group_payment';
//  $form['#group_children']['field_exp_year']   = 'group_payment';

// Display Form
  $form['card'] = array(
    '#type' => 'fieldset',
    '#access' => $access,
    '#required' => TRUE,
    '#description' => t('This form is encrypted for your protection.'),
    '#title' => t('Credit Card Information'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#weight' => -20,
  );

  $form['card']['field_first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#description' => t('Please enter your First Name as it appears on your card'),
    '#default_value' => ($user_data && $user_data->field_first_name && $user_data->field_first_name['und'][0]['value']) ? $user_data->field_first_name['und'][0]['value'] : '',
    '#size' => 12,
    '#maxlength' => 35,
    '#required' => $required,
    '#access' => $access,
    '#weight' => -30,
  );
  $form['card']['field_last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
//    '#description' => t('Please enter your Last Name as it appears on your card'),
    '#default_value' => ($user_data && $user_data->field_last_name && $user_data->field_last_name['und'][0]['value']) ? $user_data->field_last_name['und'][0]['value'] : '',
    '#size' => 12,
    '#maxlength' => 35,
    '#required' => $required,
    '#access' => $access,
    '#weight' => -28,
  );

//  $form['field_email'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Email'),
//    '#description' => t('Please enter your Last Name as it appears on your card'),
//    '#default_value' => ($user_data && $user_data->field_last_name && $user_data->field_last_name['und'][0]['value']) ? $user_data->field_last_name['und'][0]['value'] : '',
//    '#size' => 12,
//    '#maxlength' => 35,
//    '#required' => $required,
//    '#access' => $access,
//  );

  $form['card']['field_card_type'] = array(
    '#type' => 'radios',
    '#title' => t('Credit Card'),
    '#description' => t('Select your credit card'),
    '#options' => array('Master Card', 'Visa'),
    '#required' => TRUE,
    '#access' => $access,
    '#weight' => 20,
  );
  $form['card']['field_cc_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Credit Card Number'),
    '#validate' => array('ad_payment_cc_number_validate'),
    '#size' => 26,
    '#maxlength' => 36,
    '#default_value' => $cc_number,
    '#attributes' => array('autocomplete' =>'off'),
    '#required' => $required,
    '#access' => $access,
    '#weight' => 30,
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
  $form['card']['field_exp_month'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Month'),
    '#options' => $months,
    '#default_value' => $cc_month,
    '#required' => $required,
    '#access' => $access,
    '#weight' => 35,
  );
  $form['card']['field_exp_year'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Year'),
    '#options' => $years,
    '#default_value' => $cc_year,
    '#required' => $required,
    '#access' => $access,
    '#weight' => 40,
  );
}
