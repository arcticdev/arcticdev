/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2014 Arctic Server Team
 * See COPYING for license details.
 */

#include "Common.h"
#include "CThreads.h"

CThread::CThread() : ThreadBase()
{
	ThreadState = THREADSTATE_AWAITING;
	start_time  = 0;
}

CThread::~CThread()
{
	
}

bool CThread::run()
{
	return false;
}

void CThread::OnShutdown()
{
	SetThreadState(THREADSTATE_TERMINATE);
}

