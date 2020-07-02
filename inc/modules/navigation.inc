<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
	http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 13.01.2002
*/

global $id;
global $flavour;

function display_items (&$parents, $level = 0) {
	global $document;
	global $id;
	global $design;
	list($key, $value) = each($parents);
	for($i = 0; $i < $level; $i++) {
		$pre .= '&nbsp;&nbsp;';
		}
	if($level > 0) $pre .= '<img src="'.$design['nav_bullet'].'" border="0" />';
	$related = get_children(0, 100, -1, true, 'DESC', true, $key);
	while(list($docid, $doc) = each($related)) {
		if(isset($parents[$docid])) {
			echo $pre.'<a href="'.get_url($docid).'" class="selectedNav">'.$doc['title']."</a><br />\n";
			display_items($parents, $level + 1);
			}
		else { 
			echo $pre.'<a href="'.get_url($docid).'" class="normalNav">'.$doc['title']."</a><br />\n";
			}
		}
	}

$filename = 'cache/modules/nav_'.$id.'_'.$flavour.'_'.$design['name'];
 
if(time() - filemtime($filename) < CACHE_TIME && CACHE_TIME != 0 && SESSION_STATUS != 'ok') {
        readfile($filename);
        }
else {
	ob_start();
	
	init_parents();

	$parents = $GLOBALS['parents'];
	$parents[0] = true;
	$parents = array_reverse($parents, true);
	$parents[$id] = true;

	display_items($parents);

	$content = ob_get_contents();
        ob_end_clean();
        if($cache_time != 0 && SESSION_STATUS != 'ok') {
                $fp = fopen ($filename, "w");
                fwrite($fp,$content);
                fclose($fp);
                }
        echo $content;
	}
?> 
