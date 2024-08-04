#include <Novice.h>
#include "GameOver.h"

void GameOver::Init() {}

void GameOver::Update(char* keys, char* preKeys)
{
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = /*タイトルへ*/TITLE;
	}
}

void GameOver::Draw()
{
	//クリア画面表示
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffff0000, kFillModeSolid);
	Novice::ScreenPrintf(600, 360, "Game Over!!");
}