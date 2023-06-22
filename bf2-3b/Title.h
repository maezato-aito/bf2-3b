#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene
{
private:
	int Titleimage;	// タイトル画像

public:

	// コンストラクタ
	Title();
	// デストラクタ
	~Title();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw()const override;
};

