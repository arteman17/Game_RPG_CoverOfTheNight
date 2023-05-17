#include "Weapon.h"

Weapon::Weapon(WeaponTypes type, int damage, double range, int speed) :
      type_(type), range_(range), damage_(damage), speed_(speed) { }

WeaponTypes Weapon::getType() {
    return type_;
}

int Weapon::getDamage() const {
    return damage_;
}

void Weapon::setDamage(int damage) {
    damage_ = damage;
}

double Weapon::getRange() const {
    return range_;
}

void Weapon::setRange(double range) {
    range_ = range;
}

int Weapon::getSpeed() const {
    return speed_;
}

void Weapon::setSpeed(int speed) {
    speed_ = speed;
}
