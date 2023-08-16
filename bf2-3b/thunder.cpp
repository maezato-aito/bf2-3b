#include "DxLib.h"
#include "thunder.h"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

thunder::thunder()
{
	LoadDivGraph("images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, CloudImg);
	LoadDivGraph("images/stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 63, ThunderImg);
	LoadDivGraph("images/stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, BallImg);
	A_ThunderImg = 1;
	C_AnimImg = 1;
	Time = 0;
	pointFlg = 3;
	countFlg = 0;
	AnimFlg = 0b0000;
	A_nimFlg = 0b0000;
	centerX = 400;
	centerY = 100;
	ranDirection = 0;
	incFlg = 24;
	TimeFlg = 0;
	moveAmount = 28;
	MoveAmount = 28;
	x = 0;
	y = 0;
	centerx = 400;
	centery = 100;
	once = false;
	A_Flg = 3;
	C_Flg = 0;
	BallX = 400;
	BallY = 100 - 5;
	A_BallImg = 0;
	MoveX = 0;
	MoveY = 0;
	speed = 5;
	T_Angle = 0;
	BallAngle = 0;
	
}

thunder::~thunder()
{
	/*DeleteGraph(Titleimage);*/
	DeleteGraph(ThunderImg[0]);
}

void thunder::Update()
{
	if (++TimeFlg < 100000000) {
		if (TimeFlg > 300) {
			BallX += MoveX;
			BallY += MoveY;
			// 壁・天井での反射
			if (BallX < 4 || BallX > 640 - 4) { // 横の壁
				if (BallY <= 400) {
					if (BallX < 4) {
						BallX = 4;
					}
					else {
						BallX = 640 - 4;
					}
					BallAngle = (1 - BallAngle) + 0.5f;
					if (BallAngle > 1) BallAngle -= 1.0f;
					ChangeAngle();
				}
			}
			if (BallX >= 190) {
				if (BallX <= 480) {
					if (BallY >= 280) {
						if (BallY <= 300) {
							BallAngle = (1 - BallAngle);
							ChangeAngle();
						}
					}
				}
			}
			if (BallY < 8) {   // 上の壁
				BallAngle = (1 - BallAngle);
				ChangeAngle();
			}
			if (BallX >= 0) {
				if (BallX <= 200) {
					if (BallY <= 400) {
						BallAngle = (1 - BallAngle);
						ChangeAngle();
					}
				}
			}
			if (BallX >= 500) {
				//if (BallX <= 700) {
					if (BallY >= 400) {
						if (BallY <= 450) {
							BallAngle = (1 - BallAngle);
							ChangeAngle();
						}
					}
				//}
			}
		}
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
}
void thunder::ChangeAngle()
{
	rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(speed * cosf(rad));
	MoveY = (int)(speed * sinf(rad));
}
void thunder::Circle()
{

	if (once == false) {
		ranDirection = GetRand(3);

		switch (ranDirection) {
		case 0: // 斜め右上
			x = centerX += moveAmount;
			y = centerY -= moveAmount;
			BallX = centerx += MoveAmount + 13;
			BallY = centery -= MoveAmount + 13;
			T_Angle = -170.0f;
			BallAngle = 0.875f;
			ChangeAngle();
			break;
		case 1: // 斜め右下
			x = centerX += moveAmount;
			y = centerY += moveAmount;
			BallX = centerx += MoveAmount + 13;
			BallY = centery += MoveAmount + 13;
			T_Angle = -60.0f;
			BallAngle = 0.125f;
			ChangeAngle();
			break;
		case 2: // 斜め左下
			x = centerX -= moveAmount;
			y = centerY += moveAmount;
			BallX = centerx -= MoveAmount + 13;
			BallY = centery += MoveAmount + 13;
			BallAngle = 0.375f;
			ChangeAngle();
			break;
		case 3: // 斜め左上
			x = centerX -= moveAmount + 8;
			y = centerY -= moveAmount + 8;
			BallX = centerx -= MoveAmount + 18;
			BallY = centery -= MoveAmount + 18;
			T_Angle = 140.0f;
			BallAngle = 0.625f;
			ChangeAngle();
			break;
		default:
			break;
		}
		once = true;
	}

}
void thunder::Ball()
{
	if (++pointFlg < 10000) {
		if (AnimFlg == 0b0000) {
			countFlg = pointFlg % 3;
			if (countFlg == 0) {
				A_BallImg = 0;
			}
			if (countFlg == 1) {
				A_BallImg = 1;
			}
			if (countFlg == 2) {
				A_BallImg = 2;
			}


		}
	}
}
void thunder::Anim() {
	if (++incFlg < 200) {
		if (incFlg > 100) {
			if (A_nimFlg == 0b0000) {
				C_Flg = incFlg % 24;
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
					A_ThunderImg = 0;
				}
				if (C_Flg == 4) {
					A_ThunderImg = 0;
				}
				if (C_Flg == 5) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 6) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 7) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 8) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 9) {
					A_ThunderImg = 1;
				}
				if (C_Flg == 10) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 11) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 12) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 13) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 14) {
					A_ThunderImg = 2;
				}
				if (C_Flg == 15) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 16) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 17) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 18) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 19) {
					A_ThunderImg = 3;
				}
				if (C_Flg == 20) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 21) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 22) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 23) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 18) {
					A_ThunderImg = 4;
				}
				if (C_Flg == 19) {
					A_ThunderImg = 5;
				}
				if (C_Flg == 20) {
					A_ThunderImg = 5;
				}
				if (C_Flg == 21) {
					A_ThunderImg = 5;
				}
				if (C_Flg == 22) {
					A_ThunderImg = 5;
				}
				if (C_Flg == 23) {
					A_ThunderImg = 5;
				}
			}
		}
	}
}

void thunder::D_thunder()
{
	if (++TimeFlg < 100000000) {
		if (TimeFlg > 300) {
			DrawRotaGraph(BallX, BallY, 1, 0, BallImg[A_BallImg], TRUE, FALSE);
		}
	}
	if (++TimeFlg < 300) {
		if (TimeFlg > 200) {
			DrawRotaGraph(x, y, 1,T_Angle * DX_PI_F / 180.0f, ThunderImg[A_ThunderImg], TRUE, FALSE);
		}
	}
	DrawRotaGraph(S1_Thunder_X, S1_Thunder_Y, 1, 0, CloudImg[C_AnimImg], TRUE, FALSE);
	DrawCircle(centerX, centerY, 2, GetColor(255, 0, 0), TRUE);
	//DrawGraph(S1_Thunder_X, S1_Thunder_Y, ThunderImg[0], TRUE);
}