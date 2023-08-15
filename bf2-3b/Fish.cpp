#include"fish.h"
#include"DxLib.h"
#include"common.h"
#include"Player.h"
#include"Enemy.h"

int Fish::fBoxY;
int Fish::fBoxY2;


Fish::Fish()
{
	//画像の読み込み
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, fishImg);
	// 魚の当たり判定
	fishX = S1_Landleft_Width;
	fishY = S1_Landleft_Y;
	fBoxX = fishX;
	fBoxY = fishY;
	fBoxX2 = fBoxX + 64;
	fBoxY2 = fBoxY + 70;
	// 魚の行動範囲
	fishBoxX = S1_Landleft_Width;
	fishBoxY = 410;
	fishBoxX2 = S1_Landright_X;
	fishBoxY2 = 480;
	ChangeAnim = 0;
	Anim = 0;
	rand = 100;
	count = 0;
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
	//敵のボックス
	eBoxX = Enemy::eBoxX;
	eBoxY = Enemy::eBoxY;
	eBoxX2 = Enemy::eBoxX2;
	eBoxY2 = Enemy::eBoxY2;
	// 敵の風船のボックス
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
	if (pBoxX <= fishBoxX2 && pBoxX2 >= fishBoxX && pBoxY2 > fishBoxY+1  && Player::PlayerFlg != 0) {
		rand = GetRand(99);
		count++;
		if (count > 180) {
			ChangeAnim++;
			if (count > 180 && ChangeAnim >= 0 && ChangeAnim < 10 && rand <= 30) {
				Anim = 0;
				fBoxX = pBoxX;
				fBoxX2 = pBoxX2;
				fBoxY -= 8;
				fBoxY2 -= 8;
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
				fBoxY += 4;
				fBoxY2 += 4;
			}
			if (ChangeAnim >= 50 && ChangeAnim < 60) {
				fBoxX = pBoxX;
				fBoxX2 = pBoxX2;
				Anim = 5;
				fBoxY += 4;
				fBoxY2 += 4;
			}
			if (ChangeAnim >= 60) {
				ChangeAnim = 0;
				
			}
		}
	}
	if (Player::PlayerFlg == 0 || Enemy::enemyFlg == 0 || Player::Life == 1 || Player::Life == 0) {
		ChangeAnim++;
		if (ChangeAnim >= 30 && ChangeAnim < 40) {
			Anim = 3;
		}

		if (ChangeAnim >= 40 && ChangeAnim < 50) {
			Anim = 4;
			if (fBoxY == 396) {
				fBoxY += 2;
				fBoxY2 += 2;
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
	if (pBoxY2 <= fishBoxY + 10 && fishBoxY < fBoxY && Anim == 5) {
		fBoxY = 410;
		fBoxY2 = 480;
		Anim = 0;
		ChangeAnim = 0;
		count = 0;
	}


	if (eBoxY2 > fishBoxY &&eBoxX > 160 && eBoxX2 < 480 ) {
		
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
		if (ChangeAnim >= 20 && ChangeAnim < 30 && Enemy::enemyFlg == 1) {
			Anim = 7;
			Enemy::enemyFlg = 0;

		}
		else if (ChangeAnim >= 20 && ChangeAnim < 30 && Enemy::enemyFlg == 2) {
			Anim = 8;
			Enemy::enemyFlg = 0;
		}
		else if (ChangeAnim >= 20 && ChangeAnim < 30 && Enemy::enemyFlg == 3) {
			Anim = 9;
			Enemy::enemyFlg = 0;
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
			ChangeAnim = 0;
			
		}

	}
	if (count > 180 && playerFlg == 0 || pBoxY2 < fishBoxY ) {
		count = 0;
	}
}

void Fish::Draw()
{
	DrawBox(fBoxX, fBoxY, fBoxX2, fBoxY2, 0xff2255, FALSE);//プレイヤーのbox
	DrawBox(fishBoxX, fishBoxY, fishBoxX2, fishBoxY2, 0xffff55, FALSE); // 魚の行動範囲
	/*DrawBox(fishBoxX, fishBoxY, fishBoxX2, fishBoxY2, 0xff2255, FALSE);*/
	DrawExtendGraph(fBoxX, fBoxY, fBoxX2, fBoxY2, fishImg[Anim], TRUE);
#if _DEBUG
	DrawFormatString(0, 350, 0xffffff, "状態 %d", count, TRUE);
	DrawFormatString(0, 380, 0xffffff, "確率 %d", rand, TRUE);
#endif _DEBUG
}

