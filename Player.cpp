//#include "Player.hpp"
//
//Player::Player() : velocity(0.f), gravity(600.f) {}
//
//void Player::setTexture(const sf::Texture& tex) {
//    sprite.setTexture(tex);
//    sprite.setPosition(200.f, 300.f);
//}
//
//void Player::update(float dt) {
//    velocity += gravity * dt;
//    sprite.move(0, velocity * dt);
//
//    // Giới hạn không bay quá trần
//    if (sprite.getPosition().y < 0)
//        sprite.setPosition(sprite.getPosition().x, 0);
//}
//
//void Player::draw(sf::RenderWindow& window) {
//    window.draw(sprite);
//}
//
//void Player::jump() {
//    velocity = -300.f;
//}
//
//sf::FloatRect Player::getBounds() const {
//    return sprite.getGlobalBounds();
//}
//
//sf::Vector2f Player::getPosition() const {
//    return sprite.getPosition();
//}
