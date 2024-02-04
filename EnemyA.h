#pragma once
#include "Enemy.h"

class EnemyA: public Enemy
{
private:
	int timer_;
public:
	EnemyA(Vector2 pos, int speed, Size size);
	void Update()override;
	void Draw()override;

	Vector2 GetPosition() { return pos_; }
	Size GetSize() { return size_; }
	void SetPosition(Vector2 pos) { pos_ = pos; }
	void SetSize(Size size) { size_ = size; }
};

