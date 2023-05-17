#include "Enemy.h"

void Enemy::paint(
    QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget
) {
    painter->setPen({Qt::red, 2});
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRect(boundingRect());
}

int Enemy::getDamage() {
    return damage_;
}

QRectF Enemy::boundingRect() const {
    return QRectF(-20, -20, 40, 40);
}

Enemy::Enemy(const QPointF& pos){
    setPosition(pos);
    direction_ = {0, 0};
    max_hp_ = 10;
    hp_ = max_hp_;
    speed_ = 5;
    damage_ = 2;
}

void Enemy::attack(Creature* target) {
    target->damage(damage_);
}
