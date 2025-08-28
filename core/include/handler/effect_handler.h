#pragma once
#include "component/effect.h"
#include "pch.h"

class EffectHandler {
   public:
    void handle(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e);

    virtual ~EffectHandler() = default;

   protected:
    virtual void handleImpl(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) = 0;

    virtual void handleBattleEnded(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e);

    static bool isBattleEnded();
};