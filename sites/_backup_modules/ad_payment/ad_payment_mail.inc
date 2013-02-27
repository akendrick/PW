<?php

/**
* @FILE
*
* Default email behaviour for Ad Payment Module
*/

/**
* Implementation of custom email implementor.
*/
function ad_payment_send_email($email_type, $details = NULL) {
  //dpm($details);
  global $user;

  // Set defaults
  $language = language_default();
  $send = TRUE;

  switch ($email_type) {
    case 'receipt':  // Customer Receipt
      $to = $user->mail;
      $from = variable_get('pw_email', 'k2@pennywiseads.com');
      $result = drupal_mail('ad_payment', 'receipt', $to, $language, $details, $from, $send);

      if ($result['result'] == TRUE) {
        drupal_set_message(t('A copy of this receipt has beed sent to your email address: @email.', array('@email' => $to)), 'status' );
      }
      else {
        watchdog('Ad Payment', 'Receipt Email Error',
          array('to' => $to, 'from' => $from, 'result' => $result, 'data' => $data), WATCHDOG_NOTICE);
      }
      break;

    case 'inhouse': // Inhouse Receipt
    default:
      $to = variable_get('pw_email_inhouse_receipt', 'info@pennywiseads.com');
      $from = $user->mail;  //variable_get('pw_email', 'info@pennywiseads.com');
      $result = drupal_mail('ad_payment', 'inhouse', $to, $language, $details, $from, $send);

      if ($result['result'] == TRUE) {
        // drupal_set_message(t('A copy of this receipt has beed sent to your email address.'), 'status' );
      }
      else {
        watchdog('Ad Payment', 'Inhouse Receipt Email Error', array('to' => $to, 'from' => $from, 'result' => $result, 'data' => $details), WATCHDOG_NOTICE);
      }

      break;
  }
}


/**
* Implementation of hook_mail
*/
function ad_payment_mail($key, &$message, $params) {

  $receipt_id = $message['params']['receipt'];

  switch($key) {
    case 'receipt':
      $message['body'][] = email_receipt_body($message);;
      $message['subject'] = 'Pennywise Ad Submission ' . $receipt_id;
      break;
    case 'inhouse':
      $message['body'][] = email_receipt_body($message);;
      $message['subject'] = 'Pennywise Ad IN HOUSE ' . $receipt_id;
      break;
  }

  if (DEBUG_ADP || DEBUG_EMAIL) {
    $debug_var = array(
      '@key' => $key,
      '@subject' => $message['subject'],
      '@body' => $message['body'][0],
    );
    $debug_msg = "KEY: @key <br> Triggered in ad_payment_mail.<br>
      SUBJECT: @subject<br>
      <p>BODY: <br>
      @body</p>";
    watchdog('Ad Payment - eMail', $debug_msg, $debug_vars, WATCHDOG_INFO);
  }
}


/**
* Custom Reciept Body Theme
*
* @TODO!!!!!!!!!!!!!!!!!!!!!!!!
*
* Email Receipt Details
* - Confirmation #
* - Thanks $user['real-name']
* - General Info on what happens next.
* - - Which paper it will appear in.
* - - When it will appear.
* - - Etc.
* - AD INFO
* - - Receipt #
* - - Placed by REAL NAME - EMAIL
* - - Mailing Address
* - - @TODO - View Ad/Ad progress
* - AD DETAILS
* - - AD copy
* - - Area
* - - Section
* - - Classification
* - - Duration
* - - Image: YES/NO
* - - Liveload: YES/NO
* - - Details
* - PAYMENT
* - - Sub-total
* - - Taxes
* - - Total
* - - CC Type
* - - Payment - Pending
* - - - (Why pending?) - details as to why.
*/
function email_receipt_body($message = NULL) {

  // Get ad submission details
  $ad = $message['params']['values'];
  $rate = $message['params']['rate'];

  // Basic Details
  $duration = $message['params']['duration']['actual'];
  $image = (isset($ad['image']))? 'Image: Received.' : '';
  $ad_copy = $ad['ad_copy'];

  $areas = $message['params']['values']['areas'];
  $area_count = $ad['area_count'];

  $rate = $ad['rate'];
  $rate_name = $rate['rate_name'];

  $section_count = $ad['section_count'];
  $section = $ad['sections'];

  // Payment Details
  $receipt_id = $message['params']['receipt'];
  $name = $ad['user']['real-name'];
  $card = $ad['user']['card-type'];
  $discount = (isset($message['params']['discount']))? ' (all area discount $' . abs($message['params']['discount'] * $message['params']['duration']['adjusted']) . ')' : '';
  $subtotal = $message['params']['subtotal'];
  $taxes = $message['params']['taxes'];
  $total = $message['params']['total'];

  // Set Message (if holiday)
  $standard_message = 'PLEASE NOTE:
  Live Load ads are given priority and will be processed as quickly as possible (during regular business hours).
  Regular ads placed before 3pm on Thursday will appear in the following Tuesday\'s print edition.';

  // Check to see is the holiday settings are set and get message.
  $holiday = variable_get('pennywise_holiday_settings', NULL);
  $message = ($holiday['holiday_settings'] > 1) ? $holiday['holiday_message_plain'] : $standard_message;


$reciept = <<<RECEIPT
Classified Ad Receipt #$receipt_id

Thank you for submitting your ad to PennywiseAds.com.
This email is your receipt and should be kept for your records.

DETAILS
Areas ($area_count): $areas
Section ($section_count): $section
Duration: $duration weeks
$image

AD COPY
$ad_copy

PAYMENT INFO
Submitted by: $name
Rate: $rate_name

Subtotal: $$subtotal $discount
Taxes:    $$taxes
Total:    $$total
Billed to $card.

CONTACT US
You can contact us 9am to 5pm Monday to Thursday (& until 4pm on Friday).
Toll free: 1-800-663-4619
Local: 250-353-2602
Email: info@pennywiseads.com
Address: Box 430,
         Kaslo BC
         Canada V0G 1M0

$message

Thank you for placing your ads with the Pennywise, we appreciate your business .

Sincerly,
The Pennywise Team.

RECEIPT;

#$message['subject'] = 'PennywiseAds.com ad submission #' . $receipt_id;
#$message['body'] = $reciept;

  if (DEBUG_ADP || DEBUG_EMAIL) {
    $debug_var = array(
      '@body' => $reciept,
    );
    $debug_msg = "Receipt Body<br>
      <p>BODY: <br>
      @body</p>";
    watchdog('Ad Payment - eMail', $debug_msg, $debug_vars, WATCHDOG_INFO);
  }

  return $reciept;
}