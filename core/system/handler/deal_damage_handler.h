#pragma once
#include "component/health.h"
#include "component/strength.h"
#include "effect_handler.h"
#include "util/logging.h"

struct DealDamageHandler final : EffectHandler {
    void handle(entt::registry& registry, const entt::entity player, entt::entity target,
                const CardEffects::Effect& e) override {
        auto* health = registry.try_get<Health>(target);
        if (!health) return;

        int bonus = 0;
        if (const auto* str = registry.try_get<Strength>(player)) {
            bonus = str->amount;
        }

        const int totalDamage = e.value + bonus;
        health->current -= totalDamage;
        if (health->current < 0) health->current = 0;

        const auto logger = core::getLogger();
        logger->debug("Player {} dealt {} damage to entity {}. HP = {}/{}", static_cast<int>(player), totalDamage,
                      static_cast<int>(target), health->current, health->max);
    }
};
