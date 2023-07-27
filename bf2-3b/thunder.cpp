#include "DxLib.h"
#include "thunder.h"
#include <stdio.h>

thunder::thunder()
{
	LoadDivGraph("x64/Release/images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, CloudImg);
	LoadDivGraph("x64/Release/images/stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 63, ThunderImg);
	A_ThunderImg = 1;
	C_AnimImg = 1;
	Time = 0;
	pointFlg = 3;
	countFlg = 0;
	AnimFlg = 0b0000;
	A_nimFlg = 0b0000;
	centerX = 200;
	centerY = 100;
	ranDirection = 0;
	incFlg = 18;
	moveAmount = 28;
	x = 0;
	y = 0;
	once = false;
	A_Flg = 3;
	C_Flg = 0;
}

thunder::~thunder()
{
	/*DeleteGraph(Titleimage);*/
	DeleteGraph(ThunderImg[0]);
}

void thunder::Update()
{
	if (++pointFlg < 100) {
		if (AnimFlg == 0b0000) {
			countFlg = pointFlg % 3;
			if (countFlg == 0) {
				C_AnimImg = 0;
			}
			if (countFlg == 1) {
				C_AnimImg = 1;
			}
			if (countFlg == 2) {
				C_AnimImg = 2;
			}

		}
	}

}
void thunder::Circle()
{

	if (once == false) {
		ranDirection = 2;//GetRand(3);

		switch (ranDirection) {
		case 0: // ŽÎ‚ß‰Eã
			x = centerX += moveAmount;
			y = centerY -= moveAmount;
			break;
		case 1: // ŽÎ‚ß‰E‰º
			x = centerX += moveAmount;
			y = centerY += moveAmount;
			break;
		case 2: // ŽÎ‚ß¶‰º
			x = centerX -= moveAmount;
			y = centerY += moveAmount;
			break;
		case 3: // ŽÎ‚ß¶ã
			x = centerX -= moveAmount;
			y = centerY -= moveAmount;
			break;
		default:
			break;
		}
		once = true;
	}

}
void thunder::Anim() {
	if (++incFlg < 200) {
		if (incFlg > 100) {
			if (A_nimFlg == 0b0000) {
				C_Flg = incFlg % 18;
				if (C_Flg == 0) {
					A_ThunderImg = 0;
				}
				if (C_Flg == 1) {
					A_ThunderImg = 0;
				}
				if (C_Flg == 2) {
					A_ThunderImg = 0;
				}
				if (C_Flg == 3) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 4) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 5) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 6) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 7) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 8) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 9) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 10) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 11) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 12) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 13) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 14) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 15) {
					A_ThunderImg = 5;
				}
				if (C_Flg == 16) {
					A_ThunderImg = 5;
				}
				if (C_Flg == 17) {
					A_ThunderImg = 5;
				}

			}
		}
	}
}

void thunder::D_thunder()
{
	DrawRotaGraph(x, y, 0.8f, 0, ThunderImg[A_ThunderImg], TRUE, FALSE);
	DrawRotaGraph(S1_Thunder_X, S1_Thunder_Y, 0.8f, 0, CloudImg[C_AnimImg], TRUE, FALSE);
	DrawCircle(centerX, centerY, 2, GetColor(255, 0, 0), TRUE);
	//DrawGraph(S1_Thunder_X, S1_Thunder_Y, ThunderImg[0], TRUE);
}