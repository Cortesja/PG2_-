#pragma once
#include "Object.h"

class Enemy: public Object
{
public:
	~Enemy() {};
	virtual void Update();
	virtual void Draw();

	Vector2 GetPosition() { return pos_; }
	Size GetSize() { return size_; }
	void SetPosition(Vector2 pos) { pos_ = pos; }
	void SetSize(Size size) { size_ = size; }
};

