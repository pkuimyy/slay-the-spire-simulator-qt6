#pragma once
#include <stdexcept>

#include "card_database.h"
#include "entt/entt.hpp"

struct CardFactory {
    static entt::entity createCard(entt::registry& registry, const std::string& id) {
        const auto it = CardDatabase.find(id);
        if (it == CardDatabase.end()) {
            throw std::runtime_error("Card ID not found: " + id);
        }
        const entt::entity e = registry.create();
        const auto& def = it->second;
        registry.emplace<Card>(e, def);
        registry.emplace<CardEffects>(e, def.effects);
        return e;
    }
};
