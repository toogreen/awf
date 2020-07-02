<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 06.12.2001
*/

global $profile;
global $PHP_SELF;
global $id;
global $mod_textarea;

$filename = INC_PATH.DATA_PATH.'vars/module_textarea_'.$module['id'].'.inc';

if($profile['editor'] == 1) { 
	if(isset($mod_textarea[$module['id']])) {
		$fd = fopen ($filename, "w");
		fwrite ($fd, stripslashes($mod_textarea[$module['id']]));
		fclose ($fd);
		}
?><center>
<form action="<?=$PHP_SELF?>" method="post">
<input type="hidden" name="id" value="<?=$id?>" />
<input type="hidden" name="first_item" value="<?=$first_item?>" />
<textarea name="mod_textarea[<?=$module['id']?>]" cols="15" rows="10"><? if(file_exists($filename)) include($filename); ?></textarea>
<input type="submit" value="Save" />
</form></center>
<?
} else {

if(file_exists($filename)) include($filename);

}

?>

