#include "GameManager.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

GameManager::GameManager() : window(sf::VideoMode(800, 600), "Flappy Bird") {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    birdTex.loadFromFile("assets/bird.png");
    pipeTex.loadFromFile("assets/pipe.png");
    bgTex.loadFromFile("assets/bgr.png");
    hitBuffer.loadFromFile("assets/hit.mp3");
    hitSound.setBuffer(hitBuffer);

    bgSprite.setTexture(bgTex);

    ui.loadFont("assets/Roboto_Condensed-Regular.ttf");
    score.load("assets/Roboto_Condensed-Regular.ttf", "assets/score.mp3");
    player.setTexture(birdTex);
    player.loadSound("assets/jump.wav");
}

void GameManager::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        if (state == GameState::PLAYING) update(dt);
        render();
    }
}

void GameManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (state == GameState::MENU) {
                    state = GameState::PLAYING;
                    resetGame();
                } else if (state == GameState::PLAYING) {
                    player.jump();
                } else if (state == GameState::GAMEOVER) {
                    // Nếu đã đủ 4 vòng thì reset bảng
                    if (roundManager.isSummaryReady()) {
                        roundManager.resetRounds();
                    }
                    state = GameState::MENU;
                }
            }

            if (state == GameState::GAMEOVER && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    if (roundManager.isSummaryReady()) {
                        roundManager.resetRounds(); // reset sau 4 vòng
                    }
                    resetGame();
                    state = GameState::PLAYING;
                }
            }
        }
    }
}

void GameManager::update(float dt) {
    player.update(dt);
    pipeSpawnTimer += dt;
    if (pipeSpawnTimer > 2.f) {
        spawnPipePair();
        pipeSpawnTimer = 0.f;
    }

    for (auto &p : pipes)
        p.update(dt);

    // Xóa cột ra khỏi màn hình
    pipes.erase(std::remove_if(pipes.begin(), pipes.end(),
        [](Pipe &p) { return p.getPosition().x + p.getWidth() < 0; }),
        pipes.end());

    // Kiểm tra va chạm & tính điểm
    for (auto &p : pipes) {
        if (player.getBounds().intersects(p.getBounds())) {
            state = GameState::GAMEOVER;
            hitSound.play();
            roundManager.addRoundScore(score.getScore());
        }

        if (!p.isScored() && p.getPosition().x + p.getWidth() < player.getPosition().x) {
            p.markScored();
            if (!p.isTop()) score.add(1);
        }
    }

    // Nếu chim rơi xuống đất
    if (player.getPosition().y > window.getSize().y - 20.f) {
        state = GameState::GAMEOVER;
        hitSound.play();
        roundManager.addRoundScore(score.getScore());
    }
}

void GameManager::render() {
    window.clear();
    window.draw(bgSprite);

    for (auto &p : pipes)
        p.draw(window);

    player.draw(window);
    score.draw(window);

    if (state == GameState::MENU)
        ui.drawStartText(window);

    if (state == GameState::GAMEOVER) {
        ui.drawGameOver(window);

        // ✅ Hiển thị bảng tổng kết nếu đã đủ 4 vòng
        if (roundManager.isSummaryReady()) {
            roundManager.drawSummary(window);
        }
    }

    window.display(); // ✅ gọi sau cùng
}


void GameManager::spawnPipePair() {
    pipes.emplace_back(pipeTex, true);
    pipes.emplace_back(pipeTex, false);
}

void GameManager::resetGame() {
    pipes.clear();
    score.reset();
    player.reset(); // ✅ reset player
    pipeSpawnTimer = 0.f;
}
