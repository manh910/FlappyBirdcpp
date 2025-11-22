//
//#ifndef SCOREMANAGER_HPP
//#define SCOREMANAGER_HPP
//
//#include <iostream>
//#include <fstream>
//#include <stdexcept>
//#include <string>
//
//class ScoreManager {
//private:
//    int highScore;
//
//public:
//    ScoreManager() : highScore(0) {}
//
//    int getHighScore() const {
//        return highScore;
//    }
//
//    void setHighScore(int score) {
//        if (score > highScore) {
//            highScore = score;
//        }
//    }
//
//    // Tải điểm cao từ file
//    void load(const std::string &path) {
//        std::ifstream file(path);
//        if (!file.is_open()) {
//            throw std::runtime_error("scores.txt not found");
//        }
//
//        if (!(file >> highScore)) {
//            throw std::runtime_error("scores.txt corrupted");
//        }
//        file.close();
//    }
//
//    // Ghi điểm cao ra file
//    void save(const std::string &path) const {
//        std::ofstream file(path);
//        if (!file.is_open()) {
//            throw std::runtime_error("Unable to write scores.txt");
//        }
//        file << highScore;
//        file.close();
//    }
//};
//
//#endif
