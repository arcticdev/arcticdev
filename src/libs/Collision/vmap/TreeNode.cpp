/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#include "TreeNode.h"

namespace VMAP
{

    TreeNode const* TreeNode::getChild(TreeNode const* pValueArray,int pNo) const
    {
        if(iChilds[pNo] != -1)
            return(&pValueArray[iChilds[pNo]]);
        else
            return(0);
    }

    //=================================================================
    //=================================================================
    //=================================================================
}
