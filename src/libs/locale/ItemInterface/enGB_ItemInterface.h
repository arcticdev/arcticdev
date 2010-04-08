/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __ENGB_ITEMINTERFACE_H
#define __ENGB_ITEMINTERFACE_H
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ItemInterface.cpp                        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Строчки
#define SMAXSISLOTAI "%s: slot (%d) >= MAX_INVENTORY_SLOT (%d)"
#define SMAFSISLOTAI "%s: ContainerSlot (%d) >= MAX_INVENTORY_SLOT (%d)"
#define ADUPLICATEAI "A duplicated item, `%s` was found in your inventory. We've attempted to add it to a free slot in your inventory, if there is none this will fail. It will be attempted again the next time you log on."
#define SLOTWARNINAI "Slot warning: slot: %d\n"
#define SLOTWARNHOAI "setting buybackslot %u\n"
#define WLWTWARNHOAI "nulling %u\n"
#define ITEMINTERFAI "ItemInterface","SwapItemSlots(%u, %u);"

#endif
