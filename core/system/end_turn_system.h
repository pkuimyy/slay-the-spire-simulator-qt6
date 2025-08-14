#pragma once
#include <entt/entt.hpp>

#include "component/block.h"
#include "util/logging.h"

struct EndTurnSystem {
    static void onEndTurn(entt::registry& registry) {
        const auto logger = core::getLogger();
        registry.view<Block>().each([&](auto entity, Block& block) {
            if (block.amount > 0) {
                logger->debug("Entity {} block reset from {} to 0", static_cast<int>(entity), block.amount);
                block.amount = 0;
            }
        });
    }
};
