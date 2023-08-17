#pragma once

#include "Player.h"

class GameOver
{
private:
	Player* player;
	int Gameover;
	int pBoxX, pBoxY, pBoxX2, pBoxY2;
	int SEGameOver;
public:

	
	//	コンストラクタ
	GameOver();
	//デストラクタ
	~GameOver();
	//アップデート
	void Update();
	//描画
	void Draw();
};

