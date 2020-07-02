<?
$image_size = getimagesize($value); 
?>
<script language="javascript">
<!--

window.open("<?=$value?>","<?=md5($value)?>","width=<?=$image_size[0]+20?>,height=<?=$image_size[1]+20?>,dependent=yes,toolbar=no,menubar=no,scrollbars=no,resizable=no,status=no,location=no");

// -->
</script>
