#pragma once
#include "component/health.h"
#include "event/turn.h"
#include "pch.h"

class TurnManager {
   public:
    TurnManager(entt::dispatcher& dispatcher, entt::registry& registry)
        : dispatcher(dispatcher), registry(registry), turnNumber(1) {};

    void startTurn(entt::entity entity);

    void endTurn(entt::entity entity);

    void registerSystem(TurnPhase phase, const std::function<void(entt::registry&, entt::entity)>& system,
                        int priority = 0);

    void registerDefaultSystems();

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

    bool isAlive(entt::entity entity);
};