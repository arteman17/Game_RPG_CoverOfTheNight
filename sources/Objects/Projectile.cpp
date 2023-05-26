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
    auto fireball = new QPixmap(":resources/fireball.png");
    double angle = atan2(direction_.y(), direction_.x());
    fireball->transformed(QTransform().rotateRadians(angle));
    painter->drawPixmap(-10, -10, *fireball);
//    painter->drawRect(boundingRect());
}

QRectF Projectile::boundingRect() const {
    return {-10, -10, 20, 20};
}

int Projectile::getDamage() {
    return damage_;
}

QPointF Projectile::getStartPos() {
    return start_moving_;
}
