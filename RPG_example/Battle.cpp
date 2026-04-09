#include "Battle.h"
#include <iostream>
#include <iomanip>

Battle::Battle(Player* p, Monster* m)
    : player(p), monster(m), battleActive(true) {}

Battle::~Battle() {}

void Battle::startBattle() {
    std::cout << "\n╔════════════════════════════════╗" << std::endl;
    std::cout << "║        전투 시작!              ║" << std::endl;
    std::cout << "║  " << std::setw(10) << player->getName() 
              << " VS " << std::setw(10) << monster->getName() << "║" << std::endl;
    std::cout << "╚════════════════════════════════╝\n" << std::endl;

    while (battleActive && player->isAlive() && monster->isAlive()) {
        displayBattleStatus();
        playerTurn();
        
        if (monster->isAlive()) {
            monsterTurn();
        }
    }

    // 전투 결과
    if (player->isAlive()) {
        std::cout << "\n╔════════════════════════════════╗" << std::endl;
        std::cout << "║      ★ 승리! ★                ║" << std::endl;
        std::cout << "╚════════════════════════════════╝" << std::endl;
        
        int exp = monster->getExperienceReward();
        int gold = monster->getGoldReward();
        
        player->gainExperience(exp);
        player->addGold(gold);
        std::cout << gold << " 골드를 획득했습니다!" << std::endl;
    } else {
        std::cout << "\n╔════════════════════════════════╗" << std::endl;
        std::cout << "║      ★ 패배... ★              ║" << std::endl;
        std::cout << "╚════════════════════════════════╝" << std::endl;
    }
}

void Battle::displayBattleStatus() const {
    std::cout << "┌─ 전투 상황 ─────────────────────────┐" << std::endl;
    std::cout << "│ [플레이어] " << player->getName() << std::endl;
    std::cout << "│ HP: " << player->getCurrentHP() << "/" << player->getMaxHP() << std::endl;
    std::cout << "│" << std::endl;
    std::cout << "│ [몬스터] " << monster->getName() << std::endl;
    std::cout << "│ HP: " << monster->getCurrentHP() << "/" << monster->getMaxHP() << std::endl;
    std::cout << "└────────────────────────────────────┘" << std::endl;
}

void Battle::playerTurn() {
    std::cout << "\n[당신의 턴]" << std::endl;
    std::cout << "1. 공격" << std::endl;
    std::cout << "선택: ";
    
    int choice;
    std::cin >> choice;
    
    if (choice == 1) {
        int damage = player->attack_action();
        monster->takeDamage(damage);
        std::cout << player->getName() << "이(가) " << monster->getName() 
                  << "에게 " << damage << "의 피해를 입혔습니다!" << std::endl;
    }
}

void Battle::monsterTurn() {
    std::cout << "\n[몬스터의 턴]" << std::endl;
    int damage = monster->attack_action();
    player->takeDamage(damage);
    std::cout << monster->getName() << "이(가) " << player->getName() 
              << "에게 " << damage << "의 피해를 입혔습니다!" << std::endl;
}

bool Battle::battleEnded() const {
    return !player->isAlive() || !monster->isAlive();
}