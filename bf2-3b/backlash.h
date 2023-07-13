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
	int HitBox;
	int x1, y1,x2,y2;
public:
	int Left, Right, North, South;
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
