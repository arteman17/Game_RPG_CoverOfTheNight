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

double dist(QPointF begin, QPointF end) {
    return std::sqrt((end.x() - begin.x()) * (end.x() - begin.x()) + (end.y() - begin.y()) * (end.y() - begin.y()));
}
