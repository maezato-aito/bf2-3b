#pragma once
class UI
{
private:

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

