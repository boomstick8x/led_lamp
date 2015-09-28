<?php
function Socket_Snd($ip, $port, $send_str)
{
    $fp = fsockopen($ip, $port, $errno, $errstr);
        if (!$fp)
            {
            echo "ERROR: $errno - $errstr<br />\n";
            }
        else
        {
            fwrite($fp, $send_str);
            while (!feof( $fp ))
            {
                $ret .= fgets($fp, 4096);
            }
        echo $ret;
        fclose($fp);
        }
    }
?>