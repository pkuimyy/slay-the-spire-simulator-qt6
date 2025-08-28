#include "pch.h"

TEST(Handler, DealDamageHandler) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    entt::entity player = CharacterFactory::createPlayer(registry, 20, 20);
    entt::entity enemy = CharacterFactory::createEnemy(registry, 10, 10);

    BattleManager battleManager(dispatcher, registry);
    DealDamageHandler damageHandler(dispatcher, registry, battleManager);
    [[maybe_unused]] EndBattleHandler endBattleHandler(dispatcher, registry, battleManager);

    Effect dmgEffect;
    dmgEffect.value = 6;

    damageHandler.handle(player, enemy, dmgEffect);

    auto* health = registry.try_get<Health>(enemy);
    ASSERT_NE(health, nullptr);
    EXPECT_EQ(health->current, 4);

    EXPECT_FALSE(battleManager.isBattleEnded());

    damageHandler.handle(player, enemy, dmgEffect);

    health = registry.try_get<Health>(enemy);
    ASSERT_NE(health, nullptr);
    EXPECT_EQ(health->current, 0);

    EXPECT_TRUE(battleManager.isBattleEnded());
}