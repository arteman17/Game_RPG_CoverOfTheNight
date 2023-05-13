#include "GameWindow.h"
#include <QDebug>
#include <QTimer>
#include <iostream>

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent),
      scene_(new QGraphicsScene(this)),
      view_(new QGraphicsView(this)),
      model_(new model()) {
    resize(800, 800);
    view_->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    view_->setFixedSize(800, 800);

    setFocusPolicy(Qt::StrongFocus);
    scene_->setSceneRect(-5000, -5000, 10000, 10000);
    scene_->addItem(model_->hero_);

    view_->setScene(scene_);

    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() { updateFrame(); });
    timer->start(16);

    scene_->addLine({-10000, 0, 10000, 0}, {Qt::red, 3});
    scene_->addLine({0, -10000, 0, 10000}, {Qt::red, 3});
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
    double xd = model_->hero_->getDirection().x();
    double yd = model_->hero_->getDirection().y();
    if (event->key() == Qt::Key_W) {
        model_->hero_->setDirection(QPointF(xd, -1));
    }
    if (event->key() == Qt::Key_A) {
        model_->hero_->setDirection(QPointF(-1, yd));
    }
    if (event->key() == Qt::Key_S) {
        model_->hero_->setDirection(QPointF(xd, 1));
    }
    if (event->key() == Qt::Key_D) {
        model_->hero_->setDirection(QPointF(1, yd));
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent* event) {
    double xd = model_->hero_->getDirection().x();
    double yd = model_->hero_->getDirection().y();
    if (event->key() == Qt::Key_W && yd == -1 || event->key() == Qt::Key_S && yd == 1) {
        yd = 0;
    } else if (event->key() == Qt::Key_A && xd == -1 || event->key() == Qt::Key_D && xd == 1) {
        xd = 0;
    } else
        return;
    model_->hero_->setDirection({xd, yd});
}

void GameWindow::updateFrame() {
    model_->modelUpdate();
    view_->centerOn(model_->hero_);
    view_->scene()->update();
    update();
}
