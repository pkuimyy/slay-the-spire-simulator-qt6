#pragma once
#include <entt/entt.hpp>

#include "component/block.h"
#include "component/vulnerable.h"
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

        registry.view<Vulnerable>().each([](auto entity, Vulnerable& vuln) {
            if (vuln.turns > 0) vuln.turns--;
        });
    }
};
