/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef WINTERGRASP_H
#define WINTERGRASP_H

#define WARCTIC_WINTERGRASP 4197
#define A_NUMVEH_WORLDSTATE 3680
#define A_MAXVEH_WORLDSTATE 3681
#define H_NUMVEH_WORLDSTATE 3490
#define H_MAXVEH_WORLDSTATE 3491

// Fatty array time.
/*const uint32 CreatureEntryPair[][2] =
{
    {32307, 32308}, // Guards
    {30739, 30740}, // Champions
    {31101, 31051}, // Hoodoo Master & Sorceress
    {31102, 31052}, // Vieron Blazefeather & Bowyer
    {32296, 32294}, // Quartermaster
    {31107, 31109}, // Lieutenant & Senior Demolitionist
    {31151, 31153}, // Tactical Officer
    {31106, 31108}, // Siegesmith & Siege Master
    {31053, 31054}, // Primalist & Anchorite
    {31091, 31036}, // Commander
    {32615, 32626}, // Warbringer & Brigadier General
    {0,0}
};*/

const uint32 ClockWorldState[5] = { 3785, 3784, 3782, 3976, 3975};

typedef std::set<Creature*> CreatureSwapSet;
typedef std::set<Player*> WintergraspPlayerSet;

class Wintergrasp
{
public:
	Wintergrasp(WintergraspInternal* WGI, MapMgr* mgr);
	~Wintergrasp();
	virtual void Init();

	static Wintergrasp* Create( WintergraspInternal* i, MapMgr* m) { return new Wintergrasp(i, m); }
	WintergraspPlayerSet WGPlayers;
	CreatureSwapSet WGCreatures;
	uint32 GetNumVehicles(uint32 team) { if(team > 1) return 0; return numvehicles[team]; };
	uint32 GetNumWorkshops(uint32 team) { if(team > 1) return 0; return numworkshop[team]; };

private:
	WintergraspInternal Internal;

	// Counts
	uint32 playercount[3];

	// Buildings

	// Vehicles
	uint32 numvehicles[2];

	// Workshops
	uint32 numworkshop[2];
};

#endif // WINTERGRASP_H
