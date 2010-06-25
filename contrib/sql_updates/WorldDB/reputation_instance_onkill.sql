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
-- Table structure for table `reputation_instance_onkill`
--

DROP TABLE IF EXISTS `reputation_instance_onkill`;
CREATE TABLE `reputation_instance_onkill` (
  `mapid` int(30) NOT NULL,
  `mob_rep_reward` int(30) NOT NULL,
  `mob_rep_reward_heroic` int(30) NOT NULL,
  `mob_rep_limit` int(30) NOT NULL,
  `mob_rep_limit_heroic` int(30) NOT NULL,
  `boss_rep_reward` int(30) NOT NULL,
  `boss_rep_reward_heroic` int(30) NOT NULL,
  `boss_rep_limit` int(30) NOT NULL,
  `boss_rep_limit_heroic` int(30) NOT NULL,
  `faction_change_alliance` int(30) NOT NULL,
  `faction_change_horde` int(30) NOT NULL,
  PRIMARY KEY  (`mapid`,`mob_rep_reward`,`boss_rep_reward`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

--
-- Dumping data for table `reputation_instance_onkill`
--

LOCK TABLES `reputation_instance_onkill` WRITE;
/*!40000 ALTER TABLE `reputation_instance_onkill` DISABLE KEYS */;
INSERT INTO `reputation_instance_onkill` VALUES (564,15,15,42000,42000,250,250,42000,42000,1012,1012),(556,9,9,12000,12000,90,90,12000,12000,1011,1011),(558,9,9,12000,12000,90,90,12000,12000,1011,1011),(555,12,12,42000,42000,120,120,42000,42000,1011,1011),(534,12,12,42000,42000,375,375,42000,42000,990,990),(269,0,0,42000,42000,120,120,42000,42000,989,989),(560,8,8,42000,42000,150,150,42000,42000,989,989),(532,15,15,42000,42000,250,250,42000,42000,967,967),(540,10,10,42000,42000,150,150,42000,42000,946,947),(543,5,5,12000,12000,50,50,12000,12000,946,947),(542,1,1,12000,12000,50,50,12000,12000,946,947),(545,10,10,42000,42000,120,120,42000,42000,942,942),(547,5,5,12000,12000,70,70,12000,12000,942,942),(546,12,12,12000,12000,70,70,12000,12000,942,942),(554,12,12,42000,42000,120,120,42000,42000,935,935),(552,12,12,42000,42000,120,120,42000,42000,935,935),(553,12,12,42000,42000,120,120,42000,42000,935,935),(557,7,7,42000,42000,70,70,42000,42000,933,933),(531,100,100,5999,5999,0,0,5999,5999,910,910),(509,0,0,5999,5999,50,50,5999,5999,910,910),(329,10,10,42000,42000,100,100,42000,42000,529,529),(289,10,10,42000,42000,100,100,42000,42000,529,529),(309,5,5,42000,42000,100,100,42000,42000,270,270);
/*!40000 ALTER TABLE `reputation_instance_onkill` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-03 14:50:24
