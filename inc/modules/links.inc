<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 27.11.2001
*/

$filename = INC_PATH.DATA_PATH.'links.txt';
$lines = file($filename);
while (list ($line_num, $line) = each ($lines)) {
  $buffer = split('\|', $line);
  echo('<a href="'.$buffer[1].'">'.$buffer[0].'</a><br>');
}

?>
