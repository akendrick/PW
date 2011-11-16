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
define ('DEBUG', FALSE);
/**
* Custom Form Validation
*
* Determine current form Rate and Classification.
*
* @return
*   array of price points to determine ad price.
*
* @TODO
* - Use set_/get_ variable
* - Cache business rated Terms
*/
function _ad_submission_validate_rate(&$form_state) {
  // Get Section Rating
  $term_id = $form_state['values']['field_tags']['und'][0]['tid'];
  $term = taxonomy_term_load($term_id);
  $section_rating = ($term->field_business_rated['und'][0]['value'] == TRUE) ? 1 : 0;
  dsm('Section Rating - ' . $section_rating);
  // Get Form Rating
  $form_rating = ($form_state['values']['field_rate']['und'][0]['value'] == 'Personal') ? 0 : 1;
  dsm('Form Rating - ' . $form_rating);

  // IF BUSINESS Rated agree
  if ($section_rating == TRUE) {
    dsm('This Classification is BUSINESS RATED!');
    if ($section_rating != $form_rating) {
      dsm('You have chosen a PERSANAL rate despite the section!');
      form_set_error('field_tags', 
        (t('%term is a Business Rated classification.<br>You may either:<ul><li>Change your ad to "Business" rated <li>or choose a different section for your ad to appear in.</ul>', 
        array('%term' => $term->name))));
    }
    $rate = 1;    
  }
  // IF section is not business rated.  
  elseif ($section_rating == FALSE) {
    $rate = $section_rating;
  }
  else {
    return;
  }
  // Anything goes.
  

  // Set Price Rates
  switch($rate) {
    case 0: // Personal
    $rate = array(
      'rate' => 0,
      'rate_name' => 'Personal',
      'base_rate' => 3.5,
      'word_rate' => .2,
      'image_rate' => 1.99,
      'liveload_rate' => 5,
    );
      break;
    case 1: // Business
      $rate = array(
        'rate' => 0,
        'rate_name' => 'Personal',
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
function _ad_submission_business_rating($form_state) {
  $term_id = $form_state['values']['field_tags']['und'][0]['tid'];
  $term = taxonomy_term_load($term_id);
  if($term->field_business_rated['und'][0]['value'] == FALSE) {
    return FALSE;
  }
  else {
    return TRUE;
  }
  
}



/**
* Process ad price depending on returned form values.
* 
* $debug - set to TRUE to display Pricing variables in step2 of the form
* 
* @return
* Final price
*/
function ad_submission_price_check(&$form_state) {
  // Set to TRUE to display values.
  $debug = TRUE;   

  // Clear $form_state storage price.
  $form_state['#storage']['price'] = array();

  // Determine Ad Section
  $section_id = $form_state['values']['field_tags']['und'][0]['tid'];
  

  // Validate Rate
  $rate = _ad_submission_validate_rate($form_state);

  // Sections
  $sections = count($form_state['values']['field_area']['und']);
  
  // Duration
  $duration = _ad_submission_set_ad_duration($form_state['values']['field_duration']['und'][0]['value']);

  // Word Count
  $count = _ad_submission_word_counter($form_state['values']['field_ad_copy']['und'][0]['value']);
  
  // Options
  $liveload = ($form_state['values']['field_promote']['und'][0]['value'] == 'Liveload Your Ad!') ? TRUE : FALSE;
  $image = ($form_state['values']['field_image']['und'][0]['fid']) ? TRUE : FALSE;
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
  $adj_price = $base_price * $duration['adjusted'] * $sections;
  // If booking all 4 areas get $1 off.
  $discount = ($sections == 4) ?  -2 : 0;
  
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
  $total = _ad_submission_dollar_format($total);
  
  // TEST PRICES
  if(DEBUG) {
    // Base
    drupal_set_message(t('Base Price: @base = $@base_rate base price + (@over words over @ $@word_rate word)', array('@base' => $base_price, '@base_rate' => $rate['base_rate'], '@word_rate' => $rate['word_rate'], '@over' => $count['over']))); 
    // Adjusted with duration and areas
    drupal_set_message(t('Adj Price: @adj = $@base * @duration weeks * @sect sections', array('@adj' => $adj_price, '@base' => $base_price, '@duration' => $duration['adjusted'], '@sect' => $sections))); 
    // All four areas are booked add discount.
    // If optional perks
    drupal_set_message(t('With Options (if present): @sub = $@adj + $@live (liveload) + $@image (image) + @discount discount', array('@sub' => $sub_total, '@adj' => $adj_price, '@image' => $img_price, '@live' => $live_price, '@discount' => $discount))); 
    // Taxes
    drupal_set_message(t('Taxes: $@tax', array('@tax' => $taxes))); 
    // TOTAL
    drupal_set_message(t('Total Price: $@total', array('@total' => $total))); 
  }
  
  // Set Price Variables
  $form_state['#storage']['price'] = array(
    'rate' => $rate,
    'count' => $count,
    'duration' => $duration,
    'sections' => $sections,
    'options' => $options,
    'sub-total' => $sub_total,
    'taxes' => $taxes,
    'total' => $total,
  );
  
  return $total;
}


/**
* Set Ad Duration
*
* @return
*   duration['adjusted'] = ad duration - for billing (& math)
*   duration['actual']   = actual ad duration weeks
*
*/
function _ad_submission_set_ad_duration($weeks) {
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
function _ad_submission_word_counter($copy) {
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

function _ad_submission_dollar_format($amount)  	{
  $new_amount = sprintf("%.2f",$amount);
  return $new_amount;
}
