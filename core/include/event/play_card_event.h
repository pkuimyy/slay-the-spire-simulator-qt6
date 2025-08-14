#pragma once
#include "pch.h"

struct PlayCardEvent {
    entt::entity player;
    entt::entity target;
    entt::entity card;
};
