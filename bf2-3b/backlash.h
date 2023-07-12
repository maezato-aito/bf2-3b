#pragma once

#include"Backlash.h"
#include"PadInput.h"
#include"Player.h"

class Backlash
{
private:
	int Speed;
	int BallAngle;
	int MoveX;
	int	MoveY;

public:

	// コンストラクタ
	Backlash();
	// デストラクタ
	~Backlash();

	//描画以外の処理
	void Update();

	//描画処理
	void Draw();
	Player* player;
};
