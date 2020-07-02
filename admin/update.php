<?

include('inc/database.inc');

sql_query('ALTER TABLE '.$db_table_prefix.'modules ADD COLUMN caption text');
sql_query('ALTER TABLE '.$db_table_prefix.'nodedata ADD COLUMN version varchar(8)');
sql_query('ALTER TABLE '.$db_table_prefix.'modules CHANGE COLUMN position placement');

?>
