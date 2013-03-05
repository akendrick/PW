/**
 * Form THeming.
 *
 * - Drop down menus etc.
 */
jQuery(document).ready(function() {
  //jQuery.event.props = jQuery.event.props.join('|').replace('layerX|layerY|', '').split('|');
    // remove layerX and layerY
  (function(){
      // remove layerX and layerY
      var all = jQuery.event.props,
          len = all.length,
          res = [];
      while (len--) {
        var el = all[len];
        if (el != 'layerX' && el != 'layerY') res.push(el);
      }
      jQuery.event.props = res;
  }());

 // New form validation in case of multiple forms detected.
  if (jQuery('#ad-s-node-form').length) {
    console.log('form-theme!');
   //var description = jQuery('.form-item-field-image-und-0 > .description');
   jQuery('.form-item-field-image-und-0 > label').append('<div id="form-item-field-image-und-0-description-toggle" class="small-description">?</div>');
   jQuery('#form-item-field-image-und-0-description-toggle').click(function(){
     jQuery(this).toggleClass("down");
   });
   toggle('.form-item-field-image-und-0 > .description');

//   jQuery('.form-item-field-image-und-0 > .description').css('font-size:.8em');
  };
});

