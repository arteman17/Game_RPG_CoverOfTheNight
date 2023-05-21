#pragma once

#include "Creature.h"
#include <QPainter>
#include <QDeadlineTimer>

class Enemy : public Creature {
public:
    Enemy(const QPointF& pos);

    int getDamage();
    int getAgrDist();
    QPointF getStartPos();

    void attack(Creature* target);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
protected:
    int damage_;
    int duration_;
    int agr_dist_;
    QPointF start_pos_;
    QDeadlineTimer* attack_timer_;
};
