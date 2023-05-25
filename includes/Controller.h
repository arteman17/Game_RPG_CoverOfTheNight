#pragma once

#include <QWidget>
#include "model.h"

class Controller : public QWidget{
public:
    explicit Controller(QWidget* parent);

    model* getModel();

    void heroProjCollide();

    void enemyMoving();

    void enemyAttack();

    void heroCollide();
private:
    model* model_;
};
