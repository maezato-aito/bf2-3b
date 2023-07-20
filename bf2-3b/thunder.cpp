#include "DxLib.h"
#include "thunder.h"

thunder::thunder()
{
	LoadDivGraph("x64/Release/images/stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, ThunderImg);
	T_AnimImg = 1;
	Time = 0;
	pointFlg = 3;
	countFlg = 1;
	blinkCycle = 60;
	AnimFlg = 0b0000;
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
					T_AnimImg = 0;
				}
				if (countFlg == 1) {
					T_AnimImg = 1;
				}
				if (countFlg == 2) {
					T_AnimImg = 2;
			}
			
		}
	}
}

void thunder::D_thunder()
{
	DrawRotaGraph(S1_Thunder_X, S1_Thunder_Y, 0.8f, 0, ThunderImg[T_AnimImg], TRUE, FALSE);
	//DrawGraph(S1_Thunder_X, S1_Thunder_Y, ThunderImg[0], TRUE);
}