#include "Character.h"
#include <algorithm>

Character::Character(std::string name, int maxHP, int maxMP, int attack, int defense, int level)
    : name(name), maxHP(maxHP), currentHP(maxHP), maxMP(maxMP), 
      currentMP(maxMP), attack(attack), defense(defense), level(level) {}

Character::~Character() {}

void Character::takeDamage(int damage) {
    int actualDamage = damage - (defense / 2);
    actualDamage = std::max(1, actualDamage);  // 최소 1의 데미지
    currentHP -= actualDamage;
    if (currentHP < 0) currentHP = 0;
}

void Character::heal(int amount) {
    currentHP += amount;
    if (currentHP > maxHP) currentHP = maxHP;
}

void Character::recoverMP(int amount) {
    currentMP += amount;
    if (currentMP > maxMP) currentMP = maxMP;
}

void Character::displayStatus() const {
    std::cout << "─────────────────────────" << std::endl;
    std::cout << "이름: " << name << std::endl;
    std::cout << "레벨: " << level << std::endl;
    std::cout << "HP: " << currentHP << "/" << maxHP << std::endl;
    std::cout << "MP: " << currentMP << "/" << maxMP << std::endl;
    std::cout << "공격력: " << attack << " | 방어력: " << defense << std::endl;
    std::cout << "─────────────────────────" << std::endl;
}