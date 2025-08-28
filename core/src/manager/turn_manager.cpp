#include "manager/turn_manager.h"

void TurnManager::startTurn(entt::entity character) {
    turnNumber++;
    dispatcher.trigger(TurnStartEvent{character, turnNumber});
}

void TurnManager::endTurn(entt::entity character) {
    dispatcher.trigger(TurnEndEvent{character, turnNumber});
}
