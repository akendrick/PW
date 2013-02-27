Drupal.adPayment = Drupal.adPayment || {};


/**
 * jQuery Word Counter
 *
 * First we clean the text.
 * Then we count it.
 *
 *  Counter and Cleaner from jQuery
 */
Drupal.adPayment.wordCleaner = function(content) {
	var fullStr = content + " ";
	var initial_whitespace_rExp = /^[^A-Za-z0-9-@_.]+/gi;
	var left_trimmedStr = fullStr.replace(initial_whitespace_rExp, "");
	var non_alphanumerics_rExp = rExp = /[^A-Za-z0-9-@_.]+/gi;
	var cleanedStr = left_trimmedStr.replace(non_alphanumerics_rExp, " ");
	var splitString = cleanedStr.split(" ");

	return splitString;
};
Drupal.adPayment.countWords = function(cleanedWordString) {
	var word_count = Drupal.adPayment.wordCleaner(cleanedWordString).length-1;
	return word_count;
}


/**
 * Form Validation
 */
Drupal.adPayment.validate = function(ad) {
       //console.log('Payment validation script.');
  ad.errorMsg = {};
  var state = false;

  // Hyphenation Check
	var hyphensRg = /([A-Za-z0-9][-_.*#]){2,}/;
  if (hyphensRg.test(ad.copy)) {
    state = true;
    ad.errorMsg.hyphen = Drupal.t('<h3>Too Many Connections!</h3> You have too many connections between words. This can include periods between words or hyphens. If this is correct you can ignore this warning.');
    jQuery('#field-ad-copy-add-more-wrapper').addClass('error element-error');
  }
  else {
    jQuery('#field-ad-copy-add-more-wrapper').removeClass('error element-error');
  };

  // DETERMINE RATE
  // - If BIZ rate.
  //   Ignore and clean errors.
  // - If PERSONAL rate.
  //   Check term Rate.
  //   If Term rate is Biz - send errors.
  //   Otherwise ignore.
  if (ad.formRate == 'Personal') {
    // Get Selected SECTION
    ad.section = jQuery('#edit-field-tags-und').val();

    if (ad.section >= 0) {
      // get section ratings
      var bizRatedSections = Drupal.settings.adPaymentBiz;

      if (bizRatedSections[ad.section]) {
        // Biz Rated
        state = true;
        jQuery('.form-item-field-tags-und, #edit-field-rate-und').addClass('error element-error');
        ad.errorMsg.section = Drupal.t("<h3>@section is a business rated section.</h3> Please choose another section or change your ad rating to </em>Business</em>.", {'@section': bizRatedSections[ad.section]});
      }
      else {
        jQuery('.form-item-field-tags-und, #edit-field-rate-und').removeClass('error element-error');
        // personal rate
      }

    }
  }
  else {
      jQuery('.form-item-field-tags-und, #edit-field-rate-und').removeClass('error element-error');
  };


  // Output error message
  if (state) {
    ad.errorMsg.warning = Drupal.t('<h3>The quoted price may not be accurate.</h3>This ad will need to verified by Pennywise staff before billing.');

    var validationBoxes = '';
    jQuery.each(ad.errorMsg, function(key, value) {
        validationBoxes += '<div style="display:block" class="messages error"><h2 class="element-invisible">Error Message</h2>' + value + '</div>';
    });

    //var validationBox = '<h2 class="element-invisible">Error Message</h2><ul>' + errorMsg + '</ul>';
    jQuery('#validation-box').html(validationBoxes);
    // Make sure the "NEXT" button is visable.
    jQuery('.multipage-button').show();
;
  }
  else {
    jQuery('#validation-box').html('').removeClass('messages error');
    ad.errorMsg = '';
  };

  return ad;

};


/**
 * Get Form Data.
 *
 * @return
 *  array of form variables.
 */
Drupal.adPayment.formData = function(ad) {

        //console.log('Form Data script.');
 // Ad Copy
  ad.copy = jQuery('#edit-field-ad-copy-und-0-value').val();

  // Word Counter
  ad.wordCountTrim = jQuery('#edit-field-ad-copy-und-0-value').val().trim();
  //ad.wordCount     = jQuery('#edit-field-ad-copy-und-0-value').val().split(/\b[\n\s,\.:;.]*/).length;
  ad.wordCount = Drupal.adPayment.countWords(Drupal.adPayment.wordCleaner( ad.copy ));

  if (ad.wordCount == 'undefined' || ad.wordCount < 15) {
    // ad.wordCount = 15;
  }
  else if (ad.wordCount > 15) {
    ad.countOver = ad.wordCount-15;
  }

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
  //ad.area = (ad.area == 0) ? 'undefined' : ad.area;

  // RATE
  if (jQuery('#edit-field-rate-und-personal:checked').val() == 'Personal') {
    ad.formRate = 'Personal';
  }
  else if (jQuery('#edit-field-rate-und-business:checked').val() == 'Business') {
    ad.formRate = 'Business';
  }
  else {
    ad.formRate = 'Not Set';
  };

  // DURATION
  ad.duration = jQuery('#edit-field-duration-und').val();

  // LIVELOAD
  if (jQuery('#edit-field-promote-und-0:checked').val() == '0') {
    ad.type = 'Regular Classified Ad';
  }
  else if (jQuery('#edit-field-promote-und-1:checked').val() == '1') {
    ad.type = 'Liveload Classified Ad';
  }
  else {
    ad.type = 'Not Set';
  };

  // Section
  if(jQuery('#edit-field-tags-und').val()) {
    ad.section = jQuery('#edit-field-tags-und').val().length;
  }

  // Validate Form Data
  ad = Drupal.adPayment.validate(ad);

  return ad;
};


/**
 * Format Currency
 */
Drupal.adPayment.formatCurrency = function(num) {
  num = isNaN(num) || num == '\u65533' || num === '' || num === null ? 0.00 : num;
  return parseFloat(num).toFixed(2);
};

/**
 * Determine Price
 */
Drupal.adPayment.getPrice = function(ad) {
        //console.log('Get Price script.');
 var price = {};

  // Get Rate
  if (ad.formRate == 'Personal') {
    price.rate = 'Personal';
    price.base = 3.5;
    price.word = .2;
    price.img  = 1.49;
    price.promote = 5;
  }
  else if (ad.formRate == 'Business'){
    price.rate = 'Business';
    price.base = 5;
    price.word = .4;
    price.img  = 2.99;
    price.promote = 5;
  };

  //  // CALCULATE PRICE
  // If no area selected use default one.
  price.area = (ad.area == 0) ? 1 : ad.area;

  // Word Rate
  price.overCount = (ad.wordCount > 15) ? (ad.countOver * price.word) : 0;
  // 1. Base Price - Total Word count
  price.adWordCount = price.base + price.overCount;

  // 2. Area Multiplyer
  price.basePrice = price.adWordCount * price.area;

  // 3. Section Multiplyer
    if(jQuery('#edit-field-tags-und').val()) {
      price.section = jQuery('#edit-field-tags-und').val().length;
    }
    else {
      price.section = 1;
    }
  price.subTotal1 = price.basePrice * price.section;

  // 4. Duration ( Image price here... if any)
  price.image = (ad.image == 1) ? price.img : 0;
  price.subTotal = (price.subTotal1 + price.image) * ad.duration;

    // Determine options and if discount
    price.discount = (ad.area == 4) ? -2 * ad.duration : 0;
    // Determine Liveload (if any)
    price.liveload = (ad.type == 'Liveload Classified Ad') ? price.promote : 0;

  // 5. Add up options
  price.subTotal  = price.subTotal + price.discount + price.liveload;


  // Determine taxes
  price.taxRate = .12;
  price.taxes   = price.subTotal * price.taxRate;

  // 6. Total Price
  price.total = price.subTotal + price.taxes;

//  // Round prices for output
  price.subTotalRound = Drupal.adPayment.formatCurrency(price.subTotal);
  price.taxesRound    = Drupal.adPayment.formatCurrency(price.taxes);
  price.totalRound    = Drupal.adPayment.formatCurrency(price.total);

//  console.log('Price');
//  console.log(price);
//  console.log('Ad');
//  console.log(ad);

  return price;
};


/**
 * Output Message
 *
 * Determine form data and configure display.
 */
Drupal.adPayment.displayMsg = function() {
       //console.log('Message Display script.');
  var ad = {};
  ad = Drupal.adPayment.formData(ad);

  var price = {};
  price = Drupal.adPayment.getPrice(ad);

    // Ad Message
  ad.msg = {};
  ad.msg.wordcount   = Drupal.t("<dt>Word count:</dt><dd>@count </dd>", {'@count': ad.wordCount});

  // Show formatted ad:
  if (ad.wordCount > 0) {
    ad.msg.ad = Drupal.t("<dt>How your ad will look:</dt><dd>@trim </dd>", {'@trim': ad.wordCountTrim});
  }
  else {
    ad.msg.ad = '';
  };

  // Over 15 words notice.
  if (ad.wordCount > 15) {
    ad.msg.countOver   = Drupal.t("<dt>Words over 15:</dt><dd> @count at &cent;@wordPrice0 a word </dd>", {'@count': ad.countOver, '@wordPrice': price.word});
    ad.msg.countOverSum   = Drupal.t("<dt>Words over 15:</dt><dd> @count </dd>", {'@count': ad.countOver});
  }
  else {
    ad.msg.countOver = '';
    ad.msg.countOverSum = '<dt>Words over 15:</dt><dd>0</dd>';
  }

  // Area MSG
  if (ad.area == 0) {
    ad.msg.areaList = Drupal.t("<dt>Areas:</dt><dd> No Area Selected</dd>");
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd><em>No Area Selected</em></dd>");
  }
  else if (ad.area > 0 && ad.area < 4) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas</dd>", {'@area': ad.area, '@areas': ad.areaList});
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd> @area</dd>", {'@area': ad.area,});
  }
  else if (ad.area == 4) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas <br />$2 Discount on ad.</dd>", {'@area': ad.area, '@areas': ad.areaList});
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd> @area </dd>", {'@area': ad.area,});
  }
  else {
    ad.msg.areaList = '<dt>Area: None Selected</dt><dd>Please select an area for your ad to appear in.</dd>';
    ad.msg.areaListSum = "";
  }
  // ad web area free
  ad.msg.areaList += '<em class="price-box duration duration-note">Internet Included FREE</em>';

  // Rate MSG
  ad.msg.rate = Drupal.t("<dt>Rate:</dt><dd> @rate</dd>", {'@rate': ad.formRate});

  // Duration MSG
  ad.msg.duration = Drupal.t("<dt>Duration:</dt><dd> @duration weeks</dd>", {'@duration': ad.duration}) + ad.msg.durationDiscount;
  ad.msg.durationSum = Drupal.t("<dt>Duration:</dt><dd>@duration weeks</dd>", {'@duration': ad.duration});
  if (ad.duration == '2') {
    ad.msg.duration = '<dt>Duration:</dt><dd>When you book for 2 weeks you get the 3rd for FREE!</dd>';
    ad.msg.durationSum = Drupal.t("<dt>Duration:</dt><dd>@duration weeks</dd>", {'@duration': ad.duration});
  };

  // Liveload
  ad.msg.type = Drupal.t("<dt>Ad Type:</dt><dd> @type</dd>", {'@type': ad.type});

  // PRICE
  ad.msg.priceSum = Drupal.t("<dt>Price:</dt><dd><ul class=\"price price-review\"><li class=\"price price-subtotal\">Subtotal: $@basePrice</li><li class=\"price price-taxes\">Taxes: $@taxes</li><li class=\"price price-total\">Total: $@total</li></ul></dd>", {'@basePrice': price.subTotalRound, '@taxes': price.taxesRound,'@total': price.totalRound});
  ad.msg.priceOverview = Drupal.t("<dt>Price</dt><dd><ul class='price price-review'><li class='price price-subtotal'>Sub Total: $@subTotal</li><li class='price price-option'>Optional Extras: $@optional</li><li class='price price-taxes'>Taxes: $@taxes</li><li class='price price-total'>Total: $@priceTotal</li></dd>", {'@basePrice': price.basePrice, '@overPrice': price.overCount, '@subTotal': price.subTotalRound, '@taxes': price.taxesRound, '@optional': price.optional, '@priceTotal': price.totalRound});

  // SHow save on AGREE
  if (jQuery('#edit-field-agree-und-confirm').is(':checked')) {
    jQuery('#edit-submit, #edit-preview').show();
   // jQuery('.multipage-button').hide();
  }
  else {
   // jQuery('#edit-submit, #edit-preview').hide();
  }
  if (jQuery('#edit-field-agree-und-not-yet').is(':checked')) {
   // jQuery('#edit-submit, #edit-preview').hide();
   // jQuery('.multipage-button').show();
  }
  // Error Messages
  ad.msg.error = '';
  if (ad.errorMsg) {
    jQuery.each(ad.errorMsg, function(key, value) {
      ad.msg.error += '<li>' + value + '</li>';
    });
    ad.msg.error = '<ul class="error">' + ad.msg.error + '</ul>';
    //  jQuery('#edit-submit, #edit-preview').hide();
    // Make sure the "NEXT" button is visable.
    jQuery('.multipage-button').show();

  }
  else {
    ad.msg.error = '';
  }

  // Compose Messages
  // Summary - quick feedback as you type.
  ad.msg.summary =
    '<div id="ad-summary">'
     + '<div id="ad-summary-price" class="block summary-price-block block-details">'
     + '<h4 class="ad-summary-header">Summary</h4>'
     + '<dl class="ad-summary">'
     + '<span class="ad-summary-block">' + ad.msg.areaListSum  + '</span>'
     + '<span class="ad-summary-block">' + ad.msg.durationSum  + '</span>'
     + '<span class="ad-summary-block">' + ad.msg.wordcount    + '</span>'
     + '<span class="ad-summary-block">' + ad.msg.countOverSum + '</span>'
     + '<span class="ad-summary-block ad-summary-price-block">' + ad.msg.priceSum     + '</span>'
     + '</dl>'
     + '</div>'
    + '</div>'
    ;

  // Review - full review of ad before submission.
  ad.msg.review =
    '<div id="review-ad-box-ad" class="review-ad-block">'
    + '<h2>Ad</h2>'
    + ad.msg.ad
    + ad.msg.wordcount
    + ad.msg.countOver
    + '</div>'
    + '<div id="ad-review-data">'
    + '<div id="review-ad-box-price" class="review-ad-block">'
    + '<h2>Summary</h2>'
    + ad.msg.error
    + '<dl>'
    + ad.msg.areaList
    + ad.msg.rate
    + ad.msg.duration
    + ad.msg.type
    + ad.msg.priceOverview
    + '</dl>'
    + '</div>'
    ;
  ad.msg.storage =
    '$adp_pricing = array('
    + '\'wordcount\' => ' + ad.wordCount + ','
    + '\'duration\' => ' + ad.duration + ','
    + '\'count_over\' => ' + ad.countOver + ','
    + '\'area_list\' => ' + '\'' + ad.areaList + '\','
    + '\'rate\' => ' + '\'' +  ad.formRate + '\','
    + '\'type\' => ' + '\'' +  ad.type + '\','
    + '\'base_price\' => ' + price.subTotalRound + ','
    + '\'taxes_price\' => ' + price.taxesRound + ','
    + '\'base_price\' => ' + price.subTotalRound + ','
    + '\'total_price\' => ' + price.totalRound + ','
    + ');'
    // {'@basePrice': price.subTotalRound, '@taxes': price.taxesRound,'@total': price.totalRound});
  // SET FORM PRICE
  jQuery('#edit-field-price-und-0-value').val(price.totalRound);

  return ad.msg;
}


/**
 * PRIMARY EVENT HANDLING.
 *
 * Sidebar-first - summary
 * Content Review - hidden until submitting
 */
jQuery(document).ready(function() {



 // var formID = jQuery("form").attr('id');
 // if (formID == 'ad-s-node-form'){

 // New form validation in case of multiple forms detected.
  if (jQuery('#ad-s-node-form').length) {

       // console.log('FOrm Id detected and prepared.');

    // Hide Edit/Submit & image AJAX uploader -  unless on page 4
  //  jQuery('#edit-submit, #edit-preview').hide();

    // Hide Image Upload Button (uploading images always produces an error.
    jQuery('#edit-field-image-und-0-upload-button').hide();

    // Get Settings
    var sideBar = '#sidebar-first > .section > .region';
    var summaryBox = Drupal.adPayment.displayMsg().summary;
    jQuery(sideBar).prepend(summaryBox);

    // Create DIV for OverView
    //jQuery('#ad-s-node-form').prepend('<div id="ad-review">There are no ads ready to submit at this time.</div>');
    var boxDetails = '<div id="ad-review" class="ad-review-empty-box"> <div id="ad-summary" class="block summary-price-block ad-summary-directions"> <h4 class="ad-summary-header">Directions</h4><ul class="ad-summary-list"> <li>Begin by typing your ad in the <em>Ad Copy</em> box.</li> <li>Below that are your preferences for how & where you want your ad displayed.</li> <li>To get help your ad get noticed check out step <em>2: Options</em>.</li> <li>Enter credit card information in step <em>3: Payment</em>.</li> <li>When satisfied with your ad go to step <em>Review & Submit</em> to submit your finished ad.</li></ul></div></div>';
    jQuery('.group-ad-copy-block').prepend(boxDetails);
//    jQuery('#ad-review ').hide();

    // DIV for ReView
    var reviewLocation = '#edit-field-agree';
    jQuery(reviewLocation).prepend('<div id="review-ad-block"></div>');

    // create error box for validation
    var validationBox = '<div id="validation-box"></div>';
    jQuery('#ad-s-node-form').prepend(validationBox);

    jQuery('#ad-s-node-form').bind('click keypress keyup change mouseup', function() { //click change keypress keyup
       // console.log('Action Detected.');

              console.log('Validation.');
      jQuery('#ad-s-node-form').validate({
        rules: {
          field_cc_number: {
            required: true,
            creditcard: true
          }
        }
      });


      var sideBox = '#ad-summary';
      var summaryBox = Drupal.adPayment.displayMsg().summary;
      jQuery(sideBox).html(summaryBox);

      // Review box
      var reviewLocation = '#review-ad-block';
      var reviewBox = Drupal.adPayment.displayMsg().review;
      jQuery(reviewLocation).html(reviewBox).show();

      //console.log(reviewBox);
      jQuery('#ad-review').html(summaryBox);

      // Store Details for future processing.
      jQuery('#edit-field-ad-details-und-0-value').val(Drupal.adPayment.displayMsg().storage);

      // Hide 'Next Page' upon 'Save' option
     var ConfirmForm = jQuery('#edit-field-agree-und-confirm:checked').val();
     // var SaveButton = jQuery('#edit-submit').is(':visible');


     // HIDE SUBMIT UNTIL READY
     if (ConfirmForm) {
       console.log('Save button is visible');
       // jQuery('.multipage-button').hide();
       jQuery('#edit-submit').show();
     }
//     else {
//         jQuery('#edit-submit').hide();
//         jQuery('.multipage-button').show();
//        console.log('No save visible.');
//        var ConfirmPage = jQuery('#edit-field-agree-und-not-yet:checked').val();
//        if (!ConfirmPage) {
//         jQuery('.multipage-link-next').hide();
//        }
//        else {
//         jQuery('.multipage-link-next').hide();
//        }
////
//    }
//
     // If on the confirmation page --> hide "Next Page" button.
      // Reinterpret SUBMIT, NEXT & PREVIOUS button's CSS
       //console.log('Action detected - end of script.');

      // var pageState = jQuery('#node_ad_s_form_group_ad_review').attr('style');
      // console.log('Page state: ' + pageState);
      // Hide Submit Button if you're on page 4 and no ad copy.
      // if (pageState == "display: block;") {
      //   console.log('You are on page 4.');
      //   jQuery('#edit-submit, #edit-preview').show();
      // }
      // else {
      //   console.log('Not final page.');
      //   jQuery('#edit-submit, #edit-preview').hide();
      // };
    });
  };
});

