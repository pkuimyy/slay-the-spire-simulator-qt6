#pragma once
#include "component/strength.h"
#include "effect_handler.h"
#include "util/logging.h"

struct GainStrengthHandler final : EffectHandler {
    void handle(entt::registry& registry, const entt::entity player, entt::entity target, const Effect& e) override {
        auto& str = registry.get_or_emplace<Strength>(player);
        str.amount += e.value;

        const auto logger = core::getLogger();
        logger->debug("Player {} gained {} Strength. Total = {}", static_cast<int>(player), e.value, str.amount);
    }
};
