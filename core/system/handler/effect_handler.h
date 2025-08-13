#pragma once
#include "component/card_effects.h"
#include "entt/entt.hpp"

struct EffectHandler {
    virtual void handle(entt::registry& registry, entt::entity player, entt::entity target,
                        const CardEffects::Effect& e) = 0;
    virtual ~EffectHandler() = default;
};
