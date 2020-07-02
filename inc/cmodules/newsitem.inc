<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 06.01.2002
*/
 
if($profile['editor']!='1') {

if(isset($action) && $action="send_email") {
?>
        <form action="<?=$PHP_SELF?>" method="post">
        <input type="hidden" name="id" value="<?=$id?>">
        <input type="hidden" name="docinput[save]" value="send_email">
        <p>
        <b><?=LANG_SEND_THIS_DOCUMENT?></b><br />
        <input type="text" name="docinput[email]" size="50"><br />
        <?=LANG_MULTIPLE_RECIPIENTS?>
        <br />
        <br />
        <? if(SESSION_STATUS != 'ok') { ?>
        <?=LANG_YOUR_EMAIL_ADDRESS?><br />
        <input type="text" name="docinput[sender]" size="50"><br />
        <br />
        <? }
        else { ?>
        <input type="hidden" name="docinput[sender]" value="<?=SESSION_EMAIL?>">
        <? } ?>
        <?=LANG_MESSAGE?><br />
        <input type="text" name="docinput[body]" size="50"><br />
        <br />
        <input type="submit" value="Send">
        </form>
        <?
        }

elseif(isset($docinput['save']) && $docinput['save'] == "send_email" && isset($docinput['email']) &&
	strlen($docinput['email']) > 3 && isemail($docinput['sender'])) {

	if($docinput['sender'] == '') { $docinput['sender'] = 'unknown_user@'.$SERVER_NAME; }
        if($docinput['body'] != '') {
        $message_body = $docinput['body']."\n\n";
 	       }
        else {
        	$message_body = '';
                }
	$message_body .= transform($document['timestamp'], 'date')."\n\n";
        if(isset($document['title'])) $message_body .= transform($document['title'],'clean')."\n\n";
        if(isset($document['body']))  $message_body .= transform(transform($document['body'], $value['datatype']['body']),'html2txt')."\n\n";

        $message_body .= "--------------------------------------------------------\n\n";
        $message_body .= LANG_EMAIL_SENT_BY.' '.email_to_string($docinput['sender'])."\n";
        $message_body .= LANG_ORIGINAL_DOC."\nhttp://".$SERVER_NAME.$REQUEST_URI."?id=$id\n";
        mail($docinput['email'], '['.SITE_TITLE.'] '.transform($document['title'],'clean'), 
		$message_body, "From: ".email_to_string($docinput['sender']).' <'.$docinput['sender'].'>');
        ?>
        <p><?=LANG_DOC_SENT_TO?> <b><?=$docinput['email']?></b></p>
        <?
        }

echo '<p class="newsDate">'.transform($document['timestamp'], 'date')."</p>";
echo '<h2>'.transform($document['title'], $document['datatype']['title']).'</h2>';
if($document['source'] != '') echo '<i>'.LANG_SOURCE.': '.transform($document['source'], $document['datatype']['source']).'</i>';
echo '<p class="justify">';
if($document['icon'] != '') echo transform($image_rpath.'news/'.$document['icon'], 'image_right');
echo transform($document['image'], $document['datatype']['image']).'</p>';
echo transform($document['body'], $document['datatype']['body']).'</p>';

if(isset($parents)) {
	echo('[ <a href="'.get_url($document['parent_id'],'first_item='.$first_item).'">'.LANG_BACK.'</a> ] ');
        }

if(!isset($action)) {
        echo '[ <a href="'.get_url($id,'action=send_email').'">'.LANG_SEND_TO_A_FRIEND.'</a> ]';
        }

echo('</p>');

$related = array();

$related = get_sorted_children(0, 10, 'timestamp', $doctypes['newsitem'], $document['parent_id']);

if(count($related) > 1) { 
	echo('<p>'.LANG_MORE_NEWS.'<br />');

	reset($related);
	while (list ($docid2, $value2) = each ($related)) {
		if($value2['title'] != '' && $docid2 != $id) {
			echo '<img src="'.$design['arrow_bullet'].'" border="0" hspace="2" width="10" height="7">'.
			'<a href="'.get_url($docid2).'">'.transform($value2['title'], 'clean').
			'</a> ('.transform($value2['timestamp'], 'date').')<br />'."\n";
			}
		}
	
	echo('</p><br><br>');
	}
}

elseif($profile['editor']=='1') {

	?>
	<p>
	<table width="100%" border="0" cellpadding="0" cellspacing="0"><tr>
	<td>
	<? create_editor_input('User comments at bottom', 'comments', 'onoff_input'); ?>
	<input type="hidden" name="docdataflavour[comments]" value="0" />
	</td><td>
	<? create_editor_input('Show published files at bottom','show_files','onoff_input'); ?>
	</td></tr></table><p>
	<? create_editor_input('Source','source','text_input'); ?>
	<br /><br />
	<? create_editor_input('Link to external URL (optional)','redirect','text_input'); ?>
	</p>
	<p>
	<input type="hidden" name="docdataflavour[icon]" value="0">
	<?
	create_editor_input('Icon','icon','icon_input');
	echo '<br /><br />';
	create_editor_input('Image', 'image', 'image_input');
	echo '<br /><br />';
	create_editor_input('Body', 'body', 'area_input');

	} 

else {
        echo("<b>".LANG_NO_CONTENT."</b>");
        }

?>
