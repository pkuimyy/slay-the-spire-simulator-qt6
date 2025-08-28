#include "handler/effect_handler.h"

EffectHandler::EffectHandler(entt::dispatcher& _dispatcher, entt::registry& _registry, BattleManager& _battleManager)
    : dispatcher(_dispatcher), registry(_registry), battleManager(_battleManager) {}

void EffectHandler::handle(entt::entity player, entt::entity target, const Effect& e) {
    if (battleManager.isBattleEnded()) {
        handleBattleEnded(player, target, e);
    } else {
        handleImpl(player, target, e);
    }
}

void EffectHandler::handleBattleEnded(entt::entity player, entt::entity target, const Effect& e) {
    core::getLogger()->debug("Battle ended. EffectHandler does not handle effect.");
}
