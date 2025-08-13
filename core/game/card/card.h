#pragma once
#include <string>

#include "component/effect.h"

struct Card {
    std::string id;    // "inflame", "strike_r"
    std::string name;  // "Inflame", "Strike R"
    int cost;          // 1, 2, etc.
    CardEffects effects;
};
