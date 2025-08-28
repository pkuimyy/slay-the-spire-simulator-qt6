#include "manager/battle_manager.h"

#include "event/battle_event.h"

void BattleManager::startBattle() {
    dispatcher.trigger(BattleStartEvent{});
}

void BattleManager::endBattle() {
    dispatcher.trigger(BattleEndEvent{});
}