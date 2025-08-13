#include "system/play_card_system.h"

#include <gtest/gtest.h>

#include <entt/entt.hpp>

#include "component/health.h"
#include "component/strength.h"
#include "event/play_card_event.h"
#include "game/card/card_database.h"
#include "game/card/card_factory.h"
#include "game/character/character_factory.h"

TEST(EventModule, playCardSystem) {
    entt::registry registry;

    const auto player = CharacterFactory::createPlayer(registry);
    const auto enemy = CharacterFactory::createEnemy(registry);

    const auto inflameCard = CardFactory::createCard(registry, "inflame");
    const auto strikeCard = CardFactory::createCard(registry, "strike_r");

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