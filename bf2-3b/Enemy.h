#pragma once
#include "AbstractScene.h"
#include "fish.h"

class Enemy
{
private:
	int EnemyG_img[18];
	int EnemyP_img[18];
	int EnemyR_img[18];

	int InputX = 0, InputY = 0;
	float Speed, SpeedY;
	float Gvy;
	float MoveX;

	float eSpeed[3] = { 0.3, 0.6, 0.9 };		// 敵のスピード
	float eSpeed2[3] = { 1.0, 1.5, 2.0 };		// 敵のスピード（回避）

	int EnemyPScore[3] = { 500, 1000, 750 };	// 敵のスコア
	int EnemyGScore[3] = { 750, 1500, 1000 };	// 敵のスコア
	int EnemyRScore[3] = { 1000, 2000, 1500 };	// 敵のスコア

	
	int PointFlg;	// ポイントフラグ
	int AnimFlg;	// アニメーションフラグ
	float Count;
	int Counter;
	int AnimImg;	// アニメーション画像用
	float AnimCount;
	int EnemyLR;
	int rand;		// 乱数用
	int e;			// 反発係数
	int HitFlg;
	int vx, vy;
	float UpNum;
	int UpFlg;
	int Time;

	// 敵の構造体
	static struct ENEMY
	{
		int flg;			// 使用フラグ （ 0:表示なし　1:初期　2:浮遊　3:パラシュート　4:死亡 ）
		int type;			// タイプ
		int img;			// 画像
		float x, y, w, h;	// 座標、幅、高さ
		float speed;		// 速度
		int score;			// スコア加算ポイント
	};
	struct ENEMY enemy[3];
	
	Fish* fish;

public:
	static int Lv;

	static int enemyFlg;
	// コンストラクタ
	Enemy();
	// デストラクタ
	~Enemy();
	//描画以外の処理
	void Update();
	//描画処理
	void Draw() const;

	void EnemyInit();	// 敵初期化処理
	void EnemyStart();	// 初期状態処理
	void Parachute();	// パラシュート処理
	void Death();		// 死亡処理
	void Backlash();	// 反発処理

	static int St_x, St_y;	// スタート時の座標
	static int Pr_x, Pr_y;	// パラシュート時の座標
	static int De_x, De_y;	// 死亡時の座標

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// 敵の当たり判定
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// 敵の風船の当たり判定

	static int Score;

	static int EnemyDeath();

};
