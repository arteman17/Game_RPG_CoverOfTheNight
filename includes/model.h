#pragma once

#include "Hero.h"
#include "Projectile.h"
#include "Enemy.h"

class model {
public:
    model();
    void modelUpdate();

    void addHeroProjectile(QPointF coord);
//    void addEnemy(QPointF coord);
    Enemy* newEnemy(int id, const QPointF& pos);
    void loadEnemyType();
    void loadEnemy();

    Hero* hero_;
    std::vector<Enemy*> enemies_ { };
    std::vector<Projectile*> hero_proj_ { };
    std::map<int, std::vector<double>> enemyTypes;
    std::vector<GameObject*> scene_obj_ {new GameObject({2300, 2300})};
};
