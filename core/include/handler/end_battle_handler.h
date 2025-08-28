#pragma once
#include "event/battle_event.h"
#include "manager/battle_manager.h"
#include "pch.h"

class EndBattleHandler {
   public:
    EndBattleHandler(entt::dispatcher& _dispatcher, entt::registry& _registry, BattleManager& _battleManager);

   private:
    void onBattleEnd(const struct BattleEndEvent&);

    BattleManager& battleManager;
    entt::dispatcher& dispatcher;
    entt::registry& registry;
};
