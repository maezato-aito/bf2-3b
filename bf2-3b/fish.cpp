#include"fish.h"
#include"DxLib.h"
#include"common.h"
#include"Player.h"

Fish::Fish()
{
	//âÊëúÇÃì«Ç›çûÇ›
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
	// ãõÇÃìñÇΩÇËîªíË
	fishX = S1_Landleft_w;
	fishY = S1_Landleft_Y;
	fBoxX = fishX;
	fBoxY = fishY;
	fBoxX2 = fBoxX + 64;
	fBoxY2 = fBoxY + 64;

}

Fish::~Fish()
{

}

void Fish::Update()
{
	pBoxX = Player::pBoxX;
	pBoxY = Player::pBoxY;
	pBoxX2 = Player::pBoxX2;
	pBoxY2 = Player::pBoxY2;

	if (pBoxX2 > fBoxX2 && fBoxX2 <= S1_Landright_X) {
		fBoxX += 3;
		fBoxX2 += 3;
	}
	if (pBoxX2 < fBoxX2 && fBoxX >= S1_Landleft_w) {
		fBoxX -= 3;
		fBoxX2 -= 3;
	}
}

void Fish::Draw()
{
	DrawBox(fBoxX, fBoxY, fBoxX2, fBoxY2, 0xff2255, FALSE);//ÉvÉåÉCÉÑÅ[ÇÃbox
	DrawExtendGraph(fBoxX, fBoxY, fBoxX2, fBoxY2, fishImg[2], TRUE);
	
}