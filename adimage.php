<?php
include('inc/database.inc');
  $queryres = sql_query("SELECT banner FROM ".$db_table_prefix."ads WHERE host='".$host."'");
  $row = sql_fetch_row($queryres); 
  if($host != '' && $row[0] != '') {
    sql_query("UPDATE ".$db_table_prefix."ads SET views=views + 1 WHERE host='".$host."'");
    header ("Location: ".$row[0]);
    exit;
    }
?>
