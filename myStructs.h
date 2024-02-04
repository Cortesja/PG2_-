#pragma once

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

enum scene {
	gameTitle,
	gameMain,
	gameOver
};

typedef struct Vector2 {
	float x;
	float y;
}Vector2;

typedef struct Size {
	float w;
	float h;
}Size;