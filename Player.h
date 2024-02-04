#pragma once
#include "Object.h"
#include "Bullet.h"

class Player : public Object
{
public:
	Player(Vector2 pos, Size size, bool isAlive);
	~Player();
	Bullet* bullet;

	void Update(char keys[], char preKeys[]);
	void Draw();

	Vector2 GetPosition() { return pos_; }
	Size GetSize() { return size_; }
	void SetPosition(Vector2 pos) { pos_ = pos; }
	void SetSize(Size size) { size_ = size; }
};