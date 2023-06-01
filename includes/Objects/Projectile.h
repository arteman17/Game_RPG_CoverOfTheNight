#pragma once

#include <QPainter>
#include <QPixmap>
#include "MovableObject.h"
#include "Weapon.h"
#include "Hero.h"

class Projectile : public MovableObject{
public:
    Projectile(const Weapon& weapon, const QPointF& target, const Hero* owner);

    int getDamage();
    QPointF getStartPos();
    const Hero& getOwner();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
protected:
    QPointF start_moving_;
    int damage_;
    QPixmap pict_;
    const Hero* owner_;
};
