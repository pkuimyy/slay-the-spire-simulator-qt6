#pragma once
#include <vector>

struct CardEffects {
    enum class Type { GainStrength, DealDamage };
    struct Effect {
        Type type;
        int value;
        int priority;
    };
    std::vector<Effect> effects;
};