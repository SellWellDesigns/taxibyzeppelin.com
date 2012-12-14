<header id="main-menu">
  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
  </a>
  <nav id="nav">
    <?php include 'menu.inc'; ?>
  </nav>
</header>

<div id="wrap" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $messages; ?>
	<?php print render($page['content']) ?>
</div>

<footer id="footer">
 
</footer> 