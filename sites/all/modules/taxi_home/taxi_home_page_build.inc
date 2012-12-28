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
  $all_companies = array();
  $companies_markup = '';


	// Adding javascript
	$js_path = "$module_path/js/jquery.easing.1.3.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 1));
	$js_path = "$module_path/js/homepage.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 10));
	$js_path = "https://maps.google.com/maps/api/js?sensor=false";
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

  // Map image
  $map_query_string = "
    SELECT m.map_img, f.fid, f.uri
    FROM taxi_home_page AS m
    JOIN file_managed AS f
    ON m.map_img = f.fid
  ";
  
  // Use drupal's db_query function 
  $slider_query = db_query( $slider_query_string );
  $slider_items = $slider_query->fetchAll();

  $home_query = db_query( $home_query_string );
  $home_items = $home_query->fetchAll();

  $company_query = db_query( $company_query_string );
  $company_items = $company_query->fetchAll();

  $map_query = db_query( $map_query_string );
  $map_item = $map_query->fetchAll();
  
  // Map image
  $map_img = $img_path = file_create_url($map_item[0]->uri);

  // Loop through compant items to build list
  foreach ( $company_items as $value ) {
    
    // Init
    $company = '';
    $company_url = '';
    $building = '';
    $link = '';

    // Get Data
    $company = $value->title;
    $company_url = $value->link;
    $building = str_replace('_', ' ', $value->building);
    $options = array( 'html' => TRUE );
    $link = l( "<p>$company</p>", $company_url, $options );


    // Load markup into appropriate array slot
    if ( isset( $all_companies[$building] ) ) {
      
      $all_companies[$building] .= "
        <div class=\"company-link\">$link</div>
      ";

    } else {
      
      $all_companies[$building] = "
        <div class=\"company-link\">$link</div>
      ";

    }

  }

  // Build companies markup
  foreach( $all_companies as $building => $companies ) {
    
    $companies_markup .= "
      <div class=\"building\">
        <h4>$building</h4>
        <div class=\"companies-list\">$companies</div>
      </div>
    ";

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
  	   <div class=\"tri tri-top\"></div>
  		<article class=\"content-section\">
  			<h1>About</h1>
        <hr></hr>
        <div class=\"body-text\">
          $intro_body
        </div>
  		</article>
      <div class=\"tri tri-bottom\"></div>
  	</section>
  ";

  $company_section = "
  	<section id=\"companies\" class=\"section text-center\">
  		<div class=\"tri tri-top\"></div>
  		<article class=\"content-section\">
  			<h1>Companies</h1>
        <hr></hr>
        <div class=\"buildings-wrapper\">
          $companies_markup
        </div>
  		</article>
      <div class=\"tri tri-bottom\"></div>
  	</section>
  ";

  $social = "
    <div id=\"social-btns\">
      <a href=\"###\">
        <span class=\"social\" data-icon=\"&#62220;\"></span>
      </a>
      <a href=\"###\">
        <span class=\"social\" data-icon=\"&#62217;\"></span>
      </a>
      <a href=\"###\">
        <span class=\"social\" data-icon=\"&#62253;\"></span>
      </a>
    </div>
  ";

  $contact = "
  	<section id=\"contact\" class=\"section text-center\">
      <div class=\"tri tri-top\"></div>
      <article class=\"content-section\">
        <h1>Contact</h1>
        <hr></hr>
        $address
        $leasing_info
        $social
      </article>
      <div class=\"tri tri-bottom\"></div>
		</section> 
  ";

  $map = "
  	<section id=\"map\" class=\"section text-center\">
      <div class=\"tri tri-top\"></div>
      <article class=\"content-section\">
        <div id=\"map-info\">
          <h1>MAP</h1>
            <a href=\"http://itunes.com/apps/appname\" class=\"btn\">
              Download the App
            </a>
        </div>
        <a href=\"https://maps.google.com/maps?q=3457+ringsby+ct&oe=utf-8&client=firefox-a&channel=np&hnear=3457+Ringsby+Ct,+Denver,+Colorado+80216&gl=us&t=v&z=16\">
          <div id=\"map-wrap\">
            <img src=\"$map_img\" />
          </div>
        </a>
      </article>
    </section>
  ";

  // Putting everything together :{) (with a moustach)
	$html = "
		$bg_slider
		<div id=\"main-content\">
			<section id=\"start-section\"></section>
			$about
			$window
			$company_section
			$window
			$contact
			$window
			$map
		</div>
	";
	

	return $html; 

}