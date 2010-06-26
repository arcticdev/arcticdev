/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef WOWSERVER_DYNAMICOBJECT_H
#define WOWSERVER_DYNAMICOBJECT_H

struct SpellEntry;

typedef unordered_set<UnitPointer >  DynamicObjectList;
typedef unordered_set<UnitPointer >  FactionRangeList;

class SERVER_DECL DynamicObject : public Object
{
public:
	DynamicObject( uint32 high, uint32 low );
	~DynamicObject( );

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	virtual void Destructor();
	virtual void Init();

	void Create(ObjectPointer caster, SpellPointer pSpell, float x, float y, float z, uint32 duration, float radius);
	void UpdateTargets();

	void AddInRangeObject(ObjectPointer pObj);
	void OnRemoveInRangeObject(ObjectPointer pObj);
	void Remove();

	// Accessors
	void SetAliveDuration(uint32 dur){m_aliveDuration = dur;};

protected:
	
	SpellEntry * m_spellProto;
	UnitPointer u_caster;
	PlayerPointer p_caster;
	ObjectPointer m_caster;
	GameObjectPointer g_caster;
	SpellPointer m_parentSpell;
	DynamicObjectList targets;
	
	uint32 m_aliveDuration;
	uint32 _fields[DYNAMICOBJECT_END];
	FactionRangeList  m_inRangeOppFactions;
};

#endif

