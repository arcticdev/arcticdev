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
-- Table structure for table `randomcardcreation`
--

DROP TABLE IF EXISTS `randomcardcreation`;
CREATE TABLE `randomcardcreation` (
  `SpellId` int(10) unsigned NOT NULL default '0',
  `ItemId0` int(10) unsigned NOT NULL default '0',
  `ItemId1` int(10) unsigned NOT NULL default '0',
  `ItemId2` int(10) unsigned NOT NULL default '0',
  `ItemId3` int(10) unsigned NOT NULL default '0',
  `ItemId4` int(10) unsigned NOT NULL default '0',
  `ItemId5` int(10) unsigned NOT NULL default '0',
  `ItemId6` int(10) unsigned NOT NULL default '0',
  `ItemId7` int(10) unsigned NOT NULL default '0',
  `ItemId8` int(10) unsigned NOT NULL default '0',
  `ItemId9` int(10) unsigned NOT NULL default '0',
  `ItemId10` int(10) unsigned NOT NULL default '0',
  `ItemId11` int(10) unsigned NOT NULL default '0',
  `ItemId12` int(10) unsigned NOT NULL default '0',
  `ItemId13` int(10) unsigned NOT NULL default '0',
  `ItemId14` int(10) unsigned NOT NULL default '0',
  `ItemId15` int(10) unsigned NOT NULL default '0',
  `ItemId16` int(10) unsigned NOT NULL default '0',
  `ItemId17` int(10) unsigned NOT NULL default '0',
  `ItemId18` int(10) unsigned NOT NULL default '0',
  `ItemId19` int(10) unsigned NOT NULL default '0',
  `ItemId20` int(10) unsigned NOT NULL default '0',
  `ItemId21` int(10) unsigned NOT NULL default '0',
  `ItemId22` int(10) unsigned NOT NULL default '0',
  `ItemId23` int(10) unsigned NOT NULL default '0',
  `ItemId24` int(10) unsigned NOT NULL default '0',
  `ItemId25` int(10) unsigned NOT NULL default '0',
  `ItemId26` int(10) unsigned NOT NULL default '0',
  `ItemId27` int(10) unsigned NOT NULL default '0',
  `ItemId28` int(10) unsigned NOT NULL default '0',
  `ItemId29` int(10) unsigned NOT NULL default '0',
  `ItemId30` int(10) unsigned NOT NULL default '0',
  `ItemId31` int(10) unsigned NOT NULL default '0',
  `ItemCount` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`SpellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `randomcardcreation`
--

LOCK TABLES `randomcardcreation` WRITE;
/*!40000 ALTER TABLE `randomcardcreation` DISABLE KEYS */;
INSERT INTO `randomcardcreation` VALUES (59480,37145,37147,37159,37160,37161,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5),(59491,44143,44154,44155,44156,44157,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5),(48247,37140,37143,37156,37157,37158,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5),(59487,44165,44144,44145,44146,44147,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5),(44317,31882,31901,31910,31892,31883,31902,31911,31893,31884,31903,31912,31894,31885,31904,31913,31895,31886,31905,31915,31896,31887,31906,31916,31898,31888,31908,31917,31899,31889,31909,31918,31900,32),(59502,19227,19236,19233,19232,19235,19234,19231,19230,19268,19275,19272,19271,19274,19273,19270,19269,19276,19284,19281,19280,19283,19282,19279,19278,19258,19265,19262,19261,19264,19263,19260,19259,32),(59504,44277,44285,44281,44280,44284,44282,44279,44278,44286,44293,44290,44289,44292,44291,44288,44287,44268,44275,44272,44271,44274,44273,44270,44269,44260,44267,44264,44263,44266,44265,44262,44261,32);
/*!40000 ALTER TABLE `randomcardcreation` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-03 14:50:23
