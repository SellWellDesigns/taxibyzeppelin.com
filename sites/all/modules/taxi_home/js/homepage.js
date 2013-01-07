;(function( $, window, document, undefined ){
    
	// Init vars
	var $window   = $(window),
			$document = $(document),
			$loader   = $("div#loader");
			$html     = $("html");

	// TAXI
	var taxi = {

		init: function(){

			var self = this;

			self.$nav         = $("#nav a");
			self.$logo				= $("#logo a");
			self.$bgPhoto     = $("div.slide");
			self.currentSlide = 0;
			self.totalSlides  = self.$bgPhoto.length;

			// Attach click handlers
			self.$nav.on("click", self.scrollTo);
			self.$logo.on("click", self.scrollTop);

			self.bgSlideshow();
			self.setActiveSection();
			self.accordion();

		},

		//
		// Playin' polka with code
		//
		accordion: function(){

			// Define variables
			var $accordion  = $('div.accordionButton');

			// Accordion butotn action-jackson
			$accordion.click(function(event){

				var $this = $(this);
				var $siblings = $this.parent().siblings().find('div.accordionButton');
			

				$siblings.removeClass('.active');
				$siblings.next().slideUp('normal');
				$siblings.find('.plus-minus h5').text('+');

			
				if ( !$this.hasClass('.active') ) {

					$this.addClass('.active');
					$this.next().slideDown('normal');
					$this.find('.plus-minus h5').text('-');

				

				} else {

					$this.removeClass('.active');
					$this.next().slideUp('normal');
					$this.find('.plus-minus h5').text('+');

				}

			});


			// Hide all divs on page load
			$("div.companies-list").hide();	

    		

		},


		//
		// Change up dat background already!
		//
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
					.fadeOut(1000, 'easeInOutQuad');

				if ( self.currentSlide === self.totalSlides  - 1 ) self.currentSlide = 0;

			 	else self.currentSlide++;

				self.$bgPhoto
					.eq(self.currentSlide)
					.addClass("current")
					.fadeIn(1000, 'easeInOutQuad');

			}, 7000);

		},


		//
		// We are talking about a real live map here
		//
		googleMap: function(){

			var self = this;

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
			      //title:"TAXI"
			  });

			  //Associate the styled map with the MapTypeId and set it to display.
			  map.mapTypes.set('map_style', styledMap);
			  map.setMapTypeId('map_style');

		},


		//
		// Ohhhhhh baby that is some smooth scrolling
		//
		scrollTo: function(event){

			var self = taxi;

			// Init
			var $link = $(this);

			// Scroll to href of clicked link
			$("html, body").stop().animate({

        scrollTop: $($link.attr("href")).offset().top + 300

      }, 1500,'easeInOutExpo');

			event.preventDefault();

		},

			//
		// Ohhhhhh baby that is some smooth scrolling
		//
		scrollTop: function(event){

			var self = taxi;

			// Init
			var $link = $(this);

			// Scroll to href of clicked link
			$("html, body").stop().animate({

        scrollTop: $($link.attr("href")).offset().top

      }, 1500,'easeInOutExpo');

			event.preventDefault();

		},


		//
		// Just tell me where i am dammit!
		//
		setActiveSection: function(){

			var sections  = {},
					$this     = $(this);
					winHeight = $window.height(),
					$nav      = $("#nav"),
					$navItem  = $("#nav li a"),
					i 		  = 0;

			// Grab the position of all our sections
			$(".section").each(function(){

				sections[this.id] = $(this).offset().top;

			})
			
			$(window).scroll(function(){

				var pos = $(this).scrollTop();

				for ( i in sections ) {

					if ( sections[i] > pos - 500 && sections[i] < pos + winHeight - 700 ) {

						var $active = $('#nav a.active');

						// Remove other active class if necessary
						if ( !$active.hasClass(i) ){
						  
						  $active.removeClass('active');

						} 

						// Add new active class
						if ( i !== 'start-section' ) {
						  
						  $( '#nav a.' + i ).addClass('active');
						  
					  }

					} 
				
				} 

			})

		}
		
	}


	//
	// All ready.. lets do this dance
	//
	$window
		.load(function(){

			setTimeout(function() {

				$html.css("overflow","auto");
				$loader.fadeOut();

			}, 2000)

			taxi.init();

		})


}( jQuery, window, document));

