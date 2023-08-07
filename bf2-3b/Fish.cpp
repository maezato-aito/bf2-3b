#include"fish.h"
#include"DxLib.h"
#include"common.h"

Fish::Fish()
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
	// ‹›‚Ì“–‚½‚è”»’è
	fishX = S1_Landleft_Width;
	fishY = S1_Landleft_Y;
	fBoxX = fishX + 6;
	fBoxY = fishY;
	fBoxX2 = fBoxX + 38;
	fBoxY2 = fBoxY + 64;
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
	if (fBoxX2 > S1_Landright_X) {
		fBoxX -= 2;
		fBoxX2 -= 2;
	}
}

void Fish::Draw()
{
	DrawBox(fBoxX, fBoxY, fBoxX2, fBoxY2, 0xff2255, FALSE);//ƒvƒŒƒCƒ„[‚Ìbox
	DrawExtendGraph(270, 400, 320, 450, fishImg[2], TRUE);
	
}