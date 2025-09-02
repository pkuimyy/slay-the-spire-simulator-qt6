#pragma once
#include "event/play_card_event.h"
#include "handler/event_handler.h"
#include "manager/battle_manager.h"

class PlayCardHandler final : public EventHandler {
   public:
    PlayCardHandler(entt::dispatcher& dispatcher, entt::registry& registry, BattleManager& battleManager);

    void onPlayCard(const PlayCardEvent& event);

   protected:
    void handleImpl(entt::entity player, entt::entity target, const Effect& e) override;
};