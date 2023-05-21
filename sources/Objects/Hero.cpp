#include "Hero.h"

Hero::Hero() {
    setPosition({5000, 5000});
    setSpeed(8);
    setMaxHp(50);
    setHp(50);

}

QRectF Hero::boundingRect() const {
    return {-50, -50, 100, 100};
}

void Hero::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::black, 3});
    painter->drawRect(boundingRect());
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