#include "handler/deal_damage_handler.h"

#include "util/logging.h"

void DealDamageHandler::handleImpl(entt::registry& registry, entt::entity player, entt::entity target,
                                   const Effect& e) {
    auto* health = registry.try_get<Health>(target);
    if (!health) return;

    int bonus = 0;
    if (const auto* str = registry.try_get<Strength>(player)) {
        bonus = str->amount;
    }

    int totalDamage = e.value + bonus;

    if (const auto* vuln = registry.try_get<Vulnerable>(target)) {
        if (vuln->turns > 0) {
            totalDamage = static_cast<int>(totalDamage * 1.5f);
        }
    }

    health->current -= totalDamage;
    if (health->current < 0) health->current = 0;

    const auto logger = core::getLogger();
    logger->debug("Player {} dealt {} damage to entity {}. HP = {}/{}", static_cast<int>(player), totalDamage,
                  static_cast<int>(target), health->current, health->max);
}
