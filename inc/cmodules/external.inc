<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 22.12.2001
*/

if($profile['editor']=='1') {
	echo '<p>';
	create_editor_input('External document filename', 'external', 'text_input');
	echo '</p>';
	}
else {
        echo("<b>Sorry, this page should redirect you to other content....</b>");
        }
?>
