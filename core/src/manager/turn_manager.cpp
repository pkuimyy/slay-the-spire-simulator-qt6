#include "manager/turn_manager.h"

void TurnManager::startTurn(const entt::entity character) {
    turnNumber++;
    dispatcher.trigger(TurnStartEvent{character, turnNumber});
}

void TurnManager::endTurn(const entt::entity character) const {
    dispatcher.trigger(TurnEndEvent{character, turnNumber});
}
