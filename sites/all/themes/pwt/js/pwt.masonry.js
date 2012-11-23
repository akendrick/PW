/**
 * Customizations to jQuery.masonry for PWTheme
 */


(function ($) {
  $(document).ready(function() {
    // Classified Ads with Masonry
    $('.classified-ad-group-section > img').imagesLoaded(function() {
      $('.classified-ad-group-section').masonry({
        itemSelector : '.classified-ad-block',
        columnWidth : 285,
        isFitWidth: true
      });
    });

    // Classified Section Listings
    $('.stem_class').masonry({
      itemSelector : '.branch_class',
      columnWidth : 285,
      isFitWidth: true
    });

  });
}(jQuery));


