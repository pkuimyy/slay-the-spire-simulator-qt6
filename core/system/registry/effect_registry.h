#pragma once
#include <memory>
#include <unordered_map>

#include "component/card_effects.h"
#include "system/handler/deal_damage_handler.h"
#include "system/handler/gain_strength_handler.h"

inline static std::unordered_map<CardEffects::Type, std::shared_ptr<EffectHandler>> EffectHandlers = {
    {CardEffects::Type::GainStrength, std::make_shared<GainStrengthHandler>()},
    {CardEffects::Type::DealDamage, std::make_shared<DealDamageHandler>()}};
