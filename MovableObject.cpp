#include "MovableObject.h"
#include <cmath>
#include <QDebug>

MovableObject::MovableObject() {
    direction_ = QPointF(0, 0);
}

double MovableObject::getSpeed() const {
    return speed_;
}

void MovableObject::setSpeed(double speed) {
    speed_ = speed;
}

const QPointF& MovableObject::getDirection() const {
    return direction_;
}

void MovableObject::setDirection(const QPointF& direction) {
    direction_ = direction;
}

void MovableObject::move() {
    double lenght = sqrt(direction_.x() * direction_.x() + direction_.y() * direction_.y());
    if (lenght == 0)
        return;
    SetPosition(QPointF(position_.x() + speed_ * direction_.x() / lenght, position_.y() + speed_ * direction_.y() / lenght));
}
