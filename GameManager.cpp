#include "GameManager.h"
using namespace std;

GameManager::GameManager()
{
	sceneArr_[TITLE] = std::make_unique<TitleScene>();/*TitleSceneを実体化*/;
	sceneArr_[STAGE] = std::make_unique<StageScene>();/*StageSceneを実体化*/;
	sceneArr_[CLEAR] = std::make_unique<ClearScene>(); /*ClearSceneを実体化*/;

	currentSceneNo_ = TITLE;
}

GameManager::~GameManager()
{
}

int GameManager::Run(char* keys, char* preKeys)
{
	/*1つ前のSceneNo*/ prevSceneNo_= /*今のSceneNo*/currentSceneNo_;
	/*今のSceneNo*/currentSceneNo_ = sceneArr_[/*今のSceneNo*/currentSceneNo_]->GetSceneNo();

	if (/*1つ前のSceneNo*/ prevSceneNo_!= /*今のSceneNo*/currentSceneNo_)
	{
		sceneArr_[/*今のSceneNo*/currentSceneNo_]->Init();
	}

	sceneArr_[/*今のSceneNo*/currentSceneNo_]->Update(keys, preKeys);
	sceneArr_[/*今のSceneNo*/currentSceneNo_]->Draw();

	return 0;
}