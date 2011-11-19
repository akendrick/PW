/**
 * Form Feedback 
 *  
 * @TODO: 
 *  Links for State Switching - editing
 *  Change title depending on state - 'page-title'
 *
 */ 
Drupal.adPayment.formStateFeedback = function(formStep) {
  var step1 = '<span id="form-step-1" class="form-feedback-step"> Create Ad </span>';
  var step2 = '<span id="form-step-2" class="form-feedback-step"> Options </span>';
  var step3 = '<span id="form-step-3" class="form-feedback-step"> Payment </span>';
  var step4 = '<span id="form-step-4" class="form-feedback-step"> Review </span>';
  var formSteps = '<div id="form-feedback">' + step1 + step2 + step3 + step4 + '</div>';

  jQuery('#form-feedback').html(formSteps);
  jQuery('#form-step-'+formStep).addClass('highlight');
};



/**
 * State Hide/Show Funcitonality 
 */ 
Drupal.adPayment.formState = function(activationState, formStep) {
  if (activationState == 'submit-form') {
    // retrieve formStep - if set.
    var formStep = jQuery('#field-ccid-add-more-wrapper').data('formStep');
    
    if (formStep == 'undefined') {
      formStep = 0;
    }
    else {
      // If the form is ready increment step.
      formStep++;
    }
    
    var returnVal = false;    
  }
  else {
    var returnVal = true;
  };


  jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);

  // Hide Submit/Save Actions
  jQuery('#edit-submit').hide();

  if (formStep == 2) { // STEP 2 - UPGRADE AD
    // form state
    Drupal.adPayment.formStateFeedback(formStep);
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);
    jQuery('#edit-preview').attr({value: 'Continue Step 3 - Payment'});
    
    // layout
    jQuery('.group-ad').hide();
    jQuery('.group-upgrade').show();
    jQuery('.group-payment').hide();
    jQuery('#ad-review').hide();
    jQuery('#ad-summary').show();

    return returnVal;
  } 
  else if (formStep == 3) { // STEP 4 - PAYMENT
    // form state
    Drupal.adPayment.formStateFeedback(formStep);
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);
    jQuery('#edit-preview').attr({value: 'Review Ad'});

    // layout
    jQuery('.group-ad').hide();
    jQuery('.group-upgrade').hide();
    jQuery('.group-payment').show();
    jQuery('#ad-review').hide();
    jQuery('#ad-summary').show();

    return returnVal;
  } 
  else if (formStep == 4) { // STEP 5 - REVIEW & SUBMIT
    // form state
    Drupal.adPayment.formStateFeedback(formStep);
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);
    jQuery('#edit-preview').hide();
    jQuery('#edit-submit').attr({value: 'Submit Completed Ad'}).show();
    
    // layout
    jQuery('.group-ad').hide();
    jQuery('.group-upgrade').hide();
    jQuery('.group-payment').hide();
    jQuery('#ad-review').show();
    jQuery('#ad-summary').hide();
    return returnVal;
  }
  else {
    // form state
    formStep = 1; // STEP 1 - CREATE AD
    Drupal.adPayment.formStateFeedback(formStep);
    jQuery('#field-ccid-add-more-wrapper').data('formStep', formStep);
    jQuery('#edit-preview').attr({value: 'Continue Step 2 - Ad Upgrades'});
    
    // layout
    jQuery('.group-ad').show();
    jQuery('.group-upgrade').hide();
    jQuery('.group-payment').hide();    
    jQuery('#ad-review').hide();
    jQuery('#ad-summary').show();

    return returnVal;
  };
}

/**
 * Controls formState via the Header Buttons
 */
Drupal.adPayment.stateSwitcher = function() {
  var gotoStep = jQuery(this).attr('id');
  
  switch(gotoStep) {
    case 'form-step-1':
      Drupal.adPayment.formState('toggle', 1);
      break;
    case 'form-step-2':
      Drupal.adPayment.formState('toggle', 2);
      break;
    case 'form-step-3':
      Drupal.adPayment.formState('toggle', 3);
      break;
    case 'form-step-4':
      Drupal.adPayment.formState('toggle', 4);
      break;
  };
  
  return false;
};


jQuery(document).ready(function() {
  
  // Layout - hide elements
  jQuery('#field-price-add-more-wrapper').hide();
  jQuery('#field-ccid-add-more-wrapper').hide();
  jQuery('#block-ad-payment-ad-payment-create-ad').hide();
  jQuery('.group-upgrade').hide();
  jQuery('.group-payment').hide();
  
  // Rename Preview
  jQuery('#edit-preview').attr({value: 'Continue Step 2 - Ad Upgrades'});
  
  // Add State Switcher DIV
  jQuery('#content').prepend('<div id="form-feedback"></div>');  


  // Check Form Status on Submit
  jQuery("#ad-s-node-form").submit(function(event) {
    event.preventDefault();
    var formStep = Drupal.adPayment.formState('submit-form', 'undefined');
    return formStep;
  });
  var formStep = Drupal.adPayment.formState();
  
  // Form State Switching
  jQuery('#content').bind('click change', function() {
  
  jQuery("#form-feedback span").css('cursor', 'pointer').bind('click', function() {
    var gotoStep = jQuery(this).attr('id');
    switch(gotoStep) {
      case 'form-step-1':
        Drupal.adPayment.formState('toggle', 1);
        break;
      case 'form-step-2':
        Drupal.adPayment.formState('toggle', 2);
        break;
      case 'form-step-3':
        Drupal.adPayment.formState('toggle', 3);
        break;
      case 'form-step-4':
        Drupal.adPayment.formState('toggle', 4);
        break;
    };
  });
  
  });
  
});