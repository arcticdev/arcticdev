/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _CONTAINER_H
#define _CONTAINER_H

class SERVER_DECL Container : public Item
{
public:
	friend class WorldSession;
	Container(uint32 high, uint32 low);
	~Container();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	virtual void Init();
	virtual void Destructor();

	void Create( uint32 itemid, PlayerPointer owner );
	void LoadFromDB( Field*fields);

	bool AddItem(int8 slot, ItemPointer item);
	bool AddItemToFreeSlot(ItemPointer pItem, uint32 * r_slot);
	ItemPointer GetItem(int8 slot)
	{
		if(slot >= 0 && (uint8)slot < GetProto()->ContainerSlots)
			return m_Slot[slot];
		else
			return NULLITEM;
	}
	
	int8 FindFreeSlot();
	bool HasItems();
	
	void SwapItems(int8 SrcSlot,int8 DstSlot);
	ItemPointer SafeRemoveAndRetreiveItemFromSlot(int8 slot, bool destroy); // doesnt destroy item from memory
	bool SafeFullRemoveItemFromSlot(int8 slot); // destroys item fully
   
	void SaveBagToDB(int8 slot, bool first, QueryBuffer * buf);

protected:
	ItemPointer m_Slot[72];
	uint32 __fields[CONTAINER_END];
};

#endif
