#include "handler/handler_registry.h"

#include "handler/end_battle_handler.h"

HandlerRegistry::HandlerRegistry(entt::dispatcher& _dispatcher, entt::registry& _registry,
                                 BattleManager& _battleManager) {
    endBattleHandler = std::make_unique<EndBattleHandler>(_dispatcher, _registry, _battleManager);
    dealDamageHandler = std::make_unique<DealDamageHandler>(_dispatcher, _registry, _battleManager);
}
