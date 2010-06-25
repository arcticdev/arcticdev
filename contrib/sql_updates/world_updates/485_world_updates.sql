/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

/* 3_rev_updates */
ALTER TABLE worldmap_info ADD COLUMN maxplayers_heroic int(10) DEFAULT 0 NOT NULL AFTER maxplayers;
UPDATE worldmap_info SET maxplayers_heroic = maxplayers;

/* 16_rev_inscriptiondiscoveries */
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56944','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56946','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56947','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56949','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56950','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56954','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56958','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56960','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56975','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56977','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56983','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56986','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56988','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56989','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56996','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56998','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','56999','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57010','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57011','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57012','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57013','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57014','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57019','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57021','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57028','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57034','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57035','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57112','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57115','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57116','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57117','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57124','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57126','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57127','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57128','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57130','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57152','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57153','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57155','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57159','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57160','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57164','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57166','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57169','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57170','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57181','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57189','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57190','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57191','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57193','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57195','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57199','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57202','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57207','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57208','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57211','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57212','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57214','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57218','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57220','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57223','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57232','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57233','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57234','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57235','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57237','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57243','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57247','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57250','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57258','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57260','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57261','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57263','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57264','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57267','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57268','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57273','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57276','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','57719','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','59559','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','59560','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','59561','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61177','61677','385','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','56965','355','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','56990','350','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','56991','310','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57209','350','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57215','305','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57217','350','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57228','305','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57229','305','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57230','305','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','57253','355','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58253','350','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58286','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58287','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58288','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58289','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58296','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58297','205','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58298','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58299','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58300','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58301','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58302','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58303','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58305','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58306','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58307','130','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58308','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58310','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58311','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58312','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58313','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58314','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58315','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58316','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58317','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58318','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58319','180','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58320','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58321','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58322','355','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58323','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58324','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58325','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58326','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58327','205','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58328','130','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58329','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58330','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58331','130','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58332','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58333','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58336','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58337','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58338','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58339','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58340','130','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58341','350','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58342','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58343','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58344','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58345','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58346','75','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','58347','350','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','59315','150','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','59326','105','100');
insert into `professiondiscoveries` (`SpellId`, `SpellToDiscover`, `SkillValue`, `Chance`) values('61288','62162','380','100');

/* 16_rev_random */
update `gameobject_names` set `spellfocus` = 4 where `name` LIKE "%fire%" AND `type` = 8 AND `spellfocus` = 0;
update `gameobject_names` set `sound2` =  0 where `name` LIKE "%fire%" AND `type` = 8 AND `spellfocus` = 4;
update `gameobject_names` set `sound1`=5 where `sound1`<5 AND `Type`=8;

SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `spell_coef_override`;
-- ----------------------------
-- Table structure for spell_coef_override
-- ----------------------------
CREATE TABLE `spell_coef_override` (
  `id` int default '0',
  `Dspell_coef_override` float default '0',
  `OTspell_coef_override` float default '0',
  `AP_coef_override` float default '0',
  `RAP_coef_override` float default '0'  
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
-- Shadow Bolt
INSERT INTO `spell_coef_override` VALUES ('686', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('695', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('705', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1088', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1106', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('7641', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11659', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11660', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11661', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25307', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27209', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47808', '0.8569', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47809', '0.8569', '0', '0', '0');

-- Magma totem
INSERT INTO `spell_coef_override` VALUES ('8187', '0.10', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10579', '0.10', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10580', '0.10', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10581', '0.10', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25550', '0.10', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58732', '0.10', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58735', '0.10', '0', '0', '0');

-- Cricle of Healing
INSERT INTO `spell_coef_override` VALUES ('34861', '0.402', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('34863', '0.402', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('34864', '0.402', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('34865', '0.402', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('34866', '0.402', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48088', '0.402', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48089', '0.402', '0', '0', '0');

-- Dragon's Breath
INSERT INTO `spell_coef_override` VALUES ('31661', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33041', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33042', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33043', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42949', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42950', '0.1936', '0', '0', '0');

-- Fire Nova Totem
INSERT INTO `spell_coef_override` VALUES ('8443', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8504', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8505', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11310', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11311', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25538', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25539', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('61650', '0.2142', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('61654', '0.2142', '0', '0', '0');

-- Earth Shock
INSERT INTO `spell_coef_override` VALUES ('8042', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8044', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8045', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8046', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10412', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10413', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10414', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25454', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49230', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49231', '0.3858', '0', '0', '0');

-- Desperate Prayer
INSERT INTO `spell_coef_override` VALUES ('19236', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19238', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19240', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19241', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19242', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19243', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25437', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48172', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48173', '0.8068', '0', '0', '0');

-- Chain Heal
INSERT INTO `spell_coef_override` VALUES ('1064', '0.8', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10622', '0.8', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10623', '0.8', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25422', '0.8', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25423', '0.8', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('55458', '0.8', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('55459', '0.8', '0', '0', '0');

-- Incinerate
INSERT INTO `spell_coef_override` VALUES ('29722', '0.7139', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('32231', '0.7139', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47837', '0.7139', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47838', '0.7139', '0', '0', '0');

-- Flame Shock
INSERT INTO `spell_coef_override` VALUES ('8050', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8052', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8053', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10447', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10448', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('29228', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25457', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49232', '0.2142', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49233', '0.2142', '0.1', '0', '0');

-- Blizzard
INSERT INTO `spell_coef_override` VALUES ('42208', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42209', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42210', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42211', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42212', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42213', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42198', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42937', '0.1437', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42938', '0.1437', '0', '0', '0');

-- Force of Nature
-- INSERT INTO `spell_coef_override` VALUES ('', '0.035', '0', '0', '0');

-- Healing Stream Totem
INSERT INTO `spell_coef_override` VALUES ('52041', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52046', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52047', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52048', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52049', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52050', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58759', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58760', '0.045', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58761', '0.045', '0', '0', '0');

-- Shadow Ward
INSERT INTO `spell_coef_override` VALUES ('6229', '0.3', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11739', '0.3', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11740', '0.3', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('28610', '0.3', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47890', '0.3', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47891', '0.3', '0', '0', '0');

-- Arcane Blast
INSERT INTO `spell_coef_override` VALUES ('30451', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42894', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42896', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42897', '0.7143', '0', '0', '0');

-- Regrowth
INSERT INTO `spell_coef_override` VALUES ('8936', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8938', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8939', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8940', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8941', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9750', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9856', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9857', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9858', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26980', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48442', '0.539', '0.188', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48443', '0.539', '0.188', '0', '0');

-- Seal of Light
INSERT INTO `spell_coef_override` VALUES ('20167', '0.15', '0', '0.15', '0');

-- Nourish
INSERT INTO `spell_coef_override` VALUES ('50464', '0.6611', '0', '0', '0');

-- Rain of Fire
INSERT INTO `spell_coef_override` VALUES ('5740', '0.6932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6219', '0.6932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11677', '0.6932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11678', '0.6932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27212', '0.6932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47819', '0.6932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47820', '0.6932', '0', '0', '0');

-- Devouring Plague
INSERT INTO `spell_coef_override` VALUES ('2944', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19276', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19277', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19278', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19279', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19280', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25467', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48299', '0', '0.1849', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48300', '0', '0.1849', '0', '0');

-- Seal of Wisdom
INSERT INTO `spell_coef_override` VALUES ('20168', '0.25', '0', '0', '0');

-- Arcane Missiles
INSERT INTO `spell_coef_override` VALUES ('5143', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5144', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5145', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8416', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8417', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10211', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10212', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25345', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27075', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('38699', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('38704', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42843', '0.2857', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42846', '0.2857', '0', '0', '0');

-- Lifebloom
INSERT INTO `spell_coef_override` VALUES ('33763', '0.6453', '0.09518', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48450', '0.6453', '0.09518', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48451', '0.6453', '0.09518', '0', '0');

-- Renew
INSERT INTO `spell_coef_override` VALUES ('139', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6074', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6075', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6076', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6077', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6078', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10927', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10928', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10929', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25315', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25221', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25222', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48067', '0', '0.36', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48068', '0', '0.36', '0', '0');

-- Siphon Life 3.1 change
-- INSERT INTO `spell_coef_override` VALUES ('', '0', '0.10', '0', '0');

-- Frost Shock
INSERT INTO `spell_coef_override` VALUES ('8056', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8058', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10472', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10473', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25464', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49235', '0.3858', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49236', '0.3858', '0', '0', '0');

-- Tranquility
INSERT INTO `spell_coef_override` VALUES ('740', '0.538', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8918', '0.538', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9862', '0.538', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9863', '0.538', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26983', '0.538', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48446', '0.538', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48447', '0.538', '0', '0', '0');

-- Wrath
INSERT INTO `spell_coef_override` VALUES ('5176', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5177', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5178', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5179', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5180', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6780', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8905', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9912', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26984', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26985', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48459', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48461', '0.5714', '0', '0', '0');

-- Living Bomb
INSERT INTO `spell_coef_override` VALUES ('44457', '0.4', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('55359', '0.4', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('55360', '0.4', '0.2', '0', '0');

-- Flamestrike
INSERT INTO `spell_coef_override` VALUES ('2120', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2121', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8422', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8423', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10215', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10216', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27086', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42925', '0.2357', '0.122', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42926', '0.2357', '0.122', '0', '0');

-- Shadowfury
INSERT INTO `spell_coef_override` VALUES ('30283', '0.1932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30413', '0.1932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30414', '0.1932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47846', '0.1932', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47847', '0.1932', '0', '0', '0');

-- Searing Totem
INSERT INTO `spell_coef_override` VALUES ('3606', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6350', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6351', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6352', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10435', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10436', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25530', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58700', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58701', '0.1667', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58702', '0.1667', '0', '0', '0');

-- Curse of Agony
INSERT INTO `spell_coef_override` VALUES ('980', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1014', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6217', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11711', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11712', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11713', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27218', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47863', '0', '0.10', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47864', '0', '0.10', '0', '0');

-- Lightning Shield
INSERT INTO `spell_coef_override` VALUES ('324', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('325', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('905', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('945', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8134', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10431', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10432', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25469', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25472', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49280', '0.33', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49281', '0.33', '0', '0', '0');

-- Seed of Corruption
INSERT INTO `spell_coef_override` VALUES ('27243', '0.2129', '0.25', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47835', '0.2129', '0.25', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47836', '0.2129', '0.25', '0', '0');

-- Flametongue Weapon
INSERT INTO `spell_coef_override` VALUES ('8026', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8028', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8029', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10445', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('16343', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('16344', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25488', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58786', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58787', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58788', '0.1', '0', '0', '0');

-- Frostbrand Weapon
INSERT INTO `spell_coef_override` VALUES ('8034', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8037', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10458', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('16352', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('16353', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25501', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58797', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58798', '0.1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('58799', '0.1', '0', '0', '0');

-- Drain Life
INSERT INTO `spell_coef_override` VALUES ('689', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('699', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('709', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('7651', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11699', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11700', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27219', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27220', '0.1430', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47857', '0.1430', '0', '0', '0');

-- Seal of the Martyr
INSERT INTO `spell_coef_override` VALUES ('53719', '0.25', '0', '0', '0');

-- Riptide
INSERT INTO `spell_coef_override` VALUES ('61295', '0.4', '0.18', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('61299', '0.4', '0.18', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('61300', '0.4', '0.18', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('61301', '0.4', '0.18', '0', '0');

-- Blast Wave
INSERT INTO `spell_coef_override` VALUES ('11113', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13018', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13019', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13020', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13021', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27133', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33933', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42944', '0.1936', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42945', '0.1936', '0', '0', '0');

-- Shadowfiend
-- INSERT INTO `spell_coef_override` VALUES ('0', 'Shadowfiend', '0.65', '0', '0', '0');

-- Typhoon
INSERT INTO `spell_coef_override` VALUES ('50516', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53223', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53225', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53226', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('61384', '0.193', '0', '0', '0');

-- Mana Shield
INSERT INTO `spell_coef_override` VALUES ('1463', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8494', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8495', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10191', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10192', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10193', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27131', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('43019', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('43020', '0', '0.8053', '0', '0');

-- Health Funnel
INSERT INTO `spell_coef_override` VALUES ('755', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3698', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3699', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3700', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11693', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11694', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11695', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27259', '0', '0.4485', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47856', '0', '0.4485', '0', '0');

-- Searing Pain
INSERT INTO `spell_coef_override` VALUES ('5676', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17919', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17920', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17921', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17922', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17923', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27210', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30459', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47814', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47815', '0.4293', '0', '0', '0');

-- Curse of Doom
INSERT INTO `spell_coef_override` VALUES ('603', '0', '2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30910', '0', '2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47867', '0', '2', '0', '0');

-- Lava Burst
INSERT INTO `spell_coef_override` VALUES ('51505', '0.5714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('60043', '0.5714', '0', '0', '0');

-- Greater Heal
INSERT INTO `spell_coef_override` VALUES ('2060', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10963', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10964', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10965', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25314', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25210', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25213', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48062', '1.6135', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48063', '1.6135', '0', '0', '0');

-- Shadow Word: Pain
INSERT INTO `spell_coef_override` VALUES ('589', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('594', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('970', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('992', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2767', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10892', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10893', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10894', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25367', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25368', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48124', '0', '0.1829', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48125', '0', '0.1829', '0', '0');

-- Fireball
INSERT INTO `spell_coef_override` VALUES ('133', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('143', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('145', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3140', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8400', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8401', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8402', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10148', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10149', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10150', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10151', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25306', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27070', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('38692', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42832', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42833', '1', '0', '0', '0');

-- Haunt
INSERT INTO `spell_coef_override` VALUES ('48181', '0.4793', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59161', '0.4793', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59163', '0.4793', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59164', '0.4793', '0', '0', '0');

-- Frostbolt
INSERT INTO `spell_coef_override` VALUES ('116', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('205', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('837', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('7322', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8406', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8407', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8408', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10179', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10180', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10181', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25304', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27071', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27072', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('38697', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42841', '0.8143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42842', '0.8143', '0', '0', '0');

-- Soul Fire
INSERT INTO `spell_coef_override` VALUES ('6353', '1.15', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17924', '1.15', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27211', '1.15', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27211', '1.15', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47824', '1.15', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47825', '1.15', '0', '0', '0');

-- Entangling Roots
INSERT INTO `spell_coef_override` VALUES ('339', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1062', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5195', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5196', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9852', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9853', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26989', '0', '0.1', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53308', '0', '0.1', '0', '0');

-- Unstable Affliction - dot
INSERT INTO `spell_coef_override` VALUES ('30108', '0', '0.20', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30404', '0', '0.20', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30405', '0', '0.20', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47841', '0', '0.20', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47843', '0', '0.20', '0', '0');

-- Unstable Affliction - DD
INSERT INTO `spell_coef_override` VALUES ('31117', '1.8', '0', '0', '0');

-- Healing Wave
INSERT INTO `spell_coef_override` VALUES ('331', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('332', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('547', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('913', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('933', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('953', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8005', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10395', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10396', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25357', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25391', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25396', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49272', '1.6106', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49273', '1.6106', '0', '0', '0');

-- Lesser Healing Wave
INSERT INTO `spell_coef_override` VALUES ('8004', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8008', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8010', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10466', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10467', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10468', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25420', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49275', '0.8082', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49276', '0.8082', '0', '0', '0');

-- Rejuvenation
INSERT INTO `spell_coef_override` VALUES ('774', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1058', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1430', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2090', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2091', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3627', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8910', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9839', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9840', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9841', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25299', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26981', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26982', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48440', '1.88', '0.37604', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48441', '1.88', '0.37604', '0', '0');

-- Chain Lightning
INSERT INTO `spell_coef_override` VALUES ('421', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('930', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2860', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10605', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25439', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25442', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49270', '0.4', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49271', '0.4', '0', '0', '0');

-- Frostfire Bolt
INSERT INTO `spell_coef_override` VALUES ('44614', '0.8571', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47610', '0.8571', '0', '0', '0');

-- Flash Heal
INSERT INTO `spell_coef_override` VALUES ('2061', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9472', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9473', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9474', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10915', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10916', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10917', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25233', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25235', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48070', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48071', '0.8068', '0', '0', '0');

-- Holy Light
INSERT INTO `spell_coef_override` VALUES ('635', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('639', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('647', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1026', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1042', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3472', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10328', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10329', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25292', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27135', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27136', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48781', '1.66', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48782', '1.66', '0', '0', '0');

-- Earth Shield
INSERT INTO `spell_coef_override` VALUES ('974', '0.4761', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('32593', '0.4761', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('32594', '0.4761', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49283', '0.4761', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49284', '0.4761', '0', '0', '0');

-- Immolate
INSERT INTO `spell_coef_override` VALUES ('348', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('707', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1094', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2941', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11665', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11667', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11668', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25309', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27215', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47810', '0.2', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47811', '0.2', '0.2', '0', '0');

-- Cone of Cold
INSERT INTO `spell_coef_override` VALUES ('120', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8492', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10159', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10160', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10161', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27087', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42930', '0.214', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42931', '0.214', '0', '0', '0');

-- Death Coil
INSERT INTO `spell_coef_override` VALUES ('6789', '0.2140', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17925', '0.2140', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17926', '0.2140', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27223', '0.2140', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47859', '0.2140', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47860', '0.2140', '0', '0', '0');

-- Moonfire
INSERT INTO `spell_coef_override` VALUES ('8921', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8924', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8925', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8926', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8927', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8928', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8929', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8933', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8934', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8935', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26987', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26988', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48462', '0.1515', '0.13', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48463', '0.1515', '0.13', '0', '0');

-- Consecration
INSERT INTO `spell_coef_override` VALUES ('26573', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('20116', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('20922', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('20923', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('20924', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27173', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48818', '0.04', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48819', '0.04', '0', '0', '0');

-- Starfire
INSERT INTO `spell_coef_override` VALUES ('2912', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8949', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8950', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8951', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9875', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9876', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25298', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26986', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48464', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48465', '1', '0', '0', '0');

-- Healing Touch
INSERT INTO `spell_coef_override` VALUES ('5185', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5186', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5187', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5188', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('5189', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6778', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8903', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9758', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9888', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('9889', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25297', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26978', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('26979', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48377', '1.6104', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48378', '1.6104', '0', '0', '0');

-- Prayer of Mending
INSERT INTO `spell_coef_override` VALUES ('41637', '0.8068', '0', '0', '0');

-- Flash of Light
INSERT INTO `spell_coef_override` VALUES ('19750', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19939', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19940', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19941', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19942', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('19943', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27137', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48784', '1', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48785', '1', '0', '0', '0');

-- Smite
INSERT INTO `spell_coef_override` VALUES ('585', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('591', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('598', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('984', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('1004', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6060', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10933', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10934', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25363', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25364', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48122', '0.714', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48123', '0.714', '0', '0', '0');

-- Frost Nova
INSERT INTO `spell_coef_override` VALUES ('122', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('856', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6131', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10230', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27088', '0.193', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42917', '0.193', '0', '0', '0');

-- Dark Pact
INSERT INTO `spell_coef_override` VALUES ('18220', '0.96', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18937', '0.96', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18938', '0.96', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27265', '0.96', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59092', '0.96', '0', '0', '0');

-- Mind Flay
INSERT INTO `spell_coef_override` VALUES ('15407', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17311', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17312', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17313', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('17314', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18807', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25387', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48155', '0', '0.257', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48156', '0', '0.257', '0', '0');

-- Wild Growth
INSERT INTO `spell_coef_override` VALUES ('48438', '0', '0.11505', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53248', '0', '0.11505', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53249', '0', '0.11505', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53251', '0', '0.11505', '0', '0');

-- Fire Blast
INSERT INTO `spell_coef_override` VALUES ('2136', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2137', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('2138', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8412', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8413', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10197', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10199', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27078', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27079', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42872', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42873', '0.4286', '0', '0', '0');

-- Hellfire
INSERT INTO `spell_coef_override` VALUES ('1949', '0', '0.12', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11683', '0', '0.12', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11684', '0', '0.12', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27213', '0', '0.12', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47823', '0', '0.12', '0', '0');

-- Prayer of Healing
INSERT INTO `spell_coef_override` VALUES ('596', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('996', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10960', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10961', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25316', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25308', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48072', '0.8068', '0', '0', '0');

-- Lightning Bolt
INSERT INTO `spell_coef_override` VALUES ('403', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('529', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('548', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('915', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('943', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6041', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10391', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10392', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15207', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15208', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25448', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25449', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49237', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('49238', '0.7143', '0', '0', '0');

-- Holy Fire
INSERT INTO `spell_coef_override` VALUES ('14914', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15262', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15263', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15264', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15265', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15266', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15267', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15261', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25384', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48134', '0.5711', '0.024', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48135', '0.5711', '0.024', '0', '0');

-- Ice Lance
INSERT INTO `spell_coef_override` VALUES ('30455', '0.1429', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42913', '0.1429', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42914', '0.1429', '0', '0', '0');

-- Scorch
INSERT INTO `spell_coef_override` VALUES ('2948', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8444', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8445', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8446', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10205', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10206', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10207', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27073', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27074', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42858', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42859', '0.4286', '0', '0', '0');

-- Arcane Barrage
INSERT INTO `spell_coef_override` VALUES ('44425', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('44780', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('44781', '0.7143', '0', '0', '0');

-- Starfall - DD
INSERT INTO `spell_coef_override` VALUES ('50288', '0.05', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53191', '0.05', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53194', '0.05', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53195', '0.05', '0', '0', '0');

-- Starfall - AOE
INSERT INTO `spell_coef_override` VALUES ('50294', '0.012', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53188', '0.012', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53189', '0.012', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53190', '0.012', '0', '0', '0');

-- Power Word: Shield
INSERT INTO `spell_coef_override` VALUES ('17', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('592', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('600', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('3747', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6065', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6066', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10898', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10899', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10900', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10901', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25217', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25218', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48065', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48066', '0.8068', '0', '0', '0');

-- Vampiric Touch
INSERT INTO `spell_coef_override` VALUES ('34914', '0', '0.4', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('34916', '0', '0.4', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('34917', '0', '0.4', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48159', '0', '0.4', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48160', '0', '0.4', '0', '0');

-- Shadow Word: Death
INSERT INTO `spell_coef_override` VALUES ('32379', '0.4296', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('32996', '0.4296', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48157', '0.4296', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48158', '0.4296', '0', '0', '0');

-- Pyroblast
INSERT INTO `spell_coef_override` VALUES ('11366', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('12505', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('12522', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('12523', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('12524', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('12525', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('12526', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18809', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27132', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33938', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42890', '1.15', '0.05', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42891', '1.15', '0.05', '0', '0');

-- Binding Heal
INSERT INTO `spell_coef_override` VALUES ('32546', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48119', '0.8068', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48120', '0.8068', '0', '0', '0');

-- Drain Soul
INSERT INTO `spell_coef_override` VALUES ('1120', '0', '0.4290', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8288', '0', '0.4290', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8289', '0', '0.4290', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11675', '0', '0.4290', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27217', '0', '0.4290', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47855', '0', '0.4290', '0', '0');

-- Shadowburn
INSERT INTO `spell_coef_override` VALUES ('17877', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18867', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18868', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18869', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18870', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('18871', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27263', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('30546', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47826', '0.4293', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47827', '0.4293', '0', '0', '0');

-- Conflagrate
INSERT INTO `spell_coef_override` VALUES ('17962', '0.4293', '0', '0', '0');

-- Ice Barrier
INSERT INTO `spell_coef_override` VALUES ('11426', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13031', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13032', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('13033', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27134', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33405', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('43038', '0', '0.8053', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('43039', '0', '0.8053', '0', '0');

-- Mind Blast
INSERT INTO `spell_coef_override` VALUES ('8092', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8102', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8103', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8104', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8105', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8106', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10945', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10946', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10947', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25372', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25375', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48126', '0.428', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48127', '0.428', '0', '0', '0');

-- Mind Sear
INSERT INTO `spell_coef_override` VALUES ('49821', '0.7143', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53022', '0.7143', '0', '0', '0');

-- Corruption
INSERT INTO `spell_coef_override` VALUES ('172', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6222', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('6223', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('7648', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11671', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('11672', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25311', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27216', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47812', '0', '0.2', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('47813', '0', '0.2', '0', '0');

-- Hurricane
INSERT INTO `spell_coef_override` VALUES ('42231', '0.12898', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42232', '0.12898', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42233', '0.12898', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42230', '0.12898', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48466', '0.12898', '0', '0', '0');

-- Insect Swarm
INSERT INTO `spell_coef_override` VALUES ('5570', '0.127', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('24974', '0.127', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('24975', '0.127', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('24976', '0.127', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('24977', '0.127', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27013', '0.127', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48468', '0.127', '0', '0', '0');

-- Arcane Explosion
INSERT INTO `spell_coef_override` VALUES ('1449', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8437', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8438', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('8439', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10201', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('10202', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27080', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27082', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42920', '0.2128', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('42921', '0.2128', '0', '0', '0');

-- Rip
INSERT INTO `spell_coef_override` VALUES ('1079', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('9492', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('9493', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('9752', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('9894', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('9896', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('27008', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('49799', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('49800', '0', '0', '0.01', '0');

-- Faerie Fire (Feral)
INSERT INTO `spell_coef_override` VALUES ('60089', '0', '0', '0.05', '0');

-- Lacerate
INSERT INTO `spell_coef_override` VALUES ('33745', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('48567', '0', '0', '0.01', '0');
INSERT INTO `spell_coef_override` VALUES ('48567', '0', '0', '0.01', '0');

-- Savage Defense
INSERT INTO `spell_coef_override` VALUES ('62606', '0', '0', '0.25', '0');

-- Arcane Shot
INSERT INTO `spell_coef_override` VALUES ('3044', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14281', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14282', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14283', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14284', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14285', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14286', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('14287', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('27019', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('49044', '0', '0', '0', '0.15');
INSERT INTO `spell_coef_override` VALUES ('49045', '0', '0', '0', '0.15');

-- Kill Shot
INSERT INTO `spell_coef_override` VALUES ('53351', '0', '0', '0', '0.40');
INSERT INTO `spell_coef_override` VALUES ('61005', '0', '0', '0', '0.40');
INSERT INTO `spell_coef_override` VALUES ('61006', '0', '0', '0', '0.40');

-- Multi-Shot
INSERT INTO `spell_coef_override` VALUES ('2643', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('14288', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('14289', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('14290', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('25294', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('27021', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('49047', '0', '0', '0', '0.20');
INSERT INTO `spell_coef_override` VALUES ('49048', '0', '0', '0', '0.20');

-- Serpent Sting
INSERT INTO `spell_coef_override` VALUES ('1978', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13549', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13550', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13551', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13552', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13553', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13554', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('13555', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('25295', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('27016', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('49000', '0', '0', '0', '0.04');
INSERT INTO `spell_coef_override` VALUES ('49001', '0', '0', '0', '0.04');

-- Steady Shot
INSERT INTO `spell_coef_override` VALUES ('56641', '0', '0', '0', '0.10');
INSERT INTO `spell_coef_override` VALUES ('34120', '0', '0', '0', '0.10');
INSERT INTO `spell_coef_override` VALUES ('49051', '0', '0', '0', '0.10');
INSERT INTO `spell_coef_override` VALUES ('49052', '0', '0', '0', '0.10');

-- Explosive Shot
INSERT INTO `spell_coef_override` VALUES ('53301', '0', '0', '0', '0.16');
INSERT INTO `spell_coef_override` VALUES ('60051', '0', '0', '0', '0.16');
INSERT INTO `spell_coef_override` VALUES ('60052', '0', '0', '0', '0.16');
INSERT INTO `spell_coef_override` VALUES ('60053', '0', '0', '0', '0.16');

-- Immolation Trap
INSERT INTO `spell_coef_override` VALUES ('13797', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('14298', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('14299', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('14300', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('14301', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('27024', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('49053', '0', '0', '0', '0.02');
INSERT INTO `spell_coef_override` VALUES ('49054', '0', '0', '0', '0.02');

-- Mongoose Bite
INSERT INTO `spell_coef_override` VALUES ('1495', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('14269', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('14270', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('14271', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('36916', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('53339', '0', '0', '0.20', '0');


-- Avenger's Shield
INSERT INTO `spell_coef_override` VALUES ('31935', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('32699', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('32700', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('48826', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('48827', '0.07', '0', '0.07', '0');

-- Consecration
INSERT INTO `spell_coef_override` VALUES ('26573', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('20116', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('20922', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('20923', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('20924', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('27173', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('48818', '0', '0.04', '0.04', '0');
INSERT INTO `spell_coef_override` VALUES ('48819', '0', '0.04', '0.04', '0');

-- Exorcism
INSERT INTO `spell_coef_override` VALUES ('879', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('5614', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('5615', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('10312', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('10313', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('10314', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('27138', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('48800', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('48801', '0.15', '0', '0.15', '0');

-- Hammer of Wrath
INSERT INTO `spell_coef_override` VALUES ('24275', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('24274', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('24239', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('27180', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('48805', '0.15', '0', '0.15', '0');
INSERT INTO `spell_coef_override` VALUES ('48806', '0.15', '0', '0.15', '0');

-- Hand of Reckoning
INSERT INTO `spell_coef_override` VALUES ('62124', '0.085', '0', '0', '0');

-- Holy Shield
INSERT INTO `spell_coef_override` VALUES ('20925', '0.09', '0', '0.056', '0');
INSERT INTO `spell_coef_override` VALUES ('20927', '0.09', '0', '0.056', '0');
INSERT INTO `spell_coef_override` VALUES ('20928', '0.09', '0', '0.056', '0');
INSERT INTO `spell_coef_override` VALUES ('27179', '0.09', '0', '0.056', '0');
INSERT INTO `spell_coef_override` VALUES ('48951', '0.09', '0', '0.056', '0');
INSERT INTO `spell_coef_override` VALUES ('48952', '0.09', '0', '0.056', '0');

-- Holy Wrath
INSERT INTO `spell_coef_override` VALUES ('2812', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('10318', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('27139', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('48816', '0.07', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('48817', '0.07', '0', '0.07', '0');

-- Seal of Command
INSERT INTO `spell_coef_override` VALUES ('20424', '0.23', '0', '0', '0');

-- Seal of Blood
INSERT INTO `spell_coef_override` VALUES ('31893', '0', '0.02', '0.03', '0');

-- Seal of Vengeance
INSERT INTO `spell_coef_override` VALUES ('31803', '0', '0.025', '0.05', '0');

-- Seal of Corruption
INSERT INTO `spell_coef_override` VALUES ('53742', '0', '0.025', '0.05', '0');

-- Seal of Righteousnes
INSERT INTO `spell_coef_override` VALUES ('21084', '0.07', '0', '0.039', '0');

-- Judgement of Righteousness
INSERT INTO `spell_coef_override` VALUES ('20187', '0.4', '0', '0.25', '0');

-- Judgement of Blood
INSERT INTO `spell_coef_override` VALUES ('31898', '0.25', '0', '0.16', '0');

-- Judgement of the Martyr
INSERT INTO `spell_coef_override` VALUES ('53726', '0.25', '0', '0.16', '0');

-- Judgement of Vengeance
INSERT INTO `spell_coef_override` VALUES ('31804', '0.22', '0', '0.14', '0');

-- Judgement of Wisdom/Judgement of Light/Judgement of Justice (seals, custom unused spell)
INSERT INTO `spell_coef_override` VALUES ('53733', '0.25', '0', '0.16', '0');

-- Judgement of Light
INSERT INTO `spell_coef_override` VALUES ('20267', '0.10', '0', '0.10', '0');

-- Judgement of Command
INSERT INTO `spell_coef_override` VALUES ('20467', '0.25', '0', '0.16', '0');

-- Sacred Shield
INSERT INTO `spell_coef_override` VALUES ('58597', '0.75', '0', '0', '0');

-- Holy Shock - DMG
INSERT INTO `spell_coef_override` VALUES ('25912', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25911', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25902', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27176', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33073', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48822', '0.4286', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48823', '0.4286', '0', '0', '0');

-- Holy Shock - HEAL
INSERT INTO `spell_coef_override` VALUES ('25914', '0.81', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25913', '0.81', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25903', '0.81', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27175', '0.81', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('33074', '0.81', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48820', '0.81', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48821', '0.81', '0', '0', '0');

-- Shamanistic Rage
INSERT INTO `spell_coef_override` VALUES ('30824', '0', '0', '0.30', '0');

-- Heroic Throw
INSERT INTO `spell_coef_override` VALUES ('57755', '0', '0', '0.50', '0');

-- Thunder Clap
INSERT INTO `spell_coef_override` VALUES ('6343', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('8198', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('8204', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('8205', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('11580', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('11581', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('25264', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('47501', '0', '0', '0.12', '0');
INSERT INTO `spell_coef_override` VALUES ('47502', '0', '0', '0.12', '0');

-- Execute
INSERT INTO `spell_coef_override` VALUES ('5308', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('20658', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('20660', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('20661', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('20662', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('25234', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('25236', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('47470', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('47471', '0', '0', '0.20', '0');

-- Intercept
INSERT INTO `spell_coef_override` VALUES ('20252', '0', '0', '0.12', '0');

-- Victory Rush
INSERT INTO `spell_coef_override` VALUES ('34428', '0', '0', '0.45', '0');

-- Revenge
INSERT INTO `spell_coef_override` VALUES ('6572', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('6574', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('7379', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('11600', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('11601', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('25288', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('25269', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('30357', '0', '0', '0.207', '0');
INSERT INTO `spell_coef_override` VALUES ('57823', '0', '0', '0.207', '0');

-- Holy Nova - Heal
INSERT INTO `spell_coef_override` VALUES ('23455', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('23458', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('23459', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27803', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27804', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27805', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25329', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48075', '0.3035', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48076', '0.3035', '0', '0', '0');

-- Holy Nova - Damage
INSERT INTO `spell_coef_override` VALUES ('15237', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15430', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('15431', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27799', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27800', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('27801', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('25331', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48077', '0.1606', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('48078', '0.1606', '0', '0', '0');

-- Penance Heal
INSERT INTO `spell_coef_override` VALUES ('47750', '0.535', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52983', '0.535', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52984', '0.535', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52985', '0.535', '0', '0', '0');

-- Chaos Bolt
INSERT INTO `spell_coef_override` VALUES ('50796', '0.7139', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59170', '0.7139', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59171', '0.7139', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('59172', '0.7139', '0', '0', '0');

-- Immolation Aura
INSERT INTO `spell_coef_override` VALUES ('50590', '0.1622', '0', '0', '0');


-- Garrote
INSERT INTO `spell_coef_override` VALUES ('703', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('8631', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('8632', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('8633', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('11289', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('11290', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('26839', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('26884', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('48675', '0', '0', '0.07', '0');
INSERT INTO `spell_coef_override` VALUES ('48676', '0', '0', '0.07', '0');

-- Gouge
INSERT INTO `spell_coef_override` VALUES ('1776', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('1777', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('8629', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('11285', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('11286', '0', '0', '0.20', '0');
INSERT INTO `spell_coef_override` VALUES ('38764', '0', '0', '0.20', '0');

-- Concussion Blow
INSERT INTO `spell_coef_override` VALUES ('12809', '0', '0', '0.75', '0');

-- Shockwave
INSERT INTO `spell_coef_override` VALUES ('46968', '0', '0', '0.75', '0');

-- Bloodthirst
INSERT INTO `spell_coef_override` VALUES ('23881', '0', '0', '0.50', '0');

-- Instant Poison
INSERT INTO `spell_coef_override` VALUES ('8680', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('8685', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('8689', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('11335', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('11336', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('11337', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('26890', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('57964', '0', '0', '0.10', '0');
INSERT INTO `spell_coef_override` VALUES ('57965', '0', '0', '0.10', '0');

-- Deadly Poison
INSERT INTO `spell_coef_override` VALUES ('2818', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('2819', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('11353', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('11354', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('25349', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('26968', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('27187', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('57969', '0', '0', '0.024', '0');
INSERT INTO `spell_coef_override` VALUES ('57970', '0', '0', '0.024', '0');

-- Wound Poison
INSERT INTO `spell_coef_override` VALUES ('13218', '0', '0', '0.008', '0');
INSERT INTO `spell_coef_override` VALUES ('13222', '0', '0', '0.008', '0');
INSERT INTO `spell_coef_override` VALUES ('13223', '0', '0', '0.008', '0');
INSERT INTO `spell_coef_override` VALUES ('13224', '0', '0', '0.008', '0');
INSERT INTO `spell_coef_override` VALUES ('27189', '0', '0', '0.008', '0');
INSERT INTO `spell_coef_override` VALUES ('57974', '0', '0', '0.008', '0');
INSERT INTO `spell_coef_override` VALUES ('57975', '0', '0', '0.008', '0');

-- Gore
INSERT INTO `spell_coef_override` VALUES ('35290', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35291', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35292', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35293', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35294', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35295', '0', '0', '0', '0.125');

-- Lighting Breath
INSERT INTO `spell_coef_override` VALUES ('24844', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('25008', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('25009', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('25010', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('25011', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('25012', '0', '0', '0', '0.125');

-- Claw
INSERT INTO `spell_coef_override` VALUES ('16827', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('16828', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('16829', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('16830', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('16831', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('16832', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('3010', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('3009', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('27049', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('52471', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('52472', '0', '0', '0', '0.125');

-- Poison Spit
INSERT INTO `spell_coef_override` VALUES ('35387', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35389', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35392', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55555', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55556', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55557', '0', '0', '0', '0.125');

-- Fire Breath
INSERT INTO `spell_coef_override` VALUES ('34889', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('35323', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55482', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55483', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55484', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('55485', '0', '0', '0', '0.125');

-- Bite
INSERT INTO `spell_coef_override` VALUES ('17253', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17255', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17256', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17257', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17258', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17259', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17260', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('17261', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('27050', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('52473', '0', '0', '0', '0.125');
INSERT INTO `spell_coef_override` VALUES ('52474', '0', '0', '0', '0.125');

-- Scorpid Poison
INSERT INTO `spell_coef_override` VALUES ('24640', '0', '0', '0', '0.015');
INSERT INTO `spell_coef_override` VALUES ('24583', '0', '0', '0', '0.015');
INSERT INTO `spell_coef_override` VALUES ('24586', '0', '0', '0', '0.015');
INSERT INTO `spell_coef_override` VALUES ('24587', '0', '0', '0', '0.015');
INSERT INTO `spell_coef_override` VALUES ('27060', '0', '0', '0', '0.015');
INSERT INTO `spell_coef_override` VALUES ('55728', '0', '0', '0', '0.015');
-- ----------------------------
-- Table structure for spell_forced_targets
-- ----------------------------
DROP TABLE IF EXISTS `spell_forced_targets`;
CREATE TABLE `spell_forced_targets` (
  `spellid` int(8) unsigned NOT NULL,
  `target` int(8) unsigned NOT NULL DEFAULT '0',
  UNIQUE KEY `entry_type_target` (`spellid`,`target`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Spell System';

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `spell_forced_targets` VALUES ('7035', '4251');
INSERT INTO `spell_forced_targets` VALUES ('7036', '4252');
INSERT INTO `spell_forced_targets` VALUES ('7393', '15275');
INSERT INTO `spell_forced_targets` VALUES ('7393', '15276');
INSERT INTO `spell_forced_targets` VALUES ('8283', '4781');
INSERT INTO `spell_forced_targets` VALUES ('8593', '6172');
INSERT INTO `spell_forced_targets` VALUES ('8593', '6177');
INSERT INTO `spell_forced_targets` VALUES ('8593', '17542');
INSERT INTO `spell_forced_targets` VALUES ('9012', '6492');
INSERT INTO `spell_forced_targets` VALUES ('9082', '6492');
INSERT INTO `spell_forced_targets` VALUES ('9232', '3976');
INSERT INTO `spell_forced_targets` VALUES ('9257', '3977');
INSERT INTO `spell_forced_targets` VALUES ('9455', '2163');
INSERT INTO `spell_forced_targets` VALUES ('9712', '2726');
INSERT INTO `spell_forced_targets` VALUES ('9976', '7167');
INSERT INTO `spell_forced_targets` VALUES ('9976', '7168');
INSERT INTO `spell_forced_targets` VALUES ('9976', '8391');
INSERT INTO `spell_forced_targets` VALUES ('10113', '7233');
INSERT INTO `spell_forced_targets` VALUES ('10137', '7233');
INSERT INTO `spell_forced_targets` VALUES ('10260', '2748');
INSERT INTO `spell_forced_targets` VALUES ('10345', '25');
INSERT INTO `spell_forced_targets` VALUES ('10345', '2678');
INSERT INTO `spell_forced_targets` VALUES ('10348', '6225');
INSERT INTO `spell_forced_targets` VALUES ('10348', '6226');
INSERT INTO `spell_forced_targets` VALUES ('10348', '6227');
INSERT INTO `spell_forced_targets` VALUES ('10732', '25');
INSERT INTO `spell_forced_targets` VALUES ('10732', '2678');
INSERT INTO `spell_forced_targets` VALUES ('11402', '7774');
INSERT INTO `spell_forced_targets` VALUES ('11513', '6213');
INSERT INTO `spell_forced_targets` VALUES ('11513', '6329');
INSERT INTO `spell_forced_targets` VALUES ('11637', '6218');
INSERT INTO `spell_forced_targets` VALUES ('11637', '6219');
INSERT INTO `spell_forced_targets` VALUES ('11637', '6220');
INSERT INTO `spell_forced_targets` VALUES ('12151', '5273');
INSERT INTO `spell_forced_targets` VALUES ('12347', '8442');
INSERT INTO `spell_forced_targets` VALUES ('12623', '8443');
INSERT INTO `spell_forced_targets` VALUES ('12699', '5307');
INSERT INTO `spell_forced_targets` VALUES ('12699', '5308');
INSERT INTO `spell_forced_targets` VALUES ('12709', '6218');
INSERT INTO `spell_forced_targets` VALUES ('12709', '6219');
INSERT INTO `spell_forced_targets` VALUES ('12709', '6220');
INSERT INTO `spell_forced_targets` VALUES ('12774', '8662');
INSERT INTO `spell_forced_targets` VALUES ('12938', '7664');
INSERT INTO `spell_forced_targets` VALUES ('12938', '7668');
INSERT INTO `spell_forced_targets` VALUES ('13461', '7664');
INSERT INTO `spell_forced_targets` VALUES ('13951', '2520');
INSERT INTO `spell_forced_targets` VALUES ('13982', '9016');
INSERT INTO `spell_forced_targets` VALUES ('14247', '9376');
INSERT INTO `spell_forced_targets` VALUES ('14250', '9520');
INSERT INTO `spell_forced_targets` VALUES ('14806', '9157');
INSERT INTO `spell_forced_targets` VALUES ('14928', '9503');
INSERT INTO `spell_forced_targets` VALUES ('15281', '9816');
INSERT INTO `spell_forced_targets` VALUES ('15591', '9999');
INSERT INTO `spell_forced_targets` VALUES ('15998', '10221');
INSERT INTO `spell_forced_targets` VALUES ('16007', '7047');
INSERT INTO `spell_forced_targets` VALUES ('16007', '7048');
INSERT INTO `spell_forced_targets` VALUES ('16053', '175321');
INSERT INTO `spell_forced_targets` VALUES ('16378', '10541');
INSERT INTO `spell_forced_targets` VALUES ('16452', '10601');
INSERT INTO `spell_forced_targets` VALUES ('16452', '10602');
INSERT INTO `spell_forced_targets` VALUES ('16629', '1852');
INSERT INTO `spell_forced_targets` VALUES ('17048', '10899');
INSERT INTO `spell_forced_targets` VALUES ('17166', '7583');
INSERT INTO `spell_forced_targets` VALUES ('17166', '10977');
INSERT INTO `spell_forced_targets` VALUES ('17166', '10978');
INSERT INTO `spell_forced_targets` VALUES ('17179', '10508');
INSERT INTO `spell_forced_targets` VALUES ('17190', '10508');
INSERT INTO `spell_forced_targets` VALUES ('17536', '11218');
INSERT INTO `spell_forced_targets` VALUES ('17698', '11197');
INSERT INTO `spell_forced_targets` VALUES ('18666', '10937');
INSERT INTO `spell_forced_targets` VALUES ('19032', '12202');
INSERT INTO `spell_forced_targets` VALUES ('19250', '177668');
INSERT INTO `spell_forced_targets` VALUES ('19952', '11502');
INSERT INTO `spell_forced_targets` VALUES ('21794', '10981');
INSERT INTO `spell_forced_targets` VALUES ('21866', '10990');
INSERT INTO `spell_forced_targets` VALUES ('22906', '10184');
INSERT INTO `spell_forced_targets` VALUES ('23015', '12396');
INSERT INTO `spell_forced_targets` VALUES ('23019', '12396');
INSERT INTO `spell_forced_targets` VALUES ('23359', '5357');
INSERT INTO `spell_forced_targets` VALUES ('23359', '5358');
INSERT INTO `spell_forced_targets` VALUES ('23359', '5359');
INSERT INTO `spell_forced_targets` VALUES ('23359', '5360');
INSERT INTO `spell_forced_targets` VALUES ('23359', '5361');
INSERT INTO `spell_forced_targets` VALUES ('23394', '14601');
INSERT INTO `spell_forced_targets` VALUES ('24322', '14834');
INSERT INTO `spell_forced_targets` VALUES ('26235', '15727');
INSERT INTO `spell_forced_targets` VALUES ('27184', '16044');
INSERT INTO `spell_forced_targets` VALUES ('27190', '16045');
INSERT INTO `spell_forced_targets` VALUES ('27191', '16046');
INSERT INTO `spell_forced_targets` VALUES ('27201', '16047');
INSERT INTO `spell_forced_targets` VALUES ('27202', '16048');
INSERT INTO `spell_forced_targets` VALUES ('27203', '16044');
INSERT INTO `spell_forced_targets` VALUES ('27203', '16045');
INSERT INTO `spell_forced_targets` VALUES ('27203', '16046');
INSERT INTO `spell_forced_targets` VALUES ('27203', '16047');
INSERT INTO `spell_forced_targets` VALUES ('27203', '16048');
INSERT INTO `spell_forced_targets` VALUES ('27517', '16079');
INSERT INTO `spell_forced_targets` VALUES ('28806', '16592');
INSERT INTO `spell_forced_targets` VALUES ('28806', '181288');
INSERT INTO `spell_forced_targets` VALUES ('29120', '16899');
INSERT INTO `spell_forced_targets` VALUES ('29121', '16897');
INSERT INTO `spell_forced_targets` VALUES ('29122', '16898');
INSERT INTO `spell_forced_targets` VALUES ('29339', '15547');
INSERT INTO `spell_forced_targets` VALUES ('29339', '15548');
INSERT INTO `spell_forced_targets` VALUES ('29340', '15547');
INSERT INTO `spell_forced_targets` VALUES ('29340', '15548');
INSERT INTO `spell_forced_targets` VALUES ('29364', '16975');
INSERT INTO `spell_forced_targets` VALUES ('29435', '17034');
INSERT INTO `spell_forced_targets` VALUES ('29612', '16468');
INSERT INTO `spell_forced_targets` VALUES ('29989', '17178');
INSERT INTO `spell_forced_targets` VALUES ('30065', '15688');
INSERT INTO `spell_forced_targets` VALUES ('30098', '17253');
INSERT INTO `spell_forced_targets` VALUES ('30166', '17257');
INSERT INTO `spell_forced_targets` VALUES ('30207', '17257');
INSERT INTO `spell_forced_targets` VALUES ('30410', '17257');
INSERT INTO `spell_forced_targets` VALUES ('30427', '17378');
INSERT INTO `spell_forced_targets` VALUES ('30427', '17407');
INSERT INTO `spell_forced_targets` VALUES ('30427', '17408');
INSERT INTO `spell_forced_targets` VALUES ('30427', '24222');
INSERT INTO `spell_forced_targets` VALUES ('30462', '17404');
INSERT INTO `spell_forced_targets` VALUES ('30834', '17646');
INSERT INTO `spell_forced_targets` VALUES ('30875', '17326');
INSERT INTO `spell_forced_targets` VALUES ('30876', '17326');
INSERT INTO `spell_forced_targets` VALUES ('30877', '17326');
INSERT INTO `spell_forced_targets` VALUES ('30988', '17701');
INSERT INTO `spell_forced_targets` VALUES ('31225', '17768');
INSERT INTO `spell_forced_targets` VALUES ('31326', '15608');
INSERT INTO `spell_forced_targets` VALUES ('31333', '17664');
INSERT INTO `spell_forced_targets` VALUES ('31411', '17886');
INSERT INTO `spell_forced_targets` VALUES ('31412', '17886');
INSERT INTO `spell_forced_targets` VALUES ('31413', '17886');
INSERT INTO `spell_forced_targets` VALUES ('31414', '17886');
INSERT INTO `spell_forced_targets` VALUES ('31532', '17796');
INSERT INTO `spell_forced_targets` VALUES ('31537', '17895');
INSERT INTO `spell_forced_targets` VALUES ('31543', '17798');
INSERT INTO `spell_forced_targets` VALUES ('31736', '17998');
INSERT INTO `spell_forced_targets` VALUES ('31736', '17999');
INSERT INTO `spell_forced_targets` VALUES ('31736', '18000');
INSERT INTO `spell_forced_targets` VALUES ('31736', '18002');
INSERT INTO `spell_forced_targets` VALUES ('31927', '18110');
INSERT INTO `spell_forced_targets` VALUES ('31927', '18142');
INSERT INTO `spell_forced_targets` VALUES ('31927', '18143');
INSERT INTO `spell_forced_targets` VALUES ('31927', '18144');
INSERT INTO `spell_forced_targets` VALUES ('32042', '18161');
INSERT INTO `spell_forced_targets` VALUES ('32042', '18162');
INSERT INTO `spell_forced_targets` VALUES ('32045', '17968');
INSERT INTO `spell_forced_targets` VALUES ('32051', '17968');
INSERT INTO `spell_forced_targets` VALUES ('32052', '17968');
INSERT INTO `spell_forced_targets` VALUES ('32146', '18240');
INSERT INTO `spell_forced_targets` VALUES ('32163', '18247');
INSERT INTO `spell_forced_targets` VALUES ('32164', '18246');
INSERT INTO `spell_forced_targets` VALUES ('32205', '18305');
INSERT INTO `spell_forced_targets` VALUES ('32205', '18306');
INSERT INTO `spell_forced_targets` VALUES ('32205', '18307');
INSERT INTO `spell_forced_targets` VALUES ('32307', '17146');
INSERT INTO `spell_forced_targets` VALUES ('32307', '17147');
INSERT INTO `spell_forced_targets` VALUES ('32307', '17148');
INSERT INTO `spell_forced_targets` VALUES ('32307', '18397');
INSERT INTO `spell_forced_targets` VALUES ('32307', '18658');
INSERT INTO `spell_forced_targets` VALUES ('32314', '18393');
INSERT INTO `spell_forced_targets` VALUES ('32560', '17893');
INSERT INTO `spell_forced_targets` VALUES ('32622', '17545');
INSERT INTO `spell_forced_targets` VALUES ('32623', '18660');
INSERT INTO `spell_forced_targets` VALUES ('32838', '16899');
INSERT INTO `spell_forced_targets` VALUES ('32979', '18818');
INSERT INTO `spell_forced_targets` VALUES ('32979', '19009');
INSERT INTO `spell_forced_targets` VALUES ('32979', '21236');
INSERT INTO `spell_forced_targets` VALUES ('32979', '21237');
INSERT INTO `spell_forced_targets` VALUES ('33067', '18849');
INSERT INTO `spell_forced_targets` VALUES ('33067', '19008');
INSERT INTO `spell_forced_targets` VALUES ('33423', '19139');
INSERT INTO `spell_forced_targets` VALUES ('33424', '19139');
INSERT INTO `spell_forced_targets` VALUES ('33425', '19139');
INSERT INTO `spell_forced_targets` VALUES ('33531', '19067');
INSERT INTO `spell_forced_targets` VALUES ('33532', '19210');
INSERT INTO `spell_forced_targets` VALUES ('33796', '16898');
INSERT INTO `spell_forced_targets` VALUES ('33796', '19727');
INSERT INTO `spell_forced_targets` VALUES ('33805', '19387');
INSERT INTO `spell_forced_targets` VALUES ('33806', '19388');
INSERT INTO `spell_forced_targets` VALUES ('33822', '19394');
INSERT INTO `spell_forced_targets` VALUES ('33924', '19424');
INSERT INTO `spell_forced_targets` VALUES ('34062', '19484');
INSERT INTO `spell_forced_targets` VALUES ('34063', '18688');
INSERT INTO `spell_forced_targets` VALUES ('34239', '19599');
INSERT INTO `spell_forced_targets` VALUES ('34367', '19421');
INSERT INTO `spell_forced_targets` VALUES ('34387', '184289');
INSERT INTO `spell_forced_targets` VALUES ('34387', '184290');
INSERT INTO `spell_forced_targets` VALUES ('34387', '184414');
INSERT INTO `spell_forced_targets` VALUES ('34387', '184415');
INSERT INTO `spell_forced_targets` VALUES ('34397', '20139');
INSERT INTO `spell_forced_targets` VALUES ('34630', '19849');
INSERT INTO `spell_forced_targets` VALUES ('34646', '19866');
INSERT INTO `spell_forced_targets` VALUES ('34646', '19867');
INSERT INTO `spell_forced_targets` VALUES ('34646', '19868');
INSERT INTO `spell_forced_targets` VALUES ('34665', '16880');
INSERT INTO `spell_forced_targets` VALUES ('35016', '20209');
INSERT INTO `spell_forced_targets` VALUES ('35016', '20417');
INSERT INTO `spell_forced_targets` VALUES ('35016', '20418');
INSERT INTO `spell_forced_targets` VALUES ('35063', '20251');
INSERT INTO `spell_forced_targets` VALUES ('35097', '20251');
INSERT INTO `spell_forced_targets` VALUES ('35113', '20333');
INSERT INTO `spell_forced_targets` VALUES ('35113', '20336');
INSERT INTO `spell_forced_targets` VALUES ('35113', '20337');
INSERT INTO `spell_forced_targets` VALUES ('35113', '20338');
INSERT INTO `spell_forced_targets` VALUES ('35176', '20440');
INSERT INTO `spell_forced_targets` VALUES ('35246', '20473');
INSERT INTO `spell_forced_targets` VALUES ('35246', '20475');
INSERT INTO `spell_forced_targets` VALUES ('35246', '20476');
INSERT INTO `spell_forced_targets` VALUES ('35282', '20243');
INSERT INTO `spell_forced_targets` VALUES ('35289', '22963');
INSERT INTO `spell_forced_targets` VALUES ('35372', '20561');
INSERT INTO `spell_forced_targets` VALUES ('35413', '20781');
INSERT INTO `spell_forced_targets` VALUES ('35515', '20454');
INSERT INTO `spell_forced_targets` VALUES ('35683', '20769');
INSERT INTO `spell_forced_targets` VALUES ('35724', '20813');
INSERT INTO `spell_forced_targets` VALUES ('35724', '20814');
INSERT INTO `spell_forced_targets` VALUES ('35724', '20815');
INSERT INTO `spell_forced_targets` VALUES ('35724', '20816');
INSERT INTO `spell_forced_targets` VALUES ('35734', '20899');
INSERT INTO `spell_forced_targets` VALUES ('35771', '20610');
INSERT INTO `spell_forced_targets` VALUES ('35771', '20777');
INSERT INTO `spell_forced_targets` VALUES ('35772', '20774');
INSERT INTO `spell_forced_targets` VALUES ('35782', '20809');
INSERT INTO `spell_forced_targets` VALUES ('36374', '21182');
INSERT INTO `spell_forced_targets` VALUES ('36374', '22401');
INSERT INTO `spell_forced_targets` VALUES ('36374', '22402');
INSERT INTO `spell_forced_targets` VALUES ('36374', '22403');
INSERT INTO `spell_forced_targets` VALUES ('36460', '183805');
INSERT INTO `spell_forced_targets` VALUES ('36460', '183806');
INSERT INTO `spell_forced_targets` VALUES ('36460', '183807');
INSERT INTO `spell_forced_targets` VALUES ('36460', '183808');
INSERT INTO `spell_forced_targets` VALUES ('36852', '21440');
INSERT INTO `spell_forced_targets` VALUES ('36854', '21437');
INSERT INTO `spell_forced_targets` VALUES ('36856', '21436');
INSERT INTO `spell_forced_targets` VALUES ('36857', '21438');
INSERT INTO `spell_forced_targets` VALUES ('36858', '21439');
INSERT INTO `spell_forced_targets` VALUES ('37055', '21512');
INSERT INTO `spell_forced_targets` VALUES ('37076', '17798');
INSERT INTO `spell_forced_targets` VALUES ('37204', '21709');
INSERT INTO `spell_forced_targets` VALUES ('37573', '20021');
INSERT INTO `spell_forced_targets` VALUES ('37689', '21847');
INSERT INTO `spell_forced_targets` VALUES ('37784', '21867');
INSERT INTO `spell_forced_targets` VALUES ('37843', '21899');
INSERT INTO `spell_forced_targets` VALUES ('37853', '15608');
INSERT INTO `spell_forced_targets` VALUES ('37936', '17796');
INSERT INTO `spell_forced_targets` VALUES ('37984', '21940');
INSERT INTO `spell_forced_targets` VALUES ('38020', '21949');
INSERT INTO `spell_forced_targets` VALUES ('38044', '21212');
INSERT INTO `spell_forced_targets` VALUES ('38112', '21212');
INSERT INTO `spell_forced_targets` VALUES ('38202', '18733');
INSERT INTO `spell_forced_targets` VALUES ('38360', '20216');
INSERT INTO `spell_forced_targets` VALUES ('38439', '21648');
INSERT INTO `spell_forced_targets` VALUES ('38444', '17008');
INSERT INTO `spell_forced_targets` VALUES ('38449', '21214');
INSERT INTO `spell_forced_targets` VALUES ('38451', '21214');
INSERT INTO `spell_forced_targets` VALUES ('38452', '21214');
INSERT INTO `spell_forced_targets` VALUES ('38455', '21214');
INSERT INTO `spell_forced_targets` VALUES ('38469', '22137');
INSERT INTO `spell_forced_targets` VALUES ('38469', '22139');
INSERT INTO `spell_forced_targets` VALUES ('38482', '22137');
INSERT INTO `spell_forced_targets` VALUES ('38484', '21246');
INSERT INTO `spell_forced_targets` VALUES ('38530', '22177');
INSERT INTO `spell_forced_targets` VALUES ('38729', '22288');
INSERT INTO `spell_forced_targets` VALUES ('38736', '22288');
INSERT INTO `spell_forced_targets` VALUES ('38762', '21722');
INSERT INTO `spell_forced_targets` VALUES ('38782', '22423');
INSERT INTO `spell_forced_targets` VALUES ('39010', '19264');
INSERT INTO `spell_forced_targets` VALUES ('39043', '22377');
INSERT INTO `spell_forced_targets` VALUES ('39094', '22395');
INSERT INTO `spell_forced_targets` VALUES ('39140', '22418');
INSERT INTO `spell_forced_targets` VALUES ('39141', '17968');
INSERT INTO `spell_forced_targets` VALUES ('39189', '21846');
INSERT INTO `spell_forced_targets` VALUES ('39189', '21859');
INSERT INTO `spell_forced_targets` VALUES ('39219', '22443');
INSERT INTO `spell_forced_targets` VALUES ('39246', '22105');
INSERT INTO `spell_forced_targets` VALUES ('39635', '22996');
INSERT INTO `spell_forced_targets` VALUES ('39849', '22996');
INSERT INTO `spell_forced_targets` VALUES ('39873', '22917');
INSERT INTO `spell_forced_targets` VALUES ('40076', '22884');
INSERT INTO `spell_forced_targets` VALUES ('40309', '23055');
INSERT INTO `spell_forced_targets` VALUES ('40401', '22841');
INSERT INTO `spell_forced_targets` VALUES ('40447', '22841');
INSERT INTO `spell_forced_targets` VALUES ('40468', '22252');
INSERT INTO `spell_forced_targets` VALUES ('40603', '22948');
INSERT INTO `spell_forced_targets` VALUES ('40874', '22841');
INSERT INTO `spell_forced_targets` VALUES ('41268', '23412');
INSERT INTO `spell_forced_targets` VALUES ('41269', '23412');
INSERT INTO `spell_forced_targets` VALUES ('41271', '23412');
INSERT INTO `spell_forced_targets` VALUES ('41295', '23418');
INSERT INTO `spell_forced_targets` VALUES ('42222', '23616');
INSERT INTO `spell_forced_targets` VALUES ('42323', '23720');
INSERT INTO `spell_forced_targets` VALUES ('42356', '23751');
INSERT INTO `spell_forced_targets` VALUES ('42356', '23752');
INSERT INTO `spell_forced_targets` VALUES ('42356', '23753');
INSERT INTO `spell_forced_targets` VALUES ('42411', '4328');
INSERT INTO `spell_forced_targets` VALUES ('42411', '4329');
INSERT INTO `spell_forced_targets` VALUES ('42411', '4331');
INSERT INTO `spell_forced_targets` VALUES ('44132', '24239');
INSERT INTO `spell_forced_targets` VALUES ('44320', '24722');
INSERT INTO `spell_forced_targets` VALUES ('44872', '25158');
INSERT INTO `spell_forced_targets` VALUES ('44969', '24980');
INSERT INTO `spell_forced_targets` VALUES ('44981', '24980');
INSERT INTO `spell_forced_targets` VALUES ('45030', '25003');
INSERT INTO `spell_forced_targets` VALUES ('45115', '25090');
INSERT INTO `spell_forced_targets` VALUES ('45115', '25091');
INSERT INTO `spell_forced_targets` VALUES ('45115', '25092');
INSERT INTO `spell_forced_targets` VALUES ('45191', '25154');
INSERT INTO `spell_forced_targets` VALUES ('45191', '25156');
INSERT INTO `spell_forced_targets` VALUES ('45191', '25157');
INSERT INTO `spell_forced_targets` VALUES ('45203', '24882');
INSERT INTO `spell_forced_targets` VALUES ('45223', '25192');
INSERT INTO `spell_forced_targets` VALUES ('45259', '25213');
INSERT INTO `spell_forced_targets` VALUES ('45351', '17845');
INSERT INTO `spell_forced_targets` VALUES ('45368', '187428');
INSERT INTO `spell_forced_targets` VALUES ('45371', '187431');
INSERT INTO `spell_forced_targets` VALUES ('45389', '25265');
INSERT INTO `spell_forced_targets` VALUES ('45839', '25653');
INSERT INTO `spell_forced_targets` VALUES ('46281', '25882');
INSERT INTO `spell_forced_targets` VALUES ('46474', '25315');
INSERT INTO `spell_forced_targets` VALUES ('46475', '25507');
INSERT INTO `spell_forced_targets` VALUES ('46964', '26391');

/* 35_rev_randomcreation */
ALTER TABLE `randomcardcreation` ADD `ItemCount` INT(10) UNSIGNED DEFAULT '0' NOT NULL AFTER `ItemId31`;
UPDATE `randomcardcreation` SET `ItemCount`=32 WHERE `SpellId`=59504;
UPDATE `randomcardcreation` SET `ItemCount`=32 WHERE `SpellId`=59502;
UPDATE `randomcardcreation` SET `ItemCount`=32 WHERE `SpellId`=44317;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=59480;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=59491;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=48247;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=59487;

/* 35_rev_spellfixes */
INSERT INTO `spell_coef_override` VALUES ('47666', '0.229', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52998', '0.229', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('52999', '0.229', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('53000', '0.229', '0', '0', '0');
INSERT INTO `spell_coef_override` VALUES ('16857', '0', '0', '0.15', '0');

REPLACE INTO `spell_forced_targets` VALUES(36310, 20058);

delete from `gameobject_names` where `Name`="Lightwell";

INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (300000, 22, 6671, "Lightwell", 7001, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (300001, 22, 6671, "Lightwell", 27873, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (300002, 22, 6671, "Lightwell", 27874, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (300003, 22, 6671, "Lightwell", 28276, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (300004, 22, 6671, "Lightwell", 48084, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (300005, 22, 6671, "Lightwell", 48085, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/* 36_rev_randomcreation */
CREATE TABLE `randomcardcreation` (
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId0` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId1` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId2` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId4` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId5` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId6` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId7` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId8` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId9` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId10` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId11` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId12` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId13` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId14` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId15` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId16` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId17` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId18` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId19` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId20` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId21` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId22` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId23` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId24` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId25` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId26` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId27` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId28` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId29` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId30` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId31` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

insert  into `randomcardcreation`(`SpellId`,`ItemId0`,`ItemId1`,`ItemId2`,`ItemId3`,`ItemId4`,`ItemId5`,`ItemId6`,`ItemId7`,`ItemId8`,`ItemId9`,`ItemId10`,`ItemId11`,`ItemId12`,`ItemId13`,`ItemId14`,`ItemId15`,`ItemId16`,`ItemId17`,`ItemId18`,`ItemId19`,`ItemId20`,`ItemId21`,`ItemId22`,`ItemId23`,`ItemId24`,`ItemId25`,`ItemId26`,`ItemId27`,`ItemId28`,`ItemId29`,`ItemId30`,`ItemId31`) values (59480,37145,37147,37159,37160,37161,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(59491,44143,44154,44155,44156,44157,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(48247,37140,37143,37156,37157,37158,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(59487,44165,44144,44145,44146,44147,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(44317,31882,31901,31910,31892,31883,31902,31911,31893,31884,31903,31912,31894,31885,31904,31913,31895,31886,31905,31915,31896,31887,31906,31916,31898,31888,31908,31917,31899,31889,31909,31918,31900),(59502,19227,19236,19233,19232,19235,19234,19231,19230,19268,19275,19272,19271,19274,19273,19270,19269,19276,19284,19281,19280,19283,19282,19279,19278,19258,19265,19262,19261,19264,19263,19260,19259),(59504,44277,44285,44281,44280,44284,44282,44279,44278,44286,44293,44290,44289,44292,44291,44288,44287,44268,44275,44272,44271,44274,44273,44270,44269,44260,44267,44264,44263,44266,44265,44262,44261);

CREATE TABLE `randomitemcreation` (
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemToCreate` int(10) unsigned NOT NULL DEFAULT '0',
  `Skill` int(10) unsigned NOT NULL DEFAULT '0',
  `Chance` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ItemToCreate`,`SpellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

insert  into `randomitemcreation`(`SpellId`,`ItemToCreate`,`Skill`,`Chance`) values (48247,0,773,0),(59487,0,773,0),(59480,0,773,0),(53892,41482,755,25),(53866,42450,755,25),(53831,41432,755,25),(53835,41433,755,25),(53852,41444,755,25),(53874,41483,755,25),(53926,41463,755,25),(53877,41484,755,25),(53869,41451,755,25),(53880,41485,755,25),(53832,41434,755,25),(53884,41486,755,25),(53888,41487,755,25),(53918,41464,755,25),(53930,41465,755,25),(53873,41488,755,25),(53876,41489,755,25),(53844,41435,755,25),(53920,41466,755,25),(53845,41436,755,25),(53878,41491,755,25),(53862,41452,755,25),(53871,41453,755,25),(53867,41454,755,25),(53872,41492,755,25),(53925,41467,755,25),(53916,41468,755,25),(53928,41469,755,25),(53879,41493,755,25),(53881,41494,755,25),(53941,41440,755,25),(53922,41470,755,25),(53865,41455,755,25),(53857,41445,755,25),(53929,41471,755,25),(53882,41495,755,25),(54017,41437,755,25),(53887,41496,755,25),(53870,41456,755,25),(53863,41457,755,25),(53856,41446,755,25),(53931,41472,755,25),(53885,41497,755,25),(53893,41498,755,25),(53875,41499,755,25),(53854,41447,755,25),(53864,41459,755,25),(53834,41438,755,25),(53921,41473,755,25),(53933,41474,755,25),(53860,41460,755,25),(53923,41475,755,25),(53853,41448,755,25),(53934,41441,755,25),(53859,41461,755,25),(53940,41442,755,25),(53890,41500,755,25),(53889,41501,755,25),(53919,41476,755,25),(53943,41443,755,25),(53927,41447,755,25),(53932,41478,755,25),(53861,41462,755,25),(53855,41449,755,25),(53894,41479,755,25),(53924,41480,755,25),(53883,41502,755,25),(53917,41481,755,25),(53886,41429,755,25),(53843,41439,755,25),(53868,41458,755,25),(53891,41490,755,25),(59491,0,773,0),(44317,0,773,0),(59502,0,773,0),(59504,0,773,0);

/* 36_rev_spellfixes */
REPLACE INTO `teleport_coords` VALUE(54406, "Teleport to Dalaran", 571, 5807.75, 588.347, 661.505, 0);
REPLACE INTO `teleport_coords` VALUE(53140, "Teleport to Dalaran", 571, 5807.75, 588.347, 661.505, 0);
REPLACE INTO totemspells VALUES(8512, 8515, 0, 0);
REPLACE INTO totemspells VALUES(8227, 52109, 0, 0);
REPLACE INTO totemspells VALUES(8249, 52110, 0, 0);
REPLACE INTO totemspells VALUES(10526, 52111, 0, 0);
REPLACE INTO totemspells VALUES(16387, 52112, 0, 0);
REPLACE INTO totemspells VALUES(25557, 52113, 0, 0);
REPLACE INTO totemspells VALUES(58649, 58651, 0, 0);
REPLACE INTO totemspells VALUES(58652, 58654, 0, 0);
REPLACE INTO totemspells VALUES(58656, 58655, 0, 0);

update totemspells set castspell1=8263 where spell=8262;

REPLACE INTO totemspells VALUES(30706, 57658, 0, 0);
REPLACE INTO totemspells VALUES(57720, 57660, 0, 0);
REPLACE INTO totemspells VALUES(57721, 57662, 0, 0);
REPLACE INTO totemspells VALUES(57722, 57663, 0, 0);

REPLACE INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (189318, 6, 3074, "Immolation Trap VII", 12, 0, 5, 49053, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

REPLACE INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (189321, 6, 3074, "Explosive Trap V", 12, 0, 5, 49064, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

REPLACE INTO `spell_forced_targets` VALUES(36314, 20132);
REPLACE INTO `spell_forced_targets` VALUES(41291, 22357);
REPLACE INTO `spell_forced_targets` VALUES(38177, 21387);
REPLACE INTO `spell_forced_targets` VALUES(4130, 2760);
REPLACE INTO `spell_forced_targets` VALUES(4131, 2761);
REPLACE INTO `spell_forced_targets` VALUES(4132, 2762);
REPLACE INTO `spell_forced_targets` VALUES(38177, 21387);
REPLACE INTO `spell_forced_targets` VALUES(45072, 25031);
REPLACE INTO `spell_forced_targets` VALUES(45072, 25033);
REPLACE INTO `spell_forced_targets` VALUES(45072, 25030);
REPLACE INTO `spell_forced_targets` VALUES(36310, 20058);

update `gameobject_names` set `sound1`=5 where `sound1`<5 AND `Type`=8;

REPLACE INTO items values
  (40773, 0, 8, -1, "Master Firestone", "", "", "", 7409, 1, 2097216, 0, 0, 0, -1, -1, 56, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54721, 0, -5, 1000, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 1, "", 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0);

update `gameobject_names` set `spellfocus` = 4 where `name` LIKE "%fire%" AND `type` = 8 AND `spellfocus` = 0;
update `gameobject_names` set `sound2` =  0 where `name` LIKE "%fire%" AND `type` = 8 AND `spellfocus` = 4;

REPLACE INTO totemspells VALUES(58771, 58775, 0, 0);
REPLACE INTO totemspells VALUES(58773, 58776, 0, 0);
REPLACE INTO totemspells VALUES(58774, 58777, 0, 0);

DELETE FROM gameobject_names where name="Soul Portal";
DELETE FROM gameobject_names where name="Soulwell";

INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (181622, 18, 7358, "Soul Portal", 3, 29886, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (193168, 18, 7358, "Soul Portal", 3, 58889, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (193169, 22, 7359, "Soulwell", 34150, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO gameobject_names
  (entry, Type, DisplayID, Name, spellfocus, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, unknown1, unknown2, unknown3, unknown4, unknown5, unknown6, unknown7, unknown8, unknown9, unknown10, unknown11, unknown12, unknown13, unknown14)
VALUES
  (181621, 22, 7359, "Soulwell", 34130, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/* 50_rev_updates */
CREATE TABLE `scrollcreation` (
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellId`,`ItemId`)
);

-- Table structure for table `randomcardcreation`

CREATE TABLE `randomcardcreation` (
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId0` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId1` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId2` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId4` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId5` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId6` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId7` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId8` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId9` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId10` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId11` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId12` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId13` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId14` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId15` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId16` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId17` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId18` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId19` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId20` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId21` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId22` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId23` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId24` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId25` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId26` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId27` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId28` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId29` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId30` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId31` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Data for the table `randomcardcreation` 

insert  into `randomcardcreation`(`SpellId`,`ItemId0`,`ItemId1`,`ItemId2`,`ItemId3`,`ItemId4`,`ItemId5`,`ItemId6`,`ItemId7`,`ItemId8`,`ItemId9`,`ItemId10`,`ItemId11`,`ItemId12`,`ItemId13`,`ItemId14`,`ItemId15`,`ItemId16`,`ItemId17`,`ItemId18`,`ItemId19`,`ItemId20`,`ItemId21`,`ItemId22`,`ItemId23`,`ItemId24`,`ItemId25`,`ItemId26`,`ItemId27`,`ItemId28`,`ItemId29`,`ItemId30`,`ItemId31`) values (59480,37145,37147,37159,37160,37161,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(59491,44143,44154,44155,44156,44157,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(48247,37140,37143,37156,37157,37158,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(59487,44165,44144,44145,44146,44147,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),(44317,31882,31901,31910,31892,31883,31902,31911,31893,31884,31903,31912,31894,31885,31904,31913,31895,31886,31905,31915,31896,31887,31906,31916,31898,31888,31908,31917,31899,31889,31909,31918,31900),(59502,19227,19236,19233,19232,19235,19234,19231,19230,19268,19275,19272,19271,19274,19273,19270,19269,19276,19284,19281,19280,19283,19282,19279,19278,19258,19265,19262,19261,19264,19263,19260,19259),(59504,44277,44285,44281,44280,44284,44282,44279,44278,44286,44293,44290,44289,44292,44291,44288,44287,44268,44275,44272,44271,44274,44273,44270,44269,44260,44267,44264,44263,44266,44265,44262,44261);

-- Table structure for table `randomitemcreation` 

CREATE TABLE `randomitemcreation` (
  `SpellId` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemToCreate` int(10) unsigned NOT NULL DEFAULT '0',
  `Skill` int(10) unsigned NOT NULL DEFAULT '0',
  `Chance` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ItemToCreate`,`SpellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Data for the table `randomitemcreation`

insert  into `randomitemcreation`(`SpellId`,`ItemToCreate`,`Skill`,`Chance`) values (48247,0,773,0),(59487,0,773,0),(59480,0,773,0),(53892,41482,755,25),(53866,42450,755,25),(53831,41432,755,25),(53835,41433,755,25),(53852,41444,755,25),(53874,41483,755,25),(53926,41463,755,25),(53877,41484,755,25),(53869,41451,755,25),(53880,41485,755,25),(53832,41434,755,25),(53884,41486,755,25),(53888,41487,755,25),(53918,41464,755,25),(53930,41465,755,25),(53873,41488,755,25),(53876,41489,755,25),(53844,41435,755,25),(53920,41466,755,25),(53845,41436,755,25),(53878,41491,755,25),(53862,41452,755,25),(53871,41453,755,25),(53867,41454,755,25),(53872,41492,755,25),(53925,41467,755,25),(53916,41468,755,25),(53928,41469,755,25),(53879,41493,755,25),(53881,41494,755,25),(53941,41440,755,25),(53922,41470,755,25),(53865,41455,755,25),(53857,41445,755,25),(53929,41471,755,25),(53882,41495,755,25),(54017,41437,755,25),(53887,41496,755,25),(53870,41456,755,25),(53863,41457,755,25),(53856,41446,755,25),(53931,41472,755,25),(53885,41497,755,25),(53893,41498,755,25),(53875,41499,755,25),(53854,41447,755,25),(53864,41459,755,25),(53834,41438,755,25),(53921,41473,755,25),(53933,41474,755,25),(53860,41460,755,25),(53923,41475,755,25),(53853,41448,755,25),(53934,41441,755,25),(53859,41461,755,25),(53940,41442,755,25),(53890,41500,755,25),(53889,41501,755,25),(53919,41476,755,25),(53943,41443,755,25),(53927,41447,755,25),(53932,41478,755,25),(53861,41462,755,25),(53855,41449,755,25),(53894,41479,755,25),(53924,41480,755,25),(53883,41502,755,25),(53917,41481,755,25),(53886,41429,755,25),(53843,41439,755,25),(53868,41458,755,25),(53891,41490,755,25),(59491,0,773,0),(44317,0,773,0),(59502,0,773,0),(59504,0,773,0);

ALTER TABLE `randomcardcreation` ADD `ItemCount` INT(10) UNSIGNED DEFAULT '0' NOT NULL AFTER `ItemId31`;
UPDATE `randomcardcreation` SET `ItemCount`=32 WHERE `SpellId`=59504;
UPDATE `randomcardcreation` SET `ItemCount`=32 WHERE `SpellId`=59502;
UPDATE `randomcardcreation` SET `ItemCount`=32 WHERE `SpellId`=44317;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=59480;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=59491;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=48247;
UPDATE `randomcardcreation` SET `ItemCount`=5 WHERE `SpellId`=59487;

INSERT INTO `prestartqueries` VALUES ('DELETE  FROM clientaddons', '0', '1');

/* 70_rev_ritual_of_summoning */
REPLACE INTO `gameobject_names` (`entry`, `type`, `displayid`, `name`, `spellfocus`, `sound1`, `sound2`, `sound3`, `sound4`, `sound5`, `sound6`, `sound7`, `sound8`, `sound9`, `unknown1`, `unknown2`, `unknown3`, `unknown4`, `unknown5`, `unknown6`, `unknown7`, `unknown8`, `unknown9`, `unknown10`, `unknown11`, `unknown12`, `unknown13`, `unknown14`) VALUES('194108','18','7358','Summoning Portal','3','61993','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0');
REPLACE INTO `gameobject_names` (`entry`, `type`, `displayid`, `name`, `spellfocus`, `sound1`, `sound2`, `sound3`, `sound4`, `sound5`, `sound6`, `sound7`, `sound8`, `sound9`, `unknown1`, `unknown2`, `unknown3`, `unknown4`, `unknown5`, `unknown6`, `unknown7`, `unknown8`, `unknown9`, `unknown10`, `unknown11`, `unknown12`, `unknown13`, `unknown14`) values('194097','23','8548','Summoning Portal','1','300','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0');

/* 70_rev_updates */
UPDATE `creature_waypoints` SET `forwardSayText`='' WHERE  `forwardSayText` = '0';
UPDATE `creature_waypoints` SET `backwardSayText`='' WHERE  `backwardSayText` = '0';

alter table creature_proto change column resistance6 `resistance7` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column resistance5 `resistance6` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column resistance4 `resistance5` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column resistance3 `resistance4` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column resistance2 `resistance3` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column resistance1 `resistance2` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column armor `resistance1` int(30) UNSIGNED NOT NULL DEFAULT 0;
alter table creature_proto change column equipmodel1 `Item1` int(30) UNSIGNED NOT NULL DEFAULT 0 ;
alter table creature_proto change column equipmodel2 `Item2` int(30) UNSIGNED NOT NULL DEFAULT 0 ;
alter table creature_proto change column equipmodel3 `Item3` int(30) UNSIGNED NOT NULL DEFAULT 0 ;

ALTER TABLE ai_agents CHANGE spelltype spelltype enum('ROOT','HEAL','STUN','FEAR','SILENCE','CURSE','AOEDAMAGE','DAMAGE','SUMMON','BUFF','DEBUFF','INTERRUPT') NOT NULL DEFAULT 'ROOT';
UPDATE ai_agents SET spelltype = 'DEBUFF' where spelltype = 'CURSE';
UPDATE ai_agents SET spelltype = 'INTERRUPT' where spelltype = 'SILENCE';
ALTER TABLE ai_agents CHANGE spelltype spelltype enum('ROOT','DAMAGE','AOEDAMAGE','INTERRUPT','FEAR','STUN','BUFF','DEBUFF','SUMMON','HEAL') NOT NULL DEFAULT 'ROOT';
DELETE FROM clientaddons WHERE 1 = 1;

/* 72_rev_events_system */
DROP TABLE IF EXISTS `events`;

CREATE TABLE `events` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'Id of event you want to trigger',
  `daynumber` tinyint(3) unsigned NOT NULL COMMENT '1 - 31 day of the month you want to trigger event',
  `monthnumber` tinyint(3) unsigned DEFAULT '0' COMMENT '1 - 12 month of the year you want to trigger event',
  `eventname` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL COMMENT 'Just for human readable purposes, this is not used by the server at all',
  `activedays` tinyint(3) unsigned DEFAULT NULL COMMENT 'Number of days the event will remain active',
  `ishourlyevent` tinyint(1) DEFAULT NULL COMMENT 'Is this an hourly event? This cannot be used in conjunction with daily events',
  `starthour` tinyint(3) unsigned DEFAULT NULL COMMENT '0 - 23 the hour that the event begins',
  `endhour` tinyint(3) unsigned DEFAULT NULL COMMENT '0 - 23 the hour that the event ends, if this is smaller that the starthour, it will end on the next day',
  PRIMARY KEY (`eventid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Table structure for table `events_creature`

DROP TABLE IF EXISTS `events_creature`;

CREATE TABLE `events_creature` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'Relates to creature_spawn eventid',
  `id` tinyint(3) unsigned NOT NULL COMMENT 'Relates to creature_spawn id',
  `changesflag` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'See enum in the core for permissable flags in World.h',
  `phase` tinyint(3) DEFAULT NULL COMMENT 'This is the phase the creature is in when the event is active',
  `displayid` int(10) unsigned DEFAULT NULL COMMENT 'This is the displayid to change to while the event is active',
  `item1` int(10) unsigned DEFAULT NULL COMMENT 'This is the id of equip slot 1 to change while the event is active',
  `item2` int(10) unsigned DEFAULT NULL COMMENT 'This is the id of equip slot 2 to change while the event is active',
  `item3` int(10) unsigned DEFAULT NULL COMMENT 'This is the id of equip slot 3 to change while the event is active',
  PRIMARY KEY (`eventid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- Table structure for table `events_gameobject`

DROP TABLE IF EXISTS `events_gameobject`;

CREATE TABLE `events_gameobject` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'This relates to gameobject_spawns eventid',
  `id` int(11) unsigned NOT NULL COMMENT 'Relates to gameobject_spawn id',
  `changesflag` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'See enum in core for permissable flags in World.h',
  `phase` tinyint(3) DEFAULT NULL COMMENT 'Phase the go is in when the event is active',
  `displayid` int(10) unsigned DEFAULT NULL COMMENT 'This is the displayid to change to while the event is active',
  PRIMARY KEY (`eventid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

alter table `gameobject_spawns` add column `eventid` tinyint (3)UNSIGNED  DEFAULT '0' NOT NULL after `phase`;
alter table `creature_spawns` add column `eventid` tinyint (3)UNSIGNED  DEFAULT '0' NOT NULL  after `vehicle`;

/* 159_rev_updates */
ALTER TABLE `creature_names` ADD `TypeFlags` INT( 10 ) UNSIGNED NOT NULL DEFAULT '0' AFTER `type`;   
RENAME TABLE `skinningloot` TO `creatureloot_gathering`;
 CREATE TABLE `creature_stats_heroic` (  
 `entry` int(10) NOT NULL,  
 `Minlevel` int(10) unsigned NOT NULL default '0',  
 `Maxlevel` int(10) unsigned NOT NULL default '0',  
 `Minhealth` int(10) NOT NULL default '1',  
 `Maxhealth` int(10) NOT NULL default '1',  
 `Mindmg` int(10) NOT NULL default '1',  
 `Maxdmg` int(10) NOT NULL default '1',  
 `mana` int(10) NOT NULL default '1',  
 `armor` int(10) NOT NULL default '0',  
 `Holy_Resistance` int(10) NOT NULL default '0',  
 `Fire_Resistance` int(10) NOT NULL default '0',  
 `Nature_Resistance` int(10) NOT NULL default '0',  
 `Frost_Resistance` int(10) NOT NULL default '0',  
 `Shadow_Resistance` int(10) NOT NULL default '0',  
 `Arcane_Resistance` int(10) NOT NULL default '0',  
 `auras` longtext NOT NULL,  
 `auraimmune_flag` int(10) NOT NULL default '0',  
 PRIMARY KEY  (`entry`)
 ) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Heroic Npc Tables';
ALTER TABLE `items` ADD COLUMN `ExistingDuration` INT(30) NOT NULL DEFAULT 0 AFTER `ArmorDamageModifier`,
ADD COLUMN `ItemLimitCategoryId` INT(30) NOT NULL DEFAULT 0 AFTER `ExistingDuration`;
UPDATE items SET ItemLimitCategoryId = '2' WHERE entry in ('42142','36766','42143','42153','42146','42152','42148','42158','42150','42144','36767','42155','42151','42145','42149','42156','42154','42157');
UPDATE items SET ItemLimitCategoryId = '3' WHERE entry in ('36891', '36890','36889','36892','36893','36894','19010','19011','5510','19008','5509','19009','5511','19006','19007','19012','9421','19013','22104','22103','22105','5512','19005','19004');
UPDATE items SET ItemLimitCategoryId = '4' WHERE entry in ('5514','3552','10053','8008','22044','33312');
UPDATE items SET ItemLimitCategoryId = '6' WHERE entry in ('45862','45882','45879','45987','45883','45880','45881');
INSERT INTO `npc_text` VALUES (30000,1,"The Dual Talent Specialization allows you to keep two active talent specs. You will be able to easily switch between these two specializations. When you switch between specs, you will also get access to a second glyph pane and a second set of action bars and keybindings.","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0);

/* 185_rev_updates */
DROP TABLE IF EXISTS `spell_proc_override`;

CREATE TABLE `spell_proc_override` (
  `ID` int(6) NOT NULL,
  `ProcFlags` int(32) NOT NULL DEFAULT '0',
  `ExtraProc` int(32) NOT NULL DEFAULT '0',
  `ProcChance` int(3) NOT NULL DEFAULT '-1',
  `PPM` float(10,0) NOT NULL DEFAULT '0',
  `ProcCharges` int(3) NOT NULL DEFAULT '-1',
  `ProcInterval` int(10) NOT NULL DEFAULT '0',
  `ProcModify` int(1) NOT NULL DEFAULT '0',
  `SpellClassMask1_1` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask1_2` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask1_3` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask2_1` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask2_2` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask2_3` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask3_1` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask3_2` int(32) NOT NULL DEFAULT '-1',
  `SpellClassMask3_3` int(32) NOT NULL DEFAULT '-1',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `spell_proc_override` */

insert  into `spell_proc_override`(`ID`,`ProcFlags`,`ExtraProc`,`ProcChance`,`PPM`,`ProcCharges`,`ProcInterval`,`ProcModify`,`SpellClassMask1_1`,`SpellClassMask1_2`,`SpellClassMask1_3`,`SpellClassMask2_1`,`SpellClassMask2_2`,`SpellClassMask2_3`,`SpellClassMask3_1`,`SpellClassMask3_2`,`SpellClassMask3_3`) values (66,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(168,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(324,67240616,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(325,67240616,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(588,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(602,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(742,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(758,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(905,67240616,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(945,67240616,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(974,67240616,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(1006,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(1120,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,16384,0,0),(1719,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3235,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3284,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3338,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3394,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3411,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3417,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3418,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3424,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3436,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3439,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3440,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3509,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3512,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3582,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3616,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(3637,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4064,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4065,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4066,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4067,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4068,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4069,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4070,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4112,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4113,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4114,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4115,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4133,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4136,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4138,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4140,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4142,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4144,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4241,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4242,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4245,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4279,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4283,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4284,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4315,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4317,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4493,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4525,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4932,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(4951,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5104,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5118,656040,8192,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5202,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5205,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5262,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5301,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5364,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5368,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5369,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5370,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5377,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5427,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5680,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5728,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5811,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(5952,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6268,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6346,2048,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6397,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6398,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6399,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6433,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6645,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6750,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6752,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6867,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6871,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6909,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6921,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6923,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6947,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(6961,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7095,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7098,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7102,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7103,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7128,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7137,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7276,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7300,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7301,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7302,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7320,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7383,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7445,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7446,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7486,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7617,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7619,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7711,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7720,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7721,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7722,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7723,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7724,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7725,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7726,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7806,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7807,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7808,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7849,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(7999,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8134,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8224,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8247,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8260,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8288,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8289,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8397,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8601,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8612,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8788,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8852,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8876,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(8981,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9160,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9233,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9276,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9452,65876,0,25,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9460,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9463,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9778,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9782,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9784,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(9799,131752,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10022,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10092,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10219,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10220,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10400,20,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10425,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10426,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10431,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10432,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10951,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(10952,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11071,65536,0,5,0,-1,0,0,544,4160,0,-1,-1,-1,-1,-1,-1),(11095,65536,0,33,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11103,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11119,65536,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11120,65536,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11180,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11185,65536,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(11213,536936448,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11255,4096,0,-1,0,-1,0,0,16384,0,0,-1,-1,-1,-1,-1,-1),(11371,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11441,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11675,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11919,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11959,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11964,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(11984,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12043,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12099,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12169,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12246,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12254,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12281,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12289,1024,0,-1,0,-1,0,0,2,0,0,-1,-1,-1,-1,-1,-1),(12298,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12311,272,0,-1,0,-1,0,0,2048,1,0,-1,-1,-1,-1,-1,-1),(12317,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12319,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12322,4,0,0,2,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12357,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12358,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12421,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12487,65536,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(12488,65536,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(12496,65536,0,10,0,-1,0,0,544,4160,0,-1,-1,-1,-1,-1,-1),(12497,65536,0,15,0,-1,0,0,544,4160,0,-1,-1,-1,-1,-1,-1),(12529,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12536,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12539,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12543,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12544,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12550,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12556,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12562,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12574,536936448,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12575,536936448,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12576,536936448,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12577,536936448,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12598,4096,0,-1,0,-1,0,0,16384,0,0,-1,-1,-1,-1,-1,-1),(12668,1024,0,-1,0,-1,0,0,2,0,0,-1,-1,-1,-1,-1,-1),(12724,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12725,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12726,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12727,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12782,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12787,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12797,16,0,25,0,-1,0,0,1024,0,0,-1,-1,-1,-1,-1,-1),(12799,16,0,50,0,-1,0,0,1024,0,0,-1,-1,-1,-1,-1,-1),(12812,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12813,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12814,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12815,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12834,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12846,65536,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12847,65536,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12848,65536,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12849,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12867,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12872,65536,0,66,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12873,65536,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12947,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12958,272,0,-1,0,-1,0,0,2048,1,0,-1,-1,-1,-1,-1,-1),(12966,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12967,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12968,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12969,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12970,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12971,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12972,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12973,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12974,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(12999,4,0,0,3,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13000,4,0,0,5,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13001,4,0,0,6,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13002,4,0,0,8,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13045,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13046,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13047,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13048,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13159,656040,8192,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13163,8,8,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13165,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13299,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13585,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13616,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13716,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13743,1024,0,50,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13754,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13808,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13867,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13875,1024,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13879,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13886,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13959,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13960,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13961,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13962,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13963,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13964,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13976,536870928,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13979,536870928,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13980,536870928,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(13983,131752,40,33,0,-1,1000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14070,131752,40,66,0,-1,1000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14071,131752,40,100,0,-1,1000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14108,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14111,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14133,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14143,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14144,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14148,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14149,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14156,16,0,-1,0,-1,0,1,4063232,9,0,-1,-1,-1,-1,-1,-1),(14160,16,0,-1,0,-1,0,1,4063232,9,0,-1,-1,-1,-1,-1,-1),(14161,16,0,-1,0,-1,0,1,4063232,9,0,-1,-1,-1,-1,-1,-1),(14177,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14178,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14179,536870928,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14186,16,1,-1,0,-1,0,1,0,0,0,0,0,0,0,0,0),(14190,16,1,-1,0,-1,0,1,0,0,0,0,0,0,0,0,0),(14193,16,1,-1,0,-1,0,1,0,0,0,0,0,0,0,0,0),(14194,16,1,-1,0,-1,0,1,0,0,0,0,0,0,0,0,0),(14195,16,1,-1,0,-1,0,1,0,0,0,0,0,0,0,0,0),(14318,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14319,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14320,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14321,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14322,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14531,680,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14751,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14774,680,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14796,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14869,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(14892,16384,1,-1,0,-1,0,0,268443136,65540,0,-1,-1,-1,-1,-1,-1),(15088,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15097,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15128,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15257,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15258,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15268,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15270,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15277,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15323,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15324,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15325,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15326,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15331,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15332,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15335,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15336,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15337,65536,1,-1,0,-1,0,0,8192,2,0,-1,-1,-1,-1,-1,-1),(15338,65536,1,-1,0,-1,0,0,8192,2,0,-1,-1,-1,-1,-1,-1),(15346,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15362,16384,1,-1,0,-1,0,0,268443136,65540,0,-1,-1,-1,-1,-1,-1),(15363,16384,1,-1,0,-1,0,0,268443136,65540,0,-1,-1,-1,-1,-1,-1),(15506,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15507,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15567,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15568,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15569,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15573,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15594,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15599,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15600,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15603,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15636,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15641,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15709,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15730,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15733,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15784,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15849,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15852,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15876,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(15978,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16086,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16142,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16146,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16164,65536,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16176,16384,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16180,16384,1,-1,0,-1,0,1,192,0,16,-1,-1,-1,-1,-1,-1),(16188,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16196,16384,1,-1,0,-1,0,1,192,-1,16,-1,-1,-1,-1,-1,-1),(16198,16384,1,-1,0,-1,0,1,192,-1,16,-1,-1,-1,-1,-1,-1),(16235,16384,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16240,16384,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16246,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16247,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16256,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16257,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16277,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16278,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16279,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16280,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16281,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16282,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16283,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16284,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16311,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16312,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16313,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16428,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16487,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16489,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16492,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16511,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16550,40,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16574,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16575,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16611,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16615,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16620,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16624,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16689,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16792,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16800,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16810,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16811,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16812,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16813,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16843,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16850,65536,0,3,0,-1,0,0,4,0,0,-1,-1,-1,-1,-1,-1),(16864,82260,0,6,0,2,10000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16870,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16880,536953104,1,33,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16886,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16923,65536,0,6,0,-1,0,0,4,0,0,-1,-1,-1,-1,-1,-1),(16924,65536,0,9,0,-1,0,0,4,0,0,-1,-1,-1,-1,-1,-1),(16952,16,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16954,16,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16958,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16961,20,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(16982,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17010,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17014,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17106,1024,0,100,0,-1,0,0,-1,-1,-1,524288,0,0,-1,-1,-1),(17107,1024,0,100,0,-1,0,0,-1,-1,-1,524288,0,0,-1,-1,-1),(17108,1024,0,100,0,-1,0,0,-1,-1,-1,524288,0,0,-1,-1,-1),(17116,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17329,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17332,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17347,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17348,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17350,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17495,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17687,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17688,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17690,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17767,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17768,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17793,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(17794,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17796,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(17797,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17798,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17799,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17800,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17801,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(17802,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(17803,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(17850,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17851,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17852,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17853,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17854,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17941,65536,0,100,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17945,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17947,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(17949,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18073,65536,1,100,0,-1,0,0,256,8388608,0,-1,-1,-1,-1,-1,-1),(18094,262144,0,2,0,-1,0,0,10,0,0,-1,-1,-1,-1,-1,-1),(18095,262144,0,4,0,-1,0,0,10,0,0,-1,-1,-1,-1,-1,-1),(18096,65536,1,100,0,-1,0,0,256,8388608,0,-1,-1,-1,-1,-1,-1),(18097,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18100,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18119,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18120,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18146,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18167,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18186,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18189,65808,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18213,805306368,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18372,805306368,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18499,537002664,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18542,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18708,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18799,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18815,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18816,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18847,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18943,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18979,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(18983,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19184,4194304,0,-1,0,-1,0,0,20,8192,0,-1,-1,-1,-1,-1,-1),(19194,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19228,16,0,-1,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(19232,16,0,-1,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(19233,16,0,-1,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(19387,4194304,0,-1,0,-1,0,0,20,8192,0,-1,-1,-1,-1,-1,-1),(19388,4194304,0,-1,0,-1,0,0,20,8192,0,-1,-1,-1,-1,-1,-1),(19409,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19449,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19514,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19577,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19621,4,1,20,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19622,4,1,40,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19623,4,1,60,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19624,4,1,80,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19625,4,1,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19769,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19784,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19817,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(19818,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20049,81940,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20056,81940,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20057,81940,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20127,8,128,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20128,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20130,8,128,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20131,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20132,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20135,8,128,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20164,4,0,0,6,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20165,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20166,4,0,25,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20177,537002664,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20178,537002664,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20179,537002664,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20180,537002664,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20181,537002664,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20182,537002664,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20185,8,0,35,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20186,131752,0,35,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20210,16384,1,20,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20212,16384,1,40,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20213,16384,1,60,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20214,16384,1,80,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20215,16384,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20216,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20230,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20234,4096,0,25,0,-1,0,0,32768,0,0,-1,-1,-1,-1,-1,-1),(20235,4096,0,50,0,-1,0,0,32768,0,0,-1,-1,-1,-1,-1,-1),(20335,65536,0,100,0,-1,0,0,8388608,0,0,-1,-1,-1,-1,-1,-1),(20336,65536,0,100,0,-1,0,0,8388608,0,0,-1,-1,-1,-1,-1,-1),(20337,65536,0,100,0,-1,0,0,8388608,0,0,-1,-1,-1,-1,-1,-1),(20375,4,0,0,7,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20500,536871936,0,100,0,-1,0,0,268435456,0,0,-1,-1,-1,-1,-1,-1),(20501,536871936,0,100,0,-1,0,0,268435456,0,0,-1,-1,-1,-1,-1,-1),(20545,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20705,8,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20725,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20847,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20884,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20891,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20911,8,28,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20925,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20927,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(20928,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21053,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21061,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21080,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21089,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21091,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21185,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21334,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21645,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21747,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21788,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21838,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21841,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21853,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21882,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21887,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21890,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21897,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21911,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21969,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(21978,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22007,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22010,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22413,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22438,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22618,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22620,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22648,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22812,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22835,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(22857,8,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23340,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23378,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23537,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23548,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23551,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23552,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23572,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23578,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23581,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23591,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23686,4,0,-1,3,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23688,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23689,20,0,-1,3,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23695,1024,0,-1,0,-1,0,0,2,0,0,-1,-1,-1,-1,-1,-1),(23721,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23771,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23780,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23863,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23867,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(23885,4,0,-1,0,3,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24051,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24256,4,64,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24353,65556,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24389,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24392,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24398,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24574,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(24905,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25020,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25023,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25050,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25296,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25431,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25469,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25472,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25513,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25669,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25767,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25820,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25899,8,28,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25906,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(25988,131752,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26016,65876,0,25,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26107,16,30,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26119,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26128,4096,32,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26135,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26376,135848,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26463,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26467,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26480,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26605,65876,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26612,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26614,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(26864,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27009,67108872,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27044,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27124,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27179,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27217,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27243,268443648,512,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27252,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27272,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27419,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27498,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27521,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27522,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27561,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27656,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27688,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27774,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27776,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27778,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27780,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27781,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27785,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27787,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27811,680,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27815,680,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27816,680,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27867,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(27997,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28200,67108864,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28429,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28458,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28460,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28592,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28593,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28714,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28752,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28761,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28762,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28771,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28772,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28780,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28787,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28802,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28812,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28814,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28815,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28816,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28821,28821,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28831,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(28845,327680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29074,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29075,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29076,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29118,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29119,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29150,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29162,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29179,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29180,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29185,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29194,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29196,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29198,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29202,16384,0,-1,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(29205,16384,0,-1,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(29206,16384,0,-1,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(29220,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29291,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29299,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29307,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29315,393216,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29363,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29385,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29441,131072,32,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29444,131072,32,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29455,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29494,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29497,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29501,320,0,30,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29593,40,28,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29594,40,28,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29601,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29624,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29625,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29626,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29632,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29633,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29634,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29635,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29636,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29637,320,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29723,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29724,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29725,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29788,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29793,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29794,640,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29801,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29834,2048,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29836,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29838,2048,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29859,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29908,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29976,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(29977,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30079,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30080,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30081,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30108,8192,256,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30160,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30216,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30217,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30293,65536,0,10,0,-1,0,1,385,8519872,0,-1,-1,-1,-1,-1,-1),(30295,65536,0,20,0,-1,0,1,385,8519872,0,-1,-1,-1,-1,-1,-1),(30296,65536,0,30,0,-1,0,1,385,8519872,0,-1,-1,-1,-1,-1,-1),(30299,131072,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30301,131072,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30302,131072,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30326,81920,0,100,0,-1,0,1,262160,0,0,-1,-1,-1,-1,-1,-1),(30403,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30404,8192,256,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30405,8192,256,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30461,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30475,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30482,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30516,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30550,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30557,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30562,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30564,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30567,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30598,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30636,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30675,65536,0,7,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30678,65536,0,14,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30679,65536,0,20,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30802,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30808,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30809,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30823,536870916,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30881,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30883,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30884,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30885,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30886,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(30937,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31073,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31124,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31126,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31138,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31255,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31256,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31386,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31394,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31396,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31398,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31426,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31569,1024,0,-1,0,-1,0,0,-1,-1,-1,65536,0,0,-1,-1,-1),(31570,1024,0,-1,0,-1,0,0,-1,-1,-1,65536,0,0,-1,-1,-1),(31641,136,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31661,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31734,136,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31757,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31765,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31785,294912,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31794,82944,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31828,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31829,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31830,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31833,16384,0,-1,0,1,0,0,-2147483648,0,0,-1,-1,-1,-1,-1,-1),(31834,16384,0,100,0,2,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31835,16384,0,-1,0,1,0,0,-2147483648,0,0,-1,-1,-1,-1,-1,-1),(31836,16384,0,-1,0,1,0,0,-2147483648,0,0,-1,-1,-1,-1,-1,-1),(31892,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31904,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31976,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(31997,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32008,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32066,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32106,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32215,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32339,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32385,65536,0,100,0,-1,0,0,1,262144,0,-1,-1,-1,-1,-1,-1),(32387,65536,0,100,0,-1,0,0,1,262144,0,-1,-1,-1,-1,-1,-1),(32392,65536,0,100,0,-1,0,0,1,262144,0,-1,-1,-1,-1,-1,-1),(32393,65536,0,100,0,-1,0,0,1,262144,0,-1,-1,-1,-1,-1,-1),(32394,65536,0,100,0,-1,0,0,1,262144,0,-1,-1,-1,-1,-1,-1),(32429,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32587,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32593,67240616,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32594,67240616,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32642,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32682,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32732,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32734,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32776,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32777,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32837,4096,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32844,4,0,5,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32850,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32861,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32885,131616,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32898,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32900,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32912,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32970,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32980,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(32981,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33012,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33014,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33041,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33042,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33043,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33089,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33127,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33142,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33145,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33146,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33150,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33151,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33154,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33191,262144,0,-1,0,-1,0,0,32768,1024,1024,-1,-1,-1,-1,-1,-1),(33192,262144,0,-1,0,-1,0,0,32768,1024,1024,-1,-1,-1,-1,-1,-1),(33193,262144,0,-1,0,-1,0,0,32768,1024,1024,-1,-1,-1,-1,-1,-1),(33297,536936448,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33299,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33493,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33510,68,0,7,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33511,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33522,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33648,68,1,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33731,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33736,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33746,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33757,4,0,20,0,-1,3000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33759,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33776,294912,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33881,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33882,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33883,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33896,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33949,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(33953,278528,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34027,16,0,-1,0,3,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34074,68,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34080,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34112,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34138,16384,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(34139,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34158,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34191,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34258,65536,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34262,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34303,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34320,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34323,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34329,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34343,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34355,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34365,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34392,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34455,65876,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34457,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34459,65876,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34460,65876,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34477,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34497,256,1,33,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(34498,256,1,66,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(34499,256,1,100,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(34500,320,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34502,320,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34503,320,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34506,536870976,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34507,536870976,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34508,536870976,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34524,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34582,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34584,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34586,68,0,-1,2,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34598,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34657,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34697,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34700,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34749,65536,32,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34753,16384,1,-1,0,-1,0,0,6144,4,0,-1,-1,-1,-1,-1,-1),(34754,16384,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34774,68,0,-1,2,0,20000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34784,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34827,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34838,536870976,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34839,536870976,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34859,16384,1,-1,0,-1,0,0,6144,4,0,-1,-1,-1,-1,-1,-1),(34860,16384,1,-1,0,-1,0,0,6144,4,0,-1,-1,-1,-1,-1,-1),(34935,680,0,-1,0,-1,8000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34936,65536,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34938,680,0,-1,0,-1,8000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34939,680,0,-1,0,-1,8000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34948,536870914,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34949,536870914,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34950,320,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(34954,320,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35004,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35005,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35029,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35035,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35077,131752,0,-1,0,-1,55000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35080,4,0,-1,0,-1,55000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35083,65536,0,-1,0,-1,55000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35086,81920,0,-1,0,-1,55000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35098,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35099,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35100,256,0,-1,0,-1,0,0,4096,0,1,-1,-1,-1,-1,-1,-1),(35101,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35102,256,0,-1,0,-1,0,0,4096,0,1,-1,-1,-1,-1,-1,-1),(35103,256,0,-1,0,-1,0,0,4096,0,1,0,0,0,0,0,0),(35121,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35123,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35184,8192,256,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35186,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35187,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35188,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35191,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35192,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35193,8192,512,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35205,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35230,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35249,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35250,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35319,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35346,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35408,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35541,8388608,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35550,8388608,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35551,8388608,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35552,8388608,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35553,8388608,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35685,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35691,1024,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35692,1024,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35693,1024,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35747,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35848,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35877,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35915,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35922,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35942,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(35948,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36032,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36056,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36101,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36111,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36173,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36488,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36515,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36541,327680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36563,16,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36576,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36582,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36635,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36637,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36640,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36733,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36788,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(36881,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37016,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37030,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37165,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37168,16,0,15,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37170,4,0,4,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37171,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37173,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37189,16384,4097,100,0,-1,60000,0,-2147481600,0,0,-1,-1,-1,-1,-1,-1),(37191,1024,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37193,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37195,65536,0,6,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37197,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37213,65536,1,0,11,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(37214,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37227,16384,4097,100,0,-1,60000,0,448,0,0,-1,-1,-1,-1,-1,-1),(37228,65536,0,7,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(37234,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37237,65536,1,25,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(37239,4,0,2,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37240,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37247,4096,0,-1,0,-1,45000,1,0,0,0,-1,-1,-1,-1,-1,-1),(37289,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37306,4,0,4,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37311,4,0,4,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37316,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37325,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37336,81924,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37375,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37377,65536,0,5,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(37386,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37443,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37447,1024,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37496,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37499,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37507,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37514,40,4,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37516,16,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37517,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37519,20,12,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37522,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37523,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37525,131752,0,7,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37528,16,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37529,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37536,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37555,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37558,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37564,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37568,16384,0,-1,0,-1,0,0,2048,0,0,-1,-1,-1,-1,-1,-1),(37570,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37594,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37600,65536,0,6,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(37601,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37603,262144,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37604,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37611,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37617,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37618,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37619,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37655,4096,0,-1,0,-1,45000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37657,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37705,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37706,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37721,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37722,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37723,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(37982,4,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38008,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38026,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38031,680,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38149,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38184,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38290,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38297,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38299,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38319,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38326,65876,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38327,65876,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38332,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38334,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38347,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38350,68,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38363,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38379,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38394,262144,0,-1,0,-1,0,0,6,0,0,-1,-1,-1,-1,-1,-1),(38427,4,0,20,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38432,16,0,100,0,-1,0,0,0,16,0,-1,-1,-1,-1,-1,-1),(38471,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38519,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38520,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38793,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38805,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38847,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(38905,131752,524288,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39009,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39027,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39057,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39067,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39071,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39215,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39437,65536,0,5,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(39438,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39440,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39442,65876,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39443,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39444,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39530,82944,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39556,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39598,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39647,65556,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39831,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39832,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39867,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39950,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(39958,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40250,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40291,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40334,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40336,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40350,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40394,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40407,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40438,262144,0,10,0,-1,0,0,32768,0,1024,64,0,1024,-1,-1,-1),(40442,81936,0,30,0,-1,0,0,0,1088,0,4,0,0,16,0,0),(40444,8,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40458,16,0,-1,0,-1,0,0,33554432,1536,0,-1,-1,-1,-1,-1,-1),(40460,16,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40470,81920,0,50,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40475,340,0,20,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40478,262144,0,-1,0,-1,0,0,2,0,0,-1,-1,-1,-1,-1,-1),(40482,81920,1,-1,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(40484,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40485,256,0,-1,0,-1,0,0,4096,0,0,-1,-1,-1,-1,-1,-1),(40546,8,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40594,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40740,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40771,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40773,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40816,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40899,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(40971,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41034,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41037,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41042,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41151,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41191,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41248,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41260,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41262,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41266,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41381,8192,512,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41393,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41434,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41459,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41913,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(41989,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42083,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42135,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42136,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42368,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42370,16384,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(42556,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42730,32768,4096,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42949,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(42950,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43008,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43045,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43046,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43124,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43224,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43339,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43506,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43508,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43580,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43726,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43728,16384,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(43730,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43737,16,0,-1,0,-1,0,0,0,1088,0,-1,-1,-1,-1,-1,-1),(43739,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43741,16384,0,100,0,-1,0,0,-2147483648,0,0,0,0,0,0,0,0),(43745,65536,0,40,0,-1,0,1,8388608,0,0,-1,-1,-1,-1,-1,-1),(43748,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43750,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(43816,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43818,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43819,82944,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43820,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43822,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43823,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43837,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43840,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43841,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43842,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43843,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43844,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43845,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43850,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43851,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43852,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43854,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43855,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43856,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43857,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43858,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43859,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43860,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43861,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43862,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43877,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43929,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43945,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(43983,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44373,16,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44401,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44404,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44442,65536,0,-1,0,-1,0,0,8388608,64,0,-1,-1,-1,-1,-1,-1),(44443,65536,0,-1,0,-1,0,0,8388608,64,0,-1,-1,-1,-1,-1,-1),(44445,65536,1,33,0,-1,0,1,19,135168,8,0,0,0,0,0,0),(44446,65536,1,66,0,-1,0,1,19,135168,8,0,0,0,0,0,0),(44448,65536,1,100,0,-1,0,1,19,135168,8,0,0,0,0,0,0),(44449,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44469,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44470,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44471,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44472,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44480,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44537,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44543,65536,0,5,0,-1,0,0,544,4160,8,-1,-1,-1,-1,-1,-1),(44545,65536,0,10,0,-1,0,0,544,4160,8,-1,-1,-1,-1,-1,-1),(44546,65536,0,-1,0,-1,0,0,544,4096,8,-1,-1,-1,-1,-1,-1),(44548,65536,0,-1,0,-1,0,0,544,4096,8,-1,-1,-1,-1,-1,-1),(44549,65536,0,-1,0,-1,0,0,544,4096,8,-1,-1,-1,-1,-1,-1),(44599,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44604,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(44809,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45040,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45054,262144,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45057,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45059,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45095,65556,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45234,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45243,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45244,131752,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45354,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45355,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45444,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(45985,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46024,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46025,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46030,65556,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46046,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46048,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46088,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46090,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46091,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46092,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46095,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46096,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46097,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46098,16384,0,-1,0,-1,0,0,128,0,0,-1,-1,-1,-1,-1,-1),(46184,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46267,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46277,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46352,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46364,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46478,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46483,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46484,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46548,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46662,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46744,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46832,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46833,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46854,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46855,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46867,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46910,4,0,50,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46911,4,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46913,16,0,-1,0,-1,0,0,64,1028,0,-1,-1,-1,-1,-1,-1),(46914,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46915,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46916,16,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46939,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46945,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46949,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(46951,16,0,10,0,-1,0,0,1024,64,-1,-1,-1,-1,-1,-1,-1),(46952,16,0,20,0,-1,0,0,1024,64,-1,-1,-1,-1,-1,-1,-1),(46953,16,0,30,0,-1,0,0,1024,64,-1,-1,-1,-1,-1,-1,-1),(47195,262144,0,-1,0,-1,30000,0,2,0,0,-1,-1,-1,-1,-1,-1),(47196,262144,0,-1,0,-1,30000,0,2,0,0,-1,-1,-1,-1,-1,-1),(47197,262144,0,-1,0,-1,30000,0,2,0,0,-1,-1,-1,-1,-1,-1),(47201,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47202,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47203,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47204,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47205,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47230,327680,0,50,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(47231,327680,0,100,0,-1,0,1,0,0,0,-1,-1,-1,-1,-1,-1),(47245,327680,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47246,327680,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47247,327680,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47258,65536,0,100,0,4,0,0,8388608,8388608,0,-1,-1,-1,-1,-1,-1),(47259,65536,0,100,0,4,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47260,65536,0,100,0,4,0,0,8388608,8388608,0,-1,-1,-1,-1,-1,-1),(47261,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47262,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47263,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47264,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47265,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47269,65536,0,-1,0,-1,0,0,8388608,8388608,0,-1,-1,-1,-1,-1,-1),(47271,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47283,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47509,16384,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47511,16384,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47515,16384,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47516,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47517,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47580,262144,0,-1,0,-1,0,0,0,0,64,-1,-1,-1,-1,-1,-1),(47581,262144,0,-1,0,-1,0,0,0,0,64,-1,-1,-1,-1,-1,-1),(47582,262144,0,-1,0,-1,0,0,0,0,64,-1,-1,-1,-1,-1,-1),(47699,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47841,8192,256,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47843,8192,256,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(47987,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48040,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48110,131752,0,100,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48111,131752,0,100,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48168,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48266,393896,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48294,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48389,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48392,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48393,131752,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48405,16,30,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48473,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48483,16,0,-1,0,-1,0,0,34816,1088,0,-1,-1,-1,-1,-1,-1),(48484,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48485,16,0,-1,0,-1,0,0,34816,1088,0,-1,-1,-1,-1,-1,-1),(48496,16384,1,33,0,-1,0,0,96,33554434,0,-1,-1,-1,-1,-1,-1),(48499,16384,1,66,0,-1,0,0,96,33554434,0,-1,-1,-1,-1,-1,-1),(48500,16384,1,100,0,-1,0,0,96,33554434,0,-1,-1,-1,-1,-1,-1),(48504,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48506,65536,0,-1,0,-1,0,0,5,0,0,-1,-1,-1,-1,-1,-1),(48510,65536,0,-1,0,-1,0,0,5,0,0,-1,-1,-1,-1,-1,-1),(48511,65536,0,-1,0,-1,0,0,5,0,0,-1,-1,-1,-1,-1,-1),(48516,65536,1,100,0,-1,30000,0,4,0,0,1,0,0,-1,-1,-1),(48521,65536,1,100,0,-1,30000,0,4,0,0,1,0,0,-1,-1,-1),(48525,65536,1,100,0,-1,30000,0,4,0,0,1,0,0,-1,-1,-1),(48584,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48660,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48833,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48835,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48837,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48876,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48951,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48952,67108904,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(48988,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49004,40,1037,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49005,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49018,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49121,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49137,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49163,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49182,4096,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49188,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49200,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49222,20,1024,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49280,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49281,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49283,67240616,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49284,67240616,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49500,4096,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49501,4096,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49503,65876,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49504,65876,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49508,40,1037,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49509,40,1037,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49529,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49530,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49622,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49657,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49676,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49713,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49717,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49796,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(49871,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50040,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50041,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50043,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50044,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50151,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50152,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50197,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50227,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50248,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50262,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50264,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50303,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50347,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50412,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50413,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50416,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50419,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50421,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50506,393896,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50637,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50654,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50689,393896,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50714,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50720,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50728,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50831,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50871,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50908,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(50920,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51123,4,0,0,1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51127,4,0,0,2,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51128,4,0,0,3,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51129,4,0,0,4,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51130,4,0,0,5,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51209,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51291,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51346,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51349,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51352,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51359,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51414,40,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51466,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51470,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51474,2048,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51478,2048,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51479,2048,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51525,20,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51526,20,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51527,20,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51528,4,0,0,2,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51529,4,0,0,4,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51530,4,0,0,6,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51531,4,0,0,8,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51532,4,0,0,10,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51556,16384,1,-1,0,-1,0,1,-1,-1,192,0,16,-1,-1,-1,-1),(51557,16384,1,-1,0,-1,0,1,-1,-1,192,0,16,-1,-1,-1,-1),(51558,16384,1,-1,0,-1,0,1,-1,-1,192,0,16,-1,-1,-1,-1),(51562,16384,0,-1,0,-1,0,0,256,0,16,-1,-1,-1,-1,-1,-1),(51563,16384,0,-1,0,-1,0,0,256,0,16,-1,-1,-1,-1,-1,-1),(51564,16384,0,-1,0,-1,0,0,256,0,16,-1,-1,-1,-1,-1,-1),(51565,16384,0,-1,0,-1,0,0,256,0,16,-1,-1,-1,-1,-1,-1),(51566,16384,0,-1,0,-1,0,0,256,0,16,-1,-1,-1,-1,-1,-1),(51620,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51627,8,28,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51628,8,28,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51629,8,28,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51634,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51635,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51636,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51672,8,8,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51674,8,8,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51679,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51682,340,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51692,16,1,-1,0,-1,0,0,512,0,0,-1,-1,-1,-1,-1,-1),(51696,16,1,-1,0,-1,0,0,512,0,0,-1,-1,-1,-1,-1,-1),(51698,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51700,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51701,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51703,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51706,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51776,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51810,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51876,131072,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51915,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51940,278528,4096,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(51989,278528,4096,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52004,278528,4096,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52005,278528,4096,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52007,278528,4096,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52008,278528,4096,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52020,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52101,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52127,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52129,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52131,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52134,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52136,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52138,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52290,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52321,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52342,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52418,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52420,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52423,8,4,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52530,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52628,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52642,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52651,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52701,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52710,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52734,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52795,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52797,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52798,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52799,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52800,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52825,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52856,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52871,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52898,131072,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52916,82192,1,100,0,-1,4000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(52979,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53137,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53138,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53186,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53187,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53215,64,0,-1,0,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1),(53216,64,0,-1,0,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1),(53217,64,0,-1,0,-1,0,0,0,0,0,-1,-1,-1,-1,-1,-1),(53220,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53221,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53222,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53224,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53228,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53232,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53256,256,1,-1,0,-1,0,0,6144,8388608,0,-1,-1,-1,-1,-1,-1),(53259,256,1,-1,0,-1,0,0,6144,8388608,0,-1,-1,-1,-1,-1,-1),(53260,256,1,-1,0,-1,0,0,6144,8388608,0,-1,-1,-1,-1,-1,-1),(53290,262400,1,33,0,-1,0,1,6144,-2147483648,0,-1,-1,-1,-1,-1,-1),(53291,262400,1,66,0,-1,0,1,6144,-2147483648,0,-1,-1,-1,-1,-1,-1),(53292,262400,1,100,0,-1,0,1,6144,-2147483648,0,-1,-1,-1,-1,-1,-1),(53312,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53355,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53371,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53380,65552,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53381,65552,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53382,65552,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53383,65552,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53384,65552,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53386,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53390,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53397,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53401,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53476,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53486,65552,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53488,65552,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53489,16384,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53501,16384,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53502,16384,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53503,16384,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53514,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53515,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53516,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53551,4096,0,-1,0,-1,0,0,4096,0,0,-1,-1,-1,-1,-1,-1),(53552,4096,0,-1,0,-1,0,0,4096,0,0,-1,-1,-1,-1,-1,-1),(53553,4096,0,-1,0,-1,0,0,4096,0,0,-1,-1,-1,-1,-1,-1),(53569,81920,1,-1,0,-1,0,0,2097152,65536,0,-1,-1,-1,-1,-1,-1),(53576,81920,1,-1,0,-1,0,0,2097152,65536,0,-1,-1,-1,-1,-1,-1),(53601,537002664,0,100,0,-1,6000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53646,65540,1,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53668,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53671,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53672,16384,0,-1,0,2,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53673,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53703,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53720,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53756,2048,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53814,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53816,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53817,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53818,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(53819,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54149,16384,0,-1,0,2,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54151,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54154,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54155,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54174,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54176,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54178,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54274,66560,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54276,66560,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54277,66560,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54278,131752,1,5,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54306,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54309,32768,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54404,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54450,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54467,66216,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54476,393896,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54479,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54486,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54488,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54489,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54490,65536,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54493,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54515,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54524,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54582,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54608,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54646,65536,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54647,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54695,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54696,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54707,12,0,-1,0,-1,60000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54715,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54738,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54741,65536,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54747,2048,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54749,2048,0,50,0,-1,60000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54808,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54838,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54841,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54909,65540,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54913,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54921,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(54937,16384,0,100,0,-1,0,1,-2147483648,0,0,-1,-1,-1,-1,-1,-1),(55067,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55166,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55193,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55225,4096,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55226,4096,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55380,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55381,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55461,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55599,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55603,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55640,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55666,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55667,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55668,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55669,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55670,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55689,81920,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55735,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55742,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55747,68,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55755,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55768,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55776,4,0,-1,0,-1,60000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55843,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(55970,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56035,268435456,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56145,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56218,262144,0,4,0,-1,0,0,2,0,0,-1,-1,-1,-1,-1,-1),(56249,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56333,65536,0,-1,0,-1,0,0,4,-2147483648,0,-1,-1,-1,-1,-1,-1),(56336,65536,0,-1,0,-1,0,0,4,-2147483648,0,-1,-1,-1,-1,-1,-1),(56337,65536,0,-1,0,-1,0,0,4,-2147483648,0,-1,-1,-1,-1,-1,-1),(56342,4456448,0,33,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56343,4456448,0,66,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56344,4456448,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56355,40,16,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56364,1024,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56443,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56444,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56445,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56451,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56453,256,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56583,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56584,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56604,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56611,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56612,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56613,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56614,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56623,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56636,262144,0,-1,0,-1,6000,0,32,0,0,-1,-1,-1,-1,-1,-1),(56637,262144,0,-1,0,-1,6000,0,32,0,0,-1,-1,-1,-1,-1,-1),(56638,262144,0,-1,0,-1,6000,0,32,0,0,-1,-1,-1,-1,-1,-1),(56707,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56708,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56816,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56821,16,1,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(56822,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57345,81920,0,-1,0,-1,45000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57348,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57351,131756,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57352,65876,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57378,1,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57408,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57455,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57481,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57529,4096,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57531,4096,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57545,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57688,131080,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57769,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57791,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57802,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57907,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57935,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(57960,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58357,16,1,100,0,-1,0,0,64,0,0,-1,-1,-1,-1,-1,-1),(58363,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58364,16,0,-1,0,-1,0,0,1024,0,0,-1,-1,-1,-1,-1,-1),(58372,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58386,8,4,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58413,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58422,536870928,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58423,536870928,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58424,536870928,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58425,536870928,0,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58435,262144,0,100,0,-1,0,1,2,256,0,-1,-1,-1,-1,-1,-1),(58436,262144,0,100,0,-1,0,1,2,256,0,-1,-1,-1,-1,-1,-1),(58437,262144,0,100,0,-1,0,1,2,256,0,-1,-1,-1,-1,-1,-1),(58442,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58444,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58501,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58583,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58584,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58585,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58616,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58620,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58626,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58631,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58642,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58677,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58781,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58784,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58791,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58792,4,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58835,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58872,40,16,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58874,40,16,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58901,68,1,10,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58914,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58948,65540,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(58981,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59022,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59025,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59052,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59057,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59140,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59143,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59176,131072,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59213,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59237,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59240,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59274,20,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59301,65876,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59327,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59345,4,64,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59352,32768,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59407,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59454,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59471,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59479,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59578,16384,0,-1,0,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59609,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59735,32768,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59745,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59776,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59787,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59818,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59845,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59887,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59888,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59889,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59890,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(59891,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60013,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60061,278528,4096,-1,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60063,65536,0,-1,0,-1,45000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60066,4,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60132,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60170,262144,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60172,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60176,262144,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60221,131752,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60301,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60306,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60312,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60313,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60317,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60436,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60442,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60470,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60473,81920,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60482,65536,0,15,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60485,81920,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60487,262144,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60490,81920,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60493,81920,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60503,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60510,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60512,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60513,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60514,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60515,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60517,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60519,81920,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60524,4096,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60529,16384,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60537,81920,1,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60543,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60546,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60548,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60550,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60552,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60554,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60564,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60571,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60572,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60573,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60574,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60575,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60576,65536,0,-1,0,-1,0,1,8388608,0,0,-1,-1,-1,-1,-1,-1),(60577,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60617,8,4,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60632,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60633,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60634,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60635,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60636,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60675,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60685,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60686,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60687,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60688,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60690,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60693,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60695,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60696,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60698,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60700,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60701,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60710,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60717,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60719,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60720,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60722,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60724,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60726,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60765,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60770,65536,0,-1,0,-1,0,0,1,0,0,-1,-1,-1,-1,-1,-1),(60781,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60794,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60799,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60818,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(60826,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61015,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61062,16384,0,100,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61165,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61185,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61188,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61189,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61324,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61345,536952832,1,66,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61346,536952832,1,100,0,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61356,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61367,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61548,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61555,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61570,680,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61571,16,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61587,8,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61595,65536,1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61618,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61846,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61847,64,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(61848,8,8,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(62114,4096,0,-1,0,-1,45000,1,-1,-1,-1,-1,-1,-1,-1,-1,-1),(62115,68,0,-1,0,-1,45000,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(62147,4,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(62259,2,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1),(62459,65536,0,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

/*Table structure for table `spell_coef_override` */

DROP TABLE IF EXISTS `spell_coef_override`;

CREATE TABLE `spell_coef_override` (
  `id` int(11) NOT NULL DEFAULT '0',
  `Base_coef` float DEFAULT '0',
  `Misc_coef` float DEFAULT '0',
  `AP_coef` float DEFAULT '0',
  `RAP_coef` float DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `spell_coef_override` */

insert  into `spell_coef_override`(`id`,`Base_coef`,`Misc_coef`,`AP_coef`,`RAP_coef`) values (686,0.8569,0,0,0),(695,0.8569,0,0,0),(705,0.8569,0,0,0),(1088,0.8569,0,0,0),(1106,0.8569,0,0,0),(7641,0.8569,0,0,0),(11659,0.8569,0,0,0),(11660,0.8569,0,0,0),(11661,0.8569,0,0,0),(25307,0.8569,0,0,0),(27209,0.8569,0,0,0),(47808,0.8569,0,0,0),(47809,0.8569,0,0,0),(8187,0.1,0,0,0),(10579,0.1,0,0,0),(10580,0.1,0,0,0),(10581,0.1,0,0,0),(25550,0.1,0,0,0),(58732,0.1,0,0,0),(58735,0.1,0,0,0),(34861,0.402,0,0,0),(34863,0.402,0,0,0),(34864,0.402,0,0,0),(34865,0.402,0,0,0),(34866,0.402,0,0,0),(48088,0.402,0,0,0),(48089,0.402,0,0,0),(31661,0.1936,0,0,0),(33041,0.1936,0,0,0),(33042,0.1936,0,0,0),(33043,0.1936,0,0,0),(42949,0.1936,0,0,0),(42950,0.1936,0,0,0),(8443,0.2142,0,0,0),(8504,0.2142,0,0,0),(8505,0.2142,0,0,0),(11310,0.2142,0,0,0),(11311,0.2142,0,0,0),(25538,0.2142,0,0,0),(25539,0.2142,0,0,0),(61650,0.2142,0,0,0),(61654,0.2142,0,0,0),(8042,0.3858,0,0,0),(8044,0.3858,0,0,0),(8045,0.3858,0,0,0),(8046,0.3858,0,0,0),(10412,0.3858,0,0,0),(10413,0.3858,0,0,0),(10414,0.3858,0,0,0),(25454,0.3858,0,0,0),(49230,0.3858,0,0,0),(49231,0.3858,0,0,0),(19236,0.8068,0,0,0),(19238,0.8068,0,0,0),(19240,0.8068,0,0,0),(19241,0.8068,0,0,0),(19242,0.8068,0,0,0),(19243,0.8068,0,0,0),(25437,0.8068,0,0,0),(48172,0.8068,0,0,0),(48173,0.8068,0,0,0),(1064,0.8,0,0,0),(10622,0.8,0,0,0),(10623,0.8,0,0,0),(25422,0.8,0,0,0),(25423,0.8,0,0,0),(55458,0.8,0,0,0),(55459,0.8,0,0,0),(29722,0.7139,0,0,0),(32231,0.7139,0,0,0),(47837,0.7139,0,0,0),(47838,0.7139,0,0,0),(8050,0.2142,0.1,0,0),(8052,0.2142,0.1,0,0),(8053,0.2142,0.1,0,0),(10447,0.2142,0.1,0,0),(10448,0.2142,0.1,0,0),(29228,0.2142,0.1,0,0),(25457,0.2142,0.1,0,0),(49232,0.2142,0.1,0,0),(49233,0.2142,0.1,0,0),(42208,0.1437,0,0,0),(42209,0.1437,0,0,0),(42210,0.1437,0,0,0),(42211,0.1437,0,0,0),(42212,0.1437,0,0,0),(42213,0.1437,0,0,0),(42198,0.1437,0,0,0),(42937,0.1437,0,0,0),(42938,0.1437,0,0,0),(52041,0.045,0,0,0),(52046,0.045,0,0,0),(52047,0.045,0,0,0),(52048,0.045,0,0,0),(52049,0.045,0,0,0),(52050,0.045,0,0,0),(58759,0.045,0,0,0),(58760,0.045,0,0,0),(58761,0.045,0,0,0),(6229,0.3,0,0,0),(11739,0.3,0,0,0),(11740,0.3,0,0,0),(28610,0.3,0,0,0),(47890,0.3,0,0,0),(47891,0.3,0,0,0),(30451,0.7143,0,0,0),(42894,0.7143,0,0,0),(42896,0.7143,0,0,0),(42897,0.7143,0,0,0),(8936,0.539,0.188,0,0),(8938,0.539,0.188,0,0),(8939,0.539,0.188,0,0),(8940,0.539,0.188,0,0),(8941,0.539,0.188,0,0),(9750,0.539,0.188,0,0),(9856,0.539,0.188,0,0),(9857,0.539,0.188,0,0),(9858,0.539,0.188,0,0),(26980,0.539,0.188,0,0),(48442,0.539,0.188,0,0),(48443,0.539,0.188,0,0),(20167,0.15,0,0.15,0),(50464,0.6611,0,0,0),(5740,0.6932,0,0,0),(6219,0.6932,0,0,0),(11677,0.6932,0,0,0),(11678,0.6932,0,0,0),(27212,0.6932,0,0,0),(47819,0.6932,0,0,0),(47820,0.6932,0,0,0),(2944,0.1849,0,0,0),(19276,0.1849,0,0,0),(19277,0.1849,0,0,0),(19278,0.1849,0,0,0),(19279,0.1849,0,0,0),(19280,0.1849,0,0,0),(25467,0.1849,0,0,0),(48299,0.1849,0,0,0),(48300,0.1849,0,0,0),(20168,0.25,0,0,0),(5143,0.2857,0,0,0),(5144,0.2857,0,0,0),(5145,0.2857,0,0,0),(8416,0.2857,0,0,0),(8417,0.2857,0,0,0),(10211,0.2857,0,0,0),(10212,0.2857,0,0,0),(25345,0.2857,0,0,0),(27075,0.2857,0,0,0),(38699,0.2857,0,0,0),(38704,0.2857,0,0,0),(42843,0.2857,0,0,0),(42846,0.2857,0,0,0),(33763,0.6453,0.09518,0,0),(48450,0.6453,0.09518,0,0),(48451,0.6453,0.09518,0,0),(139,0.36,0,0,0),(6074,0.36,0,0,0),(6075,0.36,0,0,0),(6076,0.36,0,0,0),(6077,0.36,0,0,0),(6078,0.36,0,0,0),(10927,0.36,0,0,0),(10928,0.36,0,0,0),(10929,0.36,0,0,0),(25315,0.36,0,0,0),(25221,0.36,0,0,0),(25222,0.36,0,0,0),(48067,0.36,0,0,0),(48068,0.36,0,0,0),(8056,0.3858,0,0,0),(8058,0.3858,0,0,0),(10472,0.3858,0,0,0),(10473,0.3858,0,0,0),(25464,0.3858,0,0,0),(49235,0.3858,0,0,0),(49236,0.3858,0,0,0),(740,0.538,0,0,0),(8918,0.538,0,0,0),(9862,0.538,0,0,0),(9863,0.538,0,0,0),(26983,0.538,0,0,0),(48446,0.538,0,0,0),(48447,0.538,0,0,0),(5176,0.5714,0,0,0),(5177,0.5714,0,0,0),(5178,0.5714,0,0,0),(5179,0.5714,0,0,0),(5180,0.5714,0,0,0),(6780,0.5714,0,0,0),(8905,0.5714,0,0,0),(9912,0.5714,0,0,0),(26984,0.5714,0,0,0),(26985,0.5714,0,0,0),(48459,0.5714,0,0,0),(48461,0.5714,0,0,0),(44457,0.4,0.2,0,0),(55359,0.4,0.2,0,0),(55360,0.4,0.2,0,0),(2120,0.2357,0.122,0,0),(2121,0.2357,0.122,0,0),(8422,0.2357,0.122,0,0),(8423,0.2357,0.122,0,0),(10215,0.2357,0.122,0,0),(10216,0.2357,0.122,0,0),(27086,0.2357,0.122,0,0),(42925,0.2357,0.122,0,0),(42926,0.2357,0.122,0,0),(30283,0.1932,0,0,0),(30413,0.1932,0,0,0),(30414,0.1932,0,0,0),(47846,0.1932,0,0,0),(47847,0.1932,0,0,0),(3606,0.1667,0,0,0),(6350,0.1667,0,0,0),(6351,0.1667,0,0,0),(6352,0.1667,0,0,0),(10435,0.1667,0,0,0),(10436,0.1667,0,0,0),(25530,0.1667,0,0,0),(58700,0.1667,0,0,0),(58701,0.1667,0,0,0),(58702,0.1667,0,0,0),(980,0.1,0,0,0),(1014,0.1,0,0,0),(6217,0.1,0,0,0),(11711,0.1,0,0,0),(11712,0.1,0,0,0),(11713,0.1,0,0,0),(27218,0.1,0,0,0),(47863,0.1,0,0,0),(47864,0.1,0,0,0),(324,0.33,0,0,0),(325,0.33,0,0,0),(905,0.33,0,0,0),(945,0.33,0,0,0),(8134,0.33,0,0,0),(10431,0.33,0,0,0),(10432,0.33,0,0,0),(25469,0.33,0,0,0),(25472,0.33,0,0,0),(49280,0.33,0,0,0),(49281,0.33,0,0,0),(27243,0.2129,0.25,0,0),(47835,0.2129,0.25,0,0),(47836,0.2129,0.25,0,0),(8026,0.1,0,0,0),(8028,0.1,0,0,0),(8029,0.1,0,0,0),(10445,0.1,0,0,0),(16343,0.1,0,0,0),(16344,0.1,0,0,0),(25488,0.1,0,0,0),(58786,0.1,0,0,0),(58787,0.1,0,0,0),(58788,0.1,0,0,0),(8034,0.1,0,0,0),(8037,0.1,0,0,0),(10458,0.1,0,0,0),(16352,0.1,0,0,0),(16353,0.1,0,0,0),(25501,0.1,0,0,0),(58797,0.1,0,0,0),(58798,0.1,0,0,0),(58799,0.1,0,0,0),(689,0.143,0,0,0),(699,0.143,0,0,0),(709,0.143,0,0,0),(7651,0.143,0,0,0),(11699,0.143,0,0,0),(11700,0.143,0,0,0),(27219,0.143,0,0,0),(27220,0.143,0,0,0),(47857,0.143,0,0,0),(53719,0.25,0,0,0),(61295,0.4,0.18,0,0),(61299,0.4,0.18,0,0),(61300,0.4,0.18,0,0),(61301,0.4,0.18,0,0),(11113,0.1936,0,0,0),(13018,0.1936,0,0,0),(13019,0.1936,0,0,0),(13020,0.1936,0,0,0),(13021,0.1936,0,0,0),(27133,0.1936,0,0,0),(33933,0.1936,0,0,0),(42944,0.1936,0,0,0),(42945,0.1936,0,0,0),(50516,0.193,0,0,0),(53223,0.193,0,0,0),(53225,0.193,0,0,0),(53226,0.193,0,0,0),(61384,0.193,0,0,0),(1463,0,0.8053,0,0),(8494,0,0.8053,0,0),(8495,0,0.8053,0,0),(10191,0,0.8053,0,0),(10192,0,0.8053,0,0),(10193,0,0.8053,0,0),(27131,0,0.8053,0,0),(43019,0,0.8053,0,0),(43020,0,0.8053,0,0),(755,0.4485,0,0,0),(3698,0.4485,0,0,0),(3699,0.4485,0,0,0),(3700,0.4485,0,0,0),(11693,0.4485,0,0,0),(11694,0.4485,0,0,0),(11695,0.4485,0,0,0),(27259,0.4485,0,0,0),(47856,0.4485,0,0,0),(5676,0.4293,0,0,0),(17919,0.4293,0,0,0),(17920,0.4293,0,0,0),(17921,0.4293,0,0,0),(17922,0.4293,0,0,0),(17923,0.4293,0,0,0),(27210,0.4293,0,0,0),(30459,0.4293,0,0,0),(47814,0.4293,0,0,0),(47815,0.4293,0,0,0),(603,2,0,0,0),(30910,2,0,0,0),(47867,2,0,0,0),(51505,0.5714,0,0,0),(60043,0.5714,0,0,0),(2060,1.6135,0,0,0),(10963,1.6135,0,0,0),(10964,1.6135,0,0,0),(10965,1.6135,0,0,0),(25314,1.6135,0,0,0),(25210,1.6135,0,0,0),(25213,1.6135,0,0,0),(48062,1.6135,0,0,0),(48063,1.6135,0,0,0),(589,0.1829,0,0,0),(594,0.1829,0,0,0),(970,0.1829,0,0,0),(992,0.1829,0,0,0),(2767,0.1829,0,0,0),(10892,0.1829,0,0,0),(10893,0.1829,0,0,0),(10894,0.1829,0,0,0),(25367,0.1829,0,0,0),(25368,0.1829,0,0,0),(48124,0.1829,0,0,0),(48125,0.1829,0,0,0),(133,1,0,0,0),(143,1,0,0,0),(145,1,0,0,0),(3140,1,0,0,0),(8400,1,0,0,0),(8401,1,0,0,0),(8402,1,0,0,0),(10148,1,0,0,0),(10149,1,0,0,0),(10150,1,0,0,0),(10151,1,0,0,0),(25306,1,0,0,0),(27070,1,0,0,0),(38692,1,0,0,0),(42832,1,0,0,0),(42833,1,0,0,0),(48181,0.4793,0,0,0),(59161,0.4793,0,0,0),(59163,0.4793,0,0,0),(59164,0.4793,0,0,0),(116,0.8143,0,0,0),(205,0.8143,0,0,0),(837,0.8143,0,0,0),(7322,0.8143,0,0,0),(8406,0.8143,0,0,0),(8407,0.8143,0,0,0),(8408,0.8143,0,0,0),(10179,0.8143,0,0,0),(10180,0.8143,0,0,0),(10181,0.8143,0,0,0),(25304,0.8143,0,0,0),(27071,0.8143,0,0,0),(27072,0.8143,0,0,0),(38697,0.8143,0,0,0),(42841,0.8143,0,0,0),(42842,0.8143,0,0,0),(6353,1.15,0,0,0),(17924,1.15,0,0,0),(27211,1.15,0,0,0),(30545,1.15,0,0,0),(47824,1.15,0,0,0),(47825,1.15,0,0,0),(339,0.1,0,0,0),(1062,0.1,0,0,0),(5195,0.1,0,0,0),(5196,0.1,0,0,0),(9852,0.1,0,0,0),(9853,0.1,0,0,0),(26989,0.1,0,0,0),(53308,0.1,0,0,0),(30108,0.2,0,0,0),(30404,0.2,0,0,0),(30405,0.2,0,0,0),(47841,0.2,0,0,0),(47843,0.2,0,0,0),(331,1.6106,0,0,0),(332,1.6106,0,0,0),(547,1.6106,0,0,0),(913,1.6106,0,0,0),(933,1.6106,0,0,0),(953,1.6106,0,0,0),(8005,1.6106,0,0,0),(10395,1.6106,0,0,0),(10396,1.6106,0,0,0),(25357,1.6106,0,0,0),(25391,1.6106,0,0,0),(25396,1.6106,0,0,0),(49272,1.6106,0,0,0),(49273,1.6106,0,0,0),(8004,0.8082,0,0,0),(8008,0.8082,0,0,0),(8010,0.8082,0,0,0),(10466,0.8082,0,0,0),(10467,0.8082,0,0,0),(10468,0.8082,0,0,0),(25420,0.8082,0,0,0),(49275,0.8082,0,0,0),(49276,0.8082,0,0,0),(774,1.88,0.37604,0,0),(1058,1.88,0.37604,0,0),(1430,1.88,0.37604,0,0),(2090,1.88,0.37604,0,0),(2091,1.88,0.37604,0,0),(3627,1.88,0.37604,0,0),(8910,1.88,0.37604,0,0),(9839,1.88,0.37604,0,0),(9840,1.88,0.37604,0,0),(9841,1.88,0.37604,0,0),(25299,1.88,0.37604,0,0),(26981,1.88,0.37604,0,0),(26982,1.88,0.37604,0,0),(48440,1.88,0.37604,0,0),(48441,1.88,0.37604,0,0),(421,0.4,0,0,0),(930,0.4,0,0,0),(2860,0.4,0,0,0),(10605,0.4,0,0,0),(25439,0.4,0,0,0),(25442,0.4,0,0,0),(49270,0.4,0,0,0),(49271,0.4,0,0,0),(44614,0.8571,0,0,0),(47610,0.8571,0,0,0),(2061,0.8068,0,0,0),(9472,0.8068,0,0,0),(9473,0.8068,0,0,0),(9474,0.8068,0,0,0),(10915,0.8068,0,0,0),(10916,0.8068,0,0,0),(10917,0.8068,0,0,0),(25233,0.8068,0,0,0),(25235,0.8068,0,0,0),(48070,0.8068,0,0,0),(48071,0.8068,0,0,0),(635,1.66,0,0,0),(639,1.66,0,0,0),(647,1.66,0,0,0),(1026,1.66,0,0,0),(1042,1.66,0,0,0),(3472,1.66,0,0,0),(10328,1.66,0,0,0),(10329,1.66,0,0,0),(25292,1.66,0,0,0),(27135,1.66,0,0,0),(27136,1.66,0,0,0),(48781,1.66,0,0,0),(48782,1.66,0,0,0),(974,0.4761,0,0,0),(32593,0.4761,0,0,0),(32594,0.4761,0,0,0),(49283,0.4761,0,0,0),(49284,0.4761,0,0,0),(348,0.2,0.2,0,0),(707,0.2,0.2,0,0),(1094,0.2,0.2,0,0),(2941,0.2,0.2,0,0),(11665,0.2,0.2,0,0),(11667,0.2,0.2,0,0),(11668,0.2,0.2,0,0),(25309,0.2,0.2,0,0),(27215,0.2,0.2,0,0),(47810,0.2,0.2,0,0),(47811,0.2,0.2,0,0),(120,0.214,0,0,0),(8492,0.214,0,0,0),(10159,0.214,0,0,0),(10160,0.214,0,0,0),(10161,0.214,0,0,0),(27087,0.214,0,0,0),(42930,0.214,0,0,0),(42931,0.214,0,0,0),(6789,0.214,0,0,0),(17925,0.214,0,0,0),(17926,0.214,0,0,0),(27223,0.214,0,0,0),(47859,0.214,0,0,0),(47860,0.214,0,0,0),(8921,0.1515,0.13,0,0),(8924,0.1515,0.13,0,0),(8925,0.1515,0.13,0,0),(8926,0.1515,0.13,0,0),(8927,0.1515,0.13,0,0),(8928,0.1515,0.13,0,0),(8929,0.1515,0.13,0,0),(8933,0.1515,0.13,0,0),(8934,0.1515,0.13,0,0),(8935,0.1515,0.13,0,0),(26987,0.1515,0.13,0,0),(26988,0.1515,0.13,0,0),(48462,0.1515,0.13,0,0),(48463,0.1515,0.13,0,0),(2912,1,0,0,0),(8949,1,0,0,0),(8950,1,0,0,0),(8951,1,0,0,0),(9875,1,0,0,0),(9876,1,0,0,0),(25298,1,0,0,0),(26986,1,0,0,0),(48464,1,0,0,0),(48465,1,0,0,0),(5185,1.6104,0,0,0),(5186,1.6104,0,0,0),(5187,1.6104,0,0,0),(5188,1.6104,0,0,0),(5189,1.6104,0,0,0),(6778,1.6104,0,0,0),(8903,1.6104,0,0,0),(9758,1.6104,0,0,0),(9888,1.6104,0,0,0),(9889,1.6104,0,0,0),(25297,1.6104,0,0,0),(26978,1.6104,0,0,0),(26979,1.6104,0,0,0),(48377,1.6104,0,0,0),(48378,1.6104,0,0,0),(41637,0.8068,0,0,0),(19750,1,0,0,0),(19939,1,0,0,0),(19940,1,0,0,0),(19941,1,0,0,0),(19942,1,0,0,0),(19943,1,0,0,0),(27137,1,0,0,0),(48784,1,0,0,0),(48785,1,0,0,0),(585,0.714,0,0,0),(591,0.714,0,0,0),(598,0.714,0,0,0),(984,0.714,0,0,0),(1004,0.714,0,0,0),(6060,0.714,0,0,0),(10933,0.714,0,0,0),(10934,0.714,0,0,0),(25363,0.714,0,0,0),(25364,0.714,0,0,0),(48122,0.714,0,0,0),(48123,0.714,0,0,0),(122,0.193,0,0,0),(856,0.193,0,0,0),(6131,0.193,0,0,0),(10230,0.193,0,0,0),(27088,0.193,0,0,0),(42917,0.193,0,0,0),(18220,0.96,0,0,0),(18937,0.96,0,0,0),(18938,0.96,0,0,0),(27265,0.96,0,0,0),(59092,0.96,0,0,0),(15407,0.257,0,0,0),(17311,0.257,0,0,0),(17312,0.257,0,0,0),(17313,0.257,0,0,0),(17314,0.257,0,0,0),(18807,0.257,0,0,0),(25387,0.257,0,0,0),(48155,0.257,0,0,0),(48156,0.257,0,0,0),(48438,0.11505,0,0,0),(53248,0.11505,0,0,0),(53249,0.11505,0,0,0),(53251,0.11505,0,0,0),(2136,0.4286,0,0,0),(2137,0.4286,0,0,0),(2138,0.4286,0,0,0),(8412,0.4286,0,0,0),(8413,0.4286,0,0,0),(10197,0.4286,0,0,0),(10199,0.4286,0,0,0),(27078,0.4286,0,0,0),(27079,0.4286,0,0,0),(42872,0.4286,0,0,0),(42873,0.4286,0,0,0),(1949,0.12,0,0,0),(11683,0.12,0,0,0),(11684,0.12,0,0,0),(27213,0.12,0,0,0),(47823,0.12,0,0,0),(596,0.8068,0,0,0),(996,0.8068,0,0,0),(10960,0.8068,0,0,0),(10961,0.8068,0,0,0),(25316,0.8068,0,0,0),(25308,0.8068,0,0,0),(48072,0.8068,0,0,0),(403,0.7143,0,0,0),(529,0.7143,0,0,0),(548,0.7143,0,0,0),(915,0.7143,0,0,0),(943,0.7143,0,0,0),(6041,0.7143,0,0,0),(10391,0.7143,0,0,0),(10392,0.7143,0,0,0),(15207,0.7143,0,0,0),(15208,0.7143,0,0,0),(25448,0.7143,0,0,0),(25449,0.7143,0,0,0),(49237,0.7143,0,0,0),(49238,0.7143,0,0,0),(14914,0.5711,0.024,0,0),(15262,0.5711,0.024,0,0),(15263,0.5711,0.024,0,0),(15264,0.5711,0.024,0,0),(15265,0.5711,0.024,0,0),(15266,0.5711,0.024,0,0),(15267,0.5711,0.024,0,0),(15261,0.5711,0.024,0,0),(25384,0.5711,0.024,0,0),(48134,0.5711,0.024,0,0),(48135,0.5711,0.024,0,0),(30455,0.1429,0,0,0),(42913,0.1429,0,0,0),(42914,0.1429,0,0,0),(2948,0.4286,0,0,0),(8444,0.4286,0,0,0),(8445,0.4286,0,0,0),(8446,0.4286,0,0,0),(10205,0.4286,0,0,0),(10206,0.4286,0,0,0),(10207,0.4286,0,0,0),(27073,0.4286,0,0,0),(27074,0.4286,0,0,0),(42858,0.4286,0,0,0),(42859,0.4286,0,0,0),(44425,0.7143,0,0,0),(44780,0.7143,0,0,0),(44781,0.7143,0,0,0),(50288,0.05,0,0,0),(53191,0.05,0,0,0),(53194,0.05,0,0,0),(53195,0.05,0,0,0),(50294,0.012,0,0,0),(53188,0.012,0,0,0),(53189,0.012,0,0,0),(53190,0.012,0,0,0),(17,0.8068,0,0,0),(592,0.8068,0,0,0),(600,0.8068,0,0,0),(3747,0.8068,0,0,0),(6065,0.8068,0,0,0),(6066,0.8068,0,0,0),(10898,0.8068,0,0,0),(10899,0.8068,0,0,0),(10900,0.8068,0,0,0),(10901,0.8068,0,0,0),(25217,0.8068,0,0,0),(25218,0.8068,0,0,0),(48065,0.8068,0,0,0),(48066,0.8068,0,0,0),(34914,0.4,0,0,0),(34916,0.4,0,0,0),(34917,0.4,0,0,0),(48159,0.4,0,0,0),(48160,0.4,0,0,0),(32379,0.4296,0,0,0),(32996,0.4296,0,0,0),(48157,0.4296,0,0,0),(48158,0.4296,0,0,0),(11366,1.15,0.05,0,0),(12505,1.15,0.05,0,0),(12522,1.15,0.05,0,0),(12523,1.15,0.05,0,0),(12524,1.15,0.05,0,0),(12525,1.15,0.05,0,0),(12526,1.15,0.05,0,0),(18809,1.15,0.05,0,0),(27132,1.15,0.05,0,0),(33938,1.15,0.05,0,0),(42890,1.15,0.05,0,0),(42891,1.15,0.05,0,0),(32546,0.8068,0,0,0),(48119,0.8068,0,0,0),(48120,0.8068,0,0,0),(1120,0.429,0,0,0),(8288,0.429,0,0,0),(8289,0.429,0,0,0),(11675,0.429,0,0,0),(27217,0.429,0,0,0),(47855,0.429,0,0,0),(17877,0.4293,0,0,0),(18867,0.4293,0,0,0),(18868,0.4293,0,0,0),(18869,0.4293,0,0,0),(18870,0.4293,0,0,0),(18871,0.4293,0,0,0),(27263,0.4293,0,0,0),(30546,0.4293,0,0,0),(47826,0.4293,0,0,0),(47827,0.4293,0,0,0),(17962,0.4293,0,0,0),(11426,0.8053,0,0,0),(13031,0.8053,0,0,0),(13032,0.8053,0,0,0),(13033,0.8053,0,0,0),(27134,0.8053,0,0,0),(33405,0.8053,0,0,0),(43038,0.8053,0,0,0),(43039,0.8053,0,0,0),(8092,0.428,0,0,0),(8102,0.428,0,0,0),(8103,0.428,0,0,0),(8104,0.428,0,0,0),(8105,0.428,0,0,0),(8106,0.428,0,0,0),(10945,0.428,0,0,0),(10946,0.428,0,0,0),(10947,0.428,0,0,0),(25372,0.428,0,0,0),(25375,0.428,0,0,0),(48126,0.428,0,0,0),(48127,0.428,0,0,0),(49821,0.7143,0,0,0),(53022,0.7143,0,0,0),(172,0.2,0,0,0),(6222,0.2,0,0,0),(6223,0.2,0,0,0),(7648,0.2,0,0,0),(11671,0.2,0,0,0),(11672,0.2,0,0,0),(25311,0.2,0,0,0),(27216,0.2,0,0,0),(47812,0.2,0,0,0),(47813,0.2,0,0,0),(42231,0.12898,0,0,0),(42232,0.12898,0,0,0),(42233,0.12898,0,0,0),(42230,0.12898,0,0,0),(48466,0.12898,0,0,0),(5570,0.127,0,0,0),(24974,0.127,0,0,0),(24975,0.127,0,0,0),(24976,0.127,0,0,0),(24977,0.127,0,0,0),(27013,0.127,0,0,0),(48468,0.127,0,0,0),(1449,0.2128,0,0,0),(8437,0.2128,0,0,0),(8438,0.2128,0,0,0),(8439,0.2128,0,0,0),(10201,0.2128,0,0,0),(10202,0.2128,0,0,0),(27080,0.2128,0,0,0),(27082,0.2128,0,0,0),(42920,0.2128,0,0,0),(42921,0.2128,0,0,0),(1079,0,0,0.01,0),(9492,0,0,0.01,0),(9493,0,0,0.01,0),(9752,0,0,0.01,0),(9894,0,0,0.01,0),(9896,0,0,0.01,0),(27008,0,0,0.01,0),(49799,0,0,0.01,0),(49800,0,0,0.01,0),(60089,0,0,0.05,0),(16857,0,0,0.15,0),(33745,0,0,0.01,0),(48567,0,0,0.01,0),(48568,0,0,0.01,0),(62606,0,0,0.25,0),(3044,0,0,0,0.15),(14281,0,0,0,0.15),(14282,0,0,0,0.15),(14283,0,0,0,0.15),(14284,0,0,0,0.15),(14285,0,0,0,0.15),(14286,0,0,0,0.15),(14287,0,0,0,0.15),(27019,0,0,0,0.15),(49044,0,0,0,0.15),(49045,0,0,0,0.15),(53351,0,0,0,0.4),(61005,0,0,0,0.4),(61006,0,0,0,0.4),(2643,0,0,0,0.2),(14288,0,0,0,0.2),(14289,0,0,0,0.2),(14290,0,0,0,0.2),(25294,0,0,0,0.2),(27021,0,0,0,0.2),(49047,0,0,0,0.2),(49048,0,0,0,0.2),(1978,0,0,0,0.04),(13549,0,0,0,0.04),(13550,0,0,0,0.04),(13551,0,0,0,0.04),(13552,0,0,0,0.04),(13553,0,0,0,0.04),(13554,0,0,0,0.04),(13555,0,0,0,0.04),(25295,0,0,0,0.04),(27016,0,0,0,0.04),(49000,0,0,0,0.04),(49001,0,0,0,0.04),(56641,0,0,0,0.1),(34120,0,0,0,0.1),(49051,0,0,0,0.1),(49052,0,0,0,0.1),(53301,0,0,0,0.14),(60051,0,0,0,0.14),(60052,0,0,0,0.14),(60053,0,0,0,0.14),(13797,0,0,0,0.02),(14298,0,0,0,0.02),(14299,0,0,0,0.02),(14300,0,0,0,0.02),(14301,0,0,0,0.02),(27024,0,0,0,0.02),(49053,0,0,0,0.02),(49054,0,0,0,0.02),(1495,0,0,0.2,0),(14269,0,0,0.2,0),(14270,0,0,0.2,0),(14271,0,0,0.2,0),(36916,0,0,0.2,0),(53339,0,0,0.2,0),(31935,0.07,0,0.07,0),(32699,0.07,0,0.07,0),(32700,0.07,0,0.07,0),(48826,0.07,0,0.07,0),(48827,0.07,0,0.07,0),(26573,0.04,0,0.04,0),(20116,0.04,0,0.04,0),(20922,0.04,0,0.04,0),(20923,0.04,0,0.04,0),(20924,0.04,0,0.04,0),(27173,0.04,0,0.04,0),(48818,0.04,0,0.04,0),(48819,0.04,0,0.04,0),(879,0.15,0,0.15,0),(5614,0.15,0,0.15,0),(5615,0.15,0,0.15,0),(10312,0.15,0,0.15,0),(10313,0.15,0,0.15,0),(10314,0.15,0,0.15,0),(27138,0.15,0,0.15,0),(48800,0.15,0,0.15,0),(48801,0.15,0,0.15,0),(24275,0.15,0,0.15,0),(24274,0.15,0,0.15,0),(24239,0.15,0,0.15,0),(27180,0.15,0,0.15,0),(48805,0.15,0,0.15,0),(48806,0.15,0,0.15,0),(62124,0.085,0,0,0),(20925,0.09,0,0.056,0),(20927,0.09,0,0.056,0),(20928,0.09,0,0.056,0),(27179,0.09,0,0.056,0),(48951,0.09,0,0.056,0),(48952,0.09,0,0.056,0),(2812,0.07,0,0.07,0),(10318,0.07,0,0.07,0),(27139,0.07,0,0.07,0),(48816,0.07,0,0.07,0),(48817,0.07,0,0.07,0),(20424,0.23,0,0,0),(31893,0.02,0,0.03,0),(31803,0.025,0,0.05,0),(53742,0.025,0,0.05,0),(21084,0.07,0,0.039,0),(20187,0.4,0,0.25,0),(31898,0.25,0,0.16,0),(53726,0.25,0,0.16,0),(31804,0.22,0,0.14,0),(53733,0.25,0,0.16,0),(20267,0.1,0,0.1,0),(20467,0.25,0,0.16,0),(58597,0.75,0,0,0),(25912,0.4286,0,0,0),(25911,0.4286,0,0,0),(25902,0.4286,0,0,0),(27176,0.4286,0,0,0),(33073,0.4286,0,0,0),(48822,0.4286,0,0,0),(48823,0.4286,0,0,0),(25914,0.81,0,0,0),(25913,0.81,0,0,0),(25903,0.81,0,0,0),(27175,0.81,0,0,0),(33074,0.81,0,0,0),(48820,0.81,0,0,0),(48821,0.81,0,0,0),(30823,0,0,0.3,0),(57755,0,0,0.5,0),(6343,0,0,0.12,0),(8198,0,0,0.12,0),(8204,0,0,0.12,0),(8205,0,0,0.12,0),(11580,0,0,0.12,0),(11581,0,0,0.12,0),(25264,0,0,0.12,0),(47501,0,0,0.12,0),(47502,0,0,0.12,0),(5308,0,0,0.2,0),(20658,0,0,0.2,0),(20660,0,0,0.2,0),(20661,0,0,0.2,0),(20662,0,0,0.2,0),(25234,0,0,0.2,0),(25236,0,0,0.2,0),(47470,0,0,0.2,0),(47471,0,0,0.2,0),(20252,0,0,0.12,0),(34428,0,0,0.45,0),(6572,0,0,0.207,0),(6574,0,0,0.207,0),(7379,0,0,0.207,0),(11600,0,0,0.207,0),(11601,0,0,0.207,0),(25288,0,0,0.207,0),(25269,0,0,0.207,0),(30357,0,0,0.207,0),(57823,0,0,0.207,0),(23455,0.3035,0,0,0),(23458,0.3035,0,0,0),(23459,0.3035,0,0,0),(27803,0.3035,0,0,0),(27804,0.3035,0,0,0),(27805,0.3035,0,0,0),(25329,0.3035,0,0,0),(48075,0.3035,0,0,0),(48076,0.3035,0,0,0),(15237,0.1606,0,0,0),(15430,0.1606,0,0,0),(15431,0.1606,0,0,0),(27799,0.1606,0,0,0),(27800,0.1606,0,0,0),(27801,0.1606,0,0,0),(25331,0.1606,0,0,0),(48077,0.1606,0,0,0),(48078,0.1606,0,0,0),(47750,0.535,0,0,0),(52983,0.535,0,0,0),(52984,0.535,0,0,0),(52985,0.535,0,0,0),(47666,0.229,0,0,0),(52998,0.229,0,0,0),(52999,0.229,0,0,0),(53000,0.229,0,0,0),(50796,0.7139,0,0,0),(59170,0.7139,0,0,0),(59171,0.7139,0,0,0),(59172,0.7139,0,0,0),(50590,0.1622,0,0,0),(703,0,0,0.07,0),(8631,0,0,0.07,0),(8632,0,0,0.07,0),(8633,0,0,0.07,0),(11289,0,0,0.07,0),(11290,0,0,0.07,0),(26839,0,0,0.07,0),(26884,0,0,0.07,0),(48675,0,0,0.07,0),(48676,0,0,0.07,0),(1776,0,0,0.2,0),(1777,0,0,0.2,0),(8629,0,0,0.2,0),(11285,0,0,0.2,0),(11286,0,0,0.2,0),(38764,0,0,0.2,0),(12809,0,0,0.75,0),(46968,0,0,0.75,0),(23881,0,0,0.5,0),(8680,0,0,0.1,0),(8685,0,0,0.1,0),(8689,0,0,0.1,0),(11335,0,0,0.1,0),(11336,0,0,0.1,0),(11337,0,0,0.1,0),(26890,0,0,0.1,0),(57964,0,0,0.1,0),(57965,0,0,0.1,0),(2818,0,0,0.024,0),(2819,0,0,0.024,0),(11353,0,0,0.024,0),(11354,0,0,0.024,0),(25349,0,0,0.024,0),(26968,0,0,0.024,0),(27187,0,0,0.024,0),(57969,0,0,0.024,0),(57970,0,0,0.024,0),(13218,0,0,0.008,0),(13222,0,0,0.008,0),(13223,0,0,0.008,0),(13224,0,0,0.008,0),(27189,0,0,0.008,0),(57974,0,0,0.008,0),(57975,0,0,0.008,0),(35290,0,0,0,0.125),(35291,0,0,0,0.125),(35292,0,0,0,0.125),(35293,0,0,0,0.125),(35294,0,0,0,0.125),(35295,0,0,0,0.125),(24844,0,0,0,0.125),(25008,0,0,0,0.125),(25009,0,0,0,0.125),(25010,0,0,0,0.125),(25011,0,0,0,0.125),(25012,0,0,0,0.125),(16827,0,0,0,0.125),(16828,0,0,0,0.125),(16829,0,0,0,0.125),(16830,0,0,0,0.125),(16831,0,0,0,0.125),(16832,0,0,0,0.125),(3010,0,0,0,0.125),(3009,0,0,0,0.125),(27049,0,0,0,0.125),(52471,0,0,0,0.125),(52472,0,0,0,0.125),(35387,0,0,0,0.125),(35389,0,0,0,0.125),(35392,0,0,0,0.125),(55555,0,0,0,0.125),(55556,0,0,0,0.125),(55557,0,0,0,0.125),(34889,0,0,0,0.125),(35323,0,0,0,0.125),(55482,0,0,0,0.125),(55483,0,0,0,0.125),(55484,0,0,0,0.125),(55485,0,0,0,0.125),(17253,0,0,0,0.125),(17255,0,0,0,0.125),(17256,0,0,0,0.125),(17257,0,0,0,0.125),(17258,0,0,0,0.125),(17259,0,0,0,0.125),(17260,0,0,0,0.125),(17261,0,0,0,0.125),(27050,0,0,0,0.125),(52473,0,0,0,0.125),(52474,0,0,0,0.125),(24640,0,0,0,0.015),(24583,0,0,0,0.015),(24586,0,0,0,0.015),(24587,0,0,0,0.015),(27060,0,0,0,0.015),(55728,0,0,0,0.015),(50256,0,0,0.063,0),(53526,0,0,0.063,0),(53528,0,0,0.063,0),(53529,0,0,0.063,0),(53532,0,0,0.063,0),(53533,0,0,0.063,0),(9007,0,0,0.03,0),(9824,0,0,0.03,0),(9826,0,0,0.03,0),(27007,0,0,0.03,0),(49804,0,0,0.03,0);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

/*Table structure for table `totemspells` */

DROP TABLE IF EXISTS `totemspells`;

CREATE TABLE `totemspells` (
  `spell` int(10) unsigned NOT NULL DEFAULT '0',
  `castspell1` int(10) unsigned NOT NULL DEFAULT '0',
  `castspell2` int(10) unsigned NOT NULL DEFAULT '0',
  `castspell3` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

/*Data for the table `totemspells` */

insert  into `totemspells`(`spell`,`castspell1`,`castspell2`,`castspell3`) values (1535,8443,0,0),(2062,33663,0,0),(2484,3600,0,0),(2894,32982,0,0),(3599,3606,0,0),(3738,2895,0,0),(5394,5672,0,0),(5675,5677,0,0),(5730,5728,0,0),(6363,6350,0,0),(6364,6351,0,0),(6365,6352,0,0),(6375,6371,0,0),(6377,6372,0,0),(6390,6397,0,0),(6391,6398,0,0),(6392,6399,0,0),(6495,0,0,0),(8071,8072,0,0),(8075,8076,0,0),(8143,8146,0,0),(8154,8156,0,0),(8155,8157,0,0),(8160,8162,0,0),(8161,8163,0,0),(8166,8167,0,0),(8170,8172,0,0),(8177,8178,0,0),(8181,8182,0,0),(8184,8185,0,0),(8187,8188,0,0),(8190,8187,0,0),(8227,8230,0,0),(8249,8250,0,0),(8262,0,0,0),(8264,8266,0,0),(8376,8378,0,0),(8498,8504,0,0),(8499,8505,0,0),(8512,8514,0,0),(8835,8836,0,0),(10406,10403,0,0),(10407,10404,0,0),(10408,10405,0,0),(10427,10425,0,0),(10428,10426,0,0),(10437,10435,0,0),(10438,10436,0,0),(10442,10441,0,0),(10462,10460,0,0),(10463,10461,0,0),(10478,10476,0,0),(10479,10477,0,0),(10495,10491,0,0),(10496,10493,0,0),(10497,10494,0,0),(10526,10521,0,0),(10537,10534,0,0),(10538,10535,0,0),(10585,10579,0,0),(10586,10580,0,0),(10587,10581,0,0),(10595,10596,0,0),(10600,10598,0,0),(10601,10599,0,0),(10613,10607,0,0),(10614,10611,0,0),(10627,10626,0,0),(11314,11310,0,0),(11315,11311,0,0),(12506,12504,0,0),(15038,0,0,0),(15107,15108,0,0),(15111,15109,0,0),(15112,15110,0,0),(15786,3600,0,0),(15787,15789,0,0),(15867,0,0,0),(16190,39610,0,0),(16387,15036,0,0),(17354,17355,0,0),(17359,17360,0,0),(18975,18978,0,0),(22047,0,0,0),(23419,11311,0,0),(23420,10405,0,0),(23422,10461,0,0),(23423,10611,0,0),(25359,25360,0,0),(25361,25362,0,0),(25508,25506,0,0),(25509,25507,0,0),(25525,25513,0,0),(25528,25527,0,0),(25533,25530,0,0),(25546,25538,0,0),(25547,25539,0,0),(25552,25550,0,0),(25555,25554,0,0),(25557,25554,0,0),(25560,25559,0,0),(25563,25562,0,0),(25567,25566,0,0),(25570,25569,0,0),(25574,25573,0,0),(25577,25576,0,0),(25585,25579,0,0),(25587,25580,0,0),(25908,25909,0,0),(27621,10611,0,0),(27623,11307,0,0),(30706,57658,0,0),(57622,57621,0,0),(58643,58646,0,0),(58751,58752,0,0),(58753,58754,0,0),(58737,58738,0,0),(58739,58740,0,0),(58741,58742,0,0),(58745,58744,0,0),(58746,58748,0,0),(58749,58750,0,0),(58731,58732,0,0),(58734,58735,0,0),(61649,61651,0,0),(61657,61660,0,0),(58580,25513,0,0),(58581,25513,0,0),(58582,25513,0,0),(58699,58700,0,0),(58703,58701,0,0),(58704,58702,0,0),(58755,58763,0,0),(58756,58764,0,0),(58757,58765,0,0),(57720,57660,0,0),(57721,57662,0,0),(57722,57663,0,0),(58771,58775,0,0),(58773,58776,0,0),(58774,58777,0,0);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

/*Table structure for table `spelloverride` */

DROP TABLE IF EXISTS `spelloverride`;

CREATE TABLE `spelloverride` (
  `overrideId` int(30) NOT NULL DEFAULT '0',
  `spellhash` int(30) NOT NULL DEFAULT '0',
  KEY `overrideId` (`overrideId`,`spellhash`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

/*Data for the table `spelloverride` */

insert  into `spelloverride`(`overrideId`,`spellhash`) values (1,0),(21,0),(849,0),(910,0),(911,0),(3736,-1371035778),(4415,1125899035),(4418,0),(4554,0),(4555,1767655744),(4919,0),(4920,0),(4953,1125899035),(4992,0),(4993,0),(5142,0),(5147,-1459078418),(5148,-89212514),(5481,-89212514),(6008,0),(6427,0),(6428,0),(6916,552594024),(6917,0),(6918,0),(6925,552594024),(6926,0),(6927,552594024),(6928,0),(6935,0),(7277,0),(7278,0),(7293,0),(7377,0),(7598,0),(7599,0),(7600,0),(7601,0),(7602,0),(7798,1655691180),(7871,-1371035778),(7997,0),(7998,0),(8477,502237171),(8627,0);

ALTER TABLE `gameobject_names`
  ADD COLUMN `Size` float NOT NULL DEFAULT '1' after `Name`,
  ADD COLUMN `QuestItem1` int(11) UNSIGNED DEFAULT '0' NOT NULL after `Size`,
  ADD COLUMN `QuestItem2` int(11) UNSIGNED DEFAULT '0' NOT NULL after `QuestItem1`,
  ADD COLUMN `QuestItem3` int(11) UNSIGNED DEFAULT '0' NOT NULL after `QuestItem2`,
  ADD COLUMN `QuestItem4` int(11) UNSIGNED DEFAULT '0' NOT NULL after `QuestItem3`;

/* 375_rev_HellfirePeninsula_DeleteBanners */
DELETE FROM gameobject_spawns WHERE Entry = 182175 AND Map = 530;
DELETE FROM gameobject_spawns WHERE Entry = 182174 AND Map = 530;
DELETE FROM gameobject_spawns WHERE Entry = 182173 AND Map = 530;

DELETE FROM gameobject_spawns WHERE Entry = 183515 AND Map = 530;
DELETE FROM gameobject_spawns WHERE Entry = 182525 AND Map = 530;
DELETE FROM gameobject_spawns WHERE Entry = 183514 AND Map = 530;

/* 375_rev_potions */
UPDATE items SET spellcategory_1 = 2000 where spellcategory_1 = 4;

/* 375_rev_SilithusStuff */
REPLACE INTO `areatriggers` VALUES ('4162', '0', '1', '0', 'Silithus, Hive\'Zora, Alliance Camp', '-7142.04', '1397.92', '4.32689', '0', '0', '1');
REPLACE INTO `areatriggers` VALUES ('4168', '0', '1', '0', 'Silithus, Hive Regal, Horde Camp', '-7588.48', '756.806', '-16.4248', '0', '0', '1');

UPDATE `creature_proto` SET `npcflags`='129' WHERE `entry` in ('18564', '18581');

DELETE FROM gameobject_spawns WHERE `Map` = 530 AND `entry` in (182529, 182527, 182528);
DELETE FROM gameobject_spawns WHERE `Map` = 530 AND `entry` in (182523, 182522);
REPLACE INTO `gameobject_names` VALUES ('182522', '29', '6834', 'Zangarmarsh Banner', '60', '11515', '2527', '2528', '0', '0', '11813', '11812', '11805', '11804', '11808', '11809', '80', '2529', '1', '5', '300', '600', '1', '0', '0', '0', '0', '0');
REPLACE INTO `gameobject_names` VALUES ('182523', '29', '6834', 'Zangarmarsh Banner', '60', '11515', '2533', '2534', '0', '0', '11816', '11817', '11807', '11806', '11814', '11815', '80', '2535', '1', '5', '300', '600', '1', '0', '0', '0', '0', '0');
UPDATE `gameobject_names` SET `Type`='1' WHERE (`entry`='182527');
UPDATE `gameobject_names` SET `Type`='1' WHERE (`entry`='182529');
UPDATE `gameobject_names` SET `Type`='1' WHERE (`entry`='182528');

delete from gameobject_spawns where entry = 181597;

REPLACE INTO `graveyards` VALUES ('142', '248.339', '7084.93', '36.6211', '0', '3521', '0', '530', '4', 'Twin Spire Ruins');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2647','1','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2648','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2649','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2652','1','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2560','1','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2646','1','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2557','1','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2650','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2558','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2644','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2555','0','');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2651','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2559','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2645','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2556','0','');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2527','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2528','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2533','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2534','0','');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2655','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2658','0','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2656','1','');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3521','-1','2657','1','');

/* 375_rev_terrokar_gameobject */
DELETE FROM gameobject_spawns WHERE `Map` = 530 AND `entry` in (183104, 183411, 182301, 183412, 183413, 183414);

/* 375_rev_terrokar_wordstates */
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2621','0','WORLDSTATE_TEROKKAR_ALLIANCE_TOWERS_CONTROLLED');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2622','0','WORLDSTATE_TEROKKAR_HORDE_TOWERS_CONTROLLED');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2620','1','WORLDSTATE_TEROKKAR_TOWER_DISPLAY');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2623','0','WORLDSTATE_TEROKKAR_PVP_CAPTURE_BAR_DISPLAY');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2625','0','WORLDSTATE_TEROKKAR_PVP_CAPTURE_BAR_VALUE');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2681','1','WORLDSTATE_TEROKKAR_TOWER1_NEUTRAL');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2686','1','WORLDSTATE_TEROKKAR_TOWER2_NEUTRAL');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2690','1','WORLDSTATE_TEROKKAR_TOWER3_NEUTRAL');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2696','1','WORLDSTATE_TEROKKAR_TOWER4_NEUTRAL');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2693','1','WORLDSTATE_TEROKKAR_TOWER5_NEUTRAL');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2683','0','WORLDSTATE_TEROKKAR_TOWER1_ALLIANCE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2684','0','WORLDSTATE_TEROKKAR_TOWER2_ALLIANCE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2688','0','WORLDSTATE_TEROKKAR_TOWER3_ALLIANCE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2694','0','WORLDSTATE_TEROKKAR_TOWER4_ALLIANCE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2691','0','WORLDSTATE_TEROKKAR_TOWER5_ALLIANCE');

REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2682','0','WORLDSTATE_TEROKKAR_TOWER1_HORDE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2685','0','WORLDSTATE_TEROKKAR_TOWER2_HORDE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2689','0','WORLDSTATE_TEROKKAR_TOWER3_HORDE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2695','0','WORLDSTATE_TEROKKAR_TOWER4_HORDE');
REPLACE INTO `worldstate_template` (`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) VALUES ('530','3519','-1','2692','0','WORLDSTATE_TEROKKAR_TOWER5_HORDE');

/* 375_rev_Ulduar */
INSERT INTO areatriggers(`entry`, `type`, `map`, `screen`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `required_honor_rank`, `required_level`)VALUES(5379, 0, 0, 0, 'Ulduar Entrance', 0, 0, 0, 0, 0, 0);
UPDATE Areatriggers SET Type = '1' WHERE Entry = '5379';
UPDATE Areatriggers SET Map = '603' WHERE Entry = '5379';
UPDATE Areatriggers SET Screen = '603' WHERE Entry = '5379';
UPDATE Areatriggers SET Position_x = '-863.575' WHERE Entry = '5379';
UPDATE Areatriggers SET Position_y = '-149.027' WHERE Entry = '5379';
UPDATE Areatriggers SET Position_z = '458.885' WHERE Entry = '5379';
UPDATE Areatriggers SET Orientation = '0.001567' WHERE Entry = '5379';
UPDATE Areatriggers SET Required_level = '80' WHERE Entry = '5379';
UPDATE Areatriggers SET Type = '1' WHERE Entry = '5381';
UPDATE Areatriggers SET Map = '571' WHERE Entry = '5381';
UPDATE Areatriggers SET Screen = '571' WHERE Entry = '5381';
UPDATE Areatriggers SET Position_x = '9333.82' WHERE Entry = '5381';
UPDATE Areatriggers SET Position_y = '-1114.78' WHERE Entry = '5381';
UPDATE Areatriggers SET Position_z = '1245.12' WHERE Entry = '5381';
UPDATE Areatriggers SET Orientation = '3.12981' WHERE Entry = '5381';
UPDATE Areatriggers SET Required_level = '0' WHERE Entry = '5381';

/* 375_rev_visual_items */
UPDATE creature_proto set equipslot1=5287 where entry=5603;
UPDATE creature_proto set equipslot1=5284 where entry=5188;
UPDATE creature_proto set equipslot1=5303 where entry=3370;
UPDATE creature_proto set equipslot1=5289 where entry=3296;
UPDATE creature_proto set equipslot1=13339 where entry=13842;
UPDATE creature_proto set equipslot1=12852 where entry=3309;
UPDATE creature_proto set equipslot2=12855 where entry=3309;
UPDATE creature_proto set equipslot1=3433 where entry=3310;
UPDATE creature_proto set equipslot1=2827 where entry=3312;
UPDATE creature_proto set equipslot2=2196 where entry=3312;
UPDATE creature_proto set equipslot3=2551 where entry=3312;
UPDATE creature_proto set equipslot1=12850 where entry=3320;
UPDATE creature_proto set equipslot2=12745 where entry=3320;
UPDATE creature_proto set equipslot1=10611 where entry=3314;
UPDATE creature_proto set equipslot1=12856 where entry=3318;
UPDATE creature_proto set equipslot2=12859 where entry=3318;
UPDATE creature_proto set equipslot1=6680 where entry=12793;
UPDATE creature_proto set equipslot1=14836 where entry=26397;
UPDATE creature_proto set equipslot1=37123 where entry=32833;
UPDATE creature_proto set equipslot1=5287 where entry=5597;
UPDATE creature_proto set equipslot1=1910 where entry=5817;
UPDATE creature_proto set equipslot2=2081 where entry=5817;
UPDATE creature_proto set equipslot1=18419 where entry=14392;
UPDATE creature_proto set equipslot1=1906 where entry=3313;
UPDATE creature_proto set equipslot2=12745 where entry=3313;
UPDATE creature_proto set equipslot1=10612 where entry=14375;
UPDATE creature_proto set equipslot2=10612 where entry=14375;
UPDATE creature_proto set equipslot2=1985 where entry=3319;
UPDATE creature_proto set equipslot3=2551 where entry=5611;
UPDATE creature_proto set equipslot1=2716 where entry=5614;
UPDATE creature_proto set equipslot1=2703 where entry=5613;
UPDATE creature_proto set equipslot1=2703 where entry=5606;
UPDATE creature_proto set equipslot1=2703 where entry=5609;
UPDATE creature_proto set equipslot1=2703 where entry=5610;
UPDATE creature_proto set equipslot1=6334 where entry=6929;
UPDATE creature_proto set equipslot1=5288 where entry=4311;
UPDATE creature_proto set equipslot3=2552 where entry=3322;
UPDATE creature_proto set equipslot1=2200 where entry=3323;
UPDATE creature_proto set equipslot1=3346 where entry=3329;
UPDATE creature_proto set equipslot1=2178 where entry=3331;
UPDATE creature_proto set equipslot1=2827 where entry=3399;
UPDATE creature_proto set equipslot1=3351 where entry=3400;
UPDATE creature_proto set equipslot2=4993 where entry=3400;
UPDATE creature_proto set equipslot1=2827 where entry=3368;
UPDATE creature_proto set equipslot2=2196 where entry=3368;
UPDATE creature_proto set equipslot2=12745 where entry=3369;
UPDATE creature_proto set equipslot1=2559 where entry=3216;
UPDATE creature_proto set equipslot1=5277 where entry=5639;
UPDATE creature_proto set equipslot1=1896 where entry=3315;
UPDATE creature_proto set equipslot1=1908 where entry=3363;
UPDATE creature_proto set equipslot1=5278 where entry=7088;
UPDATE creature_proto set equipslot2=12745 where entry=2855;
UPDATE creature_proto set equipslot1=2184 where entry=5811;
UPDATE creature_proto set equipslot1=3699 where entry=3366;
UPDATE creature_proto set equipslot1=2197 where entry=3367;
UPDATE creature_proto set equipslot1=5303 where entry=7010;
UPDATE creature_proto set equipslot1=12862 where entry=30706;
UPDATE creature_proto set equipslot1=10612 where entry=14377;
UPDATE creature_proto set equipslot2=10612 where entry=14377;
UPDATE creature_proto set equipslot1=1911 where entry=6986;
UPDATE creature_proto set equipslot1=1903 where entry=6987;
UPDATE creature_proto set equipslot1=6233 where entry=3404;
UPDATE creature_proto set equipslot2=12860 where entry=11066;
UPDATE creature_proto set equipslot1=3699 where entry=11046;
UPDATE creature_proto set equipslot2=3697 where entry=11046;
UPDATE creature_proto set equipslot1=3696 where entry=3405;
UPDATE creature_proto set equipslot1=2711 where entry=8659;
UPDATE creature_proto set equipslot2=10619 where entry=8659;
UPDATE creature_proto set equipslot1=2198 where entry=3348;
UPDATE creature_proto set equipslot1=3699 where entry=3347;
UPDATE creature_proto set equipslot2=3697 where entry=3347;
UPDATE creature_proto set equipslot1=4994 where entry=23635;
UPDATE creature_proto set equipslot1=19623 where entry=14942;
UPDATE creature_proto set equipslot1=2183 where entry=4485;
UPDATE creature_proto set equipslot2=2183 where entry=4485;
UPDATE creature_proto set equipslot3=5259 where entry=3410;
UPDATE creature_proto set equipslot1=1910 where entry=3357;
UPDATE creature_proto set equipslot1=2714 where entry=3358;
UPDATE creature_proto set equipslot1=12951 where entry=14182;
UPDATE creature_proto set equipslot1=12348 where entry=3408;
UPDATE creature_proto set equipslot1=1983 where entry=3354;
UPDATE creature_proto set equipslot1=2182 where entry=7230;
UPDATE creature_proto set equipslot1=5532 where entry=11176;
UPDATE creature_proto set equipslot1=5491 where entry=7793;
UPDATE creature_proto set equipslot1=21580 where entry=30582;
UPDATE creature_proto set equipslot1=18419 where entry=3890;
UPDATE creature_proto set equipslot1=13706 where entry=15350;
UPDATE creature_proto set equipslot1=10612 where entry=3353;
UPDATE creature_proto set equipslot2=10611 where entry=3353;
UPDATE creature_proto set equipslot1=1903 where entry=11178;
UPDATE creature_proto set equipslot1=5491 where entry=11177;
UPDATE creature_proto set equipslot1=10616 where entry=15006;
UPDATE creature_proto set equipslot1=25758 where entry=20385;
UPDATE creature_proto set equipslot1=1911 where entry=9317;
UPDATE creature_proto set equipslot1=1903 where entry=11017;
UPDATE creature_proto set equipslot1=1906 where entry=2857;
UPDATE creature_proto set equipslot1=1911 where entry=3413;
UPDATE creature_proto set equipslot1=4994 where entry=3412;
UPDATE creature_proto set equipslot1=1903 where entry=3355;
UPDATE creature_proto set equipslot1=2182 where entry=7792;
UPDATE creature_proto set equipslot1=1903 where entry=5812;
UPDATE creature_proto set equipslot1=5532 where entry=10266;
UPDATE creature_proto set equipslot1=1903 where entry=3356;
UPDATE creature_proto set equipslot2=13611 where entry=3356;
UPDATE creature_proto set equipslot1=1903 where entry=7790;
UPDATE creature_proto set equipslot1=1117 where entry=3333;
UPDATE creature_proto set equipslot1=20468 where entry=7951;
UPDATE creature_proto set equipslot1=1117 where entry=3332;
UPDATE creature_proto set equipslot1=1906 where entry=3350;
UPDATE creature_proto set equipslot2=12745 where entry=3350;
UPDATE creature_proto set equipslot1=5277 where entry=3324;
UPDATE creature_proto set equipslot1=2199 where entry=3335;
UPDATE creature_proto set equipslot1=12864 where entry=5875;
UPDATE creature_proto set equipslot1=5277 where entry=3326;
UPDATE creature_proto set equipslot1=2717 where entry=3351;
UPDATE creature_proto set equipslot1=13718 where entry=15765;
UPDATE creature_proto set equipslot1=5300 where entry=3403;
UPDATE creature_proto set equipslot1=3361 where entry=3344;
UPDATE creature_proto set equipslot1=2558 where entry=13417;
UPDATE creature_proto set equipslot1=5291 where entry=5892;
UPDATE creature_proto set equipslot1=5304 where entry=4047;
UPDATE creature_proto set equipslot1=5289 where entry=14304;
UPDATE creature_proto set equipslot1=10612 where entry=3144;
UPDATE creature_proto set equipslot1=14085 where entry=10540;
UPDATE creature_proto set equipslot3=14118 where entry=10540;
UPDATE creature_proto set equipslot1=14824 where entry=16012;
UPDATE creature_proto set equipslot1=24034 where entry=23131;
UPDATE creature_proto set equipslot2=24038 where entry=23131;
UPDATE creature_proto set equipslot1=12183 where entry=4949;
UPDATE creature_proto set equipslot1=29403 where entry=23128;
UPDATE creature_proto set equipslot2=27406 where entry=23128;
UPDATE creature_proto set equipslot1=5304 where entry=3330;
UPDATE creature_proto set equipslot1=2023 where entry=3189;
UPDATE creature_proto set equipslot1=5304 where entry=5815;
UPDATE creature_proto set equipslot1=2199 where entry=3334;
UPDATE creature_proto set equipslot3=6231 where entry=5816;
UPDATE creature_proto set equipslot1=2711 where entry=6446;
UPDATE creature_proto set equipslot1=10617 where entry=3402;
UPDATE creature_proto set equipslot1=2184 where entry=3327;
UPDATE creature_proto set equipslot1=5278 where entry=3328;
UPDATE creature_proto set equipslot1=1900 where entry=3401;
UPDATE creature_proto set equipslot2=5281 where entry=3401;
UPDATE creature_proto set equipslot1=12329 where entry=3342;
UPDATE creature_proto set equipslot1=12329 where entry=5910;
UPDATE creature_proto set equipslot1=10611 where entry=12796;
UPDATE creature_proto set equipslot1=12786 where entry=12795;
UPDATE creature_proto set equipslot1=14824 where entry=26396;
UPDATE creature_proto set equipslot1=10612 where entry=14376;
UPDATE creature_proto set equipslot2=10612 where entry=14376;
UPDATE creature_proto set equipslot1=5277 where entry=5958;
UPDATE creature_proto set equipslot1=4993 where entry=5882;
UPDATE creature_proto set equipslot1=6618 where entry=5883;
UPDATE creature_proto set equipslot1=33161 where entry=27819;
UPDATE creature_proto set equipslot1=5276 where entry=5994;
UPDATE creature_proto set equipslot1=12787 where entry=6014;
UPDATE creature_proto set equipslot1=1908 where entry=6018;
UPDATE creature_proto set equipslot1=12328 where entry=7311;
UPDATE creature_proto set equipslot1=1907 where entry=3373;
UPDATE creature_proto set equipslot3=6231 where entry=5885;
UPDATE creature_proto set equipslot1=1906 where entry=8404;
UPDATE creature_proto set equipslot1=27496 where entry=19239;
UPDATE creature_proto set equipslot1=12742 where entry=18547;
UPDATE creature_proto set equipslot1=23382 where entry=19240;
UPDATE creature_proto set equipslot1=20468 where entry=19251;
UPDATE creature_proto set equipslot1=13750 where entry=21905;
UPDATE creature_proto set equipslot1=2177 where entry=19252;
UPDATE creature_proto set equipslot1=19053 where entry=19248;
UPDATE creature_proto set equipslot1=12864 where entry=19250;
UPDATE creature_proto set equipslot1=23382 where entry=20613;
UPDATE creature_proto set equipslot1=19053 where entry=19249;
UPDATE creature_proto set equipslot3=11021 where entry=25142;
UPDATE creature_proto set equipslot1=29707 where entry=19687;
UPDATE creature_proto set equipslot2=29640 where entry=19687;
UPDATE creature_proto set equipslot3=30580 where entry=19687;
UPDATE creature_proto set equipslot1=27496 where entry=18893;
UPDATE creature_proto set equipslot2=27496 where entry=18893;
UPDATE creature_proto set equipslot1=25688 where entry=20331;
UPDATE creature_proto set equipslot1=29663 where entry=24932;
UPDATE creature_proto set equipslot1=13709 where entry=27666;
UPDATE creature_proto set equipslot1=1903 where entry=27667;
UPDATE creature_proto set equipslot1=18419 where entry=20269;
UPDATE creature_proto set equipslot1=21580 where entry=30586;
UPDATE creature_proto set equipslot1=13722 where entry=20274;
UPDATE creature_proto set equipslot1=14877 where entry=20276;
UPDATE creature_proto set equipslot1=26003 where entry=20384;
UPDATE creature_proto set equipslot1=24012 where entry=19475;
UPDATE creature_proto set equipslot1=12748 where entry=19142;
UPDATE creature_proto set equipslot1=34531 where entry=25134;
UPDATE creature_proto set equipslot2=34532 where entry=25134;
UPDATE creature_proto set equipslot1=27905 where entry=23449;
UPDATE creature_proto set equipslot1=34531 where entry=25135;
UPDATE creature_proto set equipslot2=34532 where entry=25135;
UPDATE creature_proto set equipslot1=34531 where entry=25137;
UPDATE creature_proto set equipslot2=34532 where entry=25137;
UPDATE creature_proto set equipslot1=34531 where entry=25136;
UPDATE creature_proto set equipslot2=34532 where entry=25136;
UPDATE creature_proto set equipslot1=29107 where entry=20791;
UPDATE creature_proto set equipslot3=18282 where entry=25885;
UPDATE creature_proto set equipslot1=10612 where entry=20124;
UPDATE creature_proto set equipslot1=12748 where entry=19202;
UPDATE creature_proto set equipslot1=2707 where entry=19164;
UPDATE creature_proto set equipslot1=1906 where entry=15303;
UPDATE creature_proto set equipslot1=3367 where entry=20123;
UPDATE creature_proto set equipslot1=29124 where entry=23270;
UPDATE creature_proto set equipslot1=18873 where entry=18166;
UPDATE creature_proto set equipslot1=34596 where entry=25115;
UPDATE creature_proto set equipslot2=34590 where entry=25115;
UPDATE creature_proto set equipslot1=29114 where entry=16800;
UPDATE creature_proto set equipslot1=24324 where entry=16801;
UPDATE creature_proto set equipslot2=24324 where entry=16801;
UPDATE creature_proto set equipslot3=24326 where entry=16801;
UPDATE creature_proto set equipslot1=14882 where entry=16802;
UPDATE creature_proto set equipslot2=24038 where entry=16802;
UPDATE creature_proto set equipslot1=12862 where entry=30710;
UPDATE creature_proto set equipslot1=1903 where entry=16669;
UPDATE creature_proto set equipslot2=13611 where entry=16669;
UPDATE creature_proto set equipslot1=1903 where entry=16671;
UPDATE creature_proto set equipslot1=1911 where entry=16667;
UPDATE creature_proto set equipslot3=5262 where entry=18147;
UPDATE creature_proto set equipslot1=24034 where entry=18175;
UPDATE creature_proto set equipslot2=24038 where entry=18175;
UPDATE creature_proto set equipslot1=34311 where entry=25223;
UPDATE creature_proto set equipslot1=24034 where entry=17769;
UPDATE creature_proto set equipslot2=24038 where entry=17769;
UPDATE creature_proto set equipslot1=24034 where entry=18174;
UPDATE creature_proto set equipslot2=24038 where entry=18174;
UPDATE creature_proto set equipslot1=34693 where entry=30584;
UPDATE creature_proto set equipslot1=26003 where entry=20390;
UPDATE creature_proto set equipslot1=23908 where entry=18626;
UPDATE creature_proto set equipslot2=23908 where entry=18626;
UPDATE creature_proto set equipslot1=24324 where entry=18629;
UPDATE creature_proto set equipslot2=24324 where entry=18629;
UPDATE creature_proto set equipslot1=23908 where entry=18627;
UPDATE creature_proto set equipslot2=23908 where entry=18627;
UPDATE creature_proto set equipslot1=2201 where entry=16683;
UPDATE creature_proto set equipslot2=3698 where entry=16683;
UPDATE creature_proto set equipslot1=13612 where entry=16442;
UPDATE creature_proto set equipslot1=27405 where entry=18146;
UPDATE creature_proto set equipslot2=27406 where entry=18146;
UPDATE creature_proto set equipslot1=1902 where entry=20087;
UPDATE creature_proto set equipslot1=1117 where entry=18347;
UPDATE creature_proto set equipslot2=24038 where entry=18790;
UPDATE creature_proto set equipslot1=29114 where entry=21970;
UPDATE creature_proto set equipslot1=2716 where entry=19882;
UPDATE creature_proto set equipslot2=13609 where entry=19882;
UPDATE creature_proto set equipslot1=5303 where entry=16192;
UPDATE creature_proto set equipslot1=12864 where entry=18951;
UPDATE creature_proto set equipslot1=10616 where entry=16278;
UPDATE creature_proto set equipslot1=5278 where entry=16273;
UPDATE creature_proto set equipslot1=11343 where entry=15970;

/* 391_rev_guard_types */
ALTER TABLE `creature_proto` ADD COLUMN `GuardType` INT UNSIGNED DEFAULT '0' NOT NULL AFTER `CanMove`;
UPDATE `creature_proto` SET `GuardType` = '1' WHERE `entry` IN ('68','1423','1756','15858','15859','16864','20556','18948','18949','1642','1976','3296','15852','15853','15854','18950','5624','18971','16432','16733','18815','3084','16221','17029','16222','727','5595','4262','3222','3224','3223','18038','3571','3221','3219','3220','3215','3218','3212','13076','5953','1735','1744','1745','5725','1743','1742','1746','2209','1738','2210','12996');
UPDATE `creature_proto` SET `GuardType` = '2' WHERE `entry` IN ('3502','4624','15088','9460','11102','16378','15184','11822','11190','17855','18099','18101','18102','20484','20485','22494','23636','23721','19687','18549','18568','26253','24994');

/* 410_rev_events */
DROP TABLE IF EXISTS `events`;

CREATE TABLE `events` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'Id of event you want to trigger',
  `daynumber` tinyint(3) unsigned NOT NULL COMMENT '1 - 31 day of the month you want to trigger event',
  `monthnumber` tinyint(3) unsigned DEFAULT '0' COMMENT '1 - 12 month of the year you want to trigger event',
  `eventname` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL COMMENT 'Just for human readable purposes, this is not used by the server at all',
  `activedays` tinyint(3) unsigned DEFAULT NULL COMMENT 'Number of days the event will remain active',
  `ishourlyevent` tinyint(1) DEFAULT NULL COMMENT 'Is this an hourly event? This cannot be used in conjunction with daily events',
  `starthour` tinyint(3) unsigned DEFAULT NULL COMMENT '0 - 23 the hour that the event begins',
  `endhour` tinyint(3) unsigned DEFAULT NULL COMMENT '0 - 23 the hour that the event ends, if this is smaller that the starthour, it will end on the next day',
  PRIMARY KEY (`eventid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

/*Table structure for table `events_creature` */

DROP TABLE IF EXISTS `events_creature`;

CREATE TABLE `events_creature` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'Relates to creature_spawn eventid',
  `id` tinyint(3) unsigned NOT NULL COMMENT 'Relates to creature_spawn id',
  `changesflag` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'See enum in the core for permissable flags in World.h',
  `phase` tinyint(3) DEFAULT NULL COMMENT 'This is the phase the creature is in when the event is active',
  `displayid` int(10) unsigned DEFAULT NULL COMMENT 'This is the displayid to change to while the event is active',
  `item1` int(10) unsigned DEFAULT NULL COMMENT 'This is the id of equip slot 1 to change while the event is active',
  `item2` int(10) unsigned DEFAULT NULL COMMENT 'This is the id of equip slot 2 to change while the event is active',
  `item3` int(10) unsigned DEFAULT NULL COMMENT 'This is the id of equip slot 3 to change while the event is active',
  PRIMARY KEY (`eventid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

/*Table structure for table `events_gameobject` */

DROP TABLE IF EXISTS `events_gameobject`;

CREATE TABLE `events_gameobject` (
  `eventid` tinyint(3) unsigned NOT NULL COMMENT 'This relates to gameobject_spawns eventid',
  `id` int(11) unsigned NOT NULL COMMENT 'Relates to gameobject_spawn id',
  `changesflag` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'See enum in core for permissable flags in World.h',
  `phase` tinyint(3) DEFAULT NULL COMMENT 'Phase the go is in when the event is active',
  `displayid` int(10) unsigned DEFAULT NULL COMMENT 'This is the displayid to change to while the event is active',
  PRIMARY KEY (`eventid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;

ALTER TABLE `gameobject_spawns` ADD COLUMN `eventid` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'relates to events table' AFTER `phase` ;
ALTER TABLE `creature_spawns` ADD COLUMN `eventid` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Relates to events table' AFTER `vehicle`;

/* 410_rev_spell_coef_override */
DROP TABLE if EXISTS spelloverride;
CREATE TABLE `spelloverride` (
  `overrideId` INT(30) NOT NULL DEFAULT '0',
  `spellId` INT(30) NOT NULL DEFAULT '0',
  PRIMARY KEY (`overrideId`,`spellId`),
  UNIQUE KEY `overrideId` (`overrideId`,`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
 
ALTER TABLE `spell_coef_override` CHANGE `Base_coef` `Dspell_coef_override` FLOAT DEFAULT '0';
ALTER TABLE `spell_coef_override` CHANGE `Misc_coef` `OTspell_coef_override` FLOAT DEFAULT '0';
ALTER TABLE `spell_coef_override` CHANGE `AP_coef` `AP_coef_override` FLOAT DEFAULT '0';
ALTER TABLE `spell_coef_override` CHANGE `RAP_coef` `RAP_coef_override` FLOAT DEFAULT '0';

/* 410_rev_spell_forced_targets */
INSERT INTO `spell_forced_targets` VALUES ('32146', '18240');
INSERT INTO `spell_forced_targets` VALUES ('30988', '17701');
INSERT INTO `spell_forced_targets` VALUES ('43723', '19973');
INSERT INTO `spell_forced_targets` VALUES ('41621', '23487');
INSERT INTO `spell_forced_targets` VALUES ('3607', '2530');
INSERT INTO `spell_forced_targets` VALUES ('34665', '16880');
INSERT INTO `spell_forced_targets` VALUES ('37136', '21729');
INSERT INTO `spell_forced_targets` VALUES ('39810', '22979');
INSERT INTO `spell_forced_targets` VALUES ('38554', '19440');
INSERT INTO `spell_forced_targets` VALUES ('33531', '19067');
INSERT INTO `spell_forced_targets` VALUES ('33532', '19210');
INSERT INTO `spell_forced_targets` VALUES ('32146', '18240');
INSERT INTO `spell_forced_targets` VALUES ('38177', '21387');
INSERT INTO `spell_forced_targets` VALUES ('32578', '20748');
INSERT INTO `spell_forced_targets` VALUES ('30077', '17266');
INSERT INTO `spell_forced_targets` VALUES ('44997', '24972');
