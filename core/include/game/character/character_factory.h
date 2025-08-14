#pragma once
#include "component/health.h"
#include "component/strength.h"

struct CharacterFactory {
    static entt::entity createPlayer(entt::registry& registry, const int hp = 20, const int maxHp = 20) {
        const entt::entity e = registry.create();
        registry.emplace<Health>(e, Health{hp, maxHp});
        registry.emplace<Strength>(e, Strength{0});
        return e;
    }

    static entt::entity createEnemy(entt::registry& registry, const int hp = 20, const int maxHp = 20) {
        const entt::entity e = registry.create();
        registry.emplace<Health>(e, Health{hp, maxHp});
        return e;
    }
};
