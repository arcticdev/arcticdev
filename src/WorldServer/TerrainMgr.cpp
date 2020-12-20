/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include <fcntl.h>
#include "TerrainMgr.h"

TerrainMgr::TerrainMgr(string MapPath, uint32 MapId, bool Instanced) : mapPath(MapPath), mapId(MapId), Instance(Instanced)
{
	FileDescriptor = NULL;
	CellInformation = NULL;
}

TerrainMgr::~TerrainMgr()
{
	if(FileDescriptor)
	{
		// Free up our file pointer.
		mutex.Acquire();
		fclose(FileDescriptor);
		mutex.Release();
		FileDescriptor = NULL;
	}

	// Big memory cleanup, whee.
	if(CellInformation)
	{
		for(uint32 x = 0; x < _sizeX; ++x)
		{
			for(uint32 y = 0; y < _sizeY; ++y)
			{
				if(CellInformation[x][y] != 0)
					delete CellInformation[x][y];
			}
			delete [] CellInformation[x];
		}
		delete [] CellInformation;
		CellInformation = NULL;
	}
}

bool TerrainMgr::LoadTerrainHeader()
{
	// Create the path
	char File[200];

	snprintf(File, 200, "%s/Map_%u.bin", mapPath.c_str(), (unsigned int)mapId);

	FileDescriptor = fopen(File, "rb");
	if(FileDescriptor == 0)
		//Log.Error("TerrainMgr", "Map load failed for %s. Missing file?", File);
		return false;

	/* check file size */
	fseek(FileDescriptor, 0, SEEK_END);
	if(ftell(FileDescriptor) == 1048576)
	{
		/* file with no data */
		fclose(FileDescriptor);
		FileDescriptor = NULL;
		return false;
	}

	// Read in the header.
	fseek(FileDescriptor,0,SEEK_SET);
	size_t dread = fread(CellOffsets, 1, TERRAIN_HEADER_SIZE, FileDescriptor);
	if(dread != TERRAIN_HEADER_SIZE)
	{
		fclose(FileDescriptor);
		FileDescriptor = NULL;
		return false;
	}

	// Allocate both storage arrays.
	CellInformation = new CellTerrainInformation**[_sizeX];
	for(uint32 x = 0; x < _sizeX; ++x)
	{
		CellInformation[x] = new CellTerrainInformation*[_sizeY];
		for(uint32 y = 0; y < _sizeY; ++y)
		{
			// Clear the pointer.
			CellInformation[x][y] = 0;
		}
	}

	return true;
}

bool TerrainMgr::LoadCellInformation(uint32 x, uint32 y)
{
	if(!FileDescriptor)
		return false;

	// Make sure that we're not already loaded.
	assert(CellInformation[x][y] == 0);

	// Find our offset in our cached header.
	uint32 Offset = CellOffsets[x][y];

	// If our offset = 0, it means we don't have cell information for
	// these coords.
	if(Offset == 0)
		return false;

	// Lock the mutex to prevent double reading.
	mutex.Acquire();

	// Check that we haven't been loaded by another thread.
	if(CellInformation[x][y] != 0)
	{
		mutex.Release();
		return true;
	}

	// Seek to our specified offset.
	if(fseek(FileDescriptor, Offset, SEEK_SET) == 0)
	{
		// Allocate the cell information.
		CellInformation[x][y] = new CellTerrainInformation;

		// Read from our file into this newly created struct.
		fread(CellInformation[x][y], sizeof(CellTerrainInformation), 1, FileDescriptor);
	}
	// Release the mutex.
	mutex.Release();

	// If we don't equal 0, it means the load was successful.
	if(CellInformation[x][y] != 0)
		return true;
	else
		return false;
}

bool TerrainMgr::UnloadCellInformation(uint32 x, uint32 y)
{
	uint32 Start = getMSTime();

	assert(!Instance);
	// Find our information pointer.
	CellTerrainInformation * ptr = CellInformation[x][y];
	assert(ptr != 0);

	// Set the spot to unloaded (null).
	CellInformation[x][y] = 0;

	// Free the memory.
	delete ptr;

	DEBUG_LOG("TerrainMgr","Unloaded cell information for cell [%u][%u] in %ums.", x, y, getMSTime() - Start);
	// Success
	return true;
}

uint8 TerrainMgr::GetWaterType(float x, float y)
{
	if(!AreCoordinatesValid(x, y))
		return 0;

	// Convert the co-ordinates to cells.
	uint32 CellX = ConvertGlobalXCoordinate(x);
	uint32 CellY = ConvertGlobalYCoordinate(y);

	if(!CellInformationLoaded(CellX, CellY))
		return 0;

	// Convert the co-ordinates to cell's internal
	// system.
	float IntX = ConvertInternalXCoordinate(x, CellX);
	float IntY = ConvertInternalYCoordinate(y, CellY);

	// Find the offset in the 2d array.
	return GetCellInformation(CellX, CellY)->LiquidType[ConvertTo2dArray(IntX)][ConvertTo2dArray(IntY)];
}

float TerrainMgr::GetWaterHeight(float x, float y)
{
	if(!AreCoordinatesValid(x, y))
		return 0.0f;

	// Convert the co-ordinates to cells.
	uint32 CellX = ConvertGlobalXCoordinate(x);
	uint32 CellY = ConvertGlobalYCoordinate(y);

	if(!CellInformationLoaded(CellX, CellY))
		return 0.0f;

	// Convert the co-ordinates to cell's internal
	// system.
	float IntX = ConvertInternalXCoordinate(x, CellX);
	float IntY = ConvertInternalYCoordinate(y, CellY);

	// Find the offset in the 2d array.
	return GetCellInformation(CellX, CellY)->LiquidLevel[ConvertTo2dArray(IntX)][ConvertTo2dArray(IntY)];
}

uint8 TerrainMgr::GetWalkableState(float x, float y)
{
	// This has to be implemented.
	return 1;
}

uint16 TerrainMgr::GetAreaID(float x, float y)
{
	if(!AreCoordinatesValid(x, y))
		return 0;

	// Convert the co-ordinates to cells.
	uint32 CellX = ConvertGlobalXCoordinate(x);
	uint32 CellY = ConvertGlobalYCoordinate(y);

	if(!CellInformationLoaded(CellX, CellY) && !LoadCellInformation(CellX, CellY))
		return 0;

	// Convert the co-ordinates to cell's internal
	// system.
	float IntX = ConvertInternalXCoordinate(x, CellX);
	float IntY = ConvertInternalYCoordinate(y, CellY);

	// Find the offset in the 2d array.
	return GetCellInformation(CellX, CellY)->AreaID[ConvertTo2dArray(IntX)][ConvertTo2dArray(IntY)];
}

float TerrainMgr::GetLandHeight(float x, float y)
{
	if(!AreCoordinatesValid(x, y))
		return 0.0f;

	// Convert the co-ordinates to cells.
	uint32 CellX = ConvertGlobalXCoordinate(x);
	uint32 CellY = ConvertGlobalYCoordinate(y);

	if(!CellInformationLoaded(CellX, CellY) && !LoadCellInformation(CellX, CellY))
		return 0.0f;

	// Convert the co-ordinates to cell's internal
	// system.
	float IntX = ConvertInternalXCoordinate(x, CellX);
	float IntY = ConvertInternalYCoordinate(y, CellY);

	// Calculate x index.
	float TempFloat = IntX * (MAP_RESOLUTION / CellsPerTile / _cellSize);
	uint32 XOffset = FL2UINT(TempFloat);
	if((TempFloat - (XOffset * _cellSize)) >= 0.5f)
		++XOffset;

	// Calculate y index.
	TempFloat = IntY * (MAP_RESOLUTION / CellsPerTile / _cellSize);
	uint32 YOffset = FL2UINT(TempFloat);
	if((TempFloat - (YOffset * _cellSize)) >= 0.5f)
		++YOffset;

	// Return our cached information.
	return GetCellInformation(CellX, CellY)->Z[XOffset][YOffset];
}

void TerrainMgr::CellGoneActive(uint32 x, uint32 y)
{
	// Load cell information if it's not already loaded.
	if(!CellInformationLoaded(x, y))
		LoadCellInformation(x, y);
}

void TerrainMgr::CellGoneIdle(uint32 x, uint32 y)
{
	// If we're not an instance, unload our cell info.
	if(!Instance && CellInformationLoaded(x, y))
		UnloadCellInformation(x, y);
}
