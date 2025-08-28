#pragma once
#include "event/battle_event.h"
#include "event/turn_event.h"
#include "pch.h"

class LogSystem {
   public:
    LogSystem(entt::dispatcher& disp);

    void onBattleStart(const BattleStartEvent& evt);

    void onBattleEnd(const BattleEndEvent& evt);

    void onTurnStart(const TurnStartEvent& evt);

    void onTurnEnd(const TurnEndEvent& evt);

    const std::vector<std::string>& getRecords();
    
    void clear();

   private:
    std::vector<std::string> records;
};