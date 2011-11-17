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

  // Hyphenation Check
	var hyphensRg = /([A-Za-z0-9][-_.*#]){3,}/;
  if (hyphensRg.test(ad.copy)) {
    jQuery('#validation-box').html('Too Many Connections!<br> This ad will need to verified by Pennywise staff before approval. The quoted price may not be accurate.').addClass('error');
  }
  else if (!hyphensRg.test(ad.copy)) {
    jQuery('#validation-box').html('').addClass('ok');
  };	

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
    ad.rate = 'Personal';
  }
  else if (jQuery('#edit-field-rate-und-business:checked').val() == 'Business') {
    ad.rate = 'Business';
  }
  else {
    ad.rate = 'Not Set';
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
  
  // SECTION
  ad.section = jQuery('#edit-field-tags-und').val();
  

  // Validate Form Data
  Drupal.adPayment.validate(ad);

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
  if (ad.rate == 'Personal') {
    price.rate = 'Personal';
    price.base = 3.5;
    price.word = .2;
    price.img  = 1.99;    
    price.promote = 5;
  }
  else if (ad.rate == 'Business'){
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
  price.subTotal = Drupal.adPayment.formatCurrency(price.adjPrice + price.discount + price.optional);
  
  // Get Taxes
  price.taxeRate = .12;
  price.taxes = Drupal.adPayment.formatCurrency(price.subTotal * price.taxeRate);

  // Total Cost
  price.total = Drupal.adPayment.formatCurrency(price.subTotal + price.taxes);

  // Round Total
  //price.total = Drupal.adPayment.formatCurrency(price.totalRaw);
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
  ad.msg.rate = Drupal.t("<dt>Rate:</dt><dd> @rate</dd>", {'@rate': ad.rate});
  
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
  ad.msg.priceSum = Drupal.t("<dt>Price:</dt><dd><ul class=\"price price-review\"><li class=\"price price-subtotal\">Subtotal: $@basePrice</li><li class=\"price price-taxes\">Taxes: $@taxes</li><li class=\"price price-total\">Total: $@total</li></ul></dd>", {'@basePrice': price.subTotal, '@taxes': price.taxes,'@total': price.total});
  ad.msg.priceOverview = Drupal.t("<dt>Price</dt><dd><ul class='price price-review'><li class='price price-subtotal'>Sub Total: $@subTotal</li><li class='price price-option'>Optional Extras: $@optional</li><li class='price price-taxes'>Taxes: $@taxes</li><li class='price price-total'>Total: $@priceTotal</li></dd>", {'@basePrice': price.basePrice, '@overPrice': price.overCount, '@subTotal': price.subTotal, '@taxes': price.taxes, '@optional': price.optional, '@priceTotal': price.total});
  
  // Compose MSG
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
    + '<dl>' 
    + ad.msg.areaList 
    + ad.msg.rate 
    + ad.msg.duration 
    + ad.msg.type 
    + ad.msg.priceOverview 
    + '</div>'
    ;
  
  return ad.msg;
}

/**
 * PRIMARY EVENT HANDLING.
 *
 * Sidebar-first - summary
 * Content Review - hidden until submitting
 */
jQuery(document).ready(function() {
    var sideBar = '#sidebar-first > .section > .region';
    var summaryBox = Drupal.adPayment.displayMsg().summary;
    jQuery(sideBar).append(summaryBox);
    
    // Create DIV for review
    jQuery('#ad-s-node-form').prepend('<div id="ad-review">Placeholder</div>');
    jQuery('#ad-review').hide();
  
    // create error box for validation
    jQuery('#ad-s-node-form').prepend('<div id="validation-box"></div>');

  jQuery('#ad-s-node-form').bind('click change keypress keyup ', function() { //click change keypress keyup
    var sideBox = '#ad-summary';
    var summaryBox = Drupal.adPayment.displayMsg().summary;
    jQuery(sideBox).html(summaryBox);
    
    // Review box.
    var reviewLocation = '#ad-review';
    var reviewBox = Drupal.adPayment.displayMsg().review;
    jQuery(reviewLocation).html(reviewBox);

  });

});

  