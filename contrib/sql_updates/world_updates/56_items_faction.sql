/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

ALTER TABLE `items`
ADD COLUMN `faction` INT(11) UNSIGNED DEFAULT '3' NOT NULL AFTER `ItemLimitCategoryId`;
