<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 20.12.2001
*/
?>
	<br /><br /><center>
	<input type="hidden" name="docinput[save_doc_properties]" value="true">
        <input type="hidden" name="id" value="<? echo $id; ?>">
        <input type="hidden" name="first_item" value="<? echo $first_item; ?>">
        <input type="hidden" name="back_dest" value="<? echo $document['parent_id']; ?>">

	<input type="submit" name="docinput[submit]" value="Back" title="Back to parent document." />&nbsp;&nbsp;
	<input type="submit" name="docinput[submit]" value="Reload" title="Reload this document. Useful to undo changes." />&nbsp;&nbsp;	
	<input type="submit" name="docinput[submit]" value="Save" title="Make your changes to this document permanent." />
	</center>
	</td></tr>
	</table> 
	</form>

<!-- AWF editor panel END -->



