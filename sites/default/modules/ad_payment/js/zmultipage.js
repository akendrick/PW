/**
 * Form Feedback 
 *  
 * @TODO: 
 *  Links for State Switching - editing
 *  Change title depending on state - 'page-title'
 *
 */ 
Drupal.adPayment.formStateFeedback = function(formStep) {
  var step1 = '<a href="#form-step-1" class="form-feedback-step"> Create Ad </a>';
  var step2 = '<a href="#form-step-2" class="form-feedback-step"> Options </a>';
  var step3 = '<a href="#form-step-3" class="form-feedback-step"> Payment </a>';
  var step4 = '<a href="#form-step-4" class="form-feedback-step"> Review </a>';
  var formSteps = '<div id="form-feedback">' + step1 + step2 + step3 + step4 + '</div>';

  jQuery('#form-feedback').html(formSteps);
  jQuery('#form-step-'+formStep).addClass('form-feedback-step-highlight');
  
  // jQuery UI button test.
  jQuery('.form-feedback').tabs();
};



/**
 * State Hide/Show Funcitonality 
 */ 
Drupal.adPayment.formLayout = function(formStep) {

  // console.log('Step Detect: ' + formStep);
  
  // Default Layout
  // Layout - hide all elements
  jQuery('#field-price-add-more-wrapper, #field-price -add-more-wrapper, #block-ad-payment-ad-payment-create-ad, .group-upgrade, .group-payment').hide();
    //
  switch (formStep) {
    case 1:
      // STEP 1 - CREATE AD
      Drupal.adPayment.formStateFeedback(formStep);
      jQuery('#field-price-add-more-wrapper').data('formStep', formStep);
      jQuery('#edit-preview').attr({value: 'Continue Step 2 - Ad Options'});
      
      // layout
      jQuery('.edit-submit, .group-upgrade, .group-payment, #ad-review').hide();
      jQuery('.group-ad, #ad-summary').show();
      break;

    case 4:
      // STEP 4 - SUBMIT AD
      Drupal.adPayment.formStateFeedback(formStep);
      jQuery('#field-price-add-more-wrapper').data('formStep', formStep+1);
      jQuery('#edit-submit').attr({value: 'Submit Completed Ad'}).show();
      
      // layout
      jQuery('#edit-preview, .group-ad, .group-upgrade, .group-payment, #ad-summary').hide();
      jQuery('#ad-review').show();
      break;

    case 3:
      // STEP 3 - PAYMENT DATA
      Drupal.adPayment.formStateFeedback(formStep);
      jQuery('#field-price-add-more-wrapper').data('formStep', formStep+1);
      jQuery('#edit-preview').attr({value: 'Review Ad'});
  
      // layout
      jQuery('.group-ad, .group-upgrade, #ad-review').hide();
      jQuery('.group-payment').show();
      break;

    case 'all':
      // ERROR - show ALL
      Drupal.adPayment.formStateFeedback(4);
      jQuery('group-ad, .group-upgrade, .group-payment, #ad-summary').show();
      jQuery('#ad-review').hide();
      jQuery('#edit-submit').attr({'value': 'Submit Completed Ad'}).show();
     break;

    case 2:
      // STEP 2 - AD OPTIONS
    default:
      // DEFAULT
      Drupal.adPayment.formStateFeedback(formStep);
      jQuery('#field-price-add-more-wrapper').data('formStep', (formStep+1));
      jQuery('#edit-preview').attr({value: 'Continue Step 3 - Payment'});
      
      // layout
      jQuery('#ad-review, .group-ad, .group-payment').hide();
      jQuery('#ad-summary, .group-upgrade').show();
      break;
  };
  // console.log('Step SET: ' + formStep);

}


jQuery(document).ready(function() {
  var formID = jQuery("form").attr('id');
  if (formID == 'ad-s-node-form'){
  
    // Form State Switcher
    jQuery('#content').prepend('<div id="form-feedback"></div>');      // Add State Switcher DIV
  
    // Set layout
      Drupal.adPayment.formLayout(1);
    
    // State Switcher
    jQuery('#content').bind('mouseover click change', function() {  
      jQuery("#form-feedback span").css('cursor', 'pointer').bind('click', function() {
        var gotoStep = jQuery(this).attr('id');
        switch(gotoStep) {
          case 'form-step-1':
            Drupal.adPayment.formLayout(1);
            break;
          case 'form-step-2':
            Drupal.adPayment.formLayout(2);
            break;
          case 'form-step-3':
            Drupal.adPayment.formLayout(3);
            break;
          case 'form-step-4':
            Drupal.adPayment.formLayout(4);
            break;
        };
      });
    }); // End Form State Switcher.
    
    // Check Form Status on Submit
    jQuery("#ad-s-node-form").submit(function(adForm) {
      adForm.preventDefault();
      var self = this;
  
        if (jQuery('#messages .error') === true) {
          Drupal.adPayment.formLayout('all');
          console.log('Error Step: ' + formStep);
        }
        else {
          var formStep = jQuery('#field-price-add-more-wrapper').data('formStep');    

          switch(formStep) {
            case 1:
            case 2:
              formStep++;
              Drupal.adPayment.formLayout(formStep);
              break;
            case 3:
              Drupal.adPayment.formLayout(formStep);
              break;
            case 4:
              Drupal.adPayment.formLayout(formStep);
              break;
            case 5:
              Drupal.adPayment.formLayout(formStep);
              self.submit();
            default:
              formStep = 1;
              Drupal.adPayment.formLayout(formStep);
              break;
          };
          // if (!parseInt(formStep) | formStep == 'undefined' | formStep == 'Nan' | formStep == 'all') {
          //   formStep = 2;
          //   console.log('Set Step as -  ' + formStep);
          // }
          // else {
          //   // If the form is ready increment step.
          //   formStep++;
          // };
          // 
          // if (formStep > 4) {
          //   formStep = 4;
          //   self.submit();
          // }
          //Drupal.adPayment.formLayout(formStep);
        };
    });
  };  
  
});