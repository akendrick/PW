Drupal.adPayment.formStateFeedback = function(formStep) {
  if (formStep == 1) {
    jQuery('#content').prepend('<div id="form-step"> <strong>Create Ad</strong> - Options - Payment - Submit </div>');
  }
  else if (formStep == 2) {
    jQuery('#form-step').html('<div id="form-step">Create Ad - <strong>Options</strong> - Payment - Submit </div>');
  }
  else if (formStep == 3) {
    jQuery('#form-step').html('<div id="form-step"> Create Ad - Options - <strong>Payment</strong> - Submit </div>');
  }
  else if (formStep == 4) {
    jQuery('#content').html('<div id="form-step"> Create Ad - Options - Payment - <strong>Submit </strong> </div>');
  }
  else {};
};

Drupal.adPayment.formState = function() {
  // retrieve formStep - if set.
  var formStep = jQuery('#field-ccid-add-more-wrapper').data('formStep');

  if (formStep == 'undefined') {
    formStep = 0;
  }
  else {
    // If the form is ready increment step.
    formStep++;
  }

  jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);

  if (formStep == 2) {
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);

    jQuery('#edit-preview').attr({value: 'Continue Step 3 - Payment'});

    jQuery('.group-ad').hide();
    jQuery('.group-upgrade').show();
    jQuery('.group-payment').hide();
    
    Drupal.adPayment.formStateFeedback(formStep);
    return false;
  } //
  else if (formStep == 3) {
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);
    jQuery('#edit-preview').attr({value: 'Review Ad'});

    jQuery('.group-ad').hide();
    jQuery('.group-upgrade').hide();
    jQuery('.group-payment').show();

    Drupal.adPayment.formStateFeedback(formStep);
    return false;
  } //
  else if (formStep == 4) {
    jQuery('#edit-submit').show();
    jQuery('#edit-preview').hide();
    jQuery('#edit-submit').attr({value: 'Submit Completed Ad'});
    Drupal.adPayment.formStateFeedback(formStep);

    return false;
  }
  else {
    formStep = 1;
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);
    jQuery('#edit-preview').attr({value: 'Continue Step 2 - Ad Upgrades'});

    jQuery('.group-ad').show();
    jQuery('.group-upgrade').hide();
    jQuery('.group-payment').hide();    

    Drupal.adPayment.formStateFeedback(formStep);
    return false;
  };
}

jQuery(document).ready(function() {
  jQuery('#field-price-add-more-wrapper').hide();
  jQuery('#field-ccid-add-more-wrapper').hide();
  jQuery('#field-ccid-add-more-wrapper').hide();
  
  // Hide Upgrade
  jQuery('.group-upgrade').hide();
  // Hide Payment
  jQuery('.group-payment').hide();
  
  // Hide Submit/Save Actions
  jQuery('#edit-submit').hide();
  // Rename Preview
  jQuery('#edit-preview').attr({value: 'Continue Step 2 - Ad Upgrades'});

  // Check Form Status on Submit
  jQuery("#ad-s-node-form").submit(function(event) {
    event.preventDefault();
    var formStep = Drupal.adPayment.formState();
    return formStep;
  });
  var formStep = Drupal.adPayment.formState();
  
});