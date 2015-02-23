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
      .prepend('<div class="beautytips image-note">Add a web only picture starting at $1.49/week.</div>')
      .prepend('<div id="bt-picture" class="beautytips form-toggle">More info.</div>');
     // .prepend('<span id="bt-picture" class=" beautytips form-toggle">About Pictures</span>');

  // Add CSS to Power Picture drop down button.
  $("#bt-picture")
    .css({'background-color':'#303',
    'color':'#fff',
    'float':'left',
    'border-radius':'20px',
    '-moz-border-radius':'20px',
    '-webkit-border-radius':'20px',
    'background-color':'#303',
    'color':'#fff',
    'border':'1pt solid #fff',
    'padding':'2px 6px'});
  $("#beautytips-toggle-box-bt-picture")
    .css({
      'clear':'left',
      'padding':'4px',
      'background':'#fff',
      'margin':'0 0 20px 0',
      'border':'1pt solid #0059b3'});

  // Beauty tips replacement
  // - hide and show extra info for form submission.
  $('.beautytips-box').hide();
  $('.form-toggle').css('cursor', 'pointer').click(function() {
    $('#beautytips-toggle-box-'+($(this).attr('id'))).toggle('slow');
     console.log($(this).attr('id'));
  })

});

}(jQuery));