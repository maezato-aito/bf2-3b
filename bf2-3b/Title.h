#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene
{
private:
	int TitleLogoimage;	// タイトルロゴ画像
	int TitleOimage;	// options（選択肢）
	int TitleNOCimage; //name of company（社名)

	int TitleBimage[4];//タイトルの風船

	int bCount;
	int animImage;

public:

	// コンストラクタ
	Title();
	// デストラクタ
	~Title();

	//描画以外の処理
	AbstractScene* Update()override;

	//描画処理
	void Draw()const override;
};

