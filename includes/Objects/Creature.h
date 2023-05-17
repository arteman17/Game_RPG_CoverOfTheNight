#pragma once

#include "MovableObject.h"

class Creature : public MovableObject{
public:
    Creature();
    int getHp() const;

    int getMaxHp() const;
    bool isAlive() const;
    void damage(int damage);
    void heal(int heal);
protected:
    explicit Creature(int max_hp);
    int hp_;
    int max_hp_;
};
