<?php
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 21.06.2001
*/

if(!isset($url) || $url == '') { 
	echo 'Sorry, this is a redirection script. You can\'t expect any useful output.';
	exit(); 
	}

include('inc/database.inc');

mysql_query("UPDATE ".$db_table_prefix."redirect SET views=views+1 WHERE 
referer='".addslashes($referer)."' AND url='".addslashes($url)."'"); 
if(mysql_affected_rows() < 1) {
	mysql_query("INSERT INTO ".$db_table_prefix."redirect SET views=1, referer='".addslashes($referer)."',
	url='".addslashes($url)."'");
	if(mysql_affected_rows() < 1) {
		mysql_query("CREATE TABLE ".$db_table_prefix."redirect (id int not null auto_increment, 
		url text not null, referer text not null, views int default 1, primary key(id))");
		mysql_query("INSERT INTO ".$db_table_prefix."redirect SET views=1,
			referer='".addslashes($referer)."', url='".addslashes($url)."'");
		}
	}
header("Location: ".$url); // Redirect browser to $url

mysql_close();

exit();

?>
