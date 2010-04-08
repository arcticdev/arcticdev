/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _ISLESOFCONQUEST_H_
#define _ISLESOFCONQUEST_H_

class CBattleground;
class IslesOfConquest;

class IslesOfConquestScore : public CBattlegroundManager
{
    public:
        IslesOfConquestScore() {};
        virtual ~IslesOfConquestScore() {};
};

class IslesOfConquest : public CBattleground
{
   // friend class BattleGroundMgr;

    public:
        IslesOfConquest();
        ~IslesOfConquest();
        // void Update(uint32 diff);

        virtual void AddPlayer(PlayerPointer plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(PlayerPointer plr, uint64 guid);
        void HandleAreaTrigger(PlayerPointer plr, uint32 Trigger);
        bool SetupCBattleground();
        void UpdatePlayerScore(PlayerPointer plr, uint32 type, uint32 value);

};

#endif
