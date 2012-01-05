/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"

bool ColdSnap(uint32 i, Spell* pSpell)
{
    if(!pSpell->p_caster) return true;
    pSpell->p_caster->ClearCooldownsOnLine(6, pSpell->m_spellInfo->Id);
    return true;
}

void SetupMageSpells(ScriptMgr * mgr)
{
    mgr->register_dummy_spell(11958, &ColdSnap);
}
