<?php
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
	http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 25.11.2001
*/

error_reporting(1); // Disable Warnings

define('SESSION_STATUS', 'ok');

// Load database stuff
include('../inc/database.inc');
include('../inc/functions.inc');

                // Read all contstants from database
                $qresult = sql_query ("SELECT name, value FROM ".$db_table_prefix."setup");
                if(sql_num_rows($qresult) > 0) {
                        while ($row = sql_fetch_row($qresult)) {
                                define(strtoupper($row[0]),$row[1]);
                                }
                        sql_free_result($qresult);
                        }
$order_by = 'id';

?>

<html>
<head>
<title>
Liquid Bytes AWF User Management - HTML dump
</title>
</head>
<body bgcolor="#ffffff" topmargin="0" rightmargin="0" leftmargin="0" marginwidth="0" marginheight="0">
<?
$qres = sql_query("SELECT id, email, password, valid, views, last_login FROM ".$db_table_prefix."users $where".
		" ORDER BY $order_by");

$qres2 = sql_query("SELECT DISTINCT name FROM ".$db_table_prefix."userdata ORDER BY name");

while($row2 = sql_fetch_row($qres2)) {
	$userdata[] = $row2[0];
	}
?>
<table width="100%" border="0" cellpadding="2" cellspacing="1">
        <tr>
        <td>id</td>
	<td>email</td>
	<td>password</td>
	<td>valid</td>
        <td>views</td>
        <td>last_login</td>
	<?
	while(list($key, $value) = each($userdata)) {
        echo "<td>$value</td>";
        }
	?>
        </tr>
		<?
		while($row = sql_fetch_row($qres)) {
			if($row[3]==1) { $row[3] = '1'; } else { $row[3] = '0'; } 
			?>
	<tr>
        <td><?=$row[0]?></td>
        <td><?=$row[1]?></td>
        <td><?=$row[2]?></td>
        <td><?=$row[3]?></td>
        <td><?=$row[4]?></td>
        <td><?=$row[5]?></td>
	<?
	$profile = get_profile ($row[0]);
	reset($userdata);
	while(list($key, $value) = each($userdata)) {
        if(isset($profile[$value])) { echo "<td>$profile[$value]</td>"; }
	else { echo "<td></td>"; }
        }
	?>
        </tr>
		<? } ?>
</table>
</body>
</html>
