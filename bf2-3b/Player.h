#pragma once
#pragma once
#include "AbstractScene.h"

class Player : public AbstractScene
{
private:

public:

	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw() const override;
};