<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 11.01.2002
*/

// set lang const
load_lang('general');

// set defaults
if(!isset($id) || !is_numeric($id)) $id = DEFAULT_DOCUMENT;
if(!isset($flavour) || !is_numeric($flavour)) $flavour = $default_flavour;
if(!isset($design['name']) || $design['name'] == '') $design['name'] = $default_design;

// check for SSL
define('SSL', $SERVER_PORT == '443');

// unset profile and set enabled_filter to avoid hacking!
unset($profile);
unset($enabled_filter);
unset($ssl_filter);
if(!SSL) { $ssl_filter = ' AND ssl_only = 0'; } else { $ssl_filter = ''; }
$enabled_filter = 'AND enabled=1 AND release_date < '.time().' AND (expiration_date > '.time().' OR expiration_date = 0)'.$ssl_filter;

// init other arrays
init_groups();
$cache_refresh = array();
$document = array();

//now we'll check the user data; maybe there's a registered community member
$qresult = sql_query("SELECT email, password, valid, id FROM ".$db_table_prefix."users WHERE email='$session_userid'");
if($qresult) {
        $row = sql_fetch_row($qresult);
	if((md5($row[1].$REMOTE_ADDR) == $session_passwd) && ($row[2] == '1') && !(FORCE_SSL && !SSL)) { 
		// Define constants for session info
		define('SESSION_STATUS','ok');
		define('SESSION_DBID', $row[3]);
		define('SESSION_EMAIL', $row[0]);

		// Inc view counter
		if($count_views == 1) sql_query("UPDATE ".$db_table_prefix."users SET views=views+1 WHERE email='$session_userid'");

		// Read USER PROFILE from database
		$profile = get_profile();

		// This is done for security reasons
		if($profile['edithost_'.$REMOTE_ADDR] != 1 && $profile['edithost_all'] != 1) { 
			$profile['editor'] = 0; 
			}
		elseif($profile['editor'] == '1') { 
			// If user is editor, show disabled documents too  
			$enabled_filter = ''; 
			// and switch off caching
			$cache_time = 0;
			}
		// Some users have editor rights for one document only
		if($profile['editor_'.$id] == '1' && ($profile['edithost_'.$REMOTE_ADDR] == 1 || $profile['edithost_all'] == 1)) {
			$profile['editor'] = 1;
			// If user is editor, show disabled documents too  
			$enabled_filter = ''; 
			// and switch off caching
			$cache_time = 0;
			}
		}
	elseif($row[2] != '1') {
		// I'm sorry...
		define('SESSION_STATUS','denied');
		define('SESSION_DBID', '-1');
		}
	elseif(FORCE_SSL && !SSL) {
		define('SESSION_STATUS','ssl_required');
		define('SESSION_DBID', '-1');
		}
	elseif(md5($row[1].$REMOTE_ADDR) != $session_passwd) {
		define('SESSION_STATUS','passwd');
		define('SESSION_DBID', '-1');
		}
	}
else {
	define('SESSION_STATUS','unknown');
	}  

if(SESSION_STATUS != 'ok') { 
	$enabled_filter .= ' AND members_only = 0';
	}

// nickname hack
if(!isset($profile['nickname'])) $profile['nickname'] = get_user_nickname();

// set wildcards
if(file_exists(INC_PATH.DATA_PATH.'wildcards.conf')) {
	$lines = file(INC_PATH.DATA_PATH.'wildcards.conf');
	while(list($line_num, $line) = each($lines)) {
	  $buffer = split('\|', $line);
	  $wildcards[$buffer[0]] = trim($buffer[1]);
	  }
	}

if($profile['editor'] == '1' && $self_loop != 'true') {
	if($docinput['save_doc_properties'] == 'true') {
	if($docinput['submit'] == 'Save' && $docinput['remove_document'] == '1') {
		destroy_node($id);
		remove_profile('editor_'.$id);
		$id = $back_dest;
		}
	elseif($docinput['submit'] == 'Save') {
		if($doc['enabled'] != 1) $doc['enabled'] = 0;
		if($doc['published'] != 1) $doc['published'] = 0;
		if($doc['searchable'] != 1) $doc['searchable'] = 0;
		if($doc['cacheable'] != 1) $doc['cacheable'] = 0;
		update_node($id, $doc['parent_id'], $doc['type_id'], $doc['sort_order'], $doc['enabled'], 
			$doc['published'], $doc['description'], $doc['key_id'], $doc['searchable'], $doc['cacheable']);
		if(isset($docdata)) {
		reset($docdata);
		while(list($key, $value) = each($docdata)) {
			if(isset($docdatatype[$key])) {
				$datatype = $docdatatype[$key]; 
				}
			else {
				$datatype = 'notrans';
				}
			if(isset($docdataflavour[$key]) && is_numeric($docdataflavour[$key])) {
				if(!update_nodedata($id, $key, $value, $docdataflavour[$key], $datatype)) add_nodedata($id, $key, $value, $docdataflavour[$key], $datatype);
				}
			else {
				if(!update_nodedata($id, $key, $value, $flavour, $datatype)) add_nodedata($id, $key, $value, $flavour, $datatype);
				}
			}
			}
		if(isset($docupload)) {
		reset($docupload);
		while(list($key, $value) = each($docupload)) {
			$filename = $docupload_name[$key];
			if($value != '' && $value != 'none') {
				if(dirname($key) != '.') { 
					mkdirs(BASE_PATH.get_dir_name('files', $id).'/'.dirname($key), CONFIG_CREATE_MASK);
/*					if(!file_exists(BASE_PATH.get_dir_name('files', $id).'/'.dirname($key))) {
						mkdir(BASE_PATH.get_dir_name('files', $id).'/'.dirname($key), CONFIG_CREATE_MASK);
						} */
					if(basename($key) != '*') { $filename = basename($key); }
					move_uploaded_file($value, BASE_PATH.get_dir_name('files', $id).'/'.dirname($key).'/'.basename($filename));
					chmod(BASE_PATH.get_dir_name('files', $id).'/'.basename($filename), CONFIG_CREATE_MASK);
					} 
				else {
					if(basename($key) != '*') { $filename = basename($key); }
					move_uploaded_file($value, BASE_PATH.get_dir_name(INC_PATH.DATA_PATH.'nodes', $id).'/'.basename($filename));
					chmod(BASE_PATH.get_dir_name(INC_PATH.DATA_PATH.'nodes', $id).'/'.basename($filename), CONFIG_CREATE_MASK);
					}
				}
			}
			}
		if(!update_nodedata($id, 'author', SESSION_EMAIL, $flavour, 'email')) add_nodedata($id, 'author', SESSION_EMAIL,$flavour,'email');
		if(!update_nodedata($id, 'author_id', SESSION_DBID, $flavour, 'user_id')) add_nodedata($id, 'author_id', SESSION_DBID, $flavour, 'user_id');
		if(!update_nodedata($id, 'timestamp', time(), $flavour, 'datetime')) add_nodedata($id, 'timestamp', time(), $flavour, 'datetime');
		if($docinput['default_doc'] == 1) {
			sql_query("UPDATE ".$db_table_prefix."setup SET value='".$id."' WHERE name='default_document'");
			$default_document = $id;
			}
		}
	elseif($docinput['submit'] == 'Back') { 
		$id=$back_dest;
		}
		}
        if($docinput['create_new_node'] == 'true') {
		$document['type_id']=$docinput['doctype'];
                $document['sort_order']=$docinput['docsort_order'];
                if($docinput['docpublished'] != '') { $document['published'] = 1; } else { $document['published'] = 0; }
                $document['parent_id']=$docinput['docparent_id'];
                $document['description']=$docinput['docdescription'];
                if($docinput['docenabled'] != '') { $document['enabled'] = 1;  } else { $document['enabled'] = 0; }
		$set_editor_rights = (isset($profile['editor_'.$id]) && $profile['editor_'.$id] == 1);
		$id = create_node($document['parent_id'], $document['type_id'], $document['sort_order'],
			$document['enabled'], $document['published'], $document['description']);
		if($set_editor_rights) { set_profile('editor_'.$id, 1); }
                unset($document);
		}
	if($docinput['delete_node'] == 'true') {
		remove_profile('editor_'.$docinput['delete_node_id']);
		if($id == $docinput['delete_node_id']) {
			$id = $default_document; 
			}
		destroy_node($docinput['delete_node_id']);
		}
	}


      

$document = get_node($id, $flavour);

if($document[key_id] == '0' || (SESSION_STATUS == 'ok' && ($profile['key_'.$document[key_id]] == '1' || $profile['key_master'] == '1'))) {
	define('DOCUMENT_ACCESS','1');
	}

else {
	switch(DENIED_ACTION) {
		case 1 : 
			define('DOCUMENT_ACCESS','1');
			$id = DENIED_DOCUMENT;
			$document = get_node($id, $flavour);
			break;
		case 2 :
			define('DOCUMENT_ACCESS','1');
			break;
		case 3 :
			define('DOCUMENT_ACCESS','0');
			break;
		case 4 :
			exit();
		case 5 :
			echo 'Access denied.'; 
			exit();	
		}
	}

if(!isset($document['enabled'])) {
	$id=$default_document;
	unset($document);
	$document = get_node($id, $flavour);
	}

if(!isset($document['title'])) { 
	if($profile[editor] != 1) { $flavour  = $default_flavour; } else { $document['title'] = 'Unknown'; }
	unset($document);
	$document = get_node($id, $flavour);
	} 

if(isset($document['redirect']) && $document['redirect'] != '' && $profile['editor'] != 1) {
	header("Location: ".$document['redirect']);
	exit();
	}

if(!defined('FINGERPRINT')) {
	define('FINGERPRINT', md5($db_table_prefix.$PHP_SELF.serialize(array_merge($HTTP_POST_VARS, $HTTP_GET_VARS)).$design['name'].$lang.$flavour.DOCUMENT_ACCESS));
	}

// define filename for cached content or switch off caching
if($document[cacheable] != 1 || defined("CACHE_FILENAME")) { 
	$cache_time = 0; 
	} 
else {
	define('CACHE_FILENAME', get_dir_name('cache', $id).'/'.FINGERPRINT);
	}

init_doctypes();

init_modules();

if(!isset($document['show_doc_only'])) { $document['show_doc_only'] = 0; }

if(SESSION_STATUS == 'ok') {

// Handle MAXIMIZE, MINIMIZE, ADD and REMOVE for modules

// REMOVE
if($docinput['rem_module']) {
	set_profile('module_'.$docinput['rem_module'], 2);
	$profile['module_'.$docinput['rem_module']] = 2;
	}

// ADD
elseif($docinput['add_module']) {
	set_profile('module_'.$docinput['add_module'], 1);
	$profile['module_'.$docinput['add_module']] = 1;
	}

// MAXIMIZE
elseif($docinput['max_module']) {
	set_profile('module_size_'.$docinput['max_module'], 1);
	$profile['module_size_'.$docinput['max_module']] = 1;
	}

// MINIMIZE
elseif($docinput['min_module']) {
	set_profile('module_size_'.$docinput['min_module'], 2);
	$profile['module_size_'.$docinput['min_module']] = 2;
	}
	}

// Handle multiple module show/hide requests
if(isset($docinput['save']) && $docinput['save'] == 'modules') {
	$qresult = sql_query("SELECT id, caption, visible, removeable FROM ".$db_table_prefix."modules WHERE removeable = 1 AND (target = 0 OR
                        target = 2) ORDER BY sort_order");
 
        if(sql_num_rows($qresult) > 0) {
                while($row = sql_fetch_row($qresult)) {
                        $mod_name = 'module_'.$row[0];
                        if($docinput['module_'.$row[0]] == '1' && ($row[2] != 1 || $profile['module_'.$row[0]] != 1)) {
                                set_profile('module_'.$row[0], 1);
                                $profile['module_'.$row[0]] = 1;
                                }
                        elseif($docinput['module_'.$row[0]] != '1' && $row[3] == 1) {
                                set_profile('module_'.$row[0], 2);
                                $profile['module_'.$row[0]] = 2;
                                }
                        }
                sql_free_result($qresult);
                }
	}

// set page title
$page_title = $site_title.' :: ';
$page_title .= trim(replace_wildcards(strip_tags($document['title']), $profile));

// set meta tags
$meta_author = trim(strip_tags(get_user_nickname($document['author_id'])));
$meta_description = trim(strip_tags($document['description']));
$meta_keywords = trim(strip_tags($document['keywords']));

if(isset($document['refresh']) && $document['refresh'] > 0 && $profile['editor'] != 1) {
	header('Refresh: '.$document['refresh']);
	}
header('Expires: 0');
header('Pragma: no-cache');

include('inc/custom/custom_init.inc');

?>
