<?php
/**
 * @file
 * pw_admin.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function pw_admin_default_rules_configuration() {
  $items = array();
  $items['rules_ad_submission_redirect'] = entity_import('rules_config', '{ "rules_ad_submission_redirect" : {
      "LABEL" : "Ad Submission Redirect",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin" ],
      "REQUIRES" : [ "path", "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [ { "path_has_alias" : { "source" : "ad\\u002Fsumit" } } ],
      "DO" : [ { "redirect" : { "url" : "ad\\u002Fsubmit" } } ]
    }
  }');
  return $items;
}
