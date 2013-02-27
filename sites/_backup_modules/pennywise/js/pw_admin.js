// Toggle For Hiding/Unhiding Ad Submission 'More' Data
jQuery(document).ready(function() {
  // Hide all content that needs to hide.
  jQuery('.ad-details-toggle-box-content').hide();

  // When switch is activated use it's CLASS and then find it's ID pair and toggle it.
  jQuery('[id^=ad-details-toggle-box-switch-]').click(function() {
    jQuery('#ad-details-'+(jQuery(this).attr('class'))).toggle('slow');
  });
})
