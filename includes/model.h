#pragma once

#include "Hero.h"
#include "Projectile.h"
#include "Enemy.h"

class model {
public:
    model();
    void modelUpdate();

    void addProjectile(QPointF coord);
    void addEnemy(QPointF coord);

    Hero* hero_;
    std::vector<Enemy*> enemies_;
    std::vector<Projectile*> hero_proj_;
};
