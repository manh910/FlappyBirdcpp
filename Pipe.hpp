#pragma once
#include <SFML/Graphics.hpp>

class Pipe {
private:
    sf::Sprite sprite;
    bool topPipe;
    bool scored = false;
public:
    Pipe(const sf::Texture& tex, bool top);

    void update(float dt) { sprite.move(-200.f * dt, 0.f); }
    void draw(sf::RenderWindow& window) { window.draw(sprite); }

    sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
    sf::Vector2f getPosition() const { return sprite.getPosition(); }
    float getWidth() const { return sprite.getGlobalBounds().width; }

    bool isTop() const { return topPipe; }
    bool isScored() const { return scored; }
    void markScored() { scored = true; }
};
