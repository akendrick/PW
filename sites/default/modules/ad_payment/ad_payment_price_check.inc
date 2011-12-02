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

define ('DEBUG', TRUE);


/**
* Process ad price depending on returned form values.
* 
* @return
*  $price - array of price elements.
*  $storage['price'] = $price;
*/
function ad_payment_price_check(&$var, $data_type) {
  // If this is the first page then there are no values. So return empty.
  if (!$var['values']) {
    return;
  }
  // Clear $form_state storage price.
  $storage = array();

  switch ($data_type) {
    case 'form_state':
      $form_state = $var;

      $storage['values'] = array(
        'ad_copy' => $form_state['values']['field_ad_copy']['und'][0]['value'],
        'section' => $form_state['values']['field_tags']['und'][0]['tid'],
        'area'    => $form_state['values']['field_area']['und'],
        'image'   => $form_state['values']['field_image']['und'][0]['fid'],
        'rate'    => $form_state['values']['field_rate']['und'][0]['value'],
        'ad_type' => $form_state['values']['field_promote']['und'][0]['value'],
        'duration'=> $form_state['values']['field_duration']['und'][0]['value'],
      );
      break;
    case 'node':
      $node = $var;
      $storage['values'] = array(
        'ad_copy' => $node->field_ad_copy['und'][0]['value'],
        'section' => $node->field_tags['und'][0]['tid'],
        'area'    => $node->field_area['und'],
        'image'   => $node->field_image['und'][0]['fid'],
        'rate'    => $node->field_rate['und'][0]['value'],
        'ad_type' => $node->field_promote['und'][0]['value'],
        'duration'=> $node->field_duration['und'][0]['value'],
      );
      break;
    default:
      return;
  }

  // Validate Rate
  $rate = _ad_payment_validate_rate($storage);

  // Sections
  $areas = count($storage['values']['area']);
  
  // Duration
  $duration = _ad_payment_set_ad_duration($storage['values']['duration']);

  // Word Count
  $count = _ad_payment_word_counter($storage['values']['ad_copy']);
  
  // Options
  $liveload = ($storage['values']['ad_type'] == 'Liveload Your Ad!') ? TRUE : FALSE;
  $image = ($storage['values']['image']) ? TRUE : FALSE;
  $options = array(
    'liveload' => $liveload,
    'image' => $image,
  );
  
  //  
  // Get Prices
  //

  // Base rate + overflow word count
  $base_price = $rate['base_rate'] + ($rate['word_rate'] * $count['over']);
  
  // Adjusted with duration and areas
  $adj_price = $base_price * $duration['adjusted'] * $areas;
  // If booking all 4 areas get $1 off.
  $discount = ($areas == 4) ?  -2 : 0;
  
  // If optional perks
  $img_price = ($image) ? $rate['image_rate'] : 0;
  $live_price = ($liveload == TRUE) ? $rate['liveload_rate'] : 0;
  $sub_total = $adj_price + $discount + $img_price + $live_price;

  // Get Taxes
  $tax_rate = .12;
  $taxes    = $sub_total * $tax_rate;
  
  // Total Cost
  $total = $sub_total + $taxes;
  // Round Total
  $total = _ad_payment_dollar_format($total);
  
  // TEST PRICES
  if(DEBUG) {
    // Base
    drupal_set_message(t('Base Price: @base = $@base_rate base price + (@over words over @ $@word_rate word)', array('@base' => $base_price, '@base_rate' => $rate['base_rate'], '@word_rate' => $rate['word_rate'], '@over' => $count['over']))); 
    // Adjusted with duration and areas
    drupal_set_message(t('Adj Price: @adj = $@base * @duration weeks * @sect sections', array('@adj' => $adj_price, '@base' => $base_price, '@duration' => $duration['adjusted'], '@sect' => $areas))); 
    // All four areas are booked add discount.
    // If optional perks
    drupal_set_message(t('With Options (if present): @sub = $@adj + $@live (liveload) + $@image (image) + @discount discount', array('@sub' => $sub_total, '@adj' => $adj_price, '@image' => $img_price, '@live' => $live_price, '@discount' => $discount))); 
    // Taxes
    drupal_set_message(t('Taxes: $@tax', array('@tax' => $taxes))); 
    // TOTAL
    drupal_set_message(t('Total Price: $@total', array('@total' => $total))); 
  }
  
  
  // Set Price Variables
  $storage['price'] = array(
    'rate' => $rate,
    'count' => $count,
    'duration' => $duration,
    'areas' => $areas,
    'options' => $options,
    'discount' => $discount,
    'sub-total' => $sub_total,
    'taxes' => $taxes,
    'total' => $total,
  );
  
  //If form_state save date for future reference.
  if ($data_type == 'form_state') {
    $form_state['storage']['price'] = $storage['price'];
    $form_state['storage']['values'] = $storage['values'];
  }
  return $total;
}




/**
* Custom Form Validation
*
* Determine current form Rate and Classification.
*
* @return
*   array of price points to determine ad price.
*
*/
function _ad_payment_validate_rate($storage) {

  // Get Section Rating
  $term = taxonomy_term_load($storage['values']['section']);

  // Get Form Rating
  $form_rate = ($storage['values']['rate'] == 'Personal') ? 0 : 1;

  // Store Rate Data
  $rate = array(
    'term' => $term->name,
    'term_rate'  => $term->field_business_rated['und'][0]['value'],
    'form_rate'  => $form_rate,
  );

  // IF Business Rated Term and Personal Rate Selected
  if ($rate['term_rate'] == TRUE) {
    if ($rate['term_rate'] != $rate['form_rate']) {
      form_set_error('field_tags', 
        (t('%term is a Business Rated classification.<br>To update your ad:<ol><li>Select "<strong>Create Classified Ad</strong>" from the side menu.<li>Change your ad to "Business" rated <br/>or choose a different section for your ad to appear in.</ol>', 
        array('%term' => $term->name))));
    }
  }

  // Set Prices
  switch($rate['term_rate']) {
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
  $rate = array_merge($rate, $pricing);
  
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

