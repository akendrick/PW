<?php
/**
 * @file
 * Integration with the Context module
 *
 * Triggers a context for a mobile device vs a desktop device
 * @todo add arbitrary group contexts?
 */
class mobile_tools_context_condition_device_group extends context_condition {

  /**
   * Default values
   */
  function condition_values() {
    return mobile_tools_device_groups();
  }

  /**
   * Process condition logic
   */
  function execute($type) {
    if ($this->condition_used()) {
      // Get active device group
      $active = mobile_tools_get_active_device_group();

      foreach($this->get_contexts($active) as $context) {
    
      foreach ($active as $device_group) {
        if ($device_group['type'] == $type) {
          dpm('Condition met');
          $this->condition_met($context, $type);
        }
      }
    }
      // Trigger the context condition based on the active device group
      // @todo
    }
  }

  /**
   * Configuration form
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    
    $form['#type'] = 'checkboxes';
    $form['#description'] = t('Trigger this context when the given device groups are active.');
    $form['#options'] = mobile_tools_device_groups();
    $form['#default_value'] = $this->fetch_from_context($context, 'values');

    return $form;
  }
  
  /**
   * Form submit handler
   */
  function condition_form_submit($values) {
    // @todo
    //dpm($values);
    return $values;
  }
}
