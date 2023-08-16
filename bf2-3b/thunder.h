#pragma once
#include "AbstractScene.h"
#define S1_Thunder_X (400)
#define S1_Thunder_Y (100)

class thunder
{
private:
	int CloudImg[3];	//雷画像
	int C_AnimImg;      //雷アニメ画像
	int Time;
	int pointFlg;
	int countFlg;
	int blinkCycle;
	int AnimFlg = 0b0000;
	int centerX;
	int centerY;
	int ranDirection;
	int incFlg;
	int TimeFlg;
	int moveAmount;
	int x;
	int y;
	bool once;
	int A_Flg;
	int C_Flg;
	int A_ThunderImg;
	int ThunderImg[6];
	int A_nimFlg = 0b0000;
	int BallX;
	int BallY;
	int MoveX;
	int MoveY;
	int BallImg[3];
	int A_BallImg;
	int speed;
	float BallAngle;
	float T_Angle;
	float rad;
	int centerx;
	int centery;
	int MoveAmount;
public:

	// コンストラクタ
	thunder();
	// デストラクタ
	~thunder();

	//描画以外の処理
	void Update();

	void Circle();

	void Anim();

	void Ball();

	void ChangeAngle();

	//描画処理
	void D_thunder();
};
