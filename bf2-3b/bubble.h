#pragma once

class Bubble
{
private:
	int bubbleFlg;
public:

	//泡の位置
	float bubbleX;
	float bubbleY;

	//泡の上昇量
	float bubbleUp;

	//泡の横の移動量
	float bubbleSide;

	//泡の右上
	float bX0;
	float bY0;

	//泡の左下
	float bX1;
	float bY1;

	//画像
	int bubbleImg[4];

	//アニメーション用カウンタ
	int bubbleC;
	int bubbleAC;

	//泡の種類の順番
	int bAv;

	int b;
	//コンストラクタ
	Bubble();
	//デストラクタ
	~Bubble();
	//アップデート
	void Update();
	//描画
	void Draw();

};