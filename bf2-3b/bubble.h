#pragma once

class Bubble
{
private:

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

	int bubbleImg[4];
	//コンストラクタ
	Bubble();
	//デストラクタ
	~Bubble();
	//アップデート
	void Update();
	//描画
	void Draw();

};