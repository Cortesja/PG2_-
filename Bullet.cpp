#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(int speed, Size size) {
	speed_ = speed;
	size_ = size;

	isShot_ = false;
}

void Bullet::Update(Vector2 playerPos) {
	if (isShot_) {
		pos_.y -= speed_;
	}
	else {
		pos_.x = playerPos.x;
		pos_.y = playerPos.y;
	}

	if (pos_.y + size_.h <= 0) {
		isShot_ = false;
	}
}

void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_.w, (int)size_.h, 0.0f, WHITE, kFillModeSolid);
	}
}