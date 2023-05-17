#include "Creature.h"

Creature::Creature() : Creature(0) { }

Creature::Creature(int max_hp) : max_hp_(max_hp), hp_(max_hp) { }

int Creature::getHp() const {
    return hp_;
}

int Creature::getMaxHp() const {
    return max_hp_;
}

bool Creature::isAlive() const {
    return hp_ > 0;
}

void Creature::damage(int damage) {
    hp_ = hp_ - damage;
    if (hp_ < 0)
        hp_ = 0;
}

void Creature::heal(int heal) {
    hp_ = hp_ = heal;
    if (hp_ > max_hp_)
        hp_ = max_hp_;
}
