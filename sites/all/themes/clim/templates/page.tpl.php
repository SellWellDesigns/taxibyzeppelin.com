<div id="logo">
  <a href="html"><img src="/sites/all/themes/clim/images/logo.png"/></a>
</div>
<header id="main-menu">
  <nav id="nav">
    <?php include 'menu.inc'; ?>
  </nav>
</header>

<div id="wrap" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $messages; ?>
	<?php print render($page['content']) ?>
</div>
<div id="social">
	<?php include 'social.inc'; ?>
</div>
<div id="loader"></div>
