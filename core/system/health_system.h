#pragma once
#include <entt/entity/registry.hpp>

#include "event/attack.h"

class HealthSystem {
   public:
    explicit HealthSystem(entt::registry &reg);

    void onAttack(const AttackEvent &evt) const;

   private:
    entt::registry &registry;
};
