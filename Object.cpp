#include "Object.h"

bool chkObjHit(Vector2 playerPos, Size playerSize, Vector2 objPos, Size objSize) {
	if (playerPos.x < objPos.x + objSize.w && objPos.x < playerPos.x + playerSize.w) {
		if (playerPos.y < objPos.y + objSize.h && objPos.y < playerPos.y + playerSize.h) {
			return true;
		}
	}
	return false;
}