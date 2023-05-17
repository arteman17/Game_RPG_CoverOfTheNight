#pragma once

#include <QGraphicsItem>
#include <QPointF>

class GameObject : public QGraphicsItem {
public:
    GameObject();
    explicit GameObject(QPointF pos);

    void setPosition(QPointF newPos);
    const QPointF& getPosition() const;

protected:
    QPointF position_;
};

double dist(QPointF begin, QPointF end);
