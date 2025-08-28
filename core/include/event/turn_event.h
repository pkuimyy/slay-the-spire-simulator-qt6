#pragma once
#include "pch.h"

struct TurnStartEvent {
    entt::entity character;
    int turnNumber;
};

struct TurnEndEvent {
    entt::entity character;
    int turnNumber;
};