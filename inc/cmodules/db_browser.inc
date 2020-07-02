<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 16.09.2001
*/

echo '<h1>Simple listing of database content</h1>';

function list_nodes ($parent_id = 0, $published = -1) {
        global $db_table_prefix;
        global $enabled_filter;
        global $flavour;
	global $PHP_SELF;
	global $docnames;

	if($published == 1) { $published_filter = 'AND published = 1'; } 
	elseif($published == 0) { $published_filter = 'AND published = 0'; }
	else { $published_filter = ''; }

        $qresult = sql_query("SELECT ".$db_table_prefix."nodes.id, name, value, type_id, published, enabled, searchable,
	cacheable, description, members_only, key_id, views FROM ".$db_table_prefix."nodes,
        ".$db_table_prefix."nodedata WHERE parent_id=$parent_id AND node_id=".$db_table_prefix."nodes.id
        AND flavour_id=$flavour AND name='title' $published_filter $enabled_filter ORDER BY sort_order DESC");
 
        if(sql_num_rows($qresult) > 0) {
		echo '<ul>';
                while($row = sql_fetch_row($qresult)) {
			echo '<li> <b><a href="'.$PHP_SELF.'?id='.$row[0].'">'.strip_tags(stripslashes($row[2])).'</a></b>, ';
			echo 'id '.$row[0].', ';
			if($row[4] == 1) { echo 'p'; } else { echo '-'; }
			if($row[5] == 1) { echo 'e'; } else { echo '-'; }
			if($row[6] == 1) { echo 's'; } else { echo '-'; }
			if($row[7] == 1) { echo 'c'; } else { echo '-'; }
			if($row[9] == 1) { echo 'm'; } else { echo '-'; }
			echo ', '.$row[11].' views, '.$docnames[$row[3]].'';
			list_nodes($row[0]);
                        }
		sql_free_result($qresult);
		echo '</ul>';
                }
        return(void);
        }

list_nodes();

?>
