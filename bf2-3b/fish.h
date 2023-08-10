#pragma once



class Fish
{
private:
	int fBoxX,fBoxY,fBoxX2,fBoxY2;
	int fishBoxX, fishBoxY, fishBoxX2, fishBoxY2;
	int fishX, fishY;
	int pBoxX,pBoxY,pBoxX2,pBoxY2;
	int ChangeAnim;
	int Anim;
	int playerFlg;
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