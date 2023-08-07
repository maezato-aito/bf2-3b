#include"fish.h"
#include"DxLib.h"
#include"common.h"

Fish::Fish()
{
	//画像の読み込み
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
	// 魚の当たり判定
	fishX = S1_Landleft_Width;
	fishY = S1_Landleft_Y;
	fBoxX = fishX + 6;
	fBoxY = fishY + 32;
	fBoxX2 = fBoxX + 50;
	fBoxY2 = fBoxY + 32;
}

Fish::~Fish()
{

}

void Fish::Update()
{
	if (fBoxX2 < S1_Landright_X) {
		fBoxX += 2;
		fBoxX2 += 2;
	}
	else if (fBoxX2 > S1_Landright_X) {
		fBoxX -= 2;
		fBoxX2 -= 2;
	}
}

void Fish::Draw()
{
	DrawBox(fBoxX, fBoxY, fBoxX2, fBoxY2, 0xff2255, FALSE);//プレイヤーのbox
	DrawExtendGraph(270, 400, 320, 450, fishImg[2], TRUE);
	
}