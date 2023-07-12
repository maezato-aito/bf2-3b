#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
public:
	int boxX=100, boxY=100, boxX2=150, boxY2=150;
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw() const override;
};