README.txt
==========
The purpose of this module is to provide de Drupal developer with some tools that assist in making sites for defined "device groups".

INSTALLATION
============

**NOTE**
If you have previously installed the 7.x-2.0-unstable, an older dev release or upgrading from the 6.x branch your site settings will not migrate over. Be sure to fully uninstall mobile tools before upgrading to this version.


This module has the following dependencies:

- [PURL](http://drupal.org/project/purl)
- [Spaces](http://drupal.org/project/spaces)
- [ThemeKey](http://drupal.org/project/themekey)

It can also take advantage of the following modules if available:

- [Session API](http://drupal.org/project/session_api)
- [BrowsCap](http://drupal.org/project/browscap)
- [WURFL](http://drupal.org/project/wurfl)
- [Modernizr](http://drupal.org/project/modernizr)

To install the module and all dependencies from the module administration panel.

Then you can begin configuration by going to admin/config/system/mobile-tools

You can enable any of the defined configuration presets, modify them or create your own.

USAGE
=====

Mobile Tools works with the concept of "device groups". A device group is any grouping of conditions or requirements for a given type of device or set of devices. Each defined device group can cause Drupal to display a different theme, override site variables, display different views displays among other things.

For example, you can define a set of device groups as follows:

- desktop
- tablet
- phone

Each can be triggered in various ways. The most common way is by a custom URL pattern. You could trigger each device group's settings by using the following URL structure in your configuration:

- example.com
- touch.example.com
- m.example.com


Subdomains aren't your only options. URL handling in Mobile Tools is powered by the [PURL](http://drupal.org/project/purl) module. This means you can active a device group using a different domain, path, path pair and more. You can even define your own PURL processor if you so choose. For more information on creating PURL processors, see the README.txt in the [PURL](http://drupal.org/project/purl) module.

Advanced Usage
==============

Automatic Redirection
---------------------
If you want to direct your users to the appropriate site automatically based on their detected device group, you have two modes you can use

1. First visit redirect
2. Automatica redirect

The first will redirect the user as their session is initiated. The device group is determined and then a one-time redirection will occur to send the user to the appropriate URL. If the user then decides to explicitly choose which device group site to visit, then the redirection won't interfere.

The second forces the user into their device group regardless of their choice. There is no means of overriding the automatic redirection.

Device/Capability Detection
---------------------------

Another way of triggering a device group is by using device detection. There are a few ways of detecting the type of device the user is using. You can go by the user-agent headers in the request object and use [Browscap](http://drupal.org/project/browscap) to determine the type of device. You could have a set of device groups as follows:

- iOS
- Android
- Gecko

Or you can use the [WURFL](http://drupal.org/project/wurfl) to determine the capabilities of the device and assign the device to an appropriate group

Example device groups based on browser quality:

- enhanced
- normal
- basic

Finally, along the same lines as WURFL, you can use [Modernizr](http://drupal.org/project/modernizr) to run its capabilities check on the device and report the results back to Drupal. This is the most accurate way of determining the capabilities of the device in use. If you get no return from the device, you'll have to assume that javascript doesn't work and assign the device to an appropriate device group. But if a return value is set, you can parse the test results and group your device accordingly. The results of that test are saved using the [Session API](http://drupal.org/project/session_api) module. This allows both anonymous and authenticated user device settings to persist.

@TODO describe the usage with modernizr

Device Group Contexts
---------------------

TODO


SETTINGS AND OPTIONS
====================

Each device group has two key functions:

1. Allow a theme override
2. Allow a site configuration override

The first is handled using the [ThemeKey](http://drupal.org/project/themekey) module. Each device group can trigger a defined rule in ThemeKey to switch the theme for the incoming request.

The second is handled using the [Spaces](http://drupal.org/project/spaces) module. Spaces allows you to override Drupal objects giving custom configurations for each Space. Each device group is it's own Space and therefore will load configuration options in the following order

1. custom
2. preset
3. sitewide

For example, when variable_get('site_name'); is called in a Space, it will first look at the spaces_overrides table to see if there is a value set for 'site_name'. Next, it will check any defined values in the Space preset for this value. Finally, it will load the normal value from the default Drupal table. For more information, see the README.txt in the [Spaces](http://drupal.org/project/spaces) module.

To configure each device group's Space settings, go to admin/structure/spaces.

CACHING
=======

@TODO rewrite any required caching mechanisms


AUTHOR/MAINTAINER
======================
Tom Deryckere
http://twitter.com/twom
http://www.mobiledrupal.com

CO-MAINTAINER
=============
Mathew Winstone (minorOffense)
http://twitter.com/mathewwinstone
http://coldfrontlabs.ca