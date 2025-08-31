#include "handler/end_battle_handler.h"

EndBattleHandler::EndBattleHandler(entt::dispatcher& _dispatcher, entt::registry& _registry,
                                   BattleManager& _battleManager)
    : dispatcher(_dispatcher), registry(_registry), battleManager(_battleManager) {
    dispatcher.sink<BattleEndEvent>().connect<&EndBattleHandler::onBattleEnd>(*this);
}

void EndBattleHandler::onBattleEnd(const BattleEndEvent&) const {
    if (battleManager.isBattleEnded()) {
        return;
    }
    battleManager.setBattleEnded(true);
    core::getLogger()->debug("Battle ended. EndBattleHandler set battle state to ended.");
}
