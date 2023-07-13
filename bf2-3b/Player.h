#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
public:

	int PlayerStus=0; //地面の状態を0　空中なら1をいれる

	int boxX=100, boxY=100, boxX2=boxX+50, boxY2=boxY+50;
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw() const override;
};