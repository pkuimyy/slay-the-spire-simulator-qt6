#pragma once
#include "event/turn.h"
#include "pch.h"

class TurnManager {
   public:
    TurnManager(entt::dispatcher& dispatcher, entt::registry& registry)
        : dispatcher(dispatcher), registry(registry), turnNumber(1) {};

    void startTurn(entt::entity entity);

    void endTurn(entt::entity entity);

    void registerSystem(TurnPhase phase, std::function<void(entt::registry&, entt::entity)> system, int priority = 0);

   private:
    struct SystemEntry {
        int priority;
        std::function<void(entt::registry&, entt::entity)> system;
    };

    entt::dispatcher& dispatcher;
    entt::registry& registry;
    int turnNumber;
    std::unordered_map<TurnPhase, std::vector<SystemEntry>> systems;

    void executePhase(TurnPhase phase, entt::entity entity);
};