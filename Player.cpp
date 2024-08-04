#include "Player.h"
#include "Novice.h"
#include "tama.h"

Player::Player(Vector2 pos, int r, int speed)
{
	pos_ = pos;
	r_ = r;
	speed_ = speed;

	bullet_ = new Bullet({ 0, 0 }, 15, 10, false);
}

Player::~Player()
{
	delete bullet_;
}

void Player::Update(char* keys, char* preKeys)
{

	if (keys[DIK_W] && preKeys[DIK_W])pos_.y -= speed_;

	if (keys[DIK_S] && preKeys[DIK_S])pos_.y += speed_;

	if (keys[DIK_A] && preKeys[DIK_A])pos_.x -= speed_;

	if (keys[DIK_D] && preKeys[DIK_D])pos_.x += speed_;

	if (pos_.x <= r_) {
		pos_.x =(float)r_;
	}
	if (pos_.x >= 1280 - r_) {
		pos_.x = 1280 - (float)r_;
	}
	if (pos_.y >= 720 - r_) {
		pos_.y = 720 - (float)r_;
	}
	if (pos_.y <= 400) {
		pos_.y = 400;
	}


	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet_->isShot_ == false)
	{
		bullet_->pos_ = pos_;
		bullet_->isShot_ = true;
	}

	bullet_->Update();
}

void Player::Draw()
{
	int texture_ = Novice::LoadTexture("Player.png");
	//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, r_, r_, 0.0f, GREEN, kFillModeSolid);
	Novice::DrawSprite((int)pos_.x-r_, (int)pos_.y-r_, texture_, 1.0f, 1.0f, 0.0f, WHITE);
	bullet_->Draw();
}
