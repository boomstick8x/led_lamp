<?php
include_once 'push_db_str.php';
include_once 'socket_send.php';

error_reporting(E_ALL);
ini_set("display_errors", 1);

if ($_SERVER['REQUEST_METHOD']=="POST") {
    if ($_POST['submit_command']=="Execute") {
      $sendString =
      $_POST["RGB"] . "," .
      $_POST["stay_time"] . "," .
      $_POST["change_time"] . "," .
      $_POST["enable_random"];
      /* pushDatabaseString($database_name, $table_name, $string_name, $row, $send_string) */
      pushDatabaseString('lamp', 'execute_command', 'execute_string', '0', $sendString . "," . $_POST["powerOn"]);
      changeState($sendString, $_POST["powerOn"]);
    }
}

function changeState($sendString, $currentState) {
  if ($currentState == "true")
    SocketSend('192.168.0.199', 8888, $sendString);
  else
    SocketSend('192.168.0.199', 8888, "0,0,0,1,1,0");
}
?>
