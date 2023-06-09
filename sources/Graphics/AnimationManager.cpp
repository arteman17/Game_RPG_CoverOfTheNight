#include "AnimationManager.h"

AnimationManager::AnimationManager(const QPixmap& frames, int count, int speed, int width, int height, int gap) : width_(width), height_(height), gap_(gap), speed_(speed) {
    for (int i = 0; i < count; ++i) {
        frames_.push_back(frames.copy(i * width + i * gap, 0, width, height));
    }
}

const QPixmap& AnimationManager::getCurrentFrame() const {
    return frames_[current_state_ / 9];
}

void AnimationManager::nextFrame() {
    current_state_ = (current_state_ + 1) % (9 * frames_.size());
}

AnimationManager::AnimationManager(const QPixmap& sprite) {
    frames_.push_back(sprite);
}

bool AnimationManager::isActive() const {
    return !frames_.empty();
}
