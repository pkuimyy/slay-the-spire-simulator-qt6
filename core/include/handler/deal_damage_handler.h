#pragma once
#include "component/effect.h"
#include "component/health.h"
#include "event/battle_event.h"
#include "event/deal_damage_event.h"
#include "handler/event_handler.h"

class DealDamageHandler final : public EventHandler {
   public:
    DealDamageHandler(entt::dispatcher& dispatcher, entt::registry& registry, BattleManager& battleManager);

    void onDealDamage(const DealDamageEvent& event);

   protected:
    void handleImpl(entt::entity player, entt::entity target, const Effect& e) override;
};
