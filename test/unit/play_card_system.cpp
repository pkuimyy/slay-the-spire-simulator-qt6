#include "system/play_card_system.h"

#include <gtest/gtest.h>

#include <entt/entt.hpp>

#include "component/card_effects.h"
#include "component/health.h"
#include "component/strength.h"
#include "event/play_card_event.h"

TEST(EventModule, playCardSystem) {
    entt::registry registry;

    const auto player = registry.create();
    const auto enemy = registry.create();
    registry.emplace<Health>(enemy, Health{20, 20});

    const auto inflameCard = registry.create();
    registry.emplace<CardEffects>(inflameCard, CardEffects{{{CardEffects::Type::GainStrength, 2, 0}}});

    const auto strikeCard = registry.create();
    registry.emplace<CardEffects>(strikeCard, CardEffects{{{CardEffects::Type::DealDamage, 6, 1}}});

    const PlayCardEvent evt1{player, player, inflameCard};
    PlayCardSystem::onPlayCard(registry, evt1);

    auto* str = registry.try_get<Strength>(player);
    ASSERT_NE(str, nullptr);
    EXPECT_EQ(str->amount, 2);

    const PlayCardEvent evt2{player, enemy, strikeCard};
    PlayCardSystem::onPlayCard(registry, evt2);

    auto* h = registry.try_get<Health>(enemy);
    ASSERT_NE(h, nullptr);
    EXPECT_EQ(h->current, 14);
}