/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#define _CRT_SECURE_NO_DEPRECATE

#include "wmoJuicer.h"

#include <math.h>
#include <stdio.h>
#include <string>

bool  wmoJuicer::wmo_MOGP::prepareLoadedData()
{
    if (fcc != 'MOGP')
        return false;
    return true;
}

bool  wmoJuicer::wmo_MOHD::prepareLoadedData()
{
    if (fcc != 'MOHD')
        return false;
    return true;
}

 wmoJuicer::WMO_file::WMO_file()
{
    mogp = 0;
}

 wmoJuicer::WMO_file::~WMO_file()
{
    free();
}

void  wmoJuicer::WMO_file::free()
{
    mogp = 0;
    FileLoader::free();
}

bool  wmoJuicer::WMO_file::prepareLoadedData()
{
  // Check version
    version = (file_MVER *) GetData();
    if (version->fcc != 'MVER')
        return false;
    if (version->ver != 17)
        return false;

	mohd = (wmo_MOHD *)((uint8*)version+version->size+8);
	mogp=(wmo_MOGP *)mohd;
    if (mogp->prepareLoadedData())
		type=group;
	else if (mohd->prepareLoadedData())
		type=root;
	else
        return false;

	if (type==root)
	{
		mogi=(wmo_chunk*)mohd;
		while (mogi->fcc != 'MOGI')
		{
			if (mogi->fcc == 'MOGN')
				mogn=mogi;
			mogi=(wmo_chunk*)((uint8*)mogi+mogi->size+8);
		}
	}
	else if (mogp->hasWater())
	{
		wmo_chunk *w=(wmo_chunk*)((uint8*)mogp+76);
		while (w->fcc != 'MLIQ')
		{
			w=(wmo_chunk*)((uint8*)w+w->size+8);
		}
		mliq=(wmo_MLIQ *)w;
	}
    return true;
}

wmoJuicer::wmoJuicer(const char* outdir)
{
  strcpy( path, outdir); 
}

wmoJuicer::~wmoJuicer()
{

}

void wmoJuicer::squeeze(char* wmo_file, SMMapObjDef* wmo_map, bool global)
{
    WMO_file wmog;
    if (!wmog.loadFile(wmo_file))
        printf("could not load file %s\n", wmo_file);
    else 
    {
        if (wmog.mogp->hasWater())
        {
            wmo_MLIQ* water=wmog.mliq;

            float rad=(wmo_map->rot[1])*3.14592f/180.0f;
            rad=-rad;
            for (uint16 ii=0; ii<= water->xt; ii++)
                for (uint16 jj=0; jj<=  water->yt; jj++)
                {
                    float y=(wmo_map->pos[1])+water->pos[2];
                    //Convert to wmo location to rotate
                    float wmo_x=water->pos[1]+(jj*TILESIZE/ADT_GRID_SIZE);
                    float wmo_y=water->pos[0]+(ii*TILESIZE/ADT_GRID_SIZE);
                    float abs_x=(wmo_map->pos[0]);
                    float abs_y=(wmo_map->pos[2]);
                    //rotate
                    abs_x+=(wmo_x*cos(rad))-(wmo_y*sin(rad));
                    abs_y+=(wmo_y*cos(rad))+(wmo_x*sin(rad));
                    //now find corresponding grid
	                float cx=abs_x*ADT_GRID_SIZE/TILESIZE;
                    float cy=abs_y*ADT_GRID_SIZE/TILESIZE;
					if (global)
					{
						cx+=ADT_GRID_SIZE*(WDT_MAP_SIZE>>1);
						cy+=ADT_GRID_SIZE*(WDT_MAP_SIZE>>1);
					}
                    int gx=(int)(cx/ADT_GRID_SIZE);
                    int gy=(int)(cy/ADT_GRID_SIZE);
                    cx-=gx*ADT_GRID_SIZE;
                    cy-=gy*ADT_GRID_SIZE;
                    if (cx > 0  && cy > 0 && gx<WDT_MAP_SIZE && gy<WDT_MAP_SIZE)  //just a sanity check
                    {
                        if (jj < water->yt && ii < water->xt)
                        {
                    	    uint8 c_flag = water->getLiquidFlags(ii,jj);									
                            if (!(c_flag & 0x08))
                            {
                                ranged_liquid_show[gy][gx][(int)cy][(int)cx] = true;
								if (c_flag&(0x40))
									ranged_liquid_type[gy][gx][(int)(cy/8)][(int)(cx/8)] |= MAP_LIQUID_TYPE_WATER;
								if (c_flag&(0x01))
									ranged_liquid_type[gy][gx][(int)(cy/8)][(int)(cx/8)] |= MAP_LIQUID_TYPE_SLIME;
								if (c_flag&(0x02))
									ranged_liquid_type[gy][gx][(int)(cy/8)][(int)(cx/8)] |= MAP_LIQUID_TYPE_MAGMA;
							}
                        }
						float high=water->getLiquidData(ii,jj)->height+y;
						if (high>ranged_liquid_height[gy][gx][(int)cy][(int)cx])
						{
							ranged_liquid_height[gy][gx][(int)cy][(int)cx] = high;
						}
					}
				}
		}
	}
}
void wmoJuicer::readADT(char *filename, int cell_x, int cell_y)
{
    ADT_file adt;

    if (!adt.loadFile(filename))
        return;

    adt_MCIN *cells = adt.a_grid->getMCIN();
    if (!cells)
    {
        printf("Can't find cells in '%s'\n", filename);
        return;
    }

    //Get Liquid Data from wmos
    adt_MWMO* add=adt.a_grid->getMWMO();	
    char* wmo_root;
    int wmo_idx=0;
    for (uint32 i=0; i<add->size; i+=strlen(wmo_root)+1)
    {
        wmo_root=(char*)(add->getWMO(i));

        WMO_file wmo;
        if (!wmo.loadFile(wmo_root))

            printf("could not load file %s\n", wmo_root);
        else 
        {
            SMMapObjDef* wmo_map=&(adt.a_grid->getMODF()->data);
            for (int j=0; j< adt.a_grid->getMODF()->getCount(); j++)
            {
                if (wmo_map->nameId==wmo_idx)
                    break;
                wmo_map++;
            }
			if (wmo_map->nameId!=wmo_idx)
				continue;
			for (uint32 j=0; j<wmo.mohd->groups; j++)
			{
				char* wmo_fname=new char[256];
				std::string tmps=((std::string)wmo_root).substr(0,strlen(wmo_root)-4);
				sprintf(wmo_fname,"%s_%03i.wmo", tmps.c_str(), j);
				squeeze(wmo_fname, wmo_map, false);
			}
		}
    wmo_idx++;
	}
}

void wmoJuicer::readWDT(WDT_file *wdt)
{
  
    //Get Liquid Data from wmos
    char* wmo_root;
    int wmo_idx=0;
    for (uint32 i=0; i<wdt->wmo->size; i+=strlen(wmo_root)+1)
    {
        wmo_root=(char*)(wdt->wmo->getWMO(i));
        WMO_file wmo;
        if (!wmo.loadFile(wmo_root))

            printf("could not load file %s\n", wmo_root);
        else 
        {
            SMMapObjDef* wmo_map=&(wdt->modf->data);
            for (int j=0; j< wdt->modf->getCount(); j++)
            {
                if (wmo_map->nameId==wmo_idx)
                    break;
                wmo_map++;
            }
			if (wmo_map->nameId!=wmo_idx)
				continue;
			for (uint32 j=0; j<wmo.mohd->groups; j++)
			{
				char* wmo_fname=new char[256];
				std::string tmps=((std::string)wmo_root).substr(0,strlen(wmo_root)-4);
				sprintf(wmo_fname,"%s_%03i.wmo", tmps.c_str(), j);
				squeeze(wmo_fname, wmo_map, true);
			}
		}
    wmo_idx++;
	}
}
void wmoJuicer::Juice(char* map_name, int map_id, WDT_file* wdt)
{
    char mpq_filename[128]=".";
    clearLiquid();
	if (wdt->mphd->data1) //one global WMO
	{
		readWDT(wdt);
		for(int y=0; y < WDT_MAP_SIZE; ++y)
			for(int x=0; x< WDT_MAP_SIZE; ++x)
				saveWDT(map_id ,y,x);
	}
	//else   Someplaces have both
	{
		for(int y = 0; y < WDT_MAP_SIZE; ++y)
		{  
	        
			for(uint32 x = 0; x < WDT_MAP_SIZE; ++x)
			{
				if (wdt->main->adt_list[y][x].exist)
				{
					sprintf(mpq_filename, "World\\Maps\\%s\\%s_%u_%u.adt", map_name, map_name, x, y);
					readADT(mpq_filename, x, y);
				}
			}

			// draw progress bar
			printf("Processing........................%d%%\r", (50 * (y+1)) / WDT_MAP_SIZE);
		}
	}
}


void wmoJuicer::clearLiquid()
{
     memset(ranged_liquid_type, 0, sizeof(uint8)*ADT_CELLS_PER_GRID*ADT_CELLS_PER_GRID*WDT_MAP_SIZE*WDT_MAP_SIZE);
     memset(ranged_liquid_show, 0, sizeof(bool)*ADT_GRID_SIZE*ADT_GRID_SIZE*WDT_MAP_SIZE*WDT_MAP_SIZE);
	 for (int cy=0; cy< WDT_MAP_SIZE; ++cy)
		for (int cx=0; cx< WDT_MAP_SIZE; ++cx)
			for (int y=0; y<= ADT_GRID_SIZE; ++y)
				for (int x=0; x<= ADT_GRID_SIZE; ++x)
					ranged_liquid_height[cy][cx][y][x]=-500.f;	 
}

bool wmoJuicer::getLiquid(int cell_x, int cell_y, uint8* type, bool* show, float* height)
{
     memcpy(type, ranged_liquid_type[cell_y][cell_x], sizeof(uint8)*ADT_CELLS_PER_GRID*ADT_CELLS_PER_GRID);
	 memcpy(show, ranged_liquid_show[cell_y][cell_x], sizeof(bool)*ADT_GRID_SIZE*ADT_GRID_SIZE);
	 memcpy(height, ranged_liquid_height[cell_y][cell_x], sizeof(float)*(ADT_GRID_SIZE+1)*(ADT_GRID_SIZE+1));

     return true;
} 

bool wmoJuicer::saveWDT(int map_id, int cell_y, int cell_x)
{
	// Prepare map header
    map_fileheader map;
    map.mapMagic = MAP_MAGIC;
    map.versionMagic = MAP_VERSION_MAGIC;

	//============================================
    // Pack liquid data
    //============================================
    uint8 type = ranged_liquid_type[cell_y][cell_x][0][0];
    bool fullType = false;
    for (int y=0;y<ADT_CELLS_PER_GRID;y++)
    {
        for(int x=0;x<ADT_CELLS_PER_GRID;x++)
        {
            if (ranged_liquid_type[cell_y][cell_x][y][x]!=type)
            {
                fullType = true;
                y = ADT_CELLS_PER_GRID;
                break;
            }
        }
    }

	// no water data (if all grid have 0 liquid type)
    if (type == 0 && !fullType)
    {
        return false;
    }

    float maxHeight = -20000;
    float minHeight =  20000;

	map.areaMapOffset = sizeof(map);
    map.areaMapSize   = sizeof(map_areaHeader);

    map_areaHeader areaHeader;
    areaHeader.fourcc = MAP_AREA_MAGIC;
    areaHeader.flags = 0;
    areaHeader.flags = MAP_AREA_NO_AREA;
    areaHeader.gridArea = 0;

	map.heightMapOffset = map.areaMapOffset + map.areaMapSize;
    map.heightMapSize = sizeof(map_heightHeader);

    map_heightHeader heightHeader;
    heightHeader.fourcc = MAP_HEIGTH_MAGIC;
    heightHeader.flags = 0;
    heightHeader.gridHeight    = maxHeight;
    heightHeader.gridMaxHeight = maxHeight;
    heightHeader.flags |=MAP_HEIGHT_NO_HIGHT;
 
	map_liquidHeader liquidHeader;

	maxHeight = -20000;
    minHeight =  20000;
    int minX = 255, minY = 255;
    int maxX = 0, maxY = 0;
    for (int y=0; y<ADT_GRID_SIZE; y++)
    {
        for(int x=0; x<ADT_GRID_SIZE; x++)
        {
            if (ranged_liquid_show[cell_y][cell_x][y][x])
            {
                if (minX > x) minX = x;
                if (maxX < x) maxX = x;
                if (minY > y) minY = y;
                if (maxY < y) maxY = y;
                float h = ranged_liquid_height[cell_y][cell_x][y][x];
                if (maxHeight < h) maxHeight = h;
                if (minHeight > h) minHeight = h;
            }
            else
                ranged_liquid_height[cell_y][cell_x][y][x] = -500.0f;
        }
    }
    map.liquidMapOffset = map.heightMapOffset + map.heightMapSize;
    map.liquidMapSize = sizeof(map_liquidHeader);
    liquidHeader.fourcc = MAP_LIQUID_MAGIC;
    liquidHeader.flags = 0;
    liquidHeader.liquidType = 0;
    liquidHeader.offsetX = minX;
    liquidHeader.offsetY = minY;
    liquidHeader.width   = maxX - minX + 1;
    liquidHeader.height  = maxY - minY + 1;
    liquidHeader.liquidLevel = minHeight;

    if (maxHeight == minHeight)
        liquidHeader.flags|=MAP_LIQUID_NO_HIGHT;

    // Not need store if flat surface
    if ((maxHeight - minHeight) < 0.001f)
        liquidHeader.flags|=MAP_LIQUID_NO_HIGHT;

    if (!fullType)
        liquidHeader.flags|=MAP_LIQUID_NO_TYPE;

    if (liquidHeader.flags&MAP_LIQUID_NO_TYPE)
        liquidHeader.liquidType = type;
    else
        map.liquidMapSize+=sizeof(ranged_liquid_type[cell_y][cell_x]);
 
    if (!(liquidHeader.flags&MAP_LIQUID_NO_HIGHT))
        map.liquidMapSize+=sizeof(float)*liquidHeader.width*liquidHeader.height;

	char filename[1024];
	sprintf(filename, "%s/%03u%02u%02u.map", path, map_id, cell_y, cell_x);
                

    // Ok all data prepared - store it
    FILE *output=fopen(filename, "wb");
    if(!output)
    {
        printf("Can't create the output file '%s'\n", filename);
        return false;
    }
    fwrite(&map, sizeof(map), 1, output);
    // Store area data
    fwrite(&areaHeader, sizeof(areaHeader), 1, output);
    // Store height data
    fwrite(&heightHeader, sizeof(heightHeader), 1, output);
    // Store liquid data if need
    if (map.liquidMapOffset)
    {
        fwrite(&liquidHeader, sizeof(liquidHeader), 1, output);
        if (!(liquidHeader.flags&MAP_LIQUID_NO_TYPE))
            fwrite(ranged_liquid_type[cell_y][cell_x], sizeof(ranged_liquid_type[cell_y][cell_x]), 1, output);
        if (!(liquidHeader.flags&MAP_LIQUID_NO_HIGHT))
        {
            for (int y=0; y<liquidHeader.height;y++)
                fwrite(&ranged_liquid_height[cell_y][cell_x][y+liquidHeader.offsetY][liquidHeader.offsetX], sizeof(float), liquidHeader.width, output);
        }
    }
    fclose(output);
	return true;
}