/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "Config.h"

#ifndef _SHARED_PTR_H
#define _SHARED_PTR_H

#ifdef SHARED_PTR_MODE_ON

// Meh
class CBattleground;
class CBattlegroundManager;
class AlteracValley;
class ArathiBasin;
class Arena;
class Aura;
class Container;
class Corpse;
class Creature;
class DynamicObject;
class EventableObject;
class EyeOfTheStorm;
class GameObject;
class Item;
class LootRoll;
class MapMgr;
class Object;
class Pet;
class Player;
class QuestMgr;
class Spell;
class Transporter;
class Unit;
class Vehicle;
class WarsongGulch;
class WeatherInfo;
class World;
class StrandOfTheAncients;
class IslesOfConquest;

// Typedefs for readable code
typedef shared_ptr<CBattleground> BattlegroundPointer;
typedef shared_ptr<CBattlegroundManager> BattlegroundMgrPointer;
typedef shared_ptr<AlteracValley> AlteracValleyPointer;
typedef shared_ptr<ArathiBasin> ArathiBasinPointer;
typedef shared_ptr<Arena> ArenaPointer;
typedef shared_ptr<Aura> AuraPointer;
typedef shared_ptr<CBattleground> CBattlegroundPointer;
typedef shared_ptr<CBattlegroundManager> CBattlegroundManagerPointer;
typedef shared_ptr<Container> ContainerPointer;
typedef shared_ptr<Corpse> CorpsePointer;
typedef shared_ptr<Creature> CreaturePointer;
typedef shared_ptr<DynamicObject> DynamicObjectPointer;
typedef shared_ptr<EventableObject> EventableObjectPointer;
typedef shared_ptr<EyeOfTheStorm> EyeOfTheStormPointer;
typedef shared_ptr<GameObject> GameObjectPointer;
typedef shared_ptr<Item> ItemPointer;
typedef shared_ptr<LootRoll> LootRollPointer;
typedef shared_ptr<MapMgr> MapMgrPointer;
typedef shared_ptr<Object> ObjectPointer;
typedef shared_ptr<Pet> PetPointer;
typedef shared_ptr<Player> PlayerPointer;
typedef shared_ptr<QuestMgr> QuestMgrPointer;
typedef shared_ptr<Spell> SpellPointer;
typedef shared_ptr<Transporter> TransporterPointer;
typedef shared_ptr<Unit> UnitPointer;
typedef shared_ptr<Vehicle> VehiclePointer;
typedef shared_ptr<WarsongGulch> WarsongGulchPointer;
typedef shared_ptr<WeatherInfo> WeatherInfoPointer;
typedef shared_ptr<World> WorldPointer;
typedef shared_ptr<IslesOfConquest> IslesOfConquestPointer;

#define CAST(x,y) std::tr1::static_pointer_cast<x>(y)

#define TO_PLAYER(ptr) CAST(Player,ptr)
#define TO_UNIT(ptr) CAST(Unit,ptr)
#define TO_CREATURE(ptr) CAST(Creature,ptr)
#define TO_PET(ptr) CAST(Pet,ptr)
#define TO_CONTAINER(ptr) CAST(Container,ptr)
#define TO_ITEM(ptr) CAST(Item,ptr)
#define TO_OBJECT(ptr) CAST(Object,ptr)
#define TO_GAMEOBJECT(ptr) CAST(GameObject,ptr)
#define TO_DYNAMICOBJECT(ptr) CAST(DynamicObject,ptr)
#define TO_CORPSE(ptr) CAST(Corpse,ptr)
#define TO_EVENTABLEOBJECT(ptr) CAST(EventableObject,ptr)
#define TO_CBATTLEGROUND(ptr) CAST(CBattleground,ptr)
#define TO_CBATTLEGROUNDMGR(ptr) CAST(CBattlegroundManager,ptr)
#define TO_ALTERACVALLEY(ptr) CAST(AlteracValley,ptr)
#define TO_EYEOFTHESTORM(ptr) CAST(EyeOfTheStorm,ptr)
#define TO_WARSONGGULCH(ptr) CAST(WarsongGulch,ptr)
#define TO_SOTA(ptr) CAST(StrandOfTheAncients,ptr)
#define TO_ARENA(ptr) CAST(Arena,ptr)
#define TO_ARATHIBASIN(ptr) CAST(ArathiBasin,ptr)
#define TO_TRANSPORT(ptr) CAST(Transporter,ptr)
#define TO_AURA(ptr) CAST(Aura,ptr)
#define TO_SPELL(ptr) CAST(Spell,ptr)
#define TO_LOOTROLL(ptr) CAST(LootRoll,ptr)
#define TO_VEHICLE(ptr) CAST(Vehicle,ptr)
#define TO_PTR(classname, ptr) CAST(classname,ptr)
#define TO_ISLESOFCONQUEST(ptr) CAST(IslesOfConquest,ptr)

#define NULLPTR shared_ptr<void>()
#define NULLGOB shared_ptr<GameObject>()
#define NULLPLR shared_ptr<Player>()
#define NULLOBJ shared_ptr<Object>()
#define NULLUNIT shared_ptr<Unit>()
#define NULLPET shared_ptr<Pet>()
#define NULLITEM shared_ptr<Item>()
#define NULLDYN shared_ptr<DynamicObject>()
#define NULLCREATURE shared_ptr<Creature>()
#define NULLVEHICLE shared_ptr<Vehicle>()
#define NULLCORPSE shared_ptr<Corpse>()
#define NULLTRANSPORT shared_ptr<Transporter>()
#define NULLEVENTABLEOBJECT shared_ptr<EventableObject>()
#define NULLCONTAINER shared_ptr<Container>()
#define NULLMAPMGR shared_ptr<MapMgr>()
#define NULLBGMGR shared_ptr<CBattlegroundManager>()
#define NULLBATTLEGROUND shared_ptr<CBattleground>()
#define NULLWEATHER shared_ptr<WeatherInfo>()
#define NULLWORLD shared_ptr<World>()
#define NULLINSTANCEMGR shared_ptr<InstanceMgr>()
#define NULLAURA shared_ptr<Aura>()
#define NULLROLL shared_ptr<LootRoll>()
#define NULLMAPMGR shared_ptr<MapMgr>()
#define NULLSPELL shared_ptr<Spell>()
#define NULLMISC(class_name) shared_ptr<class_name>()

#define object_shared_from_this() TO_OBJECT(shared_from_this())
#define obj_shared_from_this() TO_OBJECT(shared_from_this())
#define gob_shared_from_this() TO_GAMEOBJECT(shared_from_this())
#define unit_shared_from_this() TO_UNIT(shared_from_this())
#define plr_shared_from_this() TO_PLAYER(shared_from_this())
#define player_shared_from_this() TO_PLAYER(shared_from_this())
#define dyn_shared_from_this() TO_DYNAMICOBJECT(shared_from_this())
#define item_shared_from_this() TO_ITEM(shared_from_this())
#define creature_shared_from_this() TO_CREATURE(shared_from_this())
#define pet_shared_from_this() TO_PET(shared_from_this())
#define spell_shared_from_this() TO_SPELL(shared_from_this())
#define aura_shared_from_this() TO_AURA(shared_from_this())
#define lootroll_shared_from_this() TO_LOOTROLL(shared_from_this())
#define vehicle_shared_from_this() TO_VEHICLE(shared_from_this())
#define class_shared_from_this(x) TO_PTR(x, shared_from_this())

#else

// Meh
class CBattleground;
class CBattlegroundManager;
class AlteracValley;
class ArathiBasin;
class Arena;
class Aura;
class Container;
class Corpse;
class Creature;
class DynamicObject;
class EventableObject;
class EyeOfTheStorm;
class GameObject;
class Item;
class LootRoll;
class MapMgr;
class Object;
class Pet;
class Player;
class QuestMgr;
class Spell;
class Transporter;
class Unit;
class Vehicle;
class WarsongGulch;
class WeatherInfo;
class World;
class StrandOfTheAncients;
class IslesOfConquest;

// Typedefs for readable code
#define BattlegroundPointer CBattleground*;
#define BattlegroundMgrPointer CBattlegroundManager*;
#define AlteracValleyPointer AlteracValley*;
#define ArathiBasinPointer ArathiBasin*;
#define ArenaPointer Arena*;
#define AuraPointer Aura*;
#define CBattlegroundPointer CBattleground*;
#define CBattlegroundManagerPointer CBattlegroundManager*;
#define ContainerPointer Container*;
#define CorpsePointer Corpse*;
#define CreaturePointer Creature*;
#define DynamicObjectPointer DynamicObject*;
#define EventableObjectPointer EventableObject*;
#define EyeOfTheStormPointer EyeOfTheStorm*;
#define GameObjectPointer GameObject*;
#define ItemPointer Item*;
#define LootRollPointer LootRoll*;
#define MapMgrPointer MapMgr*;
#define ObjectPointer Object*;
#define PetPointer Pet*;
#define PlayerPointer Player*;
#define QuestMgrPointer QuestMgr*;
#define SpellPointer Spell*;
#define TransporterPointer Transporter*;
#define UnitPointer Unit*;
#define VehiclePointer Vehicle*;
#define WarsongGulchPointer WarsongGulch*;
#define WeatherInfoPointer WeatherInfo*;
#define WorldPointer World*;
#define IslesOfConquestPointer IslesOfConquest*;

#define CAST(x,y) static_cast<x>(y)

#define TO_PLAYER(ptr) CAST(Player*,ptr)
#define TO_UNIT(ptr) CAST(Unit*,ptr)
#define TO_CREATURE(ptr) CAST(Creature*,ptr)
#define TO_PET(ptr) CAST(Pet*,ptr)
#define TO_CONTAINER(ptr) CAST(Container*,ptr)
#define TO_ITEM(ptr) CAST(Item*,ptr)
#define TO_OBJECT(ptr) CAST(Object*,ptr)
#define TO_GAMEOBJECT(ptr) CAST(GameObject*,ptr)
#define TO_DYNAMICOBJECT(ptr) CAST(DynamicObject*,ptr)
#define TO_CORPSE(ptr) CAST(Corpse*,ptr)
#define TO_EVENTABLEOBJECT(ptr) CAST(EventableObject*,ptr)
#define TO_CBATTLEGROUND(ptr) CAST(CBattleground*,ptr)
#define TO_CBATTLEGROUNDMGR(ptr) CAST(CBattlegroundManager*,ptr)
#define TO_ALTERACVALLEY(ptr) CAST(AlteracValley*,ptr)
#define TO_EYEOFTHESTORM(ptr) CAST(EyeOfTheStorm*,ptr)
#define TO_WARSONGGULCH(ptr) CAST(WarsongGulch*,ptr)
#define TO_SOTA(ptr) CAST(StrandOfTheAncients*,ptr)
#define TO_ARENA(ptr) CAST(Arena*,ptr)
#define TO_ARATHIBASIN(ptr) CAST(ArathiBasin*,ptr)
#define TO_TRANSPORT(ptr) CAST(Transporter*,ptr)
#define TO_AURA(ptr) CAST(Aura*,ptr)
#define TO_SPELL(ptr) CAST(Spell*,ptr)
#define TO_LOOTROLL(ptr) CAST(LootRoll*,ptr)
#define TO_VEHICLE(ptr) CAST(Vehicle*,ptr)
#define TO_PTR(classname, ptr) CAST(classname*,ptr)
#define TO_ISLESOFCONQUEST(ptr) CAST(IslesOfConquest*,ptr)

#define NULLPTR NULL
#define NULLGOB NULL
#define NULLPLR NULL
#define NULLOBJ NULL
#define NULLUNIT NULL
#define NULLPET NULL
#define NULLITEM NULL
#define NULLDYN NULL
#define NULLCREATURE NULL
#define NULLVEHICLE NULL
#define NULLCORPSE NULL
#define NULLTRANSPORT NULL
#define NULLEVENTABLEOBJECT NULL
#define NULLCONTAINER NULL
#define NULLMAPMGR NULL
#define NULLBGMGR NULL
#define NULLBATTLEGROUND NULL
#define NULLWEATHER NULL
#define NULLWORLD NULL
#define NULLINSTANCEMGR NULL
#define NULLAURA NULL
#define NULLROLL NULL
#define NULLMAPMGR NULL
#define NULLSPELL NULL
#define NULLMISC(class_name) NULL

#define object_shared_from_this() TO_OBJECT(this)
#define obj_shared_from_this() TO_OBJECT(this)
#define gob_shared_from_this() TO_GAMEOBJECT(this)
#define unit_shared_from_this() TO_UNIT(this)
#define plr_shared_from_this() TO_PLAYER(this)
#define player_shared_from_this() TO_PLAYER(this)
#define dyn_shared_from_this() TO_DYNAMICOBJECT(this)
#define item_shared_from_this() TO_ITEM(this)
#define creature_shared_from_this() TO_CREATURE(this)
#define pet_shared_from_this() TO_PET(this)
#define spell_shared_from_this() TO_SPELL(this)
#define aura_shared_from_this() TO_AURA(this)
#define lootroll_shared_from_this() TO_LOOTROLL(this)
#define vehicle_shared_from_this() TO_VEHICLE(this)
#define class_shared_from_this(x) TO_PTR(x, this)

#endif
#endif
