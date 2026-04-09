
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Battle.h"

std::vector<Monster*> createMonsters() {
    std::vector<Monster*> monsters;
    monsters.push_back(new Monster("고블린", 30, 10, 8, 1, 50, 20, 1));
    monsters.push_back(new Monster("오크", 50, 15, 12, 3, 100, 50, 2));
    monsters.push_back(new Monster("드래곤", 100, 30, 20, 8, 300, 200, 5));
    return monsters;
}

Monster* getRandomMonster(std::vector<Monster*>& monsters) {
    int index = rand() % monsters.size();
    Monster* selectedMonster = monsters[index];
    
    // 새로운 인스턴스 생성 (선택된 몬스터의 복제본)
    Monster* newMonster = new Monster(
        selectedMonster->getName(),
        selectedMonster->getMaxHP(),
        selectedMonster->getMaxMP(),
        selectedMonster->getAttack(),
        selectedMonster->getDefense(),
        selectedMonster->getExperienceReward(),
        selectedMonster->getGoldReward(),
        selectedMonster->getLevel()
    );
    return newMonster;
}

void displayMenu() {
    std::cout << "\n╔════════════════════════════════╗" << std::endl;
    std::cout << "║      텍스트 RPG 게임           ║" << std::endl;
    std::cout << "╚════════════════════════════════╝" << std::endl;
    std::cout << "1. 몬스터와 전투" << std::endl;
    std::cout << "2. 상태 보기" << std::endl;
    std::cout << "Q. 게임 종료" << std::endl;
    std::cout << "선택: ";
}

int main() {
    // 랜덤 seed를 생성하는 것
    srand(static_cast<unsigned>(time(0)));
    
    // 시스템 로케일 설정 (한글 출력)
    system("chcp 65001 > nul");
    
    std::string playerName;
    std::cout << "플레이어 이름을 입력하세요: ";
    std::cin >> playerName;
    
    Player* player = new Player(playerName);
    std::vector<Monster*> monsterTemplates = createMonsters();
    
    char choice;
    bool gameRunning = true;
    
    while (gameRunning) {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case '1': {
                Monster* monster = getRandomMonster(monsterTemplates);
                Battle* battle = new Battle(player, monster);
                battle->startBattle();
                
                // 플레이어가 패배했을 경우
                if (!player->isAlive()) {
                    std::cout << "\n게임 오버! 죽었습니다." << std::endl;
                    gameRunning = false;
                }
                
                delete battle;
                delete monster;
                break;
            }
            case '2': {
                player->displayFullStatus();
                break;
            }
            case 'Q':
            case 'q': {
                std::cout << "\n게임을 종료합니다. 플레이해주셔서 감사합니다!" << std::endl;
                gameRunning = false;
                break;
            }
            default:
                std::cout << "잘못된 입력입니다. 다시 선택하세요." << std::endl;
        }
    }
    
    // 메모리 정리
    delete player;
    for (auto monster : monsterTemplates) {
        delete monster;
    }
    
    return 0;
}