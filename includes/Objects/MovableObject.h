#pragma once

#include "GameObject.h"
#include "AnimationManager.h"

class MovableObject : public GameObject{
public:
    MovableObject();

    double getSpeed() const;
    void setSpeed(double speed);

    const QPointF& getDirection() const;
    void setDirection(const QPointF& direction);
    void setAnimation(AnimationManager& anim);

    void move();
    void move(double x, double y);
protected:
    double speed_;
    QPointF direction_ = {0, 0};
    AnimationManager animation_;
};
