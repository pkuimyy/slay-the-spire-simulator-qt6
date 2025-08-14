#pragma once
#include "component/health.h"
#include "component/strength.h"

struct CharacterFactory {
    static entt::entity createPlayer(entt::registry& registry, const int hp = 20, const int maxHp = 20) {
        const entt::entity e = registry.create();
        registry.emplace<Health>(e, Health{hp, maxHp});
        registry.emplace<Strength>(e, Strength{0});

        auto& hand = registry.emplace<Hand>(e);
        hand.cards.clear();

        auto& deck = registry.emplace<Deck>(e);
        deck.cards.clear();
        deck.cards.push_back(CardFactory::createCard(registry, "strike_r"));
        deck.cards.push_back(CardFactory::createCard(registry, "strike_r"));
        deck.cards.push_back(CardFactory::createCard(registry, "strike_r"));
        deck.cards.push_back(CardFactory::createCard(registry, "strike_r"));
        deck.cards.push_back(CardFactory::createCard(registry, "strike_r"));

        registry.emplace<Discard>(e);
        return e;
    }

    static entt::entity createEnemy(entt::registry& registry, const int hp = 20, const int maxHp = 20) {
        const entt::entity e = registry.create();
        registry.emplace<Health>(e, Health{hp, maxHp});
        return e;
    }
};
