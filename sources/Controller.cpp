#include "Controller.h"
#include <QDebug>

Controller::Controller(QWidget* parent) : model_(new model) { }

model* Controller::getModel() {
    return model_;
}

void Controller::heroProjCollide() {
    for (auto*& hero_proj : model_->hero_proj_) {
        if (dist(hero_proj->getStartPos(), hero_proj->getPosition())
            > model_->hero_->getActiveWeapon().getRange()) {
            delete hero_proj;
            hero_proj = nullptr;
            continue;
        }
        for (auto* enemy : model_->enemies_) {
            if (hero_proj->collidesWithItem(enemy)) {
                enemy->damage(hero_proj->getDamage());
                delete hero_proj;
                hero_proj = nullptr;
                if (!enemy->isAlive()) {
                    erase_if(model_->enemies_, [enemy](auto* obj) {return enemy == obj;});
                    delete enemy;
                }
                break;
            }
        }
    }
    erase_if(model_->hero_proj_, [](auto* obj) { return obj == nullptr; });
}

void Controller::enemyMoving() {
    for (auto* enemy : model_->enemies_) {
        if (dist(model_->hero_->getPosition(), enemy->getPosition()) <= enemy->getAgrDist()) {
            double length = dist(model_->hero_->getPosition(), enemy->getPosition());
            enemy->setDirection(
                {(model_->hero_->getPosition().x() - enemy->getPosition().x()) / length,
                 (model_->hero_->getPosition().y() - enemy->getPosition().y()) / length}
            );
        } else {
            if (enemy->getStartPos() != enemy->getPosition()) {
                double length = dist(enemy->getStartPos(), enemy->getPosition());
                if (length <= 5) {
                    enemy->setDirection({0, 0});
                    enemy->setPosition(enemy->getStartPos());
                } else {
                    enemy->setDirection(
                        {(enemy->getStartPos().x() - enemy->getPosition().x()) / length,
                         (enemy->getStartPos().y() - enemy->getPosition().y()) / length}
                    );
                }
            }
        }
    }
}

void Controller::enemyAttack() {
    for(auto* enemy : model_->enemies_) {
        double minDist = (model_->hero_->boundingRect().width() + enemy->boundingRect().width()) / 2 + 5;
        if (minDist / dist(model_->hero_->getPosition(), enemy->getPosition()) >= 1) {
            enemy->attack(model_->hero_);
            enemy->setDirection({0, 0});
        }
    }
}

void Controller::heroCollide() {
    for(auto obj : model_->scene_obj_) {
        if (model_->hero_->collidesWithItem(obj)) {
            model_->hero_->setDirection({-model_->hero_->getDirection().x(), -model_->hero_->getDirection().y()});
        }
    }
}
