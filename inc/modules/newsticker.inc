
<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 09.01.2002
*/

global $profile;
global $PHP_SELF;
global $design;

if($profile['editor'] == 1) { 
	if(isset($GLOBALS['module_news_source_'.$module['id']])) {
		save_var('rdf_source_'.$module['id'], $GLOBALS['module_news_source_'.$module['id']]);
		}
	$source = load_var('rdf_source_'.$module['id']);
	if($source == '') $source = 'heise.rdf';
	?>
	<center>
	<form action="<?=$PHP_SELF?>" method="post">
	<input type="hidden" name="id" value="<?=$GLOBALS['id']?>">
	<input type="hidden" name="first_item" value="<?=$GLOBALS['first_item']?>">
	<input type="hidden" name="subject" value="<?=$GLOBALS['subject']?>">
	<input type="hidden" name="search" value="<?=$GLOBALS['search']?>">
	<select name="module_news_source_<?=$module['id']?>">
	<?
	echo INC_PATH.DATA_PATH.'rdf';
	$handle=opendir(INC_PATH.DATA_PATH.'rdf');
	while (false!==($file = readdir($handle))) {
	    if ($file != "." && $file != "..") {
		$files[] = $file;
	    }	
	}
	closedir($handle); 
	
	natcasesort($files);
	while(list($key, $file) = each($files)) {
	        if($file == $source) { $sel = ' SELECTED'; } else { $sel = ''; }
		echo '<option value="'.$file.'"'.$sel.'>'.$file.'</option>';
        }
	
	?>
	</select><br />
	<input type="submit" value="<?=LANG_SAVE?>" />
	</form>
	</center>
	<?
	}
else {

$filename = 'cache/modules/rdf_cache_'.$module['id'].'_'.$design['name'];
$cache_time = 900;

if(time() - filemtime($filename) < $cache_time && $cache_time != 0) {
	readfile($filename);
	}
else {
	ob_start();

	include_once(BASE_PATH.INC_PATH."rdf.inc");
	$source = load_var('rdf_source_'.$module['id']);
	if($source == '') $source = 'heise.rdf';
	$item = new rdfFile(BASE_PATH.INC_PATH.DATA_PATH."rdf/$source");
	$item->parse(true);
	?><span style="font-size: 10px"><?
	while(list($key, $value) = each ($item->Items)) {
		?><img src="<?=$design['nav_bullet']?>" border="0" width="10" height="7">&nbsp;<a href="<?
		echo $value['Link'].'">'.$value['Title'].'</a><br />';
		}

	?>
	</span>
	<? 
	$content = ob_get_contents();
	ob_end_clean();
	if($cache_time != 0) {
	        $fp = fopen ($filename, "w");
        	fwrite($fp,$content);
	        fclose($fp);
		}
	echo $content;
	}
} ?>
