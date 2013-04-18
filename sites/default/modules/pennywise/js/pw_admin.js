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

})

}(jQuery));