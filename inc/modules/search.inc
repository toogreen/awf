<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 06.01.2002
*/
 
$key = get_cmodule_id('search_form');

global $module;

?>

<center>
<form action="<?=$PHP_SELF?>">
<input type="hidden" name="id" value="<?=$key?>" />
<input type="text" size="11" name="search" />
<input type="submit" value="<?=LANG_SEARCH?>" />
</form>
</center>
