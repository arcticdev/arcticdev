/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

// Class used to link multiple monsters together for agro.
class SERVER_DECL ChainAggroEntity
{
	friend class AIInterface;

private:
	set<Creature*> m_agroEntitySet;
public:
	ChainAggroEntity(Creature* pOwner);
	~ChainAggroEntity();

	static ChainAggroEntity* Create(Creature* pCreature) { return new ChainAggroEntity(pCreature); }

	void AddAggroEntity(Creature* pCreature);
	void RemoveAggroEntity(Creature* pCreature);

	void Delete();

	void EventEnterCombat(Unit* pTarget);
};
