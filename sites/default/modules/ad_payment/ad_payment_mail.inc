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
  if (DEBUG_ADP || DEBUG_EMAIL) {
    dpm('Call made to ad_payment_mail');
    dpm('KEY: ' . $key);

    dpm('MESSAGE');
    dpm($message);

    dpm('PARAMS');
    dpm($params);
  }

  switch($key) {
    case 'customer_receipt':
      $message['body'][] = email_receipt_body($message);
      $message['subject'] = 'Pennywise Classified Ad Receipt';
      break;
    case 'inhouse_receipt':
      $ad_received .= "Ad Copy: \n" . $params['values']['ad_copy'] . "\n\n";
      $ad_received .= 'Word Count: ' . $params['count']['count'] . "\n";
      $ad_received .= 'Section: ' . $params['section']. "\n";
      $ad_received .= 'Area (' . count($params['areas']) . ")" . $params['values']['area'] . "\n";
      $ad_received .= 'Rate: ' . $params['rate']['rate_name'] . "\n";
      $ad_received .= ($params['values']['ad_type']) ? "Liveload: YES \n " : "";
      $ad_received .= ($params['values']['image']) ? "Image: Received \n" : " ";
      $ad_received .= ($params['values']['notes']) ? $params['values']['notes'] . " \n " : "";
      $ad_received .= 'Duration: ' . $params['duration']['actual'] . ' weeks' . "\n";
      $ad_received .= 'Notes: ' . $params['duration'] . "\n";

      $ad_received .= 'Price: $' . $params['total'] . "\n";

      $message['body'][] = 'inhouse backup email test';
      $message['subject'] = 'Pennywise Ad In House Receipt';
      break;
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
//  $receipt = '<strong>Order #' . $message['params']['reciept'] . ' has been received.</strong>';
//  $receipt .= 'Greetings ' . $message['params']['values']['user']['real-name'];
//  $receipt .= 'Your classified ad has been submitted to PennywiseAds.com.';
//  $receipt .= ;

  $body = 'Oh Bother!';

  if (DEBUG_ADP || DEBUG_EMAIL) {
    dpm('eMail Body - Customer Receipt');
    dpm($body);
  }

  return $body;
}