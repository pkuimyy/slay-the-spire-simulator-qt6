#include "handler/handler_registry.h"
#include "pch.h"

TEST(Handler, EndBattleHandler) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    BattleManager battleManager(dispatcher, registry);

    HandlerRegistry handlerRegistry(dispatcher, registry, battleManager);

    EXPECT_FALSE(battleManager.isBattleEnded());

    dispatcher.trigger(BattleEndEvent{});

    EXPECT_TRUE(battleManager.isBattleEnded());

    battleManager.endBattle();

    EXPECT_TRUE(battleManager.isBattleEnded());
}
