#pragma once

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "model.h"
#include <QWidget>

class GameWindow : public QMainWindow {
    Q_OBJECT;
public:
    GameWindow(QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void updateFrame();
private:
    QGraphicsScene* scene_;
    QGraphicsView* view_;
    std::unique_ptr<model> model_;
};