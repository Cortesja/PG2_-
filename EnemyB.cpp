#include "EnemyB.h"
#include "Novice.h"

EnemyB::EnemyB(Vector2 pos, int speed, Size size) {
	pos_ = pos;
	speed_ = speed;
	size_ = size;

	speedY_ = speed;

	timer_ = 180;
}

void EnemyB::Update() {
	pos_.x += speed_;
	pos_.y += speedY_;

	if (pos_.x >= kWindowWidth - size_.w || pos_.x <= 0 + size_.w) {
		speed_ *= -1;
	}
	if (pos_.y >= kWindowHeight - size_.h || pos_.y <= 0 + size_.h) {
		speedY_ *= -1;
	}

	if (!isAlive_) {
		timer_--;
		if (timer_ <= 0) {
			SetPosition({ 300.0f, 200.0f });
			timer_ = 180;
			isAlive_ = true;
		}
	}
}

void EnemyB::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_.w, (int)size_.h, 0.0f, RED, kFillModeSolid);
	}
}