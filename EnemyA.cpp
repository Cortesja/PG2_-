#include "EnemyA.h"
#include "Novice.h"

EnemyA::EnemyA(Vector2 pos, int speed, Size size) {
	pos_ = pos;
	speed_ = speed;
	size_ = size;

	timer_ = 120;
}

void EnemyA::Update() {
	pos_.x += speed_;

	if (pos_.x >= kWindowWidth - size_.w || pos_.x <= 0 + size_.w) {
		speed_ *= -1;
	}

	if (!isAlive_) {
		timer_--;
		if (timer_ <= 0) {
			SetPosition({ (float)kWindowWidth / 2, 200.0f});
			timer_ = 120;
			isAlive_ = true;
		}
	}
}

void EnemyA::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_.w, (int)size_.h, 0.0f, RED, kFillModeSolid);
	}
}