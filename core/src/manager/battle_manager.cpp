#include "manager/battle_manager.h"

#include "event/battle_event.h"

void BattleManager::startBattle() {
    dispatcher.trigger(BattleStartEvent{});
}

void BattleManager::setBattleEnded(bool ended) {
    battleEnded = ended;
}

bool BattleManager::isBattleEnded() const {
    return battleEnded;
}

void BattleManager::endBattle() {
    if (battleEnded) return;
    battleEnded = true;
    dispatcher.trigger(BattleEndEvent{});
}