#include"bubble.h"
#include"DxLib.h"
#include"Player.h"
#include "Enemy.h"

Bubble::Bubble()
{

	//泡の位置
	 bubbleX=250;
	 bubbleY=480;
	 bubbleFlg = 0;
	 //泡の上昇量
	 bubbleUp = 0.5;

	 //泡の横の移動量
	 bubbleSide = 1.0f;

	//泡の右上
	 bX0=bubbleX-25;
	 bY0=bubbleY-25;

	//泡の左下
	 bX1=bubbleX+25;
	 bY1=bubbleY+25;

	 //アニメーション用カウンタ
	 bubbleC = 0;
	 bubbleAC = 0;

	 bAv = 0;
	 b=0;
	//画像の読み込み
	LoadDivGraph("images/Stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, bubbleImg);
}
Bubble::~Bubble()
{

}
void Bubble::Update()
{
	//泡の位置
	bubbleY-=bubbleUp;
	bubbleX += bubbleSide;
	//泡の右上
	bX0 = bubbleX - 30;
	bY0 = bubbleY - 30;

	//泡の左下
	bX1 = bubbleX + 30;
	bY1 = bubbleY + 30;

	if (bubbleFlg == 1) {
		if (Enemy::eBoxX>Enemy::eBoxX -70 || Enemy::eBoxX < Enemy::eBoxX + 70)
		{
			bubbleSide *= -1;
		}

		if (bubbleY <= -25)
		{
			bubbleUp=0;
			bubbleSide = 0;
		}
		//アニメーション
		if (bubbleY >= 0)
		{
			if (++bubbleC < 66)
			{
				if (0 < bubbleC)
				{
					bubbleAC = 0;
				}
				if (60 < bubbleC)
				{
					bubbleAC = 1;
				}
				if (120 < bubbleC)
				{
					bubbleAC = 0;
				}
				if (180 < bubbleC)
				{
					bubbleAC = 2;
				}
				if (239 < bubbleC)
				{
					bubbleC = 0;
				}

			}
		}
	}
	else if (bubbleFlg == 0) {

	}
	//ぶつかったら
	/*if (
		(bX0 <= pBoxX2 && bX1 >= pBoxX &&
			bY0 <= pBoxY2 && bY1 >= pBoxY))
	{
		bubbleAC == 3;
	}*/
}
void Bubble::Draw()
{
	
#if _DEBUG
	DrawFormatString(350, 0, 0xffffff, "泡の座標 X:%3.2f Y:%3.2f",bubbleX,bubbleY,  TRUE);
	DrawFormatString(350, 20, 0xffffff, "泡の種類:%d",bubbleC,  TRUE);
	DrawFormatString(350, 40, 0xffffff,		"時間: % d",bAv,  TRUE);
#endif _DEBUG
	DrawExtendGraph(bX0, bY0, bX1, bY1, bubbleImg[bubbleAC], TRUE);
}
