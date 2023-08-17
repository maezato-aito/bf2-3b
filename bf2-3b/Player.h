#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:
	
	int InputX = 0, InputY = 0;
	int Playerimg[30];
	int Image;
	int BGM;
	float vx, vy;		//ベクトル
	float e;			// 反発係数
	int eBoxX, eBoxY, eBoxX2, eBoxY2; //敵の判定
	int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2; //敵の風船の判定
	int fall;
	int AnimCount;
	int add;
	int fBoxY;
	int death;
	float a;

	int Count;
public:
	static float playerX, playerY;
	static int Time; // 待機時間
	
	static int Life;	// 残機
	static int PlayerFlg; //地面の状態を0　空中なら1をいれる
	int HitFlg = 0;	//横に触れていたら0 触れていなかったら１
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
	int gCount;
	int buttonC;

	float UpNum;
	int UpFlg;

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

	void backlash();

	void life();

	void balloon();
};