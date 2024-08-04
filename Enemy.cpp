#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy(Vector2 pos, int s, int r, int isAlive)
{
	pos_ = pos;
	radius_ = r;
	speed_ = s;
	isAlive_ = isAlive;

}

void Enemy::Update() {
	pos_.x += speed_;

	// 画面端に当たったら反対に移動
	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
		speed_ *= -1;
		pos_.y = pos_.y + radius_;
	}

}

	void Enemy::Draw(){
		int texture_ = Novice::LoadTexture("Enemy1.png");
		//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
		Novice::DrawSprite((int)pos_.x - radius_, (int)pos_.y - radius_, texture_, 1.0f, 1.0f, 0.0f, WHITE);

	}
