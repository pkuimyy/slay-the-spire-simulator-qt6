#pragma once
#include "component/effect.h"
#include "pch.h"

struct PlayCardEvent {
    entt::entity player;
    entt::entity target;
    entt::entity card;
    Effect effect;
};
