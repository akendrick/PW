<?php
// $Id:
/**
 * @file
 *   Adminstrative pages for Mobile Tools
 */

 /**
 * Configuration form for the mobile device detection, redirection and notification
 * 
 * @return
 *   The configuration form   
 */ 
function mobile_tools_configuration_form() {
  global $base_url;
  $form['general'] = array(
    '#type' => 'vertical_tabs',
    '#title' => t('General'),
  );
  
  $form['general']['mobile_tools_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => 'General configuration',
    '#description' => 'Enter the mobile and desktop url for your site. If both urls are equal there will be no redirection, but only theme switching. Go to "theme switching" to configure the theme',
    '#collapsible' => TRUE,
  );
  
  $form['general']['mobile_tools_configuration']['mobile_tools_mobile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile URL'),
    '#description' => t('Give the name of your mobile site. It is recommended to use the convention of m.domain .com or www.domain.mobi'),
    '#default_value' => variable_get('mobile_tools_mobile_url', mobile_tools_create_mobile_url($base_url)),
  );
  $form['general']['mobile_tools_configuration']['mobile_tools_desktop_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop URL'),
    '#description' => t('Give the name of your regular website.'),
    '#collapsible' => TRUE,
    '#default_value' => variable_get('mobile_tools_desktop_url', $base_url)
  );
  
 $form['general']['mobile_tools_redirection'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redirection options'),
    '#collapsible' => TRUE,  
    '#collapsed' => TRUE,
  );
  
  // @todo add detection for aggressive caching and disable redirection field
  // @todo add form alter on caching form to disable the redirection flag
  // @todo change options for redirect to the following:
  //  - none
  //  - first page (redirect the user when they view their first page, i.e. when they create their session)
  //  - automatic (redirect on all pages)
  
  $form['general']['mobile_tools_redirection']['mobile_tools_redirect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable automatic redirection of the mobile user'),
    '#default_value' => variable_get('mobile_tools_redirect', FALSE),
    '#description' => 'Mobile visitors will automatically be redirected to the mobile site. But mobile users can also -- if they prefer --
    view the desktop version. In order to do so, append ?device=desktop to the URL. The module
    will set a cookie that remembers that the user does not want to be redirected. To undo, add ?device=auto',
  );
  
  $form['general']['mobile_tools_redirection']['mobile_tools_cookie_session'] = array (
    '#type' => 'textfield',
    '#title' => 'Redirection cookie    (seconds)',
    '#description' => t('This field is only used when using the "?device=" setting. This is the lifetime of the cookie that determines how long the session is remembered. Choose 0 for only the session.'),
    '#default_value' => variable_get('mobile_tools_cookie_session', 3600*24*30),
  );
  
  $form['general']['mobile_tools_redirection']['mobile_tools_redirect_exceptions_type'] = array(
  	'#type' => 'radios',
    '#title' => 'exception type',
    '#options' => array('not-redirect' => 'Do not redirect from the following pages', 'only-redirect' => 'Do only redirect from the following pages' ),
    '#default_value' => variable_get('mobile_tools_redirect_exceptions_type', 'not-redirect'),
  );
  
  $form['general']['mobile_tools_redirection']['mobile_tools_redirect_exceptions'] = array(
  	'#type' => 'textarea',
    '#title' => 'redirection exceptions',
    '#description' => t('Give the paths to pages that should not be redirected. Put each path on a separate line. The \'*\' character is a wildcard.'),
    '#default_value' => variable_get('mobile_tools_redirect_exceptions', ''),
  );
  
  $form['general']['mobile_tools_notification'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mobile Tools block message options'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#description' => t('You can create a block with a different message on the mobile site than the desktop site. This can be for example used to create a link back to the deskop or mobile site (e.g. view Mobile | Desktop)'),
  );

  $form['general']['mobile_tools_notification']['mobile_tools_switch_link_text'] = array(
    '#type' => 'textarea',
    '#rows' => 2,
    '#title' => t('Block text'),
    '#description' => t('If you would like to include the name of the device group in your text, add &#64;device to your text. It will be replaced by the name of the device group.'),
    '#default_value' => variable_get('mobile_tools_switch_link_text', MOBILE_TOOLS_SWITCH_LINK_TEXT),
  );
   
   $form['general']['build_mode'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mobile Tools Build Mode'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Enable a Mobile Build mode'),
  );
  
  $form['general']['build_mode']['mobile_tools_enable_build_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable a Mobile Tools display mode'),
    '#default_value' => variable_get('mobile_tools_enable_build_mode', 0),
    '#description' => t('New build modes will be available in the Content Types configuration page (see Manage Display)'),
  );
  
  $form['general']['extra'] = array(
    '#type' => 'fieldset',
    '#title' => 'Other Options',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  

  $form['general']['extra']['default_nodes_main_mobile'] = array(
      '#type' => 'select',
      '#title' => t('Number of posts on main page for the mobile version'),
      '#default_value' => variable_get('default_nodes_main_mobile', 10),
      '#options' => Array(
              1 => 1,
              2 => 2,
              3 => 3,
              4 => 4,
              5 => 5,
              6 => 6,
              7 => 7,
              8 => 8,
              9 => 9,
              10 => 10,
              15 => 15,
              20 => 20,
              25 => 25,
              30 => 30,
          ),
      '#description' => t('The default maximum number of posts to display per page on overview pages such as the main page (on Mobile).'),
  );

  $form['general']['extra']['site_frontpage_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Choose another frontpage for mobile visitors.'),
    '#default_value' => variable_get('site_frontpage_mobile', variable_get('site_frontpage', 'node')),
    '#description' => t('If you want a different page as the frontpage of your site for mobile users, specify it here.'),
  );
  return system_settings_form($form);
}

/**
 * Validation of the system settings form
 */
function mobile_tools_configuration_form_validate($form, &$form_state) {
  $form_state['values']['mobile_tools_mobile_url'] = preg_replace('{/$}', '', $form_state['values']['mobile_tools_mobile_url']);
  $form_state['values']['mobile_tools_desktop_url'] = preg_replace('{/$}', '', $form_state['values']['mobile_tools_desktop_url']);
  
  // Move to submit handler
  cache_clear_all('entity_info', 'cache', TRUE);
  variable_set('menu_rebuild_needed', TRUE);
}

/**
 * Configuration form for Space related settings
 */
function mobile_tools_configuration_spaces_form($form, &$form_state) {
  $form = array();
  
  // @todo

  return system_settings_form($form);
}

 /**
 * Configuration form for configuring the mobile context in the theming system
 */ 
function mobile_tools_themes_configuration_form() {
  $themes = mobile_tools_list_theme_names();
  $prefix = '';
  $warning = '';
  if (count($themes) == 0) {
    $warning = '<div class="message error">You must enable themes in order to use theme switching</div>';
  }   

  $form['mobile_tools_theme_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => 'Theming configuration',
    '#collapsible' => TRUE,
    '#description' => t('You can assign a variation of your current theme to all mobile users . this allows you to configure your theme 
    specific for mobile users. See !url for more information on this configuration. In order to use this functionality
    you will have to manually create a second *.info file in your theme directory.', array('!url' => l('help', 'help'))),
    '#suffix' => t('If enabled, !configure the settings of your mobile theme and manage the !blocks layout', array('!configure' => l('configure', 'admin/appearance/list'), '!blocks' => l('blocks', 'admin/structure/block'))) .'<br>',
    '#prefix' => $warning,
   );
    $form['mobile_tools_theme_configuration']['mobile_tools_theme_switch'] = array(
    '#type' => 'radios',
    '#title' => t('When do you want to switch themes'),
    '#default_value' => variable_get('mobile_tools_theme_switch', 'mobile-tools-no-switch'),
    '#options' =>   array('mobile-tools-no-switch' => 'No theme switch', 'mobile-tools-mobile-url' => 'Switch theme based on the URL'),
    '#description' => 'Choose one of these methods. To change theme based on device, ensure device redirection is enabled. *Note these settings will be replaced by the new device groups options.',
  );
  if (count($themes) > 0 ) {
   $form['mobile_tools_theme_configuration']['mobile_tools_theme_name'] = array(
     '#type' => 'select',
     '#title' => 'Mobile theme',
     '#default_value' => variable_get("mobile_tools_theme_name", FALSE),
     '#options' => $themes,
     '#description' => t('Select your default mobile theme. You can specify a different theme for different devices.'),
 //    '#prefix' => t('!configure your mobile theme', array('!configure' => l('Configure', 'admin/structure/block/' . variable_get("mobile_tools_theme_name", FALSE)))),
  );

  $form['mobile_tools_theme_configuration']['mobile_tools_additional_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional mobile specific theming configuration')
  );
  
  $form['mobile_tools_theme_configuration']['mobile_tools_additional_config']['mobile_tools_hide_address_bar'] = array(
   '#type' => 'checkbox',
   '#title' => t('Automatically hide address bar in mobile theme (uses javascript and only work on javascript enabled devices)'),
   '#default_value' => variable_get('mobile_tools_hide_address_bar', 1),
   '#description' => t('Enabling this injects some line of javascript to hide the address bar when the page is loaded'),
  );
  
  $form['mobile_tools_theme_configuration']['mobile_tools_additional_config']['mobile_tools_add_header'] = array(
   '#type' => 'checkbox',
   '#title' => t('Add Mobile Tools header'),
   '#default_value' => variable_get('mobile_tools_add_header', 1),
   '#description' => t('Add mobile specific headers into the header tag. This includes viewport, HandheldFriendly, ... See theme/mobile-tools-header.tpl.php'),
  );

   // for each group, checkbox and dropdown
   // Mobile
   $mobile_groups = module_invoke(variable_get('mobile_tools_device_detection', 'mobile_tools'), 'device_groups');
   $mobile_detection_module = variable_get('mobile_tools_device_detection', 'mobile_tools');
   foreach ($mobile_groups as $group => $group_title) {
      $form['mobile_tools_theme_configuration'][$mobile_detection_module . '_' . $group] = array(
        '#type' => 'fieldset',
        '#title' => $group_title,
        '#collapsible' => TRUE,
        
      );
      $form['mobile_tools_theme_configuration'][$mobile_detection_module . '_' . $group][$mobile_detection_module . '_' . $group . '_enable'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enable filter for this device group'),
        '#default_value' => variable_get($mobile_detection_module . '_' . $group . '_enable', ''),
        '#description' => t('Choose a theme for this device group'),
      );
       $form['mobile_tools_theme_configuration'][$mobile_detection_module . '_' . $group][$mobile_detection_module . '_' . $group . '_theme'] = array(
         '#type' => 'select',
         '#title' => 'Mobile theme',
         '#default_value' => variable_get($mobile_detection_module . '_' . $group . '_theme', FALSE),
         '#options' => $themes,
         '#description' => t('Select your mobile theme. See <a href="">help</a> for information on the name'),
      );
     } 
   }
   return system_settings_form($form);
}

/**
 * Function returning the available themes
 */ 
function mobile_tools_list_theme_names() {
  global $conf;
  $themes = list_themes();
  $list = array();
  foreach ($themes as $key => $value ) {
    if ($value->status == 1 ) {
      $list[] = $key;
    }    
  }
  if (count($list) == 0) {
    return array();
  } 
  else {
    return array_combine($list, $list);
  }
}

/**
 * Helper function to return the configuration options
 */ 
function mobile_tools_configuration_options($configuration) {
  switch ($configuration) {
    case 'device handling':
      $options = array(
        'nothing' => t('Do nothing, just provide the $_SESSION[\'mobile_device\'] variable'), 
        'redirect' => t('Automatic redirection to mobile or desktop site'), 
      //  'notification' => t('Display a block notification with link to mobile site'),
      //  'theme-switch' => t('Switch the theme when a mobile user visits the site (only 1 url for both mobile and desktop url). Enable and configure the mobile theme !here', array('!here' => l('here', 'admin/settings/mobile-tools/themes'))),
      );
    break;
    case 'site type':
      $options =  array(
        'mobile' => t('Only the mobile site'),  
        'desktop' => t('only the deskop site'), 
        'mobile-desktop' => t('for both mobile and desktop site'),
      );
    break;
  }  
  return $options;
}

/**
 * Helper function to assist in making a mobile url (m.*) from a given url
 *
 * @param $url
 *  orginal url
 * @return
 *  the mobile url
 */
function mobile_tools_create_mobile_url($url) {
  
  // @todo replace with a PURL provider definition
  
  $url_parsed = parse_url($url);
  if (!array_key_exists('path', $url_parsed)) {
    $url_parsed['path'] = "";
  }
  $url = $url_parsed['host'];
  $url = explode('.', $url);
  if (count($url) == 3 ) {
    $url[0] = 'm';
    return 'http://' . implode('.', $url)  . $url_parsed['path'];
  }
  elseif (count($url) == 2) {
    return 'http://m.' . implode('.', $url)  . $url_parsed['path'];
  }
  else {
    return 'http://' .  implode('.', $url)  . $url_parsed['path'] . '/mobile';
  }
}
