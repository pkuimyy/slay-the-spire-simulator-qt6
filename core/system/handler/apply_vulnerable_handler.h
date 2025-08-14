#pragma once
#include "component/vulnerable.h"
#include "effect_handler.h"
#include "util/logging.h"

struct ApplyVulnerableHandler final : EffectHandler {
    void handle(entt::registry& registry, const entt::entity player, entt::entity target, const Effect& e) override {
        auto& vuln = registry.get_or_emplace<Vulnerable>(target);
        vuln.turns += e.value;

        const auto logger = core::getLogger();
        logger->debug("Entity {} gained {} turns of Vulnerable (total: {}).", static_cast<int>(target), e.value,
                      vuln.turns);
    }
};
