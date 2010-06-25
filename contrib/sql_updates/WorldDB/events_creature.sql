-- MySQL dump 10.11
--
-- Host: localhost    Database: wow_arctic
-- ------------------------------------------------------
-- Server version	5.0.51b-community-nt

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
-- Table structure for table `events_creature`
--

DROP TABLE IF EXISTS `events_creature`;
CREATE TABLE `events_creature` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'Relates to creature_spawn eventid',
  `id` tinyint(3) unsigned NOT NULL COMMENT 'Relates to creature_spawn id',
  `changesflag` tinyint(1) NOT NULL default '0' COMMENT 'See enum in the core for permissable flags in World.h',
  `phase` tinyint(3) default NULL COMMENT 'This is the phase the creature is in when the event is active',
  `displayid` int(10) unsigned default NULL COMMENT 'This is the displayid to change to while the event is active',
  `item1` int(10) unsigned default NULL COMMENT 'This is the id of equip slot 1 to change while the event is active',
  `item2` int(10) unsigned default NULL COMMENT 'This is the id of equip slot 2 to change while the event is active',
  `item3` int(10) unsigned default NULL COMMENT 'This is the id of equip slot 3 to change while the event is active',
  PRIMARY KEY  (`eventid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `events_creature`
--

LOCK TABLES `events_creature` WRITE;
/*!40000 ALTER TABLE `events_creature` DISABLE KEYS */;
/*!40000 ALTER TABLE `events_creature` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-03 14:49:58
