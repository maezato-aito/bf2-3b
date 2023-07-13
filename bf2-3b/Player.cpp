#include"DxLib.h"
#include"Player.h"
#include"common.h"

int Gvy = 0;

Player::Player()
{
	Image = LoadDivGraph("x64/Release/images/Player_Animation.png",30,8,4,64,64,Playerimg);

}
Player::~Player()
{

}
AbstractScene* Player::Update()
{
	if (boxY2 < S1_Landright_Y) {
		// ƒWƒƒƒ“ƒv‚ª‰Ÿ‚³‚ê‚Ä‚¢‚È‚¢
		Gvy = 3;
		boxY += Gvy;
		boxY2 += Gvy;
	}
	if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_UP) != 0)
	{
		if (boxY > 4) {
			Gvy = 3;
			// ‰Ÿ‚³‚ê‚Ä‚¢‚é
			boxY -= Gvy;
			boxY2 -= Gvy;
		}
	}
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);
	if (boxX > 0) {
		if (InputX < -1)
		{
			boxX -= 6;
			boxX2 -= 6;
		}
	}
	if (boxX2 < 640) {
		if (InputX > 1)
		{
			boxX += 6;
			boxX2 += 6;
		}
	}
	return this;
}

void Player::Draw() const
{
	DrawFormatString(0, 0, 0xffffff,"%d",InputX, TRUE);
	
	DrawBox(boxX, boxY,boxX2, boxY2+5, 0xff22ff, TRUE);
	DrawGraph(boxX, boxY, Playerimg[0], true);
}
