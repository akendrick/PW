<?php

/**
* @FILE
*
* Default email behaviour for Ad Payment Module
*/

/**
* Implementation of hook_mail
*/
function ad_payment_mail($key, &$message, $params) {
  if (DEBUG || DEBUG_EMAIL) {
    dpm('KEY - MESSAGE - PARAMS');
    dpm($key);
    dpm($message);
    dpm($params);
  }

  switch($key) {
    case 'customer_receipt':
      $message['body'][] = email_receipt_body($message);;
      $message['subject'] = 'Pennywise Ad Submission';
     // email_receipt_body(&$message);
      break;
    case 'inhouse_receipt':
      $message['body'][] = email_receipt_body($message);;
      $message['subject'] = 'Pennywise Ad IN HOUSE';
//      $ad_received .= "Ad Copy: \n" . $params['values']['ad_copy'] . "\n\n";
//      $ad_received .= 'Word Count: ' . $params['count']['count'] . "\n";
//      $ad_received .= 'Section: ' . $params['section']. "\n";
//      $ad_received .= 'Area (' . count($params['areas']) . ")" . $params['values']['area'] . "\n";
//      $ad_received .= 'Rate: ' . $params['rate']['rate_name'] . "\n";
//      $ad_received .= ($params['values']['ad_type']) ? "Liveload: YES \n " : "";
//      $ad_received .= ($params['values']['image']) ? "Image: Received \n" : " ";
//      $ad_received .= ($params['values']['notes']) ? $params['values']['notes'] . " \n " : "";
//      $ad_received .= 'Duration: ' . $params['duration']['actual'] . ' weeks' . "\n";
//      $ad_received .= 'Notes: ' . $params['duration'] . "\n";
//
//      $ad_received .= 'Price: $' . $params['total'] . "\n";
//
//      $message['body'][] = 'inhouse backup email test';
//      $message['subject'] = 'Pennywise Ad In House Receipt';
      break;
  }

  if (DEBUG_ADP || DEBUG_EMAIL) {
    $debug_var = array(
      '@key' => $key,
      '@subject' => $message['subject'],
      '@body' => $message['body'][0],
      '@ad' => $ad_received,
    );
    $debug_msg = "@key - triggered in ad_payment_mail.<br>
      SUBJECT: @subject<br>
      <p>BODY: <br>
      @body</p>
      AD RECIEVED:<br>
      @ad";
    watchdog('Ad Payment - eMail', $debug_msg, $debug_vars, WATCHDOG_INFO);

    dpm('MESSAGE - POST');
    dpm($message);
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

  $ad = $message['params']['values'];
  $rate = $message['params']['rate'];

  $ad_copy = $ad['ad_copy'];
  $areas = $message['params']['values']['areas'];
  $image = $ad['image'];
  $rate = $message['params']['values']['rate'];
  $duration = $message['params']['duration']['actual'];
  $name = $ad['user']['real-name'];
  $rate_name = $rate['rate_name'];
  $section = $rate['term_name'];
  $receipt_id = $message['params']['receipt'];
  $card = $ad['user']['card-type'];

  $discount = $message['params']['discount'] * $message['params']['duration']['adjusted'];
  $subtotal = $message['params']['subtotal'];
  $taxes = $message['params']['taxes'];
  $total = $message['params']['total'];

$reciept = <<<RECEIPT
Classified Ad Receipt #$receipt_id
Your ad has been submitted.

Thank you for submitting an ad to PennywiseAds.com.
Here is an email receipt for you records.

DETAILS
Areas: $areas
Section: $section
Duration: $duration

Ad copy:
$ad_copy

PAYMENT INFO
Submitted by: $name
Rate: $rate_name

Subtotal: $$subtotal
Discount: $$discount
Taxes:    $$taxes
Total:    $$total
Billed to $card.

CONTACT US
You can contact us 9am to 5pm Monday to Friday (& until 4pm on Friday).
Toll free: 1-800-663-4619
Local: 250-353-2602
Email: info@pennywiseads.com
Address: Box 430,
         Kaslo BC
         Canada V0G 1M0

PLEASE NOTE:
Your ad will be reviewed by out friendly staff before being placed online and in print.
If you have chosed the liveload ad feature this will happen within 1/2 hour (during business hours).
Otherwise the ad will wait until our next print edition which is every Tuesday.

We appreciate your business, and look forward to helping you again.

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
  dpm('receipt');
  dpm($reciept);
  }

  return $reciept;
}