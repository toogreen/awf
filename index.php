<?php
/*
        Copyright (C) 2000-2002 Liquid Bytes (R), Germany. All rights reserved.
        http://www.liquidbytes.net/
 
        This file is part of the liquidbytes.net Adaptive Website Framework (AWF)
        The author is Michael Mayer (michael@liquidbytes.net)
        Last update: 10.01.2002
*/

	include("inc/functions.inc");
	include("inc/licence.key");
	include("inc/sessions.inc");
	include("inc/caching.inc");
	include("inc/config.inc");
	include(INC_PATH.INIT_INC);
	include(INC_PATH.DESIGN_INC);

?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="format" value="text/xhtml" />
<meta name="robots" value="index,follow" />
<meta name="charset" value="<?=CHARSET?>" />
<meta name="generator" value="adaptive website framework" />
<meta name="description" content="<?=$meta_description?>" />
<meta name="author" content="<?=$meta_author?>" />
<meta name="keywords" content="<?=$meta_keywords?>" />
<title><?=$page_title?></title>
<?php include(INC_PATH."popup.inc"); ?>
<?php include(INC_PATH."css.inc"); ?>
</head>
<body bgcolor="<?=$design['bgcolor']?>" marginheight="<?=$design['bodymarginheight']?>" marginwidth="<?=$design['bodymarginwidth']?>" topmargin="<?=$design['bodytopmargin']?>" bottommargin="<?=$design['bodybottommargin']?>" rightmargin="<?=$design['bodyrightmargin']?>" leftmargin="<?=$design['bodyleftmargin']?>" link="<?=$design['linkcolor']?>" vlink="<?=$design['vlinkcolor']?>" text="<?=$design['textcolor']?>"> 
<?php
	include(INC_PATH.CONTENT_INC);
?>
</body>
</html>
<?php
	include(INC_PATH.SHUTDOWN_INC);

?>



