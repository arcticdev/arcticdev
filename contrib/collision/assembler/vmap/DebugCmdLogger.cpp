/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */
 
#include "DebugCmdLogger.h"

namespace VMAP
{

    bool CommandFileRW::appendCmd(const Command& pCommand)
    {
        #ifdef _DEBUG
        bool result = false;
        if(iWritingEnabled || pCommand.isCoreCmd())
        {
            FILE* f = fopen(iFileName.c_str(), "ab");
            if(f)
            {
                result = true;
                if(fwrite(&pCommand, sizeof(Command), 1, f) != 1) { result = false; }
                fclose(f);
            }
        }
        else
        {
            result = true;
        }
        return result;
        #else
        return true;
        #endif
    }

    //=========================================================

    bool CommandFileRW::appendCmds(const Array<Command>& pCmdArray)
    {
        #ifdef _DEBUG
        bool result = false;
        if(iWritingEnabled)
        {
            FILE* f;
            if(resetfile)
                f = fopen(iFileName.c_str(), "wb");
            else
                f = fopen(iFileName.c_str(), "ab");
            resetfile = false;

            if(f)
            {
                result = true;
                for(int i=0; i<pCmdArray.size(); ++i)
                {
                    if(fwrite(&pCmdArray[i], sizeof(Command), 1, f) != 1) { result = false; break; }
                }
                fclose(f);
            }
        }
        else
        {
            result = true;
        }
        return result;
        #else
        return true;
        #endif
    }

    //=========================================================

    bool CommandFileRW::getNewCommands(Array<Command>& pCmdArray)
    {
        bool result = false;
        FILE* f = fopen(iFileName.c_str(), "rb");
        if(f)
        {
            Command cmd;
            if(fseek(f, iLastPos, SEEK_SET) == 0) { result = true; }
            while(result)
            {
                if(fread(&cmd, sizeof(Command), 1, f) != 1)
                {
                    result = false;
                }
                iLastPos = ftell(f);
                if(cmd.getType() == STOP)
                {
                    break;
                }
                pCmdArray.append(cmd);
            }
            fclose(f);
        }
        if(result)
        {
            iCommandArray.append(pCmdArray);
        }
        return(result);
    }
    //========================================================
}
