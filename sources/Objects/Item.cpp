#include "Item.h"

Item::Item(int id) {
    id_ = id;
}

void Item::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::black, 3});
    painter->drawRect(boundingRect());

}

QRectF Item::boundingRect() const {
    return QRectF(-20, -20, 40, 40);
}
