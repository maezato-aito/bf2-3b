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
	A_ThunderImg = 0;
	C_AnimImg = 0;
	Time = 0;
	pointFlg = 3;
	countFlg = 0;
	AnimFlg = 0b0000;
	A_nimFlg = 0b0000;
	centerX = 350;
	centerY = 100;
	ranDirection = 0;
	incFlg = 24;
	indFlg = 24;
	TimeFlg = 3;
	moveAmount = 28;
	MoveAmount = 28;
	x = 0;
	y = 0;
	centerx = 350;
	centery = 100;
	once = false;
	A_Flg = 3;
	C_Flg = 0;
	BallX = 350;
	BallY = 100 - 5;
	Ballx = 350;
	Bally = 100 - 5;
	Movex = 0;
	Movey = 0;
	A_BallImg = 0;
	MoveX = 0;
	MoveY = 0;
	speed = 3;
	T_Angle = 0;
	BallAngle = 0;
	Ball_Angle = 0;
	//ChangeAngle2();
}

thunder::~thunder()
{
	/*DeleteGraph(Titleimage);*/
	DeleteGraph(ThunderImg[0]);
}

void thunder::Update()
{
	if (++TimeFlg < 100000000) {
		if (TimeFlg > 3300) {
			BallX += MoveX;
			BallY += MoveY;
			// 壁・天井での反射
			if (BallX < 4 || BallX > 640 - 4) { // 横の壁
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
					if (BallY >= 400) {
						BallAngle = (1 - BallAngle);
						ChangeAngle();
					}
				}
			}
			if (BallX >= 500) {
				if (BallX <= 700) {
					if (BallY >= 400) {
						if (BallY <= 450) {
							BallAngle = (1 - BallAngle);
							ChangeAngle();
						}
					}
				}
			}
		}
	}

		if (++TimeFlg < 3300) {
			if (TimeFlg > 3000) {
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
		if (++TimeFlg < 8280) {
			if (TimeFlg > 8000) {
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
void thunder::ChangeAngle2()
{
	rod = Ball_Angle * (float)M_PI * 2;
	Movex = (int)(speed * cosf(rod));
	Movey = (int)(speed * sinf(rod));
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
			Ballx = centerx += MoveAmount + 13;
			Bally = centery -= MoveAmount + 13;
			T_Angle = -170.0f;
			BallAngle = 0.875f;
			Ball_Angle = 0.875f;
			ChangeAngle();
			ChangeAngle2();
			break;
		case 1: // 斜め右下
			x = centerX += moveAmount;
			y = centerY += moveAmount;
			BallX = centerx += MoveAmount + 13;
			BallY = centery += MoveAmount + 13;
			Ballx = centerx += MoveAmount + 13;
			Bally = centery += MoveAmount + 13;
			T_Angle = -60.0f;
			BallAngle = 0.125f;
			Ball_Angle = 0.125f;
			ChangeAngle();
			ChangeAngle2();
			break;
		case 2: // 斜め左下
			x = centerX -= moveAmount;
			y = centerY += moveAmount;
			BallX = centerx -= MoveAmount + 17;
			BallY = centery += MoveAmount + 17;
			Ballx = centerx -= MoveAmount + 17;
			Bally = centery += MoveAmount + 17;
			BallAngle = 0.375f;
			Ball_Angle = 0.375f;
			ChangeAngle();
			ChangeAngle2();
			break;
		case 3: // 斜め左上
			x = centerX -= moveAmount + 8;
			y = centerY -= moveAmount + 8;
			BallX = centerx -= MoveAmount + 18;
			BallY = centery -= MoveAmount + 18;
			Ballx = centerx -= MoveAmount + 18;
			Bally = centery -= MoveAmount + 18;
			T_Angle = 140.0f;
			BallAngle = 0.625f;
			Ball_Angle = 0.625f;
			ChangeAngle();
			ChangeAngle2();
			break;
		default:
			break;
		}
		once = true;
	}

}
void thunder::Ball()
{
	if (++TimeFlg < 100000000) {
		if (TimeFlg > 8400) {
			Ballx += Movex;
			Bally += Movey;
			// 壁・天井での反射
			if (Ballx < 4 || Ballx > 640 - 4) { // 横の壁
				if (Ballx < 4) {
					Ballx = 4;
				}
				else {
					Ballx = 640 - 4;
				}
				Ball_Angle = (1 - Ball_Angle) + 0.5f;
				if (Ball_Angle > 1) Ball_Angle -= 1.0f;
				ChangeAngle2();
			}
			if (Ballx >= 190) {
				if (Ballx <= 480) {
					if (Bally >= 280) {
						if (Bally <= 300) {
							Ball_Angle = (1 - Ball_Angle);
							ChangeAngle2();
						}
					}
				}
			}
			if (Bally < 8) {   // 上の壁
				Ball_Angle = (1 - Ball_Angle);
				ChangeAngle2();
			}
			if (Ballx >= 0) {
				if (Ballx <= 200) {
					if (Bally >= 400) {
						Ball_Angle = (1 - Ball_Angle);
						ChangeAngle2();
					}
				}
			}
			if (Ballx >= 500) {
				if (Ballx <= 700) {
					if (Bally >= 400) {
						if (Bally <= 450) {
							Ball_Angle = (1 - Ball_Angle);
							ChangeAngle2();
						}
					}
				}
			}
		}
	}
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
	if (++incFlg < 3400) {
		if (++TimeFlg > 3300) {
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
	if (++incFlg < 8400) {
		if (++TimeFlg > 8300) {
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
		if (TimeFlg > 3400) {
			if (BallY < 450) {
				DrawRotaGraph(BallX, BallY, 1, 0, BallImg[A_BallImg], TRUE, FALSE);
			}
		}
	}
	if (++TimeFlg < 100000000) {
		if (TimeFlg > 8400) {
			if (Bally < 450) {
				DrawRotaGraph(Ballx, Bally, 1, 0, BallImg[A_BallImg], TRUE, FALSE);
			}
		}
	}
	if (++TimeFlg < 3400) {
		if (TimeFlg > 3300) {
			DrawRotaGraph(x, y, 1,T_Angle * DX_PI_F / 180.0f, ThunderImg[A_ThunderImg], TRUE, FALSE);
		}
	}
	if (++TimeFlg < 8400) {
		if (TimeFlg > 8300) {
			DrawRotaGraph(x, y, 1, T_Angle * DX_PI_F / 180.0f, ThunderImg[A_ThunderImg], TRUE, FALSE);
		}
	}
	DrawRotaGraph(S1_Thunder_X, S1_Thunder_Y, 1, 0, CloudImg[C_AnimImg], TRUE, FALSE);
	//DrawCircle(centerX, centerY, 2, GetColor(255, 0, 0), TRUE);
	//DrawGraph(S1_Thunder_X, S1_Thunder_Y, ThunderImg[0], TRUE);
}