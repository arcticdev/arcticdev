/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef WMOJUICER_H
#define WMOJUICER_H

#include "loadlib/loadlib.h"
#include "loadlib/adt.h"
#include "loadlib/wdt.h"

#define MAP_LIQUID_TYPE_NO_WATER    0x00
#define MAP_LIQUID_TYPE_WATER       0x01
#define MAP_LIQUID_TYPE_OCEAN       0x02
#define MAP_LIQUID_TYPE_MAGMA       0x04
#define MAP_LIQUID_TYPE_SLIME       0x08

#define MAP_LIQUID_TYPE_DARK_WATER  0x10
#define MAP_LIQUID_TYPE_WMO_WATER   0x20

#define BLOCK (ADT_CELLS_PER_GRID * ADT_CELLS_PER_GRID) + (ADT_GRID_SIZE * ADT_GRID_SIZE) + (4 * (ADT_GRID_SIZE+1)*(ADT_GRID_SIZE+1))

class wmoJuicer{
public:
    class wmo_chunk{
    public:
	union{
            uint32 fcc;
            char   fcc_txt[4];
        };
	uint32 size;
	uint32 pad;
    };

    struct liquid_data{
        uint16 light;
	uint16 right;
        float  height;
    };

    class wmo_MLIQ{
	union{
            uint32 fcc;
            char   fcc_txt[4];
        };
    public:
        uint32 size;
	uint32 xv;
	uint32 yv;
	uint32 xt;
	uint32 yt;
	float pos[3];
	uint16 matID;
	uint32 data;
	liquid_data* getLiquidData(int x, int y) {return (liquid_data*)((uint8 *)&data+(y*xv+x)*sizeof(liquid_data));}
	uint8 getLiquidFlags(int x, int y){ return ((uint8 *)&data+(yv*xv)*sizeof(liquid_data))[y*xt+x];}
    };

    class wmo_MOGP
	{
        union{
            uint32 fcc;
            char   fcc_txt[4];
        };
    public:
        uint32 size;
	uint32 groupName;
	uint32 descName;
	uint32 flags;
	uint32 pad;
	bool   prepareLoadedData();
	bool hasWater(){ return flags & 0x1000;}
	wmo_chunk* getName(){ return (wmo_chunk*)((uint8 *)&pad+groupName);}
	wmo_chunk* getDesc(){ return (wmo_chunk*)((uint8 *)&pad+descName);}

	};

    class wmo_MOHD{
        union{
            uint32 fcc;
            char   fcc_txt[4];
        };
    public:
        uint32 size;
	uint32 mats;
	uint32 groups;
	uint32 portals;
	uint32 pad;
	bool   prepareLoadedData();
    };

    struct group_entry
    {
	uint32 flags;
	float bb1[3];
	float bb2[3];
	uint32 nameoffs;
    };

    class WMO_file : public FileLoader{
    public:
        bool   prepareLoadedData();

        WMO_file();
        ~WMO_file();
        void free();
	
	union{
            wmo_MOGP *mogp;
	    wmo_MOHD *mohd;
	};

	wmo_chunk *mogi;
	wmo_chunk *mogn;
	wmo_MLIQ *mliq;

	enum wmo_type{
		root,
		group
	};

	wmo_type type;
    };
    
    wmoJuicer(const char* outdir);
    ~wmoJuicer();

    void Juice(char* map_name, int map_id, WDT_file* wdt);
    bool getLiquid(int cell_x, int cell_y, uint8* type, bool* show, float* height);

private:
    void readADT(char *filename, int cell_y, int cell_x);
	void readWDT(WDT_file* wdt);
	bool saveWDT(int map_id, int cell_y, int cell_x);

	void squeeze(char *wmo_file, SMMapObjDef* wmo_map, bool global); 
    
    void clearLiquid();

    uint8 ranged_liquid_type[WDT_MAP_SIZE][WDT_MAP_SIZE][ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];
    bool  ranged_liquid_show[WDT_MAP_SIZE][WDT_MAP_SIZE][ADT_GRID_SIZE][ADT_GRID_SIZE];
    float ranged_liquid_height[WDT_MAP_SIZE][WDT_MAP_SIZE][ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];
    char path[128];
    char filepath[128];


};


#endif
