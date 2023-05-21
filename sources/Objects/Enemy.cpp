#include "Enemy.h"

Enemy::Enemy(const QPointF& pos) : attack_timer_(new QDeadlineTimer()){
    setPosition(pos);
    max_hp_ = 10;
    hp_ = max_hp_;
    speed_ = 5;
    damage_ = 5;
    agr_dist_ = 300;
    start_pos_ = pos;
    duration_ = 500;
}

void Enemy::paint(
    QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget
) {
    painter->setPen({Qt::red, 2});
//    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRect(boundingRect());
}

QRectF Enemy::boundingRect() const {
    return QRectF(-20, -20, 40, 40);
}

void Enemy::attack(Creature* target) {
    if (!attack_timer_->hasExpired()) return;
    target->damage(damage_);
    attack_timer_->setRemainingTime(duration_);
}

int Enemy::getDamage() {
    return damage_;
}

int Enemy::getAgrDist() {
    return agr_dist_;
}

QPointF Enemy::getStartPos() {
    return start_pos_;
}
