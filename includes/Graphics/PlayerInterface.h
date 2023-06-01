#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPalette>
#include <QPixmap>
#include <string>
#include "HpBar.h"
#include "XpBar.h"
#include "Hero.h"

class PlayerInterface : public QGraphicsView {
    Q_OBJECT
public:
    explicit PlayerInterface(Hero* hero, QWidget* parent = nullptr);
    void updateHUD();

    XpBar* xp_bar_;
    Hero* hero_;
    QGraphicsTextItem* hp_;
    QGraphicsTextItem* xp_;
    QGraphicsPixmapItem* icon_;
    QGraphicsPixmapItem* inter_back_;
};
