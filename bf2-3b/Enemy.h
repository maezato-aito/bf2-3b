#pragma once
#include "AbstractScene.h"

class Enemy
{
private:
	int EnemyG_img[18];
	int EnemyP_img[18];
	int EnemyR_img[18];

	int InputX, InputY;
	float SpeedX, SpeedY;
	int Gvy;

	// 敵のスコア
	int Score_g[3] = { 500, 1000, 750 };
	int Score_p[3] = { 750, 1500, 1000 };
	int Score_r[3] = { 1000, 2000, 1500 };

	int eSpeed[3] = { 1000, 2000, 1500 };

	int Lv;

	int PointFlg;
	int AnimFlg;
	float Count;
	int Counter;
	int AnimImg;

	// スタート時の座標
	int St_x;
	int St_y;

	// パラシュート時の座標
	int Pr_x;	
	int Pr_y;

	// 死亡時の座標
	int De_x;
	int De_y;

	// 敵の構造体
	struct ENEMY
	{
		int flg;			// 使用フラグ （ 0:表示なし　1:初期　2:浮遊　3:パラシュート　4:死亡 ）
		int type;			// タイプ
		int img;			// 画像
		float x, y, w, h;	// 座標、幅、高さ
		float speed;		// 速度
		int score;			// スコア加算ポイント
	};
	struct ENEMY enemy[3];
public:
	// コンストラクタ
	Enemy();
	// デストラクタ
	~Enemy();
	//描画以外の処理
	void Update();
	//描画処理
	void Draw() const;

	void EnemyStart();
	void Parachute();
	void Death();

	static int EnemyScore[3];	// 敵のスコア

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// 敵の当たり判定
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// 敵の風船の当たり判定
};
