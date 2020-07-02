<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 22.12.2001
*/

global $image_path;

?>

<?=$title?><br />
<select name="docdata[<?=$value?>]"><option value="">No Icon</option>
<?
$handle=opendir($image_path.'news/');
while (false!==($file = readdir($handle))) {
	if ($file != "." && $file != "..") {
		$icons[] = $file;
        	}
	}

natcasesort($icons);

while(list($key, $file) = each($icons)) {
	if($file == $document[icon]) { $sel = ' SELECTED'; } else { $sel = ''; }
	echo '<option value="'.$file.'"'.$sel.'>'.substr($file, 0, -4).'</option>';
	}

?>
</select>
<input type="hidden" name="docdatatype[<?=$value?>]" value="notrans" />
