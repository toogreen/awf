<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 21.12.2001
*/

?>

<?=$title?><br />
<input type="radio" value="1" name="docdata[<?=$value?>]"<? if($document[$value] == '1') echo ' CHECKED'; ?> /> Enable&nbsp;&nbsp;
<input type="radio" value="0" name="docdata[<?=$value?>]"<? if($document[$value] == '0') echo ' CHECKED'; ?> /> Disable
