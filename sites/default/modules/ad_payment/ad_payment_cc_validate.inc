<?php
/**
*
* This page is called from ad_payment_cc_validate
*
* @var $form_state_values
* - submitted form state values
*
* @return
* - array of errors and corresponding field names for form_set_error().
*/
function ad_payment_validate_cc_data($form_state_values = NULL) {
  if (CC_VALIDATION_MODE == TRUE) {
    return;
 }

  // VARIABLES

  // CARD TYPE
  // Determine Card Type.
  if(isset($form_state_values['field_card_type'])) {
   switch ($form_state_values['field_card_type']) {
     case 1:
       $cc_name = 'VISA';
       break;
     case 0:
       $cc_name = 'MASTER CARD';
       break;
    default:
      $form_validation['field_card_type'] = 'Please select your credit card type.';
      $form_errors['field_card_type'] = 'Error #001-A1-' . $form_state_values['field_card_type'] . '-NA';
      break;
   }
  }
  else {
    $form_validation['field_card_type'] = 'Please select your credit card type.';
    $form_errors['field_card_type'] = 'Error #001-A2-' . $form_state_values['field_card_type'] . '-NA';
  }

  // MONTH
  $cc_month = check_plain($form_state_values['field_exp_month']);
  if (!isset($cc_month) || $cc_month == NULL || $cc_month == '00') {
    $form_validation['field_exp_month'] = 'Invalid expiry month.';
    $form_errors['field_exp_month'] = 'Error #100-B' . $form_state_values['field_card_type'] . '-' . $cc_month;
  }

  // YEAR
  $cc_year = check_plain(substr($form_state_values['field_exp_year'], 2, 2));
  if (isset($cc_year)) {
  	if ($cc_year > 90) {
  	  $cc_year += 1900;
  	} else {
  	  $cc_year += 2000;
  	}

    // EXPIRY
  	// Use date windowing to determine current century.
  	if ($cc_year < date ('Y') ) {
    	$form_validation['field_exp_year'] =  'Your card has expired.';
    	$form_errors['field_exp_year'] = ' Error #200-CA' . $form_state_values['field_card_type'] . '-' . $cc_month . $cc_year;
  	}
  	elseif (($cc_month < date ('m') ) && ($cc_year == date ('Y') )) {
    	$form_validation['field_exp_year'] = 'Your card has expired.';
    	$form_errors['field_exp_year'] = ' Error #200-CB' . $form_state_values['field_card_type'] . '-' . $cc_month . $cc_year;
  	}
  }
  else {
    $form_validation['field_exp_year'] = 'Invalid expiry year.';
    $form_errors['field_exp_year'] = ' Error #300-D' . $form_state_values['field_card_type'] . '-' . $cc_year;
  }

  // NAME
  $cc_first_name = check_plain($form_state_values['field_first_name']);
  if(!isset($cc_first_name)) {
    $form_validation['field_first_name'] = 'Please fill in your first name.';
    $form_errors['field_first_name'] = 'Missing first name.';
  }

  $cc_last_name  = check_plain($form_state_values['field_last_name']);
  if(!isset($cc_last_name)) {
    $form_validation['field_last_name'] = 'Please fill in your last name.';
    $form_errors['field_last_name'] = 'Missing last name.';
  }

  // CARD NUMBER
  $cc_number = $form_state_values['field_cc_number'];
  if (isset($cc_number)) {
    // Check for VISA DEBIT card number
    $visa_debit = strpos($cc_number, "4506");
    if (isset($cc_name) == 'VISA' && $visa_debit === 0) {
       $error_msg = t('<strong>We cannot accept VISA DEBIT cards at this time.</strong><br>
          - Please use another card for this transaction.<br> - Or call toll free 1-800-663-4619');
      $form_validation['field_cc_number'] = $error_msg;
      $form_errors['field_cc_number'] = 'Visa Debit Error';
    }

    // Length -- clear all spaces.
    // Strip any non-digits (useful for credit card numbers with spaces and hyphens)
    $cc_number = preg_replace(array('/\s+/', '/\D/'), '', $cc_number);

    $cc_number_length = strlen( $cc_number );
    if ($cc_number_length != 16 ) {
      $form_validation['field_cc_number'] = 'Credit card number has incorrect number of digits. ';
      $form_errors['field_cc_number'] = 'Error #100-L' . $form_state_values['field_card_type'] . '-' . $cc_number_length;
    }

    /* Luhn algorithm number checker - (c) 2005-2008 shaman - www.planzero.org *
   * This code has been released into the public domain, however please      *
   * give credit to the original author where possible.                      */

    // Set the string length and parity
    $parity=$cc_number_length % 2;

    // Loop through each digit and do the maths
    $total=0;
    for ($i=0; $i<$cc_number_length; $i++) {
      $digit=$cc_number[$i];
      // Multiply alternate digits by two
      if ($i % 2 == $parity) {
        $digit*=2;
        // If the sum is two digits, add them together (in effect)
        if ($digit > 9) {
          $digit-=9;
        }
      }
      // Total up the digits
      $total+=$digit;
    }
    // If the total mod 10 equals 0, the number is valid
    if ($total % 10 != 0) { // ? TRUE : FALSE;
      $form_validation['field_cc_number'] = 'Please check your credit card number and try again.';
      $form_errors['field_cc_number'] = 'Error #300-E' . $form_state_values['field_card_type'] . '-' . $cc_number_length . '-' . ($total % 10) ;
    }
  }
  else {
    $form_validation['field_cc_number'] = 'Credit card number is missing.';
  }



  // VALIDATE RATE
  // Get Section Rating
  $submitted_rate = ($form_state_values['field_rate'][LANGUAGE_NONE][0]['value'] == 'Business') ? TRUE : FALSE;

  if(isset($form_state_values['field_tags'][LANGUAGE_NONE][0]['tid'])){
    foreach ($form_state_values['field_tags'][LANGUAGE_NONE] as $sect) {
      $term = taxonomy_term_load($sect['tid']);
      $term_rate = $term->field_business_rated[LANGUAGE_NONE][0]['value'];
      if ($term_rate != $submitted_rate && $term_rate == TRUE) {
        $form_validation['field_tags'] = $term->name . 'is a Business Rated classification.<br>To update your ad:
         <ol><li>Select "<strong>Create Classified Ad</strong>" from the side menu.
         <li>Change your ad to "Business" rated <br/>or choose a different section for your ad to appear in.</ol>';
         $form_errors['field_tags'] = 'Error #400-T-' . $sect['tid'];
      }
    }
  }
  else {
    // No Rate submitted but rate form validation is handeled elsewhere.
    // $form_validation['field_rate'] = 'Please your classification section.';
    // $form_errors['field_rate'] = 'Error #350-NullRate';
  }

  if (ADP_LOG_ERRORS || ADP_LOG_ERRORS_CC) {
    // drupal_set_message('Form State Values', 'adp');

    $type = 'Ad Payment';
    $message = t('Submission Error <br> Logged By @name <br>Username: @username - UID: @uid<br> <br>Email: @email <br>Phone: @phone<br><br>',
      array(
        '@name' => $form_state_values['field_first_name'] . ' ' . $form_state_values['field_last_name'],
        '@username' => $form_state_values['name'],
        '@uid' => $form_state_values['uid'],
        '@email' => $form_state_values['field_email'][LANGUAGE_NONE][0]['email'],
        '@phone' => $form_state_values['field_phone'][LANGUAGE_NONE][0]['number'],
        )
      );
    if (isset($form_validation)) {
      $errors = array();
      foreach ($form_validation as $key => $error) {
        $message .= '[' . $key . '] => ' . $error;
        $errors[$key] = $error . ' ' . $form_errors[$key];
      }
      unset($form_validation);
    }
    watchdog($type, $message);

  }


  if (isset($errors)) {
    return $errors;
  }
  else if (isset($form_validation)) {
    return $form_validation;
  }
  else {
    return FALSE;
  }
}

