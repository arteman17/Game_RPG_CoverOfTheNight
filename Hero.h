#pragma once

#include <QPainter>
#include "Creature.h"

class Hero :public Creature {
public:
    Hero();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

protected:
    int exp_ = 0;
};
