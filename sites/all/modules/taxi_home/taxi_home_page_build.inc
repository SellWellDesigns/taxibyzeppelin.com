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
  $bg_slides    = '';


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

  // Build query for slider images
  $slider_query_string = "
  	SELECT c.fid, c.weight, c.parent_type, f.fid, f.uri
    FROM cirro_multi_img AS c
    JOIN file_managed AS f
    ON c.fid = f.fid
    ORDER BY c.weight
  ";

  // Home page query string
  $home_query_string = "
    SELECT intro_body, address, leasing_info
    FROM taxi_home_page
  ";

  // Company item query string 
  $company_query_string = "
    SELECT title, link, building
    FROM taxi_company_item
    ORDER BY building, title
  ";
  
  // Use drupal's db_query function 
  $slider_query = db_query( $slider_query_string );
  $slider_items = $slider_query->fetchAll();

  // Use drupal's db_query function 
  $home_query = db_query( $home_query_string );
  $home_items = $home_query->fetchAll();

  // Use drupal's db_query function 
  $company_query = db_query( $company_query_string );
  $company_items = $company_query->fetchAll();

  dsm($company_items);

  // Loop through compant items to build list
  foreach ($company_items as $key => $value) {
    
      $company = $value->title;
      $company_url = $value->link;
      $building = $value->building;

      $building_title = NULL;


  }

  // Home Page vars
  $intro_body   = $home_items[0]->intro_body;
  $address      = $home_items[0]->address;
  $leasing_info = $home_items[0]->leasing_info;

  // Loop through and build images
  foreach ( $slider_items as $key => $value ) {

    $uri = $value->uri;
    $img_path = file_create_url($uri);

    // Build slide markup
    $bg_slides .= "
      <div id=\"slide_01\" class=\"slide\" style=\"background-image: url($img_path); display: none;\"></div>
    ";

  }

  // Background slides with wrapper
  $bg_slider = "
  	<section id=\"bg-slider\" class=\"section\">
  		$bg_slides
  	</section>
  ";

  // Add $window var to sections that you want a break in sections
  $window = "
  	<section class=\"slide-window\"></section>
  ";


  $about = "
  	<section id=\"about\" class=\"section text-center\">
  			<img src=\"/sites/all/themes/clim/images/slice01.png\" class=\"slice\"/>
  		<article class=\"content-section\">
  			<h1>About</h1>
        <div class=\"body-text\">
          $intro_body
        </div>
  		</article>
  		<img src=\"/sites/all/themes/clim/images/slice02.png\" class=\"slice\"/>
  	</section>
  ";

  $companies = "
  	<section id=\"companies\" class=\"section text-center\">
  		<img src=\"/sites/all/themes/clim/images/slice03.png\" class=\"slice\"/>
  		<article class=\"content-section\">
  			<h1>Companies</h1>
          
  		</article>
      <img src=\"/sites/all/themes/clim/images/slice04.png\" class=\"slice\"/>
  	</section>
  ";

  $contact = "
  	<section id=\"contact\" class=\"section text-center\">
      <img src=\"/sites/all/themes/clim/images/slice05.png\" class=\"slice\"/>
      <article class=\"content-section\">
        <h1>Contact</h1>
        $address
        $leasing_info
      </article>
      <img src=\"/sites/all/themes/clim/images/slice06.png\" class=\"slice\"/>
		</section> 
  ";

  $map = "
  	 <div id=\"map_canvas\" style=\"width:100%; height:100%\"></div>
  ";

  // Putting everything together :)
	$html = "
		$bg_slider
		<div id=\"main-content\">
			<div id=\"start-section\"></div>
			$about
			$window
			$companies
			$window
			$contact
			$window
			$map
		</div>
	";
	

	return $html; 

}