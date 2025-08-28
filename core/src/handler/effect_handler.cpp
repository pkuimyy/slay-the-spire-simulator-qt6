#include "handler/effect_handler.h"

void EffectHandler::handleBattleEnded(entt::registry& registry, entt::entity player, entt::entity target,
                                      const Effect& e) {
    return;
}

bool EffectHandler::isBattleEnded() {
    return false;
}

void EffectHandler::handle(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) {}