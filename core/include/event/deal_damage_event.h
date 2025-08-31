#pragma once
#include "pch.h"

struct DealDamageEvent {
    entt::entity player;
    entt::entity target;
    Effect effect;
};