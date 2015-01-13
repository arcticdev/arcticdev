/*
Navicat MySQL Data Transfer

Source Server         : arcticdev
Source Server Version : 50509
Source Host           : localhost:3306
Source Database       : account_template

Target Server Type    : MYSQL
Target Server Version : 50509
File Encoding         : 65001

Date: 2014-12-29 22:23:17
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for accounts
-- ----------------------------
DROP TABLE IF EXISTS `accounts`;
CREATE TABLE `accounts` (
  `acct` int(5) NOT NULL AUTO_INCREMENT,
  `login` varchar(32) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `password` varchar(255) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `SessionKey` varchar(255) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `gm` varchar(10) COLLATE utf8_unicode_ci NOT NULL DEFAULT '0',
  `flags` int(11) NOT NULL DEFAULT '24',
  `banned` tinyint(1) NOT NULL DEFAULT '0',
  `banreason` varchar(512) COLLATE utf8_unicode_ci DEFAULT '0',
  `lastlogin` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `lastip` varchar(15) COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
  `forceLanguage` varchar(5) COLLATE utf8_unicode_ci NOT NULL DEFAULT 'enUS',
  `email` varchar(32) COLLATE utf8_unicode_ci DEFAULT NULL,
  `muted` int(30) NOT NULL DEFAULT '0',
  PRIMARY KEY (`acct`),
  UNIQUE KEY `login` (`login`)
) ENGINE=MyISAM AUTO_INCREMENT=8631 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for ipbans
-- ----------------------------
DROP TABLE IF EXISTS `ipbans`;
CREATE TABLE `ipbans` (
  `ip` varchar(128) COLLATE utf8_unicode_ci NOT NULL,
  `time` int(30) NOT NULL DEFAULT '0',
  `expire` int(30) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ip`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
