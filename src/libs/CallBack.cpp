/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "CallBack.h"

void CallbackFP::operator()()
{
	mycallback();
}

void CallbackFP::execute()
{
	mycallback();
}

CallbackFP* CallbackFP::Create()
{
	return new CallbackFP(NULL);
}
