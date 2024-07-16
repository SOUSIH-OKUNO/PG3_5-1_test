#pragma once
#include "IScene.h"
#include "Vector2.h"
#include "Player.h"
#include "Enemy.h"

/*ISceneをパブリック継承してStageSceneクラスを定義*/
class StageScene:public IScene
{
public:
	~StageScene();
	/* 継承したInit、Update、Draw関数をoverride定義*/
	void Init()override;
	void Update(char* keys, char* preKeys) override;
	void Draw()override;
	

public:
	Player* player_;
	Enemy* enemy_;
};