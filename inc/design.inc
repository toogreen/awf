<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 13.01.2002
*/

// This is the main config file for all design issues

if (file_exists(INC_PATH.DESIGN_PATH.$design['name'].'.inc')) {
	$design_name = $design['name'];
	unset($design);
	include(INC_PATH.DESIGN_PATH.$design_name.'.inc');
	$design['name'] = $design_name;
	}
else {
	unset($design);
	include(INC_PATH.DESIGN_PATH.DEFAULT_DESIGN.'.inc');
	$design['name'] = DEFAULT_DESIGN;
	}
?>
