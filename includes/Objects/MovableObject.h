#pragma once

#include "GameObject.h"

class MovableObject : public GameObject{
public:
    MovableObject();

    double getSpeed() const;
    void setSpeed(double speed);

    const QPointF& getDirection() const;
    void setDirection(const QPointF& direction);

    void move();
protected:
    double speed_;
    QPointF direction_ = {0, 0};
};
