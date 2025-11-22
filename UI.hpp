#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class UI {
private:
    sf::Font font;

public:
    // Chỉ khai báo hàm, KHÔNG định nghĩa ở đây
    bool loadFont(const std::string &path);

    void drawScore(sf::RenderWindow &window, int currentScore, int highScore);
    void drawStartText(sf::RenderWindow &window);
    void drawGameOver(sf::RenderWindow &window);
};
