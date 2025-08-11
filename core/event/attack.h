#pragma once
#include <entt/entt.hpp>

struct AttackEvent {
    entt::entity attacker;
    entt::entity target;
    int damage;
};
