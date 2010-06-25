-- MySQL dump 10.11
--
-- Host: 192.168.1.4    Database: ascent_world
-- ------------------------------------------------------
-- Server version	5.0.51a

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
-- Table structure for table `worldmap_info`
--

DROP TABLE IF EXISTS `worldmap_info`;
CREATE TABLE `worldmap_info` (
  `entry` int(10) unsigned NOT NULL default '0',
  `screenid` int(10) unsigned default '0',
  `type` int(10) unsigned default '0',
  `maxplayers` int(10) unsigned default '0',
  `maxplayers_heroic` int(10) NOT NULL default '0',
  `minlevel` int(10) unsigned default '1',
  `repopx` float default '0',
  `repopy` float default '0',
  `repopz` float default '0',
  `repopentry` int(10) unsigned default '0',
  `area_name` varchar(100) default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `cooldown` int(10) unsigned NOT NULL default '0',
  `lvl_mod_a` int(10) unsigned NOT NULL default '0',
  `required_quest` int(10) unsigned NOT NULL default '0',
  `required_item` int(10) unsigned NOT NULL default '0',
  `heroic_keyid_1` int(30) NOT NULL default '0',
  `heroic_keyid_2` int(30) NOT NULL default '0',
  `viewingDistance` float NOT NULL default '80',
  `required_checkpoint` int(30) NOT NULL default '0',
  `collision` int(10) NOT NULL default '1',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';

--
-- Dumping data for table `worldmap_info`
--

LOCK TABLES `worldmap_info` WRITE;
/*!40000 ALTER TABLE `worldmap_info` DISABLE KEYS */;
INSERT INTO `worldmap_info` VALUES (0,0,0,0,0,1,0,0,0,0,'Eastern Kingdoms',1,1,0,0,0,0,0,80,0,1),(1,1,0,0,0,1,0,0,0,1,'Kalimdor',1,1,0,0,0,0,0,80,0,1),(13,13,0,0,0,1,0,0,0,0,'Testing',1,1,0,0,0,0,0,195,0,1),(25,25,0,0,0,1,0,0,0,0,'Scott Test',1,1,0,0,0,0,0,195,0,1),(29,29,2,0,0,1,0,0,0,0,'CashTest',1,1,0,0,0,0,0,195,0,1),(30,30,3,80,80,51,0,0,0,0,'Alterac Valley',3,360000,0,0,0,0,0,195,0,1),(33,204,2,5,5,14,-230.989,1571.57,78.8909,0,'Shadowfang Keep',3,360000,0,0,0,0,0,195,0,1),(34,34,2,5,5,15,-8762.38,848.01,89.8765,0,'The Stockades',3,360000,0,0,0,0,0,195,0,1),(35,194,0,5,5,1,-8762.48,848.049,0,0,'<unused>StormwindPrison',0,360000,0,0,0,0,0,195,0,1),(36,36,2,5,5,10,-11207.8,1681.15,24.6245,0,'Deadmines',3,360000,0,0,0,0,0,195,0,1),(37,37,0,0,0,1,0,0,0,0,'Azshara Crater',1,1,0,0,0,0,0,195,0,1),(42,42,0,0,0,1,0,0,0,0,'Collin\'s Test',1,1,0,0,0,0,0,195,0,1),(43,143,2,5,5,10,-751.131,-2209.24,21.5403,1,'Wailing Caverns',3,360000,0,0,0,0,0,195,0,1),(44,44,2,0,0,1,2892.41,-811.241,0,0,'<unused> Monastery',1,1,0,0,0,0,0,195,0,1),(47,188,2,5,5,15,-4459.45,-1660.21,86.1095,1,'Razorfen Kraul',3,360000,0,0,0,0,0,195,0,1),(48,196,2,5,5,19,4249.12,748.387,-23.0632,1,'Blackfathom Deeps',3,360000,0,0,0,0,0,195,0,1),(70,144,2,5,5,30,-6060.18,-2955,266.91,0,'Uldaman',3,360000,0,0,0,0,0,195,0,1),(90,193,2,5,5,15,-5162.66,931.599,260.554,0,'Gnomeregan',3,360000,0,0,0,0,0,195,0,1),(109,109,2,5,5,35,-10170.1,-3995.97,-109.194,0,'Sunken Temple',3,360000,0,0,0,0,0,195,0,1),(129,145,2,5,5,25,-4662.88,-2535.87,86.9671,1,'Razorfen Downs',3,360000,0,0,0,0,0,195,0,1),(169,169,0,100,100,1,0,0,132.213,169,'Emerald Dream',1,360000,0,0,0,0,0,195,0,1),(189,42,2,5,5,20,2892.24,-811.264,160.333,0,'Scarlet Monastery',3,360000,0,0,0,0,0,195,0,1),(209,146,2,5,5,35,-6790.58,-2891.28,15.1063,1,'Zul\'Farrak',3,360000,0,0,0,0,0,195,0,1),(229,189,2,10,10,45,-7522.53,-1233.04,287.243,0,'Blackrock Spire',3,360000,0,0,0,0,0,195,0,1),(230,103,2,5,5,40,-7178.09,-928.639,170.206,0,'Blackrock Depths',3,360000,0,0,0,0,0,195,0,1),(249,61,1,40,40,60,-4753.31,-3752.42,53.4317,1,'Onyxia\'s Lair',3,432000,0,0,16309,0,0,195,0,1),(269,269,4,5,5,66,-8750.83,-4193.51,-210.158,1,'The Black Morass',9,360000,0,0,0,30635,0,195,0,1),(289,102,2,5,5,45,1274.78,-2552.56,85.3994,0,'Scholomance',3,360000,0,0,0,0,0,195,0,1),(309,161,1,20,20,51,-11916.1,-1224.58,96.1502,0,'Zul\'Gurub',3,259200,0,0,0,0,0,195,0,1),(329,101,2,5,5,45,3392.32,-3378.48,112.01,0,'Stratholme',3,360000,0,0,0,0,0,195,0,1),(349,81,2,5,5,30,-1432.7,2924.98,85.491,1,'Maraudon',3,360000,0,0,0,0,0,195,0,1),(369,369,0,0,0,1,-8349.22,517.348,0,0,'Deeprun Tram',1,1,0,0,0,0,0,195,0,1),(389,195,2,5,5,8,1816.76,-4423.37,-10.4478,1,'Ragefire Chasm',3,360000,0,0,0,0,0,195,0,1),(409,192,1,40,40,58,-7510.56,-1036.7,180.912,0,'Molten Core',3,604800,0,7848,0,0,0,195,0,1),(429,82,2,5,5,45,-3908.03,1130,161.214,1,'Dire Maul',3,360000,0,0,0,0,0,195,0,1),(449,181,0,0,0,1,0,0,87.8052,0,'Alliance Military Barracks',1,1,0,0,0,0,0,195,0,1),(450,182,0,0,0,1,0,0,56.1557,0,'Horde Military Barracks',1,1,0,0,0,0,0,195,0,1),(451,451,0,0,0,1,0,0,0,0,'Development Land',25,1,0,0,0,0,0,195,0,1),(469,141,1,40,40,60,-7663.41,-1218.67,287.798,0,'Blackwing Lair',3,604800,0,7761,0,0,0,195,0,1),(489,489,3,20,20,10,0,0,0,0,'Warsong Gulch',0,360000,0,0,0,0,0,195,0,1),(509,184,1,20,20,60,-8114.46,1526.37,6.1904,1,'Ruins of Ahn\'Qiraj',3,259200,0,0,0,0,0,195,0,1),(529,529,3,30,30,20,0,0,0,0,'Arathi Basin ',0,360000,0,0,0,0,0,195,0,1),(530,530,0,0,0,1,0,0,0,0,'Outland',9,360000,0,0,0,0,0,80,0,1),(531,531,1,40,40,60,-8111.72,1526.79,129.861,1,'Ahn\'Qiraj Temple',3,604800,0,0,0,0,0,195,0,1),(532,532,1,10,10,70,-11110.4,-2004.07,49.3307,0,'Karazhan',3,604800,0,0,0,0,0,195,0,1),(533,533,1,40,40,80,3005.87,-3435.01,293.882,533,'Naxxramas',3,86400,0,0,0,0,0,195,0,1),(534,534,1,25,25,70,-8178.51,-4182.05,-168.4,1,'The Battle for Mount Hyjal',3,604800,0,0,0,0,0,195,0,1),(540,540,4,5,5,55,-306.758,3064.44,-3.73108,530,'Hellfire Citadel: The Shattered Halls',3,360000,0,0,0,30637,30622,195,0,1),(542,542,4,5,5,55,-295.419,3151.99,31.7029,530,'Hellfire Citadel: The Blood Furnace',3,360000,0,0,0,30637,30622,195,0,1),(543,543,4,5,5,55,-360.05,3067.9,-15.0364,530,'Hellfire Citadel: Ramparts',3,360000,0,0,0,30637,30622,195,0,1),(544,544,1,25,25,70,-330.234,3106.64,-116.502,530,'Magtheridon\'s Lair',3,604800,0,0,0,0,0,195,0,1),(545,545,4,5,5,55,764.219,6915.08,-80.5606,530,'Coilfang: The Steamvault',3,360000,0,0,0,30623,0,195,0,1),(546,546,4,5,5,55,764.628,6768.07,-72.0662,530,'Coilfang: The Underbog',3,360000,0,0,0,30623,0,195,0,1),(547,547,4,5,5,55,742.158,7011.33,-73.0743,530,'Coilfang: The Slave Pens',3,360000,0,0,0,30623,0,195,0,1),(548,548,1,25,25,70,775.786,6865.24,-65.9414,530,'Coilfang: Serpentshrine Cavern',3,604800,0,0,0,0,0,195,0,1),(550,550,1,25,25,70,0,0,184.643,0,'Tempest Keep',3,604800,0,0,0,0,0,195,0,1),(552,552,4,5,5,68,0,0,505.559,0,'Tempest Keep: The Arcatraz',3,360000,0,0,0,30634,0,195,0,1),(553,553,4,5,5,68,0,0,179.541,0,'Tempest Keep: The Botanica',3,360000,0,0,0,30634,0,195,0,1),(554,554,4,5,5,68,0,0,252.159,0,'Tempest Keep: The Mechanar',3,360000,0,0,0,30634,0,195,0,1),(555,555,4,5,5,65,-3640.69,4943.16,-101.047,530,'Auchindoun: Shadow Labyrinth',3,360000,0,0,0,30633,0,195,0,1),(556,556,4,5,5,55,-3361.86,4665.59,-101.048,530,'Auchindoun: Sethekk Halls',3,360000,0,0,0,30633,0,195,0,1),(557,557,4,5,5,55,-3089.52,4942.76,-101.048,530,'Auchindoun: Mana-Tombs',3,360000,0,0,0,30633,0,195,0,1),(558,558,4,5,5,55,-3363.44,5156.46,-101.048,530,'Auchindoun: Auchenai Crypts',3,360000,0,0,0,30633,0,195,0,1),(559,559,3,5,5,10,0,0,0,0,'Nagrand Arena',0,360000,0,0,0,0,0,195,0,1),(560,560,4,5,5,66,-8309.81,-4061.51,207.924,1,'Old Hillsbrad Foothills',3,360000,0,0,0,30635,0,195,0,1),(562,562,3,10,10,10,0,0,0,0,'Blade\'s Edge Arena',0,360000,0,0,0,0,0,195,0,1),(564,564,1,25,25,70,-3644.53,317.294,36.1671,530,'Black Temple',3,604800,0,0,0,0,0,195,0,1),(565,565,1,25,25,70,3525.45,5144.15,2.46332,530,'Gruul\'s Lair',3,604800,0,0,0,0,0,195,0,1),(566,566,3,30,30,61,0,0,0,0,'Eye of the Storm',0,360000,0,0,0,0,0,195,0,1),(568,568,1,10,10,70,6851.02,-7989.71,42.8081,530,'Zul\'Aman',3,259200,0,0,0,0,0,195,0,1),(571,571,0,0,0,1,0,0,0,0,'Northrend',25,360000,0,0,0,0,0,80,0,1),(572,572,3,5,5,10,0,0,0,0,'Ruins of Lordaeron',0,360000,0,0,0,0,0,195,0,1),(573,573,0,0,0,1,0,0,0,0,'ExteriorTest',24,360000,0,0,0,0,0,80,0,1),(574,574,4,5,5,70,1211.76,-4868.42,0,571,'Utgarde Keep',27,360000,0,0,0,0,0,80,0,1),(575,575,4,5,5,70,1232.41,-4860.95,0,571,'Utgarde Pinnacle',27,360000,0,0,0,0,0,80,0,1),(576,576,4,5,5,70,3899.93,6985.44,0,571,'The Nexus',27,360000,0,0,0,0,0,80,0,1),(578,578,4,5,5,70,3865.92,6983.94,0,571,'The Oculus',27,360000,0,0,0,0,0,80,0,1),(580,580,1,25,25,70,12551.8,-6774.57,15.076,530,'The Sunwell',3,604800,0,0,0,0,0,195,0,1),(582,582,0,0,0,1,0,0,0,0,'Transport: Ruttheran to Auberdine',1,1,0,0,0,0,0,195,0,1),(584,584,0,0,0,1,0,0,0,0,'Transport: Menethil to Theramore',1,1,0,0,0,0,0,195,0,1),(585,585,4,5,5,70,12881.9,-7343.09,-2.79915,530,'Magisters\' Terrace',3,360000,0,0,0,0,0,195,0,1),(586,586,0,0,0,1,0,0,0,0,'Transport: Exodar to Auberdine',1,1,0,0,0,0,0,195,0,1),(587,587,0,0,0,1,0,0,0,0,'Transport: Feathermoon Ferry',1,1,0,0,0,0,0,195,0,1),(588,589,0,0,0,1,0,0,0,0,'Transport: Menethil to Auberdine',1,1,0,0,0,0,0,195,0,1),(589,588,0,0,0,1,0,0,0,0,'Transport: Orgrimmar to GromGol',1,1,0,0,0,0,0,195,0,1),(590,590,0,0,0,1,0,0,0,0,'Transport: GromGol to Undercity',1,1,0,0,0,0,0,195,0,1),(591,591,0,0,0,1,0,0,0,0,'Transport: Undercity to Orgrimmar',1,1,0,0,0,0,0,195,0,1),(592,592,0,0,0,1,0,0,0,0,'Transport: Borean Tundra Test',0,360000,0,0,0,0,0,80,0,1),(593,593,0,0,0,1,0,0,0,0,'Transport: Booty Bay to Ratchet',1,1,0,0,0,0,0,195,0,1),(594,594,0,0,0,1,0,0,0,0,'Transport: Howling Fjord Sister Mercy (Quest)',24,360000,0,0,0,0,0,80,0,1),(595,595,4,5,5,70,-8756.09,-4457.42,0,1,'The Culling of Stratholme',27,360000,0,0,0,0,0,80,0,1),(596,596,0,0,0,1,0,0,0,0,'Transport: Naglfar',24,360000,0,0,0,0,0,80,0,1),(597,597,0,0,0,1,0,0,0,0,'Craig Test',0,360000,0,0,0,0,0,80,0,1),(598,598,4,0,0,1,0,0,0,0,'Sunwell Fix (Unused)',3,360000,0,0,0,0,0,195,0,1),(599,599,4,5,5,70,8921.79,-966.806,0,571,'Halls of Stone',27,360000,0,0,0,0,0,80,0,1),(600,600,4,5,5,70,4774.58,-2023.05,0,571,'Drak\'Tharon Keep',27,360000,0,0,0,0,0,80,0,1),(601,601,4,5,5,70,3672.22,2171.28,0,571,'Azjol-Nerub',27,360000,0,0,0,0,0,80,0,1),(602,602,4,5,5,70,9185.09,-1386.79,0,571,'Halls of Lightning',27,360000,0,0,0,0,0,80,0,1),(603,603,4,10,10,1,0,0,0,0,'Ulduar',27,360000,0,0,0,0,0,4000,0,1),(604,604,4,5,5,70,6708.73,-4654.9,0,571,'Gundrak',27,360000,0,0,0,0,0,80,0,1),(605,605,0,0,0,1,0,0,0,0,'Development Land (non-weighted textures)',0,360000,0,0,0,0,0,80,0,1),(606,606,0,0,0,1,0,0,0,0,'QA and DVD',24,360000,0,0,0,0,0,80,0,1),(607,607,3,30,30,71,0,0,0,0,'Strand of the Ancients',24,360000,0,0,0,0,0,80,0,1),(608,608,4,5,5,70,5689.49,498.047,0,571,'Violet Hold',27,360000,0,0,0,0,0,80,0,1),(609,609,0,0,0,1,0,0,0,0,'Ebon Hold',24,360000,0,0,0,0,0,80,0,1),(610,610,0,0,0,1,0,0,0,0,'Transport: Tirisfal to Vengeance Landing',0,360000,0,0,0,0,0,80,0,1),(612,612,0,0,0,1,0,0,0,0,'Transport: Menethil to Valgarde',0,360000,0,0,0,0,0,80,0,1),(613,613,0,0,0,1,0,0,0,0,'Transport: Orgrimmar to Warsong Hold',0,360000,0,0,0,0,0,80,0,1),(614,614,0,0,0,1,0,0,0,0,'Transport: Stormwind to Valiance Keep',0,360000,0,0,0,0,0,80,0,1),(615,615,1,0,0,78,3438.15,260.401,0,571,'The Obsidian Sanctum',27,86400,0,0,0,0,0,80,0,1),(616,616,1,0,0,78,3869.98,6984.33,0,571,'The Eye of Eternity',27,86400,0,0,0,0,0,80,0,1),(617,617,3,10,10,10,0,0,0,0,'Dalaran Sewers',0,360000,0,0,0,0,0,80,0,1),(618,618,3,10,10,10,0,0,0,0,'The Ring of Valor',0,360000,0,0,0,0,0,80,0,1),(619,619,4,5,5,70,3641.46,2032.06,0,571,'Ahn\'kahet: The Old Kingdom',27,360000,0,0,0,0,0,80,0,1),(620,620,0,0,0,1,0,0,0,0,'Transport: Moa\'ki to Unu\'pe',24,360000,0,0,0,0,0,80,0,1),(621,621,0,0,0,1,0,0,0,0,'Transport: Moa\'ki to Kamagua',24,360000,0,0,0,0,0,80,0,1),(622,622,0,0,0,1,0,0,0,0,'Transport: Orgrim\'s Hammer',24,360000,0,0,0,0,0,80,0,1),(623,623,0,0,0,1,0,0,0,0,'Transport: The Skybreaker',24,360000,0,0,0,0,0,80,0,1),(624,624,1,0,0,78,5488.12,2840.33,0,571,'Wintergrasp Raid',27,86400,0,0,0,0,0,80,0,1);
/*!40000 ALTER TABLE `worldmap_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-17 15:31:18
