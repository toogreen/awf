-- MySQL dump 10.11
--
-- Host: localhost    Database: toogreen1
-- ------------------------------------------------------
-- Server version	5.0.83-1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `awf_forum`
--

DROP TABLE IF EXISTS `awf_forum`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `awf_forum` (
  `id` int(10) unsigned NOT NULL default '0',
  `datestamp` datetime NOT NULL default '0000-00-00 00:00:00',
  `thread` int(10) unsigned NOT NULL default '0',
  `parent` int(10) unsigned NOT NULL default '0',
  `author` char(37) NOT NULL default '',
  `subject` char(255) NOT NULL default '',
  `email` char(200) NOT NULL default '',
  `host` char(50) NOT NULL default '',
  `email_reply` char(1) NOT NULL default 'N',
  `approved` char(1) NOT NULL default 'N',
  `msgid` char(100) NOT NULL default '',
  `modifystamp` int(10) unsigned NOT NULL default '0',
  `userid` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `author` (`author`),
  KEY `userid` (`userid`),
  KEY `datestamp` (`datestamp`),
  KEY `subject` (`subject`),
  KEY `thread` (`thread`),
  KEY `parent` (`parent`),
  KEY `approved` (`approved`),
  KEY `msgid` (`msgid`),
  KEY `modifystamp` (`modifystamp`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `awf_forum`
--

LOCK TABLES `awf_forum` WRITE;
/*!40000 ALTER TABLE `awf_forum` DISABLE KEYS */;
/*!40000 ALTER TABLE `awf_forum` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `awf_forum_bodies`
--

DROP TABLE IF EXISTS `awf_forum_bodies`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `awf_forum_bodies` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `body` text NOT NULL,
  `thread` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `thread` (`thread`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `awf_forum_bodies`
--

LOCK TABLES `awf_forum_bodies` WRITE;
/*!40000 ALTER TABLE `awf_forum_bodies` DISABLE KEYS */;
/*!40000 ALTER TABLE `awf_forum_bodies` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `forums`
--

DROP TABLE IF EXISTS `forums`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `forums` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `name` char(50) NOT NULL default '',
  `active` smallint(6) NOT NULL default '0',
  `description` char(255) NOT NULL default '',
  `config_suffix` char(50) NOT NULL default '',
  `folder` char(1) NOT NULL default '0',
  `parent` int(10) unsigned NOT NULL default '0',
  `display` int(10) unsigned NOT NULL default '0',
  `table_name` char(50) NOT NULL default '',
  `moderation` char(1) NOT NULL default 'n',
  `email_list` char(50) NOT NULL default '',
  `email_return` char(50) NOT NULL default '',
  `email_tag` char(50) NOT NULL default '',
  `check_dup` smallint(5) unsigned NOT NULL default '0',
  `multi_level` smallint(5) unsigned NOT NULL default '0',
  `collapse` smallint(5) unsigned NOT NULL default '0',
  `flat` smallint(5) unsigned NOT NULL default '0',
  `lang` char(50) NOT NULL default '',
  `html` char(40) NOT NULL default 'N',
  `table_width` char(4) NOT NULL default '',
  `table_header_color` char(7) NOT NULL default '',
  `table_header_font_color` char(7) NOT NULL default '',
  `table_body_color_1` char(7) NOT NULL default '',
  `table_body_color_2` char(7) NOT NULL default '',
  `table_body_font_color_1` char(7) NOT NULL default '',
  `table_body_font_color_2` char(7) NOT NULL default '',
  `nav_color` char(7) NOT NULL default '',
  `nav_font_color` char(7) NOT NULL default '',
  `allow_uploads` char(1) NOT NULL default 'N',
  `upload_types` char(100) NOT NULL default '',
  `upload_size` int(10) unsigned NOT NULL default '0',
  `max_uploads` int(10) unsigned NOT NULL default '0',
  `security` int(10) unsigned NOT NULL default '0',
  `showip` smallint(5) unsigned NOT NULL default '1',
  `emailnotification` smallint(5) unsigned NOT NULL default '1',
  `body_color` char(7) NOT NULL default '',
  `body_link_color` char(7) NOT NULL default '',
  `body_alink_color` char(7) NOT NULL default '',
  `body_vlink_color` char(7) NOT NULL default '',
  PRIMARY KEY  (`id`),
  KEY `name` (`name`),
  KEY `active` (`active`),
  KEY `parent` (`parent`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `forums`
--

LOCK TABLES `forums` WRITE;
/*!40000 ALTER TABLE `forums` DISABLE KEYS */;
INSERT INTO `forums` VALUES (1,'Default',1,'','awf_','0',0,30,'awf_forum','n','','','',1,1,0,1,'lang/english.php','html','','','','','','','','','','N','',0,0,0,1,1,'','','','');
/*!40000 ALTER TABLE `forums` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `forums_auth`
--

DROP TABLE IF EXISTS `forums_auth`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `forums_auth` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `sess_id` varchar(32) NOT NULL default '',
  `name` varchar(50) NOT NULL default '',
  `username` varchar(50) NOT NULL default '',
  `password` varchar(50) NOT NULL default '',
  `email` varchar(200) NOT NULL default '',
  `webpage` varchar(200) NOT NULL default '',
  `image` varchar(200) NOT NULL default '',
  `icq` varchar(50) NOT NULL default '',
  `aol` varchar(50) NOT NULL default '',
  `yahoo` varchar(50) NOT NULL default '',
  `msn` varchar(50) NOT NULL default '',
  `jabber` varchar(50) NOT NULL default '',
  `signature` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`id`),
  KEY `name` (`name`),
  KEY `username` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `forums_auth`
--

LOCK TABLES `forums_auth` WRITE;
/*!40000 ALTER TABLE `forums_auth` DISABLE KEYS */;
INSERT INTO `forums_auth` VALUES (1,'eb3f35e17b0c3b0f20765eb8b21c1fc3','Admin','awf','1a0e464ff4f13755869adae40d07e1f3','webmaster@localhost','','','','','','','','');
/*!40000 ALTER TABLE `forums_auth` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `forums_moderators`
--

DROP TABLE IF EXISTS `forums_moderators`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `forums_moderators` (
  `user_id` int(10) unsigned NOT NULL default '0',
  `forum_id` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`user_id`,`forum_id`),
  KEY `forum_id` (`forum_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `forums_moderators`
--

LOCK TABLES `forums_moderators` WRITE;
/*!40000 ALTER TABLE `forums_moderators` DISABLE KEYS */;
INSERT INTO `forums_moderators` VALUES (1,0);
/*!40000 ALTER TABLE `forums_moderators` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toogreentoogreentoogreentoogreentoogreentoogreen1_groups`
--

DROP TABLE IF EXISTS `toogreentoogreentoogreentoogreentoogreentoogreen1_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `toogreentoogreentoogreentoogreentoogreentoogreen1_groups` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `group_name` varchar(32) NOT NULL default '',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `name` (`group_name`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `toogreentoogreentoogreentoogreentoogreentoogreen1_groups`
--

LOCK TABLES `toogreentoogreentoogreentoogreentoogreentoogreen1_groups` WRITE;
/*!40000 ALTER TABLE `toogreentoogreentoogreentoogreentoogreentoogreen1_groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `toogreentoogreentoogreentoogreentoogreentoogreen1_groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup`
--

DROP TABLE IF EXISTS `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `name` varchar(20) NOT NULL default '',
  `value` varchar(128) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup`
--

LOCK TABLES `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup` WRITE;
/*!40000 ALTER TABLE `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup` DISABLE KEYS */;
/*!40000 ALTER TABLE `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_setup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types`
--

DROP TABLE IF EXISTS `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `parent_id` int(11) unsigned NOT NULL default '0',
  `name` varchar(30) NOT NULL default 'unknown',
  `description` varchar(128) NOT NULL default 'none',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types`
--

LOCK TABLES `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types` WRITE;
/*!40000 ALTER TABLE `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types` DISABLE KEYS */;
/*!40000 ALTER TABLE `toogreentoogreentoogreentoogreentoogreentoogreentoogreen1_types` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-07-24 15:21:32
