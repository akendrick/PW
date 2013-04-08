
/**
 * @file
 * This file contains the necessary javascript to handle the WYSIWYG map
 * token builder plugin.
 */

(function ($) {

  Drupal.wysiwyg.plugins['gmf_tokenbuilder'] = {

    /**
     * Return whether the passed node belongs to this plugin.
     */
    isNode: function(node) {
      return ($(node).is('img.google-map-field-tokenbuilder-pin'));
    },

    /**
     * Invoke is called when the toolbar button is clicked.
     */
    invoke: function(data, settings, instanceId) {
      if (this.isNode(data.node)) {
        data.mapSettings = this._getMapSettings(data.node);
      } else {
        data.mapSettings = null;
      }
      Drupal.wysiwyg.plugins.gmf_tokenbuilder.add_form(data, settings, instanceId);
    },

    /**
     * Attach function, called when the WYSIWYG editor loads.
     * This will replace, in a non-destructive way, all the map tokens
     * with map pin images.
     */
    attach: function (content, settings, instanceId) {
      var matches = content.match(/\[gmf\:.*?\]/g);
      if (matches) {
        for (i = 0; i < matches.length; i++) {
          var inlineTag = matches[i];
          var toInsert = this._getPlaceholder(settings, inlineTag);
          content = content.replace(inlineTag, toInsert);
        }
      }
      return content;
    },

    /**
     * Detach function, called when a WYSIWYG editor detaches
     */
    detach: function (content, settings, instanceId) {
      // Replace all Map pin image placeholders with the actual tokens
      if (matches = content.match(/<img[^>]+class=([\'"])google-map-field-tokenbuilder-pin[^>]*>/gi)) {
        for (var i = 0; i < matches.length; i++) {
          var imgNode = matches[i];
          var token = $(imgNode).attr('alt');
          content = content.replace(imgNode, token);
        }
      }
      return content;
    },

    /**
     *  Open a dialog and present the map field token builder.
     */
    add_form: function (data, settings, instanceId) {
      // Location, where to fetch the dialog.
      var aurl = Drupal.settings.basePath + 'index.php?q=google-map-field/token-builder';
      dialogdiv = jQuery('<div id="insert-gmf-token"></div>');
      dialogdiv.load(aurl + " .content #google-map-field-tokenbuilder-form", function(){
        var dialogClose = function () {
          try {
            dialogdiv.dialog('destroy').remove();
          } catch (e) {};
        };
        // check if an existing map is being edited.
        if (data.mapSettings != null) {
          var lat = data.mapSettings.lat;
          var lon = data.mapSettings.lon;
          var zoom = data.mapSettings.zoom;
          var width = data.mapSettings.width;
          var height = data.mapSettings.height;
          dialogdiv.contents().find('#edit-width').val(width);
          dialogdiv.contents().find('#edit-height').val(height);
          dialogdiv.contents().find('#edit-zoom').val(zoom);
        }
        btns = {};
        btns[Drupal.t('Insert map')] = function () {
          var token = dialogdiv.contents().find('#edit-token').val();
          var mapWidth = dialogdiv.contents().find('#edit-width').val();
          var mapHeight = dialogdiv.contents().find('#edit-height').val();
          if (isNaN(mapWidth) || mapWidth > 600 || mapWidth < 100) {
            alert('Your map width must be between 100 and 600 pixles.');
            return false;
          }
          if (isNaN(mapHeight) || mapHeight > 600 || mapHeight < 100) {
            alert('Your map height must be between 100 and 600 pixles.');
            return false;
          }
          var editor_id = instanceId;
          token = ' [gmf:' + token + '] ';
          Drupal.wysiwyg.plugins.gmf_tokenbuilder.insertIntoEditor(settings, token, editor_id);
          jQuery(this).dialog("close");
        };

        btns[Drupal.t('Cancel')] = function () {
          jQuery(this).dialog("close");
        };

        dialogdiv.dialog({
          modal: true,
          autoOpen: false,
          closeOnEscape: true,
          resizable: false,
          draggable: false,
          autoresize: true,
          namespace: 'jquery_ui_dialog_default_ns',
          dialogClass: 'jquery_ui_dialog-dialog',
          title: Drupal.t('Insert Google Map Field Token'),
          buttons: btns,
          width: 550,
          close: dialogClose
        });
        dialogdiv.dialog("open");
        if (data.mapSettings == null) {
          google_map_field_getMap(null, null, null);
        } else {
          google_map_field_getMap(data.mapSettings.lat, data.mapSettings.lon, data.mapSettings.zoom);
          google_map_field_buildToken();
        }
      });
    },

    insertIntoEditor: function (settings, token, editor_id) {
      token = '<img class="google-map-field-tokenbuilder-pin" src="'+settings.path+'/images/gmftb.toolbar_icon.png" alt="'+token+'" title="Google Map">';
      Drupal.wysiwyg.instances[editor_id].insert(token);
    },

    /**
     * Helper function to return a HTML placeholder.
     */
    _getPlaceholder: function (settings, token) {
      return '<img class="google-map-field-tokenbuilder-pin" src="'+settings.path+'/images/gmftb.toolbar_icon.png" alt="'+token+'" title="Google Map">';
    },

    /**
     * Helper function to extract token settings from image place holder
     */
    _getMapSettings: function (data) {
      var mapSettings = {};
      var token = $(data).attr('alt');
      token = token.replace('[gmf:', '').replace(']', '');
      var nvPairs = token.split(',');
      for (var i = 0; i < nvPairs.length; i++) {
        var tmp = nvPairs[i].split('=');
        eval('mapSettings.'+tmp[0]+' = '+tmp[1]);
      }
      return mapSettings;
    }

  };

})(jQuery);
