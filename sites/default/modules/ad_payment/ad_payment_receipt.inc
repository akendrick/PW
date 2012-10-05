<?php

/**
* @page
*
* Generates receipt from Variable table
*/

/**
* Thank You Page
*
*/
function thankyou_page2($temp_id = NULL) {
  if (!$temp_id) {
    $content .= "<div id='adsubmission-thank-you'>";
    $content .= "<h3 class='thank-you thank-you-header'>There are no submitted ads at this time.</h3>";
    $content .= "<p class='thank-you thank-you-body'>.";
    $content .= '<p>' . l('Submit new classifed ad.', 'ad/submit') . '<p>';
    $content .= '</div>';
  }

  else {

    $content = ad_payment_receipt($temp_id);

  }

  return $content;
}


/**
* Implementation of custom theming function
*
* @TODO
*   Replace with THEME function.
*/


function ad_payment_receipt($temp_id = NULL) {
  global $user;


  $client = user_load($user->uid);
  //$phone = theme('cck_phone_formatter_local_phone_number', $client->field_phone['und'][0]);

  if (!$temp_id) {
    $content .= "<div id='adsubmission-thank-you'>";
    $content .= "<h3 class='thank-you thank-you-header'>There are no submitted ads at this time.</h3>";
    $content .= "<p class='thank-you thank-you-body'>.";
    $content .= '<p>' . l('Submit new classifed ad.', 'ad/submit') . '<p>';
    $content .= '</div>';
  }
  else {
    $data = variable_get('ad_submission_' . $temp_id);
    $data['receipt'] = $temp_id;

    // AD Details
    $details = "
        <div class='reciept-details grid-8 alpha'>
          <h3 class='receipt-details-title'>Ad Details</h3>
          <dl class='receipt-copy'>
            <dt class='receipt-copy'>Ad:</dt>
            <dd class='receipt-copy'>" . $data['values']['ad_copy'] . "</dd>
          </dl>
          <dl class='receipt-area'>
            <dt class='receipt-area'>Publication Area:</dt>
            <dd class='receipt-area'>" . $data['values']['area'] . "</dd>
          </dl>
          <dl>
            <dt class='receipt-classification'>Classification:</dt>
            <dd class='receipt-copy'>" . $data['rate']['term_name'] . "</dd>
          </dl>
          <dl class='receipt-rate'>
            <dt class='receipt-rate'>Rate:</dt>
            <dd class='receipt-copy'>" . $data['rate']['rate_name'] . "</dd>
          </dl>
          <dl class='receipt-duration'>
            <dt class='receipt-duration'>Duration:</dt>
            <dd class='receipt-copy'>" . $data['duration']['actual'] . " weeks</dd>
          </dl>";
      if ($data['variables']['ad_type']) {
        $details .= "
          <dl class='receipt-liveload'>
            <dt class='receipt-liveload'>Liveload:</dt>
            <dd class='receipt-copy'>" . $data['values']['ad_type'] . "</dd>
          </dl>";
      }
      if ($data['variables']['image']) {
          $details .= "
            <dl class='receipt-image'>
              <dt class='receipt-image'>Image:</dt>
              <dd class='receipt-copy'>Image received (fid: " . $data['values']['image'] . ")</dd>
            </dl>";
      }
      if ($data['variables']['notes']) {
          $details .= "
            <dl class='receipt-notes'>
              <dt class='receipt-notes'>Notes:</dt>
              <dd class='receipt-copy'>" . $data['values']['notes'] . "</dd>
            </dl>";
      }
      $details .= "\t </div>";

    $price = "
        <div class='small-receipt receipt-price grid-8 omega'>
          <h4 class='receipt-price-title'>Price</h3>
        <div class='small-receipt receipt-price-inner'>
          <dl class='receipt-price-subtotal'>
            <dt class='receipt-price-subtotal'>Sub-total:</dt>
            <dd class='receipt-price-subtotal'>$" . $data['subtotal'] . "</dt>
          </dl>
          <dl class='receipt-price-taxes'>
            <dt class='receipt-price-taxes'>Taxes:</dt>
            <dd class='receipt-price-taxes'>$" . $data['taxes'] . "</dt>
          </dl>
          <dl class='receipt-price-total'>
            <dt class='receipt-price-total'>Total:</dt>
            <dd class='receipt-price-total'>$" . $data['total'] . "</dt>
          </dl>
          <dl class='receipt-contact-card'>
            <dt class='receipt-contact-card'>Payment:</dt>
            <dd class='receipt-contact-card'>" . $data['values']['user']['card-type'] . "</dt>
          </dl>
        </div>
        </div>
      ";

    $contact = "
        <div class='small-receipt receipt-contact grid-8 omega'>
          <h4 class='receipt-contact'>Contact Information</h3>
          <em>If you wish to edit this information you must first register your account. An email has been sent to your address with the details.</em>
          <div class='small-receipt receipt-contact-inner'>
          <dl class='receipt-contact-name'>
            <dt class='receipt-contact-name'>Name:</dt>
            <dd class='receipt-contact-name'>" . $data['values']['user']['real-name']  . "</dt>
          </dl>
          <dl class='receipt-contact-phone'>
            <dt class='receipt-contact-phone'>Phone:</dt>
            <dd class='receipt-contact-phone'>" . $phone . "</dt>
          </dl>
          <dl class='receipt-contact-email'>
            <dt class='receipt-contact-email'>Email:</dt>
            <dd class='receipt-contact-email'>" . $user->mail . "</dt>
          </dl>
        </div>
      </div>
      ";

    // Add PW Logo
    $image_variables = array(
      'path' => 'sites/default/files/pwlogo.gif',
      'title' => 'Pennywise Online Classifieds',
      'attributes' => array('class' => 'pennywise-logo'),
    );

    $content .= "<div id='adsubmission-thank-you'>";
    $content .= "<h3 class='thank-you thank-you-header'>Thank you for choosing Pennywise.</h3>";
    $content .= "<p class='thank-you thank-you-body'>A confirmation message has been sent to your email address.";
    $content .= '<div class="logo">' . theme('image', $image_variables) . '</div>';
    $content .= '<p>Please print this page for your receipt.</p>';
    $content .= '<h3> Ad Receipt #' . $temp_id . '</h3>';
    $content .= '<div id="ad-submission-receipt" class="ad-receipt-box grid-20 prefix-2 ">' . $details . $price . $contact . $receipt . '</div>';
    $content .= '<p>' . l('Return to classified ads', '<front>', array('attributes' => array('class' => array('view-classified-ad-link')))) . '<p>';
    $content .= '<p>' . l('Submit another ad', 'ad/submit', array('attributes' => array('class' => array('submit-classified-ad-link')))) . '<p>';
    $content .= '</div>';

    //variable_del('ad_submission_' . $temp_id);
  }

  // Call mail script.
  module_load_include('inc', 'ad_payment', 'ad_payment_mail');

  // Email receipt.
  $to = $user->mail;
  $from = variable_get('pw_email', 'k2@pennywiseads.com');
  $send = TRUE;
  $language = language_default();
  $result = drupal_mail('ad_payment', 'customer_receipt', $to, $language, $data, $from, $send);

  if ($result['result'] == TRUE) {
    drupal_set_message(t('A copy of this receipt has beed sent to your email address.'), 'status' );
  }
  else {
    watchdog('Ad Payment', 'Receipt Email Error',
      array('to' => $to, 'from' => $from, 'result' => $result, 'data' => $data), WATCHDOG_NOTICE);
  }

  if (DEBUG_ADP || DEBUG_EMAIL) {
    $debug_var = array(
      '@key' => 'Customer Receipt',
      '@to'  => $to,
      '@from' => $from,

    );
    $debug_msg = "@key -- To: @to;From: @from";
    watchdog('Ad Payment', $debug_msg, $debug_vars, WATCHDOG_INFO);

  }


  return $content;
}



