#include "handler/event_handler.h"

EventHandler::EventHandler(entt::dispatcher& _dispatcher, entt::registry& _registry, BattleManager& _battleManager)
    : dispatcher(_dispatcher), registry(_registry), battleManager(_battleManager) {}

void EventHandler::handle(entt::entity player, entt::entity target, const Effect& e) {
    if (battleManager.isBattleEnded()) {
        handleBattleEnded(player, target, e);
    } else {
        handleImpl(player, target, e);
    }
}

EventHandler::~EventHandler() = default;

void EventHandler::handleImpl(entt::entity player, entt::entity target, const Effect& e) {}

void EventHandler::triggerEvent(entt::entity player, entt::entity target, const Effect& e) {}

void EventHandler::handleBattleEnded(entt::entity player, entt::entity target, const Effect& e) {
    core::getLogger()->debug("Battle ended. EffectHandler does not handle effect.");
}
