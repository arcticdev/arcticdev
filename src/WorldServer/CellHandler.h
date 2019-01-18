/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

#define TilesCount 64
#define TileSize 533.33333f
#define _minY (-TilesCount*TileSize/2)
#define _minX (-TilesCount*TileSize/2)

#define _maxY (TilesCount*TileSize/2)
#define _maxX (TilesCount*TileSize/2)

#define CellsPerTile 8
#define _cellSize (TileSize/CellsPerTile)
#define _sizeX (TilesCount*CellsPerTile)
#define _sizeY (TilesCount*CellsPerTile)

#define GetRelatCoord(Coord,CellCoord) ((_maxX-Coord)-CellCoord*_cellSize)

class Map;

template < class Class >
class CellHandler
{
public:
	CellHandler(Map *map);
	~CellHandler();

	Class *GetCell(uint32 x, uint32 y);
	Class *GetCellByCoords(float x, float y);
	Class *Create(uint32 x, uint32 y);
	Class *CreateByCoords(float x, float y);
	void Remove(uint32 x, uint32 y);

	ARCTIC_INLINE bool Allocated(uint32 x, uint32 y) { return _cells[x][y] != NULL; }

	static uint32 GetPosX(float x); 
	static uint32 GetPosY(float y);

	ARCTIC_INLINE Map *GetBaseMap() { return _map; }

protected:
	void _Init();


	Class ***_cells;

	Map* _map;
};

template <class Class>
CellHandler<Class>::CellHandler(Map* map)
{
	_map = map;


	_Init();
}



template <class Class>
void CellHandler<Class>::_Init()
{
	_cells = new Class**[_sizeX];

	ASSERT(_cells);
	for (uint32 i = 0; i < _sizeX; i++)
	{
		_cells[i] = NULL;
	}
}

template <class Class>
CellHandler<Class>::~CellHandler()
{
	if(_cells)
	{
		for (uint32 i = 0; i < _sizeX; i++)
		{
			if(!_cells[i])
				continue;

			for (uint32 j = 0; j < _sizeY; j++)
			{
				if(_cells[i][j])
					delete _cells[i][j];
			}
			delete [] _cells[i];	
		}
		delete [] _cells;
	}
}

template <class Class>
Class* CellHandler<Class>::Create(uint32 x, uint32 y)
{
	if( x >= _sizeX ||  y >= _sizeY ) 
		return NULL; 

	if(!_cells[x])
	{
		_cells[x] = new Class*[_sizeY];
		memset(_cells[x],0,sizeof(Class*)*_sizeY);
	}

	ASSERT(_cells[x][y] == NULL);

	Class *cls = new Class;
	_cells[x][y] = cls;

	return cls;
}

template <class Class>
Class* CellHandler<Class>::CreateByCoords(float x, float y)
{
	return Create(GetPosX(x),GetPosY(y));
}

template <class Class>
void CellHandler<Class>::Remove(uint32 x, uint32 y)
{
	if( x >= _sizeX ||  y >= _sizeY ) 
		return; 

	if(!_cells[x]) return;
	ASSERT(_cells[x][y] != NULL);

	Class *cls = _cells[x][y];
	_cells[x][y] = NULL;

	delete cls;
}

template <class Class>
Class* CellHandler<Class>::GetCell(uint32 x, uint32 y)
{
	if(!_cells[x]) return NULL;
	return _cells[x][y];
}

template <class Class>
Class* CellHandler<Class>::GetCellByCoords(float x, float y)
{
	return GetCell(GetPosX(x),GetPosY(y));
}

template <class Class>
uint32 CellHandler<Class>::GetPosX(float x)
{
	ASSERT((x >= _minX) && (x <= _maxX));
	return (uint32)((_maxX-x)/_cellSize);
}

template <class Class>
uint32 CellHandler<Class>::GetPosY(float y)
{
	ASSERT((y >= _minY) && (y <= _maxY));
	return (uint32)((_maxY-y)/_cellSize);

}
