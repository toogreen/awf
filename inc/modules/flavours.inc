<?
/*
        Copyright (C) 2000-2001 liquidbytes.net
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AFW)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 17.12.2001
*/

global $db_table_prefix;
global $flavour;
global $self;

$qresult = sql_query ("SELECT id, name, lang FROM ".$db_table_prefix."flavours WHERE published=1 ORDER BY name");
if ($qresult) {
        while ($row = sql_fetch_row($qresult)) {
			if($row[0] == $flavour) echo '<b>';
			echo ('<a href="'.$self.'docinput[flavour]='.$row[0].'&docinput[lang]='.$row[2].'">'.$row[1]."</a><br />\n");
			if($row[0] == $flavour) echo '</b>';
			}  
		}
        sql_free_result($qresult);

?> 
