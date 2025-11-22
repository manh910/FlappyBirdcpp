#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class RoundManager {
private:
    std::vector<int> roundScores;       // Lưu điểm các vòng
    bool summaryReady;                   // Kiểm tra có hiển thị summary không
    sf::Font font;
    sf::Text summaryText;
    sf::RectangleShape background;

public:
    RoundManager();

    void addRoundScore(int score);       // Thêm điểm vòng mới
    bool isSummaryReady() const;         // Kiểm tra summary đã sẵn sàng chưa
    void resetRounds();                  // Reset toàn bộ điểm
    void clearSummary();                 // Tắt bảng summary
    void drawSummary(sf::RenderWindow& window); // Vẽ bảng summary
};
