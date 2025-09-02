#pragma once

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

#include "game/card/card.h"

class CardManager {
   public:
    static CardManager& GetInstance();

    void loadAllCards(const std::string& folderPath);

    const Card* getCard(const std::string& id);

   private:
    CardManager() = default;
    std::unordered_map<std::string, Card> cards;
};