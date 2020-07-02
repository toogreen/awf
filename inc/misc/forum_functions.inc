<?
/*	Functions for the forum module.
	maintained by Christoph Stickel <mixer2@web.de>	*/

function printnick($value) {
	if(isset($value['userid'])) {
		$nick = '<b>'.transform($value['userid'], 'user_id').'</b>';
		}
	else {
		if(ereg('@',$value['email'])) {
			$nick = '<a href="mailto:'.transform($value['email'], 'clean').'">'.transform(substr($value['nick'],0,15), 'clean');
			if(strlen($value['nick'])>15) { $nick = $nick.'...'; }
			$nick = $nick.'</a>';
			}
		else { $nick = transform(substr($value['nick'],0,15), 'clean'); if(strlen($value['nick'])>15){$nick = $nick.'...';} }
		}
	return $nick;
	}

function getswitchcolor() {
	global $design;
	global $colorswitch;
	if($colorswitch == '0') {  echo $design['table_row_dark']; return '1'; }
	else { echo $design['table_row_bright']; return '0'; }
	}

function delsendpermail ($userid) {
	if(!isset($userid) || $userid < 0) {
		return 'error';
		}
	else	{
		global $id;
		global $doctypes;
		global $childcount;
		$result=get_children(0,$childcount['forum_mailto'],$doctypes['forum_mailto']);
		while(list($key, $value) = each($result)) {
			if($value['email_user_id'] == $userid) {
				destroy_node($key);
				--$childcount['forum_mailto'];
				}
			}
		}
	}

function issendpermail ($userid)
	{
	if(!isset($userid) || $userid < 0)
		{
		return 'error';
		}
	else	{
		global $id;
		global $doctypes;
		global $childcount;
		$result=get_children(0,$childcount['forum_mailto'],$doctypes['forum_mailto']);
		while(list($key, $value) = each($result)) {
			if($value['email_user_id'] == $userid) {
				$alreadyex = '1';
				}
			}
		if($alreadyex == '1') {	return '1'; }
		else { return '0'; }
		}
	}

function sendcomplete ($userid, $docid)
	{
	global $flavour;
	global $doctypes;
	global $SERVER_NAME;
	global $REQUEST_URI;
	global $webmaster_mail;
	global $childcount;
	global $id;
	
	$result = get_nodedata($docid, $flavour);
	$mailemail = get_user_email($userid);
	$mailtitle = $result['title'];

	$message_body = transform(time(), 'date')."\n\n";
	
	if(isset($result['userid'])) {
		$message_body .= '['.transform($result['title'],'clean').']'."\n(".email_to_string(get_user_email($result['userid']))." <".get_user_email($result['userid']).">, ".transform($result['time'], 'datetime').")\n".transform(transform($result['body'], 'usertext'),'html2txt'); }
	else { $message_body .= '['.transform($result['title'],'clean').']'."\n(".email_to_string($result['email'])." <".$result['email'].">, ".transform($result['time'], 'datetime').")\n".transform(transform($result['body'], 'usertext'),'html2txt'); }
	
	$result = get_children(0, $childcount['forum_posting'], $doctypes['forum_posting'], 0, 'DESC', 0, $docid);
	while(list($key, $value) = each($result)) {
		if(isset($value['userid'])) {
		$message_body .= "\n\n".'['.transform($value['title'],'clean').']'."\n(".email_to_string(get_user_email($value['userid']))." <".get_user_email($value['userid']).">, ".transform($value['time'], 'datetime').")\n".transform(transform($value['body'], 'usertext'),'html2txt'); }
		else { $message_body .= "\n\n".'['.transform($value['title'],'clean').']'."\n(".email_to_string($value['email'])." <".$value['email'].">, ".transform($value['time'], 'datetime').")\n".transform(transform($value['body'], 'usertext'),'html2txt'); }
		}
	$message_body .= "\n\n--------------------------------------------------------\n\n";
 	$message_body .= LANG_EMAIL_SENT_BY.' '.email_to_string($webmaster_mail)."\n";
       	$message_body .= LANG_ORIGINAL_DOC."\nhttp://".$SERVER_NAME.get_url($id)."\n";	
	mail($mailemail, '['.SITE_TITLE.'] '.transform($mailtitle,'clean'), stripslashes($message_body), "From: ".email_to_string($webmaster_mail).' <'.$webmaster_mail.'>');
	return '0';
	}

function fhost($host)
	{
	return '---'.strstr($host,'.');
	}
function fhostadmin($host)
	{
	return $host;
	}

?>
