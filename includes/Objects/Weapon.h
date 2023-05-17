#pragma once

enum WeaponTypes {
    melee,
    range
};

class Weapon {
public:
    Weapon(WeaponTypes type, int damage, double range, int speed);

    WeaponTypes getType();

    int getDamage() const;
    void setDamage(int damage);

    double getRange() const;
    void setRange(double range);

    int getSpeed() const;
    void setSpeed(int speed);
protected:
    int speed_;
    int damage_;
    double range_;
    WeaponTypes type_;
};