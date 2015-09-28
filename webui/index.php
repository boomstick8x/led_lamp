<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="css/style.css" type="text/css" >
    <title>LED CONTROL</title>
    <script type="text/javascript">
    function sliderColorChange(slider, value){
    	if (slider == 'redSlider')
    		var currentSlider = "rgba(233, 81, 58,";
    	if (slider == 'greenSlider')
    		var currentSlider = "rgba(47, 202, 108,";
		if (slider == 'blueSlider')
    		var currentSlider = "rgba(70, 70, 255,";    			
    	document.getElementById(slider).style.backgroundColor = currentSlider + (value*3.9/1000) + ")";
    }
	function createAJAXRequest(){
		try{
			var ajaxRequest = new XMLHttpRequest();
		}
		catch(e1){
			try{
				ajaxRequest = new ActiveXObject("Msxml2.XMLHTTP");
			}
			catch(e2){
				try{
					ajaxRequest = new ActiveXObject("Microsoft.XMLHTTP");
				}
				catch(e3){
					ajaxRequest = false;
				}
			}
		}
		return ajaxRequest;
	}

	function dataSend(data)
	{
		var ajaxRequest = createAJAXRequest();
			ajaxRequest.open("POST", "execute_command.php", true);
			ajaxRequest.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			ajaxRequest.onreadystatechange = function(){
 				if (this.readyState == 4)
 				{
 					if (this.status == 200)
 					{
 						if (this.responseText != null)
 						{
 							//alert(data);
 						}
 						else alert("Ajax error: No data received");
 					}
 				else alert( "Ajax error: " + this.statusText);
 				}
 			}
		ajaxRequest.send(data);
	}

	function executeCommand()
	{
		var RGB = document.getElementById('redSlider').value + "," + document.getElementById('greenSlider').value + "," + document.getElementById('blueSlider').value;
		var lampState = "&stay_time=" + document.getElementById('stayTime').value + "&change_time=" + document.getElementById('changeTime').value + "&enable_random=" + document.getElementById('enableRandomCheckbox').value;
		var data = "submit_command=Execute&RGB=" + RGB + lampState;
		dataSend(data);
		//"submit_command=Execute&RGB=255,0,0&stay_time=1&change_time=1&enable_random=0"
	}
	</script>
</head>

<body>
<form action="command.php" method="post">
<div id="wrapper">
	<div id="rgb_part" class="horizontal_middle">
		Red
		<input type="range" id="redSlider" min="1" max="255" value="1" step="1" oninput="sliderColorChange('redSlider', this.value);" onchange="executeCommand()"/>
		Green
		<input type="range" id="greenSlider" min="1" max="255"  value="1" step="1" oninput="sliderColorChange('greenSlider', this.value);"  onchange="executeCommand()"/>
		Blue
		<input type="range" id="blueSlider" min="1" max="255" step="1" value="1" oninput="sliderColorChange('blueSlider', this.value);" onchange="executeCommand()"/>
	</div>
	<div id="func_wrapper" class="horizontal_middle">
		<div id="func_part1" class="">
			change_time
			<input type="range" id="changeTime" min="1" max="10" step="1" value="1" class="func_sliders" onchange="executeCommand()"/>
			stay_time
			<input type="range" id="stayTime" min="1" max="10" step="1" value="1"  class="func_sliders" onchange="executeCommand()"/>
		</div>
		<div id="func_part2" class="">
			enable_random
			<div class="flatCheckbox">
				<input type="checkbox" id="enableRandomCheckbox" name="enableRandomCheckbox" value="1" onchange="executeCommand()"/>
        		<label for="enableRandomCheckbox"></label>
        		<div></div>
			</div>
			1/0
			<div class="flatCheckbox">
				<input type="checkbox" id="ioCheckbox" name="ioCheckbox" value="1" />
       			<label for="ioCheckbox"></label>
       			<div></div>
			</div>
			<input type="submit" name="submit_command" value="Save" />
		</div>
	</div>
</div>	
</form>
</body>
</html>



