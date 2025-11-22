#include "UI.hpp"
#include <iostream>

bool UI::loadFont(const std::string &path) {
    if (!font.loadFromFile(path)) {
        std::cerr << "⚠️ Warning: Could not load font from " << path << std::endl;
        return false;
    }
    return true;
}

void UI::drawScore(sf::RenderWindow &window, int currentScore, int highScore) {
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(currentScore));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 10.f);

    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setString("High Score: " + std::to_string(highScore));
    highScoreText.setCharacterSize(20);
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setPosition(10.f, 40.f);

    window.draw(scoreText);
    window.draw(highScoreText);
}

void UI::drawStartText(sf::RenderWindow &window) {
    sf::Text startText;
    startText.setFont(font);
    startText.setString("Press SPACE to start");
    startText.setCharacterSize(28);
    startText.setFillColor(sf::Color::Cyan);
    startText.setPosition(60.f, 300.f);

    window.draw(startText);
}

void UI::drawGameOver(sf::RenderWindow &window) {
    sf::Text overText;
    overText.setFont(font);
    overText.setString("GAME OVER!");
    overText.setCharacterSize(40);
    overText.setFillColor(sf::Color::Red);
    overText.setPosition(80.f, 250.f);

    window.draw(overText);
}
