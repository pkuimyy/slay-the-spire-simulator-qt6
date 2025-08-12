#include "health_system.h"

#include <iostream>

#include "component/health.h"
#include "spdlog/spdlog.h"
#include "util/logging.h"

HealthSystem::HealthSystem(entt::registry &reg) : registry(reg) {}

void HealthSystem::onAttack(const AttackEvent &evt) const {
    if (!registry.valid(evt.target)) return;

    auto *health = registry.try_get<Health>(evt.target);
    if (!health) return;

    health->current -= evt.damage;
    if (health->current < 0) health->current = 0;

    const auto &logger = core::getLogger();
    logger->debug("Entity {} took {} damage. HP: {}/{}", static_cast<int>(evt.target), evt.damage, health->current,
                  health->max);

    if (health->current == 0) {
        spdlog::debug("Entity {} died.", static_cast<int>(evt.target));
    }
}
