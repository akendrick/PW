<?php
/**
* Custom FAPI
*
* @return
*  Custom payment form data
*/

function ad_payment_form(&$form, $form_state) {
  // FREE FOR FREE
//   $free4free = '
//       <h1 class="free-for-free-link-box box-1 grid-5 alpha">
// <a href="mailto:info@pennywiseads.com?subject=Submit FREE for FREE ad&body=Free For Free Ad. %0A%0A%0A%0A%0A
// ############        FREE for FREE Guidelines       ############ %0A
// Please use 15 - 25 words to describe your one personal item per Free for Free ad.%0A
// Such as: Puppies FREE to good home; or FREE pink floral couch; or FREE 2 wheel bike ideal fit for 8 year old. %0A
// Please don\'t post services, free estimates, buy 3 get 1 free, or free rides to polling station." class="free-ad-link ">
//      Submit <span class="free">FREE</span> for <span class="free">FREE</span> Classified <span class="click">Click Here</span>
// </a>
//       </h1>
//       <div class="grid-10 preface-1 omega alpha">
//         <h4>Save our Landfills <br> Share your Treasure!</h4>
//         <p class="free-for-free-yes-list ">
//          Please use 15 - 25 words to describe your one personal item per Free for Free ad.
//           <ul>
//             <li>Bunkbeds FREE to good home</li>
//             <li>FREE pink floral couch</li>
//             <li>FREE 2 wheel bike will fit 8 year old</li>
//           </ul>
//         </p>
//         <p class=" free-for-free-no-list ">
//           Please don\'t post services in FREE for FREE such as free estimates, no free rides to polling station, or buy 3 get 1 free.
//         </p>
//      </div> ';

//  $form['#groups']['group_free_for_free'] = 'form';
//  $form['#group_children']['free_box_link'] = 'group_free_for_free';


  // Get User Name
  // global $user;
  // $user_data = user_load($user->uid);

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

// Display Form
//  $form['card'] = array(
//    '#type' => 'fieldset',
//    '#access' => $access,
//    '#required' => TRUE,
//    '#description' => t('This form is encrypted for your protection.'),
//    '#title' => t('Credit Card Information'),
//    '#collapsible' => FALSE,
//    '#collapsed' => FALSE,
//    '#weight' => -20,
//  );

  $form['group_name'] = array(
    '#type' => 'fieldset',
    '#description' => t('Please enter your name as it appears on your card'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#title'  => t('Name'),
    '#attributes' => array('class' => array('payment-form', 'group-name')),
  );

  $form['group_name']['field_first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
//    '#description' => t('Please enter your First Name as it appears on your card'),
//    '#default_value' => ($user_data && $user_data->field_first_name && $user_data->field_first_name['und'][0]['value']) ? $user_data->field_first_name['und'][0]['value'] : '',
    '#size' => 12,
    '#maxlength' => 35,
    '#required' => $required,
    '#access' => $access,
/*     '#weight' => -60, */
  );
  $form['group_name']['field_last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
//    '#description' => t('Please enter your Last Name as it appears on your card'),
//    '#default_value' => ($user_data && $user_data->field_last_name && $user_data->field_last_name['und'][0]['value']) ? $user_data->field_last_name['und'][0]['value'] : '',
    '#size' => 12,
    '#maxlength' => 35,
    '#required' => $required,
    '#access' => $access,
/*     '#weight' => -50, */
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

  $form['group_card'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#title'  => t('Credit Card'),
    '#attributes' => array('class' => array('payment-form', 'group-card')),
  );
  $form['group_card']['field_card_type'] = array(
    '#type' => 'radios',
    '#title' => t('Credit Card'),
/*     '#description' => t('Select your credit card'), */
    '#options' => array('Master Card', 'Visa'),
    '#required' => TRUE,
    '#access' => $access,
/*     '#weight' => 200, */
  );
  $form['group_card']['field_cc_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Credit Card Number'),
    '#validate' => array('ad_payment_cc_number_validate'),
    '#size' => 26,
    '#maxlength' => 36,
    '#default_value' => $cc_number,
    '#attributes' => array('autocomplete' =>'off'),
    '#required' => $required,
    '#access' => $access,
    '#weight' => 0,
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
    '2014' => 2014,
    '2015' => 2015,
    '2016' => 2016,
    '2017' => 2017,
    '2018' => 2018,
    '2019' => 2019,
    '2020' => 2020,
    '2021' => 2021,
    '2022' => 2022,
  );
  $form['group_expiry'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#title'  => t('Expiry Date'),
    '#attributes' => array('class' => array('payment-form', 'group-expiry')),
  );
  $form['group_expiry']['field_exp_month'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Month'),
    '#options' => $months,
    '#default_value' => $cc_month,
    '#required' => $required,
    '#access' => $access,
/*     '#weight' => 220, */
  );
  $form['group_expiry']['field_exp_year'] = array(
    '#type' => 'select',
    '#title' => t('Expiry Year'),
    '#options' => $years,
    '#default_value' => $cc_year,
    '#required' => $required,
    '#access' => $access,
/*     '#weight' => 230, */
  );

  $form['field_review'] = array(
    '#type' => 'item',
/*     '#title' => t('Ad Review'), */
    '#description' => t('Click here to calculate price.'),
  );

  $form['#group_children']['group_name']  = 'group_payment';
  $form['#group_children']['group_card']  = 'group_payment';
  $form['#group_children']['group_expiry'] = 'group_payment';
  $form['#group_children']['field_review'] = 'group_review';

  // Add Contact info to bottom of form.
  $email = variable_get('pw_classified_settings_email', 'info@pennywiseads.com');
  $form['contact_info'] = array(
    '#title'  => t('Need Help?'),
    '#description' => variable_get('pennywise_classified_settings_help_message', t('Talk to us. <strong>1-800-663-4619</strong> Kaslo, BC Canada')) .
        '<a href="mailto:' . $email . '"> ' . $email . '</a>',
    '#type'   => 'item',
    '#weight' => '300',
  );
/*   $form['#group_children']['contact_info'] = 'group_more'; */
  $form['#group_children']['contact_info'] = 'group_more';


}
