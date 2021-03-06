<?
/*
        Copyright (C) 2000-2001 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 21.12.2001
*/

global $docupload;
global $design;

// check for uploads
if(isset($docupload[md5($value)]) && $docupload[md5($value)] != '' && $docupload[md5($value)] != 'none')
$document[$value] = join('', file(get_dir_name(INC_PATH.DATA_PATH.'nodes',$id).'/'.md5($value)));
?>
<?=$title?> (Type: 
<input type="radio" value="extrans" name="docdatatype[<?=$value?>]"<? if($document['datatype'][$value] == 'extrans') echo ' CHECKED'; ?> />
<span title="ASCII text with HTML tags embedded.">Extrans</span>&nbsp;
<input type="radio" value="text" name="docdatatype[<?=$value?>]"<? if($document['datatype'][$value] == 'text') echo ' CHECKED'; ?> />
<span title="Pure ASCII. Special characters will be converted by AWF.">Text</span>&nbsp;
<input type="radio" value="html" name="docdatatype[<?=$value?>]"<? if($document['datatype'][$value] == 'html') echo ' CHECKED'; ?> />
<span title="Valid XHTML source.">HTML</span>&nbsp;
<input type="radio" value="php" name="docdatatype[<?=$value?>]"<? if($document['datatype'][$value] == 'php') echo ' CHECKED'; ?> />
<span title="Executable PHP code.">PHP</span>&nbsp;
<input type="radio" value="external" name="docdatatype[<?=$value?>]"<? if($document['datatype'][$value] == 'external') echo ' CHECKED'; ?> />
<span title="Include content from the URL or file specified below.">External</span>)
<br />
<textarea wrap="virtual" name="docdata[<?=$value?>]" cols="<?=$design['input_size']?>" rows="<? if(isset($area_rows)) { echo $area_rows; } else { echo $design['input_rows']; } ?>"><?=htmlentities($document[$value])?></textarea> <br />
Upload (<u>no</u> binary files): <input type="file" name="docupload[<?=md5($value)?>]">
