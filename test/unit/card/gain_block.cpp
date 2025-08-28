#include "pch.h"

TEST(Card, playCardGainBlock) {
    entt::registry registry;
    entt::dispatcher dispatcher;

//    TurnManager turnManager(dispatcher, registry);
//    turnManager.registerDefaultSystems();
//
//    const auto player = CharacterFactory::createPlayer(registry);
//    const auto blockCard = CardFactory::createCard(registry, "gain_block");
//
//    auto* block = registry.try_get<Block>(player);
//    EXPECT_TRUE(block == nullptr || block->amount == 0);
//
//    const PlayCardEvent evt1{player, player, blockCard};
//    PlayCardSystem::onPlayCard(registry, evt1);
//
//    block = registry.try_get<Block>(player);
//    ASSERT_NE(block, nullptr);
//    EXPECT_EQ(block->amount, 5);
//
//    turnManager.endTurn(player);
//    block = registry.try_get<Block>(player);
//    EXPECT_EQ(block->amount, 0);
}
