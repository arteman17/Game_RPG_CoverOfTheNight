#include "model.h"
#include <QDebug>

model::model(){
    hero_ = new Hero();
}

void model::modelUpdate() {
    hero_->move();
}
