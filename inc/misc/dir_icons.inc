<?php
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 01.01.2002
*/

global $subject;

if(isset($subject)) {
        $subject = urldecode($subject);
        if (strstr ($subject, '.')) {
                echo ('<b>You try to cheat!</b>');
                $subject = '/';
                }
        if(substr($subject, -1) != '/') {
                $subject = $subject.'/';
                }
        }
else {
        $subject = '/';
        }

?>

<?
if (!strstr($subject, '.')) {
// <table width="100%" cellpadding="1" cellspacing="0" border="0">
?>
<?

$file_counter = 0;
$total_size   = 0;
$dir_counter  = 0;

$filelist = array();
$dirlist = array();

$handle=opendir($value.$subject);
while (false != ($file = readdir($handle))) { 
	if(filetype($value.$subject.$file) == 'dir' || filetype($value.$subject.$file) == 'link') { $dirlist[] = $file; }
	if(filetype($value.$subject.$file) == 'file') { $filelist[] = $file; }
	}

sort($filelist);
sort($dirlist);
$filelist = array_merge($dirlist,$filelist);

while (list($nr,$file) = each($filelist)) {
    if ($file != "." && $file != ".." && strlen($file) > 0 && $file[0] != '.') { 
      $file_counter++;
      ?>
      <table width="32" cellpadding="0" cellspacing="5" border="0" align="left">
      <tr><td width="100%" align="center" height="32" width="32">
      <?
      if (filetype($value.$subject.$file) == 'dir' || filetype($value.$subject.$file) == 'link')  { 
        echo '<a href="'.get_url($id,'subject='.urlencode($subject.$file)).'%2f"><img src="img/32x32/filesystems/folder_yellow.png" border="0" alt="'.LANG_DIRECTORY.'"></a>
		</td></tr>
		<tr><td align="center" width="100%">
		<a href="'.get_url($id, 'subject='.urlencode($subject.$file.'/')).'">'.$file.'</a>'; }
      if (filetype($value.$subject.$file) == 'file') { 	
	$file_extention = strtolower(substr($file,-3));
	$frame_file = false;
	switch ($file_extention) {
		case 'gif':
		case 'png':
		case 'peg':
		case 'jpg': $file_picture = 'img/32x32/actions/appearance.png'; break;
		case 'gif': $file_picture = 'img/32x32/actions/appearance.png'; break;
		case 'wav':
		case 'mp3': $file_picture = 'img/32x32/mimetypes/sound.png'; break;
		case 'lnk': $file_picture = 'img/32x32/actions/connect_established.png'; break;
		case 'mov':
		case 'avi':
		case 'peg':
		case 'exe': $file_picture = 'img/32x32/actions/gear.png'; break;
		case 'php': 
		case 'hp3': 
		case 'hp4': $file_picture = 'img/32x32/mimetypes/html.png'; break; 
		case 'htm':
		case 'tml': $file_picture = 'img/32x32/mimetypes/html.png'; break;
		case 'zip':
		case 'tgz':
		case '.gz': $file_picture = 'img/32x32/apps/package.png'; break;
		case '.ps': $file_picture = 'img/32x32/apps/kword.png'; break;
		case 'doc': $file_picture = 'img/32x32/apps/kword.png'; break;
		case 'ppt': $file_picture = 'img/32x32/apps/kpresenter.png'; break;
		case 'xls': $file_picture = 'img/32x32/apps/kspread.png'; break;
		case 'sdw': $file_picture = 'img/32x32/apps/kword.png'; break;
		case 'sdc': $file_picture = 'img/32x32/apps/kspread.png'; break;
		case 'pdf': $file_picture = 'img/32x32/mimetypes/pdf.png'; break;
	        case 'txt': $file_picture = 'img/32x32/mimetypes/txt.png'; break;
		default: $file_picture = 'img/32x32/devices/zip_unmount.png'; false;		
		} 
	if($file_extention == 'lnk') {
		$fd = fopen($value.$subject.$file, "r");
    		$link = 'redirect.php?url='.trim(fread($fd, filesize ($value.$subject.$file)));
		fclose($fd);
        	echo '<a href="'.$link.'"><img width="32" height="32" src="'.$file_picture.'" border="0" alt="Link"></a>
		</td></tr><tr>
		<td width="100%" align="center">
		<a href="'.$link.'">'.substr($file,0,-4).'</a>'; 
		}
	elseif($frame_file == true) { 
        	echo '<a href="'.get_url($id, 'subject='.urlencode($subject)."&view=".urlencode($file)).'"><img hspace="5" width="16" height="16" src="'.$file_picture.'" border="0"></a>
		</td></tr><tr>
		<td width="100%" align="center">
		<a href="'.get_url($id, 'subject='.urlencode($subject)."&view=".urlencode($file)).'">'.$file.'</a>'; 
		}
	else {	
        	echo '<a href="redirect.php?url='.str_replace(' ', '%20',$value.$subject.$file).'"><img alt="'.floor(filesize($value.$subject.$file) / 1024).' KB" width="32" height="32" src="'.$file_picture.'" border="0"></a>
		</td></tr><tr>
		<td width="100%" align="center">
		<a href="redirect.php?url='.str_replace(' ','%20', $value.$subject.$file).'">'.$file.'</a>'; 
		}
	}

      ?>
      <?php
	if($profile['allow_delete'] == '1' || file_exists(BASE_PATH.$value.$subject.'.allow_delete') || $profile['editor'] == '1') {
		echo '[ <a href="'.get_url($id, 'subject='.urlencode($subject).'&deletefile='.urlencode($file)).'">'.LANG_BROWSE_DELETE.'</a> ]';
		}
     echo('</td></tr></table>');
    } 
}
closedir($handle); 

} ?>
<br clear="all" />
