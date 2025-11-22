#include "RoundManager.hpp"
#include <sstream>

RoundManager::RoundManager() {
    // Load font
    if (!font.loadFromFile("assets/Roboto_Condensed-Regular.ttf")) {
        // Nếu font không load được, có thể log hoặc dùng font mặc định
    }

    // Text hiển thị summary
    summaryText.setFont(font);
    summaryText.setCharacterSize(24);
    summaryText.setFillColor(sf::Color::White);
    summaryText.setPosition(200.f, 180.f);

    // Nền mờ phía sau text
    background.setSize(sf::Vector2f(400.f, 250.f));
    background.setFillColor(sf::Color(0, 0, 0, 150)); // mờ đen
    background.setPosition(200.f, 150.f);

    summaryReady = false;
}

void RoundManager::addRoundScore(int score) {
    roundScores.push_back(score);
    summaryReady = true; // luôn sẵn sàng hiển thị summary sau mỗi vòng
}

bool RoundManager::isSummaryReady() const {
    return summaryReady;
}

void RoundManager::resetRounds() {
    roundScores.clear();
    summaryReady = false;
}

void RoundManager::clearSummary() {
    summaryReady = false; // tắt bảng summary
}

void RoundManager::drawSummary(sf::RenderWindow& window) {
    if (!summaryReady || roundScores.empty()) return;

    // Vẽ nền trước
    window.draw(background);

    // Tạo nội dung bảng summary
    std::stringstream ss;
    int lastIndex = roundScores.size() - 1;
    int total = 0;
    for (size_t i = 0; i < roundScores.size(); ++i) {
        total += roundScores[i];
    }

    ss << "ROUND " << (lastIndex + 1) << "\n";
    ss << "Score: " << roundScores[lastIndex] << "\n";
    ss << "TOTAL: " << total;

    summaryText.setString(ss.str());

    // Vẽ text lên màn hình
    window.draw(summaryText);
}
