#include "Hero.h"

Hero::Hero() {
    setPosition({2500, 2500});
    setSpeed(8);
    setMaxHp(50);
    setHp(50);

}

QRectF Hero::boundingRect() const {
    return {-50, -72, 100, 143};
}

void Hero::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::black, 3});
    auto hero = new QPixmap(":resources/hero.png");
//    double angle = atan2(direction_.y(), direction_.x());
//    fireball->transformed(QTransform().rotateRadians(angle));
    painter->drawPixmap(-50, -72, *hero);
//    painter->drawRect(boundingRect());
}

void Hero::addWeapon(Weapon weapon) {
    weapons_.push_back(weapon);
}

std::vector<Weapon> Hero::getWeapons() {
    return weapons_;
}

void Hero::setActiveWeapon(int id) {
    if (id <= weapons_.size()) {
        active_weapon_ = weapons_[id - 1];
    }
}

Weapon Hero::getActiveWeapon() {
    return active_weapon_;
}