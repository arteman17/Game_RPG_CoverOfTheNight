#pragma once

#include <QGraphicsItem>
#include "Creature.h"

class HpBar : public QGraphicsItem {
public:
    explicit HpBar(Creature* owner) : QGraphicsItem(owner), owner_(owner) { };
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    Creature* owner_;
};
