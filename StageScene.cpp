#include <Novice.h>
#include <math.h>
#include "StageScene.h"
#include "Player.h"

StageScene::~StageScene()
{
	delete player_;
	delete enemy_;
}

void StageScene::Init()
{
	player_ = new Player({ 1280/2, 600 }, 64, 8);
	enemy_ = new Enemy({ 100, 100 }, 6, 32, true);
}

void StageScene::Update(char* keys, char* preKeys)
{
	/*プレイヤーの更新*/
	player_->Update(keys, preKeys);
	/*敵の更新*/
	enemy_->Update();

	float r1 = (float)enemy_->radius_;
	float r2 = (float)player_->bullet_->r_;

	float a = enemy_->pos_.x - player_->bullet_->pos_.x;
	float b = enemy_->pos_.y - player_->bullet_->pos_.y;
	float distance = sqrtf(a * a + b * b);

	//撃った弾と敵が当たったらクリア
	if (distance <= r1 + r2) {
		sceneNo = CLEAR;
	}

	float r3 = (float)player_->r_;
	float c = player_->pos_.x - enemy_->pos_.x;
	float d = player_->pos_.y - enemy_->pos_.y;
	float playerToEnemy = sqrtf(c * c + d * d);
	if (playerToEnemy <= r1 + r3) {
		sceneNo = OVER;
	}
}

void StageScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 255, kFillModeSolid);
	/*プレイヤーの描画関数*/
    /*敵の描画関数*/
	player_->Draw();
	enemy_->Draw();

}
