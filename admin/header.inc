<?
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 09.01.2002
*/

if(strpos($HTTP_USER_AGENT, 'MSIE') && file_exists('css/'.$design['css'].'.msie.css')) {
?><link rel="stylesheet" type="text/css" href="admin.msie.css" /><?
} else {
?><link rel="stylesheet" type="text/css" href="admin.css" /><?
}

?>

</head>
<body bgcolor="#ffffff" topmargin="0" rightmargin="0" leftmargin="0" marginwidth="0" marginheight="0">
<table width=100% height="61" cellpadding="0" cellspacing="0" border="0">
<tr>
<td width="295" height="61" bgcolor="#ffffff" valign="top" background=""><a href="http://liquidbytes.net/products/awf/"><img src="logo.jpg" border="0" width="295" height="61"></a></td>
<td width="100%" bgcolor="#ffffff" background="sky.jpg">
&nbsp;
</td>
</tr>
<tr>
<td colspan="2" bgcolor="#ffffff">&nbsp;
<span style="font-size: 12px">
<? $fn = basename($PHP_SELF); ?>
<a href="users.php"><? if($fn=='users.php') { echo '<b>User Management</b>'; } else { echo 'User Management'; } ?></a> 
|
<a href="groups.php"><? if($fn=='groups.php') { echo '<b>Groups</b>'; } else { echo 'Groups'; } ?></a> |
<a href="stats.php"><? if($fn=='stats.php') { echo '<b>Statistics</b>'; } else { echo 'Statistics'; } ?></a> |
<a href="ads.php"><? if($fn=='ads.php') { echo '<b>Ads</b>'; } else { echo 'Ads'; } ?></a> |
<a href="modules.php"><? if($fn=='modules.php') { echo '<b>Modules</b>'; } else { echo 'Modules'; } ?></a> |
<a href="types.php"><? if($fn=='types.php') { echo '<b>Document Types</b>'; } else { echo 'Document Types'; } ?></a> |
<a href="flavours.php"><? if($fn=='flavours.php') { echo '<b>Flavours</b>'; } else { echo 'Flavours'; } ?></a> |
<a href="polls.php"><? if($fn=='polls.php') { echo '<b>Polls</b>'; } else { echo 'Polls'; } ?></a> |
<a href="l10n.php"><? if($fn=='l10n.php') { echo '<b>l10n</b>'; } else { echo 'l10n'; } ?></a> |
<a href="config.php"><? if($fn=='config.php') { echo '<b>Config</b>'; } else { echo 'Config'; } ?></a> |
<a href="phpinfo.php"><? if($fn=='phpinfo.php') { echo '<b>PHP Info</b>'; } else { echo 'PHP Info'; } ?></a> |
<a href="feedback.php"><? if($fn=='feedback.php') { echo '<b>Feedback</b>'; } else { echo 'Feedback'; } ?></a> |
<a href="setup.php"><? if($fn=='setup.php') { echo '<b>Setup</b>'; } else { echo 'Setup'; } ?></a>
</span>
</td>
</tr>
<tr>
<td width="100%" height="10" bgcolor="#ffffff" valign="top" background="shadow_2.png" colspan="2">&nbsp;</td>
</table>
<br />
