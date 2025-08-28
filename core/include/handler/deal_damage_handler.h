#pragma once
#include "component/effect.h"
#include "component/health.h"
#include "event/battle_event.h"
#include "handler/effect_handler.h"

class DealDamageHandler final : public EffectHandler {
   public:
    DealDamageHandler(entt::dispatcher& dispatcher, entt::registry& registry, BattleManager& battleManager);

   protected:
    void handleImpl(entt::entity player, entt::entity target, const Effect& e) override;
};
