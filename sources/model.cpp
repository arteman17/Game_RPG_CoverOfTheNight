#include "model.h"
#include <QDebug>
#include <cmath>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

model::model() : hero_(new Hero) {
    loadEnemyType();
    loadEnemy();
}

void model::modelUpdate() {
    for (auto*& hero_proj : hero_proj_) {
        hero_proj->move();
    }
}

void model::addHeroProjectile(QPointF coord) {
    if (hero_->getPosition().x() < 960 && hero_->getPosition().y() < 540) {
        hero_proj_.emplace_back(new Projectile(hero_->getActiveWeapon(), coord, hero_));
    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() < 540) {
        hero_proj_.emplace_back(new Projectile(
            hero_->getActiveWeapon(),
            coord + (QPointF{hero_->getPosition().x(), 0} - QPointF{960, 0}), hero_
        ));
    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() > 540) {
        hero_proj_.emplace_back(new Projectile(
            hero_->getActiveWeapon(), coord + hero_->getPosition() - QPointF{960, 540}, hero_
        ));
    } else {
        hero_proj_.emplace_back(new Projectile(
            hero_->getActiveWeapon(),
            coord + (QPointF{0, hero_->getPosition().y()} - QPointF{0, 540}), hero_
        ));
    }
}

//void model::addEnemy(QPointF coord) {
//    if (hero_->getPosition().x() < 960 && hero_->getPosition().y() < 540) {
//        enemies_.emplace_back(newEnemy(0 ,coord));
//        enemies_.back()->setStartPos(coord);
//    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() < 540) {
//        enemies_.emplace_back(
//            newEnemy(0, coord + QPointF{hero_->getPosition().x(), 0} - QPointF{960, 0})
//        );
//        enemies_.back()->setStartPos(coord);
//    } else if (hero_->getPosition().x() > 960 && hero_->getPosition().y() > 540) {
//        enemies_.emplace_back(newEnemy(0, coord + hero_->getPosition() - QPointF{960, 540}));
//        enemies_.back()->setStartPos(coord);
//    } else {
//        enemies_.emplace_back(
//            newEnemy(0, coord + (QPointF{0, hero_->getPosition().y()} - QPointF{0, 540}))
//        );
//        enemies_.back()->setStartPos(coord);
//    }
//}

Enemy* model::newEnemy(int id, const QPointF& pos) {
    auto* enemy = new Enemy(id, pos);
    enemy->setStats(enemyTypes[id]);
    auto* enemyHpBar = new HpBar(enemy);
    enemyHpBar->setPos(0, -enemy->boundingRect().height() / 2 - enemyHpBar->boundingRect().height() / 2 - 7);
    return enemy;
}

void model::loadEnemyType() {
    QFile enemyTypeFile(":/Json/enemyType.json");
    enemyTypeFile.open(QIODevice::ReadOnly);
    QJsonDocument enemiesJson(QJsonDocument::fromJson(enemyTypeFile.readAll()));
    QJsonArray enemyTypeArr = enemiesJson.array();
    for (int i = 0; i < enemyTypeArr.size(); ++i) {
        auto enemy = enemyTypeArr[i].toObject();
        enemyTypes[i] = {};
        enemyTypes[i].push_back(enemy["damage"].toInt());
        enemyTypes[i].push_back(enemy["maxHp"].toInt());
        enemyTypes[i].push_back(enemy["speed"].toDouble());
        enemyTypes[i].push_back(enemy["duration"].toInt());
        enemyTypes[i].push_back(enemy["agrDist"].toInt());
        enemyTypes[i].push_back(enemy["width"].toInt());
        enemyTypes[i].push_back(enemy["height"].toInt());
    }
    enemyTypeFile.close();
}

void model::loadEnemy() {
    QFile enemyFile(":/Json/enemy.json");
    enemyFile.open(QIODevice::ReadOnly);
    QJsonDocument enemyJson(QJsonDocument::fromJson(enemyFile.readAll()));
    QJsonArray enemyArray = enemyJson.array();
    for (int i = 0; i < enemyArray.size(); ++i) {
        auto enemy = enemyArray[i].toObject();
        auto id = enemy["id"].toInt();
        auto coords = enemy["pos"].toArray();
        for (auto pos : coords) {
            auto coord = pos.toArray();
            enemies_.emplace_back(newEnemy(id, {coord[0].toDouble(), coord[1].toDouble()}));
        }
    }
    enemyFile.close();
}