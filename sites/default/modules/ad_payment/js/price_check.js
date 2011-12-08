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
  var price = {};

  // Get Rate
  if (ad.formRate == 'Personal') {
    price.rate = 'Personal';
    price.base = 3.5;
    price.word = .2;
    price.img  = 1.99;    
    price.promote = 5;
  }
  else if (ad.formRate == 'Business'){
    price.rate = 'Business';
    price.base = 5;
    price.word = .4;
    price.img  = 2.99;    
    price.promote = 5;
  };
  
  // CALCULATE PRICE
  // If no area selected use default one.
  ad.area = (ad.area == 0) ? 1 : ad.area;

  // Base rate + overflow word count
  price.overCount = (ad.wordCount > 15) ? ad.countOver * price.word : 0 ;
  price.basePrice = price.base + price.overCount;

  // Adjusted with duration and areas
  price.adjPrice = price.basePrice * ad.duration * ad.area;

  // If booking all 4 areas get $1 off.
  price.discount = ( ad.area == 4 ) ?  -2 : 0 ;

  // If optional perks
  price.imagePrice = 0;
  price.liveload = (ad.type == 'Liveload Classified Ad') ? price.img : 0 ;
  price.optional = price.imagePrice + price.liveload;

  // SubTotal
  price.subTotal = price.adjPrice + price.discount + price.optional;

  // Get Taxes
  price.taxeRate = .12;
  price.taxes = price.subTotal * price.taxeRate;

  // Total
  price.total = price.subTotal +  price.taxes;
  
  // Round prices for output
  price.subTotalRound =  Drupal.adPayment.formatCurrency(price.subTotal);
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
  }
  else {
    ad.msg.countOver = '';
  }
  
  // Area MSG
  if (ad.area == 0) {
    ad.msg.areaList = Drupal.t("<dt>Areas:</dt><dd> No Area Selcted</dd>");
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd><em>No Area Selcted</em></dd>");
  }
  else if (ad.area > 0 && ad.area < 4) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas</dd>", {'@area': ad.area, '@areas': ad.areaList});
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd> @area</dd>", {'@area': ad.area,});
  }
  else if (ad.area == 4) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas <br />$2 Discount on ad.</dd>", {'@area': ad.area, '@areas': ad.areaList});
    ad.msg.areaListSum = Drupal.t("<dt>Areas:</dt><dd> @area <br />$2 Discount.</dd>", {'@area': ad.area,});
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
    ad.msg.durationSum = Drupal.t("<dt>Duration:</dt><dd>@duration weeks <br />+ 3rd Week Free!</dd>", {'@duration': ad.duration});
  };
  
  // Liveload
  ad.msg.type = Drupal.t("<dt>Ad Type:</dt><dd> @type</dd>", {'@type': ad.type});
  
  // PRICE
  ad.msg.priceSum = Drupal.t("<dt>Price:</dt><dd><ul class=\"price price-review\"><li class=\"price price-subtotal\">Subtotal: $@basePrice</li><li class=\"price price-taxes\">Taxes: $@taxes</li><li class=\"price price-total\">Total: $@total</li></ul></dd>", {'@basePrice': price.subTotalRound, '@taxes': price.taxesRound,'@total': price.totalRound});
  ad.msg.priceOverview = Drupal.t("<dt>Price</dt><dd><ul class='price price-review'><li class='price price-subtotal'>Sub Total: $@subTotal</li><li class='price price-option'>Optional Extras: $@optional</li><li class='price price-taxes'>Taxes: $@taxes</li><li class='price price-total'>Total: $@priceTotal</li></dd>", {'@basePrice': price.basePrice, '@overPrice': price.overCount, '@subTotal': price.subTotalRound, '@taxes': price.taxesRound, '@optional': price.optional, '@priceTotal': price.totalRound});
  
  // Error Messages
  ad.msg.error = '';
  if (ad.errorMsg) {
    jQuery.each(ad.errorMsg, function(key, value) {
      ad.msg.error += '<li>' + value + '</li>';
    });
    ad.msg.error = '<ul class="error">' + ad.msg.error + '</ul>';
  }
  else {
    ad.msg.error = '';
  }  

  // Compose Messages
  // Summary - quick feedback as you type.
  ad.msg.summary = 
    '<div id="ad-summary">' 
     + '<div id="ad-summary-price" class="block summary-price-block">'
     + '<h2>Summary</h2>'
     + ad.msg.areaListSum 
     + ad.msg.durationSum 
     + ad.msg.wordcount
     + ad.msg.countOver
     + ad.msg.priceSum
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
    + '<div id="ad-review">'
    + '<div id="review-ad-box-price" class="review-ad-block">'
    + '<h2>Summary</h2>'
    + ad.msg.error 
    + '<dl>'
    + ad.msg.areaList 
    + ad.msg.rate 
    + ad.msg.duration 
    + ad.msg.type 
    + ad.msg.priceOverview 
    + '</div>'
    ;
  
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
  var formID = jQuery("form").attr('id');
  if (formID == 'ad-s-node-form'){

    // Hide Edit/Submit unless on page 4
    //jQuery('#edit-submit, #edit-preview').hide();


    // Get Settings
    var sideBar = '#sidebar-first > .section > .region';
    var summaryBox = Drupal.adPayment.displayMsg().summary;
    jQuery(sideBar).append(summaryBox);
    
    // Create DIV for review
    jQuery('#ad-s-node-form').prepend('<div id="ad-review">There are no ads ready to submit at this time.</div>');
    jQuery('#ad-review ').hide();
  
    // create error box for validation
    var validationBox = '<div id="validation-box"></div>';
    jQuery('#ad-s-node-form').prepend(validationBox);
  
    jQuery('#ad-s-node-form').bind('click keypress keyup change', function() { //click change keypress keyup
      var sideBox = '#ad-summary';
      var summaryBox = Drupal.adPayment.displayMsg().summary;
      jQuery(sideBox).html(summaryBox);
      
      // Review box.
      var reviewLocation = '#ad-review';
      var reviewBox = Drupal.adPayment.displayMsg().review;
      jQuery(reviewLocation).html(reviewBox);
  
      var pageState = jQuery('#node_ad_s_form_group_ad_review').attr('style');
      console.log('Page state: ' + pageState);
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

  