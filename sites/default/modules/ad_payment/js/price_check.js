Drupal.adPay = Drupal.adPay || {};

Drupal.adPay.wordCounter = function() {
  var adCopy;
  adCopy = jQuery('#edit-field-ad-copy-und-0-value').val();

  var wordCount;
  wordCount = jQuery.trim(jQuery('#edit-field-ad-copy-und-0-value').val().split(/\s+/)).wordCount;

  
  message = Drupal.t("Word count: @count", {'@count': wordCount});
  return message;
}

jQuery(document).ready(function() {
  jQuery('#field-price-add-more-wrapper').hide();
  jQuery('#field-ccid-add-more-wrapper').hide();

  // Default jQuery Counter script.
  jQuery('#ad-price-box').html(Drupal.adPay.wordCounter());


});

