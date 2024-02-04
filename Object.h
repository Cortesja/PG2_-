#pragma once
#include "myStructs.h"

bool chkObjHit(Vector2 playerPos, Size playerSize, Vector2 objPos, Size objSize);

class Object
{
protected:
	Vector2 pos_;
	Size size_;
	int speed_;
public:
	bool isAlive_;
};