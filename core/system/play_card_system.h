#pragma once
#include "entt/entt.hpp"
#include "event/play_card_event.h"

class PlayCardSystem {
   public:
    static void onPlayCard(entt::registry& registry, const PlayCardEvent evt);
};