<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 11.01.2002
*/

if(CACHING == 'on') {
	if($document['cacheable'] == 1) {
		caching(ob_get_contents());
        	}
	ob_end_flush();
	}

while(list($key, $value) = each($cache_refresh)) {
 	if($value == true) clear_cache($key);
	}

write_log();

?>
