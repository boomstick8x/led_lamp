<?php
function pullDatabaseString($database_name, $table_name, $string_name, $row) {
    include_once 'mysql_login.php';
    $db_server = mysql_connect($host, $username, $password);
    if (!$db_server) die("Unable to connect to MySQL: " . mysql_error());
    mysql_select_db($database_name)
    or die("Unable to select database: " . mysql_error());
    $query = "SELECT $string_name FROM $table_name";
    $result = mysql_query($query);
    if (!$result) die ("Database access failed: " . mysql_error());
    return $execute_string = mysql_result($result, $row, $string_name);
}
?>
