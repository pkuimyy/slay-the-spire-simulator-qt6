#include <core/public_api.h>

#include <cassert>
#include <iostream>

int main() {
    entt::registry registry;

    const auto player = CharacterFactory::createPlayer(registry);
    const auto enemy = CharacterFactory::createEnemy(registry);
    const auto bashCard = CardFactory::createCard(registry, "bash");
    const auto strikeCard = CardFactory::createCard(registry, "strike_r");

    const PlayCardEvent evt1{player, enemy, bashCard};
    PlayCardSystem::onPlayCard(registry, evt1);

    auto* h = registry.try_get<Health>(enemy);
    assert(h != nullptr);
    assert(h->current == 12);

    auto* vuln = registry.try_get<Vulnerable>(enemy);
    assert(vuln != nullptr);
    assert(vuln->turns == 2);

    const PlayCardEvent evt2{player, enemy, strikeCard};
    PlayCardSystem::onPlayCard(registry, evt2);

    assert(h->current == 3);

    EndTurnSystem::onEndTurn(registry);
    assert(vuln->turns == 1);
}
