#pragma once
#include "component/effect.h"
#include "manager/battle_manager.h"
#include "pch.h"

class EventHandler {
   public:
    EventHandler(entt::dispatcher& _dispatcher, entt::registry& _registry, BattleManager& _battleManager);

    void handle(entt::entity player, entt::entity target, const Effect& e);

    virtual ~EventHandler();

   protected:
    entt::dispatcher& dispatcher;
    entt::registry& registry;
    BattleManager& battleManager;

    virtual void handleImpl(entt::entity player, entt::entity target, const Effect& e);

    virtual void handleBattleEnded(entt::entity player, entt::entity target, const Effect& e);

    virtual void triggerEvent(entt::entity player, entt::entity target, const Effect& e);
};