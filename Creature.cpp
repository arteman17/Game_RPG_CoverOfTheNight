#include "Creature.h"

Creature::Creature() {
    hp_ = 0;
    max_hp_ = 0;
    damage_ = 0;
}

int Creature::getHp() {
    return hp_;
}

int Creature::getDamage() {
    return damage_;
}

int Creature::getMaxHp() {
    return max_hp_;
}

void Creature::setHp(int hp) {
    hp_ = hp;
}

void Creature::setDamage(int damage) {
    damage_ = damage;
}

void Creature::setMaxHp(int max_hp) {
    max_hp_ = max_hp;
}
