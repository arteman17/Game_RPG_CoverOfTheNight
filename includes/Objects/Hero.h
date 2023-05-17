#pragma once

#include <QPainter>
#include "Creature.h"
#include "Weapon.h"

class Hero : public Creature {
public:
    Hero();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    void addWeapon(Weapon weapon);
    std::vector<Weapon> getWeapons();

    void setActiveWeapon(int id);
    Weapon getActiveWeapon();
protected:
    int exp_ = 0;
    int level_= 1;
    std::vector<Weapon> weapons_ {Weapon(melee, 5, 30, 20),
                                 Weapon(range, 5, 300, 20)};
    Weapon active_weapon_ = weapons_[0];
};
