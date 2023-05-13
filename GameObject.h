#pragma once

#include <QGraphicsItem>
#include <QPointF>

class GameObject : public QGraphicsItem {
public:
    GameObject();

    void SetPosition(QPointF pos);
    const QPointF GetPosition() const;

protected:
    QPointF position_;
};
