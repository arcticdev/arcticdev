/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
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
