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
	int eBoxX, eBoxY, eBoxX2, eBoxY2; //敵の判定
	int ebBoxX, ebBoxY, ebBoxX2, ebBoxY2; //敵の風船の判定
	int rand; // 確率
	int enemy;
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