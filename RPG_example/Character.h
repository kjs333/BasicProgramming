#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character {
protected:
    std::string name;
    int maxHP;
    int currentHP;
    int maxMP;
    int currentMP;
    int attack;
    int defense;
    int level;

public:
    Character(std::string name, int maxHP, int maxMP, int attack, int defense, int level = 1);
    virtual ~Character();

    // Getter 메서드
    std::string getName() const { return name; }
    int getMaxHP() const { return maxHP; }
    int getCurrentHP() const { return currentHP; }
    int getMaxMP() const { return maxMP; }
    int getCurrentMP() const { return currentMP; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getLevel() const { return level; }

    // 기본 메서드
    virtual void takeDamage(int damage);
    void heal(int amount);
    void recoverMP(int amount);
    void displayStatus() const;
    bool isAlive() const { return currentHP > 0; }
    
    // 순수 가상 함수
    virtual int attack_action() = 0;
};

#endif