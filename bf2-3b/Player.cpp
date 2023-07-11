#include"DxLib.h"
#include"Player.h"
#include"Stage.h"
#include"common.h"
Player::Player()
{

	//プレイヤー初期位置
	boxX=100;
	boxX2=150;
	boxY=100;
	boxY2=150;

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	//アナログスティックの傾き
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);

	//
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_2) == 0 )
	{
		if (S1_Landright_Y > boxY2) {
			boxY += 4;
			boxY2 += 4;
		}
	}
	else
	{
		if(boxY>0)
		boxY -= 7;
		boxY2 -= 7;
	}
	//画面内に描画
	if (boxX > 0) {
		if (InputX < -1)
		{
			boxX -= 5;
			boxX2 -= 5;
		}
	}
	if (boxX2 < 640) {
		if (InputX > 1)
		{
			boxX += 5;
			boxX2 += 5;
		}
	}
	return this;
}

void Player::Draw() const
{
	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	DrawBox(boxX, boxY,boxX2, boxY2, 0xff22ff, TRUE);
}


