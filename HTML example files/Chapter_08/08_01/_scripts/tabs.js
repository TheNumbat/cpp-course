//tabbed panels

// declare globals to hold all the links and all the panel elements
var tabLinks;
var tabPanels;

window.onload=function() {
    
    // when the page loads, grab the li elements
    tabLinks = document.getElementById("tabs").getElementsByTagName("li");
	// Now get all the tab panel container divs
	tabPanels = document.getElementById("containers").getElementsByTagName("div");

    // activate the _first_ one
    displayPanel(tabLinks[0]);

    // attach event listener to links using onclick and onfocus, fire the displayPanel function, return false to disable the link
    for (var i = 0; i < tabLinks.length; i++) {
        tabLinks[i].onclick = function() { 
			displayPanel(this); 
			return false;
		}
        tabLinks[i].onfocus = function() { 
			displayPanel(this); 
			return false;
		}
    }
}

function displayPanel(tabToActivate) {
    // go through all the <li> elements
    for (var i = 0; i < tabLinks.length; i++) {
        if (tabLinks[i] == tabToActivate) {
			// if it's the one to activate, change its class
            tabLinks[i].classList.add("active");
			// and display the corresponding panel
			tabPanels[i].style.display = "block";
        } else {
			// remove the active class on the link
        	tabLinks[i].classList.remove("active");
			// hide the panel
			tabPanels[i].style.display = "none";
        }
	}
}