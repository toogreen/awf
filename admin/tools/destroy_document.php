#!/usr/bin/php -q
<?
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
	http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 12.01.2002
*/

echo "\nThis script can be used to remove documents from a AWF database.\n";
echo "Copyright (C) 2002 Liquid Bytes (R), Germany. All rights reserved.\n\n";

if($argc < 2) {
	echo "Usage: destroy_document.php [id]\n\n";
	exit();
	}

error_reporting(1); // Disable Warnings

// Load database stuff
include('../../inc/functions.inc');
include('../../inc/database.inc');
include('../../inc/db_tables.inc');

init_doctypes();

// Read all contstants from database
$qresult = sql_query ("SELECT name, value FROM ".TABLE_SETUP);
if(sql_num_rows($qresult) > 0) {
	while ($row = sql_fetch_row($qresult)) {
        	define(strtoupper($row[0]),$row[1]);
                }
	sql_free_result($qresult);
	}

destroy_node($argv[1]);
echo "Done :-)\n\n";
?>
