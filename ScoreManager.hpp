#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

class ScoreManager {
private:
    int score = 0;
    sf::Font font;
    sf::SoundBuffer pointBuffer;
    sf::Sound pointSound;
public:
    ScoreManager() = default;

    void load(const std::string& fontPath, const std::string& pointSoundPath) {
        font.loadFromFile(fontPath);
        pointBuffer.loadFromFile(pointSoundPath);
        pointSound.setBuffer(pointBuffer);
    }

    void add(int val) {
        score += val;
        pointSound.play();
    }
    int getScore() const { return score; }
    void reset() { score = 0; }

    void draw(sf::RenderWindow& window) {
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString("Score: " + std::to_string(score));
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10.f, 10.f);
        window.draw(scoreText);
    }
};
