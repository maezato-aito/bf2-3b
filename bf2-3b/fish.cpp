#include"fish.h"
#include"DxLib.h"
#include"common.h"
#include"Player.h"
#include"Enemy.h"

Fish::Fish()
{
	//æÌÇÝÝ
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
	// Ì½è»è
	fishX = S1_Landleft_Width;
	fishY = S1_Landleft_Y;
	fBoxX = fishX;
	fBoxY = fishY;
	fBoxX2 = fBoxX + 64;
	fBoxY2 = fBoxY + 70;
	// Ìs®ÍÍ
	fishBoxX = S1_Landleft_Width;
	fishBoxY = 410;
	fishBoxX2 = S1_Landright_X;
	fishBoxY2 = 480;
	ChangeAnim = 0;
	Anim = 0;
	rand = 100;
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
	playerFlg = Player::PlayerFlg;
	//GÌ{bNX
	eBoxX = Enemy::eBoxX;
	eBoxY = Enemy::eBoxY;
	eBoxX2 = Enemy::eBoxX2;
	eBoxY2 = Enemy::eBoxY2;
	// GÌDÌ{bNX
	ebBoxX = Enemy::ebBoxX;
	ebBoxY = Enemy::ebBoxY;
	ebBoxX2 = Enemy::ebBoxX2;
	ebBoxY2 = Enemy::ebBoxY2;
	/*if (pBoxX2 > fBoxX2 && fBoxX2 <= S1_Landright_X) {
		fBoxX += 3;
		fBoxX2 += 3;
	}
	if (pBoxX2 < fBoxX2 && fBoxX >= S1_Landleft_Width) {
		fBoxX -= 3;
		fBoxX2 -= 3;
	}*/
	if (pBoxX <= fishBoxX2 && pBoxX2 >= fishBoxX && pBoxY2 >= fishBoxY+10&& Player::PlayerFlg != 0) {
		rand = GetRand(99);
		ChangeAnim++;
		if (ChangeAnim >= 0 && ChangeAnim < 10 && rand<=30) {
			Anim = 0;
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			fBoxY -= 6;
			fBoxY2 -= 6;
		}
		if (ChangeAnim >= 10 && ChangeAnim < 20) {
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			Anim = 1;
		}
		if (ChangeAnim >= 20 && ChangeAnim < 30 && pBoxY <= fBoxY2) {
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			Anim = 6;
			Player::PlayerFlg = 0;
		}
		else if (ChangeAnim >= 20 && ChangeAnim < 30) {
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			Anim = 2;
		}

		if (ChangeAnim >= 30 && ChangeAnim < 40) {
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			Anim = 3;
		}

		if (ChangeAnim >= 40 && ChangeAnim < 50) {
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			Anim = 4;
			fBoxY += 2;
			fBoxY2 += 2;
		}
		if (ChangeAnim >= 50 && ChangeAnim < 60) {
			fBoxX = pBoxX;
			fBoxX2 = pBoxX2;
			Anim = 5;
			fBoxY += 2;
			fBoxY2 += 2;
		}
		if (ChangeAnim >= 60) {
			ChangeAnim = 0;
		}	
	}
	if (Player::PlayerFlg == 0 || Anim == 6) {
		ChangeAnim++;
		if (ChangeAnim >= 30 && ChangeAnim < 40) {
			Anim = 3;
		}

		if (ChangeAnim >= 40 && ChangeAnim < 50) {
			Anim = 4;
			if (fBoxY == 396) {
				fBoxY += 1;
				fBoxY2 += 1;
			}
		}
		if (ChangeAnim >= 50 && ChangeAnim < 60) {
			Anim = 5;
			if (fBoxY <= 398) {
				fBoxY += 4;
				fBoxY2 += 4;


			}
		}
	}
	if (pBoxY2 <= fishBoxY+10) {
		fBoxY = 410;
		fBoxY2 = 480;
		Anim = 0;
		ChangeAnim = 0;
	}
	

	if (eBoxY2 >= fishBoxY) {

		ChangeAnim++;
		if (ChangeAnim >= 0 && ChangeAnim < 10) {
			Anim = 0;
			fBoxX = eBoxX;
			fBoxX2 = eBoxX2;
			fBoxY -= 4;
			fBoxY2 -= 4;
		}
		if (ChangeAnim >= 10 && ChangeAnim < 20) {
			Anim = 1;
		}
		if (ChangeAnim >= 20 && ChangeAnim < 30) {
			Anim = 6;
		}
		else if (ChangeAnim >= 20 && ChangeAnim < 30) {
			Anim = 2;
		}

		if (ChangeAnim >= 30 && ChangeAnim < 40) {
			Anim = 3;
		}

		if (ChangeAnim >= 40 && ChangeAnim < 50) {
			Anim = 4;
			fBoxY += 2;
			fBoxY2 += 2;
		}
		if (ChangeAnim >= 50 && ChangeAnim < 60) {
			Anim = 5;
			fBoxY += 2;
			fBoxY2 += 2;
		}
		if (ChangeAnim >= 60) {
			ChangeAnim = 61;
		}

	}

}

void Fish::Draw()
{
	DrawBox(fBoxX, fBoxY, fBoxX2, fBoxY2, 0xff2255, FALSE);//vC[Ìbox
	DrawBox(fishBoxX, fishBoxY, fishBoxX2, fishBoxY2, 0xffff55, FALSE); // Ìs®ÍÍ
	/*DrawBox(fishBoxX, fishBoxY, fishBoxX2, fishBoxY2, 0xff2255, FALSE);*/
	DrawExtendGraph(fBoxX, fBoxY, fBoxX2, fBoxY2, fishImg[Anim], TRUE);
#if _DEBUG
	DrawFormatString(0, 350, 0xffffff, "óÔ %d", ChangeAnim, TRUE);
	DrawFormatString(0, 380, 0xffffff, "m¦ %d", rand, TRUE);
#endif _DEBUG
}

