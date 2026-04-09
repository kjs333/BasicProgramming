#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
private:
    int experience;
    int nextLevelExp;
    int gold;

public:
    Player(std::string name);
    ~Player();

    // Getter 메서드
    int getExperience() const { return experience; }
    int getNextLevelExp() const { return nextLevelExp; }
    int getGold() const { return gold; }

    // 경험치 및 레벨 관련
    void gainExperience(int exp);
    void levelUp();
    bool checkLevelUp();

    // 골드 관련
    void addGold(int amount) { gold += amount; }

    // 행동
    int attack_action() override;
    void displayFullStatus() const;
};

#endif