#include "model.h"
#include <cmath>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMediaPlayer>

model::model() : hero_(new Hero) {
    loadEnemyType();
    loadEnemy();
    loadObj();
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
    auto* player_ = new QMediaPlayer;
    player_->setMedia(QUrl("qrc:/resources/sounds/fireball.mp3"));
    player_->play();
}

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

void model::loadObj() {
    QFile objFile(":/Json/obj.json");
    objFile.open(QIODevice::ReadOnly);
    QJsonDocument objJson(QJsonDocument::fromJson(objFile.readAll()));
    QJsonObject objPos = objJson.object();
    auto coords = objPos["pos"].toArray();
    for (auto pos : coords) {
        auto coord = pos.toArray();
        scene_obj_.push_back(new GameObject(QPointF(coord[0].toDouble(), coord[1].toDouble())));
    }
    objFile.close();
}
