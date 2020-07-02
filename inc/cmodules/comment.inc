<?php
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 28.11.2001
*/

if($profile['editor']!='1') { 
	
	if(isset($add_comment) && $add_comment == 'true') {
	
	?>
	<table width="100%" border="0" cellpadding="5" cellspacing="0"><tr><td align="left" bgcolor="<?=$design['table_row_bright']?>">
	<? printf(LANG_COMMENT_INTRO, transform($document['title'], $document['datatype']['title'])); ?>
	<br> 
	<?=LANG_HTML_CONVERTED?><br><br>
	<form action="<?php echo $PHP_SELF; ?>" method="post">
	<input type="hidden" name="id" value="<?php echo $id; ?>">
	<input type="hidden" name="docinput[save_comment]" value="true">
	<?php if(isset($comment_item)) { ?>
	<input type="hidden" name="comment_item" value="<?php echo $comment_item; ?>">
	<?php } ?>
	<?=LANG_TITLE?><br>
	<input type="text" name="docinput[title]" value="" size="60">
	<br><br>
	<?=LANG_COMMENT?><br>
	<textarea name="docinput[body]" cols="60" rows="20"></textarea>
	<br><br>
	<input type="submit" value="<?=LANG_PUBLISH?>">
	</form>
	</td></tr></table><br>
	<?php
	echo '[ <a href="'.get_url($id).'">'.LANG_BACK.'</a> ]</p>';
	
	} else {
	
	reset($parents);
	list($pid,$pdoc) = each($parents);

	echo '<table width="100%" border="0" cellpadding="5" cellspacing="0"><tr><td align="left" bgcolor="'.$design['table_row_bright'].'">';
	echo '<p>';
	printf(LANG_COMMENT_ABOUT, $pdoc['title'], transform($document['author_id'], 'user_id'), transform($document[timestamp], 'date'));
	echo '</p>';
	echo '<h2>'.transform($document['title'],$document['datatype']['title']).'</h2>';
	echo '<p>'.transform($document['body'],$document['datatype']['body']).'<br><br></td></tr></table><br>';
	echo '[ <a href="'.get_url($document['parent_id']).'">'.LANG_BACK.'</a> ]</p>';
	}

} elseif($profile['editor'] == '1') {
	create_editor_input('Comment', 'body', 'area_input');
	}

?>
