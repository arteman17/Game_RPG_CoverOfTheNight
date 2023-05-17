#pragma once

#include "Creature.h"
#include <QPainter>

class Enemy : public Creature {
public:
    Enemy(const QPointF& pos);

    int getDamage();

    void attack(Creature* target);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
protected:
    int damage_;
    int agr_dist;
};
