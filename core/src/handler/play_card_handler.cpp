#include "handler/play_card_handler.h"

PlayCardHandler::PlayCardHandler(entt::dispatcher& dispatcher, entt::registry& registry, BattleManager& battleManager)
    : EventHandler(dispatcher, registry, battleManager) {
    dispatcher.sink<PlayCardEvent>().connect<&PlayCardHandler::onPlayCard>(this);
}
void PlayCardHandler::onPlayCard(const PlayCardEvent& event) {
    handle(event.player, event.target, event.effect);
}

void PlayCardHandler::handleImpl(entt::entity player, entt::entity target, const Effect& e) {}