#pragma once
#include "AbstractScene.h"
#define S1_Thunder_X (200)
#define S1_Thunder_Y (100)

class thunder
{
private:
	int ThunderImg[3];	//雷画像
	int T_AnimImg;      //雷アニメ画像
public:

	// コンストラクタ
	thunder();
	// デストラクタ
	~thunder();

	//描画以外の処理
	void Update();

	//描画処理
	void D_thunder();
};
