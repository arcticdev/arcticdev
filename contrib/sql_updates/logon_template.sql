/*
MySQL Data Transfer
Source Host: localhost
Source Database: arctic_logon
Target Host: localhost
Target Database: arctic_logon
Date: 07.01.2010 9:50:46
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for accounts
-- ----------------------------
DROP TABLE IF EXISTS `accounts`;
CREATE TABLE `accounts` (
  `acct` int(5) NOT NULL auto_increment,
  `login` varchar(32) collate utf8_unicode_ci NOT NULL default '',
  `password` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `SessionKey` varchar(255) collate utf8_unicode_ci NOT NULL default '',
  `gm` varchar(10) collate utf8_unicode_ci NOT NULL default '0',
  `flags` int(11) NOT NULL default '24',
  `banned` tinyint(1) NOT NULL default '0',
  `lastlogin` timestamp NOT NULL default CURRENT_TIMESTAMP,
  `lastip` varchar(15) collate utf8_unicode_ci NOT NULL default '',
  `forceLanguage` varchar(5) collate utf8_unicode_ci NOT NULL default 'ruRU',
  `email` varchar(32) collate utf8_unicode_ci default NULL,
  `muted` int(30) NOT NULL default '0',
  `premium` int(10) NOT NULL default '0',
  PRIMARY KEY  (`acct`),
  UNIQUE KEY `login` (`login`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for ipbans
-- ----------------------------
DROP TABLE IF EXISTS `ipbans`;
CREATE TABLE `ipbans` (
  `ip` varchar(128) NOT NULL,
  `time` int(30) NOT NULL default '0',
  `expire` int(30) NOT NULL default '0',
  PRIMARY KEY  (`ip`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
