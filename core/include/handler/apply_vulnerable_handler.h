#pragma once
#include "component/effect.h"
#include "handler/effect_handler.h"

struct ApplyVulnerableHandler final : EffectHandler {
   protected:
    void handleImpl(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) override;
};
