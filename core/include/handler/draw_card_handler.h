#pragma once
#include "component/pile.h"
#include "handler/effect_handler.h"

struct DrawCardHandler final : EffectHandler {
   protected:
    void handleImpl(entt::registry& registry, entt::entity player, entt::entity target, const Effect& e) override;

   private:
    static void drawCardsForPlayer(entt::registry& registry, entt::entity player, int count);
};
