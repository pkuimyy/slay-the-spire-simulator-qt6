#include "handler/apply_vulnerable_handler.h"

#include "component/vulnerable.h"
#include "util/logging.h"

void ApplyVulnerableHandler::handleImpl(entt::registry& registry, entt::entity /*player*/, entt::entity target,
                                        const Effect& e) {
    auto& vuln = registry.get_or_emplace<Vulnerable>(target);
    vuln.turns += e.value;

    const auto logger = core::getLogger();
    logger->debug("Entity {} gained {} turns of Vulnerable (total: {}).", static_cast<int>(target), e.value,
                  vuln.turns);
}