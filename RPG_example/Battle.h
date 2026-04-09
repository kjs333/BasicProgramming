#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"
#include "Monster.h"

class Battle {
private:
    Player* player;
    Monster* monster;
    bool battleActive;

public:
    Battle(Player* p, Monster* m);
    ~Battle();

    void startBattle();
    void playerTurn();
    void monsterTurn();
    void displayBattleStatus() const;
    bool battleEnded() const;
    Monster* getMonster() const { return monster; }
};

#endif