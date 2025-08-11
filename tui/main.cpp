#include <entt/entt.hpp>
#include <iostream>

#include "attack.h"
#include "event/attack.h"
#include "health.h"
#include "health_system.h"

void playerUseCard(entt::registry& registry, entt::dispatcher& dispatcher, const entt::entity player,
                   const entt::entity enemy, const entt::entity card) {
    const auto* attack = registry.try_get<Attack>(card);
    if (!attack) {
        std::cout << "Card has no attack component!\n";
        return;
    }

    std::cout << "Player uses card dealing " << attack->damage << " damage.\n";

    AttackEvent evt{player, enemy, attack->damage};
    dispatcher.enqueue(evt);
}

int main() {
    entt::registry registry;
    entt::dispatcher dispatcher;

    HealthSystem healthSystem(registry);
    dispatcher.sink<AttackEvent>().connect<&HealthSystem::onAttack>(&healthSystem);

    const auto player = registry.create();
    registry.emplace<Health>(player, Health{100, 100});

    const auto enemy = registry.create();
    registry.emplace<Health>(enemy, Health{50, 50});

    const auto card = registry.create();
    registry.emplace<Attack>(card, Attack{15});

    playerUseCard(registry, dispatcher, player, enemy, card);

    dispatcher.update();

    return 0;
}
