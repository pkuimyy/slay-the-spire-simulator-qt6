#pragma once
#include <memory>
#include <unordered_map>

#include "handler/apply_vulnerable_handler.h"
#include "handler/deal_damage_handler.h"
#include "handler/draw_card_handler.h"
#include "handler/effect_handler.h"
#include "handler/gain_block_handler.h"
#include "handler/gain_strength_handler.h"

inline std::unordered_map<EffectType, std::shared_ptr<EffectHandler>>& getEffectHandlers() {
    static std::unordered_map<EffectType, std::shared_ptr<EffectHandler>> handlers;

    static bool initialized = false;
    if (!initialized) {
        handlers.emplace(EffectType::DealDamage, std::make_shared<DealDamageHandler>());
        handlers.emplace(EffectType::GainStrength, std::make_shared<GainStrengthHandler>());
        handlers.emplace(EffectType::GainBlock, std::make_shared<GainBlockHandler>());
        handlers.emplace(EffectType::ApplyVulnerable, std::make_shared<ApplyVulnerableHandler>());
        handlers.emplace(EffectType::DrawCard, std::make_shared<DrawCardHandler>());
        initialized = true;
    }

    return handlers;
}
