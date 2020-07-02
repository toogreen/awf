<script language="javascript">
<!--

<?
if(SESSION_STATUS == 'ok' && count_messages(SESSION_DBID, 'instant', '0') > 0 && (!isset($profile['im_popup']) || $profile['im_popup'] == '1')) {

$messages = search_messages(SESSION_DBID, 'instant', 0, time(), -1, '', '', false);

// echo count($messages);

while(list($key, $value) = each($messages)) { ?>
	newWindows<?=$key?> = open('message.php?message_id=<?=$key?>&session_passwd=<?=$session_passwd?>&session_userid=<?=$session_userid?>','message<?=$key?>',
	"height=249,width=299,dependent=yes,toolbar=no,menubar=no,scrollbars=no,resizable=no,status=no,location=no");
	<? 
	} 
}
?>

function sendmessage(user_id)
{
        window.open("message.php?session_passwd=<?=$session_passwd?>&session_userid=<?=$session_userid?>&send_message=" + user_id,
        "SendInstantMessage",
        "width=299,height=249,dependent=yes,toolbar=no,menubar=no,scrollbars=no,resizable=no,status=no,location=no");
}

// -->
</script>

<? include('inc/custom/custom_popup.inc'); ?>
