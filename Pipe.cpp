#include "Pipe.hpp"
#include <cstdlib>

Pipe::Pipe(const sf::Texture& tex, bool top) : topPipe(top) {
    sprite.setTexture(tex);

    // 🎯 Khoảng cách giữa 2 cột — bạn có thể chỉnh giá trị này
    const float gap = 250.f;

    // 🎯 Tọa độ Y ngẫu nhiên cho tâm khoảng trống
    const float yCenter = static_cast<float>(std::rand() % 200 + 200); // 200–400

    // 🎯 Chiều cao thật của texture (không bị scale ảnh hưởng)
    const float texHeight = static_cast<float>(tex.getSize().y);

    if (topPipe) {
        // Ống trên lộn ngược (đặt sát mép trên khoảng trống)
        sprite.setScale(1.f, -1.f);
        sprite.setPosition(800.f, yCenter - gap / 2.f);
    } else {
        // Ống dưới bình thường (đặt sát mép dưới khoảng trống)
        sprite.setScale(1.f, 1.f);
        sprite.setPosition(800.f, yCenter + gap / 2.f);
    }
}

