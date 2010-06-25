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
-- Table structure for table `playercreateinfo_skills`
--

DROP TABLE IF EXISTS `playercreateinfo_skills`;
CREATE TABLE `playercreateinfo_skills` (
  `indexid` tinyint(3) unsigned NOT NULL default '0',
  `skillid` int(10) unsigned NOT NULL default '0',
  `level` int(10) unsigned NOT NULL default '0',
  `maxlevel` int(10) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Player System';

--
-- Dumping data for table `playercreateinfo_skills`
--

LOCK TABLES `playercreateinfo_skills` WRITE;
/*!40000 ALTER TABLE `playercreateinfo_skills` DISABLE KEYS */;
INSERT INTO `playercreateinfo_skills` VALUES (1,183,5,5),(1,754,5,5),(1,433,1,1),(1,98,300,300),(1,415,1,1),(1,95,1,5),(1,43,1,5),(1,26,5,5),(1,44,1,5),(1,413,1,1),(1,414,1,1),(1,54,1,5),(1,162,1,5),(2,172,1,5),(2,183,5,5),(2,109,300,300),(2,433,1,1),(2,125,5,5),(2,415,1,1),(2,95,1,5),(2,43,1,5),(2,26,5,5),(2,44,1,5),(2,413,1,1),(2,414,1,1),(2,162,1,5),(3,172,1,5),(3,183,5,5),(3,433,1,1),(3,98,300,300),(3,415,1,1),(3,95,1,5),(3,26,5,5),(3,44,1,5),(3,101,5,5),(3,111,300,300),(3,413,1,1),(3,414,1,1),(3,54,1,5),(3,162,1,5),(4,173,1,5),(4,183,5,5),(4,433,1,1),(4,98,300,300),(4,415,1,1),(4,95,1,5),(4,43,1,5),(4,26,5,5),(4,113,300,300),(4,413,1,1),(4,414,1,1),(4,54,1,5),(4,126,5,5),(4,162,1,5),(5,173,1,5),(5,183,5,5),(5,220,5,5),(5,109,300,300),(5,433,1,1),(5,415,1,1),(5,673,300,300),(5,95,1,5),(5,43,1,5),(5,55,1,5),(5,26,5,5),(5,413,1,1),(5,414,1,1),(5,162,1,5),(6,183,5,5),(6,109,300,300),(6,124,5,5),(6,433,1,1),(6,415,1,1),(6,95,1,5),(6,26,5,5),(6,44,1,5),(6,115,300,300),(6,160,1,5),(6,413,1,1),(6,414,1,1),(6,54,1,5),(6,162,1,5),(7,173,1,5),(7,183,5,5),(7,433,1,1),(7,98,300,300),(7,415,1,1),(7,95,1,5),(7,43,1,5),(7,753,5,5),(7,26,5,5),(7,313,300,300),(7,413,1,1),(7,414,1,1),(7,54,1,5),(7,162,1,5),(8,173,1,5),(8,183,5,5),(8,109,300,300),(8,433,1,1),(8,315,300,300),(8,415,1,1),(8,95,1,5),(8,733,5,5),(8,176,1,5),(8,26,5,5),(8,44,1,5),(8,413,1,1),(8,414,1,1),(8,162,1,5),(9,183,5,5),(9,754,5,5),(9,433,1,1),(9,98,300,300),(9,415,1,1),(9,594,5,5),(9,95,1,5),(9,160,1,5),(9,413,1,1),(9,414,1,1),(9,54,1,5),(9,162,1,5),(9,44,1,5),(9,172,1,5),(10,183,5,5),(10,433,1,1),(10,98,300,300),(10,415,1,1),(10,594,5,5),(10,95,1,5),(10,101,5,5),(10,111,300,300),(10,160,1,5),(10,413,1,1),(10,414,1,1),(10,54,1,5),(10,162,1,5),(11,183,5,5),(11,109,300,300),(11,125,5,5),(11,415,1,1),(11,95,1,5),(11,44,1,5),(11,51,5,5),(11,414,1,1),(11,45,1,5),(11,163,5,5),(11,162,1,5),(12,183,5,5),(12,98,300,300),(12,415,1,1),(12,95,1,5),(12,44,1,5),(12,51,5,5),(12,101,5,5),(12,111,300,300),(12,414,1,1),(12,163,5,5),(12,46,1,5),(12,162,1,5),(15,173,1,5),(15,183,5,5),(15,98,300,300),(15,415,1,1),(15,95,1,5),(15,51,5,5),(15,113,300,300),(15,414,1,1),(15,45,1,5),(15,163,5,5),(15,126,5,5),(15,162,1,5),(16,183,5,5),(16,109,300,300),(16,124,5,5),(16,415,1,1),(16,95,1,5),(16,44,1,5),(16,51,5,5),(16,115,300,300),(16,414,1,1),(16,163,5,5),(16,46,1,5),(16,162,1,5),(17,183,5,5),(17,109,300,300),(17,315,300,300),(17,415,1,1),(17,95,1,5),(17,733,5,5),(17,44,1,5),(17,51,5,5),(17,414,1,1),(17,45,1,5),(17,163,5,5),(17,162,1,5),(18,173,1,5),(18,183,5,5),(18,754,5,5),(18,98,300,300),(18,415,1,1),(18,95,1,5),(18,176,1,5),(18,38,5,5),(18,253,5,5),(18,414,1,1),(18,162,1,5),(19,173,1,5),(19,183,5,5),(19,109,300,300),(19,125,5,5),(19,415,1,1),(19,95,1,5),(19,176,1,5),(19,38,5,5),(19,253,5,5),(19,414,1,1),(19,162,1,5),(20,173,1,5),(20,183,5,5),(20,98,300,300),(20,415,1,1),(20,95,1,5),(20,176,1,5),(20,38,5,5),(20,101,5,5),(20,111,300,300),(20,253,5,5),(20,414,1,1),(20,162,1,5),(21,173,1,5),(21,183,5,5),(21,98,300,300),(21,415,1,1),(21,95,1,5),(21,176,1,5),(21,38,5,5),(21,113,300,300),(21,253,5,5),(21,414,1,1),(21,126,5,5),(21,162,1,5),(22,173,1,5),(22,183,5,5),(22,220,5,5),(22,109,300,300),(22,415,1,1),(22,673,300,300),(22,95,1,5),(22,176,1,5),(22,38,5,5),(22,253,5,5),(22,414,1,1),(22,162,1,5),(23,173,1,5),(23,183,5,5),(23,98,300,300),(23,415,1,1),(23,95,1,5),(23,753,5,5),(23,176,1,5),(23,38,5,5),(23,253,5,5),(23,313,300,300),(23,414,1,1),(23,162,1,5),(24,173,1,5),(24,183,5,5),(24,109,300,300),(24,315,300,300),(24,415,1,1),(24,95,1,5),(24,733,5,5),(24,176,1,5),(24,38,5,5),(24,253,5,5),(24,414,1,1),(24,162,1,5),(25,183,5,5),(25,228,1,5),(25,754,5,5),(25,98,300,300),(25,415,1,1),(25,95,1,5),(25,56,5,5),(25,54,1,5),(25,162,1,5),(26,183,5,5),(26,228,1,5),(26,98,300,300),(26,415,1,1),(26,95,1,5),(26,56,5,5),(26,101,5,5),(26,111,300,300),(26,54,1,5),(26,162,1,5),(27,183,5,5),(27,228,1,5),(27,98,300,300),(27,415,1,1),(27,95,1,5),(27,56,5,5),(27,113,300,300),(27,54,1,5),(27,126,5,5),(27,162,1,5),(28,183,5,5),(28,220,5,5),(28,228,1,5),(28,109,300,300),(28,415,1,1),(28,673,300,300),(28,95,1,5),(28,56,5,5),(28,54,1,5),(28,162,1,5),(29,183,5,5),(29,228,1,5),(29,109,300,300),(29,315,300,300),(29,415,1,1),(29,95,1,5),(29,733,5,5),(29,56,5,5),(29,54,1,5),(29,162,1,5),(30,183,5,5),(30,109,300,300),(30,433,1,1),(30,125,5,5),(30,374,5,5),(30,375,5,5),(30,415,1,1),(30,95,1,5),(30,136,1,5),(30,414,1,1),(30,54,1,5),(30,162,1,5),(31,183,5,5),(31,109,300,300),(31,124,5,5),(31,433,1,1),(31,374,5,5),(31,375,5,5),(31,415,1,1),(31,95,1,5),(31,115,300,300),(31,136,1,5),(31,414,1,1),(31,54,1,5),(31,162,1,5),(32,183,5,5),(32,109,300,300),(32,433,1,1),(32,315,300,300),(32,374,5,5),(32,375,5,5),(32,415,1,1),(32,95,1,5),(32,733,5,5),(32,136,1,5),(32,414,1,1),(32,54,1,5),(32,162,1,5),(34,183,5,5),(34,228,1,5),(34,754,5,5),(34,8,5,5),(34,98,300,300),(34,415,1,1),(34,95,1,5),(34,6,5,5),(34,136,1,5),(34,162,1,5),(35,183,5,5),(35,220,5,5),(35,228,1,5),(35,109,300,300),(35,8,5,5),(35,415,1,1),(35,673,300,300),(35,95,1,5),(35,6,5,5),(35,136,1,5),(35,162,1,5),(36,183,5,5),(36,228,1,5),(36,8,5,5),(36,98,300,300),(36,415,1,1),(36,95,1,5),(36,753,5,5),(36,6,5,5),(36,136,1,5),(36,313,300,300),(36,162,1,5),(37,183,5,5),(37,228,1,5),(37,109,300,300),(37,8,5,5),(37,315,300,300),(37,415,1,1),(37,95,1,5),(37,733,5,5),(37,6,5,5),(37,136,1,5),(37,162,1,5),(38,173,1,5),(38,183,5,5),(38,228,1,5),(38,754,5,5),(38,593,5,5),(38,98,300,300),(38,354,5,5),(38,415,1,1),(38,95,1,5),(38,162,1,5),(39,173,1,5),(39,183,5,5),(39,228,1,5),(39,109,300,300),(39,593,5,5),(39,125,5,5),(39,354,5,5),(39,415,1,1),(39,95,1,5),(39,162,1,5),(40,173,1,5),(40,183,5,5),(40,220,5,5),(40,228,1,5),(40,109,300,300),(40,593,5,5),(40,354,5,5),(40,415,1,1),(40,673,300,300),(40,95,1,5),(40,162,1,5),(41,173,1,5),(41,183,5,5),(41,228,1,5),(41,593,5,5),(41,98,300,300),(41,354,5,5),(41,415,1,1),(41,95,1,5),(41,753,5,5),(41,313,300,300),(41,162,1,5),(42,173,1,5),(42,183,5,5),(42,574,5,5),(42,573,5,5),(42,98,300,300),(42,415,1,1),(42,95,1,5),(42,113,300,300),(42,136,1,5),(42,414,1,1),(42,126,5,5),(42,162,1,5),(43,183,5,5),(43,574,5,5),(43,109,300,300),(43,124,5,5),(43,573,5,5),(43,415,1,1),(43,95,1,5),(43,115,300,300),(43,136,1,5),(43,414,1,1),(43,54,1,5),(43,162,1,5),(44,759,300,300),(44,26,5,5),(44,45,0,5),(44,414,1,1),(44,413,1,1),(44,473,0,1),(44,433,1,1),(44,256,0,5),(44,415,1,1),(44,46,0,5),(44,257,0,5),(44,769,0,5),(44,54,1,5),(44,136,0,5),(44,98,300,300),(44,760,5,5),(44,43,1,5),(44,160,0,5),(44,226,0,5),(44,183,5,5),(44,173,0,5),(44,172,0,5),(44,142,0,1),(44,176,0,5),(44,55,1,5),(44,95,1,5),(44,44,0,5),(44,162,1,5),(45,759,300,300),(45,414,1,1),(45,413,1,1),(45,433,1,1),(45,594,5,5),(45,415,1,1),(45,769,0,5),(45,54,1,5),(45,98,300,300),(45,760,5,5),(45,43,0,5),(45,160,1,5),(45,184,0,5),(45,183,5,5),(45,172,0,5),(45,142,0,1),(45,55,0,5),(45,95,1,5),(45,44,0,5),(45,162,1,5),(45,267,0,5),(46,759,300,300),(46,45,0,5),(46,414,1,1),(46,473,0,1),(46,415,1,1),(46,46,0,5),(46,769,0,5),(46,136,0,5),(46,98,300,300),(46,760,5,5),(46,51,5,5),(46,43,1,5),(46,226,1,5),(46,183,5,5),(46,173,0,5),(46,172,0,5),(46,163,5,5),(46,142,0,1),(46,176,0,5),(46,55,0,5),(46,95,1,5),(46,50,0,5),(46,44,0,5),(46,162,1,5),(46,261,0,5),(47,759,300,300),(47,78,0,5),(47,613,0,5),(47,415,1,1),(47,769,0,5),(47,54,1,5),(47,136,0,5),(47,98,300,300),(47,760,5,5),(47,228,1,5),(47,183,5,5),(47,173,0,5),(47,142,0,1),(47,95,1,5),(47,56,5,5),(47,162,1,5),(48,759,300,300),(48,414,1,1),(48,473,0,1),(48,433,1,1),(48,415,1,1),(48,375,5,5),(48,374,5,5),(48,373,0,5),(48,769,0,5),(48,54,1,5),(48,136,1,5),(48,98,300,300),(48,760,5,5),(48,160,0,5),(48,183,5,5),(48,173,0,5),(48,172,0,5),(48,142,0,1),(48,95,1,5),(48,44,0,5),(48,162,1,5),(49,759,300,300),(49,415,1,1),(49,8,5,5),(49,769,0,5),(49,136,1,5),(49,98,300,300),(49,760,5,5),(49,43,0,5),(49,228,1,5),(49,183,5,5),(49,173,0,5),(49,142,0,1),(49,6,5,5),(49,95,1,5),(49,162,1,5),(49,237,0,5),(50,756,5,5),(50,414,1,1),(50,413,1,1),(50,137,300,300),(50,433,1,1),(50,594,5,5),(50,415,1,1),(50,769,0,5),(50,54,0,5),(50,43,1,5),(50,160,0,5),(50,109,300,300),(50,184,0,5),(50,183,5,5),(50,172,0,5),(50,142,0,1),(50,55,1,5),(50,95,1,5),(50,44,0,5),(50,162,1,5),(50,267,0,5),(51,756,5,5),(51,45,1,5),(51,414,1,1),(51,473,0,1),(51,137,300,300),(51,415,1,1),(51,46,0,5),(51,769,0,5),(51,136,0,5),(51,51,5,5),(51,43,0,5),(51,109,300,300),(51,226,0,5),(51,183,5,5),(51,173,1,5),(51,172,0,5),(51,163,5,5),(51,142,0,1),(51,176,0,5),(51,55,0,5),(51,95,1,5),(51,50,0,5),(51,44,0,5),(51,162,1,5),(51,261,0,5),(52,756,5,5),(52,45,0,5),(52,414,1,1),(52,253,5,5),(52,473,0,1),(52,137,300,300),(52,415,1,1),(52,46,0,5),(52,769,0,5),(52,54,0,5),(52,43,0,5),(52,109,300,300),(52,226,0,5),(52,183,5,5),(52,173,1,5),(52,142,0,1),(52,39,0,5),(52,38,5,5),(52,176,1,5),(52,95,1,5),(52,162,1,5),(53,78,0,5),(53,756,5,5),(53,613,0,5),(53,137,300,300),(53,415,1,1),(53,769,0,5),(53,54,1,5),(53,136,0,5),(53,109,300,300),(53,228,1,5),(53,183,5,5),(53,173,0,5),(53,142,0,1),(53,95,1,5),(53,56,5,5),(53,162,1,5),(54,756,5,5),(54,137,300,300),(54,415,1,1),(54,8,5,5),(54,769,0,5),(54,136,1,5),(54,43,0,5),(54,109,300,300),(54,228,1,5),(54,183,5,5),(54,173,0,5),(54,142,0,1),(54,6,5,5),(54,95,1,5),(54,162,1,5),(54,237,0,5),(55,593,5,5),(55,756,5,5),(55,137,300,300),(55,415,1,1),(55,355,0,5),(55,354,5,5),(55,769,0,5),(55,136,0,5),(55,43,0,5),(55,109,300,300),(55,228,1,5),(55,183,5,5),(55,173,1,5),(55,142,0,1),(55,95,1,5),(55,162,1,5),(57,55,270,275),(57,44,270,275),(57,43,270,275),(57,772,275,275),(57,771,275,275),(57,770,275,275),(57,762,150,150),(57,129,270,300),(56,98,300,300),(56,162,270,275),(56,95,270,275),(56,229,270,275),(56,172,270,275),(56,55,270,275),(56,44,270,275),(56,43,270,275),(56,772,275,275),(56,771,275,275),(56,770,275,275),(56,762,150,150),(56,129,270,300),(57,172,270,275),(57,229,270,275),(57,95,270,275),(57,162,270,275),(57,98,300,300),(58,129,270,300),(58,762,150,150),(58,770,275,275),(58,771,275,275),(58,772,275,275),(58,43,270,275),(58,44,270,275),(58,55,270,275),(58,172,270,275),(58,229,270,275),(58,95,270,275),(58,162,270,275),(58,98,300,300),(59,129,270,300),(59,762,150,150),(59,770,275,275),(59,771,275,275),(59,772,275,275),(59,43,270,275),(59,44,270,275),(59,55,270,275),(59,172,270,275),(59,229,270,275),(59,95,270,275),(59,162,270,275),(59,98,300,300),(60,129,270,300),(60,762,150,150),(60,770,275,275),(60,771,275,275),(60,772,275,275),(60,43,270,275),(60,44,270,275),(60,55,270,275),(60,172,270,275),(60,229,270,275),(60,95,270,275),(60,162,270,275),(60,98,300,300),(61,129,270,300),(61,762,150,150),(61,770,275,275),(61,771,275,275),(61,772,275,275),(61,43,270,275),(61,44,270,275),(61,55,270,275),(61,172,270,275),(61,229,270,275),(61,95,270,275),(61,162,270,275),(61,98,300,300),(62,129,270,300),(62,762,150,150),(62,770,275,275),(62,771,275,275),(62,772,275,275),(62,43,270,275),(62,44,270,275),(62,55,270,275),(62,172,270,275),(62,229,270,275),(62,95,270,275),(62,162,270,275),(62,98,300,300),(63,129,270,300),(63,762,150,150),(63,770,275,275),(63,771,275,275),(63,772,275,275),(63,43,270,275),(63,44,270,275),(63,55,270,275),(63,172,270,275),(63,229,270,275),(63,95,270,275),(63,162,270,275),(63,98,300,300),(64,129,270,300),(64,762,150,150),(64,770,275,275),(64,771,275,275),(64,772,275,275),(64,43,270,275),(64,44,270,275),(64,55,270,275),(64,172,270,275),(64,229,270,275),(64,95,270,275),(64,162,270,275),(64,98,300,300),(65,129,270,300),(65,762,150,150),(65,770,275,275),(65,771,275,275),(65,772,275,275),(65,43,270,275),(65,44,270,275),(65,55,270,275),(65,172,270,275),(65,229,270,275),(65,95,270,275),(65,162,270,275),(65,98,300,300),(57,109,1,1),(60,109,1,1),(61,109,1,1),(63,109,1,1),(65,109,1,1),(60,673,1,1),(61,115,1,1),(63,315,1,1),(65,137,1,1),(56,98,1,1),(58,98,1,1),(59,98,1,1),(62,98,1,1),(64,98,1,1),(58,111,1,1),(59,113,1,1),(62,313,1,1),(64,759,1,1),(56,118,275,275),(57,118,275,275),(58,118,275,275),(59,118,275,275),(60,118,275,275),(61,118,275,275),(62,118,275,275),(63,118,275,275),(64,118,275,275),(65,118,275,275),(56,183,275,275),(57,183,275,275),(58,183,275,275),(59,183,275,275),(60,183,275,275),(61,183,275,275),(62,183,275,275),(63,183,275,275),(64,183,275,275),(65,183,275,275),(56,413,1,1),(57,413,1,1),(58,413,1,1),(59,413,1,1),(60,413,1,1),(61,413,1,1),(62,413,1,1),(63,413,1,1),(64,413,1,1),(65,413,1,1),(56,414,1,1),(57,414,1,1),(58,414,1,1),(59,414,1,1),(60,414,1,1),(61,414,1,1),(62,414,1,1),(63,414,1,1),(64,414,1,1),(65,414,1,1),(56,415,1,1),(57,415,1,1),(58,415,1,1),(59,415,1,1),(60,415,1,1),(61,415,1,1),(62,415,1,1),(63,415,1,1),(64,415,1,1),(65,415,1,1),(56,293,1,1),(57,293,1,1),(58,293,1,1),(59,293,1,1),(60,293,1,1),(61,293,1,1),(62,293,1,1),(63,293,1,1),(64,293,1,1),(65,293,1,1),(56,777,1,1),(57,777,1,1),(58,777,1,1),(59,777,1,1),(60,777,1,1),(61,777,1,1),(62,777,1,1),(63,777,1,1),(64,777,1,1),(65,777,1,1),(56,754,275,275),(58,101,275,275),(59,126,275,275),(62,753,275,275),(64,760,275,275),(57,125,275,275),(60,220,275,275),(61,124,275,275),(63,733,275,275),(65,756,275,275);
/*!40000 ALTER TABLE `playercreateinfo_skills` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-08-29 23:28:41
