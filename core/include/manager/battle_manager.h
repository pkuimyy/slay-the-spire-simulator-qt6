#pragma once
#include "pch.h"

class BattleManager {
   public:
    BattleManager(entt::dispatcher& _dispatcher, entt::registry& _registry)
        : dispatcher(_dispatcher), registry(_registry) {};

    void startBattle();

    void endBattle();

   private:
    entt::dispatcher& dispatcher;
    entt::registry& registry;
};
