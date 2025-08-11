#include "health_system.h"

#include <iostream>

#include "component/health.h"

HealthSystem::HealthSystem(entt::registry &reg) : registry(reg) {}

void HealthSystem::onAttack(const AttackEvent &evt) const {
    if (!registry.valid(evt.target)) return;

    auto *health = registry.try_get<Health>(evt.target);
    if (!health) return;

    health->current -= evt.damage;
    if (health->current < 0) health->current = 0;

    std::cout << "Entity " << static_cast<int>(evt.target) << " took " << evt.damage
              << " damage. HP: " << health->current << "/" << health->max << "\n";

    if (health->current == 0) {
        std::cout << "Entity " << static_cast<int>(evt.target) << " died.\n";
    }
}
