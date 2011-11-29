<?php
/**
 * @file
 * pw_defaults.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function pw_defaults_default_rules_configuration() {
  $items = array();
  $items['rules_ad_submission_login_redirect'] = entity_import('rules_config', '{ "rules_ad_submission_login_redirect" : {
      "LABEL" : "Login Existing User Redirect",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "ad_submission", "login" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "1" : "1", "4" : "4", "2" : "2" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "submit-ad" } } ]
    }
  }');
  $items['rules_ad_submission_submission_redirect'] = entity_import('rules_config', '{ "rules_ad_submission_submission_redirect" : {
      "LABEL" : "Ad Submission Submission Redirect",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "ad_submission redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "ad_s" : "ad_s" } } } },
        { "user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : { "1" : "1", "4" : "4", "2" : "2" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "thank-you" } } ]
    }
  }');
  return $items;
}
