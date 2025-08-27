#include "handler/gain_strength_handler.h"

#include "util/logging.h"

void GainStrengthHandler::handleImpl(entt::registry& registry, entt::entity player, entt::entity /*target*/,
                                     const Effect& e) {
    auto& str = registry.get_or_emplace<Strength>(player);
    str.amount += e.value;

    const auto logger = core::getLogger();
    logger->debug("Player {} gained {} Strength. Total = {}", static_cast<int>(player), e.value, str.amount);
}
