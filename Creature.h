#pragma once

#include "MovableObject.h"

class Creature : public MovableObject{
public:
    Creature();

    int getHp();
    int getDamage();
    int getMaxHp();

    void setHp(int hp);
    void setDamage(int damage);
    void setMaxHp(int max_hp);
protected:
    int hp_;
    int max_hp_;
    int damage_;
};
