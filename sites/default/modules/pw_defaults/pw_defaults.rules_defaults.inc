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
      "ACTIVE" : false,
      "TAGS" : [ "admin", "clone", "duplication" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update", "node_presave" ],
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
        { "drupal_message" : { "message" : "\\u003Ca href=\\u0027[site:url]\\/node\\/add\\/[node:content-type]\\u0027 class=\\u0027add-another\\u0027\\u003E+ Add Another \\u003C\\/a\\u003E" } }
      ]
    }
  }');
  $items['rules_editorial_redirect_'] = entity_import('rules_config', '{ "rules_editorial_redirect_" : {
      "LABEL" : "Editorial - Redirect Admin",
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
      "DO" : [ { "redirect" : { "url" : "admin\\/pennywise\\/article" } } ]
    }
  }');
  $items['rules_redirect_admin_classifieds'] = entity_import('rules_config', '{ "rules_redirect_admin_classifieds" : {
      "LABEL" : "Classifieds - Redirect Admin",
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
      "DO" : [ { "redirect" : { "url" : "admin\\/pennywise\\/classified\\/incoming" } } ]
    }
  }');
  $items['rules_redirect_display_admin'] = entity_import('rules_config', '{ "rules_redirect_display_admin" : {
      "LABEL" : "Display - Admin Login Redirect",
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
      "DO" : [ { "redirect" : { "url" : "admin\\/pennywise\\/display_ads" } } ]
    }
  }');
  return $items;
}
