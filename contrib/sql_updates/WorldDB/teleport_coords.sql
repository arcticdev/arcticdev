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
-- Table structure for table `teleport_coords`
--

DROP TABLE IF EXISTS `teleport_coords`;
CREATE TABLE `teleport_coords` (
  `entry` int(16) NOT NULL default '0',
  `name` char(255) character set utf8 collate utf8_unicode_ci NOT NULL,
  `mapId` int(16) NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';

--
-- Dumping data for table `teleport_coords`
--

LOCK TABLES `teleport_coords` WRITE;
/*!40000 ALTER TABLE `teleport_coords` DISABLE KEYS */;
INSERT INTO `teleport_coords` VALUES (31,'Teleport: Goldshire',0,-9458.81,64.826,55.957,0),(33,'Teleport: Westfall',0,-9839.9,884.804,27.454,0),(34,'Teleport: Duskwood',0,-9973.92,-1633.17,26.94,0),(35,'Teleport: Elwynn',0,-9760.26,678.23,27.021,0),(427,'Teleport: Scarlet Monastery',0,2889.91,-811.148,160.332,0),(428,'Teleport: Moonbrook',0,-11025.2,1497.86,43.1953,0),(442,'Teleport: Northshire Abbey',0,-8914.38,-135.35,80.45,0),(444,'Teleport: Westfall Lighthouse',0,-11409.9,1968.42,10.4271,0),(445,'Teleport: Darkshire',0,-10413.9,-1136.88,24.1288,0),(446,'Teleport: Raven Hill Cemetary',0,-10531.2,296.656,30.9649,0),(1936,'Teleport: Anvilmar',0,-6133.84,383.79,395.54,0),(3561,'Teleport: Stormwind',0,-9005,869,29.621,0),(3562,'Teleport: Ironforge',0,-4613.35,-915.35,501.063,0),(3563,'Teleport: Undercity',0,1771,65,-46.3214,0),(3565,'Teleport: Darnassus',1,9657,2520,1331.65,0),(3566,'Teleport: Thunder Bluff',1,-964,282,111.562,0),(3567,'Teleport: Orgrimmar',1,1467,-4220,58.994,0),(4996,'[PH] Teleport to Orgrimmar',1,1676.21,-4315.29,61.5293,0),(4997,'[PH] Teleport to Booty Bay',0,-14319.3,442.7,22.94,0),(4998,'[PH] Teleport to Grom\'Gol',0,-12372.7,204,3.07,0),(4999,'[PH] Teleport to Ratchet',1,-994.248,-3830.1,7,0),(5000,'[PH] Teleport to Undercity',0,1586.48,239.562,-52.149,0),(6348,'[PH] Teleport to Menethil Harbor',0,-3761.54,-734.7,8.04,0),(6349,'[PH] Teleport to Auberdine',1,6426.77,398.89,10.96,0),(6483,'[PH] Teleport to Felwood',1,6200,-1035,387,0),(6484,'[PH] Teleport to Balthule',1,7245,-652,35,0),(6719,'[PH] Teleport to Theramore',1,-3717.96,-4406.17,23.12,0),(8735,'[PH] Teleport to Blackfathom Deeps',1,4127.5,867.8,9.69,0),(9268,'Teleport to Darnassus - Event',1,9951.52,2280.32,1341.39,0),(11362,'Teleport to Gnomeregan',0,-5183.1,602.77,409.11,0),(11409,'Teleport to Booty Bay',0,-14319.3,442.7,22.94,0),(12510,'Teleport to Azshara Tower',1,3778.6,-4612.2,227.254,0),(12520,'Teleport from Azshara Tower',1,3648,-4702,122,0),(12885,'Teleport to Razelikh',0,-11235,-2834,158,0),(13044,'Teleport to Ground',0,-11072,-2859,11,0),(13142,'Teleport to Razelikh',0,-11235,-2834,158,0),(17334,'Portal Effect: Stormwind',0,-9005,869,29.621,0),(44089,'Portal Effect: Ironforge',0,-4613.35,-915.35,501.063,0),(17608,'Portal Effect: Darnassus',1,9657,2520,1331.65,0),(17609,'Portal Effect: Orgrimmar',1,1467,-4220,58.994,0),(17610,'Portal Effect: Thunder Bluff',1,-964,282,111.562,0),(17611,'Portal Effect: Undercity',0,1771,65,-46.3214,0),(18960,'Teleport: Moonglade',1,7992,-2679,512.101,0),(21128,'Portal Effect: Maraudon',349,428,15,-112,0),(23442,'Everlook Transporter',1,6725.7,-4653.63,720.89,0),(23453,'Gnomish Transporter',1,-7168.33,-3839.9,8.68903,0),(28147,'Portal Effect: Karazhan',0,-11128.8,-2013.92,47.4312,0),(32268,'Portal Effect: Exodar',530,-4212.32,-11638.9,-98.9105,0),(32270,'Portal Effect: Silvermoon',530,10021.1,-7014.83,49.7176,0),(32271,'Teleport: Exodar',530,-4212.32,-11638.9,-98.9105,0),(32272,'Teleport: Silvermoon',530,10021.1,-7014.83,49.7176,0),(33690,'[A] Teleport to Shattarah',530,-1803.64,5408.89,-12.428,0),(33691,'Portal Effect: Shattarah',530,-1863.03,4998.05,-21.1847,0),(33728,'[A] Portal Effect: Shattrath',530,-1803.64,5408.89,-12.428,0),(35715,'[H] Teleport: Shattrath',530,-1924.8,5449.94,-12.4277,0),(35717,'Portal Effect: Shattarah',530,-1863.03,4998.05,-21.1847,0),(35718,'[H] Portal Effect: Shattrath',530,-1924.8,5449.94,-12.4277,0),(36890,'Area52 Transporter',530,3048.95,3685.96,142.409,0),(36941,'Toshley\'s Station Transporter',530,1907.32,5562.25,262.474,0),(44870,'Portal Effect: Sunwell Isle',530,12937.6,-6931.28,4.05783,0),(26373,'Lunar Invitation',1,7591.91,-2227,469.811,0),(31613,'Return to Temper',530,-3288.8,-12906.6,12.082,0),(41234,'Teleport: Black Temple',530,-3611.22,328.949,37.0534,0),(34448,'Duskwither Spire - To Top',530,9338.34,-7809.24,136.568,0),(34452,'Duskwither Spire - Bottom',530,9334.35,-7880.74,74.91,0),(25140,'Firewing Point - Top',530,-2263.21,3112.64,136.349,0),(29128,'Firewing Point - Top 2',530,-2260.33,3211.06,14.1116,0),(29129,'Firewing Point - Buttom',530,-2259.65,3114.53,25.017,0),(25650,'Falcon Watch - Buttom',530,-588.9,4070.8,93.8,0),(25652,'Falcon Watch - Top',530,-592.2,4070.2,143.3,0),(35376,'Orb of Translocation - Undercity',0,1805.82,334.01,70.3975,0),(35727,'Orb of Translocation - Silvermoon',530,10021.3,-7014.89,49.7177,0),(45367,'Suns Reach Sanctum - Top',530,12791.6,-6891.95,31.1053,0),(45370,'Suns Reach Sanctum - Bottom',530,12782.5,-6879.06,23.0944,0),(42953,'Teleport to violet stand',571,5724.62,1013.17,174.48,0),(53360,'Teleport to Dalaran',571,5807.75,588.347,661.505,0),(59901,'Portal Effect: Caverns Of Time',1,-8164.8,-4768.5,34.3,0),(61419,'Portal Effect: The purple parlor',571,5848.48,853.706,843.182,0),(61420,'Portal Effect: Violet Citadel',571,5819.26,829.774,680.22,0),(53141,'Portal Effect: Dalaran',571,5807.75,588.347,661.505,0),(25649,'Translocate to Undercity',0,1805,327,70.5,0),(35730,'Translocate to Silvermoon City',530,10021,-7014,50,0),(53098,'Portal Effect: Acherus',609,2400.03,-5635,377.017,0),(53822,'Death Gate',0,2359.64,-5662.41,377.017,0),(54406,'Teleport to Dalaran',571,5807.75,588.347,661.505,0),(53140,'Teleport to Dalaran',571,5807.75,588.347,661.505,0),(49362,'Portal Effect: Theramore',1,-3729.36,-4421.41,31.4474,0),(49363,'Portal Effect: Stonard',0,-10487.3,-3256.87,40.8964,0),(50135,'Teleport: Amber Ledge',571,3605.14,6018.22,138.615,4.215);
/*!40000 ALTER TABLE `teleport_coords` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-03 14:50:28
