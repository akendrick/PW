(function ($) {

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
 	var initial_whitespace_rExp = /^[^A-Za-z0-9]+/gi;
	var left_trimmedStr = fullStr.replace(initial_whitespace_rExp, "");
 	var non_alphanumerics_rExp = rExp = /[^A-Za-z0-9@_&\-\/.'\047]+/gi; // Plus unicode quotations
	var cleanedStr = left_trimmedStr.replace(non_alphanumerics_rExp, " ");
	var splitString = cleanedStr.split(" ");

	return splitString;
};

Drupal.adPayment.countWords = function(cleanedWordString) {
	var word_count = Drupal.adPayment.wordCleaner(cleanedWordString).length-1;
	return word_count;
};


/**
 * Form Validation
 */
Drupal.adPayment.validate = function(ad) {
  ad.errorMsg = {};
  var state = false;

  // Hyphenation Check
	var hyphensRg = /([A-Za-z0-9][-_.*#'\\\/\(\)]){3,}/;
  if (hyphensRg.test(ad.copy)) {
    var state = true;
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
        var state = true;
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
  //following line changed Mar 18, 2013 - Peter Fisera, Earth Angel Consulting (for Brainflex)
  //ad.wordCountTrim = jQuery('#edit-field-ad-copy-und-0-value').val().trim();
  ad.wordCountTrim = jQuery.trim(ad.copy);
  //ad.wordCount     = jQuery('#edit-field-ad-copy-und-0-value').val().split(/\b[\n\s,\.:;.]*/).length;
  ad.wordCount = Drupal.adPayment.countWords(Drupal.adPayment.wordCleaner( ad.copy ));

  if (ad.wordCount < 15) {
   // ad.wordCount = 15;
    ad.countOver = 0;
  }
  else if (ad.wordCount > 15) {
    ad.countOver = ad.wordCount-15;
  }
  else {
    ad.countOver = 0;
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

  // IMAGE
  if (jQuery('#edit-field-image-und-0-upload').val()) {
    ad.imageFile = jQuery('#edit-field-image-und-0-upload').val();
    ad.imageFlag = 1;
    ad.imageMessage = 'Yes';
  }
  else if (jQuery('.image-widget.form-managed-file .file a').length > 0) {
    ad.imageFile = jQuery('.image-widget.form-managed-file .file a');
    ad.imageFlag = 1;
    ad.imageMessage = 'Yes';
    //console.log('Image detected: ' + ad.imageFile);
  }
  else {
    ad.imageFlag = 0;
    ad.imageMessage = 'No image';
    ad.imageFile = 'No Image';
  }
  //console.log('Image FLAG: ' + ad.imageFlag + ' FILE:' +  ad.imageFile + ' IMAGE:' + ad.image);

  // DURATION
  ad.duration = jQuery('#edit-field-duration-und').val();
  switch (ad.duration) {
    case '12':
      ad.durationPricing = 8;
      break;
    case '9':
      ad.durationPricing = 6;
      break;
    case '6':
      ad.durationPricing = 4;
      break;
    case '1':
      ad.durationPricing = 1;
      break;
    default:
      ad.durationPricing = 2;
      ad.duration = 3;
  };

  // LIVELOAD
  if (jQuery('#edit-field-liveload-und:checked').val() == '1') {
    ad.type = 'Liveload Classified Ad';
    ad.typeBool = 1;  }
  else {
    ad.type = 'Regular Classified Ad';
    ad.typeBool = 0;
  };

  // SECTION - SINGLE
  ad.section = jQuery('#edit-field-tags-und').val();
  ad.sectionName = jQuery('#edit-field-tags-und option:selected').text();
  ad.sectionCount = 1;

  // SECTION - MULTIPLE
  //if(jQuery('#edit-field-tags-und').val()) {
  //  ad.section = jQuery('#edit-field-tags-und').val().length;
  //
  //  if (ad.section = jQuery('#edit-field-tags-und').val().length == 1) {
  //    ad.sectionName = jQuery('#edit-field-tags-und option:selected').text();
  //  }
  //  else if (ad.section = jQuery('#edit-field-tags-und').val().length > 1) {
  //    ad.sectionName = '';
  //    jQuery('#edit-field-tags-und option:selected').each(function() {
  //      ad.sectionName += jQuery(this).text() + ', ';
  //    });
  //  };
  //  ad.sectionCount = jQuery('#edit-field-tags-und').val().length;
  //};
  //console.log('Section: ' , ad.sectionName + '  ' + ad.section);
  //console.log('SectionCount: ', ad.sectionCount);

  // Validate Form Data
  ad = Drupal.adPayment.validate(ad);

  return ad;
};


/**
 * Format Currency
 */
Drupal.adPayment.formatCurrency = function(num) {
  var num = isNaN(num) || num == '\u65533' || num === '' || num === null ? 0.00 : num;
  return parseFloat(num).toFixed(2);
};

/**
 * Check for VISA Debit.
 */
Drupal.adPayment.cardCheck = function() {
  var txt;
  var msgClass;

  // Validate Credit Card
  // - Check for VISA DEBIT
  var visaCard = jQuery('#edit-field-card-type-1').is(':checked');
  var cardNum  = jQuery('#edit-field-cc-number').val();
  if (visaCard == true) {
    //  console.log(cardNum + ' VISA: ' + cardNum.indexOf("4506"));
    if (cardNum.indexOf('4506') >= 0 || cardNum.indexOf('4519') >= 0 || cardNum.indexOf('4724') >= 0) {
      console.log('VISA DEBIT: ' + cardNum.indexOf('4506'));
      txt = '<h5>Sorry, we cannot accept VISA Debit cards online.</h5>For other payment options please call our toll-free number <h5>1-800-663-4619</h5>';
      msgClass = 'error';
    }
    else {
      txt = '';
      msgClass = 'no-error';
    }
  }
  else {
    txt = '';
    console.log('not VISA');
  }

  var cardMsg = '<label class="' + msgClass + '">' + txt + '</label>';

  return cardMsg;

}

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

  //1. Word Rate
  price.overCount = (ad.wordCount > 15) ? (ad.countOver * price.word) : 0;
  price.adWordCount = price.base + price.overCount;

  // 2. Area Discount
  price.discount = (ad.area == 4) ? 2 * ad.durationPricing : 0;

  // 3. Section Multiplyer
  //if(jQuery('#edit-field-tags-und').val()) {
    price.section = ad.sectionCount;
  //}
  //else {
  //  price.section = 1;
  //};
  //price.subTotal1 = price.basePrice * price.section;

  // 4. Duration ( Image price here... if any)
  price.image = (ad.imageFlag == 1) ? price.img * ad.duration : 0;
  //console.log('Price.image: ' + price.img + '  Ad.duration: ' + ad.duration);
  //price.subTotal = price.subTotal1 * ad.durationPricing + price.image;

  // 5. Determine Liveload (if any)
  price.liveload = (ad.typeBool == 1) ? price.promote : 0;
  //price.subTotal  = price.subTotal + price.liveload;

  // One long string
  price.subTotal = ((price.adWordCount * price.section * price.area ) * ad.durationPricing) - price.discount;
  price.extras   = price.liveload + price.image;

  // console.log('Basic: ' + price.adWordCount + '  Sections: ' + price.section + '  Areas: ' + price.area + '  (Discount: ' + price.discount + ')' + '  Weeks: ' + ad.durationPricing + '  Image: ' + price.image + '  Liveload: ' + price.liveload);
  // console.log('Price: ' + price.subTotal + '  Extras: ' + price.extras + '(Image: ' + price.image + '  Liveload: ' + price.liveload + ')');

  // Determine taxes
  price.taxRate = Drupal.settings.pwDefaults.taxRate;
  price.taxRateDisplay = Drupal.settings.pwDefaults.taxRateDisplay;
  price.taxes   = (price.subTotal + price.extras) * price.taxRate;

  // 6. Total Price
  price.total = (price.subTotal + price.extras) + price.taxes;

  // Round prices for output
  price.subTotalRound = Drupal.adPayment.formatCurrency(price.subTotal);
  price.extras        = Drupal.adPayment.formatCurrency(price.extras);
  price.taxesRound    = Drupal.adPayment.formatCurrency(price.taxes);
  price.totalRound    = Drupal.adPayment.formatCurrency(price.total);

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
    ad.msg.ad = Drupal.t("<dt>Your ad:</dt><dd>@trim </dd>", {'@trim': ad.wordCountTrim});
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

  // ad web area free (to be added to the description of areas)
  // ad.msg.areaInternet += 'Internet Included FREE!';
  // Area MSG
  if (ad.area == 0) {
    ad.msg.areaList = Drupal.t("<dt>Areas:</dt><dd class='error'>No Area Selected</dd>");
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd><small><em>Select Area</em><small></dd>");
  }
  else if (ad.area > 0 && ad.area < 4) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas </dd>", {'@area': ad.area, '@areas': ad.areaList});
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd> @area </dd>", {'@area': ad.area});
  }
  else if (ad.area == 4) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas</dd>", {'@area': ad.area, '@areas': ad.areaList});
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd> @area </dd>", {'@area': ad.area});
    ad.msg.discount = Drupal.t("You saved $@discount!", {'@discount': price.discount});
  }
  else {
    ad.msg.areaList = Drupal.t('<dt>Area: None Selected</dt><dd class="error">Please select an area for your ad to appear in.</dd>');
    ad.msg.areaListSum = "";
    ad.msg.discount = '';
  }

  // Section
  ad.msg.section = Drupal.t('<dt>Section:</dt><dd>@sections</dd>', {'@sections': ad.sectionName});

  // Rate MSG
  ad.msg.rate = Drupal.t("<dt>Rate:</dt><dd> @rate</dd>", {'@rate': ad.formRate});

  // Duration MSG
  ad.msg.duration = Drupal.t("<dt>Duration:</dt><dd> @duration weeks</dd>", {'@duration': ad.duration});
  ad.msg.durationSum = Drupal.t("<dt>Duration:</dt><dd>@duration weeks</dd>", {'@duration': ad.duration});
  if (ad.duration == '2') {
    ad.msg.durationWk3 = '(When you book for 2 weeks you get the 3rd for FREE!)';
    ad.msg.duration = Drupal.t("<dt>Duration:</dt><dd>@duration weeks @durationMsg</dd>", {'@duration': ad.duration, '@durationMsg': ad.msg.durationWk3});
  };

  // Image
  if (ad.imageFlag < 2) {
    ad.msg.image = Drupal.t("<dt>Image:</dt><dd>@imageMsg</dd>", {'@imageMsg': ad.imageMessage, '@imageFile': ad.imageFile});
  }
  else {
    ad.msg.image = '';
  };

  // Liveload
  ad.msg.type = Drupal.t("<dt>Ad Type:</dt><dd> @type</dd>", {'@type': ad.type});

  // PRICE
  ad.msg.priceSum = Drupal.t("<dt>Price:</dt><dd><ul class=\"price price-review\"><li class=\"price price-subtotal\">Subtotal: $@basePrice</li><li class=\"price price-extras\">Extras: $@extras</li><li class=\"price price-taxes\">Taxes: $@taxes</li><li class=\"price price-total\">Total: $@total</li></ul></dd>", {'@basePrice': price.subTotalRound,'@extras': price.extras, '@taxes': price.taxesRound,'@total': price.totalRound});
  ad.msg.priceOverview = Drupal.t("<dt>Price</dt><dd><ul class='price price-review'><li class='price price-subtotal'>Subtotal: $@subTotal</li><li class='price price-extras'>Extras: $@extras</li><li class='price price-taxes'> Taxes (@trate): $@taxes</li><li class='price price-total'>Total: $@priceTotal</li></dd>", {'@trate': price.taxRateDisplay, '@discount': ad.msg.discount, '@basePrice': price.basePrice, '@overPrice': price.overCount, '@subTotal': price.subTotalRound, '@extras': price.extras, '@taxes': price.taxesRound,'@priceTotal': price.totalRound});

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
  };

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
  //  '<fieldset id="review-ad-box-ad" class="review-ad-block field-group-fieldset form-wrapper">'
  //  + '<legend><span class="fieldset-legend">Ad Review</span></legend>'
      '<p></p>'
    + '<div id="ad-review-data" class="fieldset-wrapper">'
    + '<div id="review-ad-box-price" class="review-ad-block fieldset-legend">'
    + '<div id="ad-review-data">'
    + ad.msg.ad
    + ad.msg.error
    + '<dl>'
    + ad.msg.wordcount
    + ad.msg.countOver
    + ad.msg.areaList
    + ad.msg.section
    + ad.msg.rate
    + ad.msg.duration
    + ad.msg.type
    + ad.msg.image
    + '</dl>'
    + '</div>'
    + '<div id="ad-review-price" class="fieldset-legend">'
    + '<dl>'
    + ad.msg.priceOverview
    + '</dl>'
    + '</div>'
    + '</div>'
   // + '</fieldset>'
    ;

  ad.msg.storage =
      'wordcount = '      + ad.wordCount + ';'
    + 'duration = '       + ad.duration + ';'
    + 'duration_actual = '+ ad.durationPricing + ';'
    + 'wordcount_over = ' + ad.countOver + ';'
    + 'area_list = '      + ad.areaList + ';'
    + 'imageFlag = '      + ad.imageFlag + ';'
    + 'image = '          + ad.imageFile  + ';'
    + 'ad_type = '        + ad.typeBool + ';'
    + 'ad_type_name = '   + ad.type + ';'
    + 'rate = '           + ad.formRate + ';'
    + 'subtotal = '       + price.subTotalRound + ';'
    + 'discount = '       + price.discount + ';'
    + 'extras = '         + price.extras + ';'
    + 'taxes = '          + price.taxesRound + ';'
    + 'total = '          + price.totalRound + ';'
    ;
//console.log(ad.msg.storage);

  // SET FORM PRICE
  jQuery('#edit-field-price-und-0-value').val(price.totalRound);

  return ad.msg;
};


/**
 * PRIMARY EVENT HANDLING.
 *
 * Sidebar-first - summary
 * Content Review - hidden until submitting
 */

jQuery(document).ready(function() {

 // New form validation in case of multiple forms detected.
  if (jQuery('#ad-s-node-form').length) {

    // Hide Image Upload Button (uploading images always produces an error.
    jQuery('#edit-field-image-und-0-upload-button').hide();

    // jQuery('#edit-field-review').hide();

    // Hide Preview (unless jQuery is broken)...
    jQuery('#edit-preview').hide();

    // Get Settings
    var sideBar = '#sidebar-first > .section > .region';
    var summaryBox = Drupal.adPayment.displayMsg().summary;
    jQuery(sideBar).prepend(summaryBox);

    // Create DIV for OverView
    var boxDetails = '<div id="ad-review" class="ad-review-empty-box"> <div id="ad-summary" class="block summary-price-block ad-summary-directions"> <h4 class="ad-summary-header">Directions</h4><ul class="ad-summary-list"> <li>Begin by typing your ad in the <em>Ad Copy</em> box.</li> <li>Below that are your preferences for how & where you want your ad displayed.</li> <li>To get help your ad get noticed check out step <em>2: Options</em>.</li> <li>Enter credit card information in step <em>3: Payment</em>.</li> <li>When satisfied with your ad go to step <em>Review & Submit</em> to submit your finished ad.</li></ul></div></div>';
    jQuery('.group-ad-copy-block').prepend(boxDetails);

    // DIV for ReView
    var reviewLocation = '#edit-field-ad-details';
    jQuery(reviewLocation).prepend('<div id="review-ad-block"></div>');

    // DIV for credit card check
    var cardCheckBox = '<div id="cc-checkbox-check"></div>';
    jQuery('#edit-field-card-type').append(cardCheckBox);


    // create error box for validation
    var validationBox = '<div id="validation-box"></div>';
    jQuery('#ad-s-node-form').prepend(validationBox);

    // Review box
    var reviewButton = '#edit-field-review > .description';
    //jQuery(reviewButton).css('cursor', 'pointer');     // Create button appearance with pointer.
    jQuery(reviewButton).text('Review ad price before confirming submission.');

    // Credit Card Check
     // EXTERNAL CC VALIDATION SCRIPT
    jQuery('#ad-s-node-form').validate({
      rules: {
        field_cc_number: {
          required: true,
          creditcard: true
        }
      }
    });
    jQuery('#node_ad_s_form_group_payment').change( function() {
      console.log('Ad Submission CHANGE!');
      // Check Credit Card;
      var debitMsg = Drupal.adPayment.cardCheck();

      jQuery('#cc-checkbox-check').html(debitMsg);
    });

      console.log('Ad Submission !');

    jQuery('#ad-s-node-form').change( function() { // ON CHANGE event!
    //jQuery(reviewButton).click( function() { //Bind to CLICK event!
       //console.log('Ad Submission CHANGE!');
      jQuery(reviewButton).text('Updated price.');


      jQuery("body").css("cursor", "progress");


      var sideBox = '#ad-summary';
      var summaryBox = Drupal.adPayment.displayMsg().summary;
      jQuery(sideBox).html(summaryBox);

      // Review box
      var reviewLocation = '#review-ad-block';
      var reviewBox = Drupal.adPayment.displayMsg().review;
      jQuery(reviewLocation).html(reviewBox).show();

      //console.log(reviewBox);
      jQuery('#ad-review').html(summaryBox);
      jQuery('#ad-review > ').css({'font-weight':'800'});

      // Store Details for future processing.
      jQuery('#edit-field-ad-details-und-0-value').val(Drupal.adPayment.displayMsg().storage);

      jQuery("body").css("cursor", "auto");

    });

  };
});

}(jQuery));


;
/**
 * Form THeming.
 *
 * - Drop down menus etc.
 */
(function($) {

$(document).ready(function() {

// From http://ericlondon.com/posts/68-improving-form-validation-usability-for-checkboxes-and-radio-buttons
$('form#node-form div.form-item').each(function(){
  var result = 0;
  result += $(this).find('div.form-radios input.form-radio.error').length;
  result += $(this).find('div.form-checkboxes input.form-checkbox.error').length;
  if (result) $(this).find('label:first').removeClass('error').addClass('error');
});

  // Add Elements to Beauty Tips
  //var picture = "<div class=' beautytips form-toggle' id='bt-picture'>About pictures.</div>";
  //var imageBox = '<span id="bt-picture" class=" beautytips form-toggle">About Pictures</span>'
  //              + '<div id="beautytips-toggle-box-bt-picture" class="beautytips-box">'+description+'</div>';
  var description = $('.form-item-field-image-und-0 .description').html();
  $('.form-item-field-image-und-0 .description')
      .html('<div id="beautytips-toggle-box-bt-picture" class="beautytips-box">'+description+'</div>')
      .prepend('<span id="bt-picture" class=" beautytips form-toggle">About Pictures</span>');

  // Beauty tips replacement
  // - hide and show extra info for form submission.
  $('.beautytips-box').hide();
  $('.form-toggle').css('cursor', 'pointer').click(function() {
    $('#beautytips-toggle-box-'+($(this).attr('id'))).toggle('slow');
     console.log($(this).attr('id'));
  })

});

}(jQuery));;
/**
 * jQuery Validation Plugin @VERSION
 *
 * http://bassistance.de/jquery-plugins/jquery-plugin-validation/
 * http://docs.jquery.com/Plugins/Validation
 *
 * Copyright (c) 2012 J̦rn Zaefferer
 *
 * Dual licensed under the MIT and GPL licenses:
 *   http://www.opensource.org/licenses/mit-license.php
 *   http://www.gnu.org/licenses/gpl.html
 */

(function($) {

$.extend($.fn, {
	// http://docs.jquery.com/Plugins/Validation/validate
	validate: function( options ) {

		// if nothing is selected, return nothing; can't chain anyway
		if (!this.length) {
			if (options && options.debug && window.console) {
				console.warn( "nothing selected, can't validate, returning nothing" );
			}
			return;
		}

		// check if a validator for this form was already created
		var validator = $.data(this[0], 'validator');
		if ( validator ) {
			return validator;
		}

		// Add novalidate tag if HTML5.
		this.attr('novalidate', 'novalidate');

		validator = new $.validator( options, this[0] );
		$.data(this[0], 'validator', validator);

		if ( validator.settings.onsubmit ) {

			this.validateDelegate( ":submit", "click", function(ev) {
				if ( validator.settings.submitHandler ) {
					validator.submitButton = ev.target;
				}
				// allow suppressing validation by adding a cancel class to the submit button
				if ( $(ev.target).hasClass('cancel') ) {
					validator.cancelSubmit = true;
				}
			});

			// validate the form on submit
			this.submit( function( event ) {
				if ( validator.settings.debug ) {
					// prevent form submit to be able to see console output
					event.preventDefault();
				}
				function handle() {
					var hidden;
					if ( validator.settings.submitHandler ) {
						if (validator.submitButton) {
							// insert a hidden input as a replacement for the missing submit button
							hidden = $("<input type='hidden'/>").attr("name", validator.submitButton.name).val(validator.submitButton.value).appendTo(validator.currentForm);
						}
						validator.settings.submitHandler.call( validator, validator.currentForm, event );
						if (validator.submitButton) {
							// and clean up afterwards; thanks to no-block-scope, hidden can be referenced
							hidden.remove();
						}
						return false;
					}
					return true;
				}

				// prevent submit for invalid forms or custom submit handlers
				if ( validator.cancelSubmit ) {
					validator.cancelSubmit = false;
					return handle();
				}
				if ( validator.form() ) {
					if ( validator.pendingRequest ) {
						validator.formSubmitted = true;
						return false;
					}
					return handle();
				} else {
					validator.focusInvalid();
					return false;
				}
			});
		}

		return validator;
	},
	// http://docs.jquery.com/Plugins/Validation/valid
	valid: function() {
		if ( $(this[0]).is('form')) {
			return this.validate().form();
		} else {
			var valid = true;
			var validator = $(this[0].form).validate();
			this.each(function() {
				valid &= validator.element(this);
			});
			return valid;
		}
	},
	// attributes: space seperated list of attributes to retrieve and remove
	removeAttrs: function(attributes) {
		var result = {},
			$element = this;
		$.each(attributes.split(/\s/), function(index, value) {
			result[value] = $element.attr(value);
			$element.removeAttr(value);
		});
		return result;
	},
	// http://docs.jquery.com/Plugins/Validation/rules
	rules: function(command, argument) {
		var element = this[0];

		if (command) {
			var settings = $.data(element.form, 'validator').settings;
			var staticRules = settings.rules;
			var existingRules = $.validator.staticRules(element);
			switch(command) {
			case "add":
				$.extend(existingRules, $.validator.normalizeRule(argument));
				staticRules[element.name] = existingRules;
				if (argument.messages) {
					settings.messages[element.name] = $.extend( settings.messages[element.name], argument.messages );
				}
				break;
			case "remove":
				if (!argument) {
					delete staticRules[element.name];
					return existingRules;
				}
				var filtered = {};
				$.each(argument.split(/\s/), function(index, method) {
					filtered[method] = existingRules[method];
					delete existingRules[method];
				});
				return filtered;
			}
		}

		var data = $.validator.normalizeRules(
		$.extend(
			{},
			$.validator.metadataRules(element),
			$.validator.classRules(element),
			$.validator.attributeRules(element),
			$.validator.staticRules(element)
		), element);

		// make sure required is at front
		if (data.required) {
			var param = data.required;
			delete data.required;
			data = $.extend({required: param}, data);
		}

		return data;
	}
});

// Custom selectors
$.extend($.expr[":"], {
	// http://docs.jquery.com/Plugins/Validation/blank
	blank: function(a) {return !$.trim("" + a.value);},
	// http://docs.jquery.com/Plugins/Validation/filled
	filled: function(a) {return !!$.trim("" + a.value);},
	// http://docs.jquery.com/Plugins/Validation/unchecked
	unchecked: function(a) {return !a.checked;}
});

// constructor for validator
$.validator = function( options, form ) {
	this.settings = $.extend( true, {}, $.validator.defaults, options );
	this.currentForm = form;
	this.init();
};

$.validator.format = function(source, params) {
	if ( arguments.length === 1 ) {
		return function() {
			var args = $.makeArray(arguments);
			args.unshift(source);
			return $.validator.format.apply( this, args );
		};
	}
	if ( arguments.length > 2 && params.constructor !== Array  ) {
		params = $.makeArray(arguments).slice(1);
	}
	if ( params.constructor !== Array ) {
		params = [ params ];
	}
	$.each(params, function(i, n) {
		source = source.replace(new RegExp("\\{" + i + "\\}", "g"), n);
	});
	return source;
};

$.extend($.validator, {

	defaults: {
		messages: {},
		groups: {},
		rules: {},
		errorClass: "error",
		validClass: "valid",
		errorElement: "label",
		focusInvalid: true,
		errorContainer: $( [] ),
		errorLabelContainer: $( [] ),
		onsubmit: true,
		ignore: ":hidden",
		ignoreTitle: false,
		onfocusin: function(element, event) {
			this.lastActive = element;

			// hide error label and remove error class on focus if enabled
			if ( this.settings.focusCleanup && !this.blockFocusCleanup ) {
				if ( this.settings.unhighlight ) {
					this.settings.unhighlight.call( this, element, this.settings.errorClass, this.settings.validClass );
				}
				this.addWrapper(this.errorsFor(element)).hide();
			}
		},
		onfocusout: function(element, event) {
			if ( !this.checkable(element) && (element.name in this.submitted || !this.optional(element)) ) {
				this.element(element);
			}
		},
		onkeyup: function(element, event) {
			if ( event.which == 9 && this.elementValue(element) === '' ) {
				return;
			} else if ( element.name in this.submitted || element === this.lastActive ) {
				this.element(element);
			}
		},
		onclick: function(element, event) {
			// click on selects, radiobuttons and checkboxes
			if ( element.name in this.submitted ) {
				this.element(element);
			}
			// or option elements, check parent select in that case
			else if (element.parentNode.name in this.submitted) {
				this.element(element.parentNode);
			}
		},
		highlight: function(element, errorClass, validClass) {
			if (element.type === 'radio') {
				this.findByName(element.name).addClass(errorClass).removeClass(validClass);
			} else {
				$(element).addClass(errorClass).removeClass(validClass);
			}
		},
		unhighlight: function(element, errorClass, validClass) {
			if (element.type === 'radio') {
				this.findByName(element.name).removeClass(errorClass).addClass(validClass);
			} else {
				$(element).removeClass(errorClass).addClass(validClass);
			}
		}
	},

	// http://docs.jquery.com/Plugins/Validation/Validator/setDefaults
	setDefaults: function(settings) {
		$.extend( $.validator.defaults, settings );
	},

	messages: {
		required: "This field is required.",
		remote: "Please fix this field.",
		email: "Please enter a valid email address.",
		url: "Please enter a valid URL.",
		date: "Please enter a valid date.",
		dateISO: "Please enter a valid date (ISO).",
		number: "Please enter a valid number.",
		digits: "Please enter only digits.",
		creditcard: "Please enter a valid credit card number.",
		equalTo: "Please enter the same value again.",
		maxlength: $.validator.format("Please enter no more than {0} characters."),
		minlength: $.validator.format("Please enter at least {0} characters."),
		rangelength: $.validator.format("Please enter a value between {0} and {1} characters long."),
		range: $.validator.format("Please enter a value between {0} and {1}."),
		max: $.validator.format("Please enter a value less than or equal to {0}."),
		min: $.validator.format("Please enter a value greater than or equal to {0}.")
	},

	autoCreateRanges: false,

	prototype: {

		init: function() {
			this.labelContainer = $(this.settings.errorLabelContainer);
			this.errorContext = this.labelContainer.length && this.labelContainer || $(this.currentForm);
			this.containers = $(this.settings.errorContainer).add( this.settings.errorLabelContainer );
			this.submitted = {};
			this.valueCache = {};
			this.pendingRequest = 0;
			this.pending = {};
			this.invalid = {};
			this.reset();

			var groups = (this.groups = {});
			$.each(this.settings.groups, function(key, value) {
				$.each(value.split(/\s/), function(index, name) {
					groups[name] = key;
				});
			});
			var rules = this.settings.rules;
			$.each(rules, function(key, value) {
				rules[key] = $.validator.normalizeRule(value);
			});

			function delegate(event) {
				var validator = $.data(this[0].form, "validator"),
					eventType = "on" + event.type.replace(/^validate/, "");
				if (validator.settings[eventType]) {
					validator.settings[eventType].call(validator, this[0], event);
				}
			}
			$(this.currentForm)
				.validateDelegate(":text, [type='password'], [type='file'], select, textarea, " +
					"[type='number'], [type='search'] ,[type='tel'], [type='url'], " +
					"[type='email'], [type='datetime'], [type='date'], [type='month'], " +
					"[type='week'], [type='time'], [type='datetime-local'], " +
					"[type='range'], [type='color'] ",
					"focusin focusout keyup", delegate)
				.validateDelegate("[type='radio'], [type='checkbox'], select, option", "click", delegate);

			if (this.settings.invalidHandler) {
				$(this.currentForm).bind("invalid-form.validate", this.settings.invalidHandler);
			}
		},

		// http://docs.jquery.com/Plugins/Validation/Validator/form
		form: function() {
			this.checkForm();
			$.extend(this.submitted, this.errorMap);
			this.invalid = $.extend({}, this.errorMap);
			if (!this.valid()) {
				$(this.currentForm).triggerHandler("invalid-form", [this]);
			}
			this.showErrors();
			return this.valid();
		},

		checkForm: function() {
			this.prepareForm();
			for ( var i = 0, elements = (this.currentElements = this.elements()); elements[i]; i++ ) {
				this.check( elements[i] );
			}
			return this.valid();
		},

		// http://docs.jquery.com/Plugins/Validation/Validator/element
		element: function( element ) {
			element = this.validationTargetFor( this.clean( element ) );
			this.lastElement = element;
			this.prepareElement( element );
			this.currentElements = $(element);
			var result = this.check( element ) !== false;
			if (result) {
				delete this.invalid[element.name];
			} else {
				this.invalid[element.name] = true;
			}
			if ( !this.numberOfInvalids() ) {
				// Hide error containers on last error
				this.toHide = this.toHide.add( this.containers );
			}
			this.showErrors();
			return result;
		},

		// http://docs.jquery.com/Plugins/Validation/Validator/showErrors
		showErrors: function(errors) {
			if(errors) {
				// add items to error list and map
				$.extend( this.errorMap, errors );
				this.errorList = [];
				for ( var name in errors ) {
					this.errorList.push({
						message: errors[name],
						element: this.findByName(name)[0]
					});
				}
				// remove items from success list
				this.successList = $.grep( this.successList, function(element) {
					return !(element.name in errors);
				});
			}
			if (this.settings.showErrors) {
				this.settings.showErrors.call( this, this.errorMap, this.errorList );
			} else {
				this.defaultShowErrors();
			}
		},

		// http://docs.jquery.com/Plugins/Validation/Validator/resetForm
		resetForm: function() {
			if ( $.fn.resetForm ) {
				$( this.currentForm ).resetForm();
			}
			this.submitted = {};
			this.lastElement = null;
			this.prepareForm();
			this.hideErrors();
			this.elements().removeClass( this.settings.errorClass ).removeData( "previousValue" );
		},

		numberOfInvalids: function() {
			return this.objectLength(this.invalid);
		},

		objectLength: function( obj ) {
			var count = 0;
			for ( var i in obj ) {
				count++;
			}
			return count;
		},

		hideErrors: function() {
			this.addWrapper( this.toHide ).hide();
		},

		valid: function() {
			return this.size() === 0;
		},

		size: function() {
			return this.errorList.length;
		},

		focusInvalid: function() {
			if( this.settings.focusInvalid ) {
				try {
					$(this.findLastActive() || this.errorList.length && this.errorList[0].element || [])
					.filter(":visible")
					.focus()
					// manually trigger focusin event; without it, focusin handler isn't called, findLastActive won't have anything to find
					.trigger("focusin");
				} catch(e) {
					// ignore IE throwing errors when focusing hidden elements
				}
			}
		},

		findLastActive: function() {
			var lastActive = this.lastActive;
			return lastActive && $.grep(this.errorList, function(n) {
				return n.element.name === lastActive.name;
			}).length === 1 && lastActive;
		},

		elements: function() {
			var validator = this,
				rulesCache = {};

			// select all valid inputs inside the form (no submit or reset buttons)
			return $(this.currentForm)
			.find("input, select, textarea")
			.not(":submit, :reset, :image, [disabled]")
			.not( this.settings.ignore )
			.filter(function() {
				if ( !this.name && validator.settings.debug && window.console ) {
					console.error( "%o has no name assigned", this);
				}

				// select only the first element for each name, and only those with rules specified
				if ( this.name in rulesCache || !validator.objectLength($(this).rules()) ) {
					return false;
				}

				rulesCache[this.name] = true;
				return true;
			});
		},

		clean: function( selector ) {
			return $( selector )[0];
		},

		errors: function() {
			var errorClass = this.settings.errorClass.replace(' ', '.');
			return $( this.settings.errorElement + "." + errorClass, this.errorContext );
		},

		reset: function() {
			this.successList = [];
			this.errorList = [];
			this.errorMap = {};
			this.toShow = $([]);
			this.toHide = $([]);
			this.currentElements = $([]);
		},

		prepareForm: function() {
			this.reset();
			this.toHide = this.errors().add( this.containers );
		},

		prepareElement: function( element ) {
			this.reset();
			this.toHide = this.errorsFor(element);
		},

		elementValue: function( element ) {
			var type = $(element).attr('type'),
				val = $(element).val();

			if ( type === 'radio' || type === 'checkbox' ) {
				return $('input[name="' + $(element).attr('name') + '"]:checked').val();
			}

			if ( typeof val === 'string' ) {
				return val.replace(/\r/g, "");
			}
			return val;
		},

		check: function( element ) {
			element = this.validationTargetFor( this.clean( element ) );

			var rules = $(element).rules();
			var dependencyMismatch = false;
			var val = this.elementValue(element);
			var result;

			for (var method in rules ) {
				var rule = { method: method, parameters: rules[method] };
				try {

					result = $.validator.methods[method].call( this, val, element, rule.parameters );

					// if a method indicates that the field is optional and therefore valid,
					// don't mark it as valid when there are no other rules
					if ( result === "dependency-mismatch" ) {
						dependencyMismatch = true;
						continue;
					}
					dependencyMismatch = false;

					if ( result === "pending" ) {
						this.toHide = this.toHide.not( this.errorsFor(element) );
						return;
					}

					if( !result ) {
						this.formatAndAdd( element, rule );
						return false;
					}
				} catch(e) {
					if ( this.settings.debug && window.console ) {
						console.log("exception occured when checking element " + element.id + ", check the '" + rule.method + "' method", e);
					}
					throw e;
				}
			}
			if (dependencyMismatch) {
				return;
			}
			if ( this.objectLength(rules) ) {
				this.successList.push(element);
			}
			return true;
		},

		// return the custom message for the given element and validation method
		// specified in the element's "messages" metadata
		customMetaMessage: function(element, method) {
			if (!$.metadata) {
				return;
			}
			var meta = this.settings.meta ? $(element).metadata()[this.settings.meta] : $(element).metadata();
			return meta && meta.messages && meta.messages[method];
		},

		// return the custom message for the given element and validation method
		// specified in the element's HTML5 data attribute
		customDataMessage: function(element, method) {
			return $(element).data('msg-' + method.toLowerCase()) || (element.attributes && $(element).attr('data-msg-' + method.toLowerCase()));
		},

		// return the custom message for the given element name and validation method
		customMessage: function( name, method ) {
			var m = this.settings.messages[name];
			return m && (m.constructor === String ? m : m[method]);
		},

		// return the first defined argument, allowing empty strings
		findDefined: function() {
			for(var i = 0; i < arguments.length; i++) {
				if (arguments[i] !== undefined) {
					return arguments[i];
				}
			}
			return undefined;
		},

		defaultMessage: function( element, method) {
			return this.findDefined(
				this.customMessage( element.name, method ),
				this.customDataMessage( element, method ),
				this.customMetaMessage( element, method ),
				// title is never undefined, so handle empty string as undefined
				!this.settings.ignoreTitle && element.title || undefined,
				$.validator.messages[method],
				"<strong>Warning: No message defined for " + element.name + "</strong>"
			);
		},

		formatAndAdd: function( element, rule ) {
			var message = this.defaultMessage( element, rule.method ),
				theregex = /\$?\{(\d+)\}/g;
			if ( typeof message === "function" ) {
				message = message.call(this, rule.parameters, element);
			} else if (theregex.test(message)) {
				message = $.validator.format(message.replace(theregex, '{$1}'), rule.parameters);
			}
			this.errorList.push({
				message: message,
				element: element
			});

			this.errorMap[element.name] = message;
			this.submitted[element.name] = message;
		},

		addWrapper: function(toToggle) {
			if ( this.settings.wrapper ) {
				toToggle = toToggle.add( toToggle.parent( this.settings.wrapper ) );
			}
			return toToggle;
		},

		defaultShowErrors: function() {
			var i, elements;
			for ( i = 0; this.errorList[i]; i++ ) {
				var error = this.errorList[i];
				if ( this.settings.highlight ) {
					this.settings.highlight.call( this, error.element, this.settings.errorClass, this.settings.validClass );
				}
				this.showLabel( error.element, error.message );
			}
			if( this.errorList.length ) {
				this.toShow = this.toShow.add( this.containers );
			}
			if (this.settings.success) {
				for ( i = 0; this.successList[i]; i++ ) {
					this.showLabel( this.successList[i] );
				}
			}
			if (this.settings.unhighlight) {
				for ( i = 0, elements = this.validElements(); elements[i]; i++ ) {
					this.settings.unhighlight.call( this, elements[i], this.settings.errorClass, this.settings.validClass );
				}
			}
			this.toHide = this.toHide.not( this.toShow );
			this.hideErrors();
			this.addWrapper( this.toShow ).show();
		},

		validElements: function() {
			return this.currentElements.not(this.invalidElements());
		},

		invalidElements: function() {
			return $(this.errorList).map(function() {
				return this.element;
			});
		},

		showLabel: function(element, message) {
			var label = this.errorsFor( element );
			if ( label.length ) {
				// refresh error/success class
				label.removeClass( this.settings.validClass ).addClass( this.settings.errorClass );

				// check if we have a generated label, replace the message then
				if ( label.attr("generated") ) {
					label.html(message);
				}
			} else {
				// create label
				label = $("<" + this.settings.errorElement + "/>")
					.attr({"for":  this.idOrName(element), generated: true})
					.addClass(this.settings.errorClass)
					.html(message || "");
				if ( this.settings.wrapper ) {
					// make sure the element is visible, even in IE
					// actually showing the wrapped element is handled elsewhere
					label = label.hide().show().wrap("<" + this.settings.wrapper + "/>").parent();
				}
				if ( !this.labelContainer.append(label).length ) {
					if ( this.settings.errorPlacement ) {
						this.settings.errorPlacement(label, $(element) );
					} else {
					label.insertAfter(element);
					}
				}
			}
			if ( !message && this.settings.success ) {
				label.text("");
				if ( typeof this.settings.success === "string" ) {
					label.addClass( this.settings.success );
				} else {
					this.settings.success( label, element );
				}
			}
			this.toShow = this.toShow.add(label);
		},

		errorsFor: function(element) {
			var name = this.idOrName(element);
			return this.errors().filter(function() {
				return $(this).attr('for') === name;
			});
		},

		idOrName: function(element) {
			return this.groups[element.name] || (this.checkable(element) ? element.name : element.id || element.name);
		},

		validationTargetFor: function(element) {
			// if radio/checkbox, validate first element in group instead
			if (this.checkable(element)) {
				element = this.findByName( element.name ).not(this.settings.ignore)[0];
			}
			return element;
		},

		checkable: function( element ) {
			return (/radio|checkbox/i).test(element.type);
		},

		findByName: function( name ) {
			return $(this.currentForm).find('[name="' + name + '"]');
		},

		getLength: function(value, element) {
			switch( element.nodeName.toLowerCase() ) {
			case 'select':
				return $("option:selected", element).length;
			case 'input':
				if( this.checkable( element) ) {
					return this.findByName(element.name).filter(':checked').length;
				}
			}
			return value.length;
		},

		depend: function(param, element) {
			return this.dependTypes[typeof param] ? this.dependTypes[typeof param](param, element) : true;
		},

		dependTypes: {
			"boolean": function(param, element) {
				return param;
			},
			"string": function(param, element) {
				return !!$(param, element.form).length;
			},
			"function": function(param, element) {
				return param(element);
			}
		},

		optional: function(element) {
			var val = this.elementValue(element);
			return !$.validator.methods.required.call(this, val, element) && "dependency-mismatch";
		},

		startRequest: function(element) {
			if (!this.pending[element.name]) {
				this.pendingRequest++;
				this.pending[element.name] = true;
			}
		},

		stopRequest: function(element, valid) {
			this.pendingRequest--;
			// sometimes synchronization fails, make sure pendingRequest is never < 0
			if (this.pendingRequest < 0) {
				this.pendingRequest = 0;
			}
			delete this.pending[element.name];
			if ( valid && this.pendingRequest === 0 && this.formSubmitted && this.form() ) {
				$(this.currentForm).submit();
				this.formSubmitted = false;
			} else if (!valid && this.pendingRequest === 0 && this.formSubmitted) {
				$(this.currentForm).triggerHandler("invalid-form", [this]);
				this.formSubmitted = false;
			}
		},

		previousValue: function(element) {
			return $.data(element, "previousValue") || $.data(element, "previousValue", {
				old: null,
				valid: true,
				message: this.defaultMessage( element, "remote" )
			});
		}

	},

	classRuleSettings: {
		required: {required: true},
		email: {email: true},
		url: {url: true},
		date: {date: true},
		dateISO: {dateISO: true},
		number: {number: true},
		digits: {digits: true},
		creditcard: {creditcard: true}
	},

	addClassRules: function(className, rules) {
		if ( className.constructor === String ) {
			this.classRuleSettings[className] = rules;
		} else {
			$.extend(this.classRuleSettings, className);
		}
	},

	classRules: function(element) {
		var rules = {};
		var classes = $(element).attr('class');
		if ( classes ) {
			$.each(classes.split(' '), function() {
				if (this in $.validator.classRuleSettings) {
					$.extend(rules, $.validator.classRuleSettings[this]);
				}
			});
		}
		return rules;
	},

	attributeRules: function(element) {
		var rules = {};
		var $element = $(element);

		for (var method in $.validator.methods) {
			var value;

			// support for <input required> in both html5 and older browsers
			if (method === 'required') {
				value = $element.get(0).getAttribute(method);
				// Some browsers return an empty string for the required attribute
				// and non-HTML5 browsers might have required="" markup
				if (value === "") {
					value = true;
				}
				// force non-HTML5 browsers to return bool
				value = !!value;
			} else {
				value = $element.attr(method);
			}

			if (value) {
				rules[method] = value;
			} else if ($element[0].getAttribute("type") === method) {
				rules[method] = true;
			}
		}

		// maxlength may be returned as -1, 2147483647 (IE) and 524288 (safari) for text inputs
		if (rules.maxlength && /-1|2147483647|524288/.test(rules.maxlength)) {
			delete rules.maxlength;
		}

		return rules;
	},

	metadataRules: function(element) {
		if (!$.metadata) {
			return {};
		}

		var meta = $.data(element.form, 'validator').settings.meta;
		return meta ?
			$(element).metadata()[meta] :
			$(element).metadata();
	},

	staticRules: function(element) {
		var rules = {};
		var validator = $.data(element.form, 'validator');
		if (validator.settings.rules) {
			rules = $.validator.normalizeRule(validator.settings.rules[element.name]) || {};
		}
		return rules;
	},

	normalizeRules: function(rules, element) {
		// handle dependency check
		$.each(rules, function(prop, val) {
			// ignore rule when param is explicitly false, eg. required:false
			if (val === false) {
				delete rules[prop];
				return;
			}
			if (val.param || val.depends) {
				var keepRule = true;
				switch (typeof val.depends) {
					case "string":
						keepRule = !!$(val.depends, element.form).length;
						break;
					case "function":
						keepRule = val.depends.call(element, element);
						break;
				}
				if (keepRule) {
					rules[prop] = val.param !== undefined ? val.param : true;
				} else {
					delete rules[prop];
				}
			}
		});

		// evaluate parameters
		$.each(rules, function(rule, parameter) {
			rules[rule] = $.isFunction(parameter) ? parameter(element) : parameter;
		});

		// clean number parameters
		$.each(['minlength', 'maxlength', 'min', 'max'], function() {
			if (rules[this]) {
				rules[this] = Number(rules[this]);
			}
		});
		$.each(['rangelength', 'range'], function() {
			if (rules[this]) {
				rules[this] = [Number(rules[this][0]), Number(rules[this][1])];
			}
		});

		if ($.validator.autoCreateRanges) {
			// auto-create ranges
			if (rules.min && rules.max) {
				rules.range = [rules.min, rules.max];
				delete rules.min;
				delete rules.max;
			}
			if (rules.minlength && rules.maxlength) {
				rules.rangelength = [rules.minlength, rules.maxlength];
				delete rules.minlength;
				delete rules.maxlength;
			}
		}

		// To support custom messages in metadata ignore rule methods titled "messages"
		if (rules.messages) {
			delete rules.messages;
		}

		return rules;
	},

	// Converts a simple string to a {string: true} rule, e.g., "required" to {required:true}
	normalizeRule: function(data) {
		if( typeof data === "string" ) {
			var transformed = {};
			$.each(data.split(/\s/), function() {
				transformed[this] = true;
			});
			data = transformed;
		}
		return data;
	},

	// http://docs.jquery.com/Plugins/Validation/Validator/addMethod
	addMethod: function(name, method, message) {
		$.validator.methods[name] = method;
		$.validator.messages[name] = message !== undefined ? message : $.validator.messages[name];
		if (method.length < 3) {
			$.validator.addClassRules(name, $.validator.normalizeRule(name));
		}
	},

	methods: {

		// http://docs.jquery.com/Plugins/Validation/Methods/required
		required: function(value, element, param) {
			// check if dependency is met
			if ( !this.depend(param, element) ) {
				return "dependency-mismatch";
			}
			if ( element.nodeName.toLowerCase() === "select" ) {
				// could be an array for select-multiple or a string, both are fine this way
				var val = $(element).val();
				return val && val.length > 0;
			}
			if ( this.checkable(element) ) {
				return this.getLength(value, element) > 0;
			}
			return $.trim(value).length > 0;
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/remote
		remote: function(value, element, param) {
			if ( this.optional(element) ) {
				return "dependency-mismatch";
			}

			var previous = this.previousValue(element);
			if (!this.settings.messages[element.name] ) {
				this.settings.messages[element.name] = {};
			}
			previous.originalMessage = this.settings.messages[element.name].remote;
			this.settings.messages[element.name].remote = previous.message;

			param = typeof param === "string" && {url:param} || param;

			if ( this.pending[element.name] ) {
				return "pending";
			}
			if ( previous.old === value ) {
				return previous.valid;
			}

			previous.old = value;
			var validator = this;
			this.startRequest(element);
			var data = {};
			data[element.name] = value;
			$.ajax($.extend(true, {
				url: param,
				mode: "abort",
				port: "validate" + element.name,
				dataType: "json",
				data: data,
				success: function(response) {
					validator.settings.messages[element.name].remote = previous.originalMessage;
					var valid = response === true || response === "true";
					if ( valid ) {
						var submitted = validator.formSubmitted;
						validator.prepareElement(element);
						validator.formSubmitted = submitted;
						validator.successList.push(element);
						delete validator.invalid[element.name];
						validator.showErrors();
					} else {
						var errors = {};
						var message = response || validator.defaultMessage( element, "remote" );
						errors[element.name] = previous.message = $.isFunction(message) ? message(value) : message;
						validator.invalid[element.name] = true;
						validator.showErrors(errors);
					}
					previous.valid = valid;
					validator.stopRequest(element, valid);
				}
			}, param));
			return "pending";
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/minlength
		minlength: function(value, element, param) {
			var length = $.isArray( value ) ? value.length : this.getLength($.trim(value), element);
			return this.optional(element) || length >= param;
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/maxlength
		maxlength: function(value, element, param) {
			var length = $.isArray( value ) ? value.length : this.getLength($.trim(value), element);
			return this.optional(element) || length <= param;
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/rangelength
		rangelength: function(value, element, param) {
			var length = $.isArray( value ) ? value.length : this.getLength($.trim(value), element);
			return this.optional(element) || ( length >= param[0] && length <= param[1] );
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/min
		min: function( value, element, param ) {
			return this.optional(element) || value >= param;
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/max
		max: function( value, element, param ) {
			return this.optional(element) || value <= param;
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/range
		range: function( value, element, param ) {
			return this.optional(element) || ( value >= param[0] && value <= param[1] );
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/email
		email: function(value, element) {
			// contributed by Scott Gonzalez: http://projects.scottsplayground.com/email_address_validation/
			return this.optional(element) || /^((([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+(\.([a-z]|\d|[!#\$%&'\*\+\-\/=\?\^_`{\|}~]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])+)*)|((\x22)((((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(([\x01-\x08\x0b\x0c\x0e-\x1f\x7f]|\x21|[\x23-\x5b]|[\x5d-\x7e]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(\\([\x01-\x09\x0b\x0c\x0d-\x7f]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF]))))*(((\x20|\x09)*(\x0d\x0a))?(\x20|\x09)+)?(\x22)))@((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))$/i.test(value);
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/url
		url: function(value, element) {
			// contributed by Scott Gonzalez: http://projects.scottsplayground.com/iri/
			return this.optional(element) || /^(https?|ftp):\/\/(((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:)*@)?(((\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5])\.(\d|[1-9]\d|1\d\d|2[0-4]\d|25[0-5]))|((([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|\d|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.)+(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])*([a-z]|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])))\.?)(:\d*)?)(\/((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)+(\/(([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)*)*)?)?(\?((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)|[\uE000-\uF8FF]|\/|\?)*)?(\#((([a-z]|\d|-|\.|_|~|[\u00A0-\uD7FF\uF900-\uFDCF\uFDF0-\uFFEF])|(%[\da-f]{2})|[!\$&'\(\)\*\+,;=]|:|@)|\/|\?)*)?$/i.test(value);
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/date
		date: function(value, element) {
			return this.optional(element) || !/Invalid|NaN/.test(new Date(value));
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/dateISO
		dateISO: function(value, element) {
			return this.optional(element) || /^\d{4}[\/\-]\d{1,2}[\/\-]\d{1,2}$/.test(value);
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/number
		number: function(value, element) {
			return this.optional(element) || /^-?(?:\d+|\d{1,3}(?:,\d{3})+)?(?:\.\d+)?$/.test(value);
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/digits
		digits: function(value, element) {
			return this.optional(element) || /^\d+$/.test(value);
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/creditcard
		// based on http://en.wikipedia.org/wiki/Luhn
		creditcard: function(value, element) {
			if ( this.optional(element) ) {
				return "dependency-mismatch";
			}
			// accept only spaces, digits and dashes
			if (/[^0-9 \-]+/.test(value)) {
				return false;
			}
			var nCheck = 0,
				nDigit = 0,
				bEven = false;

			value = value.replace(/\D/g, "");

			for (var n = value.length - 1; n >= 0; n--) {
				var cDigit = value.charAt(n);
				nDigit = parseInt(cDigit, 10);
				if (bEven) {
					if ((nDigit *= 2) > 9) {
						nDigit -= 9;
					}
				}
				nCheck += nDigit;
				bEven = !bEven;
			}

			return (nCheck % 10) === 0;
		},

		// http://docs.jquery.com/Plugins/Validation/Methods/equalTo
		equalTo: function(value, element, param) {
			// bind to the blur event of the target in order to revalidate whenever the target field is updated
			// TODO find a way to bind the event just once, avoiding the unbind-rebind overhead
			var target = $(param);
			if (this.settings.onfocusout) {
				target.unbind(".validate-equalTo").bind("blur.validate-equalTo", function() {
					$(element).valid();
				});
			}
			return value === target.val();
		}

	}

});

// deprecated, use $.validator.format instead
$.format = $.validator.format;

}(jQuery));

// ajax mode: abort
// usage: $.ajax({ mode: "abort"[, port: "uniqueport"]});
// if mode:"abort" is used, the previous request on that port (port can be undefined) is aborted via XMLHttpRequest.abort()
(function($) {
	var pendingRequests = {};
	// Use a prefilter if available (1.5+)
	if ( $.ajaxPrefilter ) {
		$.ajaxPrefilter(function(settings, _, xhr) {
			var port = settings.port;
			if (settings.mode === "abort") {
				if ( pendingRequests[port] ) {
					pendingRequests[port].abort();
				}
				pendingRequests[port] = xhr;
			}
		});
	} else {
		// Proxy ajax
		var ajax = $.ajax;
		$.ajax = function(settings) {
			var mode = ( "mode" in settings ? settings : $.ajaxSettings ).mode,
				port = ( "port" in settings ? settings : $.ajaxSettings ).port;
			if (mode === "abort") {
				if ( pendingRequests[port] ) {
					pendingRequests[port].abort();
				}
				return (pendingRequests[port] = ajax.apply(this, arguments));
			}
			return ajax.apply(this, arguments);
		};
	}
}(jQuery));

// provides cross-browser focusin and focusout events
// IE has native support, in other browsers, use event caputuring (neither bubbles)

// provides delegate(type: String, delegate: Selector, handler: Callback) plugin for easier event delegation
// handler is only called when $(event.target).is(delegate), in the scope of the jquery-object for event.target
(function($) {
	// only implement if not provided by jQuery core (since 1.4)
	// TODO verify if jQuery 1.4's implementation is compatible with older jQuery special-event APIs
	if (!jQuery.event.special.focusin && !jQuery.event.special.focusout && document.addEventListener) {
		$.each({
			focus: 'focusin',
			blur: 'focusout'
		}, function( original, fix ){
			$.event.special[fix] = {
				setup:function() {
					this.addEventListener( original, handler, true );
				},
				teardown:function() {
					this.removeEventListener( original, handler, true );
				},
				handler: function(e) {
					var args = arguments;
					args[0] = $.event.fix(e);
					args[0].type = fix;
					return $.event.handle.apply(this, args);
				}
			};
			function handler(e) {
				e = $.event.fix(e);
				e.type = fix;
				return $.event.handle.call(this, e);
			}
		});
	}
	$.extend($.fn, {
		validateDelegate: function(delegate, type, handler) {
			return this.bind(type, function(event) {
				var target = $(event.target);
				if (target.is(delegate)) {
					return handler.apply(target, arguments);
				}
			});
		}
	});
}(jQuery));;
(function($) {

$(document).ready(function() {
  // jCarousel fixer.
  if($('#imageScroller').length > 0) {
    $('#imageScroller').jcarousel({ scroll :1, itemFallbackDimension:280 });
  }
  // Toggle For Hiding/Unhiding Ad Submission 'More' Data
  // Hide all content that needs to hide.
  if ($('.ad-details-toggle-box-content').length > 0) {
    $('.ad-details-toggle-box-content').hide();
  }

  // When switch is activated use it's CLASS and then find it's ID pair and toggle it.
  $('[id^=ad-details-toggle-box-switch-]').click(function() {
    $('#ad-details-'+($(this).attr('class'))).toggle('slow');
  });

  //Area Phone Codes show-hide
  if ($('.page-taxonomy-term').length > 0) {
    $('.page-taxonomy-term #phone-calling-codes, #phone-calling-codes-title').hide();
    $('#block-pennywise-pw-phone-areas .block-title').css('cursor', 'pointer').click(function() {
      $('#phone-calling-codes, #phone-calling-codes-title').toggle();
      // Do masonry on it.
      $('#phone-calling-codes').masonry({
        itemSelector : '.city-phone-group',
        columnWidth : 200,
      })
      return false;
    });
  }
  else {
    $('#block-pennywise-pw-phone-areas').hide();
  }
})

}(jQuery));;
