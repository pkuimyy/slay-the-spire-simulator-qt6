#pragma once
#include <string>
#include <unordered_map>

#include "card.h"

inline const std::unordered_map<std::string, Card> CardDatabase = {
    {"inflame", {"inflame", "Inflame", 1, CardEffects{{{EffectType::GainStrength, 2, 0}}}}},
    {"strike_r", {"strike_r", "Strike R", 1, CardEffects{{{EffectType::DealDamage, 6, 1}}}}},
    {"gain_block", {"gain_block", "Gain Block", 1, CardEffects{{{EffectType::GainBlock, 5, 1}}}}},
    {"bash", {"bash", "Bash", 2, CardEffects{{{EffectType::DealDamage, 8, 1}, {EffectType::ApplyVulnerable, 2, 2}}}}},
    {"shrug_it_off",
     {"shrug_it_off", "Shrug It Off", 1, CardEffects{{{EffectType::GainBlock, 8, 1}, {EffectType::DrawCard, 1, 1}}}}}};
