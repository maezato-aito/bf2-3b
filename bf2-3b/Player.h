#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	int InputX = 0, InputY = 0;
	int boxX, boxY, boxX2, boxY2;
public:

	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw() const override;
};