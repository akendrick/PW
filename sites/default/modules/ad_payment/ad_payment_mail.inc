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

  // dpm('DETAILS');
  // dpm($details);

  // Set defaults
  $language = language_default();
  $send = TRUE;

  switch ($email_type) {
    case 'receipt':  // Customer Receipt
      $to = $details['user']['email'];
      $from = variable_get('pw_email', 'k2@pennywiseads.com');
      $result = drupal_mail('ad_payment', 'receipt', $to, $language, $details, $from, $send);

      if ($result['result'] == TRUE) {
        drupal_set_message(t('A copy of this receipt has been sent to your email address: @email.', array('@email' => $to)), 'status' );
      }
      else {
        $message = 'Receipt Error <br><br>To: @to<br>From: @from<br>@result<br>@data<br><br> Logged by <b>ad_payment_send_email</b> in <em>ad_payment_mail.inc</em>';
        watchdog('ADP Email', $message,
          array('@to' => $to, '@from' => $from, '@result' => $result, '@data' => $data), WATCHDOG_NOTICE);
      }
      break;

    case 'inhouse': // Inhouse Receipt
    default:
      $to = variable_get('pw_email_inhouse_receipt', 'info@pennywiseads.com');
      $from = $details['user']['email'];
      $result = drupal_mail('ad_payment', 'inhouse', $to, $language, $details, $from, $send);

      if ($result['result'] == TRUE) {
        //  drupal_set_message(t('A copy of this receipt has been sent to your @email address.', array('@email' => $from)), 'status' );
      }
      else {
        drupal_set_message(t('Unable to send your receipt to your @email address.', array('@email' => $from)), 'status' );
        $message = 'INHOUSE Error <br><br>To: @to<br>From: @from<br>@result<br>@data<br><br> Logged by <b>ad_payment_send_email</b> in <em>ad_payment_mail.inc</em>';
        watchdog('ADP Email', $message,
          array('to' => $to, 'from' => $from, 'result' => $result, 'data' => $details), WATCHDOG_NOTICE);
      }

      break;
  }
}


/**
* Implementation of hook_mail
*/
function ad_payment_mail($key, &$message, $params) {
  $receipt_id = (isset($message['params']['receipt'])) ? $message['params']['receipt'] : $params['receipt'] ;

  $ad_type = ($message['params']['ad_type'] == TRUE) ? '### LIVELOAD ### ' : 'Classified Ad';

  switch($key) {
    case 'receipt':
      $message['body'][] = email_receipt_body($message);
      $message['subject'] = 'Pennywise Ad Submission ' . $receipt_id;
      break;
    case 'inhouse':
      $message['body'][] = email_receipt_body($message);
      $message['subject'] = $ad_type . 'Pennywise Ad ' . $receipt_id;
      break;
  }

//  if (ADP_LOG_ERRORS) {
//    $debug_var = array(
//      '@key' => $key,
//      '@subject' => $message['subject'],
//      '@body' => $message['body'][0],
//    );
//    $debug_msg = "KEY: @key <br> Triggered in ad_payment_mail.<br>
//      SUBJECT: @subject<br>
//      <p>BODY: <br>
//      @body</p>";
//    watchdog('ADP - Email Body', $debug_msg, $debug_var, WATCHDOG_INFO);
//  }
}


/**
* Custom receipt Body Theme
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
* - - Subtotal
* - - Extras
* - - Taxes
* - - Total
* - - CC Type
* - - Payment - Pending
* - - - (Why pending?) - details as to why.
*/
function email_receipt_body($params = NULL) {
  // dpm('EMAIL Body');
  // dpm($params);
  // Get ad submission details
  $ad = $params['params'];
  // $rate = $message['params']['rate'];
  //dpm('Email Body Params');

  // Basic Details
  $duration = $ad['duration'];
  $image    = (isset($ad['image']) && $ad['image'] != '')? 'Image: Received.' : '';
  $ad_copy  = $ad['ad_copy'];
  $notes    = ($ad['notes'] != NULL) ? 'Notes: ' . $ad['notes'] : '';
  $ad_type  = ($ad['ad_type'] == TRUE) ? '######### LIVELOAD AD ############## <br>' : 'CLASSIFIED AD ';
  $rate     = (is_array($ad['rate'])) ? $ad['rate']['rate_name'] : $ad['rate'];

  // Options
  $areas    = $ad['areas'];
  $area_count    = $ad['area_count'];
  $section_count = $ad['section_count'];
  $section  = $ad['sections'];

  // Payment Details
  $receipt_id = $ad['receipt'];
  $name     = $ad['user']['real-name'];
  $card     = $ad['user']['card-type'];
  $discount = $ad['discount'];
  $extras   = $ad['extras'];
  $subtotal = $ad['subtotal'];
  $taxes    = $ad['taxes'];
  $total    = $ad['total'];

  // Set Message (if holiday)
  $standard_message = 'PLEASE NOTE:
  Live Load ads are given priority and will be processed as quickly as possible (during regular business hours).
  Regular ads placed before 3pm on Thursday will appear in the following Tuesday\'s print edition.';

  // Check to see is the holiday settings are set and get message.
  $holiday = variable_get('pennywise_holiday_settings', NULL);
  $message = ($holiday['holiday_settings'] > 1) ? $holiday['holiday_message_plain'] : $standard_message;


$receipt = <<<RECEIPT
$ad_type DETAILS
Receipt #$receipt_id

Thank you for submitting your ad to PennywiseAds.com.
This email is your receipt and should be kept for your records.

$ad_type DETAILS
Areas ($area_count): $areas
Section ($section_count): $section
Duration: $duration weeks
$image

AD COPY
$ad_copy

$notes

PAYMENT INFO
Submitted by: $name
Rate: $rate

Subtotal: $$subtotal
Extras:   $$extras
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

  return $receipt;
}