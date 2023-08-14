#pragma once
#include "AbstractScene.h"

class Enemy
{
private:
	int EnemyG_img[18];	// 敵（緑）の画像
	int EnemyP_img[18];	// 敵（ピンク）の画像
	int EnemyR_img[18];	// 敵（赤）の画像

	int InputX, InputY;
	float SpeedX, SpeedY;
	int Gvy;	// 重力
	int Cnt;	// 時間カウント用
	int Dflg;	// 死亡フラグ

	float eSpeed[3] = { 1, 1.25, 2.5 };		// 敵のスピード
	int EnemyWait[3] = { 3, 2, 1 };			// 風船をふくらますときの待ち時間

	int EnemyPScore[3] = { 500, 1000, 750 };	// 敵（ピンク）のスコア
	int EnemyGScore[3] = { 750, 1500, 1000 };	// 敵（緑）のスコア
	int EnemyRScore[3] = { 1000, 2000, 1500 };	// 敵（赤）のスコア

	int Lv;			//敵のレベル 

	int PointFlg;	// スコアフラグ
	int AnimFlg;	// アニメーションフラグ
	float Count;	// 時間カウント用
	int Counter;	// 時間カウンター
	int AnimImg;	// イメージ画像用

	int WaitTime;	// 待ち時間
	int NowTime;	// 今の時間
	
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

	void EnemyStart();	// 初期状態処理
	void Parachute();	// パラシュート処理
	void Death();		// 死亡処理
	void Wait();

	static int St_x, St_y;	// スタート時の座標
	static int Pr_x, Pr_y;	// パラシュート時の座標
	static int De_x, De_y;	// 死亡時の座標

	static int eBoxX, eBoxY, eBoxX2, eBoxY2;		// 敵の当たり判定
	static int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2;	// 敵の風船の当たり判定

	static int Score;
};
