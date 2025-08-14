#pragma once
#include "component/effect.h"

struct EffectHandler {
    virtual void handle(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) = 0;
    virtual ~EffectHandler() = default;
};
