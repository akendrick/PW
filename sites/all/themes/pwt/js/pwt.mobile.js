/**
 * Customizations to jQuery for PWTheme
 */


jQuery(document).ready(function($) {
//jQuery(document).ready(function() {

    console.log('Mobile JQ');

  // - hide and show options for mobile.
  $('#pw-mobile-links-content').hide();
  $('#pw-mobile-links-button').css('cursor', 'pointer');
  $('#pw-mobile-links-button').click(function() {
    $('#pw-mobile-links-content').toggle('slow');
  })

}(jQuery));


