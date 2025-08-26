#pragma once
#include "event/health_change_event.h"
#include "pch.h"
#include "turn_manager.h"

class BattleManager {
   public:
    BattleManager(entt::registry& registry, entt::dispatcher& dispatcher, const entt::entity player,
                  const std::vector<entt::entity>& enemies, TurnManager& playerTurnManager,
                  TurnManager& enemyTurnManager);

    void startBattle();

    void endBattle();

    void onHealthChanged(const HealthChangeEvent& evt);

   private:
    entt::dispatcher& dispatcher;
    entt::registry& registry;
    entt::entity player;
    std::vector<entt::entity> enemies;
    int roundNumber;
    bool battleEnded;

    TurnManager playerTurnManager;
    TurnManager enemyTurnManager;

    void executePlayerTurn();

    void executeEnemyTurn();

    bool isPlayerAlive() const;

    bool allEnemiesDead() const;

    bool isAlive(entt::entity entity) const;
};