#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character {
private:
    int experienceReward;
    int goldReward;

public:
    Monster(std::string name, int maxHP, int maxMP, int attack, int defense, 
            int exp, int gold, int level = 1);
    ~Monster();

    int getExperienceReward() const { return experienceReward; }
    int getGoldReward() const { return goldReward; }

    int attack_action() override;
};

#endif