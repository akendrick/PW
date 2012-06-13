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
  $items['rules_add_another'] = entity_import('rules_config', '{ "rules_add_another" : {
      "LABEL" : "Add Another",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "admin", "clone", "duplication" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "attachment" : "attachment",
                "classified" : "classified",
                "display_ads" : "display_ads",
                "article" : "article",
                "pw_digital" : "pw_digital",
                "page" : "page"
              }
            }
          }
        },
        { "AND" : [] },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "6" : "6", "5" : "5", "7" : "7", "3" : "3", "10" : "10" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u003Ca href=\\u0027[site:url]\\/node\\/add\\/[node:content-type]\\u0027 class=\\u0027add-another\\u0027\\u003E+ Add Another \\u003C\\/a\\u003E" } }
      ]
    }
  }');
  $items['rules_demote_other_editorials'] = entity_import('rules_config', '{ "rules_demote_other_editorials" : {
      "LABEL" : "Demote Other Editorials",
      "PLUGIN" : "action set",
      "TAGS" : [ "admin", "demote", "editorial" ],
      "REQUIRES" : [ "views_bulk_operations", "rules" ],
      "ACTION SET" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "editorial_promote_list|page" },
            "PROVIDE" : { "entity_list" : { "promoted_node_list" : "Promoted List of Nodes" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "promoted-node-list" ] },
            "ITEM" : { "node_list" : "Node List" },
            "DO" : [
              { "node_unpromote" : { "node" : [ "node-list" ] } },
              { "drupal_message" : { "message" : "Demoted [node:title] from front page." } }
            ]
          }
        }
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
  $items['rules_promote_incoming_ads'] = entity_import('rules_config', '{ "rules_promote_incoming_ads" : {
      "LABEL" : "Promote Incoming Ads",
      "PLUGIN" : "action set",
      "TAGS" : [ "admin", "classified" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [ { "data_set" : { "data" : [ "node:type" ], "value" : "classified" } } ]
    }
  }');
  $items['rules_publish_scheduled_nodes'] = entity_import('rules_config', '{ "rules_publish_scheduled_nodes" : {
      "LABEL" : "Publish Scheduled Nodes",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "node_publish" : { "node" : [ "node" ] } },
        { "views_bulk_operations_action_load_id_list" : {
            "USING" : {
              "view" : "classified_ad_administration|page_1",
              "args" : "[node:scheduler-publish]"
            },
            "PROVIDE" : { "entity_id_list" : { "entity_id_list" : "A list of entity ids" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-id-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : []
          }
        }
      ]
    }
  }');
  $items['rules_redirect_admin_adworks'] = entity_import('rules_config', '{ "rules_redirect_admin_adworks" : {
      "LABEL" : "Adworks - Admin Redirect",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "pw", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "adworks_file" : "adworks_file" } }
          }
        },
        { "AND" : [] },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5" } }
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "admin\\/pennywise\\/classified\\/edit" } } ]
    }
  }');
  $items['rules_redirect_admin_adworks_upload'] = entity_import('rules_config', '{ "rules_redirect_admin_adworks_upload" : {
      "LABEL" : "Classified - Redirect Admin",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "classifieds", "pw", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5", "3" : "3" } },
            "operation" : "OR"
          }
        },
        { "AND" : [] },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "adworks_file" : "adworks_file" } }
          }
        }
      ],
      "DO" : [
        { "redirect" : {
            "url" : "admin\\/pennywise\\/classified\\/unpublished",
            "force" : 0,
            "destination" : 1
          }
        }
      ]
    }
  }');
  $items['rules_redirect_admin_classified_ad_link'] = entity_import('rules_config', '{ "rules_redirect_admin_classified_ad_link" : {
      "LABEL" : "Admin - Create Another Link",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "admin", "classifieds", "display", "link", "pw" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_view", "node_presave" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5", "3" : "3" } }
          }
        },
        { "AND" : [] },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "adworks_file" : "adworks_file", "classified" : "classified" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u003Cul class=\\u0022action-links\\u0022\\u003E\\u003Cli\\u003E\\u003Ca href=\\u0027pwadmin\\/classified\\/classifieds\\u0027\\u003EEdit Classifieds\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\u003Cli\\u003E\\u003Ca href=\\u0027pwadmin\\/classified\\/incoming\\u0027\\u003EView Incoming Ads\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\u003C\\/ul\\u003E" } }
      ]
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
  $items['rules_redirect_admin_display_ad_create'] = entity_import('rules_config', '{ "rules_redirect_admin_display_ad_create" : {
      "LABEL" : "Display - Admin Redirect on Save",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "admin", "display", "pw", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "6" : "6", "3" : "3" } },
            "operation" : "OR"
          }
        },
        { "AND" : [] },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "display_ads" : "display_ads" } }
          }
        }
      ],
      "DO" : [
        { "redirect" : {
            "url" : "admin\\/pennywise\\/display_ads",
            "force" : 0,
            "destination" : 1
          }
        }
      ]
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
