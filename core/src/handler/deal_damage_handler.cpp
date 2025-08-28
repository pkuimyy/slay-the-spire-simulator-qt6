#include "handler/deal_damage_handler.h"

DealDamageHandler::DealDamageHandler(entt::dispatcher& dispatcher, entt::registry& registry,
                                     BattleManager& battleManager)
    : EffectHandler(dispatcher, registry, battleManager) {};

void DealDamageHandler::handleImpl(entt::entity player, entt::entity target, const Effect& e) {
    auto* health = registry.try_get<Health>(target);
    if (!health) return;

    health->current -= e.value;
    if (health->current < 0) health->current = 0;

    const auto logger = core::getLogger();
    logger->debug("Player {} dealt {} damage to entity {}. HP = {}/{}", static_cast<int>(player), e.value,
                  static_cast<int>(target), health->current, health->max);

    if (health->current == 0 && !battleManager.isBattleEnded()) {
        dispatcher.trigger(BattleEndEvent{});
    }
}