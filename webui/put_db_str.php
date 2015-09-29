<?php

function Put_Db_Str($database_name, $table_name, $column, $row, $send_string){
    require 'mysql_login.php';
    $db_server = mysql_connect($host, $username, $password);
    if (!$db_server) die("Unable to connect to MySQL: " . mysql_error());
    mysql_select_db($database_name)
    or die("Unable to select database: " . mysql_error());
    $query = "UPDATE $table_name SET $column='$send_string' WHERE id='$row'";
    //$query = "INSERT INTO $table_name VALUES($row, '$send_string')";
    $result = mysql_query($query);
    if (!$result) die ("Database access failed: " . mysql_error());

}

?>