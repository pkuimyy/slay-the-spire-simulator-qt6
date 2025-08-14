#pragma once
#include "pch.h"

struct AttackEvent {
    entt::entity attacker;
    entt::entity target;
    int damage;
};
