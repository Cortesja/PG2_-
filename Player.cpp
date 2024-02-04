#include "Player.h"
#include "Novice.h"

Player::Player(Vector2 pos, Size size, bool isAlive) {
	pos_ = pos;
	size_ = size;
	isAlive_ = isAlive;

	speed_ = 5;

	bullet = new Bullet(7,{15.0f,15.0f});
}

Player::~Player() {
	bullet->~Bullet();
}

void Player::Update(char keys[], char preKeys[]) {

	if (isAlive_) {
		if (keys[DIK_A] || keys[DIK_LEFT]) {
			pos_.x -= speed_;
		}
		if (keys[DIK_D] || keys[DIK_RIGHT]) {
			pos_.x += speed_;
		}

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			bullet->isShot_ = true;
		}
	}

	bullet->Update(pos_);
}

void Player::Draw() {
	if (isAlive_) {
		bullet->Draw();
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_.w, (int)size_.h, 0.0f, BLUE, kFillModeSolid);
	}
}