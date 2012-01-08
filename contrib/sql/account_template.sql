/*
Navicat MySQL Data Transfer

Source Server         : arcticdev
Source Server Version : 50509
Source Host           : localhost:3306
Source Database       : account_template

Target Server Type    : MYSQL
Target Server Version : 50509
File Encoding         : 65001

Date: 2012-01-08 02:44:06
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `accounts`
-- ----------------------------
DROP TABLE IF EXISTS `accounts`;
CREATE TABLE `accounts` (
  `acct` int(5) NOT NULL AUTO_INCREMENT,
  `login` varchar(32) NOT NULL DEFAULT '',
  `password` varchar(255) NOT NULL DEFAULT '',
  `SessionKey` varchar(255) NOT NULL DEFAULT '',
  `gm` varchar(10) NOT NULL DEFAULT '0',
  `flags` int(11) NOT NULL DEFAULT '24',
  `banned` tinyint(1) NOT NULL DEFAULT '0',
  `banreason` varchar(512) DEFAULT '0',
  `lastlogin` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `lastip` varchar(15) NOT NULL DEFAULT '',
  `forceLanguage` varchar(5) NOT NULL DEFAULT 'enUS',
  `email` varchar(32) DEFAULT NULL,
  `muted` int(30) NOT NULL DEFAULT '0',
  PRIMARY KEY (`acct`),
  UNIQUE KEY `login` (`login`)
) ENGINE=MyISAM AUTO_INCREMENT=8630 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of accounts
-- ----------------------------
-- ----------------------------
-- Table structure for ipbans
-- ----------------------------
DROP TABLE IF EXISTS `ipbans`;
CREATE TABLE `ipbans`(
  `ip` varchar(128) NOT NULL ,
  `time` int(30) NOT NULL DEFAULT 0 ,
  `expire` int(30) NOT NULL DEFAULT 0 ,
  PRIMARY KEY  (`ip`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of accounts
-- ----------------------------