#include "game/turn_manager.h"
#include "pch.h"

TEST(Card, ShrugItOff) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    TurnManager turnManager(dispatcher, registry);
    turnManager.registerDefaultSystems();

    const auto player = CharacterFactory::createPlayer(registry);
    const auto enemy = CharacterFactory::createEnemy(registry);

    const auto shrugCard = CardFactory::createCard(registry, "shrug_it_off");

    turnManager.startTurn(player);

    const PlayCardEvent evt{player, enemy, shrugCard};
    PlayCardSystem::onPlayCard(registry, evt);

    auto* playerBlock = registry.try_get<Block>(player);
    ASSERT_NE(playerBlock, nullptr);
    EXPECT_EQ(playerBlock->amount, 8);

    auto* hand = registry.try_get<Hand>(player);
    ASSERT_NE(hand, nullptr);
    EXPECT_EQ(hand->cards.size(), 1);

    turnManager.endTurn(player);

    playerBlock = registry.try_get<Block>(player);
    ASSERT_NE(playerBlock, nullptr);
    EXPECT_EQ(playerBlock->amount, 0);
}