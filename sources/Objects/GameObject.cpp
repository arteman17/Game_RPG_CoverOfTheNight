#include "GameObject.h"
#include <cmath>

GameObject::GameObject() : position_() { }

GameObject::GameObject(QPointF position) : position_(position) {
    setPos(position);
}

void GameObject::setPosition(QPointF newPos) {
    position_ = newPos;
    setPos(newPos);
}

const QPointF& GameObject::getPosition() const {
    return position_;
}

void GameObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::black, 3});
    auto house = new QPixmap(":resources/house.png");
    painter->drawPixmap(-80, -54, *house);
//    painter->drawPath(makePath());
//    painter->drawRect(boundingRect());
}

QRectF GameObject::boundingRect() const {
    return QRectF(-80, -54, 160, 108);
}

QPainterPath GameObject::makePath() {
    QPainterPath path({100, 100});
    path.lineTo(-100, 100);
    path.lineTo(-100, -100);
    path.lineTo(100, -100);
    path.lineTo(100, 100);
    return path;
}

double dist(QPointF begin, QPointF end) {
    return std::sqrt((end.x() - begin.x()) * (end.x() - begin.x()) + (end.y() - begin.y()) * (end.y() - begin.y()));
}
