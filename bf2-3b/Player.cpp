#include"DxLib.h"
#include"Player.h"
#include"PadInput.h"
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
	if ((PAD_INPUT::OnPressed(XINPUT_BUTTON_B)))
	{
		if (boxY > 4) 
		{
			Gvy = 3;
			// 押されている
			boxY -= Gvy;
			boxY2 -= Gvy;
		}
	}
	else if ((PAD_INPUT::OnButton(XINPUT_BUTTON_A)))
	{
		if (boxY > 4)
		{
			Gvy = 20;
			// 押されている
			boxY -= Gvy;
			boxY2 -= Gvy;
		}
	}

	
	//地面に立っていないとき
	if(//右地面
		S1_Landright_X <= boxX2 && S1_Landright_X + 160 >= boxX &&
		S1_Landright_Y <= boxY2 && S1_Landright_Y + 90 >= boxY  
		||
		//左地面
		S1_Landleft_X <= boxX2 && S1_Landleft_X + 160 >= boxX &&
		S1_Landleft_Y <= boxY2 && S1_Landleft_Y+90 >= boxY
		||
		//空中床
		S1_Flooting_LEFT <= boxX2 && S1_Flooting_X + 280 >= boxX &&
		S1_Flooting_LEFT <= boxY2 && S1_Flooting_Y + 20 >= boxY
		)
	{ }
	else
	{
		// ジャンプが押されていない
		Gvy = 1;
		boxY += Gvy;
		boxY2 += Gvy;
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
	
	/*DrawBox(boxX, boxY,boxX2, boxY2+5, 0xffffff, TRUE);*/
	DrawBox(boxX, boxY, boxX2, boxY2 + 5, 0xff2255, FALSE);
	DrawGraph(boxX, boxY, Playerimg[0], true);
}
