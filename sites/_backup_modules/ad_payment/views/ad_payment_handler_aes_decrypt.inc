<?php
 
/**
 * Views Handler integration with AES decryption.
 */
class ad_payment_handler_aes_decrypt extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
      $options['decrypt_aes'] = array('default' => FALSE);
    return $options;
  }
 
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
 
    $form['decrypt_aes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Decrypt field'),
      '#description' => t('Check here to decrypt AES encrypted field.'),
      '#default_value' => $this->options['decrypt_aes'],
    );

    parent::options_form($form, $form_state);
  }
 
  function pre_render($values) {
    return $values;
  }
  
  function render($values) {
    $value = $this->get_value($values);
    
    if (!empty($this->options['decrypt_aes'])) {
      return aes_decrypt($value);
    }
    else {
      return $value;
    }
  }
}
