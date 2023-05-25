#include "Projectile.h"
#include "QDebug"
#include <cmath>

Projectile::Projectile(const Weapon& weapon, const QPointF& target, const Creature& owner) {
    damage_ = weapon.getDamage();
    speed_ = weapon.getSpeed();
    position_ = owner.getPosition();
    setPos(position_);
    start_moving_ = owner.getPosition();
    direction_ = {(target.x() - position_.x()) / dist(position_, target),
                  (target.y() - position_.y()) / dist(position_, target)};
}

void Projectile::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::red, 3});
    painter->drawRect(boundingRect());
//    double angle = atan2(direction_.y(), direction_.x());
//    this->setRotation(angle);
//    this->rotation();
}

QRectF Projectile::boundingRect() const {
    return {-20, -3, 40, 6};
}

int Projectile::getDamage() {
    return damage_;
}

QPointF Projectile::getStartPos() {
    return start_moving_;
}
