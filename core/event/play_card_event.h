#pragma once
#include "entt/entt.hpp"

struct PlayCardEvent {
    entt::entity player;
    entt::entity target;
    entt::entity card;
};
