#include <gtest/gtest.h>

#include <entt/entt.hpp>

#include "component/attack.h"
#include "component/health.h"
#include "event/attack.h"
#include "spdlog/spdlog.h"
#include "system/health_system.h"

void playerUseCard(entt::registry& registry, entt::dispatcher& dispatcher, entt::entity player, entt::entity enemy,
                   entt::entity card) {
    const auto* attack = registry.try_get<Attack>(card);
    if (!attack) {
        spdlog::debug("Card has no attack component!");
        return;
    }

    spdlog::debug("Player uses card dealing {} damage.", attack->damage);

    AttackEvent evt{player, enemy, attack->damage};
    dispatcher.enqueue(evt);
}

TEST(EventModule, playCard) {
    entt::registry registry;
    entt::dispatcher dispatcher;

    HealthSystem healthSystem(registry);
    dispatcher.sink<AttackEvent>().connect<&HealthSystem::onAttack>(&healthSystem);

    constexpr int oldHealth = 200;
    constexpr int attackDamage = 15;

    const auto player = registry.create();
    registry.emplace<Health>(player, Health{100, 100});
    const auto enemy = registry.create();
    registry.emplace<Health>(enemy, Health{oldHealth, 200});
    const auto card = registry.create();
    registry.emplace<Attack>(card, Attack{attackDamage});

    playerUseCard(registry, dispatcher, player, enemy, card);
    dispatcher.update();

    auto* enemyHealth = registry.try_get<Health>(enemy);
    ASSERT_NE(enemyHealth, nullptr);
    ASSERT_EQ(enemyHealth->current, oldHealth - attackDamage);
}