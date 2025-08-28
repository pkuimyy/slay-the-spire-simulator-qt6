#include "pch.h"

TEST(Card, Bash) {
    entt::registry registry;
    entt::dispatcher dispatcher;

//    TurnManager turnManager(dispatcher, registry);
//    turnManager.registerDefaultSystems();
//
//    const auto player = CharacterFactory::createPlayer(registry);
//    const auto enemy = CharacterFactory::createEnemy(registry);
//    const auto bashCard = CardFactory::createCard(registry, "bash");
//    const auto strikeCard = CardFactory::createCard(registry, "strike_r");
//
//    turnManager.startTurn(player);
//
//    const PlayCardEvent evt1{player, enemy, bashCard};
//    PlayCardSystem::onPlayCard(registry, evt1);
//
//    auto* h = registry.try_get<Health>(enemy);
//    ASSERT_NE(h, nullptr);
//    EXPECT_EQ(h->current, 12);
//
//    auto* vuln = registry.try_get<Vulnerable>(enemy);
//    ASSERT_NE(vuln, nullptr);
//    EXPECT_EQ(vuln->turns, 2);
//
//    const PlayCardEvent evt2{player, enemy, strikeCard};
//    PlayCardSystem::onPlayCard(registry, evt2);
//
//    EXPECT_EQ(h->current, 3);
//
//    turnManager.endTurn(player);
//    vuln = registry.try_get<Vulnerable>(enemy);
//    EXPECT_EQ(vuln->turns, 1);
}
