<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: Mon May 20 21:59:58 CEST 2002
*/

define("DBMS","mysql");

function sql_query ($query) {
        return mysql_query($query);
        }
 
function sql_affected_rows($qresult = -1) {
        return mysql_affected_rows();
        }

function sql_num_rows($qresult) {
	if($qresult > 0) {
                return mysql_num_rows($qresult);
                }
        else {
                return 0;
                }
        }
 
function sql_fetch_row($qresult) {
        return mysql_fetch_row($qresult);
        }
 
function sql_free_result($qresult) {
        return mysql_free_result($qresult);
        }

function sql_insert_id($qresult = -1) {
	return mysql_insert_id();
	}

function sql_limit($count, $offset = 0) {
	return("LIMIT $offset, $count");
	}

// MySQL Database settings
$db_host        = "localhost";
$db_name        = "awf";
$db_username    = "mysql-admin";
$db_password    = "toosad";
$db_table_prefix= "1_";
 
if(function_exists("mysql_connect")) {
	mysql_connect($db_host,$db_username,$db_password);
	define(SQL_CONNECTION, mysql_select_db($db_name));
	}

?>