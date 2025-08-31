#pragma once
#include "handler/deal_damage_handler.h"
#include "handler/end_battle_handler.h"
#include "manager/battle_manager.h"

class HandlerRegistry {
   public:
    HandlerRegistry(entt::dispatcher& _dispatcher, entt::registry& _registry, BattleManager& _battleManager);

   private:
    std::unique_ptr<EndBattleHandler> endBattleHandler;
    std::unique_ptr<DealDamageHandler> dealDamageHandler;
};
