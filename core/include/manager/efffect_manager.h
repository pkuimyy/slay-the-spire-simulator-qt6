#pragma once

class EffectManager {
   public:
    static EffectType toEffectType(const std::string& str);
    static std::string toString(EffectType type);

    static CardPlayPhase toPhase(const std::string& str);
    static std::string toString(CardPlayPhase phase);

   private:
    static const std::unordered_map<std::string, EffectType> strToEffect;
    static const std::unordered_map<EffectType, std::string> effectToStr;

    static const std::unordered_map<std::string, CardPlayPhase> strToPhase;
    static const std::unordered_map<CardPlayPhase, std::string> phaseToStr;
};