#include "Monster.h"
#include <cstdlib>

Monster::Monster(std::string name, int maxHP, int maxMP, int attack, int defense,
                 int exp, int gold, int level)
    : Character(name, maxHP, maxMP, attack, defense, level),
      experienceReward(exp), goldReward(gold) {}

Monster::~Monster() {}

int Monster::attack_action() {
    int baseDamage = attack + (rand() % 8 - 2);  // -2~+6 변동
    return std::max(1, baseDamage);
}
