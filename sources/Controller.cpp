#include "Controller.h"
#include <QDebug>

Controller::Controller(QWidget* parent) : model_(new model) { }

model* Controller::getModel() {
    return model_;
}

void Controller::heroProjCollide() {
    for (auto*& hero_proj : model_->hero_proj_) {
        for (auto* enemy : model_->enemies_) {
            if (hero_proj->collidesWithItem(enemy)) {
                enemy->damage(hero_proj->getDamage());
                if (!enemy->isAlive()) {
                    erase_if(model_->enemies_, [enemy](auto* obj) {return enemy == obj;});
                    delete enemy;
                    model_->hero_->addXp(model_->hero_->enemy_exp_[model_->hero_->getLevel()]);
                }
                delete hero_proj;
                hero_proj = nullptr;
                break;
            }
        }
        if (hero_proj == nullptr) {
            continue;
        }
        for(auto*& scene_obj : model_->scene_obj_) {
            if (hero_proj->collidesWithItem(scene_obj)) {
                delete hero_proj;
                hero_proj = nullptr;
                break;
            }
        }
        if (hero_proj == nullptr) {
            continue;
        }
        if (dist(hero_proj->getStartPos(), hero_proj->getPosition())
            > model_->hero_->getActiveWeapon().getRange()) {
            delete hero_proj;
            hero_proj = nullptr;
            continue;
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
        QPointF enemyPos = enemy->getPosition();
        double x = enemy->getDirection().x();
        double y = enemy->getDirection().y();
        enemy->move(x, 0);
        for(auto obj : model_->scene_obj_) {
            if (enemy->collidesWithItem(obj)) {
                enemy->setPosition(enemyPos);
            }
        }
        for(auto otherEnemy : model_->enemies_) {
            if (otherEnemy != enemy) {
                if (enemy->collidesWithItem(otherEnemy)) {
                    enemy->setPosition(enemyPos);
                }
            }
        }
        if (enemy->collidesWithItem(model_->hero_)) {
            enemy->setPosition(enemyPos);
        }
        enemyPos = enemy->getPosition();
        enemy->move(0, y);
        for(auto obj : model_->scene_obj_) {
            if (enemy->collidesWithItem(obj)) {
                enemy->setPosition(enemyPos);
            }
        }
        for(auto otherEnemy : model_->enemies_) {
            if (otherEnemy != enemy) {
                if (enemy->collidesWithItem(otherEnemy)) {
                    enemy->setPosition(enemyPos);
                }
            }
        }
        if (enemy->collidesWithItem(model_->hero_)) {
            enemy->setPosition(enemyPos);
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

void Controller::heroMoving() {
    QPointF heroPos = model_->hero_->getPosition();
    double x = model_->hero_->getDirection().x();
    double y = model_->hero_->getDirection().y();
    model_->hero_->move(x, 0);
    for(auto obj : model_->scene_obj_) {
        if (model_->hero_->collidesWithItem(obj)) {
            model_->hero_->setPosition(heroPos);
        }
    }
    for(auto enemy : model_->enemies_) {
        if (model_->hero_->collidesWithItem(enemy)) {
            model_->hero_->setPosition(heroPos);
        }
    }
    heroPos = model_->hero_->getPosition();
    model_->hero_->move(0, y);
    for(auto obj : model_->scene_obj_) {
        if (model_->hero_->collidesWithItem(obj)) {
            model_->hero_->setPosition(heroPos);
        }
    }
    for(auto enemy : model_->enemies_) {
        if (model_->hero_->collidesWithItem(enemy)) {
            model_->hero_->setPosition(heroPos);
        }
    }
}
