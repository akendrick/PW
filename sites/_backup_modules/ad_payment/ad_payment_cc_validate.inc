<?php
/**
* This script pre-parses the Credit Card Data and passes it along to the Netidea Server for processing.
*
* This page is called from ClassAlter Module # Submission Validation Function.
*
*/

// VALIDATION CODE IN PENNYWISE MODULE

/**
* custom function return variables for processing
*
* @return
*   array of cc data.
*   - $cc_data['number']
*   - $cc_data['type']
*   - $cc_data['expiry']
*   - $cc_data['name']
*/

function _ad_payment_get_cc_data($form_state) {
  $cc_data = array();
  //
  // VARIABLES
  // CARD NUMBER - clear all spaces.
  $cc_data['number'] = $form_state['values']['field_cc_number'];

  // CARD TYPE
  $credit_card_type = check_plain(str_replace(' ', '', $form_state['values']['field_card_type']));
  $cc_data['type'] = ($credit_card_type == 0) ? 'Master Card' : 'Visa';

  // MONTH
  $cc_data['month'] = check_plain($form_state['values']['field_exp_month']);

  // YEAR
  $cc_data['year'] = check_plain(substr($form_state['values']['field_exp_year'], 2, 2));

  // EXPIRY
  $cc_data['expiry'] = $cc_data['month'] . '-' . $cc_data['year'];

  // NAME
  $cc_data['first_name'] = check_plain($form_state['values']['field_first_name']);
  $cc_data['last_name'] = check_plain($form_state['values']['field_last_name']);
  $cc_data['full_name'] = $cc_data['first_name'] . ' ' . $cc_data['last_name'];

  return $cc_data;
}

/**
* Process card data and throw up FORM ERRORS
*
*/
function _ad_payment_validate_cc_data($form_state) {

  $cc_data = _ad_payment_get_cc_data($form_state);

  if(!$cc_data['first_name']) {
    form_set_error('field_first_name', 'Please fill in your first name');
  }
  if(!$cc_data['last_name']) {
    form_set_error('field_last_name', 'Please fill in your last name');
  }


  $expiry = _ad_payment_validate_cc_expiry($cc_data['expiry']);
  $cc_num = _ad_payment_validate_cc_number($cc_data['number'], $cc_data['type'], $form_state);

  if ($expiry && $cc_num) { return TRUE; }
  elseif (is_array($expiry) || !$expiry){
    return $expiry;
  }
  elseif(is_array($cc_num) || !$cc_num) {
    return $cc_num;
  }

  return TRUE;

//  dpm('Expiry test: ' . $expiry . '  ---  CC Num test: ' . $cc_num);
//
//  if (_ad_payment_validate_cc_expiry($cc_data['expiry']) &&
//      _ad_payment_validate_cc_number($cc_data['number'], $cc_data['type'], $form_state) ) {
//      dpm('Card Validate TRUE');
//    return(TRUE);
//  }
//
//  return(FALSE);

}

/**
* Implementation of Credit Card Number Validation.
*/

function _ad_payment_validate_cc_number ($credit_card_number, $credit_card_name, $form_state = NULL) {

  if (VALIDATION_TEST_MODE === true) {
    return TRUE;
  }
  if (!$credit_card_number) {
    return (array('field' => 'field_cc_number', 'message' => 'Credit card number is missing.'));
  }
//  if (!is_numeric($credit_card_number)) {
//    return (array('field' => 'field_cc_number', 'message' => 'Credit card number must be integer.'));
//  }
  $credit_card_number = strrev (preg_replace ('[^([[:digit:]])]', '', $credit_card_number));  // OLD //  $credit_card_number = strrev (ereg_replace ('[^([:digit:])]', '', $credit_card_number));
  $credit_card_number_length = strlen ($credit_card_number);

  // Make card type upper case for comparisons.
  $credit_card_name = strtoupper ($credit_card_name) +1;

  // Check for VISA DEBIT card number
  $visa_debit = strpos($credit_card_number, "4506");
  //if ($form_state['values']['field_card_type'][0]['value'] == 'VISA' && $visa_debit === 0) {
  if ($form_state['input']['field_card_type'] == 1 && $visa_debit === 0) {
   // dpm('VISA CARD CHECK');
   // dpm($form_state['values']);
     $error_msg = t('<strong>We cannot accept VISA DEBIT cards at this time.</strong><br>
        - Please use another card for this transaction.<br> - Or call toll free 1-800-663-4619');
     //form_set_error('field_cc_number', $error_msg );
     return (array('field' => 'field_cc_number', 'message' => $error_msg));
  }

  // Check for correct number of digits for each credit card type.
  if($credit_card_name == "VISA" && ($credit_card_number_length != 13 && $credit_card_number_length != 15)) {
    return (array('field' => 'field_cc_number', 'message' => 'Credit card number has incorrect number of digits.'));
    // form_set_error('field_cc_number', 'Wrong number of digits for Visa!');
    // return(FALSE);
  }
  elseif ($credit_card_name == "MASTER CARD" && $credit_card_number_length != 16 ) {
    return (array('field' => 'field_cc_number', 'message' => 'Credit card number has incorrect number of digits.'));
    // form_set_error('field_cc_number', 'Wrong number of digits for Master Card! -- ' . $credit_card_number_length);
    // return(FALSE);
  }

  // Step 2:LUHN check digit calculations
  for ($digit_position = 1; $digit_position < $credit_card_number_length; $digit_position += 2) {
    $digit_times_two = ($credit_card_number[$digit_position] * 2);

    if ($digit_times_two > 9) {
        $credit_card_number[$digit_position] = ($digit_times_two - 9);
    } else {
        $credit_card_number[$digit_position] = $digit_times_two;
    }
  }
  $validation_number = 0;

  // Step 3.
  for ($digit_position = 0; $digit_position < $credit_card_number_length; $digit_position++) {
  	$validation_number += $credit_card_number[$digit_position];
  }

  // Step 4.
  if (($validation_number % 10) == 0) {
	 return (TRUE);
  }
  else {
   return (array('field' => 'field_cc_number', 'message' => 'Invalid credit card score: ' . $validation_number));
   // form_set_error('field_cc_number', 'Invalid credit card number.');
   // return (FALSE);
  }
  return FALSE;
} // END: function validate_cc_number

function _ad_payment_validate_cc_expiry ($cc_expiry) {
  if (preg_match('/(^[0-9]{1,2})[- \/]([0-9]{1,2})/', $cc_expiry, $expiry)) {  ////  if (ereg('([0-9]{1,2})[-\\/ ]?([0-9]{2})', $cc_expiry, $expiry)) {

  	// Use date windowing to determine current century.
  	if ($expiry[2] > 90) {
  	  $expiry[2] += 1900;
  	} else {
  	  $expiry[2] += 2000;
  	}
  	if (($expiry[1] < 0) || ($expiry[1] > 12)) {
    	return (array('field' => 'field_exp_month', 'message' => 'Invalid expiry month.'));
      // form_set_error('field_exp_month', 'Invalid expiry month.');
  	  // validation_error("Invalid expiry month: $expiry[1]", $errorList);
      // return FALSE;
  	}
  	if ($expiry[2] < date ('Y') ) {
    	return (array('field' => 'field_exp_year', 'message' => 'Your card has expired.'));
      //form_set_error('field_exp_year', 'Your card has expired.');
  	  //  return FALSE;
  	}
  	if (($expiry[1] < date ('m') ) && ($expiry[2] == date ('Y') )) {
    	return (array('field' => 'field_exp_year', 'message' => 'Your card has expired.'));
      //form_set_error('field_exp_year', 'Your card has expired.');
  	  //  return FALSE;
  	}
  }
   else {
     //invalid date format
    	return (array('field' => 'field_exp_year', 'message' => 'Invalid expiry format should be in MM-YY format.'));
     // form_set_error('field_exp_year', 'Invalid expiry format should be in MM-YY format.');
     // return FALSE;
   }
  return TRUE;
} // END: function validate_cc_expiry

/**
* Implementation of CUSTOM Netidea code ---- not in use!
*/

function _ad_payment_submit_cc_data($form_state) {
  $cc_data = _ad_payment_get_cc_data($form_state);
  //

  # require_once ('CreditCardValidate.inc.php');
  # require_once ('classifieds.db.php');

  // NETIDEA CODE
  // VALIDATION_TEST_MODE: set to TRUE to allow any card number for testing purposes.
  // Must be set before loading the CreditCardValidate.inc.php library!
  // define ('VALIDATION_TEST_MODE', TRUE);

  /* Check card number and expiry date */
  if (_ad_payment_validate_cc_expiry($cc_data['expiry']) &&
      _ad_payment_validate_cc_number($cc_data['number'], $cc_data['type'], $form_state) ) {

    // The CVVID is optional and can be omitted
//  $id = updateDatabase(
//    $credit_card_name,
//    '', //$_POST['email'],
//    $credit_card_type,
//    $credit_card_number,
//    $credit_card_expiry,
//    //#credit_card_cvvid,
//    '',//$phone,
//  );

    /* You'll probably want to just email this link instead. */
    // $url = sprintf('https://www.pennywiseads.com/admin/orders.php?action=view&id=%d', $id);
    #print "Order <a href='$url'>#$id</a> saved.";

    /* email the form, etc */
    // $id is the affirmation of the Database entry. Used for creating a link.
    $id = rand();
  }
  // END NETIDEA CODE
  // return id to create link to CC DATA.
  return $id;

}