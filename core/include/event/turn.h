#pragma once
#include "pch.h"

struct EndTurnEvent {
    entt::entity character;
    int turnNumber;
};

struct BeginTurnEvent {
    entt::entity character;
    int turnNumber;
};

enum class TurnPhase { BeginTurn, DrawPhase, PlayPhase, DiscardPhase, EndTurn };
