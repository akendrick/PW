<?php
  // Variables available:
   // 'toll_free'
   // 'local'
   // 'fax'
   // 'email'
   // 'contest'
   // 'address'
   // 'facebook'
   // 'twitter'
?>
<div id='pw-masthead'>
  <div class='pw-masthead-block pw-masthead-block-contact'>
    <?php print $toll_free; ?>
    <?php print $local; ?>
    <?php print $fax; ?>
    <?php print $email; ?>
  </div>
  <div class='pw-masthead-block pw-masthead-block-social'>
    <?php print $contest; ?>
    <?php print $facebook; ?>
    <?php print $twitter; ?>
  </div>
  <div class='pw-masthead-block pw-masthead-block-address'>
    <?php print $address; ?>
  </div>


</div>