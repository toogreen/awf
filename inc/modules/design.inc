<?php
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 17.12.2001
*/

global $design;
global $self;

$handle=opendir(INC_PATH.DESIGN_PATH); 
while (false!==($file = readdir($handle))) { 
    if ($file != "." && $file != ".." && '.inc' == substr($file, -4)) { 
	$tok = strtok ($file,".");
	if($tok == $design['name']) echo '<b>';
	echo '<a href="'.$self."docinput[design]=$tok".'">'.$tok.'</a><br />'; 
	if($tok == $design['name']) echo '</b>';
    } 
}
closedir($handle);
?>
