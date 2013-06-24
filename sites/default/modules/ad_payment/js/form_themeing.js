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

  // Beauty tips replacement
  // - hide and show extra info for form submission.
  $('.beautytips-box').hide();
  $('.form-toggle').css('cursor', 'pointer');
  $('.form-toggle').click(function() {
    $('#beautytips-toggle-box-'+($(this).attr('id'))).toggle('slow');
     console.log($(this).attr('id'));
  })

});

}(jQuery));