#pragma once
#include "event/turn_event.h"
#include "pch.h"

class TurnManager {
   public:
    TurnManager(entt::dispatcher& _dispatcher, entt::registry& _registry)
        : dispatcher(_dispatcher), registry(_registry) {};

    void startTurn(entt::entity character);

    void endTurn(entt::entity character);

   private:
    entt::dispatcher& dispatcher;
    entt::registry& registry;
    int turnNumber{0};
};
