<html>
<head>
<meta http-equiv="refresh" content="1">
</head>
<body>
<b>Michal Butkiewicz<br/>
Artur Ludwinowicz<br/>
Bartosz Soczynski</b>
<br/><br/>
<?php
	$temperature_sensor_data = -1;
	$magnetic_sensor_data = -1;
	$distance_sensor_data = -1;

	function table_display() {
		global $temperature_sensor_data;
		global $magnetic_sensor_data;
		global $distance_sensor_data;		

		echo "<center><table border=1 width=25%><tr><td>&nbsp; Temperature [&deg;C]</td><td width=30%>"; 
	        echo "&nbsp; &nbsp;";
		if ($temperature_sensor_data != -1)
	            echo "$temperature_sensor_data";
		else
		    echo "-";
		echo "</td></tr><tr><td>&nbsp; Magnetic sensor state [0/1]</td><td>"; 
		echo "&nbsp; &nbsp;"	;
		if ($magnetic_sensor_data != -1)
		    echo $magnetic_sensor_data;
		else
		    echo "-";
		echo "</td></tr><tr><td>&nbsp; Distance [cm]</td><td>";
		echo "&nbsp; &nbsp;";
		if ($distance_sensor_data != -1)
          	    echo $distance_sensor_data;
		else
		    echo "-";
		echo "</td></tr></table></center>";
	}
	
	function text_file_validate() {
		global $temperature_sensor_data;
		global $magnetic_sensor_data;
		global $distance_sensor_data;		

		$text_file = fopen("sensors_data.txt",'r');
		$validator_1 = fgets($text_file);
	        $data_1 = fgets($text_file);
		$validator_2 = fgets($text_file);
		$data_2 = fgets($text_file);
		$validator_3 = fgets($text_file);
		$data_3 = fgets($text_file);
		fclose($text_file);	
		if (($validator_1[0] == "T") && ($validator_2[0] == "M") && ($validator_3[0] == "D")) {
			$temperature_sensor_data = $data_1;
			$magnetic_sensor_data = $data_2;
			$distance_sensor_data = $data_3;
		} else {
			$temperature_sensor_data = -1;
			$magnetic_sensor_data = -1;
			$distance_sensor_data = -1;
		}
	}

	if (file_exists("sensors_data.txt") == true) {	
		text_file_validate();	
		table_display();
	}
?>
</body>
</html>