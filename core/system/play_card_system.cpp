#include "play_card_system.h"

#include <algorithm>

#include "component/card_effects.h"
#include "component/health.h"
#include "component/strength.h"
#include "util/logging.h"

void PlayCardSystem::onPlayCard(entt::registry& registry, const PlayCardEvent evt) {
    auto& effects = registry.get<CardEffects>(evt.card);

    std::vector<CardEffects::Effect> sortedEffects = effects.effects;
    std::sort(sortedEffects.begin(), sortedEffects.end(),
              [](const auto& a, const auto& b) { return a.priority < b.priority; });

    auto logger = core::getLogger();
    for (auto& e : sortedEffects) {
        switch (e.type) {
            case CardEffects::Type::GainStrength: {
                auto& str = registry.get_or_emplace<Strength>(evt.player);
                str.amount += e.value;
                logger->debug("Player gained {} Strength. Total = {}", e.value, str.amount);
                break;
            }
            case CardEffects::Type::DealDamage: {
                auto* health = registry.try_get<Health>(evt.target);
                if (!health) break;
                health->current -= e.value;
                if (health->current < 0) health->current = 0;
                logger->debug("Target took {} damage, HP = {}/{}", e.value, health->current, health->max);
                break;
            }
        }
    }
}
