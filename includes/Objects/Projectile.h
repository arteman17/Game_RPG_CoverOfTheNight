#pragma once

#include <QPainter>
#include "MovableObject.h"
#include "Weapon.h"
#include "Creature.h"

class Projectile : public MovableObject{
public:
    Projectile(const Weapon& weapon, const QPointF& target, const Creature& owner);

    int getDamage();
    QPointF getStartPos();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
protected:
    QPointF start_moving_;
    int damage_;
};
