
/**
 * @file
 * This file contain the javascript necessary to display google maps created
 * using the WYSIWYG inline map token builder.
 */

(function ($) {
  Drupal.behaviors.google_map_field_tokens = {
    attach: function (context) {
      var map_collection = Drupal.settings.gmf_token_maps;
      var map = [];
      for (var i = 0; i < map_collection.length; i++) {
        var latlng = new google.maps.LatLng(map_collection[i]['lat'], map_collection[i]['lon']);
        var mapOptions = {
          zoom: parseInt(map_collection[i]['zoom']),
          center: latlng,
          streetViewControl: false,
          mapTypeId: google.maps.MapTypeId.ROADMAP
        };
        // Create the map and drop it into the relavent container.
        map[i] = new google.maps.Map(document.getElementById("inline_google_map_field_"+parseInt(1000 + i)), mapOptions);
        // Add the marker to the map.
        marker = new google.maps.Marker({
          position: latlng,
          map: map[i],
        });
      }
    }
  };
})(jQuery);
