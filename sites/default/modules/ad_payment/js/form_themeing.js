/**
 * Form THeming.
 *
 * - Drop down menus etc.
 */
(function($) {

$(document).ready(function() {

// From http://ericlondon.com/posts/68-improving-form-validation-usability-for-checkboxes-and-radio-buttons
$('form#node-form div.form-item').each(function(){
  var result = 0;
  result += $(this).find('div.form-radios input.form-radio.error').length;
  result += $(this).find('div.form-checkboxes input.form-checkbox.error').length;
  if (result) $(this).find('label:first').removeClass('error').addClass('error');
});

  // Add Elements to Beauty Tips
  //var picture = "<div class=' beautytips form-toggle' id='bt-picture'>About pictures.</div>";
  //var imageBox = '<span id="bt-picture" class=" beautytips form-toggle">About Pictures</span>'
  //              + '<div id="beautytips-toggle-box-bt-picture" class="beautytips-box">'+description+'</div>';
  var description = $('.form-item-field-image-und-0 .description').html();
  $('.form-item-field-image-und-0 .description')
      .html('<div id="beautytips-toggle-box-bt-picture" class="beautytips-box">'+description+'</div>')
      .prepend('<span id="bt-picture" class=" beautytips form-toggle">About Pictures</span>');

  // Beauty tips replacement
  // - hide and show extra info for form submission.
  $('.beautytips-box').hide();
  $('.form-toggle').css('cursor', 'pointer').click(function() {
    $('#beautytips-toggle-box-'+($(this).attr('id'))).toggle('slow');
     console.log($(this).attr('id'));
  })

});

}(jQuery));