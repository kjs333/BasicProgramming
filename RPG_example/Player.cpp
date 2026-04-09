#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player(std::string name)
    : Character(name, 100, 50, 15, 5, 1), 
      experience(0), nextLevelExp(100), gold(0) {}

Player::~Player() {}

void Player::gainExperience(int exp) {
    experience += exp;
    std::cout << name << "이(가) " << exp << "의 경험치를 획득했습니다!" << std::endl;
    
    if (checkLevelUp()) {
        levelUp();
    }
}

bool Player::checkLevelUp() {
    return experience >= nextLevelExp;
}

void Player::levelUp() {
    level++;
    experience = 0;
    nextLevelExp = 100 + (level - 1) * 50;
    
    maxHP += 20;
    currentHP = maxHP;
    maxMP += 10;
    currentMP = maxMP;
    attack += 5;
    defense += 2;
    
    std::cout << "\n╔════════════════════════╗" << std::endl;
    std::cout << "║   ★ 레벨 업! ★       ║" << std::endl;
    std::cout << "║  현재 레벨: " << level << "       ║" << std::endl;
    std::cout << "║  최대 HP: " << maxHP << "    ║" << std::endl;
    std::cout << "║  공격력: " << attack << "       ║" << std::endl;
    std::cout << "╚════════════════════════╝\n" << std::endl;
}

int Player::attack_action() {
    int baseDamage = attack + (rand() % 10 - 5);  // -5~+5 변동
    return std::max(1, baseDamage);
}


void Player::displayFullStatus() const {
    std::cout << "\n";
    std::cout << "╔═════════════════════════════════════╗" << std::endl;
    std::cout << "║         플레이어 상태 정보         ║" << std::endl;
    std::cout << "╚═════════════════════════════════════╝" << std::endl;
    Character::displayStatus();
    std::cout << "경험치: " << experience << "/" << nextLevelExp << std::endl;
    std::cout << "골드: " << gold << std::endl;
    std::cout << std::endl;
}