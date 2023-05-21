#include "model.h"
#include <QDebug>
#include <cmath>
#include <vector>

model::model() : hero_(new Hero) { }

void model::modelUpdate() {
    hero_->move();
    for(auto* enemy : enemies_) {
        enemy->move();
    }
    for (auto*& hero_proj : hero_proj_) {
        hero_proj->move();
    }
}

void model::addHeroProjectile(QPointF coord) {
    if (hero_->getPosition().x() < 960 && hero_->getPosition().y() < 540) {
        hero_proj_.emplace_back(new Projectile(hero_->getActiveWeapon(), coord, *hero_));
    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() < 540) {
        hero_proj_.emplace_back(new Projectile(
            hero_->getActiveWeapon(),
            coord + (QPointF{hero_->getPosition().x(), 0} - QPointF{960, 0}), *hero_
        ));
    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() > 540) {
        hero_proj_.emplace_back(new Projectile(
            hero_->getActiveWeapon(), coord + hero_->getPosition() - QPointF{960, 540}, *hero_
        ));
    } else {
        hero_proj_.emplace_back(new Projectile(
            hero_->getActiveWeapon(),
            coord + (QPointF{0, hero_->getPosition().y()} - QPointF{0, 540}), *hero_
        ));
    }
}

void model::addEnemy(QPointF coord) {
    if (hero_->getPosition().x() < 960 && hero_->getPosition().y() < 540) {
        enemies_.emplace_back(new Enemy(coord));
    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() < 540) {
        enemies_.emplace_back(
            new Enemy(coord + QPointF{hero_->getPosition().x(), 0} - QPointF{960, 0})
        );
    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() > 540) {
        enemies_.emplace_back(new Enemy(coord + hero_->getPosition() - QPointF{960, 540}));
    } else {
        enemies_.emplace_back(
            new Enemy(coord + (QPointF{0, hero_->getPosition().y()} - QPointF{0, 540}))
        );
    }
}