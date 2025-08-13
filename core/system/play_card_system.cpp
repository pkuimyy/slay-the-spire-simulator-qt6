#include "play_card_system.h"

#include "game/card/card.h"
#include "registry/effect_registry.h"

void PlayCardSystem::onPlayCard(entt::registry& registry, const PlayCardEvent& evt) {
    const auto& logger = core::getLogger();

    const auto* cardComp = registry.try_get<Card>(evt.card);
    if (!cardComp) return;

    std::unordered_map<CardPlayPhase, std::vector<Effect>> phaseMap;
    for (auto& e : cardComp->effects.effects) {
        phaseMap[e.phase].push_back(e);
    }

    for (auto& [phase, effects] : phaseMap) {
        std::sort(effects.begin(), effects.end(), [](const auto& a, const auto& b) { return a.priority < b.priority; });
    }

    for (auto phase : {CardPlayPhase::PrePlay, CardPlayPhase::OnPlay, CardPlayPhase::PostPlay}) {
        auto it = phaseMap.find(phase);
        if (it == phaseMap.end()) continue;

        for (auto& e : it->second) {
            auto handlerIt = EffectHandlers.find(e.type);
            if (handlerIt != EffectHandlers.end()) {
                handlerIt->second->handle(registry, evt.player, evt.target, e);
            } else {
                logger->warn("No handler registered for effect type {}", static_cast<int>(e.type));
            }
        }
    }
}
