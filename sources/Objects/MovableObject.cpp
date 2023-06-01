#include "MovableObject.h"
#include <cmath>

MovableObject::MovableObject() : speed_(), direction_() { }

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
    double length = sqrt(direction_.x() * direction_.x() + direction_.y() * direction_.y());
    if (length == 0)
        return;
    setPosition(
        QPointF(position_.x() + speed_ * direction_.x() / length, position_.y() + speed_ * direction_.y() / length)
    );
}

void MovableObject::move(double x, double y) {
    double length = sqrt(x * x + y * y);
    if (length == 0)
        return;
    setPosition(
        QPointF(position_.x() + speed_ * x / length, position_.y() + speed_ * y / length)
    );
}
