#include "Hero.h"
#include <QDebug>

Hero::Hero() {
    setPosition({2500, 2500});
    setSpeed(6);
    setMaxHp(100);
    setHp(max_hp_);
    auto* heroHpBar = new HpBar(this);
    heroHpBar->setPos(0, -boundingRect().height() / 2 - heroHpBar->boundingRect().height() / 2 - 7);
    int inc = 500;
    level_exp_.reserve(60);
    level_exp_[0] = 0;
    level_exp_[1] = 400;
    for (int i = 2; i <= 59; ++i) {
        if ((i - 1) % 3 == 0) {
            inc += 200;
        }
        level_exp_[i] = level_exp_[i - 1] + inc;
    }
    enemy_exp_.reserve(60);
    int incE = 5;
    enemy_exp_[0] = 0;
    enemy_exp_[1] = 50;
    for (int i = 2; i <= 59; ++i) {
        enemy_exp_[i] = enemy_exp_[i - 1] + incE;
    }
}

QRectF Hero::boundingRect() const {
    return {-30, -43, 60, 86};
}

void Hero::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    auto hero = new QPixmap(":resources/hero.png");
    painter->drawPixmap(-30, -43, *hero);
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

void Hero::addXp(int value) {
    exp_ += value;
    if (exp_ >= level_exp_[level_]) {
        exp_ -= level_exp_[level_];
        ++level_;
    }
}

int Hero::getXp() {
    return exp_;
}

int Hero::getLevel() {
    return level_;
}
