#include "pch.h"

TEST(System, LogSystem) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    LogSystem logSystem(dispatcher);

    BattleManager battleManager(dispatcher, registry);
    TurnManager turnManager(dispatcher, registry);

    entt::entity player = registry.create();

    battleManager.startBattle();
    turnManager.startTurn(player);
    turnManager.endTurn(player);
    turnManager.startTurn(player);
    turnManager.endTurn(player);
    battleManager.endBattle();

    std::vector<std::string> expected = {"BattleStart", "TurnStart", "TurnEnd", "TurnStart", "TurnEnd", "BattleEnd"};
    EXPECT_EQ(logSystem.getRecords(), expected);
}
