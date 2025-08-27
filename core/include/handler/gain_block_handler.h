#pragma once
#include "handler/effect_handler.h"
#include "component/block.h"

struct GainBlockHandler final : EffectHandler {
   protected:
    void handleImpl(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) override;
};
