#pragma once
#include "pch.h"

struct HealthChangeEvent {
    entt::entity entity;
    int oldHp;
    int newHp;
};