#include "GameWindow.h"
#include <QDebug>
#include <QTimer>
#include <cmath>

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent),
      scene_(new QGraphicsScene(this)),
      view_(new QGraphicsView(this)),
      controller_(new Controller(this)) {
    view_->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFocusPolicy(Qt::StrongFocus);
    view_->setFrameShape(QGraphicsView::NoFrame);
    view_->setDragMode(QGraphicsView::NoDrag);

    resize(maximumWidth(), maximumHeight());
    scene_->setSceneRect(0, 0, 10000, 10000);
    view_->resize(1920, 1080);
    view_->setScene(scene_);

    scene_->addItem(controller_->getModel()->hero_);
    setCentralWidget(view_);

    game_timer_ = new QTimer(this);
    game_timer_->setInterval(16);
    connect(game_timer_, &QTimer::timeout, [this]() { updateFrame(); });
    game_timer_->start();

    hero_attack_timer_ = new QTimer(this);
    hero_attack_timer_->setInterval(controller_->getModel()->hero_->getActiveWeapon().getDuration());
    connect(hero_attack_timer_, &QTimer::timeout, [this]() { attackTime_++; });
    hero_attack_timer_->start();

    scene_->addLine({-10000, 5000, 10000, 5000}, {Qt::red, 3});
    scene_->addLine({5000, -10000, 5000, 10000}, {Qt::red, 3});
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
    double xd = controller_->getModel()->hero_->getDirection().x();
    double yd = controller_->getModel()->hero_->getDirection().y();
    if (event->key() == Qt::Key_W) {
        controller_->getModel()->hero_->setDirection(QPointF(xd, -1));
    }
    if (event->key() == Qt::Key_A) {
        controller_->getModel()->hero_->setDirection(QPointF(-1, yd));
    }
    if (event->key() == Qt::Key_S) {
        controller_->getModel()->hero_->setDirection(QPointF(xd, 1));
    }
    if (event->key() == Qt::Key_D) {
        controller_->getModel()->hero_->setDirection(QPointF(1, yd));
    }
    if (event->key() == Qt::Key_1) {
        controller_->getModel()->hero_->setActiveWeapon(1);
    }
    if (event->key() == Qt::Key_2) {
        controller_->getModel()->hero_->setActiveWeapon(2);
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent* event) {
    double xd = controller_->getModel()->hero_->getDirection().x();
    double yd = controller_->getModel()->hero_->getDirection().y();
    if (event->key() == Qt::Key_W && yd == -1 || event->key() == Qt::Key_S && yd == 1) {
        yd = 0;
    } else if (event->key() == Qt::Key_A && xd == -1 || event->key() == Qt::Key_D && xd == 1) {
        xd = 0;
    } else
        return;
    controller_->getModel()->hero_->setDirection({xd, yd});
}

void GameWindow::updateFrame() {
    controller_->getModel()->modelUpdate();
    controller_->heroProjCollide();
    controller_->enemyMoving();
    controller_->enemyAttack();
    if (!controller_->getModel()->hero_->isAlive()) {
//        close();
        game_timer_->stop();
    }
    view_->centerOn(controller_->getModel()->hero_);
    view_->scene()->update();
    update();
}

void GameWindow::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (attackTime_ >= 1) {
            controller_->getModel()->addHeroProjectile(event->pos());
            scene_->addItem(controller_->getModel()->hero_proj_.back());
            attackTime_ = 0;
        }
    }
    if (event->button() == Qt::RightButton) {
        controller_->getModel()->addEnemy(event->pos());
        scene_->addItem(controller_->getModel()->enemies_.back());
    }
}
