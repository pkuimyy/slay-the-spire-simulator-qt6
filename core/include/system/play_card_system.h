#pragma once
#include "event/play_card_event.h"
#include "util/logging.h"

class PlayCardSystem {
   public:
    static void onPlayCard(entt::registry& registry, const PlayCardEvent& evt);
};