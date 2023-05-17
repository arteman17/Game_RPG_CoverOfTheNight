#include "model.h"
#include <QDebug>
#include <cmath>
#include <vector>

model::model() : hero_(new Hero) { }

void model::modelUpdate() {
    hero_->move();
    for (auto& hero_proj : hero_proj_) {
        hero_proj->move();
        if (dist({0, 0}, hero_proj->getPosition() - hero_->getPosition()) > sqrt(2) * 1920) {
            delete hero_proj;
            hero_proj = nullptr;
            continue;
        }
        for (auto& enemy : enemies_) {
            if (hero_proj->collidesWithItem(enemy)) {
                enemy->damage(hero_proj->getDamage());
                delete hero_proj;
                hero_proj = nullptr;
                if (!enemy->isAlive()) {
                    delete enemy;
                    enemy = nullptr;
                }
                break;
            }
            erase_if(enemies_, [](auto* obj) {return obj == nullptr;});
        }
    }
    erase_if(hero_proj_, [](auto* obj){return obj == nullptr;});
}

void model::addProjectile(QPointF coord) {
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
