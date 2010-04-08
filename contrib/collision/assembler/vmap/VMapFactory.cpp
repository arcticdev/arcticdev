/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */
 
#include <sys/types.h>
#include "VMapFactory.h"
#include "VMapManager.h"

namespace VMAP
{
    extern void chompAndTrim(std::string& str);

    VMapManager *gVMapManager = 0;
    Table<unsigned int , bool>* iIgnoreSpellIds=0;

    //===============================================
    // result false, if no more id are found

    bool getNextId(const std::string& pString, unsigned int& pStartPos, unsigned int& pId)
    {
        bool result = false;
        unsigned int i;
        for(i=pStartPos;i<pString.size(); ++i)
        {
            if(pString[i] == ',')
            {
                break;
            }
        }
        if(i>pStartPos)
        {
            std::string idString = pString.substr(pStartPos, i-pStartPos);
            pStartPos = i+1;
            chompAndTrim(idString);
            pId = atoi(idString.c_str());
            result = true;
        }
        return(result);
    }

    //===============================================
    
	/* parameter: String of map ids. Delimiter = "," */

    void VMapFactory::preventSpellsFromBeingTestedForLoS(const char* pSpellIdString)
    {
        if(!iIgnoreSpellIds)
            iIgnoreSpellIds = new Table<unsigned int , bool>();
        if(pSpellIdString != NULL)
        {
            unsigned int pos =0;
            unsigned int id;
            std::string confString(pSpellIdString);
            chompAndTrim(confString);
            while(getNextId(confString, pos, id))
            {
                iIgnoreSpellIds->set(id, true);
            }
        }
    }

    //===============================================

    bool VMapFactory::checkSpellForLoS(unsigned int pSpellId)
    {
        return(!iIgnoreSpellIds->containsKey(pSpellId));
    }

    //===============================================
    // just return the instance
    IVMapManager* VMapFactory::createOrGetVMapManager()
    {
        if(gVMapManager == 0)
            gVMapManager= new VMapManager();                // should be taken from config ... Please change if you like :-)
        return gVMapManager;
    }

    //===============================================
    // delete all internal data structures
    void VMapFactory::clear()
    {
        if(iIgnoreSpellIds)
            delete iIgnoreSpellIds;
        if(gVMapManager)
            delete gVMapManager;
    }
}
