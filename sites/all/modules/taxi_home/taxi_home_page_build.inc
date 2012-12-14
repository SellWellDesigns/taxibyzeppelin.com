<?php
/**
* @file
*
* Build homepage
*
*/

function taxi_home_page_build(){

	// Init vars
	$module_path  = drupal_get_path('module','taxi_home');
	$brand        = '';
	$logo_grouped = '';
	$html         = '';
	$slider_imgs  = '';


	// Adding javascript
	$js_path = "$module_path/js/jquery.easing.1.3.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 1));
	$js_path = "$module_path/js/homepage.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 10));
	$js_path = "https://maps.google.com/maps/api/js?sensor=false";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 2));
	$js_path = "$module_path/js/jquery.stellar.min.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 3));
	$js_path = "$module_path/js/jquery.flexslider-min.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 3));

  // Build query for brands
  $brands_query_string = "
  	SELECT i.field_brand_logo_fid, i.delta, f.fid, f.uri
		FROM field_data_field_brand_logo AS i
		JOIN file_managed AS f
		ON i.field_brand_logo_fid = f.fid
		ORDER BY i.delta ASC
  ";
  
  // Use drupal's db_query function 
  // $brands_query = db_query( $brands_query_string );
  // $brand_items = $brands_query->fetchAll();

  $bg_slider = "
  	<section id=\"bg-slider\">
  		<img src=\"//taxibyzeppelin.com/TAXI_homepage_backgroundimage.gif\" />
  	</section>
  ";


  $about = "
  	<section id=\"about\" class=\"content-section text-center\">
  		<article>
  			<h1>About</h1>
  
  		</article>
  	</section>
  ";

  $companies = "
  	<section id=\"companies\" class=\"content-section text-center\">
  		<article>
  			<h1>Companies</h1>

  		</article>
  	</section>
  ";

  $footer = "
  	<footer id=\"footer\" class=\"text-center\">
		  	
		</footer> 
  ";


  $map = "
  	 <div id=\"map_canvas\" style=\"width:100%; height:100%\"></div>
  ";

	$html = "
		$bg_slider
		<div id=\"main-content\">
			$about
			$companies
			$footer
			$map
		</div>
	";
	

	return $html; 

}