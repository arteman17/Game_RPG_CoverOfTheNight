#pragma once

#include <QPainter>
#include <QDeadlineTimer>

#include "Creature.h"
#include "HpBar.h"

class Enemy : public Creature {
public:
    Enemy(int id, const QPointF& pos);

    int getDamage();
    int getAgrDist();
    QPointF getStartPos();

    void setStats(const std::vector<double>& stats);

    void attack(Creature* target);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    int id_;
    int width_;
    int height_;
protected:
    int damage_;
    int duration_;
    int agr_dist_;
    QPointF start_pos_;
    QDeadlineTimer* attack_timer_;
};
