#pragma once
#include <vector>

#include "pch.h"

struct Deck {
    std::vector<entt::entity> cards;
};

struct Hand {
    std::vector<entt::entity> cards;
};

struct Discard {
    std::vector<entt::entity> cards;
};
