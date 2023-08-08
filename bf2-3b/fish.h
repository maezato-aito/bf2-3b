#pragma once



class Fish
{
private:
	int fBoxX,fBoxY,fBoxX2,fBoxY2;
	int fishX, fishY;
	int pBoxX,pBoxY,pBoxX2,pBoxY2;
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