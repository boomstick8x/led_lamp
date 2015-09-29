<!DOCTYPE html>
<html>

<head>
  <link rel="stylesheet" href="css/style.css" type="text/css">
  <title>test</title>
  <script type="text/javascript">
    function restoreSliderOpacity() {
      var redSliderValue = "rgba(233, 81, 58," + document.getElementById('redSlider').value * 3.9 / 1000 + ")";
      var greenSliderValue = "rgba(47, 202, 108," + document.getElementById('greenSlider').value * 3.9 / 1000 + ")";
      var blueSliderValue = "rgba(70, 70, 255," + document.getElementById('blueSlider').value* 3.9 / 1000 + ")";
      document.getElementById('redSlider').style.backgroundColor = redSliderValue;
      document.getElementById('greenSlider').style.backgroundColor = greenSliderValue;
      document.getElementById('blueSlider').style.backgroundColor = blueSliderValue;
    }

    function sliderColorChange(slider, value) {
      if (slider == 'redSlider')
        var currentSlider = "rgba(233, 81, 58,";
      if (slider == 'greenSlider')
        var currentSlider = "rgba(47, 202, 108,";
      if (slider == 'blueSlider')
        var currentSlider = "rgba(70, 70, 255,";
      document.getElementById(slider).style.backgroundColor = currentSlider + (value * 3.9 / 1000) + ")";
    }

    function createAJAXRequest() {
      try {
        var ajaxRequest = new XMLHttpRequest();
      } catch (e1) {
        try {
          ajaxRequest = new ActiveXObject("Msxml2.XMLHTTP");
        } catch (e2) {
          try {
            ajaxRequest = new ActiveXObject("Microsoft.XMLHTTP");
          } catch (e3) {
            ajaxRequest = false;
          }
        }
      }
      return ajaxRequest;
    }

    function sendCommand(data) {
      var ajaxRequest = createAJAXRequest();
      ajaxRequest.open("POST", "execute_command.php", true);
      ajaxRequest.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
      ajaxRequest.onreadystatechange = function() {
        if (this.readyState == 4) {
          if (this.status == 200) {
            if (this.responseText != null) {
              //alert(data);
            } else alert("Ajax error: No data received");
          } else alert("Ajax error: " + this.statusText);
        }
      }
      ajaxRequest.send(data);
    }

    function executeCommand() {
      var RGB = document.getElementById('redSlider').value + "," +
      document.getElementById('greenSlider').value + "," +
      document.getElementById('blueSlider').value;
      var lampState =
      "&stay_time=" + document.getElementById('stayTime').value +
      "&change_time=" + document.getElementById('changeTime').value +
      "&enable_random=" + document.getElementById('enableRandomCheckbox').checked +
      "&powerOn=" + document.getElementById('ioCheckbox').checked;
      var data = "submit_command=Execute&RGB=" + RGB + lampState;
      sendCommand(data);
    }

      //"submit_command=Execute&RGB=255,0,0&stay_time=1&change_time=1&enable_random=0"



  </script>
</head>

<?php
error_reporting(E_ALL);
ini_set("display_errors", 1);

require_once 'execute_command.php';//Get_Database_String($database_name, $table_name, $string_name, $row)

function Get_Execute_String() {
  $execute_string_query = Get_Db_Str('lamp', 'execute_command', 'execute_string', 0);
  $execute_string_array = array (strtok($execute_string_query, ","));
    for ($i=1; $i < 7; $i++)
      $execute_string_array [$i] = strtok(",");
    print_r($execute_string_array);
    return $execute_string_array;
}

$currentValues = Get_Execute_String();
$redValue = $currentValues[0];
$greenValue = $currentValues[1];
$blueValue = $currentValues[2];
$stayTimeValue = $currentValues[3];
$changeTimeValue = $currentValues[4];
$enableRandomValue = $currentValues[5];
$powerOn = $currentValues[6];
?>









<body onload="restoreSliderOpacity();">
  <form action="command.php" method="post">
    <div id="wrapper">
      <div id="rgb_part" class="horizontal_middle">
        Red
        <input type="range" id="redSlider" min="1" max="255" value=<?php echo $redValue; ?> step="1" oninput="sliderColorChange('redSlider', this.value);" onchange="executeCommand()"/> Green
        <input type="range" id="greenSlider" min="1" max="255" value=<?php echo $greenValue; ?> step="1" oninput="sliderColorChange('greenSlider', this.value);" onchange="executeCommand()"/> Blue
        <input type="range" id="blueSlider" min="1" max="255" step="1" value=<?php echo $blueValue; ?> oninput="sliderColorChange('blueSlider', this.value);" onchange="executeCommand()"/>
      </div>
      <div id="func_wrapper" class="horizontal_middle">
        <div id="func_part1" class="">
          change_time
          <input type="range" id="changeTime" min="1" max="10" step="1" value=<?php echo $changeTimeValue; ?> class="func_sliders" onchange="executeCommand()" /> stay_time
          <input type="range" id="stayTime" min="1" max="10" step="1" value=<?php echo $stayTimeValue; ?> class="func_sliders" onchange="executeCommand()" />
        </div>
        <div id="func_part2" class="">
          Enable random
          <div class="flatCheckbox">
            <input type="checkbox" id="enableRandomCheckbox" <?php echo $enableRandomValue == "true" ? "checked" : ""; ?> name="enableRandomCheckbox" onchange="executeCommand()"/>
            <label for="enableRandomCheckbox"></label>
            <div id="enableRandomBackground"></div>
          </div>
          Power
          <div class="flatCheckbox">
            <input type="checkbox" id="ioCheckbox" name="ioCheckbox" <?php echo $powerOn == "true" ? "checked" : ""; ?> onchange="executeCommand()"/>
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
