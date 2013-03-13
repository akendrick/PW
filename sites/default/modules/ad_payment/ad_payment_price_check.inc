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

function ad_payment_log_payment($values) {

    $feedback_message = "#### @parse - Log Payment ####<br><br>
      <br> PRICING DATA::
      <br> Words: @wordcount
      <br> Above Base: @count_over words * @word_rate/word = $@price_over
      <br> Areas(@area_count): @areas
      <br> Section(@section_count): @sections
      <br>
      <br> Extras:
      <br> @liveload
      <br> @image
      <br>
      <br>
      <br> Rate: @rate
      <br> Subtotal: $@subtotal @discount
      <br>   Extras: $@extras
      <br>    Taxes: $@taxes
      <br>    Total: $@total_rounded
      <br> <br><br>
      <br> USER DATA::
      <br> Name: @user_name
      <br> Phone: @user_phone
      <br> Email: @user_email
      ";
    $feedback_vars = array(
      '@parse'      => $values['parse'],
      '@rate'       => $values['rate']['rate_name'],
      '@wordcount'  => $values['wordcount'],
      '@count_over' => $values['wordcount_over'],
      '@word_rate'  => $values['rate']['word_rate'],
      '@price_over' => $values['rate']['word_rate'] * $values['wordcount_over'],
      '@area_count' => $values['area_count'],
      '@areas'      => $values['areas'],
      '@area_discount'  => $values['discount'],
      '@section_count'  => $values['section_count'],
      '@sections'   => $values['sections'],
      '@image'      => ($values['image']) ? 'Image detected<br>' : '',
      '@liveload'   => ($values['ad_type']) ? 'Liveload Ad!' : 'Regular Classified',
      '@subtotal'   => $values['subtotal'],
      '@discount'   => ($values['discount']) ? '($' . $values['discount'] . ' discount)' : '',
      '@extras'     => $values['extras'],
      '@taxes'      => $values['taxes'],
      '@total'      => $values['subtotal'],
      '@total_rounded' => $values['total'],
      '@user_name'     => $values['user']['real-name'],
      '@user_phone'    => $values['user']['phone'],
      '@user_email'    => $values['user']['email'],
    );

    $feedback_message .= '<br><br>Logged by <b>ad_payment_log_payment</b> in <em>ad_payment_price_check.inc</em>';
    watchdog('ADP LOG', $feedback_message, $feedback_vars, WATCHDOG_INFO);

    // //dpm(t($feedback_message, $feedback_vars));

    // Base
    // drupal_set_message(t('Base Price: $@base = $@base_rate base price + @image_price (if any) + (@over words over @ $@word_rate word)',
    //   array('@base' => $base_price, '@base_rate' => $rate['base_rate'], '@image_price' => $img_price, '@word_rate' => $rate['word_rate'], '@over' => $count['over'])));
    //
    // // Adjusted with duration and areas
    // drupal_set_message(t('Adj Price: $@adj = $@base * @duration weeks * @sect sections * @areas areas',
    //   array('@adj' => $adj_price, '@base' => $base_price, '@duration' => $form_variable_storage['adjusted'], '@sect' => $areas, '@areas' => $areas)));
    //
    // // All four areas are booked add discount.
    // // If optional perks
    // drupal_set_message(t('With Options (if present): $@sub = $@adj + $@live (liveload) + $@image (image) + @discount discount',
    //   array('@sub' => $sub_total, '@adj' => $adj_price, '@image' => $img_price, '@live' => $live_price, '@discount' => $discount)));
    //
    // // Taxes
    // drupal_set_message(t('Taxes: $@tax', array('@tax' => $taxes)));
    //
    // // TOTAL
    // drupal_set_message(t('Total Price: $@total', array('@total' => $total)));

}

/**
* Parse Date in $values from form_state
*/
function ad_payment_get_form_details($form_state) {
    // Clear $form_state storage price.
  $values = array();

  // Get RAW DATA for processing
  //$values = ad_payment_get_payment_variables($var, $data_type);
  $values = array(
    'parse'   => 'Form Details',
    'ad_copy' => $form_state['values']['field_ad_copy'][LANGUAGE_NONE][0]['value'],
    'area_default'  => $form_state['values']['field_area'][LANGUAGE_NONE][0]['value'],
    'area_count'    => count($form_state['values']['field_area'][LANGUAGE_NONE]),
    'areas'   => ad_payment_parse_array($form_state['values']['field_area'][LANGUAGE_NONE], 'area'),
    'image'   => $form_state['values']['field_image'][LANGUAGE_NONE][0]['fid'],
    'image_flag' => isset($form_state['values']['field_image'][LANGUAGE_NONE][0]['fid']) ? TRUE : FALSE,
    'image_name' => $form_state['values']['field_image'][LANGUAGE_NONE][0]['fid'],
    'rate'    => $form_state['values']['field_rate'][LANGUAGE_NONE][0]['value'],
    'ad_type' => $form_state['values']['field_liveload'][LANGUAGE_NONE][0]['value'],
    'ad_type_name'    => ($form_state['values']['field_liveload'][LANGUAGE_NONE][0]['value']) ? 'Liveload' : 'Regular Classified Ad',
    'duration'=> $form_state['values']['field_duration'][LANGUAGE_NONE][0]['value'],
    'section_default' => $form_state['values']['field_tags'][LANGUAGE_NONE][0]['tid'],
    'section_count' => count($form_state['values']['field_tags'][LANGUAGE_NONE]),
    'section_name'  => ad_payment_get_term_name($form_state['values']['field_tags'][LANGUAGE_NONE][0]['tid'], 'section'),
    'sections'      => ad_payment_parse_array($form_state['values']['field_tags'][LANGUAGE_NONE], 'section'),
    'notes'   => $form_state['values']['field_notes'][LANGUAGE_NONE][0]['value'],
    'user'    => array(
      'real-name'   => $form_state['values']['field_first_name'] . ' ' . $form_state['values']['field_last_name'],
      'card-type'   => ($form_state['values']['field_card_type']) ? 'VISA' : 'Mastercard',
      'phone'       => $form_state['values']['field_phone'],
      'email'       => $form_state['values']['field_email'],
    ),
  );

  //dpm('FORM RATE');
  //dpm($form_state['values']['field_rate'][LANGUAGE_NONE][0]['value']);

  $values = ad_payment_price_check($values);

  //dpm('Established RATE - after price check.');
  //dpm($values['rate']['rate_name']);

   // TEST PRICES
    if(ADP_LOG_ERRORS || ADP_LOG_ERRORS_CC) {
      ad_payment_log_payment($values);

      $message = 'FORM Rate: ' . $form_state['values']['field_rate'][LANGUAGE_NONE][0]['value'] .
      ' <br>Parsed Rate: ' . $validated_rate['rate']['rate_name'];
      $message .= '<br><br>Logged by <b>ad_payment_get_form_details</b> in <em>ad_payment_price_check.inc</em>';
      watchdog('ADP RATE', $message);
    }

  return $values;
}

/**
* Parse data into array for final node storage.
*
* @input - Node object
* @return - array of pricing data.
*
*/

function ad_payment_get_node_details($node) {
  //dpm($node);
  $values = array(
    'parse'     => 'Node Details',
    'details'   => ($node->field_ad_details[LANGUAGE_NONE][0]['value']) ? $node->field_ad_details[LANGUAGE_NONE][0]['value'] : NULL,
    'ad_copy'   => $node->field_ad_copy[LANGUAGE_NONE][0]['value'],
    'area_default' => $node->field_area[LANGUAGE_NONE][0]['value'],
    'area_count'   => count($node->field_area[LANGUAGE_NONE]),
    'areas'     => ad_payment_parse_array($node->field_area[LANGUAGE_NONE], 'area'),
    'image'     => isset($node->field_image[LANGUAGE_NONE][0]['fid']) ? $node->field_image[LANGUAGE_NONE][0]['fid'] : '',
    'image_flag'=> isset($node->field_image[LANGUAGE_NONE][0]['fid']) ? TRUE : FALSE,
    'image_name'=> (isset($node->field_image[LANGUAGE_NONE][0]['file'])) ? $node->field_image[LANGUAGE_NONE][0]['fid'] : '',
    'rate'      => $node->field_rate[LANGUAGE_NONE][0]['value'],
    'ad_type'   => $node->field_liveload[LANGUAGE_NONE][0]['value'],
    'details'   => $node->field_ad_details[LANGUAGE_NONE][0]['value'],
    'duration'  => $node->field_duration[LANGUAGE_NONE][0]['value'],
    'section_default' => $node->field_tags[LANGUAGE_NONE][0]['tid'],
    'section_name'    => ad_payment_get_term_name($node->field_tags[LANGUAGE_NONE][0]['tid'], 'section'),
    'section_count'   => count($node->field_tags[LANGUAGE_NONE][0]['tid']),
    'sections'  => ad_payment_parse_array($node->field_tags[LANGUAGE_NONE], 'section'),
    'notes'     => isset($node->field_notes[LANGUAGE_NONE][0]['value']) ? $node->field_notes[LANGUAGE_NONE][0]['value'] : '',
    'user'      => array(
      'uid'       => $node->uid,
      'real-name' => $node->field_first_name . ' ' . $node->field_last_name,
      'card-type' => ($node->field_card_type) ? 'VISA' : 'Mastercard',
      'phone'     => ($node->field_phone) ? $node->field_phone[LANGUAGE_NONE][0]['number'] : 'No phone given.',
      'email'     => ($node->field_email) ? $node->field_email[LANGUAGE_NONE][0]['email'] : 'No email given.',
    ),
  );

  //dpm('NODE RATE');
  //dpm($node->field_rate[LANGUAGE_NONE]);

  // Get jQuery Pricing and Insert Into Database.
  if(isset($values['details'])) {
    $sub_details = array();
    $details = $node->field_ad_details[LANGUAGE_NONE][0]['value'];

    $sub_details = explode(';', $details);
    foreach($sub_details as $detail) {
      if ($detail != NULL) {
        $data = explode('=', $detail);
        $jq[trim($data[0])] = trim($data[1]);
      }
    }

    $values['wordcount']= $jq['wordcount'];
    $values['wordcount_over'] = $jq['wordcount_over'];
    $values['discount'] = $jq['discount'];
    $values['extras']   = $jq['extras'];
    $values['subtotal'] = $jq['subtotal'];
    $values['taxes']    = $jq['taxes'];
    $values['total']    = $jq['total'];

  }
  else {
    $values = ad_payment_price_check($values);
  }

 // TEST PRICES
 if(ADP_LOG_ERRORS || ADP_LOG_ERRORS_CC) {
    $message = 'Node Rate: ' . $node->field_rate[LANGUAGE_NONE][0]['value'] .
      ' <br>Parsed Rate: ' . $values['rate']['rate_name'];
    $message .= '<br><br>Logged by <b>ad_payment_get_node_details</b> in <em>ad_payment_price_check.inc</em>';
    watchdog('ADP RATE', $message);

   ad_payment_log_payment($values);
 }
  //dpm('RATE - after price check');
  //dpm($values['rate']['rate_name']);

  return($values);
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
*   - if KEY then parse for name else parse for value
*   - KEY determines name output. (either term or section).
* @return
*   - return string of all found 'value' tags.
*/
function ad_payment_parse_array($array_to_parse = NULL, $key = NULL) {
  if(!$key){
    if (!is_array($array_to_parse)) {
      return $array_to_parse;
    }

    if (is_array($array_to_parse)) {
      $item = count($array_to_parse);
    }
    else {
      $item .= item . ' ';
    }

    // If ZERO assume 1.
    $item = ($item == FALSE) ? 1 : $item;
  }
  else {
    $spacer = (count($array_to_parse) > 1) ? ', ' : '';
    $item  = '';
    switch($key) {
      case 'section':
        foreach($array_to_parse as $term) {
          $item .= ad_payment_get_term_name($term['tid']) . $spacer;
        }
        break;
      case 'area':
        foreach($array_to_parse as $area) {
          $item .= $area['value'] . $spacer;
        }
       break;
    }
  }
  return $item;
}




/**
* Process ad price depending on returned form values.
*
* This function is the backup ad pricing system. Not as reliable as jQuery(?)
* @param $data_type
*   Alter the output depending on this variable.
*   - Possible options:
*     - form_state -> @return massage data for future use in $form_state and elsewhere.
*     - node -> @return final price of submitted ad.

* @return
*  $price - array of price elements.
*  $storage['price'] = $price;
*/
function ad_payment_price_check($values) {
  // Validate Rate
  $values['rate'] = ad_payment_get_rate($values);

  // Set Duration
  $duration = ad_payment_set_ad_duration($values['duration']);
  $values['duration_actual'] = $duration['actual'];
  $values['duration_adjusted'] = $duration['adjusted'];

  // Count Areas
  $areas = $values['area_count'];

  // Count Sections
  $sections = $values['section_count'];

  // Word count
  $count = ad_payment_word_counter($values['ad_copy']);
  $values['wordcount']  = $count['total'];
  $values['wordcount_over'] = $count['over'];

  // Options
  $liveload = ($values['ad_type'] == 'Liveload Your Ad!') ? 1 : 0;
  $image = ($values['image']) ? 1 : 0;
  $options = array(
    'liveload' => $liveload,
    'image' => $image,
  );

  // DETERMINE PRICE


  // 1. Base price and extra word rate.
  $price_over = ($values['wordcount_over'] > 0) ? $values['rate']['word_rate'] * $values['wordcount_over'] : 0;

  // 2. Area Discount - If booking all 4 areas get $2 off (per week).
  $area_discount = ($areas == 4) ? (2 * $values['duration_adjusted']) : 0;

  // 3. Extras -- Liveload, Image price.
  $img_price = ($image) ? $values['rate']['image_rate'] * $duration['actual'] : 0;
  $live_price = ($values['ad_type']) ? $values['rate']['liveload_rate'] : 0;
  $extras = $img_price + $live_price;

  // One line calculations.
  // (( Base price with word count pricing) multiply by #AREA then by #SECTIONS add DISCOUNT then add IMAGE-Price ) multiply the whole thing by DURATION and add a LIVELOAD (if applicable)
  $sub_total = (($price_over + $values['rate']['base_rate']) * $areas * $sections  ) * $values['duration_adjusted'] - $area_discount;

  // Taxes
  $tax_rate = variable_get('ad_payment_taxrate', '.12');
  $taxes = ad_payment_dollar_format(($sub_total + $extras) * $tax_rate);

  // 6. Total Cost
  $total = $sub_total + $extras + $taxes;
    // Round Total
    $total = ad_payment_dollar_format($total);

  // Set Prices

  $values['discount'] = $area_discount;
  $values['extras']   = ad_payment_dollar_format($extras);
  $values['subtotal'] = $sub_total;
  $values['taxes']    = $taxes;
  $values['total']    = $total;

  // Recreate jQuery data
  if (!isset($values['details'])) {
    $values['details'] = "
      wordcount = {$values['wordcount']};
      wordcount_over = {$values['wordcount_over']};
      duration  = {$values['duration_actual']};
      area_list = $areas;
      image = $image;
      ad_type = {$values['ad_type']};
      ad_type_name = {$values['ad_type_name']};
      rate = {$values['rate']['rate_name']};
      subtotal = $$sub_total;
      discount = $$area_discount;
      extras = $$extras;
      taxes = $$taxes;
      total = $$total;
      ";
  }



  // Determine which vales are returned.
  //If form_state save payment data for future reference & return price for immediate use.
//  if ($data_type == 'form_state') {
//    $form_state['storage']['price'] = $storage['total'];
//    $form_state['storage']['values'] = $storage['values'];
//    return $storage['total'];
//  }
//  else {
//    return $storage;
//  }
  return $values;
}


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
function ad_payment_validate_rate($values) {
  if (!$values['section_default']) {
    $message .= 'No Default Section detected.';
    watchdog('ADP RATE', $message);
  }

  // Get Section Rating
  if ($taxony_term = taxonomy_term_load($values['section_default'])) {
    $rate = array(
      'term_rate' => $taxony_term->field_business_rated[LANGUAGE_NONE][0]['value'],
      'term_name' => $taxony_term->name,
      'form_rate' => ($values['rate'] == 'Personal') ? 0 : 1,
    );
  }
  else {
    form_set_error('field_tags', 'Please choose a section for your ad to appear under. Eg. "Animals & Livestock" or "Vehicles".');
    //$get_rate = array();
  }

  $message = 'SUBMITTED RATE: ' . $values['rate'] . '  <br>' .
      'FORM Rate: ' . $rate['form'] . '  <br>' .
      'TERM Rate: ' . $rate['form'] . '<br>';
  $message .= '<br><br>Logged by <b>ad_payment_validate_rate</b> in <em>ad_payment_price_check.inc</em>';
  watchdog('ADP RATE', $message);


  if ($rate['form_rate'] == $rate['term_rate'] || $rate['form_rate']) {
    return $rate;
  }
  else {
    $error_messege = $term_name . 'is a Business Rated classification.<br>To update your ad:
       <ol><li>Select "<strong>Create Classified Ad</strong>" from the side menu.
       <li>Change your ad to "Business" rated <br/>or choose a different section for your ad to appear in.</ol>';
     $error_messege = t('%term is a Business Rated classification.<br>To update your ad:
         <ol><li>Select "<strong>Create Classified Ad</strong>" from the side menu.
         <li>Change your ad to "Business" rated <br/>or choose a different section for your ad to appear in.</ol>',
         array('%term' => $term_name));
    form_set_error('field_tags', $error_messege);

    return FALSE;
  }
}


function ad_payment_get_rate($values = NULL) {
  if ($values['section_count'] > 1) {
    $validated_rate = ad_payment_validate_rate($values);
  }
  else {
    $validated_rate = ad_payment_validate_rate($values);
  }

  // Set Prices
  switch($validated_rate['form_rate']) {
    case 0: // Personal
      $rate = array(
        'rate_name' => 'Personal',
        'base_rate' => 3.5,
        'word_rate' => .2,
        'image_rate' => 1.49,
        'liveload_rate' => 5,
      );
      break;
    case 1: // Business
      $rate = array(
        'rate_name' => 'Business',
        'base_rate' => 5,
        'word_rate' => .4,
        'image_rate' => 2.99,
        'liveload_rate' => 5,
      );
      break;
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
function ad_payment_business_rating($storage) {
  $term_id = $storage['values']['section'];
  $term = taxonomy_term_load($term_id);
  if($term->field_business_rated[LANGUAGE_NONE][0]['value'] == FALSE) {
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
function ad_payment_set_ad_duration($weeks) {
  if (!$weeks) {
    $message = 'Unable to set duration. Number of weeks selected --> @weeks <--';
    $message_vars = array('@weeks' => $weeks);
    $message .= '<br><br>Logged by <b>ad_payment_log_payment</b> in <em>ad_payment_price_check.inc</em>';
    watchdog('ADP Duration', $message, $message_vars, WATCHDOG_INFO);
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
function ad_payment_word_counter($copy) {

  // Eliminate all standard connectors for wordcounting.
  //$find = array('&', '-', '.', '/' , '\\', '\'', '"');
  //$copy = str_replace($find, '--', $copy);
  $copy = preg_replace("/[^A-Za-z0-9 ]/", 'z', $copy);
  //dpm('COPY: ' . $copy);

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
    'total' => $word_count,
    'over'  => $over,
  );

  return($count);
}

/**
* Custom Price Integer Display.
*/
function ad_payment_dollar_format($amount)  	{
  $new_amount = sprintf("%.2f",$amount);
  return $new_amount;
}