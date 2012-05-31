
CONTENTS OF THIS FILE
---------------------

  * Introduction
  * Installation
  * Configuration
  * Known Issues


INTRODUCTION
------------

Current Maintainer: Scot Hubbard - http://drupal.org/user/868214

This module  allows content creators/maintainers to add maps to content via
the addition of a "Google Map Field" field type that can be added to content
types.

Using the google map field, the user can drop a marker on a map, set the
width, height and zoom factor of the map and save the data for the map
with the node.

There are no geocoding facilities and the standard map controls are shown by
default (Zoom pan up/down/left/right, Map/Satelite). This may be enhanced to
include more controls in a future version.

Another feature of this module is WYSIWYG integration. A WYSIWYG toolbar button
can be enabled under the WYSIWYG profiles setup to allow the user to open a
dialog that will enabled them to find a point on a map, set the width, height
and zoom factor, and insert a token directly into filtered content.  The map
will then display when the content is viewed normally.


INSTALLATION
------------

Install as usual...
see http://drupal.org/documentation/install/modules-themes/modules-7


CONFIGURATION
-------------

There are no specific config options for this module.  To use it you simply
add the "Google Map Field" to the entity on which you wish to use it
(node/taxonomy term/user etc).

To enable the WYSIWYG feature you must use the enlabed plugins/buttons feature
of the WYSIWYG module to enable the Google Map Field Token Builder

KNOWN ISSUES
------------

At the moment if you specify 'number of values' as anything other than 1 the
maps disappear in the node edit form when you click 'Add another'
