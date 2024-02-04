#pragma once
#include "Object.h"

class Bullet: Object
{
public:
	Bullet(int speed, Size size);
	~Bullet() {};

	void Update(Vector2 playerPos);
	void Draw();

	bool isShot_;

	Vector2 GetPosition() { return pos_; }
	Size GetSize() { return size_; }
	void SetPosition(Vector2 pos) { pos_ = pos; }
	void SetSize(Size size) { size_ = size; }
};

