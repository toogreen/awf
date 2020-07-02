<?
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
	http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 20.05.2002
*/


//error_reporting(1); // Disable Warnings

// Load database stuff
include('../inc/database.inc');
include('../inc/db_tables.inc');

// Read all contstants from database
$qresult = sql_query ("SELECT name, value FROM ".TABLE_SETUP);
if(sql_num_rows($qresult) > 0) {
        while ($row = sql_fetch_row($qresult)) {
                define(strtoupper($row[0]),$row[1]);
                }
        sql_free_result($qresult);
        }


if($_POST['send_feedback'] == 'true') {
	$body = '<form type="awf_feedback">'."\n";
	$docinput = $_POST['docinput'];
	while(list($key, $value) = each($docinput)) {
		$body .= '<'.$key.'>'.htmlspecialchars($value).'</'.$key.">\n";
		}
	$body .= '</form>';
	mail('awf-feedback@liquidbytes.net','AWF Feedback',$body,'From: '.$docinput['email']);
	}
?>

<html>
<head>
<title>
Liquid Bytes AWF Feedback
</title>
<?
        include('header.inc');
?>
<center>
<table width=90% cellpadding=0 cellspacing=0 border=0>
<tr><td align="left">
<? if($_POST['send_feedback'] != 'true') { ?>
<form action="feedback.php" method="post">
<input type="hidden" name="send_feedback" value="true">
<input type="hidden" name="docinput[awf_version]" value="<?=VERSION?>">
<center><h2>Send Feedback to Liquid Bytes</h2></center>
<p>
Note: Only fields marked with <b>*</b> are required.
<p>
<b>Feedback Type *</b>
<br>
<select name="docinput[type]">
<option>Bug report</option>
<option>Support question</option>
<option>Feature request</option>
<option>Words of thanks</option>
<option>Other</option>
</select>
<p>
<b>Priority *</b>
<br>
<select name="docinput[priority]">
<option>Highest</option>
<option>High</option>
<option selected>Normal</option>
<option>Low</option>
<option>Lowest</option>
</select>
<p>
<b>E-mail *</b>
<br>
<input type="text" name="docinput[email]" size="50" value="<?=WEBMASTER_MAIL?>">
<p>
<b>Web Site</b>
<br>
<input type="text" name="docinput[website]" size="50" value="http://">
<p>
<b>PHP-Version</b>
<br>
<input type="text" name="docinput[php_version]" size="50" value="<?=phpversion()?>">
<p>
<b>Web Server</b>
<br>
<input type="text" name="docinput[server]" size="50" value="<?=$_SERVER['SERVER_SOFTWARE']?>">
<p>
<b>PHP skills</b>
<br>
<select name="docinput[php_skills]">
<option>Guru</option>
<option>Expert</option>
<option selected>Good</option>
<option>Newbie</option>
<option>What's PHP?</option>
</select>
<p>
<b>Operating System</b>
<br>
<select name="docinput[os]">
<option selected>All</option>
<option>RedHat/Mandrake Linux</option>
<option>SuSE Linux</option>
<option>Debian Linux</option>
<option>Rock Linux</option>
<option>Other Linux</option>
<option>MacOS X</option>
<option>Solaris</option>
<option>SunOS</option>
<option>FreeBSD</option>
<option>OpenBSD</option>
<option>NetBSD</option>
<option>AIX</option>
<option>BeOS</option>
<option>HP-UX</option>
<option>IRIX</option>
<option>OS/2</option>
<option>Windows 95/98/ME</option>
<option>Windows NT/2000</option>
<option>Windows XP</option>
<option>Other</option>
</select>
<p>
<b>Message (bug reports should be as <i>detailed</i> as possible) *</b>
<br>
<textarea name="docinput[message]" cols="50" rows="10"></textarea>
<p>
<input type="checkbox" name="docinput[reply_req]" value="yes"> Reply required.
<br>
<input type="checkbox" name="docinput[contribute]" value="yes"> I'm willing to contribute.
<br>
<input type="checkbox" name="docinput[will_pay]" value="yes"> I'm willing to pay for my problem to be solved quickly.
<br>
<input type="checkbox" name="docinput[sponsor]" value="yes"> I want to become sponsor.
<br>
<input type="checkbox" name="docinput[send_sources]" value="yes"> New features/bugfixes: I will mail the sources to <a href="mailto:awf-feedback@liquidbytes.net">awf-feedback@liquidbytes.net</a>.
<br>
<input type="checkbox" name="docinput[thanks]" value="yes"> Thanks :-)
<p>
<input type="submit" value="Send">
</form>
<? 	} 

else { 
	?>
	<p>
	<h2>Thanks for your feedback!</h2>
	<p>
	Liquid Bytes will read and archive every single feedback message. We consider the feedback of our customers as very valuable. Please understand, 
	that it is not possible to write an individual reply in every case.
	
<?
	}
?>
</td></tr></table></center>
<?
	include('footer.inc');
?>
</body>
</html>
