#include "game/turn_manager.h"

void TurnManager::startTurn(const entt::entity entity) {
    dispatcher.trigger(BeginTurnEvent{entity, turnNumber});
    executePhase(TurnPhase::BeginTurn, entity);
}
void TurnManager::endTurn(const entt::entity entity) {
    executePhase(TurnPhase::EndTurn, entity);
    dispatcher.trigger(EndTurnEvent{entity, turnNumber});
    turnNumber++;
}

void TurnManager::registerSystem(const TurnPhase phase, std::function<void(entt::registry&, entt::entity)> system,
                                 int priority) {
    systems[phase].push_back({priority, system});
    std::sort(systems[phase].begin(), systems[phase].end(), [](auto& a, auto& b) { return a.priority < b.priority; });
}

void TurnManager::executePhase(TurnPhase phase, const entt::entity entity) {
    const auto& sysList = systems[phase];
    for (auto& entry : sysList) {
        entry.system(registry, entity);
    }
}
