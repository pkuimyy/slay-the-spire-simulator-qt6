#pragma once
#include "pch.h"

class BattleManager {
   public:
    BattleManager(entt::dispatcher& _dispatcher, entt::registry& _registry)
        : dispatcher(_dispatcher), registry(_registry) {};

    void startBattle();

    void endBattle();

    void setBattleEnded(bool ended);

    bool isBattleEnded() const;

   private:
    entt::dispatcher& dispatcher;
    entt::registry& registry;
    bool battleEnded{false};
};
