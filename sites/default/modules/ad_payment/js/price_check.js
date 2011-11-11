Drupal.adPayment = Drupal.adPayment || {};


/** 
 * Character Counter for inputs and text areas 
 */  
//$('.word_count').each(function(){  
//    // get current number of characters  
//    var length = $(this).val().length;  
//    // get current number of words  
//    //var length = $(this).val().split(/\b[\s,\.-:;]*/).length;  
//    // update characters  
//    $(this).parent().find('.counter').html( length + ' characters');  
//    // bind on key up event  
//    $(this).keyup(function(){  
//        // get new length of characters  
//        var new_length = $(this).val().length;  
//        // get new length of words  
//        //var new_length = $(this).val().split(/\b[\s,\.-:;]*/).length;  
//        // update  
//        $(this).parent().find('.counter').html( new_length + ' characters');  
//    });  
//});  

/**
 * Get Form Data.
 *
 * @return
 *  array of form variables.
 */
Drupal.adPayment.formData = function(ad) {
    
  // Ad Copy 
  ad.copy = jQuery('#edit-field-ad-copy-und-0-value').val();
  
  // Word Counter
  ad.wordCountTrim = jQuery('#edit-field-ad-copy-und-0-value').val().trim();
  ad.wordCount     = jQuery('#edit-field-ad-copy-und-0-value').val().split(/\b[\n\s,\.:;.]*/).length;
    
  if (ad.wordCount > 15) {
    ad.countOver = ad.wordCount - 15;
  };
  // ad.msg = Drupal.adPayment.getMsg(ad);
  
  // AD AREA
  ad.area = 0;
  ad.areaList = '';
  // Check each area.
  if (jQuery('#edit-field-area-und-trail').is(':checked')) {
    ad.area++;
    ad.areaList += 'Trail';
  }
  if (jQuery('#edit-field-area-und-nelson').is(':checked')) {
    if(ad.area > 0) { ad.areaList +=  ', ';};
    ad.area++;
    ad.areaList += 'Nelson';
  }
  if (jQuery('#edit-field-area-und-kootenay-lake').is(':checked')) {
    if(ad.area > 0) { ad.areaList += ', ';};
    ad.area++;
    ad.areaList += 'Kootenay Lake';
  }
  if (jQuery('#edit-field-area-und-castlegar').is(':checked')) {
    if(ad.area > 0) { ad.areaList += ', ';};
    ad.area++;
    ad.areaList += 'Castlegar';
  }
  
  // RATE
  if (jQuery('#edit-field-rate-und-personal:checked').val() == 'Personal') {
    ad.rate = 'Personal';
  }
  else if (jQuery('#edit-field-rate-und-business:checked').val() == 'Business') {
    ad.rate = 'Business';
  }
  else {
    ad.rate = 'Not Set';
  };
  
  // Duration
  ad.duration = jQuery('#edit-field-duration-und').val();
  
  // Return
  return ad;
};

/**
 * Output Message
 */
Drupal.adPayment.getMsg = function() { 
  var ad = {};
  
  ad = Drupal.adPayment.formData(ad);
   
  // Ad Message
  ad.msg = {};
  ad.msg.wordcount   = Drupal.t("Word count: @count - (@trim)", {'@count': ad.wordCount, '@trim': ad.wordCountTrim});
  // Over 15 words notice.
  if (ad.wordCount > 15) {
    ad.msg.countOver   = Drupal.t("Words over 15: @count - (@trim)", {'@count': ad.countOver, '@trim': ad.wordCountTrim});
  }
  else {
    ad.msg.countOver = '';
  }
  // Area MSG
  if (ad.area > 0) {
    ad.msg.areaList = Drupal.t("@area Area(s): @areas", {'@area': ad.area, '@areas': ad.areaList});
  }
  else {
    ad.msg.areaList = '';
  }
  // Rate MSG 
  ad.msg.rate = Drupal.t("Rate: @rate", {'@rate': ad.rate});
  // Duration MSG
  if (ad.duration == '2') {
    ad.msg.durationDiscount = '<br/>Book 2 Weeks and get the 3rd for FREE!<br/>';
  } else { ad.msg.durationDiscount = ''; };
  ad.msg.duration = Drupal.t("Duration: @duration weeks", {'@duration': ad.duration}) + ad.msg.durationDiscount;
  
  // MSG
  ad.msg =  ad.msg.countOver + '<br/>' + ad.msg.wordcount + ' <br>\n  ' + ad.msg.areaList + '<br/>' + ad.msg.rate + '<br/>' + ad.msg.duration;
  return ad.msg;
}

jQuery(document).ready(function() {
  jQuery('#field-price-add-more-wrapper').hide();
  jQuery('#field-ccid-add-more-wrapper').hide();
    var box = jQuery('#ad-price-box');
    box.html(Drupal.adPayment.getMsg());
  
  jQuery('#ad-s-node-form').bind('click change keyup', function() {
    var box = jQuery('#ad-price-box');
    box.html(Drupal.adPayment.getMsg());
  });

});

  