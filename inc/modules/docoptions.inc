<?
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 06.01.2002
*/

global $PHP_SELF;
global $document;
global $id;
global $first_item;
global $save;
global $db_table_prefix;
global $doc;

if($profile['editor']) {
	if($save == 'docoptions') {
		echo is_integer($doc['membersonly']);
		if($doc['membersonly'] != 1) $doc['membersonly'] = 0;
		if($doc['sslonly'] != 1) $doc['sslonly'] = 0;
		if($doc['doconly'] != 1) $doc['doconly'] = 0;
		if($doc['hideleft'] != 1) $doc['hideleft'] = 0;
		if($doc['hideright'] != 1) $doc['hideright'] = 0;
		if($doc['releasedate'] < 0) {
			if(!($doc['releasedate'] = strtotime($doc['release_date_string']))) $doc['releasedate'] = 0;
			}
		if($doc['expirationdate'] < 0) {
			if(!($doc['expirationdate'] = strtotime($doc['expiration_date_string']))) $doc['expirationdate'] = 0;
			}
		sql_query("UPDATE ".TABLE_NODES." SET members_only = ".$doc['membersonly']." WHERE id = $id");
		sql_query("UPDATE ".TABLE_NODES." SET release_date = ".$doc['releasedate']." WHERE id = $id");
		sql_query("UPDATE ".TABLE_NODES." SET expiration_date = ".$doc['expirationdate']." WHERE id = $id");
		sql_query("UPDATE ".TABLE_NODES." SET ssl_only     = ".$doc['sslonly']."     WHERE id = $id");
		add_nodedata ($id, 'refresh', $doc['refresh'], 0, 'notrans');
		add_nodedata ($id, 'show_doc_only', $doc['doconly'], 0, 'notrans');
		add_nodedata ($id, 'hide_left_col', $doc['hideleft'], 0, 'notrans');
		add_nodedata ($id, 'hide_right_col', $doc['hideright'], 0, 'notrans');
		$document['members_only'] = $doc['membersonly'];
		$document['release_date'] = $doc['releasedate'];
		$document['expiration_date'] = $doc['expirationdate'];
		$document['refresh']      = $doc['refresh'];
		$document['ssl_only']     = $doc['sslonly'];
		$document['show_doc_only']= $doc['doconly'];
		$document['hide_left_col']= $doc['hideleft'];
		$document['hide_right_col']= $doc['hideright'];
		}
	?>	
                <form action="<?=$PHP_SELF?>" method="post">
                <input type="checkbox" value="1" name="doc[membersonly]"<? if($document['members_only']) echo 'CHECKED'; ?> />&nbsp;Members only<br />
                <input type="checkbox" value="1" name="doc[doconly]"<? if($document['show_doc_only']) echo 'CHECKED'; ?> />&nbsp;Show document only<br />
                <input type="checkbox" value="1" name="doc[hideleft]"<? if($document['hide_left_col']) echo 'CHECKED'; ?> />&nbsp;Hide left column<br />
                <input type="checkbox" value="1" name="doc[hideright]"<? if($document['hide_right_col']) echo 'CHECKED'; ?> />&nbsp;Hide right column<br />
                <input type="checkbox" value="1" name="doc[sslonly]"<? if($document['ssl_only']) echo 'CHECKED'; ?> />&nbsp;SSL only<br /><br />
		Release Date<br />
		<input name="doc[releasedate]" value="0" type="radio"<? if($document['release_date'] == 0) echo ' CHECKED'; ?> /> Now<br />
		<input name="doc[releasedate]" value="-1" type="radio"<? if($document['release_date'] != 0) echo 'CHECKED'; ?> />
		<input type="text" name="doc[release_date_string]" size="15" value="<?=date('j M Y H:i',$document['release_date'])?>" /><br />
		<br />
		Expiration Date<br />
		<input name="doc[expirationdate]" value="0" type="radio"<? if($document['expiration_date'] == 0) echo ' CHECKED'; ?> /> Never<br />
		<input name="doc[expirationdate]" value="-1" type="radio"<? if($document['expiration_date'] != 0) echo 'CHECKED'; ?> />
		<input type="text" name="doc[expiration_date_string]" size="15" value="<?=date('j M Y H:i',$document['expiration_date'])?>" /><br />
		<br />
		Auto Refresh<br />
		<select name="doc[refresh]">
		<option value="0"<?if($document['refresh'] == '0') echo ' selected'; ?>>Disable</option>
		<option value="1"<?if($document['refresh'] == '1') echo ' selected'; ?>>1 sec</option>
		<option value="5"<?if($document['refresh'] == '5') echo ' selected'; ?>>5 sec</option>
		<option value="15"<?if($document['refresh'] == '15') echo ' selected'; ?>>15 sec</option>
		<option value="30"<?if($document['refresh'] == '30') echo ' selected'; ?>>30 sec</option>
		<option value="60"<?if($document['refresh'] == '60') echo ' selected'; ?>>1 min</option>
		<option value="120"<?if($document['refresh'] == '120') echo ' selected'; ?>>2 min</option>
		<option value="300"<?if($document['refresh'] == '300') echo ' selected'; ?>>5 min</option>
		<option value="600"<?if($document['refresh'] == '600') echo ' selected'; ?>>10 min</option>
		</select>
                <input type="hidden" name="first_item" value="<?=$first_item?>" />
		<input type="hidden" name="save" value="docoptions" />
		<input type="hidden" name="id" value="<?=$id?>" />
                <br /><br /><input type="submit" value="Apply" />
                </form>
		<?
		
	}

