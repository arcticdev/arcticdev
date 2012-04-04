/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

class Wintergrasp;

class SERVER_DECL WintergraspInternal : public Singleton<WintergraspInternal>, public ThreadContext
{
	// Thread stuff.
	private:
		time_t currenttime;
		tm local_currenttime;
		time_t last_countertime;
		tm local_last_countertime;
		time_t last_wintergrasp_time;
		tm local_last_wintergrasp_time;

	public:
		WintergraspInternal();
		~WintergraspInternal();

		void terminate();
		void set_tm_pointers();
		void LoadWintergraspSettings();
		void UpdateWintergraspSettings();
		void dupe_tm_pointer(tm * returnvalue, tm * mypointer);
		bool has_timeout_expired(tm * now_time, tm * last_time);

		bool run();
		bool m_threadRunning;
		bool m_dirty;

	// Actual Wintergrasp Internal stuff.
	public:
		void SendInitWorldStates(Player* plr = NULL);
		void UpdateClock();
		void UpdateClockDigit(uint32 timer, uint32 digit, uint32 mod);
		void SendWSUpdateToAll(uint32 WorldState, uint32 Value);

		int m_wintergrasp;
	private:
		Wintergrasp* WG;

		MapMgr WGMgr;
		uint32 WGcounter;
		int winnerteam; // 0 alliance 1 horde 2 = ??

		uint32 defendingteam;
		uint32 m_timer;
		uint32 m_clock[5];

		bool WG_started;
	public:
		void SetWGTimer(uint32 time) { m_timer = time; };
		void StartWintergrasp() { WG_started = true; };
		void EndWintergrasp() { WG_started = false; WG = NULL; };
};

#define sWintergraspI WintergraspInternal::getSingleton()

