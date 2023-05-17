#include "GameWindow.h"
#include <QDebug>
#include <QTimer>
#include <cmath>

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent),
      scene_(new QGraphicsScene(this)),
      view_(new QGraphicsView(this)),
      model_(new model()) {
    resize(maximumWidth(), maximumHeight());
    view_->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    scene_->setSceneRect(0, 0, 10000, 10000);
    view_->resize(1920, 1080);
    view_->setScene(scene_);

    setFocusPolicy(Qt::StrongFocus);
    scene_->addItem(model_->hero_);
    setCentralWidget(view_);

    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() { updateFrame(); });
    timer->start(16);

    scene_->addLine({-10000, 5000, 10000, 5000}, {Qt::red, 3});
    scene_->addLine({5000, -10000, 5000, 10000}, {Qt::red, 3});

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
    if (event->key() == Qt::Key_1) {
        model_->hero_->setActiveWeapon(1);
    }
    if (event->key() == Qt::Key_2) {
        model_->hero_->setActiveWeapon(2);
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

void GameWindow::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        model_->addProjectile(event->pos());
        scene_->addItem(model_->hero_proj_[model_->hero_proj_.size() - 1]);
    }
    if (event->button() == Qt::RightButton) {
        model_->addEnemy(event->pos());
        scene_->addItem(model_->enemies_[model_->enemies_.size() - 1]);
    }
}
