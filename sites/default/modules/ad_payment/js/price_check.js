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
	var non_alphanumerics_rExp = rExp = /[^A-Za-z0-9]+/gi;
	var cleanedStr = left_trimmedStr.replace(non_alphanumerics_rExp, " ");
	var splitString = cleanedStr.split(" ");

	return splitString;
};
Drupal.adPayment.countWords = function(cleanedWordString) {
	var word_count = Drupal.adPayment.wordCleaner(cleanedWordString).length-1;
	return word_count;
}


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
    ad.wordCount = 15;
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
  ad.area = (ad.area == 0) ? 1 : ad.area;
  
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
  
  // Liveload
  if (jQuery('#edit-field-promote-und-0:checked').val() == '0') {
    ad.type = 'Regular Classified Ad';
  }
  else if (jQuery('#edit-field-promote-und-1:checked').val() == '1') {
    ad.type = 'Liveload Classified Ad';
  }
  else {
    ad.type = 'Not Set';
  };
  
  return ad;
};


/**
 * Format Currency
 */
Drupal.adPayment.formatCurrency = function(num) {
//  num = isNaN(num) || num == '\u65533' || num === '' || num === null ? 0.00 : num;
//ÊÊreturn parseFloat(num).toFixed(2);
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
  
  // Base rate + overflow word count
  price.overCount = (ad.wordCount > 15) ? ad.countOver * price.word : 0 ;
  price.basePrice = price.base + price.overCount;
  // Adjusted with duration and areas
  price.adjPrice = price.basePrice * ad.duration * ad.area;
  // If booking all 4 areas get $1 off.
  price.discount = ( ad.areas == 4 ) ?  -2 : 0 ;
  // If optional perks
  price.imagePrice = 0;
  price.liveload = (ad.type == 'Liveload Classified Ad') ? price.img : 0 ;
  price.optional = price.imagePrice + price.liveload;
  // SubTotal
  price.subTotal = price.adjPrice + price.discount + price.optional;
  
  // Get Taxes
  price.taxeRate = .12;
  price.taxes = price.subTotal * price.taxeRate;
  // Total Cost
  price.total = price.subTotal + price.taxes;
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
    ad.msg.countOver   = Drupal.t("<dt>Words over 15:</dt><dd> @count </dd>", {'@count': ad.countOver});
  }
  else {
    ad.msg.countOver = '';
  }
  
  // Area MSG
  if (ad.area == 1) {
    ad.msg.areaList = Drupal.t("<dt>Area: 1</dt><dd> @areas</dd>", {'@areas': ad.areaList});
  }
  else if (ad.area > 1) {
    ad.msg.areaList = Drupal.t("<dt>Areas: @area </dt><dd> @areas</dd>", {'@area': ad.area, '@areas': ad.areaList});
  }
  else {
    ad.msg.areaList = '<dt>Area: None Selected</dt><dd>Please select an area for your ad to appear in.</dd>';
  }
  // ad web area free
  ad.msg.areaList += '<em class="price-box duration duration-note">Internet Included FREE</em>';
  
  // Rate MSG 
  ad.msg.rate = Drupal.t("<dt>Rate:</dt><dd> @rate</dd>", {'@rate': ad.rate});
  
  // Duration MSG
  ad.msg.duration = Drupal.t("<dt>Duration:</dt><dd> @duration weeks</dd>", {'@duration': ad.duration}) + ad.msg.durationDiscount;
  if (ad.duration == '2') {
    ad.msg.duration = '<dt>Duration:</dt><dd>When you book for 2 weeks you get the 3rd for FREE!</dd>';
  };
  
  // Liveload
  ad.msg.type = Drupal.t("<dt>Ad Type:</dt><dd> @type</dd>", {'@type': ad.type});
  
  // PRICE
  //ad.msg.price = Drupal.t("<dt>Price</dt><dd><ul><li>Base Price: @basePrice</li>", {'@basePrice': ad.price.basePrice});
  if ( ad.wordCount >= 1) {
    ad.msg.price = Drupal.t("<dt>Price</dt><dd><ul><li>Base Price: @basePrice</li><li>Over Price: @overPrice</li><li>Taxes: @taxes</li><li>Optional Extras: @optional</li><li>Total: @priceTotal</li></dd>", {'@basePrice': price.basePrice, '@overPrice': price.overCount,'@taxes': price.taxes, '@optional': price.optional, '@priceTotal': price.total});
  }
  else {
    ad.msg.price = '<dt>Price</dt><dd>No Price Calculated</dd>';
  }
  // Compose MSG
  ad.msg = 
    '<div id="price-box" class="block summary-price-block">'
    + '<h2>Summary</h2>'
    + '<dl>' 
    + ad.msg.areaList 
    + ad.msg.rate 
    + ad.msg.duration 
    + ad.msg.type 
    + ad.msg.price 
    + '</div>'
    + '<div id="price-box-ad" class="block summary-ad-block">'
    + '<h2>Ad</h2>'
    + ad.msg.ad 
    + ad.msg.wordcount 
    + ad.msg.countOver  
    + '</div>'
    ;
  
  return ad.msg;
}

/**
 * PRIMARY EVENT HANDLING.
 */
jQuery(document).ready(function() {
    var sideBar = '#sidebar-first > .section > .region';
    var priceBox = Drupal.adPayment.displayMsg();
    jQuery(sideBar).append(priceBox);
  
  jQuery('#ad-s-node-form').bind('click change keypress keyup', function() {
    var sideBar = '#sidebar-first > .section';
    var priceBox = Drupal.adPayment.displayMsg();
    jQuery(sideBar).html(priceBox);
    //jQuery(sideBar).html(jQuery(document.createElement('div')).attr({id:'price-box',class:'block'}).prepend(priceBox));

  });

});

  