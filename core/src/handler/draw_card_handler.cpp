#include "handler/draw_card_handler.h"

#include "util/logging.h"

void DrawCardHandler::handleImpl(entt::registry& registry, entt::entity player, entt::entity /*target*/,
                                 const Effect& e) {
    const int numCards = e.value;

    drawCardsForPlayer(registry, player, numCards);

    const auto logger = core::getLogger();
    logger->debug("Entity {} draws {} card(s).", static_cast<int>(player), numCards);
}

void DrawCardHandler::drawCardsForPlayer(entt::registry& registry, entt::entity player, int count) {
    auto& deck = registry.get<Deck>(player);
    auto& hand = registry.get<Hand>(player);

    for (int i = 0; i < count; ++i) {
        if (deck.cards.empty()) {
            break;
        }

        entt::entity cardEntity = deck.cards.back();
        deck.cards.pop_back();

        hand.cards.push_back(cardEntity);

        const auto logger = core::getLogger();
        logger->debug("Entity {} draws card {}", static_cast<int>(player), static_cast<int>(cardEntity));
    }
}
