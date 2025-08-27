#include "game/battle_manager.h"

#include "component/health.h"
#include "event/battle.h"

BattleManager& BattleManager::getInstance() {
    static BattleManager instance;
    return instance;
}

void BattleManager::init(entt::registry& reg, entt::dispatcher& disp, entt::entity playerEntity,
                         const std::vector<entt::entity>& enemyList, TurnManager& playerTM, TurnManager& enemyTM) {
    registry = &reg;
    dispatcher = &disp;
    player = playerEntity;
    enemies = enemyList;
    playerTurnManager = &playerTM;
    enemyTurnManager = &enemyTM;
    roundNumber = 1;
    battleEnded = false;

    dispatcher->sink<HealthChangeEvent>().connect<&BattleManager::onHealthChanged>(*this);
}

void BattleManager::startBattle() {
    dispatcher->trigger(BattleStartEvent{player, enemies});
    while (!battleEnded) {
        dispatcher->trigger(RoundStartEvent{roundNumber});

        executePlayerTurn();
        if (battleEnded) break;

        executeEnemyTurn();
        if (battleEnded) break;

        dispatcher->trigger(RoundEndEvent{roundNumber});
        roundNumber++;
    }
    dispatcher->trigger(BattleEndEvent{isPlayerAlive()});
}

void BattleManager::endBattle() {
    battleEnded = true;
}

void BattleManager::onHealthChanged(const HealthChangeEvent&) {
    if (!isPlayerAlive() || allEnemiesDead()) {
        endBattle();
    }
}

void BattleManager::executePlayerTurn() {
    playerTurnManager->startTurn(player);
    playerTurnManager->endTurn(player);
}

void BattleManager::executeEnemyTurn() {
    for (auto enemy : enemies) {
        if (!isAlive(enemy)) continue;
        enemyTurnManager->startTurn(enemy);
        enemyTurnManager->endTurn(enemy);
    }
}

bool BattleManager::isBattleEnded() const {
    return battleEnded;
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
    const auto* hp = registry->try_get<Health>(entity);
    return hp && hp->current > 0;
}
