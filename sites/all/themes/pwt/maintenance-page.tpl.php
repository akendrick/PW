<?php

/**
 * @file
 * Override of the default maintenance page.
 *
 * This is an override of the default maintenance page. Used for Garland and
 * Minnelli, this file should not be moved or modified since the installation
 * and update pages depend on this file.
 *
 * This mirrors closely page.tpl.php for Garland in order to share the same
 * styles.
 */
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <title><?php print $head_title ?></title>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
  </head>
  <body class="<?php print $classes ?>"
    style='background-color:#d1e5ff;text-align:center;font-size: 1em;font-family:sans-serif;'>

<!-- Layout -->
  <div id="header-region" class="clearfix"><?php print $header; ?></div>

    <div id="wrapper"
        style='
          border-radius: 10px;-moz-border-radius: 10px;-webkit-border-radius: 10px;
          border: solid 5px #036;
          background-color:#fff;
          width: 550px;
          padding: 25px;
          margin: 0 auto;
          display: block;
          '>
    <div id="container" class="clearfix">

      <div id="header" >
        <div id="logo-floater" >
        <?php
          // Prepare header
          $site_fields = array();
          if ($site_name) {
            $site_fields[] = $site_name;
          }
          if ($site_slogan) {
            $site_fields[] = $site_slogan;
          }
          $site_title = implode(' ', $site_fields);
          if ($site_fields) {
            $site_fields[0] = '<div style="font-size:1.4em;">' . $site_fields[0] . '</div>';
          }
          $site_html = implode(' ', $site_fields);

          if ($logo || $site_title) {
            $style = 'style="margin: 0 auto; display: block;padding: 10px;font-size:1em;"';
            print '<h4 id="branding" >'; //<a href="' . $base_path . '" title="' . $site_title  . '" style="font-size:1em;">';
            if ($logo) {
              print '<img src="' . $logo . '" alt="' . $site_title . '" id="logo" ' . $style . '/>';
            }
            print $site_html . '</a>'; //</h4>';
          }
        ?>
        </div>

      </div> <!-- /header -->

      <?php if ($sidebar_first): ?>
        <div id="sidebar-first" class="sidebar">
          <?php print $sidebar_first ?>
        </div>
      <?php endif; ?>

      <div id="center">
        <div id="squeeze">
          <div class="right-corner">
            <div class="left-corner" style="
                border-radius: 10px;-moz-border-radius: 10px;-webkit-border-radius: 10px;
                width: 80%;
                font-size:1.6em;
                margin: 0 auto;
                display: block;
                padding: 30px;
                line-height: 1.2em;
                background-color: #e5e0dc;">
              <?php if ($title): ?><h2><?php print $title ?></h2><?php endif; ?>
              <?php print $messages; ?>
              <?php print $help; ?>
              <div class="clearfix">
                <?php print $content ?>
                <p></p>
              </div>
              <p >
                For more information or to place an ad please call
                <span class="phone" style="font-weight:bolder">1-800-663-4619</span> or email
                <span class="email" style="font-style:emphasize;">
                  <a href="mailto:info@pennywiseads.com">info@pennywiseads.com</a>
                </span>
              </p>
            </div>
          </div>
          <div id="footer"><?php print $footer ?>
            <div style="padding: 10px; margin: 0 auto; display:block;font-size: .8em; text-decoration:none;">
              <a href="http://pennywiseads.com/user/login" style="text-decoration:none;">Staff Login</a>
            </div>
          </div>
        </div>
      </div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->

      <?php if ($sidebar_second): ?>
        <div id="sidebar-second" class="sidebar">
          <?php print $sidebar_second ?>
        </div>
      <?php endif; ?>

    </div> <!-- /container -->
  </div>
<!-- /layout -->

  </body>
</html>
