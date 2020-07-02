<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 05.01.2002
*/


if($value['title'] != '') {
	if($profile['editor'] == '1') {
		global $docid;
		echo '<h2 clear="all"><a href="'.get_url($docid).'">'.transform($value['title'], $value['datatype']['title']).'</a></h2>';
		}
	else {
		echo '<h2 clear="all"><a name="'.$docid.'">'.transform($value['title'], $value['datatype']['title']).'</a></h2>';
		}
        }

if($value['image'] != '' || $value['body'] != '') {
	echo '<p class="justify">';
        // Image
        echo transform($value['image'], $value['datatype']['image']);
        // Text
        echo transform($value['body'], $value['datatype']['body']).'</p><br clear="all" />';
        }
?>

