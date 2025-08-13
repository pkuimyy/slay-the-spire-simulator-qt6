#include "play_card_system.h"

#include "game/card/card.h"
#include "registry/effect_registry.h"
#include "util/logging.h"

void PlayCardSystem::onPlayCard(entt::registry& registry, const PlayCardEvent& evt) {
    const auto* cardComp = registry.try_get<Card>(evt.card);
    if (!cardComp) return;

    auto& effects = cardComp->effects.effects;  // vector<CardEffects::Effect>

    for (auto& e : effects) {
        auto it = EffectHandlers.find(e.type);
        if (it != EffectHandlers.end()) it->second->handle(registry, evt.player, evt.target, e);
    }
}
