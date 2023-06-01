#pragma once

#include "Hero.h"
#include <QGraphicsItem>

class XpBar : public QGraphicsItem {
public:
    explicit XpBar(Hero* owner, int width, int height)
        : QGraphicsItem(owner), owner_(owner), width_(width), height_(height){};
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;

    void setWidth(int width);
    void setHeight(int height);

private:
    Hero* owner_;
    int width_;
    int height_;
};