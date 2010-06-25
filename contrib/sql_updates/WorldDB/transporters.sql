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
-- Table structure for table `transporters`
--

DROP TABLE IF EXISTS `transporters`;
CREATE TABLE `transporters` (
  `entry` int(10) unsigned NOT NULL,
  `creature_entry` int(10) default NULL COMMENT 'If left NULL no creature will be added.',
  `creature_x` float default NULL,
  `creature_y` float default NULL,
  `creature_z` float default NULL,
  `creature_o` float default NULL,
  `transport_info` text
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `transporters`
--

LOCK TABLES `transporters` WRITE;
/*!40000 ALTER TABLE `transporters` DISABLE KEYS */;
INSERT INTO `transporters` VALUES (176310,0,0,0,0,0,'The Bravery - Stormwind and Auberdine'),(181689,0,0,0,0,0,'Cloudkisser - Undercity and Vengeance Landing'),(181646,0,0,0,0,0,'Elune`s Blessing - Azuremyst and Auberdine'),(177233,0,0,0,0,0,'Feathermoon Ferry - Forgotton Coast and Feathermoon Stronghold'),(188511,0,0,0,0,0,'Green Island - Unu`pe Turtle Boat'),(181688,0,0,0,0,0,'Icebreaker - Valgarde and Menethil'),(190536,0,0,0,0,0,'IcebreakerINSERT INTO `transporters` VALUES (Stormwind`s Pride) - Valiance Keep and Stormwind'),(175080,0,0,0,0,0,'The Iron Eagle - Grom`Gol Base Camp and Orgrimmar'),(176231,0,0,0,0,0,'The Lady Mehley - Menethil Harbor and Theramore Isle'),(20808,0,0,0,0,0,'The Maiden`s Fancy - Ratchet and Booty Bay'),(186238,0,0,0,0,0,'The Mighty Wind - Orgrimmar and Warsong Hold'),(176244,0,0,0,0,0,'Moonspray - Teldrassil and Auberdine'),(192241,0,0,0,0,0,'Orgrim`s Hammer'),(176495,0,0,0,0,0,'The Purple Princess - Grom`Gol Base Camp and Undercity'),(187038,0,0,0,0,0,'Sister Mercy - Pirate Boat'),(192242,0,0,0,0,0,'The Skybreaker - Fizzcrank Airstrip'),(164871,0,0,0,0,0,'The Thundercaller - Orgrimmar and Undercity'),(187568,0,0,0,0,0,'Walker of Waves - Moa`ki Harbor Turtle Boat'),(186371,0,0,0,0,0,'Stolen Zeppelin');
/*!40000 ALTER TABLE `transporters` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-07-31 10:21:10
