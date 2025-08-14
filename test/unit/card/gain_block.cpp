#include <entt/entt.hpp>

#include "component/block.h"
#include "game/card/card_factory.h"
#include "game/character/character_factory.h"
#include "gtest/gtest.h"
#include "system/end_turn_system.h"
#include "system/play_card_system.h"

TEST(Card, playCardGainBlock) {
    entt::registry registry;

    const auto player = CharacterFactory::createPlayer(registry);
    const auto blockCard = CardFactory::createCard(registry, "gain_block");

    auto* block = registry.try_get<Block>(player);
    EXPECT_TRUE(block == nullptr || block->amount == 0);

    const PlayCardEvent evt1{player, player, blockCard};
    PlayCardSystem::onPlayCard(registry, evt1);

    block = registry.try_get<Block>(player);
    ASSERT_NE(block, nullptr);
    EXPECT_EQ(block->amount, 5);

    EndTurnSystem::onEndTurn(registry);
    EXPECT_EQ(block->amount, 0);
}
