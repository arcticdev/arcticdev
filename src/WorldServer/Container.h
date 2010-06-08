/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _CONTAINER_H
#define _CONTAINER_H

class ARCTIC_DECL Container : public Item
{
public:
	friend class WorldSession;
	Container(uint32 high, uint32 low);
	~Container();

	virtual void Init();
	virtual void Destructor();

	void Create( uint32 itemid, Player* owner );
	void LoadFromDB( Field*fields);

	bool AddItem(int16 slot, Item* item);
	bool AddItemToFreeSlot(Item* pItem, uint32 * r_slot);
	Item* GetItem(int16 slot)
	{
		if(slot >= 0 && (uint8)slot < GetProto()->ContainerSlots)
			return m_Slot[slot];
		else
			return NULLITEM;
	}
	
	int8 FindFreeSlot();
	bool HasItems();
	
	void SwapItems(int16 SrcSlot, int16 DstSlot);
	Item* SafeRemoveAndRetreiveItemFromSlot(int16 slot, bool destroy); // doesnt destroy item from memory
	bool SafeFullRemoveItemFromSlot(int16 slot); // destroys item fully

	void SaveBagToDB(int16 slot, bool first, QueryBuffer * buf);

protected:
	Item* m_Slot[72];
	uint32 __fields[CONTAINER_END];
};

#endif
