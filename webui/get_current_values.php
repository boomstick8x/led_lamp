<?php
include_once 'get_db_str.php';
function GetCurrentExecuteValues() {
  $execute_string_query = pullDatabaseString('lamp', 'execute_command', 'execute_string', 0);
  $execute_string_array = array (strtok($execute_string_query, ","));
    for ($i=1; $i < 7; $i++)
      $execute_string_array [$i] = strtok(",");
    //print_r($execute_string_array);
    return $execute_string_array;
}
?>
