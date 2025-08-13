#pragma once
#include <string>
#include <unordered_map>

#include "card.h"

inline const std::unordered_map<std::string, Card> CardDatabase = {
    {"inflame", {"inflame", "Inflame", 1, CardEffects{{{CardEffects::Type::GainStrength, 2, 0}}}}},
    {"strike_r", {"strike_r", "Strike R", 1, CardEffects{{{CardEffects::Type::DealDamage, 6, 1}}}}}};
