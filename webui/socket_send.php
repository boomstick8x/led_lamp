<?php
function SocketSend($ip, $port, $sendString) {
  $fp = fsockopen($ip, $port, $errno, $errstr, 1);
    if (!$fp) {
      echo "ERROR: $errno - $errstr<br />\n";
    }
    else {
      fwrite($fp, $sendString);
      while (!feof($fp)) {
        echo fgets($fp, 4096);
      }
      fclose($fp);
    }
  }
  ?>
