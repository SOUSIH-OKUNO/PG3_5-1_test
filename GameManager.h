#pragma once

#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include"GameOver.h"
#include <Novice.h>

using namespace std;

class GameManager
{
public:

	GameManager();
	~GameManager();

	int Run(char* keys, char* preKeys);
private:
	unique_ptr<IScene> sceneArr_[4];

	int currentSceneNo_;
	int prevSceneNo_;
};
