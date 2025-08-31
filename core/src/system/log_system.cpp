#include "system/log_system.h"

LogSystem::LogSystem(entt::dispatcher& disp) {
    disp.sink<BattleStartEvent>().connect<&LogSystem::onBattleStart>(*this);
    disp.sink<BattleEndEvent>().connect<&LogSystem::onBattleEnd>(*this);

    disp.sink<TurnStartEvent>().connect<&LogSystem::onTurnStart>(*this);
    disp.sink<TurnEndEvent>().connect<&LogSystem::onTurnEnd>(*this);
}

void LogSystem::onBattleStart(const BattleStartEvent&) {
    core::getLogger()->info("Battle started!");
    records.emplace_back("BattleStart");
}
void LogSystem::onBattleEnd(const BattleEndEvent&) {
    core::getLogger()->info("Battle ended!");
    records.emplace_back("BattleEnd");
}

void LogSystem::onTurnStart(const TurnStartEvent& evt) {
    core::getLogger()->info("Turn {} started for entity {}", evt.turnNumber, static_cast<int>(evt.character));
    records.emplace_back("TurnStart");
}

void LogSystem::onTurnEnd(const TurnEndEvent& evt) {
    core::getLogger()->info("Turn {} ended for entity {}", evt.turnNumber, static_cast<int>(evt.character));
    records.emplace_back("TurnEnd");
}

const std::vector<std::string>& LogSystem::getRecords() {
    return records;
}
void LogSystem::clear() {
    records.clear();
}
