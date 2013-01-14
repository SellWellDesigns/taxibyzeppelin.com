<?php

// Init
$nav = '';
$dashboard = '';
global $user;

// Check for dashboard permission
if ( user_access('access dashboard') ) {

	$dashboard = "
		<li><a href=\"admin/dash\">Dashboard</a></li>
	";

}

// Output nav markup
$nav = "
	<ul id=\"nav\">
		<li><a class=\"about\" href=\"#about\">About</a></li>
		<li><a class=\"companies\" href=\"#companies\">Companies</a></li>
		<li><a class=\"contact\" href=\"#contact\">Contact</a></li>
		<li><a class=\"map\" href=\"#map\">Map</a></li>
		<li><a href=\"http://blog.taxibyzeppelin.com/\">Blog</a></li>
		$dashboard
	</ul>
";

print $nav;