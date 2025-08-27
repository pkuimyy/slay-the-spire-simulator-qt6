#include "handler/effect_handler.h"

void EffectHandler::handleBattleEnded(entt::registry& registry, entt::entity player, entt::entity target,
                                      const Effect& e) {
    return;
}

bool EffectHandler::isBattleEnded() {
    return BattleManager::getInstance().isBattleEnded();
}

void EffectHandler::handle(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) {
    if (isBattleEnded()) {
        handleBattleEnded(registry, player, target, e);
    } else {
        handleImpl(registry, player, target, e);
    }
}