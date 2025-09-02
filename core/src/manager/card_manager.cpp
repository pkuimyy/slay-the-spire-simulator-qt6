#include "manager/card_manager.h"

CardManager& CardManager::GetInstance() {
    static CardManager instance;
    return instance;
}

void CardManager::loadAllCards(const std::string& folderPath) {
    namespace fs = std::filesystem;
    for (auto& p : fs::directory_iterator(folderPath)) {
        if (p.path().extension() != ".json") continue;
        std::ifstream file(p.path());
        if (!file.is_open()) continue;

        nlohmann::json j;
        file >> j;

        Card card;
        card.id = j["id"].get<std::string>();
        card.name = j["name"].get<std::string>();
        card.cost = j["cost"].get<int>();
        for (auto& e : j["effects"]) {
            Effect effect;
            effect.type = stringToEffectType(e["type"].get<std::string>());
            effect.value = e["value"].get<int>();
            effect.priority = e["priority"].get<int>();
            effect.phase = stringToPhase(e["phase"].get<std::string>());
            card.effects.effects.push_back(effect);
        }

        cards.emplace(card.id, std::move(card));
    }
}

const Card* CardManager::getCard(const std::string& id) {
    auto it = cards.find(id);
    if (it != cards.end()) return &it->second;
    return nullptr;
}
