<table width=100% height="50" cellpadding=0 cellspacing=0 border=0>
<tr>
<td width="200" height="50" bgcolor="#000000" valign="top" background="img/the_c2.jpg"><img src="img/the_c.jpg" border="0" width="200" height="50"></td></tr>
</table>
<table width="100%" cellpadding="0" cellspacing="0" border="0" bgcolor="#000000"><tr><?php /*<td width="173" bgcolor="#000000">&nbsp;</td> */ ?><td nowrap><font color="#dbb600"><b>

<?php 
        init_parents();
        if(isset($parents)) {
                reset($parents);
                while (list($docid, $value) = each ($parents)) {
                        $section_title = '<a style="color:#dbb600" href="'.get_url($docid).'">'.$value['title'].'</a> &gt; '.$section_title;
                        }
                }
        echo '<center>'.replace_wildcards($section_title." ".$document['title'], $profile).'</center>';
?>

</b></font></td></tr></table>


