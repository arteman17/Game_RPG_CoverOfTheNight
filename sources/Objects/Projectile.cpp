#include "Projectile.h"
#include "QDebug"
#include <cmath>

Projectile::Projectile(const Weapon& weapon, const QPointF& target, const Hero* owner) : owner_(owner){
    damage_ = weapon.getDamage();
    speed_ = weapon.getSpeed();
    position_ = owner->getPosition();
    setPos(position_);
    start_moving_ = owner->getPosition();
    direction_ = {(target.x() - position_.x()) / dist(position_, target),
                  (target.y() - position_.y()) / dist(position_, target)};
    pict_ = QPixmap(":resources/fireball.png");
    double angle = atan2(direction_.y(), direction_.x());
    pict_ = pict_.transformed(QTransform().rotateRadians(angle + M_PI));
}

void Projectile::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::red, 3});
    painter->drawPixmap(-10, -10, pict_);
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

const Hero& Projectile::getOwner() {
    return *owner_;
}
