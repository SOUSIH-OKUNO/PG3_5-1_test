#pragma once
#include "IScene.h"


/*ISceneをパブリック継承してTitleSceneクラスを定義*/
class TitleScene:public IScene
	
{
public:
	/* 継承したInit、Update、Draw関数をoverride定義*/
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};
