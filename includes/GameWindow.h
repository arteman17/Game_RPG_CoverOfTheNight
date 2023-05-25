#pragma once

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimerEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QPixmap>

#include "model.h"
#include "Controller.h"

class GameWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit GameWindow(QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void updateFrame();
private:
    QTimer* game_timer_;
    QTimer* hero_attack_timer_;
    int attackTime_ = 0;
    QGraphicsScene* scene_;
    QGraphicsView* view_;
    Controller* controller_;
};