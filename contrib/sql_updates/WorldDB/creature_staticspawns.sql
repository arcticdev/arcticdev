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
-- Table structure for table `creature_staticspawns`
--

DROP TABLE IF EXISTS `creature_staticspawns`;
CREATE TABLE `creature_staticspawns` (
  `id` int(30) NOT NULL auto_increment,
  `entry` int(30) NOT NULL,
  `map` int(11) NOT NULL default '0',
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `o` float NOT NULL,
  `movetype` int(11) NOT NULL default '0',
  `displayid` int(11) NOT NULL,
  `factionid` int(11) NOT NULL default '0',
  `flags` int(30) NOT NULL default '0',
  `bytes` int(30) NOT NULL default '0',
  `bytes1` int(30) NOT NULL default '0',
  `bytes2` int(30) NOT NULL default '0',
  `emote_state` int(11) NOT NULL default '0',
  `channel_spell` int(30) NOT NULL default '0',
  `channel_target_sqlid_go` int(30) NOT NULL default '0',
  `channel_target_sqlid_creature` int(30) NOT NULL default '0',
  `MountedDisplayID` int(11) NOT NULL default '0',
  `Phase` int(11) NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Spawn System';

--
-- Dumping data for table `creature_staticspawns`
--

LOCK TABLES `creature_staticspawns` WRITE;
/*!40000 ALTER TABLE `creature_staticspawns` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_staticspawns` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-05 21:30:19
