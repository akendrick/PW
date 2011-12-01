<?php

/**
 * Implementation of HOOK_views_data
 *
 * For describing table data to views.
 */
function ad_payment_views_data() {
  // AD PAYMENT TABLE
  $data['adp']['table']['group'] = t('Ad Payment');
  
  // Linking to other tables.
  $data['adp']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );

  //FIELDS
  // Ad Payment table description.
  // CCID
  $data['adp']['ccid'] = array(
    'title' => t('CCID.'),
    'help' => t('Primary ID of linking table with CC Data.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //PRICE
  $data['adp']['price'] = array(
    'title' => t('Price'),
    'help' => t('The final calculated price of the ad.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //CARD
  $data['adp']['cc_type'] = array(
    'title' => t('CC Type'),
    'help' => t('Credit card used to pay for the ad.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //CC Num
  $data['adp']['cc_num'] = array(
    'title' => t('CC Numbers'),
    'help' => t('Last 4 digits of CC for verification.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  

  //Exp MONTH
  $data['adp']['exp_m'] = array(
    'title' => t('Expiry Month'),
    'help' => t('Expiry month of the credit card.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  //Exp YEAR
  $data['adp']['exp_y'] = array(
    'title' => t('Expiry Year'),
    'help' => t('Expiry Year of the credit card.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  // UID
  // copied on Node - UID field
  $data['adp']['uid'] = array(
    'title' => t('Author uid'),
    'help' => t('The user authoring the content. If you need more fields then the uid add the content: author relationship'),
    'relationship' => array(
      'title' => t('Author'),
      'help' => t('Relate content to the user who created it.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('author'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
  );

  // NID
  // copied on Node - NID field
  $data['adp']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The node ID.'), // The help that appears on the UI,
    'relationship' => array(
      'title' => t('Node ID'),
      'help' => t('Relate content to the Node associated with it.'),
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'field' => 'nid',
      'label' => t('Node ID'),
    ),
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // created date field
  $data['adp']['created'] = array(
    'title' => t('Submitted'), // The item it appears as on the UI,
    'help' => t('The date the content was submitted.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
 
  //END
  // AD PAYMENT TABLE

  
  return $data;
}