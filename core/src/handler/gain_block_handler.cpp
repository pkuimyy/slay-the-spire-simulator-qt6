#include "handler/gain_block_handler.h"

#include "util/logging.h"

void GainBlockHandler::handleImpl(entt::registry& registry, entt::entity player, entt::entity /*target*/,
                                  const Effect& e) {
    auto& block = registry.get_or_emplace<Block>(player);
    block.amount += e.value;

    const auto logger = core::getLogger();
    logger->debug("Player {} gained {} block. Block = {}", static_cast<int>(player), e.value, block.amount);
}
