#pragma once
#include "entt/entity/entity.hpp"

struct PlayCardEvent {
    entt::entity player;
    entt::entity target;
    entt::entity card;
};
