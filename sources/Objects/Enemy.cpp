#include "Enemy.h"

Enemy::Enemy(int id, const QPointF& pos) : attack_timer_(new QDeadlineTimer()){
    setPosition(pos);
    id_ = id;
    start_pos_ = pos;

    res_ = new QPixmap(":resources/MageHero.png");
    AnimationManager anim(*res_, 3, speed_, width_, height_, 1);
    setAnimation(anim);
}

void Enemy::paint(
    QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget
) {
    painter->drawPixmap(
        boundingRect().topLeft(), animation_.getCurrentFrame().transformed(QTransform::fromScale(direction_.x() >= 0 ? -1 : 1, 1)).scaled(70, 70)
    );
}

QRectF Enemy::boundingRect() const {
    return QRectF(-width_ / 2, -height_ / 2, width_, height_);
}

void Enemy::attack(Creature* target) {
    if (!attack_timer_->hasExpired()) return;
    auto* player = new QMediaPlayer;
    player->setMedia(QUrl(QString("qrc:/resources/sounds/punch_%1.mp3").arg(id_)));
    player->play();
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

void Enemy::setStats(const std::vector<double>& stats) {
    if (stats.size() != 7) return;
    damage_ = static_cast<int>(stats[0]);
    max_hp_ = static_cast<int>(stats[1]);
    hp_ = max_hp_;
    speed_ = stats[2];
    duration_ = static_cast<int>(stats[3]);
    agr_dist_ = static_cast<int>(stats[4]);
    width_ = static_cast<int>(stats[5]);
    height_ = static_cast<int>(stats[6]);

    AnimationManager anim(QPixmap(QString(":resources/enemy_%1.png").arg(id_)), 3, speed_, width_, height_, 1);
    setAnimation(anim);
}

