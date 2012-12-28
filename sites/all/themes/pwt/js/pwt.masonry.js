/**
 * Customizations to jQuery.masonry for PWTheme
 */


(function ($) {
  function doMasonry() {

    var width = $(window).width();

    if (width >= 600) {
      width = 280;
    }
    else {
      width = width -20;
    };


    // Classifieds
    $('.classified-ad-group-section > img').imagesLoaded(function() {
      $('.classified-ad-group-section').masonry({
        itemSelector : '.classified-ad-block',
        columnWidth : width, // was 285
        isFitWidth: true
      });
    });

    // Classified Section Listings
    $('ul.stem_class').masonry({
      itemSelector : 'ul.stem_class > li',
      columnWidth : 120, // was 270 // 3-col 105
      isFitWidth: true,
      gutterWidth: 8
    });

    // Multiple Node Attachments
    $('.field-name-field-entity-reference').masonry({
      itemSelector : '.node-attachment.view-mode-teaser',
      columnWidth : 280, // was 270 // 3-col 105
      isFitWidth: true,
      gutterWidth: 20
    });


    // Editorials
    $('.views-field-field-image > .field-content > a > img').imagesLoaded(function() {
      $('.view-display-id-attachment_1 ').masonry({
        itemSelector : '.views-row',
        columnWidth : width, // was 270
        isFitWidth: true,
        gutterWidth: 10
      });
    });
  };

  $(document).ready(function() {
    doMasonry();
  });

  $(window).bind('resize', function() {
    doMasonry()
  });

}(jQuery));


