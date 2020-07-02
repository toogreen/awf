<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 12.01.2002
*/

/*
if(isset($docinput['login']) && $docinput['login']=='true' && $PHP_AUTH_PW == '') {
	header("WWW-Authenticate: Basic realm=\"$SERVER_NAME\"");
	header("HTTP/1.0 401 Unauthorized");
	}

if(isset($PHP_AUTH_USER) && $docinput['logout'] != 'true' && $PHP_AUTH_PW != '' && $PHP_AUTH_USER != '') {
	$docinput['user_id'] = $PHP_AUTH_USER;
	$docinput['passwd2'] = $PHP_AUTH_PW;
	}
*/
if(isset($docinput['user_id'])) {
	setcookie (md5(LICENCE_KEY.'id'), $docinput['user_id'], 0);
	$session_userid = $docinput['user_id'];
	}
elseif(isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'id')])) {	
	$session_userid = $HTTP_COOKIE_VARS[md5(LICENCE_KEY.'id')];
	}

if(isset($docinput['passwd2'])) {
	setcookie (md5(LICENCE_KEY.'passwd'), md5($docinput['passwd2'].$REMOTE_ADDR), 0);
	$session_passwd = md5($docinput['passwd2'].$REMOTE_ADDR);
	}
elseif(isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'passwd')])) {
	$session_passwd = $HTTP_COOKIE_VARS[md5(LICENCE_KEY.'passwd')];
	}

if(!isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'session')])) setcookie (md5(LICENCE_KEY.'session'),
								md5(time().$REMOTE_ADDR.$HTTP_HOST.LICENCE_KEY), 0);

if(isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'session')])) $session_id = $HTTP_COOKIE_VARS[md5(LICENCE_KEY.'session')];

unset($design);

if(isset($docinput['design'])) {
	setcookie (md5(LICENCE_KEY.'design'), $docinput['design'], 0);
	$design['name'] = $docinput['design'];
	}
elseif(isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'design')])) {
	$design['name'] = $HTTP_COOKIE_VARS[md5(LICENCE_KEY.'design')];
	}
else {
	$design['name'] = '';
	}

unset($lang);

if(isset($docinput['lang'])) {
	setcookie (md5(LICENCE_KEY.'lang'), $docinput['lang'], 0);
	$lang = $docinput['lang'];
	}
elseif(isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'lang')])) {
	$lang = $HTTP_COOKIE_VARS[md5(LICENCE_KEY.'lang')];
	}

unset($flavour);

if(isset($docinput['flavour'])) {
	setcookie (md5(LICENCE_KEY.'flavour'), $docinput['flavour'], 0);
	$flavour = $docinput['flavour'];
	}
elseif(isset($HTTP_COOKIE_VARS[md5(LICENCE_KEY.'flavour')])) {
	$flavour = $HTTP_COOKIE_VARS[md5(LICENCE_KEY.'flavour')]; 
	}
else {
	$flavour = '';
	}

if(isset($docinput['logout']) && $docinput['logout'] == 'true') {
/*
	if(isset($PHP_AUTH_USER) && $PHP_AUTH_PW != '' && $PHP_AUTH_USER != '') { 
		header("WWW-Authenticate: Basic realm=\"$SERVER_NAME\"");
		header("HTTP/1.0 401 Unauthorized"); 
		}
*/
	setcookie (md5(LICENCE_KEY.'id'), "", 0);
	setcookie (md5(LICENCE_KEY.'passwd'), "", 0);
	$session_userid = '';
	$session_passwd = '';
	}

?>
