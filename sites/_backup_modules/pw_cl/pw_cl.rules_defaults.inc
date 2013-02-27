<?php
/**
 * @file
 * pw_cl.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function pw_cl_default_rules_configuration() {
  $items = array();
  $items['rules_ad_submission_login_redirect'] = entity_import('rules_config', '{ "rules_ad_submission_login_redirect" : {
      "LABEL" : "Anon - Ad Submission Login Redirect ",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "ad_submission", "login", "redirect" ],
      "REQUIRES" : [ "path", "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [ { "path_has_alias" : { "source" : "ad\\u002Fsubmit" } } ],
      "DO" : [  ]
    }
  }');
  $items['rules_ad_submission_submission_redirect'] = entity_import('rules_config', '{ "rules_ad_submission_submission_redirect" : {
      "LABEL" : "Anon - Ad Submission Thank you",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
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
      "DO" : [ { "redirect" : { "url" : "ad\\u002Fthank-you" } } ]
    }
  }');
  return $items;
}
