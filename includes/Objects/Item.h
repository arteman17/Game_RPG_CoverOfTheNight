#pragma once

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class Item : public QGraphicsItem {
public:
    Item(int id);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap icon_;
    int id_;
};