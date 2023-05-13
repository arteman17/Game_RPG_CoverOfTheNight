#include "GameObject.h"

GameObject::GameObject() : position_() { }

void GameObject::SetPosition(QPointF pos) {
    position_ = pos;
    setPos(pos);
}

const QPointF GameObject::GetPosition() const {
    return position_;
}
