#pragma once
#include "component/effect.h"
#include "manager/battle_manager.h"
#include "pch.h"

class EffectHandler {
   public:
    EffectHandler(entt::dispatcher& _dispatcher, entt::registry& _registry, BattleManager& _battleManager);

    void handle(entt::entity player, entt::entity target, const Effect& e);

    virtual ~EffectHandler() = default;

   protected:
    entt::dispatcher& dispatcher;
    entt::registry& registry;
    BattleManager& battleManager;

    virtual void handleImpl(entt::entity player, entt::entity target, const Effect& e) = 0;

    virtual void handleBattleEnded(entt::entity player, entt::entity target, const Effect& e);
};