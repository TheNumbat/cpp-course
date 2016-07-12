
var buttons = document.getElementsByClassName('button');
var shown = [];

for(var i = 0; i < buttons.length; i++) {
	buttons[i].onclick = function() {
	    var div = document.getElementById('a' + this.id);
    	if(!shown[this.id]) {
            div.style.display = 'block';
            shown[this.id] = true;
    	}
    	else {
            div.style.display = 'none';
            shown[this.id] = false;
    	}
	};
}
