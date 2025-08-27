#pragma once
#include "component/effect.h"
#include "component/health.h"
#include "component/strength.h"
#include "component/vulnerable.h"
#include "handler/effect_handler.h"

struct DealDamageHandler final : EffectHandler {
   protected:
    void handleImpl(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) override;
};
