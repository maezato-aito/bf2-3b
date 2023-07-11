#pragma once

#include"backlash.h"

class backlash
{
private:
	
public:

	// コンストラクタ
	backlash();
	// デストラクタ
	~backlash();

	//描画以外の処理
	void Update()override;

	//描画処理
	void Draw() const override;
};
