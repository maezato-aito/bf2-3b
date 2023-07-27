#pragma once

class Fish
{
private:
public:

	//画像用
	int fishImg[10];
	//	コンストラクタ
	Fish();
	//デストラクタ
	~Fish();
	//アップデート
	void Update();
	//描画
	void Draw();
};