<?php
/**
* @file
* Checks form variables and determines the ad price.
*
* This page does all the back end Price Calculations
* that appear during page loads of the online ad submission form.

* Save data in $form_data['storage']['price']
* - Price is saved at every stage of the calculation for verification purposes.
* - Which is then saved in it's own database, by NID.  -> @TODO
*
* @TODO
* - Store Price in Database for futre retrieval and verification
* - Create an alert when jQuery price is different from PHP calculated price.
*   Send alert to classifed & client that price is different.
* - Create ADMIN INTERFACE -- field on taxonomy term for - BIZ RATEd
*/


/**
 * Returns the details of the pricing model used to determine the final price.
 *
 * Used for double checking price data.
 *
 * @return
 *  Human readable array of ad submission data.
 */
function _ad_payment_pricing_details($node) {
  // Get RAW DATA for processing
  $storage['values'] = _ad_payment_get_payment_variables($node);

  $rate = ad_payment_validate_rate($storage);

  $details = array(
    'Ad Rate' => $rate['rate_name'],
    'Word Count' => $count,
    'Duration' => $duration['actual'] . ' weeks',
    'Total Areas' => $areas,
    'Areas' => $storage['values']['area'],
    'options' => $options,
    'Price' => array(
      'discount' => $discount,
      'sub-total' => $sub_total,
      'taxes' => $taxes,
      'total' => $total,
    ),
  );
  if($options['image']){
    $storage['values']['readable']['Image #'] = $form_state['input']['field_image']['und'][0]['fid'];
  }

  return $details;
}

/**
 * Returns array of form or node variables used to determine ad price.
 *
 * @var $form_state
 *  This function is called from different points in the life of the form.
 *  So different variables need to be consulted at different points.
 *   - FORM_STATE - called during the creation of the node.
 *   - NODE - called after the creation of the node or during the INSERT node function.
 *
 * @return
 *  array of form/node values
 */
function _ad_payment_get_payment_variables($data, $type = NULL){
  if (DEBUG_ADP || DEBUG_PAYMENT) {
    dpm('Ad Payment - Get Payment Variables');
    dpm('TYPE');
    dpm($type);
    dpm('DATA');
    dpm($data);
  }


  switch ($type) {
    case 'form_state':
      $form_state = $data;
      $form_values = array(
        'parse'   => 'Form State Values',
        'ad_copy' => $form_state['values']['field_ad_copy']['und'][0]['value'],
        'area_default' => $form_state['values']['field_area']['und'][0]['value'],
        'area'    => ad_payment_parse_array($form_state['values']['field_area']['und'], 'form > area'),
        'image'   => $form_state['values']['field_image']['und'][0]['fid'],
        'rate'    => $form_state['values']['field_rate']['und'][0]['value'],
        'ad_type' => $form_state['values']['field_promote']['und'][0]['value'],
        'duration'=> $form_state['values']['field_duration']['und'][0]['value'],
        'section_default' => $form_state['values']['field_tags']['und'][0]['value'],
        'section_count' => count($form_state['values']['field_tags']['und']),
        'section' => ad_payment_parse_array($form_state['values']['field_tags']['und'], 'form > section'),
        'notes'   => $form_state['values']['field_notes']['und'][0]['value'],
        'user'    => array(
          'real-name' => $form_state['values']['field_first_name'] . ' ' . $form_state['values']['field_last_name'],
          'card-type' => $form_state['values']['field_card_type'],
          'phone'     => $form_state['values']['field_phone'],
          'email'     => $form_state['values']['field_email'],
        ),
      );
      break;
    case 'node':
      $node = $data;
      $form_values = array(
        'parse'   => 'Node Values',
        'ad_copy' => $node->field_ad_copy['und'][0]['value'],
        'area_default' => $node->field_area['und'][0]['value'],
        'area_count'   => count($node->field_area['und']),
        'area'    => ad_payment_parse_array($node->field_area['und'], 'node > area'),
        'image'   => $node->field_image['und'][0]['fid'],
        'rate'    => $node->field_rate['und'][0]['value'],
        'ad_type' => $node->field_promote['und'][0]['value'],
        'ccid'    => $node->field_ad_details['und'][0]['value'],
        'duration'=> $node->field_duration['und'][0]['value'],
        'section_default' => $node->field_tags['und'][0]['tid'],
        'section_count' => count($node->field_tags['und'][0]['tid']),
        'section' => ad_payment_parse_array($node->field_tage['und'], 'node > section'),
        'notes'   => $node->field_notes['und'][0]['value'],
        'user'    => array(
          'real-name' => $node->field_first_name . ' ' . $node->field_last_name,
          'card-type' => ($node->field_first_name) ? 'Mastercard' : 'VISA',
          'phone'     => ($node->field_first_phone) ? $node->field_phone : 'No phone given.',
          'email'     => ($node->field_email) ? $node->email : 'No email given.',
        ),
      );
      break;
    default:
      return;
  }
  if (DEBUG_ADP || DEBUG_PAYMENT) {
    dpm('Ad Payment - RETURN Variables');
    dpm('FORM_VALUES');
    dpm($form_values);
  }

  return $form_values;
}

/**
* Implementation of custom taxonomy term name getter
*/
function ad_payment_get_term_name($tid) {
  if (is_numeric($tid)) {
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
  }
  return $term_name;
}

/**
* Implementation of custom array value parser
*
* @array_to_parse
*   - search this array for 'value'
* @return
*   - return string of all found 'value' tags.
*/
function ad_payment_parse_array($array_to_parse = NULL, $call = NULL) {
  if (!is_array($array_to_parse)) {
    return $array_to_parse;
  }

  if (is_array($array_to_parse)) {
    $value = count($array_to_parse);
  }
  else {
    $value .= item . ' ';
  }

  // If ZERO assume 1.
  $value = ($value == FALSE) ? 1 : $value;

  if (DEBUG_ADP || DEBUG_PAYMENT) {
    dpm('Array counted from ' . $call);
    dpm($array_to_parse);
    dpm($value);
  }

  return $value;
}



/**
* Process ad price depending on returned form values.
*
* This function the authoritative source of ad pricing
* @param $data_type
*   Alter the output depending on this variable.
*   - Possible options:
*     - form_state -> @return massage data for future use in $form_state and elsewhere.
*     - node -> @return final price of submitted ad.

* @return
*  $price - array of price elements.
*  $storage['price'] = $price;
*/
function ad_payment_price_check(&$var, $data_type) {

  // Clear $form_state storage price.
  $storage = array();

  // Get RAW DATA for processing
  $values = _ad_payment_get_payment_variables($var, $data_type);

  // Validate Rate
  $rate = ad_payment_validate_rate($values['section_default'], $values['rate']);

  // Count Areas
  $areas = $values['area_count'];

  // Count Sections
  $sections = $values['section_count'];

  // Validate Duration
  $duration = _ad_payment_set_ad_duration($values['duration']);

  // Word Count
  $count = _ad_payment_word_counter($values['ad_copy']);

  // Options
  $liveload = ($values['ad_type'] == 'Liveload Your Ad!') ? 1 : 0;
  $image = ($values['image']) ? 1 : 0;
  $options = array(
    'liveload' => $liveload,
    'image' => $image,
  );

  // DETERMINE PRICE


  // If optional perks
  $img_price = ($image) ? $rate['image_rate'] : 0;
  $live_price = ($liveload == TRUE) ? $rate['liveload_rate'] : 0;

  // Get basics
  $words_over_price = ($count['over'] > 0) ? $rate['word_rate'] * ($count['over'] -1) : 0;

  // If booking all 4 areas get $2 off (per week).
  $area_discount = ($areas == 4) ? -2 * $duration['adjusted'] : 0;

  // 1. Base Rate = ad_rate + word over count
  $base_rate = $rate['base_rate'] + $words_over_price;

  // 2. Area Multiplyer
  $sub_total_1 = $base_rate * $areas;

  // 3. Section Multiplyer
  $sub_total_2 = $sub_total_1 * $sections;

  // 4. Duration['adjusted'] - (Image price here)
  $sub_total_3 = ($sub_total_2 + $img_price) * $duration['adjusted'];

  // 5. Options
  $sub_total = $sub_total_3 + $live_price + $area_discount;

  // Taxes
  $tax_rate = variable_get('ad_payment_taxrate', '.12');
  $taxes = _ad_payment_dollar_format($sub_total * $tax_rate);

  // 6. Total Cost
  $total = $sub_total + $taxes;
    // Round Total
    $total = _ad_payment_dollar_format($total);

//
//  // Base rate + overflow word count
//  $base_price = ($rate['word_rate'] * $count['over']) + $rate['base_rate'] + $img_price ;
//      $feedback .= t('<p>Base price $@base =($@word_rate (word rate) * @words_over (words over 15)) + @base_rate (base rate) + $@img_price (image price)</p>',
//        array('@base' => $base_price, '@base_rate' => $rate['base_rate'], '@word_rate' => $rate['word_rate'], '@words_over' => $count['over'], '@img_price' => $img_price));
//
//  // Adjusted with duration and areas
//  $sub_total_1 = $base_price * $areas * $duration['adjusted'];
//      $feedback .= t('<p>Subtotal_1 $@sub1 = $@base (base rate) * @duration (duration) * @areas (# areas)</p>',
//        array('@sub1' => $sub_total_1, '@base' => $base_price, '@duration' => $duration['adjusted'], '@areas' => $areas));
//
//  // Adjusted with duration and sections
//  $sub_total_2 = $sub_total_1 * $sections;
//      $feedback .= t('<p>Subtotal_2 $@sub2 = $@sub1 (subtotal_1) * @sections (# of sections) </p>',
//        array('@sub2' => $sub_total_2, '@sub1' => $sub_total_1, '@sections' => $sections));
//
//  // Liveload - one time price.
//  $sub_total_3 = _ad_payment_dollar_format($sub_total_2 + $live_price);
//      $feedback .= t('<p>Subtotal_3 $@sub3 = $@sub2 (subtotal_2) + $@liveload (live load price)</p>',
//        array('@sub3' => $sub_total_3, '@sub2' => $sub_total_2, '@liveload' => $live_price));
//
//  // Get Taxes
//  $tax_rate = variable_get('ad_payment_taxrate', '.12');
//
//  // Total Cost
//  $total = $sub_total_3 + $taxes;
//  // Round Total
//  $total = _ad_payment_dollar_format($total);
//  $taxes = _ad_payment_dollar_format($sub_total_3 * $tax_rate);
//      $feedback .= t('<p>FINAL PRICE $@total = $@sub3 (subtotal_3) + $@tax (taxes at @tax_rate)</p>',
//        array('@total' => $total, '@sub3' => $sub_total_3, '@tax' => $taxes, '@tax_rate' => $tax_rate));

  // Set Price Variables
  $storage = array(
    'values'   => $values,
    'rate'     => $rate,
    'count'    => $count,
    'duration' => $duration,
    'areas'    => $areas,
    'options'  => $img_price + $live_price,
    'discount' => $area_discount,
    'subtotal' => $sub_total,
    'taxes'    => $taxes,
    'total'    => $total,
  );

  // Parse data into legible reciept.
  //$form_variable_storage['receipt'] = ad_payment_format_ad_submission_receipt($form_variable_storage);


  // TEST PRICES
  if(DEBUG_ADP || DEBUG_PAYMENT) {
    dpm('Data Being Saved.');
    dpm($storage);

    dpm('FEEDBACK');
    $feedback = array(
      'Image Price' => $img_price,
      'Liveload Price' => $live_price,
      'Words Over 15 price' => $words_over_price,
      'Area Discount' => $area_discount,
      'Base Rate' => $base_rate,
      'Section Subtotal' => $sub_total_1,
      'Area Subtototal' => $sub_total_2,
      'Duration Subtotal' => $sub_total_3,
      'Options Subtotal' => $sub_total_4,
      'Tax Rate' => $tax_rate,
      'Taxes' => $taxes,
      'Total (rounded)' => $total,
    );
    dpm($feedback);
    // Base
//    drupal_set_message(t('Base Price: $@base = $@base_rate base price + @image_price (if any) + (@over words over @ $@word_rate word)',
//      array('@base' => $base_price, '@base_rate' => $rate['base_rate'], '@image_price' => $img_price, '@word_rate' => $rate['word_rate'], '@over' => $count['over'])));
//
//    // Adjusted with duration and areas
//    drupal_set_message(t('Adj Price: $@adj = $@base * @duration weeks * @sect sections * @areas areas',
//      array('@adj' => $adj_price, '@base' => $base_price, '@duration' => $form_variable_storage['adjusted'], '@sect' => $areas, '@areas' => $areas)));
//
//    // All four areas are booked add discount.
//    // If optional perks
//    drupal_set_message(t('With Options (if present): $@sub = $@adj + $@live (liveload) + $@image (image) + @discount discount',
//      array('@sub' => $sub_total, '@adj' => $adj_price, '@image' => $img_price, '@live' => $live_price, '@discount' => $discount)));
//
//    // Taxes
//    drupal_set_message(t('Taxes: $@tax', array('@tax' => $taxes)));
//
//    // TOTAL
//    drupal_set_message(t('Total Price: $@total', array('@total' => $total)));
  }


  // Determine which vales are returned.
  //If form_state save payment data for future reference & return price for immediate use.
  if ($data_type == 'form_state') {
    $form_state['storage']['price'] = $storage['total'];
    $form_state['storage']['values'] = $storage['values'];
    return $storage['total'];
  }
  else {
    return $storage;
  }

}

/**
* Custom script to make a themed output of ad_submission data.
*
*/
//function ad_payment_format_ad_submission_receipt($data = NULL) {
//$details = "
//  <div class='reciept-details'>
//    <h3 class='receipt-title'>Ad Details</h3>
//    <dd>
//      <dt class='receipt-copy'>Ad:</dt>
//      <dd class='receipt-copy'>" . $data['ad_copy'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-area'>Publication Area:</dt>
//      <dd class='receipt-area'>" . $data['areas'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-classification'>Classification:</dt>
//      <dd class='receipt-copy'>" . $data['variables']['section'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-rate'>Rate:</dt>
//      <dd class='receipt-copy'>" . $data['rate'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-duration'>Duration:</dt>
//      <dd class='receipt-copy'>" . $data['variables']['area'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-liveload'>Ad Type:</dt>
//      <dd class='receipt-copy'>" . $data['variables']['ad_type'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-image'>Image:</dt>
//      <dd class='receipt-copy'>" . $data['variables']['image'] . "</dd>
//    </dd>
//    <dd>
//      <dt class='receipt-notes'>Notes:</dt>
//      <dd class='receipt-copy'>" . $data['variables']['notes'] . "</dd>
//    </dd>
//  </div>";
//
//return $details . $receipt;
//}


/**
* Custom Form Validation
*
* Determine current form Rate and Classification.
*
* $tid - a numerical term id.
* $submitted_rate -  rate selected by client
*
* @return
*   array of price points to determine ad price.
*
*/
function ad_payment_validate_rate($tid = NULL, $submitted_rate = NULL) {
  if (DEBUG_ADP || DEBUG_PAYMENT) {
    dpm('RATE');
    dpm('$submitted_rate = ' . $submitted_rate);
  }

  // Get Section Rating
  if ( $tax_term = taxonomy_term_load($tid) ) {
    $get_rate = array(
      'term_rate' => $tax_term->field_business_rated['und'][0]['value'],
      'term_name' => $tax_term->name,
      'form_rate' => ($submitted_rate == 'Personal') ? 0 : 1,
    );
  }

  if ($submitted_rate == 'Business'){
    $get_rate['rate'] = 1;
  }
  else {
      // IF Business Rated Term and Personal Rate Selected
      if ($get_rate['term_rate']) {
        if ($get_rate['term_rate'] != $get_rate['form_rate']) {
          $error_messege = $term_name . 'is a Business Rated classification.<br>To update your ad:
             <ol><li>Select "<strong>Create Classified Ad</strong>" from the side menu.
             <li>Change your ad to "Business" rated <br/>or choose a different section for your ad to appear in.</ol>';
           $error_messege = t('%term is a Business Rated classification.<br>To update your ad:
               <ol><li>Select "<strong>Create Classified Ad</strong>" from the side menu.
               <li>Change your ad to "Business" rated <br/>or choose a different section for your ad to appear in.</ol>',
               array('%term' => $term_name));
          form_set_error('field_tags', $error_messege);
        }
      }

    if (DEBUG_ADP || DEBUG_PAYMENT) {
      dpm('Taxonomy Rate - After error checking.');
      dpm($get_rate);
    }
  }


  // Set Prices
  switch($get_rate['rate']) {
    case 0: // Personal
      $pricing = array(
        'rate_name' => 'Personal',
        'base_rate' => 3.5,
        'word_rate' => .2,
        'image_rate' => 1.99,
        'liveload_rate' => 5,
      );
      break;
    case 1: // Business
      $pricing = array(
        'rate_name' => 'Business',
        'base_rate' => 5,
        'word_rate' => .4,
        'image_rate' => 2.99,
        'liveload_rate' => 5,
      );
      break;
  }
  $rate = array_merge($get_rate, $pricing);

  if (DEBUG_ADP || DEBUG_PAYMENT) {
    dpm('Returned Rate');
    dpm($rate);
  }

  return $rate;
}

/**
* Set Taxonomy Business Terms
*
* @return
*   - return array (list) of Term Synonyms that are 'Business' Rated.
*
* @TODO
* - Use set_/get_ variable
* - Cache business rated Terms
*/
function _ad_payment_business_rating($storage) {
  $term_id = $storage['values']['section'];
  $term = taxonomy_term_load($term_id);
  if($term->field_business_rated['und'][0]['value'] == FALSE) {
    return FALSE;
  }
  else {
    return TRUE;
  }

}


/**
* Set Ad Duration
*
* @return
*   duration['adjusted'] = ad duration - for billing (& math)
*   duration['actual']   = actual ad duration weeks
*
*/
function _ad_payment_set_ad_duration($weeks) {
  if (!$weeks) {
    watchdog('Ad Payment', 'Unable to set duration. _ad_payment_set_ad_duration() No data to process. _ad_payment_set_ad_duration :: ad_payment_price_check.php LINE 323');
  }

  $duration = array();

  switch($weeks) {
    case 1:
      $duration = array(
        'adjusted' => 1,
        'actual'   => 1,
      );
      break;
    case 2:
      $duration = array(
        'adjusted' => 2,
        'actual'   => 3,
      );
      break;
    case 6:
      $duration = array(
        'adjusted' => 4,
        'actual'   => 6,
      );
      break;
    case 9:
      $duration = array(
        'adjusted' => 6,
        'actual'   => 9,
      );
      break;
    case 12:
      $duration = array(
        'adjusted' => 8,
        'actual'   => 12,
      );
      break;

    default:
      $duration = array(
        'adjusted' => 2,
        'actual'   => 3,
      );
      break;

  }

  return $duration;
}


/**
* Set Word count
*
* @return
*   total word count.
*/
function _ad_payment_word_counter($copy) {
  // Make sure all periods are followed by a space.
  $copy = str_replace('.', '. ', $copy);

  // Clear Paragraph Returns or New Lines and Double Spaces
  // replace with single space
  $find = array('\r', '\n', '  ');
  $copy = str_replace($find, '', $copy);
  $copy = str_replace($find, '', $copy);

  // Count spaces.
  $count = explode(' ', $copy);

  $word_count = count($count);
  $over = ($word_count > 15) ? ($word_count - 15) : 0;

  $count = array(
    'count' => $word_count,
    'over' => $over,
  );

  return($count);
}

/**
* Custom Price Integer Display.
*/
function _ad_payment_dollar_format($amount)  	{
  $new_amount = sprintf("%.2f",$amount);
  return $new_amount;
}