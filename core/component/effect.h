#pragma once
#include <vector>

enum class EffectType { GainStrength, DealDamage, GainBlock };

enum class CardPlayPhase : int { PrePlay, OnPlay, PostPlay };

struct Effect {
    EffectType type = EffectType::DealDamage;
    int value{};
    int priority{};
    CardPlayPhase phase = CardPlayPhase::OnPlay;
};

struct CardEffects {
    std::vector<Effect> effects;
};