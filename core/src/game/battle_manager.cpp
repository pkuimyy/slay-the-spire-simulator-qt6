#include "game/battle_manager.h"

#include "component/health.h"
#include "event/battle.h"

BattleManager::BattleManager(entt::registry& registry, entt::dispatcher& dispatcher, const entt::entity player,
                             const std::vector<entt::entity>& enemies, TurnManager& playerTurnManager,
                             TurnManager& enemyTurnManager)
    : registry(registry),
      dispatcher(dispatcher),
      player(player),
      enemies(enemies),
      roundNumber(1),
      battleEnded(false),
      playerTurnManager(playerTurnManager),
      enemyTurnManager(enemyTurnManager) {
    dispatcher.sink<HealthChangeEvent>().connect<&BattleManager::onHealthChanged>(*this);
}

void BattleManager::startBattle() {
    dispatcher.trigger(BattleStartEvent{player, enemies});
    while (!battleEnded) {
        dispatcher.trigger(RoundStartEvent{roundNumber});

        executePlayerTurn();
        // if (checkBattleEnd()) break;

        executeEnemyTurn();
        // if (checkBattleEnd()) break;

        dispatcher.trigger(RoundEndEvent{roundNumber});
        roundNumber++;
    }
    dispatcher.trigger(BattleEndEvent{isPlayerAlive()});
}

void BattleManager::endBattle() {
    battleEnded = true;
}

void BattleManager::onHealthChanged(const HealthChangeEvent& evt) {
    if (!isPlayerAlive() || allEnemiesDead()) {
        endBattle();
    }
}

void BattleManager::executePlayerTurn() {
    playerTurnManager.startTurn(player);
    playerTurnManager.endTurn(player);
}

void BattleManager::executeEnemyTurn() {
    for (auto enemy : enemies) {
        if (!isAlive(enemy)) continue;
        enemyTurnManager.startTurn(enemy);
        enemyTurnManager.endTurn(enemy);
    }
}

bool BattleManager::isPlayerAlive() const {
    return isAlive(player);
}

bool BattleManager::allEnemiesDead() const {
    for (const auto enemy : enemies) {
        if (isAlive(enemy)) return false;
    }
    return true;
}

bool BattleManager::isAlive(const entt::entity entity) const {
    const auto* hp = registry.try_get<Health>(entity);
    return hp && hp->current > 0;
}
