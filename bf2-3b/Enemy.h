#pragma once
#include "AbstractScene.h"

class Enemy
{
private:
	int EnemyG_img[18];
	int EnemyP_img[18];
	int EnemyR_img[18];
public:
	// コンストラクタ
	Enemy();
	// デストラクタ
	~Enemy();
	//描画以外の処理
	void Update();

	//描画処理
	void Draw() const;
};

