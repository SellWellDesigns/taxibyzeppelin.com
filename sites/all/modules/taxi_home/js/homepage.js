;(function( $, window, document, undefined ){
    
	$(document).ready(function(){	

		// Init
	 	var	
				$window     = $(window),
				$nav        = $("#nav a"),
				$flexslider = $(".flexslider");

		// ----------------------------------------------------------
		// This scrolling is so damn smooth...mmmmmmm
		// ----------------------------------------------------------
		$(function(){

			$nav.on('click', function(event) {

				// Init
				var $link = $(this);

				// Scroll to href of clicked link
				$('html, body').stop().animate({

	          scrollTop: $($link.attr('href')).offset().top - 80

	      }, 1500,'easeInOutExpo');

				event.preventDefault();

			});

		});


		// ----------------------------------------------------------
		// Where am i? 
		// ----------------------------------------------------------
		$(function(){

			var sections  = {},
					$this     = $(this);
					winHeight = $window.height(),
					$nav      = $("#nav"),
					$navItem  = $("#nav li a"),
					i 				= 0;

			// Grab the position of all our sections
			$(".section").each(function(){

				sections[this.id] = $(this).offset().top;

				console.log(sections[this.id]);

			})

			$(document).scroll(function(){

				var pos = $this.scrollTop();

				//console.log(pos);

				for ( i in sections ) {

					if ( sections[i] > pos && sections[i] < pos + winHeight ) {

						//$navItem

					} 
				
				} 


			})


		});


		// ----------------------------------------------------------
		// This pic is stellar
		// ----------------------------------------------------------
		$(function(){

			$.stellar();

		});

	
		// ----------------------------------------------------------
		// Flexslider init
		// ----------------------------------------------------------
    $flexslider.flexslider({ 

  		directionNav: false 

    });


    // ----------------------------------------------------------
		// Scroller magic
		// ----------------------------------------------------------
  //   $(function setScroller() {

		// 	var $flexslider_pos = $flexslider.position().top;

		// 	var $scroller_pos = $flexslider.position().top;

		// 	console.log(top);

			
		// 	if( browserW > 767) {

		// 		changeColorIdentity();

		// 	}
		// });

		// function changeColorIdentity() {
			
		// 	$nav.css("color", "white");

		// }




		// ----------------------------------------------------------
		// Google Map
		// ----------------------------------------------------------
		$(function initialize() {

				// Lat long of store
				var Latlng = new google.maps.LatLng(39.774764,-105.044083);

				// Google map styles array
				var styles = [
				  {
				    "stylers": [
				      { "saturation": -100 },
				      { "gamma": 0.69 },
				      { "weight": 0.9 },
				      { "visibility": "on" }
				    ]
				  }
				];

			  // Create a new StyledMapType object, passing it the array of styles,
			  // as well as the name to be displayed on the map type control.
			  var styledMap = new google.maps.StyledMapType(styles);

			  // Create a map object, and include the MapTypeId to add
			  // to the map type control.
			  var mapOptions = {

			    zoom: 15,
			    center: Latlng,
			    scrollwheel: false,
			    mapTypeControl: false,
			    mapTypeId: google.maps.MapTypeId.ROADMAP

			  };

			  var map = new google.maps.Map(document.getElementById('map_canvas'),mapOptions);

			  // Map marker
			  var marker = new google.maps.Marker({
			      position: Latlng,
			      map: map
			      //animation: google.maps.Animation.DROP
			      //title:"Berkeley Supply"
			  });

			  //Associate the styled map with the MapTypeId and set it to display.
			  map.mapTypes.set('map_style', styledMap);
			  map.setMapTypeId('map_style');

     });





	});


}( jQuery, window, document));

