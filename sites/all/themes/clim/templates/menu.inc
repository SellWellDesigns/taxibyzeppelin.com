<?php

// Init
$nav = '';

// Build list of links with the l funcrtion

// Output nav markup
$nav = "
	<ul id=\"nav\">
		<li><a class=\"about\" href=\"#about\">About</a></li>
		<li><a class=\"companies\" href=\"#companies\">Companies</a></li>
		<li><a class=\"contact\" href=\"#contact\">Contact</a></li>
		<li><a class=\"map\" href=\"#map\">Map</a></li>
		<li><a href=\"http://blog.taxibyzeppelin.com/\">Blog</a></li>
	</ul>
";

print $nav;