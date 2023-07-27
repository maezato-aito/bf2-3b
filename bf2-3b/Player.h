#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	float playerX, playerY;
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
	float vx, vy;		//ベクトル
	float e;			// 反発係数
public:

	int PlayerFlg=0; //地面の状態を0　空中なら1をいれる

	//プレイヤーコリジョン
	static int pBoxX;
	static int pBoxY;
	static int pBoxX2;
	static int pBoxY2;

	//風船コリジョン
	static int bBoxX;
	static int bBoxY;
	static int bBoxX2;
	static int bBoxY2;

	float Gvy;
	float Speed;
	int playerLR;
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw() const override;
};