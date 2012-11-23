/**
 * Customizations to jQuery.masonry for PWTheme
 */


(function ($) {
  $(document).ready(function() {
    $('.classified-ad-group-section > img').imagesLoaded(function() {
      $('.classified-ad-group-section').masonry({
        itemSelector : '.classified-ad-block',
        columnWidth : 285,
        isFitWidth: true
      });
    });
  });
}(jQuery));


