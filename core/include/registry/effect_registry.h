#pragma once
#include <memory>
#include <unordered_map>

#include "handler/apply_vulnerable_handler.h"
#include "handler/deal_damage_handler.h"
#include "handler/draw_card_handler.h"
#include "handler/gain_block_handler.h"
#include "handler/gain_strength_handler.h"

inline static std::unordered_map<EffectType, std::shared_ptr<EffectHandler>> EffectHandlers = {
    {EffectType::GainStrength, std::make_shared<GainStrengthHandler>()},
    {EffectType::DealDamage, std::make_shared<DealDamageHandler>()},
    {EffectType::GainBlock, std::make_shared<GainBlockHandler>()},
    {EffectType::ApplyVulnerable, std::make_shared<ApplyVulnerableHandler>()},
    {EffectType::DrawCard, std::make_shared<DrawCardHandler>()},
};
