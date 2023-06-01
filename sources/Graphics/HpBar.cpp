#include "HpBar.h"

void HpBar::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::black, 1});
    painter->setBrush(Qt::transparent);
    painter->drawRect(boundingRect());
    auto currentHp = QRectF(boundingRect().topLeft(), QSize(boundingRect().width() * owner_->getHp() / owner_->getMaxHp() ,boundingRect().height()));
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawRect(currentHp);
}

QRectF HpBar::boundingRect() const {
    return QRectF(-owner_->boundingRect().x() * 1.2, 3, owner_->boundingRect().x() * 2 * 1.2, 6);
}
