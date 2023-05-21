#pragma once

#include "Creature.h"
#include "Weapon.h"
#include <QPainter>

class Hero : public Creature {
public:
    Hero();

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;

    void addWeapon(Weapon weapon);
    std::vector<Weapon> getWeapons();

    void setActiveWeapon(int id);
    Weapon getActiveWeapon();

protected:
    int exp_ = 0;
    int level_ = 1;
    std::vector<Weapon> weapons_{Weapon(melee, 5, 85, 20, 800),
                                 Weapon(range, 5, 700, 20, 800)};
    Weapon active_weapon_ = weapons_[0];
};