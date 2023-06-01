#include "PlayerInterface.h"

PlayerInterface::PlayerInterface(Hero* hero, QWidget* parent) : QGraphicsView(parent) {
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    int width;
    int height;
    hero_ = hero;
    width = parent->width();
    height = parent->height();
    resize(width, height);
    auto* scene = new QGraphicsScene(0, 0, width, height, this);

    xp_bar_ = new XpBar(hero, 300, 25);
    xp_bar_->setPos(960 - 145, 1080 - 145);

    QString hpText = QString("%1 / %2").arg(hero->getHp()).arg(hero->getMaxHp());
    hp_ = new QGraphicsTextItem(hpText);
    hp_->setDefaultTextColor(Qt::green);
    hp_->setPos(960 - 270, 1080 - 25);

    QString xpText = QString("Level %1 : %2").arg(hero->getLevel()).arg(hero->getXp());
    xp_ = new QGraphicsTextItem(xpText);
    xp_->setDefaultTextColor(Qt::white);
    xp_->setPos(960 - 25, 1080 - 145);

    icon_ = new QGraphicsPixmapItem(QPixmap(":resources/KaelIcon.png").scaled(140, 140));
    icon_->setPos(960 - 170 - 140, 1080 - 137 - 50);

    inter_back_ = new QGraphicsPixmapItem(QPixmap(":resources/interface.png").scaled(1300, 416));
    inter_back_->setPos(960 - 650, 1080 - 416);

    scene->addItem(icon_);
    scene->addItem(inter_back_);
    scene->addItem(xp_bar_);
    scene->addItem(hp_);
    scene->addItem(xp_);

    setScene(scene);
    setFrameShape(QFrame::NoFrame);
    QPalette pal;
    pal.setColor(QPalette::Base, Qt::transparent);
    setPalette(pal);
}

void PlayerInterface::updateHUD() {
    hp_->setPlainText(QString("%1 / %2").arg(hero_->getHp()).arg(hero_->getMaxHp()));
    xp_->setPlainText(QString("Level %1 : %2").arg(hero_->getLevel()).arg(hero_->getXp()));
}
