#include "Projectile.h"
#include "QDebug"

Projectile::Projectile(const Weapon& weapon, const QPointF& target, const Creature& owner) {
    damage_ = weapon.getDamage();
    speed_ = weapon.getSpeed();
    position_ = owner.getPosition();
    setPos(position_);
    direction_ = {(target.x() - position_.x()) / dist(position_, target),
                  (target.y() - position_.y()) / dist(position_, target)};
}

void Projectile::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::red, 3});
    painter->drawRect(boundingRect());
}

QRectF Projectile::boundingRect() const {
    return {-10, -5, 20, 10};
}

int Projectile::getDamage() {
    return damage_;
}
