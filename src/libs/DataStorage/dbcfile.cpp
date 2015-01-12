/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2014 Arctic Server Team
 * See COPYING for license details.
 */

#include "dbcfile.h"
#include <stdio.h>
//#include "../Common.h"

DBCFile::DBCFile()
{
	data = NULL;
	stringTable = NULL;
}

DBCFile::~DBCFile()
{
	if(	data )
		delete[] data;
	if ( stringTable )
		delete[] stringTable;
}

bool DBCFile::open(const char*fn)
{
	if(data)
	{
		delete [] data;
		data = NULL;
	}
	FILE*pf=fopen(fn,"rb");
	if(!pf)return false;

	fread(header,4,1,pf); // Number of records
	assert(header[0]=='W' && header[1]=='D' && header[2]=='B' && header[3] == 'C');
	fread(&recordCount,4,1,pf); // Number of records
	fread(&fieldCount,4,1,pf);  // Number of fields
	fread(&recordSize,4,1,pf);  // Size of a record
	fread(&stringSize,4,1,pf);  // String size

	data = new unsigned char[recordSize*recordCount];
	stringTable = new unsigned char[stringSize];
	fread( data ,recordSize*recordCount,1,pf);
	fread( stringTable , stringSize,1,pf);

	fclose(pf);
	return true;
}

DBCFile::Record DBCFile::getRecord(size_t id)
{
	assert(data);
	return Record(*this, data + id*recordSize);
}

DBCFile::Iterator DBCFile::begin()
{
	assert(data);
	return Iterator(*this, data);
}
DBCFile::Iterator DBCFile::end()
{
	assert(data);
	return Iterator(*this, stringTable);
}

bool DBCFile::DumpBufferToFile(const char*fn)
{
  FILE * pFile;
  pFile = fopen ( fn , "wb" );
  if(!pFile)
	  return false;

  // write header stuff
  fwrite ((const void *)&header , 4 , 1 , pFile );
  fwrite ((const void *)&recordCount , 4 , 1 , pFile );
  fwrite ((const void *)&fieldCount , 4 , 1 , pFile );
  fwrite ((const void *)&recordSize , 4 , 1 , pFile );
  fwrite ((const void *)&stringSize , 4 , 1 , pFile );

  // now the main part is the data
  fwrite (data , recordSize*recordCount , 1 , pFile );
  fwrite (stringTable , stringSize , 1 , pFile );

  // and pull out
  fclose (pFile);
  return true;
}
