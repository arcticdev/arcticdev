/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

void WorldSession::HandleSplitOpcode(WorldPacket& recv_data)
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 5);
	int8 DstInvSlot = 0, DstSlot = 0, SrcInvSlot = 0, SrcSlot = 0;
	uint8 count = 0;

	AddItemResult result;

	recv_data >> SrcInvSlot >> SrcSlot >> DstInvSlot >> DstSlot >> count;
	if(!GetPlayer())
		return;

	if(count >= 127)
	{
		/* exploit fix */
		return;
	}

	// f*ck wpe
	if( !_player->GetItemInterface()->VerifyBagSlots(SrcInvSlot, SrcSlot) )
		return;

	if( !_player->GetItemInterface()->VerifyBagSlots(DstInvSlot, DstSlot) )
		return;

	int32 c=count;
	ItemPointer i1 =_player->GetItemInterface()->GetInventoryItem(SrcInvSlot,SrcSlot);
	if(!i1)
		return;
	ItemPointer i2=_player->GetItemInterface()->GetInventoryItem(DstInvSlot,DstSlot);

	if( (i1 && i1->wrapped_item_id) || (i2 && i2->wrapped_item_id) || ( i1 && i1->GetProto()->MaxCount < 2 ) || ( i2 && i2->GetProto()->MaxCount < 2 ) || count < 1 )
	{
		GetPlayer()->GetItemInterface()->BuildInventoryChangeError(i1, i2, INV_ERR_ITEM_CANT_STACK);
        return;
	}

	if(i2) // smth already in this slot
	{
		if(i1->GetEntry()==i2->GetEntry() )
		{
			// check if player has the required stacks to avoid exploiting.
			// safe exploit check
			if(c < (int32)i1->GetUInt32Value(ITEM_FIELD_STACK_COUNT))
			{
				// check if there is room on the other item.
				if(((c + i2->GetUInt32Value(ITEM_FIELD_STACK_COUNT)) <= i2->GetProto()->MaxCount))
				{
					i1->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, -c);
					i2->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, +c);
					i1->m_isDirty = true;
					i2->m_isDirty = true;
				}
				else
				{
					 GetPlayer()->GetItemInterface()->BuildInventoryChangeError(i1, i2, INV_ERR_ITEM_CANT_STACK);
				}
			}
			else
			{
				// error cant split item
				_player->GetItemInterface()->BuildInventoryChangeError(i1, i2, INV_ERR_COULDNT_SPLIT_ITEMS);
			}
		}
		else
		{
			 GetPlayer()->GetItemInterface()->BuildInventoryChangeError(i1, i2, INV_ERR_ITEM_CANT_STACK);
		}
	}
	else
	{
		if(c < (int32)i1->GetUInt32Value(ITEM_FIELD_STACK_COUNT))
		{
			i1->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT,-c);

			i2=objmgr.CreateItem(i1->GetEntry(),_player);
			i2->SetUInt32Value(ITEM_FIELD_STACK_COUNT,c);
			i1->m_isDirty = true;
			i2->m_isDirty = true;

			if(DstSlot == -1)
			{
				// Find a free slot
				SlotResult res = _player->GetItemInterface()->FindFreeInventorySlot(i2->GetProto());
				if(!res.Result)
				{
					SendNotification(TPUERROORINTERAI);
					return;
				}
				else
				{
					DstSlot = res.Slot;
					DstInvSlot = res.ContainerSlot;
				}
			}
			result = _player->GetItemInterface()->SafeAddItem(i2,DstInvSlot,DstSlot);
			if(!result)
			{
				printf(HABDDIUSBUYITEAI);
				i2->Destructor();
				i2 = NULLITEM;
			}
		}
		else
		{
			_player->GetItemInterface()->BuildInventoryChangeError(i1, i2, INV_ERR_COULDNT_SPLIT_ITEMS);
		}
	}
}

void WorldSession::HandleSwapItemOpcode(WorldPacket& recv_data)
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 4);
	WorldPacket data;
	WorldPacket packet;
	ItemPointer SrcItem = NULLITEM;
	ItemPointer DstItem = NULLITEM;

	int8 DstInvSlot = 0, DstSlot = 0, SrcInvSlot = 0, SrcSlot = 0, error = 0;

	if(!GetPlayer())
		return;
	
	recv_data >> DstInvSlot >> DstSlot >> SrcInvSlot >> SrcSlot;

	OUT_DEBUG(ITEMDSTINVSLOTAI, DstInvSlot, DstSlot, SrcInvSlot, SrcSlot);

	if(DstInvSlot == SrcSlot && SrcInvSlot == -1) // player trying to add self container to self container slots
	{
		GetPlayer()->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEMS_CANT_BE_SWAPPED);
		return;
	}

	if( ( DstInvSlot <= 0 && DstSlot < 0 ) || DstInvSlot < -1 )
		return;
	
	if( ( SrcInvSlot <= 0 && SrcSlot < 0 ) || SrcInvSlot < -1 )
		return;

	SrcItem=_player->GetItemInterface()->GetInventoryItem(SrcInvSlot,SrcSlot);
	if(!SrcItem)
		return;

	DstItem=_player->GetItemInterface()->GetInventoryItem(DstInvSlot,DstSlot);

	if(DstItem)
	{   //check if it will go to equipment slot
		if(SrcInvSlot==INVENTORY_SLOT_NOT_SET)//not bag
		{
			if(DstItem->IsContainer())
			{
				if(TO_CONTAINER(DstItem)->HasItems())
				{
					if(SrcSlot < INVENTORY_SLOT_BAG_START || SrcSlot >= INVENTORY_SLOT_BAG_END || SrcSlot < BANK_SLOT_BAG_START || SrcSlot >= BANK_SLOT_BAG_END)
					{
						_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
						return;
					}
				}
			}

			if(SrcSlot <  INVENTORY_KEYRING_END)
			{
				if((error=GetPlayer()->GetItemInterface()->CanEquipItemInSlot(SrcInvSlot, SrcSlot, DstItem)))
				{
					_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, error);
					return;
				}
			}
		}
		else
		{
			if(DstItem->IsContainer())
			{
				if(TO_CONTAINER(DstItem)->HasItems())
				{
					_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
					return;
				}
			}

			if((error=GetPlayer()->GetItemInterface()->CanEquipItemInSlot(SrcInvSlot, SrcInvSlot, DstItem)))
			{
				_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, error);
				return;
			}
		}
	}

	if(SrcItem)
	{   //check if it will go to equipment slot
		if(DstInvSlot==INVENTORY_SLOT_NOT_SET)//not bag
		{
			if(SrcItem->IsContainer())
			{
				if(TO_CONTAINER(SrcItem)->HasItems())
				{
					if(DstSlot < INVENTORY_SLOT_BAG_START || DstSlot >= INVENTORY_SLOT_BAG_END || DstSlot < BANK_SLOT_BAG_START || DstSlot >= BANK_SLOT_BAG_END)
					{
						_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
						return;
					}
				}
			}

			if(DstSlot <  INVENTORY_KEYRING_END)
			{
				if((error=GetPlayer()->GetItemInterface()->CanEquipItemInSlot(DstInvSlot, DstSlot, SrcItem)))
				{
					_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, error);
					return;
				}
			} 
		}
		else
		{
			if(SrcItem->IsContainer())
			{
				if(TO_CONTAINER(SrcItem)->HasItems())
				{
					_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
					return;
				}
			}

			if((error=GetPlayer()->GetItemInterface()->CanEquipItemInSlot(DstInvSlot, DstInvSlot, SrcItem)))
			{
				_player->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, error);
				return;
			}
		}
	}

	if( DstSlot < INVENTORY_SLOT_BAG_START && DstInvSlot == INVENTORY_SLOT_NOT_SET ) //equip
	{
		if( SrcItem->GetProto()->Bonding == ITEM_BIND_ON_EQUIP )
			SrcItem->SoulBind();
	}

	if( SrcInvSlot == DstInvSlot ) // in 1 bag
	{
		if( SrcInvSlot == INVENTORY_SLOT_NOT_SET ) // in backpack
		{
			_player->GetItemInterface()->SwapItemSlots( SrcSlot, DstSlot );
		}
		else // in bag
		{
			TO_CONTAINER( _player->GetItemInterface()->GetInventoryItem( SrcInvSlot ) )->SwapItems( SrcSlot, DstSlot );
		}
	}
	else
	{

		// Check for stacking
		if(DstItem && SrcItem->GetEntry()==DstItem->GetEntry() && SrcItem->GetProto()->MaxCount>1 && SrcItem->wrapped_item_id == 0 && DstItem->wrapped_item_id == 0)
		{
			uint32 total=SrcItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT)+DstItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
			if(total<=DstItem->GetProto()->MaxCount)
			{
				DstItem->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT,SrcItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT));
				DstItem->m_isDirty = true;
				bool result = _player->GetItemInterface()->SafeFullRemoveItemFromSlot(SrcInvSlot,SrcSlot);
				if(!result)
				{
					GetPlayer()->GetItemInterface()->BuildInventoryChangeError(SrcItem, DstItem, INV_ERR_ITEM_CANT_STACK);
				}
				return;
			}
			else
			{
				if(DstItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT) == DstItem->GetProto()->MaxCount)
				{

				}
				else
				{
					int32 delta=DstItem->GetProto()->MaxCount-DstItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
					DstItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT,DstItem->GetProto()->MaxCount);
					SrcItem->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT,-delta);
					SrcItem->m_isDirty = true;
					DstItem->m_isDirty = true;
					return;
				}
			}
		}
	   
		if(SrcItem)
			SrcItem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInvSlot,SrcSlot, false);

		if(DstItem)
			DstItem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(DstInvSlot,DstSlot, false);

		if(SrcItem)
		{
			AddItemResult result =_player->GetItemInterface()->SafeAddItem(SrcItem,DstInvSlot,DstSlot);
			if(!result)
			{
				printf(HANLESSWAPITEMAI);
				if (!_player->GetItemInterface()->SafeAddItem(SrcItem, SrcInvSlot, SrcSlot))
				{
					SrcItem->Destructor();
					SrcItem = NULLITEM;
				}
				if (DstItem && !_player->GetItemInterface()->SafeAddItem(DstItem, DstInvSlot, DstSlot))
				{
					DstItem->Destructor();
					DstItem = NULLITEM;
				}
				return;
			}
		}

		if(DstItem)
		{
			AddItemResult result = _player->GetItemInterface()->SafeAddItem(DstItem,SrcInvSlot,SrcSlot);
			if(!result)
			{
				printf(HANLESSWAPITSLAI);
				if (SrcItem && !_player->GetItemInterface()->SafeAddItem(SrcItem, SrcInvSlot, SrcSlot))
				{
					SrcItem->Destructor();
					SrcItem = NULLITEM;
				}
				if (!_player->GetItemInterface()->SafeAddItem(DstItem, DstInvSlot, DstSlot))
				{
					DstItem->Destructor();
					DstItem = NULLITEM;
				}
				return;
			}
		}
	}
}

void WorldSession::HandleSwapInvItemOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 2);
	WorldPacket data;
	int8 srcslot = 0, dstslot = 0;
	int8 error = 0;

	recv_data >> dstslot >> srcslot;

	if(!GetPlayer())
		return;

	OUT_DEBUG(ITEMFDTINVSLOTAI, (uint32)srcslot, (uint32)dstslot);

	if(dstslot == srcslot) // player trying to add item to the same slot
	{
		GetPlayer()->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEMS_CANT_BE_SWAPPED);
		return;
	}

	ItemPointer dstitem = _player->GetItemInterface()->GetInventoryItem(dstslot);
	ItemPointer srcitem = _player->GetItemInterface()->GetInventoryItem(srcslot);
	
	// allow weapon switching in combat
	bool skip_combat = false;
	if( srcslot < EQUIPMENT_SLOT_END || dstslot < EQUIPMENT_SLOT_END )	  // We're doing an equip swap.
	{
		if( _player->CombatStatus.IsInCombat() )
		{
			if( srcslot < EQUIPMENT_SLOT_MAINHAND || dstslot < EQUIPMENT_SLOT_MAINHAND )	// These can't be swapped
			{
				_player->GetItemInterface()->BuildInventoryChangeError(srcitem, dstitem, INV_ERR_CANT_DO_IN_COMBAT);
				return;
			}
			skip_combat= true;
		}
	}

	if( !srcitem )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( srcitem, dstitem, INV_ERR_YOU_CAN_NEVER_USE_THAT_ITEM );
		return;
	}

	if( srcslot == dstslot )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( srcitem, dstitem, INV_ERR_ITEM_DOESNT_GO_TO_SLOT );
		return;
	}
	
	if( ( error = _player->GetItemInterface()->CanEquipItemInSlot( INVENTORY_SLOT_NOT_SET, dstslot, srcitem, skip_combat ) ) )
	{
		if( dstslot < INVENTORY_KEYRING_END )
		{
			_player->GetItemInterface()->BuildInventoryChangeError( srcitem, dstitem, error );
			return;
		}
	}

	// extra check needed here for gems, because CanEquipInSlot does not pass enchantments, etc.
	// src is the item we're equipping, dst is the item we're replacing
	if( dstslot < EQUIPMENT_SLOT_END && srcitem->HasEnchantments() )
	{
		ItemPrototype * gemitm;
		for( uint32 x = 2 ; x < 5 ; x ++ )
		{
			if( srcitem->GetEnchantment( x ) )
			{
				gemitm = ItemPrototypeStorage.LookupEntry( srcitem->GetEnchantment( x )->Enchantment->GemEntry );
				if( !gemitm || ( gemitm && !( gemitm->Flags & ITEM_FLAG_UNIQUE_EQUIP ) ) )
					continue; // baaad boy
				if( _player->GetItemInterface()->HasGemEquipped( srcitem->GetEnchantment( x )->Enchantment->GemEntry , dstslot ) )
				{
					Log.Debug( HANLERSOPCODESAI , TETSGETSITEMSSAI , srcitem->GetEnchantment( x )->Enchantment->GemEntry , srcitem->GetProto()->ItemId );
					_player->GetItemInterface()->BuildInventoryChangeError( srcitem, dstitem, INV_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED );
					return;
				}
			}
		}
	}

	if(dstitem)
	{
		if((error=_player->GetItemInterface()->CanEquipItemInSlot(INVENTORY_SLOT_NOT_SET, srcslot, dstitem, skip_combat)))
		{
			if(srcslot < INVENTORY_KEYRING_END)
			{
				data.Initialize( SMSG_INVENTORY_CHANGE_FAILURE );
				data << error;
				if(error == 1) 
				{
					data << dstitem->GetProto()->RequiredLevel;
				}
				data << (srcitem ? srcitem->GetGUID() : uint64(0));
				data << (dstitem ? dstitem->GetGUID() : uint64(0));
				data << uint8(0);

				SendPacket( &data );
				return;
			}
		}
	}

	if(srcitem->IsContainer())
	{
		// source has items and dst is a backpack or bank
		if(TO_CONTAINER(srcitem)->HasItems())
			if(!_player->GetItemInterface()->IsBagSlot(dstslot))
			{
				_player->GetItemInterface()->BuildInventoryChangeError(srcitem,dstitem, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
				return;
			}

		if(dstitem)
		{
			//source is a bag and dst slot is a bag inventory and has items
			if(dstitem->IsContainer())
			{
				if(TO_CONTAINER(dstitem)->HasItems() && !_player->GetItemInterface()->IsBagSlot(srcslot))
				{
					_player->GetItemInterface()->BuildInventoryChangeError(srcitem,dstitem, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
					return;
				}
			}
			else
			{
				//dst item is not a bag, swap impossible
				_player->GetItemInterface()->BuildInventoryChangeError(srcitem,dstitem,INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
				return;
			}
		}

		//dst is bag inventory
		if(dstslot < INVENTORY_SLOT_BAG_END)
		{
			if(srcitem->GetProto()->Bonding==ITEM_BIND_ON_EQUIP)
				srcitem->SoulBind();
		}
	}

	// swap items
	_player->GetItemInterface()->SwapItemSlots(srcslot, dstslot);
}

void WorldSession::HandleDestroyItemOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 2);
	//PlayerPointer plyr = GetPlayer();

	int8 SrcInvSlot, SrcSlot;

	recv_data >> SrcInvSlot >> SrcSlot;

	OUT_DEBUG( ITEMDDESTVSLOTAI, SrcInvSlot, SrcSlot );
	ItemPointer it = _player->GetItemInterface()->GetInventoryItem(SrcInvSlot,SrcSlot);

	if(it)
	{
		if(it->IsContainer())
		{
			if(TO_CONTAINER(it)->HasItems())
			{
				_player->GetItemInterface()->BuildInventoryChangeError(
				it, NULLITEM, INV_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS);
				return;
			}
		}

		if(it->GetProto()->ItemId == ITEM_ENTRY_GUILD_CHARTER)
		{
			if( _player->m_playerInfo->charterId[CHARTER_TYPE_GUILD] != 0 )
			{
				Charter *gc = objmgr.GetCharter(_player->m_playerInfo->charterId[CHARTER_TYPE_GUILD], CHARTER_TYPE_GUILD);
				if(gc != NULL)
					gc->Destroy();

				_player->m_playerInfo->charterId[CHARTER_TYPE_GUILD] = 0;
			}
		}

		if(it->GetProto()->ItemId == ARENA_TEAM_CHARTER_2v2)
		{
			if( _player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_2V2] != 0 )
			{
				Charter *gc = objmgr.GetCharter(_player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_2V2], CHARTER_TYPE_ARENA_2V2);
				if(gc != NULL)
					gc->Destroy();

				_player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_2V2] = 0;
			}
		}

		if(it->GetProto()->ItemId == ARENA_TEAM_CHARTER_5v5)
		{
			if( _player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_5V5] != 0 )
			{
				Charter *gc = objmgr.GetCharter(_player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_5V5], CHARTER_TYPE_ARENA_5V5);
				if(gc != NULL)
					gc->Destroy();

				_player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_5V5] = 0;
			}
		}

		if(it->GetProto()->ItemId == ARENA_TEAM_CHARTER_3v3)
		{
			if( _player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_3V3] != 0 )
			{
				Charter *gc = objmgr.GetCharter(_player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_3V3], CHARTER_TYPE_ARENA_3V3);
				if(gc != NULL)
					gc->Destroy();

				_player->m_playerInfo->charterId[CHARTER_TYPE_ARENA_3V3] = 0;
			}
		}

		uint32 mail_id = it->GetUInt32Value(ITEM_FIELD_ITEM_TEXT_ID);
		if(mail_id)
			_player->m_mailBox->OnMessageCopyDeleted(mail_id); 
		
		ItemPointer pItem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInvSlot,SrcSlot,false);
		if(!pItem)
			return;

		if(_player->GetCurrentSpell() && _player->GetCurrentSpell()->i_caster==pItem)
		{
			_player->GetCurrentSpell()->i_caster=NULLITEM;
			_player->GetCurrentSpell()->cancel();
		}

		pItem->DeleteFromDB();
		pItem->Destructor();
		pItem = NULLITEM;
	}
}

void WorldSession::HandleAutoEquipItemOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 2);
	WorldPacket data;

	AddItemResult result;
	int8 SrcInvSlot, SrcSlot, error=0;
	
	if(!GetPlayer())
		return;

	recv_data >> SrcInvSlot >> SrcSlot;

	OUT_DEBUG(ITEMDAUSTVSLOTAI, SrcInvSlot, SrcSlot); 

	ItemPointer eitem=_player->GetItemInterface()->GetInventoryItem(SrcInvSlot,SrcSlot);

	if(!eitem) 
	{
		_player->GetItemInterface()->BuildInventoryChangeError(eitem, NULLITEM, INV_ERR_ITEM_NOT_FOUND);
		return;
	}

	int8 Slot = _player->GetItemInterface()->GetItemSlotByType(eitem->GetProto()->InventoryType);
	if(Slot == ITEM_NO_SLOT_AVAILABLE)
	{
		_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM,INV_ERR_ITEM_CANT_BE_EQUIPPED);
		return;
	}

	// handle equipping of items which have unique-equipped gems
	if( eitem->HasEnchantments() )
	{
		EnchantmentInstance * enchinst;
		ItemPrototype * gemproto;
		for( uint32 x = 2 ; x < 5 ; x ++ )
		{
			if( eitem->GetEnchantment( x ) )
			{
				enchinst = eitem->GetEnchantment( x );
				gemproto = ItemPrototypeStorage.LookupEntry( enchinst->Enchantment->GemEntry );
				if( gemproto && gemproto->Flags & ITEM_FLAG_UNIQUE_EQUIP && _player->GetItemInterface()->HasGemEquipped( enchinst->Enchantment->GemEntry , SrcSlot ) )
				{
					// boo-hoo, we got one already :/
					_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM,INV_ERR_ITEM_UNIQUE_EQUIPABLE); // wrong error code
					return;
				}
			}
		}
	}

	// handle equipping of 2h when we have two items equipped! :) special case.
	if((Slot == EQUIPMENT_SLOT_MAINHAND || Slot == EQUIPMENT_SLOT_OFFHAND) && !_player->titanGrip)
	{
		ItemPointer mainhandweapon = _player->GetItemInterface()->GetInventoryItem(INVENTORY_SLOT_NOT_SET, EQUIPMENT_SLOT_MAINHAND);
		if( mainhandweapon != NULL && mainhandweapon->GetProto()->InventoryType == INVTYPE_2HWEAPON )
		{
			if( Slot == EQUIPMENT_SLOT_OFFHAND && eitem->GetProto()->InventoryType == INVTYPE_WEAPON )
			{
				Slot = EQUIPMENT_SLOT_MAINHAND;
			}
		}

		if((error=_player->GetItemInterface()->CanEquipItemInSlot(INVENTORY_SLOT_NOT_SET, Slot, eitem, true, true)))
		{
			_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM, error);
			return;
		}

		if(eitem->GetProto()->InventoryType == INVTYPE_2HWEAPON)
		{
			// see if we have a weapon equipped in the offhand, if so we need to remove it
			ItemPointer offhandweapon = _player->GetItemInterface()->GetInventoryItem(INVENTORY_SLOT_NOT_SET, EQUIPMENT_SLOT_OFFHAND);
			if( offhandweapon != NULL )
			{
				// we need to de-equip this
				SlotResult result = _player->GetItemInterface()->FindFreeInventorySlot(offhandweapon->GetProto());
				if( !result.Result )
				{
					// no free slots for this item
					_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM, INV_ERR_BAG_FULL);
					return;
				}

				offhandweapon = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(INVENTORY_SLOT_NOT_SET, EQUIPMENT_SLOT_OFFHAND, false);
				if( offhandweapon == NULL )
					return;		// should never happen

				if( !_player->GetItemInterface()->SafeAddItem(offhandweapon, result.ContainerSlot, result.Slot) )
					if( !_player->GetItemInterface()->AddItemToFreeSlot(offhandweapon) )		// shouldn't happen either.
					{
						offhandweapon->Destructor();
						offhandweapon = NULLITEM;
					}
			}
		}
		else
		{
			// can't equip a non-two-handed weapon with a two-handed weapon
			mainhandweapon = _player->GetItemInterface()->GetInventoryItem(INVENTORY_SLOT_NOT_SET, EQUIPMENT_SLOT_MAINHAND);
			if( mainhandweapon != NULL && mainhandweapon->GetProto()->InventoryType == INVTYPE_2HWEAPON )
			{
				// we need to de-equip this
				SlotResult result = _player->GetItemInterface()->FindFreeInventorySlot(mainhandweapon->GetProto());
				if( !result.Result )
				{
					// no free slots for this item
					_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM, INV_ERR_BAG_FULL);
					return;
				}

				mainhandweapon = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(INVENTORY_SLOT_NOT_SET, EQUIPMENT_SLOT_MAINHAND, false);
				if( mainhandweapon == NULL )
					return;		// should never happen

				if( !_player->GetItemInterface()->SafeAddItem(mainhandweapon, result.ContainerSlot, result.Slot) )
					if( !_player->GetItemInterface()->AddItemToFreeSlot(mainhandweapon) )		// shouldn't happen either.
					{
						mainhandweapon->Destructor();
						mainhandweapon = NULLITEM;
					}
			}
		}
	}
	else
	{
		if((error = _player->GetItemInterface()->CanEquipItemInSlot(INVENTORY_SLOT_NOT_SET, Slot, eitem)))
		{
			_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM, error);
			return;
		}
	}

	if( Slot <= INVENTORY_SLOT_BAG_END )
	{
		if((error = _player->GetItemInterface()->CanEquipItemInSlot(INVENTORY_SLOT_NOT_SET, Slot, eitem, false, false)))
		{
			_player->GetItemInterface()->BuildInventoryChangeError(eitem,NULLITEM, error);
			return;
		}
	}

	ItemPointer oitem = NULLITEM;

	if( SrcInvSlot == INVENTORY_SLOT_NOT_SET )
	{
		_player->GetItemInterface()->SwapItemSlots( SrcSlot, Slot );
	}
	else
	{
		eitem=_player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInvSlot,SrcSlot, false);
		oitem=_player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(INVENTORY_SLOT_NOT_SET, Slot, false);
		if(oitem)
		{
			result = _player->GetItemInterface()->SafeAddItem(oitem,SrcInvSlot,SrcSlot);
			if(!result)
			{
				printf(HANDLESAUTOEQUAI);
				oitem->Destructor();
				oitem = NULLITEM;
			}
		}
		result = _player->GetItemInterface()->SafeAddItem(eitem, INVENTORY_SLOT_NOT_SET, Slot);
		if(!result)
		{
			printf(HANDFGSAUTOEQUAI);
			eitem->Destructor();
			eitem = NULLITEM;
		}
		
	}

	if(eitem && eitem->GetProto()->Bonding==ITEM_BIND_ON_EQUIP)
		eitem->SoulBind();

}

void WorldSession::HandleItemQuerySingleOpcode( WorldPacket & recv_data )
{
	CHECK_PACKET_SIZE(recv_data, 4);
 
	int i;
	uint32 itemid=0;
	recv_data >> itemid;

	ItemPrototype *itemProto = ItemPrototypeStorage.LookupEntry(itemid);
	if(!itemProto)
	{
		DEBUG_LOG( WORLDWORLDWORLAI, itemid );
		return;
	} 

	uint8 databuffer[1000];
	StackPacket data(SMSG_ITEM_QUERY_SINGLE_RESPONSE, databuffer, 1000);
	
	LocalizedItem* li = (language>0) ? sLocalizationMgr.GetLocalizedItem(itemid, language) : NULL;

	data << itemProto->ItemId;
	data << itemProto->Class;
	data << itemProto->SubClass;
	data << itemProto->unknown_bc;
	if(li)
		data << li->Name;
	else
		data << itemProto->Name1;

	data << uint8( 0 ) << uint8( 0 ) << uint8( 0 );      // name 2,3,4
	data << itemProto->DisplayInfoID;
	data << itemProto->Quality;
	data << itemProto->Flags;
	data << itemProto->Faction;
	data << itemProto->BuyPrice;
	data << itemProto->SellPrice;
	data << itemProto->InventoryType;
	data << itemProto->AllowableClass;
	data << itemProto->AllowableRace;
	data << itemProto->ItemLevel;
	data << itemProto->RequiredLevel;
	data << itemProto->RequiredSkill;
	data << itemProto->RequiredSkillRank;
	data << itemProto->RequiredSkillSubRank;
	data << itemProto->RequiredPlayerRank1;
	data << itemProto->RequiredPlayerRank2;
	data << itemProto->RequiredFaction;
	data << itemProto->RequiredFactionStanding;
	data << itemProto->Unique;
	data << itemProto->MaxCount;
	data << itemProto->ContainerSlots;
	data << uint32( 10 ); // 3.0.2 count of stats
	for(i = 0; i < 10; i++)
	{
		data << itemProto->Stats[i].Type;
		data << itemProto->Stats[i].Value;
	}
	data << uint32( 0 );								// 3.0.2 related to scaling stats
	data << uint32( 0 );								// 3.0.2 related to scaling stats
	for(i = 0; i < 2; i++)
	{
		data << itemProto->Damage[i].Min;
		data << itemProto->Damage[i].Max;
		data << itemProto->Damage[i].Type;
	}
	// 7 resistances
	data << itemProto->Armor;
	data << itemProto->HolyRes;
	data << itemProto->FireRes;
	data << itemProto->NatureRes;
	data << itemProto->FrostRes;
	data << itemProto->ShadowRes;
	data << itemProto->ArcaneRes;
	data << itemProto->Delay;
	data << itemProto->AmmoType;
	data << itemProto->Range;
	
	for(i = 0; i < 2; ++i)
	{
	    data << itemProto->Spells[i].Id;
		data << itemProto->Spells[i].Trigger;
		data << itemProto->Spells[i].Charges;
		data << itemProto->Spells[i].Cooldown;
		data << itemProto->Spells[i].Category;
		data << itemProto->Spells[i].CategoryCooldown;
	}
	
	data << itemProto->Bonding;
	if(li)
		data << li->Description;
	else
		data << itemProto->Description;

	data << itemProto->PageId;
	data << itemProto->PageLanguage;
	data << itemProto->PageMaterial;
	data << itemProto->QuestId;
	data << itemProto->LockId;
	data << itemProto->LockMaterial;
	data << itemProto->SheathID;
	data << itemProto->RandomPropId;
	data << itemProto->RandomSuffixId;
	data << itemProto->Block;
	data << itemProto->ItemSet;
	data << itemProto->MaxDurability;
	data << itemProto->ZoneNameID;
	data << itemProto->MapID;
	data << itemProto->BagFamily;
	data << itemProto->TotemCategory;
	// 3 sockets
	data << itemProto->Sockets[0].SocketColor ;
	data << itemProto->Sockets[0].Unk;
	data << itemProto->Sockets[1].SocketColor ;
	data << itemProto->Sockets[1].Unk ;
	data << itemProto->Sockets[2].SocketColor ;
	data << itemProto->Sockets[2].Unk ;
	data << itemProto->SocketBonus;
	data << itemProto->GemProperties;
	data << itemProto->DisenchantReqSkill;
	data << itemProto->ArmorDamageModifier;
	data << itemProto->ExistingDuration;            // 2.4.2 
	data << itemProto->ItemLimitCategory;           // 3.0.2
	data << itemProto->HolidayId;                   // schnek: HolidayNames.dbc 

	SendPacket( &data );
}

void WorldSession::HandleBuyBackOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 8);
	WorldPacket data(16);
	uint64 guid;
	int32 stuff;
	ItemPointer add ;
	AddItemResult result;
	uint8 error;

	DEBUG_LOG( CMSGABUYBACKASAI );

	recv_data >> guid >> stuff;
	stuff -= 74;

	// prevent crashes
	if( stuff > MAX_BUYBACK_SLOT)
		return;

	//what a magical number 69???
	ItemPointer it = _player->GetItemInterface()->GetBuyBack(stuff);
	if (it)
	{
		// Find free slot and break if inv full
		uint32 amount = it->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
		uint32 itemid = it->GetEntry(); 
	  
		add = _player->GetItemInterface()->FindItemLessMax(itemid,amount, false);
	 
		   uint32 FreeSlots = _player->GetItemInterface()->CalculateFreeSlots(it->GetProto());
		if ((FreeSlots == 0) && (!add))
		{
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_INVENTORY_FULL);
			return;
		}
		
		// Check for gold
		int32 cost =_player->GetUInt32Value(PLAYER_FIELD_BUYBACK_PRICE_1 + stuff);
		if((int32)_player->GetUInt32Value(PLAYER_FIELD_COINAGE) < cost )
		{
			WorldPacket data(SMSG_BUY_FAILED, 12);
			data << uint64( guid );
			data << getMSTime();
			data << uint32( itemid );
			data << uint8( 2 ); // not enough money
			SendPacket( &data );
			return;
		}
		// Check for item uniqueness
		if ((error = _player->GetItemInterface()->CanReceiveItem(it->GetProto(), amount, NULL)))
		{
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, error);
			return;
		}
		_player->ModUnsigned32Value( PLAYER_FIELD_COINAGE , -cost);
		_player->GetItemInterface()->RemoveBuyBackItem(stuff);

		if (!add)
		{
			it->m_isDirty = true;			// save the item again on logout
			result = _player->GetItemInterface()->AddItemToFreeSlot(it);
			if(!result)
			{
				printf(ERROBUYBACKWOWAI);
				it->Destructor();
				it = NULLITEM;
			}
		}
		else
		{
			add->SetCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + amount);
			add->m_isDirty = true;

			// delete the item
			it->DeleteFromDB();

			// free the pointer
			it->DestroyForPlayer( _player );
			it->Delete();
		}

		data.Initialize( SMSG_BUY_ITEM );
		data << uint64( guid );
		data << getMSTime();
		data << uint32( itemid );
		data << uint32( amount );
		
		SendPacket( &data );
	}
	_player->SaveToDB(false);
}

void WorldSession::HandleSellItemOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 17);
	DEBUG_LOG(WORLDCMSGAITEMAI);
	if(!GetPlayer())
		return;

	uint64 vendorguid = 0, itemguid = 0;
	int8 amount = 0;

	recv_data >> vendorguid;
	recv_data >> itemguid;
	recv_data >> amount;
    if(amount == 0)
      return;

	if(_player->isCasting())
		_player->InterruptCurrentSpell();

	// Check if item exists
	if(!itemguid)
	{
		SendSellItem(vendorguid, itemguid, 1);
		return;
	}

	CreaturePointer unit = _player->GetMapMgr()->GetCreature(GET_LOWGUID_PART(vendorguid));
	// Check if Vendor exists
	if (unit == NULL)
	{
		SendSellItem(vendorguid, itemguid, 3);
		return;
	}

	ItemPointer item = _player->GetItemInterface()->GetItemByGUID(itemguid);
	if(!item)
	{
		SendSellItem(vendorguid, itemguid, 1);
		return; // our player doesn't have this item
	}

	ItemPrototype *it = item->GetProto();
	if(!it)
	{
		SendSellItem(vendorguid, itemguid, 2);
		return; // our player doesn't have this item
	}

	if(item->IsContainer() && TO_CONTAINER(item)->HasItems())
	{
		SendSellItem(vendorguid, itemguid, 6);
		return;
	}

	// Check if item can be sold
	if( it->SellPrice == 0 || item->wrapped_item_id != 0 || it->BuyPrice == 0 )
	{
		SendSellItem(vendorguid, itemguid, 2);
		return;
	}
	
	uint32 stackcount = item->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
	uint32 quantity = 0;

	if (amount != 0)
	{
		quantity = amount;
	}
	else
	{
		quantity = stackcount; // allitems
	}

	if(quantity > stackcount) quantity = stackcount; // make sure we don't over do it
	
	uint32 price = GetSellPriceForItem(it, quantity);

	_player->ModUnsigned32Value(PLAYER_FIELD_COINAGE,price);
 
	if(quantity < stackcount)
	{
		item->SetCount(stackcount - quantity);
		item->m_isDirty = true;
	}
	else
	{
		// removing the item from the char's inventory
		item = _player->GetItemInterface()->SafeRemoveAndRetreiveItemByGuid(itemguid, false); // again to remove item from slot
		if(item)
		{
			_player->GetItemInterface()->AddBuyBackItem(item,(it->SellPrice) * quantity);
			item->DeleteFromDB();
		}
	}

	WorldPacket data(SMSG_SELL_ITEM, 12);
	data << vendorguid << itemguid << uint8(0); 
	SendPacket( &data );

	DEBUG_LOG(ASSMSGASELLAITAI);

	_player->SaveToDB(false);
}

void WorldSession::HandleBuyItemInSlotOpcode( WorldPacket & recv_data ) // drag & drop
{
	if( !_player->IsInWorld() )
		return;

	CHECK_PACKET_SIZE( recv_data, 22 );

	DEBUG_LOG( CMSGAITEMANAOTAI );

	if( GetPlayer() == NULL )
		return;

	uint64 srcguid, bagguid;
	uint32 itemid;
	int32 slot;
	uint8 amount = 0;
	uint8 error;
	int8 bagslot = INVENTORY_SLOT_NOT_SET;
	int32 vendorslot; // VLack: 3.1.2

 	recv_data >> srcguid >> itemid;
	recv_data >> vendorslot; // VLack: 3.1.2 This is the slot's number on the vendor's panel, starts from 1
	recv_data >> bagguid;
	recv_data >> slot; // VLack: 3.1.2 the target slot the player selected - backpack 23-38, other bags 0-15 (Or how big is the biggest bag? 0-127?)
 	recv_data >> amount;

    if(amount == 0)
      return;

	if( _player->isCasting() )
		_player->InterruptCurrentSpell();

	CreaturePointer unit = _player->GetMapMgr()->GetCreature( GET_LOWGUID_PART(srcguid) );
	if( unit == NULL || !unit->HasItems() )
		return;

	ContainerPointer c = NULLCONTAINER;

	CreatureItem ci;
	unit->GetSellItemByItemId( itemid, ci );

	if( ci.itemid == 0 )
		return;

	if( amount < 1 )
		amount = 1;

	if( ci.max_amount > 0 && ci.available_amount < amount )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( NULLITEM, NULLITEM, INV_ERR_ITEM_IS_CURRENTLY_SOLD_OUT );
		return;
	}

	ItemPrototype* it = ItemPrototypeStorage.LookupEntry( itemid );
	
	if( it == NULL)
		return;

	if( it->MaxCount > 0 && ci.amount*amount > it->MaxCount)
	{
		_player->GetItemInterface()->BuildInventoryChangeError( NULLITEM, NULLITEM, INV_ERR_CANT_CARRY_MORE_OF_THIS );
		return;
	}

	uint32 count_per_stack = ci.amount * amount;

    // if slot is diferent than -1, check for validation, else continue for auto storing.
	if(slot != INVENTORY_SLOT_NOT_SET)
	{
		if(!(bagguid>>32)) // buy to bakcpack
		{
			if(slot > INVENTORY_SLOT_ITEM_END || slot < INVENTORY_SLOT_ITEM_START)
			{
				// hackers!
				_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEM_DOESNT_GO_TO_SLOT);
				return;
			}
		}
		else
		{
			c = TO_CONTAINER(_player->GetItemInterface()->GetItemByGUID(bagguid));
			if(!c)return;
			bagslot = _player->GetItemInterface()->GetBagSlotByGuid(bagguid);

			if(bagslot == INVENTORY_SLOT_NOT_SET || (c->GetProto() && (uint32)slot > c->GetProto()->ContainerSlots))
			{
				_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEM_DOESNT_GO_TO_SLOT);
				return;
			}
		}
	}
	else
	{
		if((bagguid>>32))
		{
			c=TO_CONTAINER(_player->GetItemInterface()->GetItemByGUID(bagguid));
			if(!c)
			{
				_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEM_NOT_FOUND);
				return;// non empty
			}

			bagslot = _player->GetItemInterface()->GetBagSlotByGuid(bagguid);
			slot = c->FindFreeSlot();
		}
		else
			slot=_player->GetItemInterface()->FindFreeBackPackSlot();
	}

	if((error = _player->GetItemInterface()->CanReceiveItem(it, amount, ci.extended_cost)))
	{
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, error);
		return;
	}

	if((error = _player->GetItemInterface()->CanAffordItem(it,amount,unit, ci.extended_cost)))
	{
		SendBuyFailed(srcguid, ci.itemid, error);
		return;
	}

	if(slot==INVENTORY_SLOT_NOT_SET)
	{
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_BAG_FULL);
		return;
	}

	// ok our z and slot are set.
	ItemPointer oldItem= NULLITEM;
	ItemPointer pItem=NULLITEM;
	if(slot != INVENTORY_SLOT_NOT_SET)
		oldItem = _player->GetItemInterface()->GetInventoryItem(bagslot, slot);

	if(oldItem != NULL)
	{
		if (oldItem->wrapped_item_id != 0)
		{
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_CANT_CARRY_MORE_OF_THIS);
			return;
		}

		// try to add to the existing items stack
		if(oldItem->GetProto() != it || oldItem->wrapped_item_id)
		{
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEM_DOESNT_GO_TO_SLOT);
			return;
		}

		if((oldItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + count_per_stack) > it->MaxCount)
		{
//			OUT_DEBUG( "SUPADBG can't carry #2" );
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_CANT_CARRY_MORE_OF_THIS);
			return;
		}

		oldItem->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, count_per_stack);
		oldItem->m_isDirty = true;
		pItem=oldItem;
	}
	else
	{
		// create new item
		if(slot == INVENTORY_SLOT_NOT_SET)
			slot = c->FindFreeSlot();
		
		if(slot==ITEM_NO_SLOT_AVAILABLE || slot == INVENTORY_SLOT_NOT_SET )
		{
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_BAG_FULL);
			return;
		}

        pItem = objmgr.CreateItem(it->ItemId, _player);
		if(pItem)
		{
			pItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT, count_per_stack);
			pItem->m_isDirty = true;
//			OUT_DEBUG( "SUPADBG bagslot=%u, slot=%u" , bagslot, slot );
			if(!_player->GetItemInterface()->SafeAddItem(pItem, bagslot, slot))
			{
				pItem->Destructor();
				pItem = NULLITEM;
				return;
			}
		}
		else
			return;
	}

	SendItemPushResult(pItem, false, true, false, (pItem==oldItem) ? false : true, bagslot, slot, amount*ci.amount);

	WorldPacket data( SMSG_BUY_ITEM, 22 );
	data << uint64( srcguid );
	data << getMSTime();
	data << uint32( itemid );
	data << uint32( amount );
 
	SendPacket( &data );
	DEBUG_LOG( SMSGABUYAITEMAAI );

	_player->GetItemInterface()->BuyItem(it,amount,unit, ci.extended_cost);
	if(ci.max_amount)
	{
		unit->ModAvItemAmount(ci.itemid,ci.amount*amount);

		// there is probably a proper opcode for this. - burlex
		SendInventoryList(unit);
	}

	_player->SaveToDB(false);
}

void WorldSession::HandleBuyItemOpcode( WorldPacket & recv_data ) // right-click on item
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 14);
	DEBUG_LOG( CMSGAAAYAAAITEAI );

	if(!GetPlayer())
		return;

	WorldPacket data(45);
	uint64 srcguid = 0;
	uint32 itemid = 0;
	int32 slot = 0;
	uint8 amount = 0;
	ItemPointer add = NULLITEM;
	uint8 error = 0;
	SlotResult slotresult;
	AddItemResult result;

	recv_data >> srcguid >> itemid;
	recv_data >> slot >> amount;


	CreaturePointer unit = _player->GetMapMgr()->GetCreature(GET_LOWGUID_PART(srcguid));
	if (unit == NULL || !unit->HasItems())
		return;

	if(amount < 1)
		amount = 1;

	CreatureItem item;
	unit->GetSellItemByItemId(itemid, item);

	if(item.itemid == 0)
	{
		// vendor does not sell this item.. bitch about cheaters?
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_DONT_OWN_THAT_ITEM);
		return;
	}

	if (item.max_amount>0 && item.available_amount<amount)
	{
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEM_IS_CURRENTLY_SOLD_OUT);
		return;
	}

	ItemPrototype *it = ItemPrototypeStorage.LookupEntry(itemid);
	if(!it) 
	{
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_DONT_OWN_THAT_ITEM);
		return;
	}

	if( amount > it->MaxCount )
	{
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_ITEM_CANT_STACK);
		return;
	}

	if((error = _player->GetItemInterface()->CanReceiveItem(it, amount*item.amount, item.extended_cost)))
	{
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, error);
		return;
	}

   if((error = _player->GetItemInterface()->CanAffordItem(it, amount, unit, item.extended_cost)))
   {
      SendBuyFailed(srcguid, itemid, error);
      return;
   }
 
	// Find free slot and break if inv full
	add = _player->GetItemInterface()->FindItemLessMax(itemid,amount*item.amount, false);
	if (!add)
	{
		slotresult = _player->GetItemInterface()->FindFreeInventorySlot(it);
	}
	if ((!slotresult.Result) && (!add))
	{
		//Our User doesn't have a free Slot in there bag
		_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_INVENTORY_FULL);
		return;
	}

	if(!add)
	{
		ItemPointer itm = objmgr.CreateItem(item.itemid, _player);
		if(!itm)
		{
			_player->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_DONT_OWN_THAT_ITEM);
			return;
		}

		itm->m_isDirty=true;
		itm->SetUInt32Value(ITEM_FIELD_STACK_COUNT, amount*item.amount <= itm->GetProto()->MaxCount ? amount*item.amount : itm->GetProto()->MaxCount);

		if(slotresult.ContainerSlot == ITEM_NO_SLOT_AVAILABLE)
		{
			result = _player->GetItemInterface()->SafeAddItem(itm, INVENTORY_SLOT_NOT_SET, slotresult.Slot);
			if(!result)
			{
				itm->Destructor();
				itm = NULLITEM;
			}
			else
				SendItemPushResult(itm, false, true, false, true, INVENTORY_SLOT_NOT_SET, slotresult.Result, amount*item.amount);
		}
		else 
		{
			if( ItemPointer bag = _player->GetItemInterface()->GetInventoryItem(slotresult.ContainerSlot))
			{
				if( !TO_CONTAINER(bag)->AddItem(slotresult.Slot, itm) )
				{
					itm->Destructor();
					itm = NULLITEM;
				}
				else
					SendItemPushResult(itm, false, true, false, true, slotresult.ContainerSlot, slotresult.Result, 1);
			}
		}
	}
	else
	{
		add->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, amount*item.amount);
		add->m_isDirty = true;
		SendItemPushResult(add, false, true, false, false, _player->GetItemInterface()->GetBagSlotByGuid(add->GetGUID()), 1, amount*item.amount);
	}

	 data.Initialize( SMSG_BUY_ITEM );
	 data << uint64(srcguid);
	 data << getMSTime();
	 data << uint32(itemid);
	 data << uint32(amount*item.amount);
	 
	 SendPacket( &data );
		
	 _player->GetItemInterface()->BuyItem(it,amount,unit, item.extended_cost);
	 if(int32(item.max_amount) > 0)
	 {
		 unit->ModAvItemAmount(item.itemid,item.amount*amount);
		
		 // there is probably a proper opcode for this.
		 SendInventoryList(unit);
	 }

	 _player->SaveToDB(false);
}

void WorldSession::HandleListInventoryOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld())
		return;

	CHECK_PACKET_SIZE(recv_data, 8);
	DEBUG_LOG(ADMSGAASAAAITEAI);
	uint64 guid;

	recv_data >> guid;

	CreaturePointer unit = _player->GetMapMgr()->GetCreature(GET_LOWGUID_PART(guid));
	if (unit == NULL)
		return;

	if(unit->GetAIInterface())
		unit->GetAIInterface()->StopMovement(180000);

	_player->Reputation_OnTalk(unit->m_factionDBC);
	SendInventoryList(unit);
}

void WorldSession::SendInventoryList(CreaturePointer unit)
{
	if(!unit->HasItems())
	{
		sChatHandler.BlueSystemMessageToPlr(_player, DEVSARCTICWOWSAI, unit->GetEntry(), unit->GetCreatureName()->Name);
		return;
	}

	WorldPacket data(((unit->GetSellItemCount() * 28) + 9));	   // allocate

	data.SetOpcode( SMSG_LIST_INVENTORY );
	data << unit->GetGUID();
	data << uint8( 0 ); // placeholder for item count

	ItemPrototype * curItem;
	uint32 counter = 0;

	for(std::vector<CreatureItem>::iterator itr = unit->GetSellItemBegin(); itr != unit->GetSellItemEnd(); ++itr)
	{
		if(itr->itemid && (itr->max_amount == 0 || (itr->max_amount>0 && itr->available_amount >0)))
		{
			if((curItem = ItemPrototypeStorage.LookupEntry(itr->itemid)))
			{
				if(curItem->AllowableClass && !(_player->getClassMask() & curItem->AllowableClass))
					continue;
				if(curItem->AllowableRace && !(_player->getRaceMask() & curItem->AllowableRace))
					continue;
				if( !sWorld.display_free_items && curItem->BuyPrice == 0 && itr->extended_cost == NULL )
					continue;
					
				int32 av_am = (itr->max_amount>0)?itr->available_amount:-1;
				data << (counter + 1);
				data << curItem->ItemId;
				data << curItem->DisplayInfoID;
				data << av_am;
				data << GetBuyPriceForItem(curItem, 1, _player, unit);
				data << int32(-1);			// wtf is dis?
				data << itr->amount;

				if( itr->extended_cost != NULL )
					data << itr->extended_cost->costid;
				else
					data << uint32(0);

				++counter;
			}
		}
	}

	const_cast<uint8*>(data.contents())[8] = (uint8)counter;	// set count

	SendPacket( &data );
	DEBUG_LOG( SMSGAISTAAAAAOAI );
}
void WorldSession::HandleAutoStoreBagItemOpcode( WorldPacket & recv_data )
{
	CHECK_PACKET_SIZE(recv_data, 3);
	DEBUG_LOG( CMSGAAASTAAATEAI );
	
	if(!GetPlayer())
		return;

	//WorldPacket data;
	WorldPacket packet;
	int8 SrcInv = 0, Slot = 0, DstInv = 0;
	ItemPointer srcitem = NULLITEM;
	ItemPointer dstitem = NULLITEM;
	int8 NewSlot = 0;
	int8 error;
	AddItemResult result;

	recv_data >> SrcInv >> Slot >> DstInv;

	srcitem = _player->GetItemInterface()->GetInventoryItem(SrcInv, Slot);

	//source item exists
	if(srcitem)
	{
		//src containers cant be moved if they have items inside
		if(srcitem->IsContainer() && TO_CONTAINER(srcitem)->HasItems())
		{
			_player->GetItemInterface()->BuildInventoryChangeError(srcitem, NULLITEM, INV_ERR_NONEMPTY_BAG_OVER_OTHER_BAG);
			return;
		}
		// check for destination now before swaping.
		// destination is backpack
		if(DstInv == INVENTORY_SLOT_NOT_SET)
		{
			//check for space
			NewSlot = _player->GetItemInterface()->FindFreeBackPackSlot();
			if(NewSlot == ITEM_NO_SLOT_AVAILABLE)
			{
				_player->GetItemInterface()->BuildInventoryChangeError(srcitem, NULLITEM, INV_ERR_BAG_FULL);
				return;
			}
			else
			{
				//free space found, remove item and add it to the destination
				srcitem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInv, Slot, false);
				if( srcitem )
				{
					result = _player->GetItemInterface()->SafeAddItem(srcitem, INVENTORY_SLOT_NOT_SET, NewSlot);
					if(!result)
					{
						printf(CMSGAAASDAATEDAI);
						srcitem->Destructor();
						srcitem = NULLITEM;
						return;
					}
				}
			}
		}
		else
		{
			if((error=_player->GetItemInterface()->CanEquipItemInSlot(DstInv,  DstInv, srcitem)))
			{
				if(DstInv < INVENTORY_KEYRING_END)
				{
					_player->GetItemInterface()->BuildInventoryChangeError(srcitem,dstitem, error);
					return;
				}
			}

			// destination is a bag
			dstitem = _player->GetItemInterface()->GetInventoryItem(DstInv);
			if(dstitem)
			{
				// dstitem exists, detect if its a container
				if(dstitem->IsContainer())
				{
					NewSlot = TO_CONTAINER(dstitem)->FindFreeSlot();
					if(NewSlot == ITEM_NO_SLOT_AVAILABLE)
					{
						_player->GetItemInterface()->BuildInventoryChangeError(srcitem, NULLITEM, INV_ERR_BAG_FULL);
						return;
					}
					else
					{
						srcitem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInv, Slot, false);
						if( srcitem != NULL )
						{
							result = _player->GetItemInterface()->SafeAddItem(srcitem, DstInv, NewSlot);
							if(!result)
							{
								printf(CTSGAPASDAATEDAI);
								srcitem->Destructor();
								srcitem = NULLITEM;
								return;
							}		
						}
					}
				}
				else
				{
					_player->GetItemInterface()->BuildInventoryChangeError(srcitem, NULLITEM,  INV_ERR_ITEM_DOESNT_GO_TO_SLOT);
					return;
				}
			}
			else
			{
				_player->GetItemInterface()->BuildInventoryChangeError(srcitem, NULLITEM, INV_ERR_ITEM_DOESNT_GO_TO_SLOT);
				return;
			}
		}
	}
	else
	{
		_player->GetItemInterface()->BuildInventoryChangeError(srcitem, NULLITEM, INV_ERR_ITEM_NOT_FOUND);
		return;
	}
}

void WorldSession::HandleReadItemOpcode(WorldPacket &recvPacket)
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recvPacket, 2);
	int8 uslot=0, slot=0;
	recvPacket >> uslot >> slot;

	if(!GetPlayer())
		return;

	ItemPointer item = _player->GetItemInterface()->GetInventoryItem(uslot, slot);
	DEBUG_LOG(ZWORLSWOWSESSIAI, slot);

	if(item)
	{
		// Check if it has pagetext
	   
		if(item->GetProto()->PageId)
		{
			WorldPacket data(SMSG_READ_ITEM_OK, 4);
			data << item->GetGUID();
			SendPacket(&data);
			DEBUG_LOG(WORLDSSESIONWOAI, item->GetGUID());
		}	
	}
}

ARCTIC_INLINE uint32 RepairItemCost(PlayerPointer pPlayer, ItemPointer pItem)
{
	DurabilityCostsEntry * dcosts = dbcDurabilityCosts.LookupEntry(pItem->GetProto()->ItemLevel);
	if(!dcosts)
	{
		OUT_DEBUG(REPAIRITEMWOWSAI, dcosts);
		return 0;
	}

	DurabilityQualityEntry * dquality = dbcDurabilityQuality.LookupEntry((pItem->GetProto()->Quality + 1) * 2);
	if(!dquality)
	{
		OUT_DEBUG(REPAIRITFGWOWSAI, dquality);
		return 0;
	}

	uint32 dmodifier = dcosts->modifier[pItem->GetProto()->Class == ITEM_CLASS_WEAPON ? pItem->GetProto()->SubClass : pItem->GetProto()->SubClass + 21];
	uint32 cost = long2int32((pItem->GetDurabilityMax() - pItem->GetDurability()) * dmodifier * double(dquality->quality_modifier));
	return cost / 2;
}

ARCTIC_INLINE void RepairItem(PlayerPointer pPlayer, ItemPointer pItem)
{
	// int32 cost = (int32)pItem->GetUInt32Value( ITEM_FIELD_MAXDURABILITY ) - (int32)pItem->GetUInt32Value( ITEM_FIELD_DURABILITY );
	int32 cost = RepairItemCost(pPlayer, pItem);
	if( cost <= 0 )
		return;

	if( cost > (int32)pPlayer->GetUInt32Value( PLAYER_FIELD_COINAGE ) )
		return;

	pPlayer->ModUnsigned32Value( PLAYER_FIELD_COINAGE, -cost );
	pItem->SetDurabilityToMax();
	pItem->m_isDirty = true;
}

void WorldSession::HandleRepairItemOpcode(WorldPacket &recvPacket)
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recvPacket, 12);
	CHECK_INWORLD_RETURN
	if(!GetPlayer())
		return;

	uint64 npcguid;
	uint64 itemguid;
	ItemPointer pItem;
	ContainerPointer pContainer;
	uint32 j, i;

	recvPacket >> npcguid >> itemguid;

	CreaturePointer pCreature = _player->GetMapMgr()->GetCreature( GET_LOWGUID_PART(npcguid) );
	if( pCreature == NULL )
		return;

	if( !pCreature->HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_ARMORER ) )
		return;

	if( !itemguid ) 
	{
		for( i = 0; i < MAX_INVENTORY_SLOT; i++ )
		{
			pItem = _player->GetItemInterface()->GetInventoryItem( i );
			if( pItem != NULL )
			{
				if( pItem->IsContainer() )
				{
					pContainer = TO_CONTAINER( pItem );
					for( j = 0; j < pContainer->GetProto()->ContainerSlots; ++j )
					{
						pItem = pContainer->GetItem( j );
						if( pItem != NULL )
							RepairItem( _player, pItem );
					}
				}
				else
				{
					if( pItem->GetProto()->MaxDurability > 0 && i < INVENTORY_SLOT_BAG_END && pItem->GetDurability() <= 0 )
					{
						RepairItem( _player, pItem );
						_player->ApplyItemMods( pItem, i, true );
					}
					else
					{
						RepairItem( _player, pItem );
					}					
				}
			}
		}
	}
	else 
	{
		ItemPointer item = _player->GetItemInterface()->GetItemByGUID(itemguid);
		if(item)
		{
			SlotResult *searchres=_player->GetItemInterface()->LastSearchResult();// this never gets null since we get a pointer to the inteface internal var
			uint32 dDurability = item->GetDurabilityMax() - item->GetDurability();

			if (dDurability)
			{
				// the amount of durability that is needed to be added is the amount of money to be payed
				if (dDurability <= _player->GetUInt32Value(PLAYER_FIELD_COINAGE))
				{
					int32 cDurability = item->GetDurability();
					_player->ModUnsigned32Value( PLAYER_FIELD_COINAGE , -(int32)dDurability );
					item->SetDurabilityToMax();
					item->m_isDirty = true;
					
					// only apply item mods if they are on char equiped
	                // printf("we are fixing a single item in inventory at bagslot %u and slot %u\n",searchres->ContainerSlot,searchres->Slot);
					if(cDurability <= 0 && searchres->ContainerSlot==INVALID_BACKPACK_SLOT && searchres->Slot<INVENTORY_SLOT_BAG_END)
						_player->ApplyItemMods(item, searchres->Slot, true);
				}
				else
				{
					// not enough money
				}
			}
		}
	}
	DEBUG_LOG(CMSGAREPAIRAITAI, itemguid);
}

void WorldSession::HandleBuyBankSlotOpcode(WorldPacket& recvPacket) 
{
	if(!_player->IsInWorld()) return;
	//CHECK_PACKET_SIZE(recvPacket, 12);
	uint32 bytes,slots;
	int32 price;
	DEBUG_LOG(CMSGABUYSLOTWOAI);

	bytes = GetPlayer()->GetUInt32Value(PLAYER_BYTES_2);
	slots =(uint8) (bytes >> 16);

	DEBUG_LOG(SADGABUYSLOTWOAI, slots);
	BankSlotPrice* bsp = dbcBankSlotPrices.LookupEntry(slots+1);
	if(!bsp) return;
	price = (bsp != NULL ) ? bsp->Price : 99999999;

	if ((int32)_player->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price) 
	{
	   _player->SetUInt32Value(PLAYER_BYTES_2, (bytes&0xff00ffff) | ((slots+1) << 16) );
	   _player->ModUnsigned32Value(PLAYER_FIELD_COINAGE, -price);
	   _player->GetAchievementInterface()->HandleAchievementCriteriaBuyBankSlot();
	}
}

void WorldSession::HandleAutoBankItemOpcode(WorldPacket &recvPacket)
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recvPacket, 2);
	DEBUG_LOG(GODGABUGFSLFWOAI);

	// WorldPacket data;

	SlotResult slotresult;
	int8 SrcInvSlot, SrcSlot; // error = 0;

	if(!GetPlayer())
		return;

	recvPacket >> SrcInvSlot >> SrcSlot;

	DEBUG_LOG(GODGABUFSSLFWOAI, (uint32)SrcInvSlot, (uint32)SrcSlot);

	ItemPointer eitem=_player->GetItemInterface()->GetInventoryItem(SrcInvSlot,SrcSlot);

	if(!eitem) 
	{
		_player->GetItemInterface()->BuildInventoryChangeError(eitem, NULLITEM, INV_ERR_ITEM_NOT_FOUND);
		return;
	}

	slotresult =  _player->GetItemInterface()->FindFreeBankSlot(eitem->GetProto());

	if(!slotresult.Result)
	{
		_player->GetItemInterface()->BuildInventoryChangeError(eitem, NULLITEM, INV_ERR_BANK_FULL);
		return;
	}
	else
	{
        eitem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInvSlot,SrcSlot, false);
		// if(!_player->GetItemInterface()->SafeAddItem(eitem, slotresult.ContainerSlot, slotresult.Slot))
        if(eitem != NULL && !_player->GetItemInterface()->SafeAddItem(eitem, slotresult.ContainerSlot, slotresult.Slot))
		{
			OUT_DEBUG(ERRORERRORERROAI);
            if( !_player->GetItemInterface()->SafeAddItem(eitem, SrcInvSlot, SrcSlot) )
			{
				eitem->Destructor();
				eitem = NULLITEM;
			}
		}
	}
}

void WorldSession::HandleAutoStoreBankItemOpcode(WorldPacket &recvPacket)
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recvPacket, 2);
	OUT_DEBUG(WORCMSGFDLDCMSAI);

	int8 SrcInvSlot, SrcSlot;

	if(!GetPlayer())
		return;

	recvPacket >> SrcInvSlot >> SrcSlot;

	OUT_DEBUG(ITEMAUTOSBANKSAI, (uint32)SrcInvSlot, (uint32)SrcSlot);

	ItemPointer eitem=_player->GetItemInterface()->GetInventoryItem(SrcInvSlot,SrcSlot);

	if(!eitem) 
	{
		_player->GetItemInterface()->BuildInventoryChangeError(eitem, NULLITEM, INV_ERR_ITEM_NOT_FOUND);
		return;
	}

	SlotResult slotresult = _player->GetItemInterface()->FindFreeInventorySlot(eitem->GetProto());

	if(!slotresult.Result)
	{
		_player->GetItemInterface()->BuildInventoryChangeError(eitem, NULLITEM, INV_ERR_INVENTORY_FULL);
		return;
	}
	else
	{
        eitem = _player->GetItemInterface()->SafeRemoveAndRetreiveItemFromSlot(SrcInvSlot, SrcSlot, false);
		// if (!_player->GetItemInterface()->AddItemToFreeSlot(eitem))
		if( eitem != NULL && !_player->GetItemInterface()->AddItemToFreeSlot(eitem))
		{
			OUT_DEBUG(ERRORCMSGAAUTOAI);
			if( !_player->GetItemInterface()->SafeAddItem(eitem, SrcInvSlot, SrcSlot) )
			{
				eitem->Destructor();
				eitem = NULLITEM;
			}
		}
		_player->SaveToDB(false);
	}
}

void WorldSession::HandleCancelTemporaryEnchantmentOpcode(WorldPacket &recvPacket)
{
	if(!_player->IsInWorld()) return;
	uint32 inventory_slot;
	recvPacket >> inventory_slot;

	ItemPointer item = _player->GetItemInterface()->GetInventoryItem(inventory_slot);
	if(!item) return;

	item->RemoveAllEnchantments(true);
}

void WorldSession::HandleInsertGemOpcode(WorldPacket &recvPacket)
{
	uint64 itemguid;
	uint64 gemguid;
	GemPropertyEntry * gp;
	EnchantEntry * Enchantment;
	recvPacket >> itemguid;

	CHECK_INWORLD_RETURN;

	GetPlayer()->ObjLock();

	ItemPointer TargetItem =_player->GetItemInterface()->GetItemByGUID(itemguid);
	if(!TargetItem)
	{
		GetPlayer()->ObjUnlock();
		return;
	}
	int slot =_player->GetItemInterface()->GetInventorySlotByGuid(itemguid);
	bool apply = (slot>=0 && slot <19);
	uint32 FilledSlots=0;

	bool ColorMatch = true;
	for(uint32 i = 0;i<TargetItem->GetSocketsCount();i++)
	{
		recvPacket >> gemguid;
		EnchantmentInstance * EI= TargetItem->GetEnchantment(2+i);
		if(EI)
		{
			FilledSlots++;
			ItemPrototype * ip = ItemPrototypeStorage.LookupEntry(EI->Enchantment->GemEntry);
			if(!ip)
				gp = 0;
			else
				gp = dbcGemProperty.LookupEntry(ip->GemProperties);
	
			if(gp && !(gp->SocketMask & TargetItem->GetProto()->Sockets[i].SocketColor))
				ColorMatch=false;
		}

		if(gemguid)//add or replace gem
		{
			ItemInterface * itemi = _player->GetItemInterface();
			ItemPrototype * ip = NULL;
			ItemPointer it = itemi->GetItemByGUID(gemguid);			
			if (apply) 
			{				
				if( !it )
					continue;

				ip = it->GetProto();

				if( !ip )
					continue;

				if( ip->Flags & ITEM_FLAG_UNIQUE_EQUIP && itemi->IsEquipped( ip->ItemId ) )
				{
					itemi->BuildInventoryChangeError( it, TargetItem, INV_ERR_CANT_CARRY_MORE_OF_THIS );
					continue;
				}
				// Skill requirement
				if( ip->RequiredSkill )
				{
					if( ip->RequiredSkillRank > _player->_GetSkillLineCurrent( ip->RequiredSkill, true ) )
					{
						itemi->BuildInventoryChangeError( it, TargetItem, INV_ERR_SKILL_ISNT_HIGH_ENOUGH );
						continue;
					}
				}
				if( ip->ItemLimitCategory )
				{
					ItemLimitCategoryEntry * ile = dbcItemLimitCategory.LookupEntry( ip->ItemLimitCategory );
					if( ile != NULL && itemi->GetEquippedCountByItemLimit( ip->ItemLimitCategory ) >= ile->maxAmount )
					{
						itemi->BuildInventoryChangeError(it, TargetItem, INV_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED);
						continue;
					}
				}
			}
			
			it = _player->GetItemInterface()->SafeRemoveAndRetreiveItemByGuid(gemguid,true);
			if(!it)
				continue;

			if( it->GetProto()->Flags & ITEM_FLAG_UNIQUE_EQUIP && _player->GetItemInterface()->HasGemEquipped( it->GetProto()->ItemId , -1 ) )
			{
				_player->GetItemInterface()->BuildInventoryChangeError( TargetItem , TargetItem , INV_ERR_ITEM_MAX_COUNT_EQUIPPED_SOCKETED );
				// .. we removed the gem, so we gotta recompensate it :x
				// afaik, ugly solution. However, it has the interesting bonus of being able to automatically remove the gem from the socketing screen!
				SlotResult sr;
				sr = _player->GetItemInterface()->FindFreeInventorySlot( it->GetProto() );
				if( sr.Result )
					_player->GetItemInterface()->SafeAddItem( it , sr.ContainerSlot , sr.Slot );
				continue;
			}
			gp = dbcGemProperty.LookupEntry(it->GetProto()->GemProperties);
			it->Destructor();
			it = NULLITEM;
		
			if(!gp)
				continue;
			if(!(gp->SocketMask & TargetItem->GetProto()->Sockets[i].SocketColor))
				ColorMatch=false;

			if(!gp->EnchantmentID) // this is ok in few cases
				continue;

			// exploit fix
			if (TargetItem->GetProto()->Sockets[i].SocketColor != GEM_META_SOCKET && gp->SocketMask == GEM_META_SOCKET)
				continue;

			if(EI) // replace gem
				TargetItem->RemoveEnchantment(2+i);//remove previous
			else // add gem
				FilledSlots++;

			Enchantment = dbcEnchant.LookupEntry(gp->EnchantmentID);
			if(Enchantment)
				TargetItem->AddEnchantment(Enchantment, 0, true,apply,false,2+i);
		}
	}

	// Add color match bonus
	if(TargetItem->GetProto()->SocketBonus)
	{
		if(ColorMatch && (FilledSlots==TargetItem->GetSocketsCount()))
		{
			if(TargetItem->HasEnchantment(TargetItem->GetProto()->SocketBonus) > 0)
			{
				GetPlayer()->ObjUnlock();
				return;
			}

			Enchantment = dbcEnchant.LookupEntry(TargetItem->GetProto()->SocketBonus);
			if(Enchantment)
			{
				uint32 Slot = TargetItem->FindFreeEnchantSlot(Enchantment,0);
				TargetItem->AddEnchantment(Enchantment, 0, true,apply,false, Slot);
			}
		}else //remove
		{
			TargetItem->RemoveSocketBonusEnchant();
		}
	}

	TargetItem->m_isDirty = true;

	GetPlayer()->ObjUnlock();
}

void WorldSession::HandleWrapItemOpcode( WorldPacket& recv_data )
{
	int8 sourceitem_bagslot, sourceitem_slot;
	int8 destitem_bagslot, destitem_slot;
	uint32 source_entry;
	uint32 itemid;
	ItemPointer src,dst;

	recv_data >> sourceitem_bagslot >> sourceitem_slot;
	recv_data >> destitem_bagslot >> destitem_slot;

	CHECK_INWORLD_RETURN;

	src = _player->GetItemInterface()->GetInventoryItem( sourceitem_bagslot, sourceitem_slot );
	dst = _player->GetItemInterface()->GetInventoryItem( destitem_bagslot, destitem_slot );

	if( !src || !dst )
		return;

	if(src == dst || !(src->GetProto()->Class == ITEM_CLASS_CONSUMABLE && src->GetProto()->SubClass == ITEM_SUBCLASS_CONSUMABLE_OTHER))
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_WRAPPED_CANT_BE_WRAPPED );
		return;
	}

	if( dst->GetUInt32Value( ITEM_FIELD_STACK_COUNT ) > 1 )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_STACKABLE_CANT_BE_WRAPPED );
		return;
	}

	if( dst->GetProto()->MaxCount > 1 )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_STACKABLE_CANT_BE_WRAPPED );
		return;
	}

	if( dst->IsSoulbound() || dst->GetProto()->Bonding != 0)
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_BOUND_CANT_BE_WRAPPED );
		return;
	}

	if( dst->wrapped_item_id || src->wrapped_item_id )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_WRAPPED_CANT_BE_WRAPPED );
		return;
	}

	if( dst->GetProto()->Unique )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_UNIQUE_CANT_BE_WRAPPED );
		return;
	}

	if( dst->IsContainer() )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_BAGS_CANT_BE_WRAPPED );
		return;
	}

	if( dst->HasEnchantments() )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_ITEM_LOCKED );
		return;
	}
	if( destitem_bagslot == (int8)0xFF && ( destitem_slot >= EQUIPMENT_SLOT_START && destitem_slot <= INVENTORY_SLOT_BAG_END ) )
	{
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_EQUIPPED_CANT_BE_WRAPPED );
		return;
	}

	// all checks passed ok
	source_entry = src->GetEntry();
	itemid = source_entry;
	switch( source_entry )
	{
	case 5042:
		itemid = 5043;
		break;

	case 5048:
		itemid = 5044;
		break;

	case 17303:
		itemid = 17302;
		break;

	case 17304:
		itemid = 17305;
		break;

	case 17307:
		itemid = 17308;
		break;

	case 21830:
		itemid = 21831;
		break;

	default:
		_player->GetItemInterface()->BuildInventoryChangeError( src, dst, INV_ERR_WRAPPED_CANT_BE_WRAPPED );
		return;
		break;
	}

	dst->SetProto( src->GetProto() );

	if( src->GetUInt32Value( ITEM_FIELD_STACK_COUNT ) <= 1 )
	{
		// destroy the source item
		_player->GetItemInterface()->SafeFullRemoveItemByGuid( src->GetGUID() );
	}
	else
	{
		// reduce stack count by one
		src->ModUnsigned32Value( ITEM_FIELD_STACK_COUNT, -1 );
		src->m_isDirty = true;
	}

	// change the dest item's entry
	dst->wrapped_item_id = dst->GetEntry();
	dst->SetUInt32Value( OBJECT_FIELD_ENTRY, itemid );

	// set the giftwrapper fields
	dst->SetUInt32Value( ITEM_FIELD_GIFTCREATOR, _player->GetLowGUID() );
	dst->SetUInt32Value( ITEM_FIELD_DURABILITY, 0 );
	dst->SetUInt32Value( ITEM_FIELD_MAXDURABILITY, 0 );
	dst->SetUInt32Value( ITEM_FIELD_FLAGS, 0x8008 );

	// save it
	dst->m_isDirty = true;
	dst->SaveToDB( destitem_bagslot, destitem_slot, false, NULL );
}
