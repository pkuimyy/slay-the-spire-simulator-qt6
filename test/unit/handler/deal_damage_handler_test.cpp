#include "handler/handler_registry.h"
#include "pch.h"

TEST(Handler, DealDamageHandler) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    const entt::entity player = CharacterFactory::createPlayer(registry, 20, 20);
    const entt::entity enemy = CharacterFactory::createEnemy(registry, 10, 10);

    BattleManager battleManager(dispatcher, registry);
    HandlerRegistry handlerRegistry(dispatcher, registry, battleManager);

    Effect dmgEffect;
    dmgEffect.value = 6;

    dispatcher.trigger(DealDamageEvent{player, enemy, dmgEffect});

    auto* health = registry.try_get<Health>(enemy);
    ASSERT_NE(health, nullptr);
    EXPECT_EQ(health->current, 4);

    EXPECT_FALSE(battleManager.isBattleEnded());

    dispatcher.trigger(DealDamageEvent{player, enemy, dmgEffect});

    health = registry.try_get<Health>(enemy);
    ASSERT_NE(health, nullptr);
    EXPECT_EQ(health->current, 0);

    EXPECT_TRUE(battleManager.isBattleEnded());
}