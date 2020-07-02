<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 10.01.2002
*/

if(strpos($HTTP_USER_AGENT, 'MSIE') && file_exists('css/'.$design['css'].'.msie.css')) {
?><link rel="stylesheet" type="text/css" href="css/<?=$design['css']?>.msie.css" /><?
} elseif(strpos($HTTP_USER_AGENT, 'pera') && file_exists('css/'.$design['css'].'.opera.css')) {
?><link rel="stylesheet" type="text/css" href="css/<?=$design['css']?>.opera.css" /><?
} elseif(strpos($HTTP_USER_AGENT, 'ozilla/4') && file_exists('css/'.$design['css'].'.ns4.css')) {
?><link rel="stylesheet" type="text/css" href="css/<?=$design['css']?>.ns4.css" /><?
} elseif(strpos($HTTP_USER_AGENT, 'ozilla/5') && file_exists('css/'.$design['css'].'.ns6.css')) {
?><link rel="stylesheet" type="text/css" href="css/<?=$design['css']?>.ns6.css" /><?
} elseif(file_exists('css/'.$design['css'].'.css')) {
?><link rel="stylesheet" type="text/css" href="css/<?=$design['css']?>.css" /><?
}
