#pragma once

enum WeaponTypes {
    melee,
    range
};

class Weapon {
public:
    Weapon(WeaponTypes type, int damage, double range, int speed, int duration);

    WeaponTypes getType();

    int getDamage() const;
    void setDamage(int damage);

    double getRange() const;
    void setRange(double range);

    int getSpeed() const;
    void setSpeed(int speed);

    int getDuration() const;
    void setDuration(int duration);
protected:
    int speed_;
    int damage_;
    double range_;
    int duration_;
    WeaponTypes type_;
};