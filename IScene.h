#pragma once

enum SCENE { 
	TITLE, //タイトル
	STAGE, //ゲームシーン
	CLEAR //クリア
};

class IScene {
protected: 

	static int sceneNo;
public: 
  
	virtual void Init()=0;/*Init()を純粋仮想関数で定義*/;
	virtual void Update(char* keys, char* preKeys)=0;/*Update()を純粋仮想関数で定義  引数は(char* keys, char* preKeys)*/;
	virtual void Draw()=0;/*Draw()を純粋仮想関数で定義*/;

	virtual ~IScene();

	int GetSceneNo();
};
