#pragma once
#include "Vector2.h"

class Bullet
{
public:
	Vector2 pos_;
	int speed_;
	int r_;
	bool isShot_;

public:
	Bullet(Vector2 pos, int speed, int r, bool isShot);
	void Update();
	void Draw();
};
