/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "TileAssembler.h"

//=======================================================
// remove last return or LF and tailing SPACE
// remove all char after a #

void chompAndTrim(std::string& str)
{
    for(unsigned int i=0;i<str.length(); ++i) {
        char lc = str[i];
        if(lc == '#') {
            str = str.substr(0,i);
            break;
        }
    }

    while(str.length() >0) {
        char lc = str[str.length()-1];
        if(lc == '\r' || lc == '\n' || lc == ' ') {
            str = str.substr(0,str.length()-1);
        } else {
            break;
        }
    }
}

//=======================================================
// This callback method is called for each model found in the dir file.
// return true if it should be included in the vmap

bool modelNameFilter(char *pName)
{
#if 0
    bool result;
    result = !Wildcard::wildcardfit("*bush[0-9]*", pName);
    if(result) result = !Wildcard::wildcardfit("*shrub[0-9]*", pName);
    if(result) result = !Wildcard::wildcardfit("*_Bushes_*", pName);
    if(result) result = !Wildcard::wildcardfit("*_Bush_*", pName);
    if(!result) {
        printf("%s",pName);
    }
#endif
    return true;
}

//=======================================================
int main(int argc, char* argv[])
{
	bool ok = true;
	if(argc != 3 && argc != 4)
	{
        printf("\nusage: %s <raw data dir> <vmap dest dir> [config file name]\n", argv[0]);
        return 1;
    }

    char *src = argv[1];
    char *dest = argv[2];
    char *conffile = NULL;
    if(argc >= 4)
        conffile = argv[3];
 
    VMAP::TileAssembler* ta = new VMAP::TileAssembler(std::string(src), std::string(dest));
    ta->setModelNameFilterMethod(modelNameFilter);
 
/*
All the names in the list are considered to be world maps or huge instances.
These maps will be spilt into tiles in the vmap assemble process
*/
	static int32 maps[999] = { 0, 1, 30, 33, 34, 36, 43, 47, 48, 70, 90, 109, 129, 189, 209, 229, 230, 249, 269, 289, 309, 329, 349, 389, 409, 429, 469, 489, 509, 529, 530, 531, 532, 533, 534, 540, 542, 543, 544, 545, 546, 547, 548, 550, 552, 553, 554, 555, 556, 557, 558, 559, 560, 562, 564, 565, 566, 568, 571, 572, 574, 575, 576, 578, 580, 585, 595, 599, 600, 601, 602, 603, 604, 607, 608, 609, 615, 616, 617, 618, 619, 624, 628, 649, 650, -1 };
	for(uint32 i = 0; maps[i] != -1; ++i)
		ta->addWorldAreaMapId( maps[i] );

    ok = ta->convertWorld();
    if(ok) 
	{
        printf("Ok, all done\n");
    } else 
	{
        printf("exit with errors\n");
        return 1;
    }
    delete ta;
    return 0;
}
