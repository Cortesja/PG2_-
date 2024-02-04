#include "Enemy.h"
#include "Novice.h"

void Enemy::Update() {

	//ここに更新処理記述してください

	pos_.x -= speed_;

	if (pos_.x >= kWindowWidth + size_.w || pos_.x <= kWindowWidth - size_.w) {
		speed_ *= -1;
	}
}

void Enemy::Draw() {

	//ここに描画処理記述してください

	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_.w, (int)size_.h, 0.0f, RED, kFillModeSolid);
}