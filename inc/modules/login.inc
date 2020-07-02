<?php
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 05.01.2002
*/

global $recover;
global $db_table_prefix;
global $id;
global $first_item;
global $self;
global $docinput;

if($recover == 'true' && isset($docinput['user_id'])) {
	$qresult = mysql_query ("SELECT password FROM ".$db_table_prefix."users WHERE email='".$docinput['user_id']."'");
	if ($qresult) {
		$row = mysql_fetch_row($qresult);
		$message = "$row[0]";
		mail($docinput['user_id'], '['.SITE_TITLE.'] Login', $message,
        	"From: ".WEBMASTER_MAIL."\nReply-To: ".WEBMASTER_MAIL);
		}
	echo '<p><b><font color="#00aa00">'.LANG_PASSWD_SENT.'</font></b><br />';
	}
if(FORCE_SSL && !SSL) {
	echo LANG_SSL_REQUIRED;
	}
elseif(SESSION_STATUS != 'ok') {
        if(SESSION_STATUS == 'passwd' && $docinput['passwd2'] != '') {
        echo '<p><b><font color="#AA0000">'.LANG_BAD_PASSWORD.'</font></b><br />
	<a href="'.$self.'docinput[user_id]='.$docinput['user_id'].'&recover=true">'.LANG_RECOVER_PASSWD.'</a></p>';
        }
        if(SESSION_STATUS != 'passwd' && $docinput['passwd2'] != '') {
        echo '<p><b><font color="#AA0000">'.LANG_BAD_EMAIL.'</font></b></p>';
        }
        ?>
        <form action="<?=$PHP_SELF?>" method="post">
        <input type="hidden" name="id" value="<?=$id?>" />
        <input type="hidden" name="first_item" value="<?=$first_item?>" />
        <input type="hidden" name="subject" value="<?=$subject?>" />
        <?=LANG_EMAIL_ADDRESS?><br />
        <input type="text" name="docinput[user_id]" size="17" value="<?=$docinput[user_id]?>" /><br /><br />
        <?=LANG_PASSWORD?><br />
        <input type="password" name="docinput[passwd2]" size="17" /><br /><br />
        <input type="submit" value="<?=LANG_LOGIN?>" />
        </form>
        <?php
        }
else { ?>
        <center><p><font color="#00aa00"><b><?=str_replace('%%email%%',SESSION_EMAIL,LANG_LOGGED_IN)?></b></font><br /><br />
        <form action="<?=$PHP_SELF?>" method="post">
        <input type="hidden" name="id" value="<?=$id?>" />
        <input type="hidden" name="first_item" value="<?=$first_item?>" />
        <input type="hidden" name="docinput[logout]" value="true" />
        <input type="submit" value="<?=LANG_LOGOUT?>" />
	</p>
        </form>
        </center>
        <?php
        }
?>

