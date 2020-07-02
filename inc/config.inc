<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 20.12.2001
*/

error_reporting(1); // Disable Warnings

define('AWF_VERSION', '102');

// Establish DB connection
require('inc/database.inc');

// Tell the user, if the DB connection is broken...
if(!defined('SQL_CONNECTION') || SQL_CONNECTION == false) { 
	// show error page
	include('inc/data/errors/db_error.inc'); 
	// log error
	error_log($GLOBALS['REMOTE_ADDR'].'	'.time().'	'.$GLOBALS['id']."	$db_host	$db_name\n", 
			3, 'log/'.date("Y_m").'_dberror.log');
	// bye
	exit(); 
	}

// define tables names
require('inc/db_tables.inc');

// Read all constants from database
$qresult = sql_query ("SELECT name, value FROM ".$db_table_prefix."setup"); 
while ($row = sql_fetch_row($qresult)) {
	define(strtoupper($row[0]),$row[1]);
	}
sql_free_result($qresult);

// set error handler
set_error_handler('awf_error_handler');

// init $self var
$pre 	= '?';
if(defined('URL_REWRITE')) { $self 	= get_url($id); }
else { $self = $PHP_SELF; }
if($HTTP_POST_VARS) $HTTP_GET_VARS = array_merge($HTTP_POST_VARS, $HTTP_GET_VARS);
while (list ($key, $value) = each ($HTTP_GET_VARS)) {
	// loop through filter
	if(!($key == 'docinput' || $key == 'docdata' || $key == 'doc' || $key == 'docupload' || (defined(URL_REWRITE) && $key == 'id'))) {
		$self .= $pre.$key.'='.urlencode($value);
		$pre = '&';
		}
	}
$self	= $self.$pre;

// Basic settings
$image_rpath	= IMAGE_RPATH;
$image_path	= BASE_PATH.IMAGE_RPATH;
$site_title	= SITE_TITLE;
$default_document= DEFAULT_DOCUMENT;
$default_flavour= DEFAULT_FLAVOUR;
$default_design = DEFAULT_DESIGN;
$count_views 	= COUNT_VIEWS;
$cache_time  	= CACHE_TIME;
$webmaster_mail = WEBMASTER_MAIL;

// i18n
if(!defined("DEFAULT_LANG")) {
	define("DEFAULT_LANG",'en');
	define("LANG_PATH", INC_PATH.'lang/');
	}
if(!isset($lang)) $lang = DEFAULT_LANG;

define("CONFIG_CREATE_MASK", 0707);

if (SHOW_WARNINGS == 1) error_reporting(4);

include('inc/custom/custom_config.inc');

?>
