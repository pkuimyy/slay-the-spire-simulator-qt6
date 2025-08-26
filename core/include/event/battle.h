#pragma once
#include "pch.h"

struct BattleStartEvent {
    entt::entity player;
    std::vector<entt::entity> enemies;
};

struct BattleEndEvent {
    bool playerWon;
};

struct RoundStartEvent {
    int roundNumber;
};

struct RoundEndEvent {
    int roundNumber;
};