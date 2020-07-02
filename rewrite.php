<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 06.01.2002
*/

// this file is required in combination with mod_rewrite to enable url rewriting

// should already work with register globals = off

global $PHP_SELF;

define('URL_REWRITE', '1');

$dirname = dirname($_SERVER['PHP_SELF']).'/';
if($dirname == '//') $dirname = '/';

if(dirname($_SERVER['REQUEST_URI']) != dirname($_SERVER['SCRIPT_NAME'])) {
	$redirect = file('inc/data/redir_map.conf');
	while(list($key, $value) = each($redirect)) {
		if($dirname.strtok($value,'	') == $_SERVER['REQUEST_URI']) {
                	header("Location: ".$dirname.trim(strstr($value,'	')));
			exit();
			}
		}
	$default = 'index.html';
	if(isset($default)) header("Location: ".$dirname.$default);
	exit(); 
	}

$url_exp = explode('/',$_SERVER['REQUEST_URI']);
if(!isset($id)) {
	if($url_exp[count($url_exp) - 1] == '') {
		header("Location: ".$dirname."index.html");
		exit();
		}
	$id = substr($url_exp[count($url_exp) - 1], 0, -1 * strlen(strstr($url_exp[count($url_exp) - 1],'.')));
	array_pop($url_exp);
	array_shift($url_exp);

} elseif(!($id == substr($url_exp[count($url_exp) - 1], 0, -1 * strlen(strstr($url_exp[count($url_exp) - 1],'.'))))) {
	// init $self var
	$pre    = '?';
	$self   = "$id.html";
	while (list ($key, $value) = each ($_GET)) {
		if($key != 'id') {
			if(is_array($$key)) {
				while (list ($key2, $value2) = each ($$key)) {
				        $self .= $pre.$key[$key2].'='.urlencode($value2);
        				$pre = '&';
					}
				}
			else {
			        $self .= $pre.$key.'='.urlencode($value);
        			$pre = '&';
				}
			}
	        }
	header("Location: $self");
	}

if(isset($id)) {
	$PHP_SELF = $dirname."$id.html"; 
	}
else {
	$PHP_SELF = $dirname.'index.html';
	}

include('index.php'); 
?>
