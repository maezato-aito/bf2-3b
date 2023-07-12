#include"DxLib.h"
#include"Player.h"


Player::Player()
{
	Image = LoadDivGraph("x64/Release/images/Player_Animation.png",30,8,4,64,64,Playerimg);

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	if (boxX > 0) {
		if (InputX < -1)
		{
			boxX -= 10;
			boxX2 -= 10;
		}
	}
	if (boxX2 < 640) {
		if (InputX > 1)
		{
			boxX += 10;
			boxX2 += 10;
		}
	}
	return this;
}

void Player::Draw() const
{
	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	
	DrawBox(boxX, boxY,boxX2, boxY2, 0xff22ff, TRUE);
	DrawGraph(boxX, boxY, Playerimg[0], true);
}
