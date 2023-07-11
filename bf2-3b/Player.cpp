#include"DxLib.h"
#include"Player.h"


Player::Player()
{
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
}


