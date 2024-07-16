#include <Novice.h>
#include "GameManager.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

const char kWindowTitle[] = "PG3_0501";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	char keys[256] = {0};
	char preKeys[256] = {0};
	GameManager* gameManager = new GameManager();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {

		Novice::BeginFrame();

		memcpy(preKeys, keys, 256);

		Novice::GetHitKeyStateAll(keys);

		gameManager->Run(keys, preKeys);

		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			break;
		}

		Novice::EndFrame();
	}

	// ライブラリの終了
	Novice::Finalize();

	return 0;
}
