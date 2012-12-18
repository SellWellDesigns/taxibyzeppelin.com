;(function( $, window, document, undefined ){
    
	// Init vars
	var $window   = $(window),
			$document = $(document);

	// TAXI
	var taxi = {

		init: function(){

			var self = this;

			self.$nav         = $("#nav a");
			self.$bgPhoto     = $("div.slide");
			self.currentSlide = 0;
			self.totalSlides  = self.$bgPhoto.length;

			// Attach click handlers
			self.$nav.on("click", self.scrollTo);

			self.bgSlideshow();

		},

		bgSlideshow: function(){

			var self = this;

			self.$bgPhoto
				.eq(self.currentSlide)
				.addClass("current")
				.css("display", "block");

			// Set interval for slideshow
			setInterval(function(){

				$("div.current")
					.removeClass("current")
					.fadeOut(2000, 'easeInOutQuad');

				if ( currentSlide === totalSlides  - 1 ) currentSlide = 0;

			 	else currentSlide++;

				self.$bgPhoto
					.eq(currentSlide)
					.addClass("current")
					.fadeIn(2000, 'easeInOutQuad');

			}, 4000);


		},

		googleMap: function(){},

		scrollTo: function(event){

			var self = taxi;

			// Init
			var $link = $(this);

			// Scroll to href of clicked link
			$("html, body").stop().animate({

        scrollTop: $($link.attr("href")).offset().top + 30

      }, 1500,'easeInOutExpo');

			event.preventDefault();

		},

		setActiveSection: function(){}
		
	}


	$window.load(function(){

		taxi.init();

	});



	$(document).ready(function(){	




		// ----------------------------------------------------------
		// Where am i? 
		// ----------------------------------------------------------
		(function(){

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
		// Put on a slideshow for me monkey, slide!!!
		// ----------------------------------------------------------
		$bgPhoto.eq(currentSlide).addClass("current").css("display", "block");

		function bgSlideshow() {

			// Set interval for slideshow
			looper = setInterval(function(){

				$("div.current").removeClass("current").fadeOut(2000, 'easeInOutQuad');

				if ( currentSlide == totalSlides  - 1 ) currentSlide = 0;

			 	else currentSlide++;

				$bgPhoto.eq(currentSlide).addClass("current").fadeIn(2000, 'easeInOutQuad');

			}, 4000);

		}




		// ----------------------------------------------------------
		// Google Map
		// ----------------------------------------------------------
		(function initialize() {

				// Lat long of store
				var Latlng = new google.maps.LatLng(39.772213,-104.982498);

				// Google map styles array
				var styles = [
				  {
				    "stylers": [
				      { "saturation": -50 },
				      { "gamma": 0 },
				      { "weight": 0.3 },
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

