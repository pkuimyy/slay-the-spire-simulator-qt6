#pragma once
#include <entt/entt.hpp>
#include <vector>

#include "event/health_change_event.h"
#include "game/turn_manager.h"

class BattleManager {
   public:
    static BattleManager& getInstance();

    void init(entt::registry& registry, entt::dispatcher& dispatcher, entt::entity player,
              const std::vector<entt::entity>& enemies, TurnManager& playerTurnManager, TurnManager& enemyTurnManager);

    void startBattle();
    void endBattle();

    bool isBattleEnded() const;
    bool isPlayerAlive() const;
    bool allEnemiesDead() const;

    BattleManager(const BattleManager&) = delete;
    BattleManager& operator=(const BattleManager&) = delete;

   private:
    BattleManager() = default;

    void onHealthChanged(const HealthChangeEvent& evt);
    void executePlayerTurn();
    void executeEnemyTurn();
    bool isAlive(entt::entity entity) const;

    entt::registry* registry{nullptr};
    entt::dispatcher* dispatcher{nullptr};
    entt::entity player{};
    std::vector<entt::entity> enemies;
    int roundNumber{1};
    bool battleEnded{false};
    TurnManager* playerTurnManager{nullptr};
    TurnManager* enemyTurnManager{nullptr};
};