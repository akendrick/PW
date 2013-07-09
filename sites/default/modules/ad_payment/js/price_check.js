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
    jQuery(reviewButton).css('cursor', 'pointer');     // Create button appearance with pointer.

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
      // Check Credit Card;
      var debitMsg = Drupal.adPayment.cardCheck();
      // console.log('MSG: ' + debitMsg);
      jQuery('#cc-checkbox-check').html(debitMsg);
    });


    //jQuery('#ad-s-node-form').change( function() { // Old change event!
    jQuery(reviewButton).change( function() { //Bind the change event!
      jQuery(reviewButton).text('Click to update price.');


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


