#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

class ScoreManager {
  public:
    int score = 0;

    void AddScore(int amount) {
      score += amount;
    }

    int GetScore() const {
      return score;
    }

    void ClearScore() {
      score = 0;
    }
};

#endif  // SCOREMANAGER_HPP