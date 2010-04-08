/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __RURU_ITEMHANDLER_H
#define __RURU_ITEMHANDLER_H
                
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ItemHandler.cpp                        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Строчки
#define TPUERROORINTERAI "Internal Error"
#define HABDDIUSBUYITEAI "HandleBuyItemInSlot: Error while adding item to dstslot"
#define ITEMDSTINVSLOTAI "ITEM: swap, DstInvSlot %i DstSlot %i SrcInvSlot %i SrcSlot %i"
#define HANLESSWAPITEMAI "HandleSwapItem: Error while adding item to dstslot\n"
#define HANLESSWAPITSLAI "HandleSwapItem: Error while adding item to srcslot\n"
#define ITEMFDTINVSLOTAI "ITEM: swap, src slot: %u dst slot: %u"
#define HANLERSOPCODESAI "HandleSwapInvItemOpcode"
#define TETSGETSITEMSSAI "testing gem %u on item %u"
#define ITEMDDESTVSLOTAI "ITEM: destroy, SrcInv Slot: %i Src slot: %i"
#define ITEMDAUSTVSLOTAI "ITEM: autoequip, Inventory slot: %i Source Slot: %i"
#define HANDLESAUTOEQUAI "HandleAutoEquip: Error while adding item to SrcSlot"
#define HANDFGSAUTOEQUAI "HandleAutoEquip: Error while adding item to Slot"
#define WORLDWORLDWORLAI "WORLD"," Unknown item id 0x%.8X"
#define CMSGABUYBACKASAI "WORLD"," Received CMSG_BUYBACK_ITEM"
#define ERROBUYBACKWOWAI "HandleBuyBack: Error while adding item to free slot"
#define WORLDCMSGAITEMAI "WORLD"," Received CMSG_SELL_ITEM" 
#define ASSMSGASELLAITAI "WORLD"," Sent SMSG_SELL_ITEM" 
#define CMSGAITEMANAOTAI "WORLD"," Received CMSG_BUY_ITEM_IN_SLOT"
#define SMSGABUYAITEMAAI "WORLD"," Sent SMSG_BUY_ITEM"
#define CMSGAAAYAAAITEAI "WORLD"," Received CMSG_BUY_ITEM"
#define ADMSGAASAAAITEAI "WORLD"," Recvd CMSG_LIST_INVENTORY" 
#define DEVSARCTICWOWSAI "No sell template found. Report this to devs: %d (%s)"
#define SMSGAISTAAAAAOAI "WORLD"," Sent SMSG_LIST_INVENTORY"
#define CMSGAAASTAAATEAI "WORLD"," Recvd CMSG_AUTO_STORE_BAG_ITEM"
#define CMSGAAASDAATEDAI "HandleAutoStoreBagItem: Error while adding item to newslot"
#define CTSGAPASDAATEDAI "HandleBuyItemInSlot: Error while adding item to newslot"
#define ZWORLSWOWSESSIAI "WorldSession","Received CMSG_READ_ITEM %d"
#define WORLDSSESIONWOAI "WorldSession","Sent SMSG_READ_OK %d"
#define REPAIRITEMWOWSAI "Repair: Unknown item level (%u)"
#define REPAIRITFGWOWSAI "Repair: Unknown item quality (%u)"
#define CMSGAREPAIRAITAI "WorldSession","Received CMSG_REPAIR_ITEM %d"
#define CMSGABUYSLOTWOAI "WorldSession","Received CMSG_BUY_bytes_SLOT"
#define SADGABUYSLOTWOAI "WorldSession","HandleBuyBankSlotOpcode: slot number = %d"
#define GODGABUGFSLFWOAI "WorldSession","Received CMSG_AUTO_BANK_ITEM"
#define GODGABUFSSLFWOAI "WorldSession","HandleAutoBankItemOpcode: Inventory slot: %u Source Slot: %u"
#define ERRORERRORERROAI "[ERROR]AutoBankItem: Error while adding item to bank bag!\n"
#define WORCMSGFDLDCMSAI "WORLD: CMSG_AUTOSTORE_BANK_ITEM"
#define ITEMAUTOSBANKSAI "ITEM: AutoStore Bank Item, Inventory slot: %u Source Slot: %u"
#define ERRORCMSGAAUTOAI "[ERROR]AutoStoreBankItem: Error while adding item from one of the bank bags to the player bag!\n"

#endif
