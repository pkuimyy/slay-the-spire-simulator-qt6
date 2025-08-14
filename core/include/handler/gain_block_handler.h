#pragma once
#include "component/block.h"
#include "effect_handler.h"
#include "util/logging.h"

struct GainBlockHandler final : EffectHandler {
    void handle(entt::registry& registry, const entt::entity player, entt::entity target, const Effect& e) override {
        auto& block = registry.get_or_emplace<Block>(player);
        block.amount += e.value;

        const auto logger = core::getLogger();
        logger->debug("Player {} gained {} block. Block = {}", static_cast<int>(player), e.value, block.amount);
    }
};
