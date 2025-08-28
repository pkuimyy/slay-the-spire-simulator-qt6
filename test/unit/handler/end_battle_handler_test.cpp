#include "pch.h"

TEST(Handler, EndBattleHandler) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    BattleManager battleManager(dispatcher, registry);

    EndBattleHandler handler(dispatcher, registry, battleManager);

    EXPECT_FALSE(battleManager.isBattleEnded());

    dispatcher.trigger(BattleEndEvent{});

    EXPECT_TRUE(battleManager.isBattleEnded());

    battleManager.endBattle();

    EXPECT_TRUE(battleManager.isBattleEnded());
}
