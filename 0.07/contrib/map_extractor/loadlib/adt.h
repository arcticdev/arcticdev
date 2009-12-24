/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef ADT_H
#define ADT_H

#include "loadlib.h"

#define TILESIZE (533.33333f)
#define CHUNKSIZE ((TILESIZE) / 16.0f)
#define UNITSIZE (CHUNKSIZE / 8.0f)

enum LiquidType
{
    LIQUID_TYPE_WATER = 0,
    LIQUID_TYPE_OCEAN = 1,
    LIQUID_TYPE_MAGMA = 2,
    LIQUID_TYPE_SLIME = 3
};


//
// Adt file convertor function and data
//

// Map file format data
#define MAP_MAGIC             'SPAM'
#define MAP_VERSION_MAGIC     '0.1w'
#define MAP_AREA_MAGIC        'AERA'
#define MAP_HEIGTH_MAGIC      'TGHM'
#define MAP_LIQUID_MAGIC      'QILM'

struct map_fileheader{
    uint32 mapMagic;
    uint32 versionMagic;
    uint32 areaMapOffset;
    uint32 areaMapSize;
    uint32 heightMapOffset;
    uint32 heightMapSize;
    uint32 liquidMapOffset;
    uint32 liquidMapSize;
};

#define MAP_AREA_NO_AREA      0x0001
struct map_areaHeader{
    uint32 fourcc;
    uint16 flags;
    uint16 gridArea;
};

#define MAP_HEIGHT_NO_HIGHT   0x0001
#define MAP_HEIGHT_AS_INT16   0x0002
#define MAP_HEIGHT_AS_INT8    0x0004

struct map_heightHeader{
    uint32 fourcc;
    uint32 flags;
    float  gridHeight;
    float  gridMaxHeight;
};




#define MAP_LIQUID_NO_TYPE    0x0001
#define MAP_LIQUID_NO_HIGHT   0x0002

struct map_liquidHeader{
    uint32 fourcc;
    uint16 flags;
    uint16 liquidType;
    uint8  offsetX;
    uint8  offsetY;
    uint8  width;
    uint8  height;
    float  liquidLevel;
};

//**************************************************************************************
// ADT file class
//**************************************************************************************
#define ADT_CELLS_PER_GRID    16
#define ADT_CELL_SIZE         8
#define ADT_GRID_SIZE         (ADT_CELLS_PER_GRID*ADT_CELL_SIZE)

//
// Adt file height map chunk
//
class adt_MCVT
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
public:
    float height_map[(ADT_CELL_SIZE+1)*(ADT_CELL_SIZE+1)+ADT_CELL_SIZE*ADT_CELL_SIZE];

    bool  prepareLoadedData();
};

//
// Adt file liquid map chunk (old)
//
class adt_MCLQ
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
public:
    float height1;
    float height2;
    struct liquid_data{
        uint32 light;
        float  height;
    } liquid[ADT_CELL_SIZE+1][ADT_CELL_SIZE+1];
    
    // 1<<0 - ochen
    // 1<<1 - lava/slime
    // 1<<2 - water
    // 1<<6 - all water
    // 1<<7 - dark water
    // == 0x0F - not show liquid
    uint8 flags[ADT_CELL_SIZE][ADT_CELL_SIZE];
    uint8 data[84];
    bool  prepareLoadedData();
};

//
// Adt file cell chunk
//
class adt_MCNK
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
public:
    uint32 flags;
    uint32 ix;
    uint32 iy;
    uint32 nLayers;
    uint32 nDoodadRefs;
    uint32 offsMCVT;        // height map
    uint32 offsMCNR;        // Normal vectors for each vertex
    uint32 offsMCLY;        // Texture layer definitions
    uint32 offsMCRF;        // A list of indices into the parent file's MDDF chunk
    uint32 offsMCAL;        // Alpha maps for additional texture layers
    uint32 sizeMCAL;
    uint32 offsMCSH;        // Shadow map for static shadows on the terrain
    uint32 sizeMCSH;
    uint32 areaid;
    uint32 nMapObjRefs;
    uint32 holes;
    uint16 s[2];
    uint32 data1;
    uint32 data2;
    uint32 data3;
    uint32 predTex;
    uint32 nEffectDoodad;
    uint32 offsMCSE;
    uint32 nSndEmitters;
    uint32 offsMCLQ;         // Liqid level (old)
    uint32 sizeMCLQ;         //
    float  zpos;
    float  xpos;
    float  ypos;
    uint32 offsMCCV;         // offsColorValues in WotLK
    uint32 props;
    uint32 effectId;

    bool   prepareLoadedData();
    adt_MCVT *getMCVT()
    {
        if (offsMCVT)
            return (adt_MCVT *)((uint8 *)this + offsMCVT);
        return 0;
    }
    adt_MCLQ *getMCLQ()
    {
        if (offsMCLQ)
            return (adt_MCLQ *)((uint8 *)this + offsMCLQ);
        return 0;
    }
};

//
// Adt file grid chunk
//
class adt_MCIN
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
public:
    struct adt_CELLS{
        uint32 offsMCNK;
        uint32 size;
        uint32 flags;
        uint32 asyncId;
    } cells[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];

    bool   prepareLoadedData();
    // offset from begin file (used this-84)
    adt_MCNK *getMCNK(int x, int y)
    {
        if (cells[x][y].offsMCNK)
            return (adt_MCNK *)((uint8 *)this + cells[x][y].offsMCNK - 84);
        return 0;
    }
};

#define ADT_LIQUID_HEADER_FULL_LIGHT   0x01
#define ADT_LIQUID_HEADER_NO_HIGHT     0x02

struct adt_liquid_header{
    uint16 liquidType;             // Index from LiquidType.dbc
    uint16 formatFlags;
    float  heightLevel1;
    float  heightLevel2;
    uint8  xOffset;
    uint8  yOffset;
    uint8  width;
    uint8  height;
    uint32 offsData2a;
    uint32 offsData2b;
};

//
// Adt file liquid data chunk (new)
//
class adt_MH2O
{
public:
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;

    struct adt_LIQUID{
        uint32 offsData1;
        uint32 used;
        uint32 offsData2;
    } liquid[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];

    bool   prepareLoadedData();

    adt_liquid_header *getLiquidData(int x, int y)
    {
        if (liquid[x][y].used && liquid[x][y].offsData1)
            return (adt_liquid_header *)((uint8*)this + 8 + liquid[x][y].offsData1);
        return 0;
    }

    float *getLiquidHeightMap(adt_liquid_header *h) 
    {
        if (h->formatFlags & ADT_LIQUID_HEADER_NO_HIGHT)
            return 0;
        if (h->offsData2b)
            return (float *)((uint8*)this + 8 + h->offsData2b);
        return 0;
    }

    uint8 *getLiquidLightMap(adt_liquid_header *h) 
    {
        if (h->formatFlags&ADT_LIQUID_HEADER_FULL_LIGHT)
            return 0;
        if (h->offsData2b)
        {
            if (h->formatFlags & ADT_LIQUID_HEADER_NO_HIGHT)
                return (uint8 *)((uint8*)this + 8 + h->offsData2b);
            return (uint8 *)((uint8*)this + 8 + h->offsData2b + (h->width+1)*(h->height+1)*4);
        }
        return 0;
    }

    uint32 *getLiquidFullLightMap(adt_liquid_header *h) 
    {
        if (!(h->formatFlags&ADT_LIQUID_HEADER_FULL_LIGHT))
            return 0;
        if (h->offsData2b)
        {
            if (h->formatFlags & ADT_LIQUID_HEADER_NO_HIGHT)
                return (uint32 *)((uint8*)this + 8 + h->offsData2b);
            return (uint32 *)((uint8*)this + 8 + h->offsData2b + (h->width+1)*(h->height+1)*4);
        }
        return 0;
    }

    uint64 getLiquidShowMap(adt_liquid_header *h)   
    {
        if (h->offsData2a)
            return *((uint64 *)((uint8*)this + 8 + h->offsData2a));
        else
            return 0xFFFFFFFFFFFFFFFFLL;
    }

};


//
// Adt wmo chunck
//
class adt_MWMO
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
public:
	uint32 size;

	uint32 pad;
	uint8 *getWMO(uint32 idz){return ((uint8 *)&pad+(idz)) ;}
};

#ifndef MAP_OBJ
#define MAP_OBJ

struct SMMapObjDef // 03-29-2005 By ObscuR
{
uint32 nameId;		
uint32 uniqueId;		
float pos[3];
float rot[3];
float extents[6];
uint32 flags;		
uint32 doodadSet;
uint16 nameSet;
};

#endif

class adt_MODF
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
public:
 
	
	SMMapObjDef data;
	int getCount() { return (size-4)/sizeof(SMMapObjDef);}
};

//
// Adt file header chunk
//
class adt_MHDR
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;

    uint32 pad;
    uint32 offsMCIN;           // MCIN
    uint32 offsTex;	           // MTEX
    uint32 offsModels;	       // MMDX	
    uint32 offsModelsIds;	   // MMID	
    uint32 offsMapObejcts;	   // MWMO	
    uint32 offsMapObejctsIds;  // MWID		
    uint32 offsDoodsDef;       // MDDF	
    uint32 offsObjectsDef;     // MODF
    uint32 offsMFBO;           // MFBO
    uint32 offsMH2O;           // MH2O
    uint32 data1;
    uint32 data2;
    uint32 data3;
    uint32 data4;
    uint32 data5;
public:
    bool prepareLoadedData();
    adt_MCIN *getMCIN(){ return (adt_MCIN *)((uint8 *)&pad+offsMCIN);}
    adt_MH2O *getMH2O(){ return offsMH2O ? (adt_MH2O *)((uint8 *)&pad+offsMH2O) : 0;}
	adt_MWMO *getMWMO(){ return offsMapObejcts ? (adt_MWMO *)((uint8 *)&pad+offsMapObejcts) : 0;}
	adt_MODF *getMODF(){ return offsObjectsDef ? (adt_MODF *)((uint8 *)&pad+offsObjectsDef) : 0;}

};

class ADT_file : public FileLoader{
public:
    bool prepareLoadedData();
    ADT_file();
    ~ADT_file();
    void free();

    adt_MHDR *a_grid;
};

#endif
