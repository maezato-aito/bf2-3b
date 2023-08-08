#include"fish.h"
#include"DxLib.h"
#include"common.h"
#include"Player.h"

Fish::Fish()
{
	//âÊëúÇÃì«Ç›çûÇ›
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
	// ãõÇÃìñÇΩÇËîªíË
	fishX = S1_Landleft_Width;
	fishY = S1_Landleft_Y;
	fBoxX = fishX;
	fBoxY = fishY;
	fBoxX2 = fBoxX + 64;
	fBoxY2 = fBoxY + 64;
	ChangeAnim = 0;
	Anim = 0;
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
	if (pBoxX2 < fBoxX2 && fBoxX >= S1_Landleft_Width) {
		fBoxX -= 3;
		fBoxX2 -= 3;
	}
	ChangeAnim++;
	if (pBoxX <= fBoxX2 && pBoxX2 >= fBoxX && pBoxY2 >= fBoxY+16) {
		if (ChangeAnim >= 0 && ChangeAnim < 10) {
			Anim = 0;
		}
		if (ChangeAnim >= 10 && ChangeAnim < 20) {
			Anim = 1;
		}
		if (ChangeAnim >= 20 && ChangeAnim < 30) {
			Anim = 2;
		}
		if (ChangeAnim >= 30 && ChangeAnim < 40) {
			Anim = 3;
		}
		if (ChangeAnim >= 40 && ChangeAnim < 50) {
			Anim = 4;
		}
		if (ChangeAnim >= 50 && ChangeAnim < 60) {
			Anim = 5;
		}
		if (ChangeAnim >= 60) {
			ChangeAnim = 0;
		}
	}
}

void Fish::Draw()
{
	DrawBox(fBoxX, fBoxY, fBoxX2, fBoxY2, 0xff2255, FALSE);//ÉvÉåÉCÉÑÅ[ÇÃbox
	DrawExtendGraph(fBoxX, fBoxY, fBoxX2, fBoxY2, fishImg[Anim], TRUE);
	
}