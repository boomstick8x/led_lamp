<html>
<head>
<title></title>
</head>
<body>
<?php
//require 'put_db_str.php';//Put_Db_String($database_name, $table_name, $string_name, $row, $send_string)
//require 'get_db_str.php';
require 'socket_snd.php';


if ($_SERVER['REQUEST_METHOD']=="POST")
{
    if ($_POST['submit_command']=="Execute")
    {
    $execute_command_str_arr = array(
            $_POST["RGB"],
            $_POST["stay_time"],
            $_POST["change_time"],
            $_POST["enable_random"]);
    $send_str = join(',' , $execute_command_str_arr);


 //   Put_Db_Str('lamp', 'execute_command', 'execute_string', '0', $send_str);



   /* $inc=Get_Db_Str('lamp', 'swatches', 'inc', 0);
    if ($inc>7){
        $inc=0;
        Put_Db_Str('lamp', 'swatches', 'inc', 0, $inc);
        Put_Db_Str('lamp', 'swatches', 'rgb', $inc, $execute_command_str_arr[0]);
    }
    else  {
        $inc++;
        Put_Db_Str('lamp', 'swatches', 'inc', 0, $inc);
        Put_Db_Str('lamp', 'swatches', 'rgb', $inc, $execute_command_str_arr[0]);
    }
*/
    Socket_Snd('192.168.0.199', 8888, $send_str);
    }
}
?>
</body>
</html>


