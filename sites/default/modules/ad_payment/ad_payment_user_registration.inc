<?php
/**
* Create User from submitted form data.
*/

function adp_user_registration(&$user, &$form_state) {

  $mail        = $form_state['values']['field_email']['und'][0]['email'];
  $first_name  = trim($form_state['values']['field_first_name']);
  $last_name   = trim($form_state['values']['field_last_name']);
  $user_name   = $first_name . '_' . $last_name;
  $phone       = $form_state['values']['field_phone']['und'][0]['number'];

  // Return error if emtpy.
  if (!$mail) {
    form_set_error('field_email', t('Please fill in your first name.'));
  }
  else if (user_validate_mail($mail)) {
    form_set_error('field_email', t('Please enter a valid email address.'));
  }
  if (!$first_name) {
    form_set_error('field_first_name', t('Please fill in your first name.'));
  }
  if (!$last_name) {
    form_set_error('field_last_name', t('Please fill in your last name.'));
  }
  if (!$phone) {
    form_set_error('field_phone', t('Please don\'t forget to fill in your phone number.'));
  }
  if (!$mail || !$first_name || !$last_name || !$phone) {
    return;
  }


  // Check if user  {email} is in database
 // $result = db_query('SELECT COUNT(*) FROM {users} WHERE mail = :mail AND name = :name', array(':mail' => $mail, ':name' => $user_name));

  if ( !db_query('SELECT COUNT(*) FROM {users} WHERE mail = :mail AND name = :name', array(':mail' => $mail, ':name' => $user_name)) ) {
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
    // if user doesn't exist.
    // Register New User
    $account = array(
      'name' => $user_name,
      'mail' => $mail,
      'pass' => $phone,
      'status' => 1,
      'init' => $mail,
      'roles' => array(4 => 'submit ad'),
      'signature_format' => 'plain_text',
    );
    $user = user_save(NULL, $account);

  }
  else {
    $user = user_load_by_mail($mail);
  }

  $login_data = array(
    'name' => $user_name,
  );
  $uid = user_authenticate($login_data);
  $login_data['uid'] = $uid;
  user_login_finalize($login_data);
    // log user in.

    // RealName format
    // check_plain(format_username($account))

  if (DEBUG_USER) {
    // dpm('ACCOUNT');
    // dpm($account);
    // dpm('Email DB Check');
    // dpm($result);
    // dpm('FORM STATE');
    // dpm($form_state);
    // dpm('USER');
    // dpm($user);
  }

}
