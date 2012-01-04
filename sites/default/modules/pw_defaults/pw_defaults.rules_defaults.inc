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
  $items['rules_add_another'] = entity_import('rules_config', '{ "rules_add_another" : {
      "LABEL" : "Add Another",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "clone", "duplication" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "6" : "6", "5" : "5", "7" : "7" } },
            "operation" : "OR"
          }
        },
        { "AND" : [] },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "classified" : "classified",
                "display_ads" : "display_ads",
                "article" : "article"
              }
            }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u003ca href=\'[site:url]\\/node\\/add\\/[node:content-type]\' class=\'add-another\'\\u003e+ Add Another \\u003c\\/a\\u003e" } }
      ]
    }
  }');
  $items['rules_editorial_redirect_'] = entity_import('rules_config', '{ "rules_editorial_redirect_" : {
      "LABEL" : "Redirect Admin - Editorial",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "editorial", "login", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "7" : "7" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "pwadmin\\/article" } } ]
    }
  }');
  $items['rules_redirect_admin_classifieds'] = entity_import('rules_config', '{ "rules_redirect_admin_classifieds" : {
      "LABEL" : "Redirect Admin - Classifieds",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "classified", "login", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "5" : "5" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "pwadmin\\/classified\\/incoming" } } ]
    }
  }');
  $items['rules_redirect_display_admin'] = entity_import('rules_config', '{ "rules_redirect_display_admin" : {
      "LABEL" : "Redirect Admin -Display",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "display", "login", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "6" : "6", "3" : "3" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "pwadmin\\/display_ads" } } ]
    }
  }');
  return $items;
}
