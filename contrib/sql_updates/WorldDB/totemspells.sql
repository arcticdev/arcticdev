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
-- Table structure for table `totemspells`
--

DROP TABLE IF EXISTS `totemspells`;
CREATE TABLE `totemspells` (
  `spell` int(10) unsigned NOT NULL default '0',
  `castspell1` int(10) unsigned NOT NULL default '0',
  `castspell2` int(10) unsigned NOT NULL default '0',
  `castspell3` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

--
-- Dumping data for table `totemspells`
--

LOCK TABLES `totemspells` WRITE;
/*!40000 ALTER TABLE `totemspells` DISABLE KEYS */;
INSERT INTO `totemspells` VALUES (1535,8443,0,0),(2062,33663,0,0),(2484,3600,0,0),(2894,32982,0,0),(3599,3606,0,0),(3738,2895,0,0),(5394,5672,0,0),(5675,5677,0,0),(5730,5728,0,0),(6363,6350,0,0),(6364,6351,0,0),(6365,6352,0,0),(6375,6371,0,0),(6377,6372,0,0),(6390,6397,0,0),(6391,6398,0,0),(6392,6399,0,0),(6495,0,0,0),(8071,8072,0,0),(8075,8076,0,0),(8143,8146,0,0),(8154,8156,0,0),(8155,8157,0,0),(8160,8162,0,0),(8161,8163,0,0),(8166,8167,0,0),(8170,8172,0,0),(8177,8178,0,0),(8181,8182,0,0),(8184,8185,0,0),(8187,8188,0,0),(8190,8187,0,0),(8227,8230,0,0),(8249,8250,0,0),(8262,0,0,0),(8264,8266,0,0),(8376,8378,0,0),(8498,8504,0,0),(8499,8505,0,0),(8512,8514,0,0),(8835,8836,0,0),(10406,10403,0,0),(10407,10404,0,0),(10408,10405,0,0),(10427,10425,0,0),(10428,10426,0,0),(10437,10435,0,0),(10438,10436,0,0),(10442,10441,0,0),(10462,10460,0,0),(10463,10461,0,0),(10478,10476,0,0),(10479,10477,0,0),(10495,10491,0,0),(10496,10493,0,0),(10497,10494,0,0),(10526,10521,0,0),(10537,10534,0,0),(10538,10535,0,0),(10585,10579,0,0),(10586,10580,0,0),(10587,10581,0,0),(10595,10596,0,0),(10600,10598,0,0),(10601,10599,0,0),(10613,10607,0,0),(10614,10611,0,0),(10627,10626,0,0),(11314,11310,0,0),(11315,11311,0,0),(12506,12504,0,0),(15038,0,0,0),(15107,15108,0,0),(15111,15109,0,0),(15112,15110,0,0),(15786,3600,0,0),(15787,15789,0,0),(15867,0,0,0),(16190,39610,0,0),(16387,15036,0,0),(17354,17355,0,0),(17359,17360,0,0),(18975,18978,0,0),(22047,0,0,0),(23419,11311,0,0),(23420,10405,0,0),(23422,10461,0,0),(23423,10611,0,0),(25359,25360,0,0),(25361,25362,0,0),(25508,25506,0,0),(25509,25507,0,0),(25525,25513,0,0),(25528,25527,0,0),(25533,25530,0,0),(25546,25538,0,0),(25547,25539,0,0),(25552,25550,0,0),(25555,25554,0,0),(25557,25554,0,0),(25560,25559,0,0),(25563,25562,0,0),(25567,25566,0,0),(25570,25569,0,0),(25574,25573,0,0),(25577,25576,0,0),(25585,25579,0,0),(25587,25580,0,0),(25908,25909,0,0),(27621,10611,0,0),(27623,11307,0,0),(30706,57658,0,0),(57622,57621,0,0),(58643,58646,0,0),(58751,58752,0,0),(58753,58754,0,0),(58737,58738,0,0),(58739,58740,0,0),(58741,58742,0,0),(58745,58744,0,0),(58746,58748,0,0),(58749,58750,0,0),(58731,58732,0,0),(58734,58735,0,0),(61649,61651,0,0),(61657,61660,0,0),(58580,25513,0,0),(58581,25513,0,0),(58582,25513,0,0),(58699,58700,0,0),(58703,58701,0,0),(58704,58702,0,0),(58755,58763,0,0),(58756,58764,0,0),(58757,58765,0,0),(57720,57660,0,0),(57721,57662,0,0),(57722,57663,0,0),(58771,58775,0,0),(58773,58776,0,0),(58774,58777,0,0);
/*!40000 ALTER TABLE `totemspells` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-03 14:50:30
