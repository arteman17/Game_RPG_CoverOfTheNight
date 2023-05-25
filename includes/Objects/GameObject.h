#pragma once

#include <QGraphicsItem>
#include <QPointF>
#include <QPainterPath>
#include <QPainter>

class GameObject : public QGraphicsItem {
public:
    GameObject();
    explicit GameObject(QPointF pos);

    void setPosition(QPointF newPos);
    const QPointF& getPosition() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath makePath();
protected:
    QPointF position_;
};

double dist(QPointF begin, QPointF end);
