#include "XpBar.h"

void XpBar::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen({Qt::darkYellow, 2});
    painter->setBrush(Qt::transparent);
    painter->drawRoundedRect(QRectF(boundingRect().topLeft().x() - 1, boundingRect().topLeft().y() + 1, width_, height_), 10, 10);
    painter->setPen({Qt::yellow, 1});
    painter->setBrush(Qt::transparent);
    painter->drawRoundedRect(boundingRect(), 10, 10);
    auto currentXp =
        QRectF(2, 2, 2 + (width_ * owner_->getXp() / owner_->level_exp_[owner_->getLevel()] - 3), height_ - 3);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkBlue);
    painter->drawRoundedRect(currentXp, 5, 5);
}

QRectF XpBar::boundingRect() const {
    return QRectF(0, 0, width_, height_);
}

void XpBar::setWidth(int width) {
    width_ = width;
}

void XpBar::setHeight(int height) {
    height_ = height;
}
