/**
 * Customizations to jQuery.masonry for PWTheme
 */


(function ($) {
  (function(){
      // remove layerX and layerY
      var all = $.event.props,
          len = all.length,
          res = [];
      while (len--) {
        var el = all[len];
        if (el != 'layerX' && el != 'layerY') res.push(el);
      }
      $.event.props = res;
  }());

  function doMasonry() {
    return;

    console.log('Width: '+$(window).width());
    var width = $(window).width();
    if (width >= 600) {
      width = 280;
      // console.log(width, 'Masonry width');
    }
//    if ( width == '') {
//      console.log(width, 'No Masonry width');
//      width = 280;
//    }
    else if (width <= 600 || width >= 280) {
      width = width -60;
      var classifiedCol = 120;
    }
    else {
      width = width -5;
      var classifiedCol = 120;
    };

 //   if( $('.responsive-layout-mobile').length > 0 ) {
 //     console.log('layout mobile');
 //     width = width -20;
 //     var classifiedCol = width;
 //   }

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
      columnWidth : classifiedCol, // was 270 // 3-col 105
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
      $('.view-display-id-editorial_main_page > .view-content').masonry({
        itemSelector : '.views-row',
        columnWidth : width, // was 270
        isFitWidth: true,
        gutterWidth: 10
      });
    });
  };


  // On Load
  $(document).ready(function() {
    doMasonry();
  });

  // On Resize
  $(window).bind('resize', function() {
 //   var width = $(window).width();
 //
 //   if (width >= 600) {
      doMasonry();
//    }
//    else (width <= 400); {
//      doMasonry();
//    }

  });

  // Again once images run.
  $(window).load(function() {
    doMasonry();
  });

  var mobileOrient =  window.matchMedia("(orientation: portrait)");

  mobileOrient.addListener(function(m) {
    //$('.classified-ad-group-section').width('auto');
    //doMasonry();
  });
//  $(mobileOrient.matches) {
//    doMasonry()
//  }
//  else {
//    doMasonry()
//  }

}(jQuery));


