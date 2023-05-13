#include "Hero.h"

QRectF Hero::boundingRect() const {
    return QRectF(-25, -25, 50, 50);
}

void Hero::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::black, 3});
    painter->drawRect(boundingRect());
}

Hero::Hero() {
    SetPosition({0, 0});
    setSpeed(8);
}
