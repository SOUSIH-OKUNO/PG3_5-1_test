#pragma once
#include "Vector2.h"

class Enemy {
public:
	Enemy(Vector2 pos, int s, int r, int isAlive);
	void Update();
	void Draw();
public:
	Vector2 pos_;
	int speed_;
	int radius_;
	bool isAlive_;
};