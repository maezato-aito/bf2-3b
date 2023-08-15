#pragma once
class UI
{
private:
	int Iimg;
	int Topimg;
	int Numberimg[10];
	int INumber[6];
	int TopNumber[6];
	int Ballonimg;

	int FontHandle;
	int CharGrHandle[10][1];
	int i;
	int j;

public:
	// コンストラクタ
	UI();
	// デストラクタ
	~UI();
	//描画以外の処理
	void Update();
	//描画処理
	void Draw() const;

	static int BestScore;
	static int NowScore;
};

