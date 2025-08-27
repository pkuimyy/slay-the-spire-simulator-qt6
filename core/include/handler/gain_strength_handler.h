#pragma once
#include "component/strength.h"
#include "handler/effect_handler.h"

struct GainStrengthHandler final : EffectHandler {
   protected:
    void handleImpl(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) override;
};
